#!/usr/bin/env cmsRun

import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils
import FWCore.ParameterSet.VarParsing as VarParsing
import os
from flashgg.Systematics.SystematicDumperDefaultVariables import minimalVariables,minimalHistograms,minimalNonSignalVariables,systematicVariables
from flashgg.MetaData.MetaConditionsReader import *

# ========================================================================
# SYSTEMATICS SECTION
process = cms.Process("FLASHggSyst")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
process.maxEvents   = cms.untracked.PSet( input  = cms.untracked.int32( 10 ) )
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 1000 )

systlabels    = [""]
phosystlabels = []
jetsystlabels = []
elesystlabels = []
musystlabels  = []

# import flashgg customization to check if we have signal or background
from flashgg.MetaData.JobConfig import customize
# Register forwardJetRMSCut to be used from customize
customize.options.register('forwardJetRMSCut',
                           3.00,
                           VarParsing.VarParsing.multiplicity.singleton,
                           VarParsing.VarParsing.varType.float,
                           'forwardJetRMSCut')

customize.options.register('pujidWP',
                           'tight', 
                           VarParsing.VarParsing.multiplicity.singleton,
                           VarParsing.VarParsing.varType.string,
                           'pujidWP')

customize.options.register('runOnZee',
                           False,
                           VarParsing.VarParsing.multiplicity.singleton,
                           VarParsing.VarParsing.varType.bool,
                           'runOnZee')

customize.options.register('dumpJetSysTrees',
                           False,
                           VarParsing.VarParsing.multiplicity.singleton,
                           VarParsing.VarParsing.varType.bool,
                           'dumpJetSysTrees')
# set default options if needed
customize.setDefault("maxEvents",-1)
customize.setDefault("targetLumi",1.00e+3)
customize.parse()
customize.metaConditions = MetaConditionsReader(customize.metaConditions)

### Global Tag
from Configuration.AlCa.GlobalTag import GlobalTag
if customize.processId == "Data": process.GlobalTag.globaltag = str(customize.metaConditions['globalTags']['data'])
else: process.GlobalTag.globaltag = str(customize.metaConditions['globalTags']['MC'])

#Systematics customize
from flashgg.Systematics.SystematicsCustomize import *
jetSystematicsInputTags = createStandardSystematicsProducers(process,customize)
modifyTagSequenceForSystematics(process,jetSystematicsInputTags,2)

#Using standard tools
useEGMTools(process)

# Load tag sequence
#process.load("flashgg.Taggers.flashggTagSequence_cfi") #FIXME testing this
process.flashggTagSequence.remove(process.flashggUntagged)
process.flashggTagSequence.remove(process.flashggTTHDiLeptonTag)
process.flashggTagSequence.remove(process.flashggTTHLeptonicTag)
process.flashggTagSequence.remove(process.flashggTTHHadronicTag)
process.flashggTagSequence.remove(process.flashggVHMetTag)
process.flashggTagSequence.remove(process.flashggWHLeptonicTag)
process.flashggTagSequence.remove(process.flashggZHLeptonicTag)
process.flashggTagSequence.remove(process.flashggVHLeptonicLooseTag)
process.flashggTagSequence.remove(process.flashggVHHadronicTag)

mva_wp = {
    "none"  : [
        [],
        [],
        []
    ],
    "tight" : [
        [0.69, -0.35, -0.26, -0.21],
        [0.86, -0.1 , -0.05, -0.01],
        [0.95,  0.28,  0.31,  0.28]
    ],
    "medium": [
        [0.18, -0.55, -0.42, -0.36],
        [0.61, -0.35, -0.23, -0.17],
        [0.87,  0.03,  0.13,  0.12]
    ],
    "loose" :[
        [-0.97, -0.68, -0.53, -0.47],
        [-0.89, -0.52, -0.38, -0.3 ],
        [-0.56, -0.17, -0.04, -0.01],
    ],
    "forward_tight" : [
        [-1, -0.35, -0.26, -0.21],
        [-1, -0.1 , -0.05, -0.01],
        [-1,  0.28,  0.31,  0.28]
    ],
    "forward_medium": [
        [-1, -0.55, -0.42, -0.36],
        [-1, -0.35, -0.23, -0.17],
        [-1,  0.03,  0.13,  0.12]
    ],
    "forward_loose" :[
        [-1, -0.68, -0.53, -0.47],
        [-1, -0.52, -0.38, -0.3 ],
        [-1, -0.17, -0.04, -0.01],
    ]
}




#== Only run systematics for signal events
from flashgg.Taggers.flashggTags_cff import UnpackedJetCollectionVInputTag

# load the correctors
process.load("JetMETCorrections.Configuration.JetCorrectors_cff")

if customize.processId == "Data":
    print "Data, so turn of all shifts and systematics, with some exceptions"
    variablesToUse = minimalNonSignalVariables
    customizeSystematicsForData(process)
else:
    print "Background MC, so store mgg and central only"
    variablesToUse = minimalNonSignalVariables

    if customize.dumpJetSysTrees:
        print "Running jet systematics and putting them in ntuples because doJetSystTrees is set"
        for direction in ["Up","Down"]:
            jetsystlabels.append("JEC%s01sigma" % direction)
            jetsystlabels.append("JER%s01sigma" % direction)
            jetsystlabels.append("PUJIDShift%s01sigma" % direction)
        systlabels += jetsystlabels
        for direction in ["Up","Down"]:
            phosystlabels += ["MvaShift%s01sigma" % direction,
                           "SigmaEOverEShift%s01sigma" % direction
                           ]
        systlabels += phosystlabels
    else:
        print "Background MC, so store mgg and central only"
        customizeSystematicsForBackground(process)

print "--- Turning on central value for UnmatchedPUweight---"
for i in range(len(jetSystematicsInputTags)):
    prodname = 'flashggJetSystematics%i'%i
    vpset = getattr(process,prodname).SystMethods
    for pset in vpset:
        syst = pset.Label.value()
        if syst.count("UnmatchedPUWeight"):
            pset.ApplyCentralValue = False # default to false
            pset.Debug = False

#process.flashggVBFTag.GetQCDWeights = True
#process.flashggVBFTag.GetJetVetoWeights = True
        
print "--- Systematics  with independent collections ---"
print systlabels
print "-------------------------------------------------"
print "--- Variables to be dumped, including systematic weights ---"
print variablesToUse
print "------------------------------------------------------------"

# ========================================================================
# Dumper section
from FWCore.ParameterSet.VarParsing import VarParsing
from flashgg.MetaData.samples_utils import SamplesManager

process.source = cms.Source ("PoolSource",
                             fileNames = cms.untracked.vstring(
#'root://xrootd-cms.infn.it//store/user/spigazzi/flashgg/Era2017_RR-31Mar2018_v2/legacyRun2FullV1/DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa/Era2017_RR-31Mar2018_v2-legacyRun2FullV1-v0-RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v2/190716_170206/0000/myMicroAODOutputFile_912.root'
#'file:/afs/cern.ch/work/d/davies/flashgg/CMSSW_10_6_1_patch2/src/flashgg/myMicroAODOutputFileGGH10K.root'
#'file:/afs/cern.ch/work/d/davies/flashgg/CMSSW_10_6_1_patch2/src/flashgg/myMicroAODOutputFileVBF10K.root'
'file:/afs/cern.ch/work/d/davies/flashgg/CMSSW_10_6_1_patch2/src/flashgg/uAODVBFTest_Jan2020.root'
#'root://xrootd-cms.infn.it//store/user/spigazzi/flashgg/Era2017_RR-31Mar2018_v2/legacyRun2FullV1/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8/Era2017_RR-31Mar2018_v2-legacyRun2FullV1-v0-RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v2/190606_100408/0002/myMicroAODOutputFile_2357.root'
#'root://xrootd-cms.infn.it//store/user/spigazzi/flashgg/Era2017_RR-31Mar2018_v2/legacyRun2FullV1/DoubleEG/Era2017_RR-31Mar2018_v2-legacyRun2FullV1-v0-Run2017C-31Mar2018-v1/190606_095024/0001/myMicroAODOutputFile_1330.root'
                             )
)

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("test.root"))

import flashgg.Taggers.dumperConfigTools as cfgTools
from   flashgg.Taggers.tagsDumpers_cfi   import createTagDumper

process.vbfTagDumper = createTagDumper("VBFTag")
process.vbfTagDumper.dumpTrees     = True
process.vbfTagDumper.dumpHistos    = True
process.vbfTagDumper.dumpWorkspace = False
process.vbfTagDumper.src = "flashggSystTagMerger"

# OPTIONS FOR VBF DUMPER
# Use JetID
process.flashggVBFMVA.UseJetID      = cms.bool(True) #fixme
process.flashggVBFMVA.JetIDLevel    = cms.string("Tight2017") #cms.string("Loose")
process.flashggVBFMVA.DrJetPhoton   = cms.double(0.4) # this is the right number
# Relax all selection on VBF tag
process.flashggVBFTag.Boundaries             = cms.vdouble(-2.0,2.0)
process.flashggVBFTag.SetArbitraryNonGoldMC  = cms.bool(False)
process.flashggVBFTag.DropNonGoldData        = cms.bool(False)
process.flashggVBFTag.RequireVBFPreselection = cms.bool(False)
#OPtions for MVA
process.flashggVBFMVA.rmsforwardCut = cms.double(customize.forwardJetRMSCut)
process.flashggVBFMVA.pujidWpPtBin1 = cms.vdouble(mva_wp[customize.pujidWP][0])
process.flashggVBFMVA.pujidWpPtBin2 = cms.vdouble(mva_wp[customize.pujidWP][1])
process.flashggVBFMVA.pujidWpPtBin3 = cms.vdouble(mva_wp[customize.pujidWP][2])
# Print to user
print '------------------------------------------------------------'
print ' PUJID Working point    ::' , customize.pujidWP
print '------------------------------------------------------------'
print ' PUJID wp cuts          ::' , mva_wp[customize.pujidWP]
print '------------------------------------------------------------'
print ' formward RMS Cut value ::' , customize.forwardJetRMSCut
print '------------------------------------------------------------'
print ' running on Zee         ::' , customize.runOnZee
print '------------------------------------------------------------'


# run on Drell-Yan
if customize.runOnZee:
    process.flashggPreselectedDiPhotons.variables =  cms.vstring('pfPhoIso03',
                                                                 'trkSumPtHollowConeDR03',
                                                                 'full5x5_sigmaIetaIeta',
                                                                 'full5x5_r9',
                                                                 '1-passElectronVeto')

# GET THE VARIABLES TO USE IN THE DUMPER
import flashgg.Taggers.VBFTagVariables as var
new_variables = [
    "n_jet_30             := VBFMVA.n_rec_jets",
    "dijet_jet1_RMS       := leading_rms",
    "dijet_jet2_RMS       := subLeading_rms",
    "dijet_jet1_QGL       := leading_QGL",
    "dijet_jet2_QGL       := subLeading_QGL",
    "dijet_jet1_pujid_mva := leading_pujidMVA()",
    "dijet_jet2_pujid_mva := subleading_pujidMVA()",
    "dipho_pt             := diPhoton.pt",
    "dijet_pt             := VBFMVA.dijet_pt",
    "cosThetaStar         := VBFMVA.cosThetaStar",

    #"FLAVOUR_GENJET1           := tagTruth().Flav_GenJ1",

    "gen_lead_jet_pt     := tagTruth().pt_GenJ1",
    "gen_lead_jet_eta    := tagTruth().eta_GenJ1",
    "gen_lead_jet_phi    := tagTruth().phi_GenJ1",
    "gen_lead_jet_energy := tagTruth().energy_GenJ1",
    "gen_lead_jet_pdgId  := tagTruth().pdgId_GenJ1",
    "gen_sublead_jet_pt     := tagTruth().pt_GenJ2",
    "gen_sublead_jet_eta    := tagTruth().eta_GenJ2",
    "gen_sublead_jet_phi    := tagTruth().phi_GenJ2",
    "gen_sublead_jet_energy := tagTruth().energy_GenJ2",
    "gen_sublead_jet_pdgId  := tagTruth().pdgId_GenJ2",
    "gen_subsublead_jet_pt     := tagTruth().pt_GenJ3",
    "gen_subsublead_jet_eta    := tagTruth().eta_GenJ3",
    "gen_subsublead_jet_phi    := tagTruth().phi_GenJ3",
    "gen_subsublead_jet_energy := tagTruth().energy_GenJ3",
    "gen_subsublead_jet_pdgId  := tagTruth().pdgId_GenJ3",

    #"gen_lead_flavour          := tagTruth().flavour_GenJ1",
    #"gen_sublead_flavour          := tagTruth().flavour_GenJ2",
    #"gen_subsublead_flavour          := tagTruth().flavour_GenJ3",


    "gen_lead_parton_pdgId  :=  tagTruth().pdgId_P1()",
    "gen_sublead_parton_pdgId  :=  tagTruth().pdgId_P2()",
    "gen_subsublead_parton_pdgId  :=  tagTruth().pdgId_P3()",

    "gen_lead_parton_pt          :=  tagTruth().pt_P1()",
    "gen_sublead_parton_pt       :=  tagTruth().pt_P2()",
    "gen_subsublead_parton_pt    :=  tagTruth().pt_P3()",

    "gen_lead_parton_eta          :=  tagTruth().eta_P1()",
    "gen_sublead_parton_eta       :=  tagTruth().eta_P2()",
    "gen_subsublead_parton_eta    :=  tagTruth().eta_P3()",

    "gen_lead_parton_phi          :=  tagTruth().phi_P1()",
    "gen_sublead_parton_phi       :=  tagTruth().phi_P2()",
    "gen_subsublead_parton_phi    :=  tagTruth().phi_P3()",

    "gen_lead_parton_phi          :=  tagTruth().charge_P1()",
    "gen_sublead_parton_phi       :=  tagTruth().charge_P2()",
    "gen_subsublead_parton_phi    :=  tagTruth().charge_P3()",

    "gen_lead_parton_energy          :=  tagTruth().energy_P1()",
    "gen_sublead_parton_energy       :=  tagTruth().energy_P2()",
    "gen_subsublead_parton_energy    :=  tagTruth().energy_P3()",

    "lead_jet_pt            :=  tagTruth().pt_J1",
    "sub_lead_jet_pt        :=  tagTruth().pt_J2",
    "subsub_lead_jet_pt     :=  tagTruth().pt_J3",

    

    "lead_jet_phi            := tagTruth().phi_J1",
    "sub_lead_jet_phi        := tagTruth().phi_J2", 
    "subsub_lead_jet_phi     := tagTruth().phi_J3",

    "lead_jet_eta            := tagTruth().eta_J1",
    "sub_lead_jet_eta        := tagTruth().eta_J2",
    "subsub_lead_jet_eta     := tagTruth().eta_J3",

    "lead_jet_charge            := tagTruth().charge_J1",
    "sub_lead_jet_charge        := tagTruth().charge_J2",
    "subsub_lead_jet_charge     := tagTruth().charge_J3",

    "lead_jet_energy            :=  tagTruth().energy_J1",
    "sub_lead_jet_energy        :=  tagTruth().energy_J2",
    "subsub_lead_jet_energy     :=  tagTruth().energy_J3",

    #"lead_jet_pdgId            :=  tagTruth().pdgId_J1",
    #"sub_lead_jet_pdgId        :=  tagTruth().pdgId_J2",
    #"subsub_lead_jet_pdgId     :=  tagTruth().pdgId_J3",

    "lead_jet_flav            :=  tagTruth().flav_J1",
    "sub_lead_jet_flav        :=  tagTruth().flav_J2",
    "subsub_lead_jet_flav     :=  tagTruth().flav_J3",
    
    "n_constits               := VBFMVA().n_constits",
    #"test_vector              := VBFMVA().test_vec",
                  
    "lead_jet_constit1_eta := VBFMVA.lead_jet_c1_eta",
    "lead_jet_constit2_eta := VBFMVA.lead_jet_c2_eta",
    "lead_jet_constit3_eta := VBFMVA.lead_jet_c3_eta",
    "lead_jet_constit4_eta := VBFMVA.lead_jet_c4_eta",
    "lead_jet_constit5_eta := VBFMVA.lead_jet_c5_eta",
    "lead_jet_constit6_eta := VBFMVA.lead_jet_c6_eta",
    "lead_jet_constit7_eta := VBFMVA.lead_jet_c7_eta",
    "lead_jet_constit8_eta := VBFMVA.lead_jet_c8_eta",
    "lead_jet_constit9_eta := VBFMVA.lead_jet_c9_eta",
    "lead_jet_constit10_eta := VBFMVA.lead_jet_c10_eta",
    "lead_jet_constit11_eta := VBFMVA.lead_jet_c11_eta",
    "lead_jet_constit12_eta := VBFMVA.lead_jet_c12_eta",
    "lead_jet_constit13_eta := VBFMVA.lead_jet_c13_eta",
    "lead_jet_constit14_eta := VBFMVA.lead_jet_c14_eta",
    "lead_jet_constit15_eta := VBFMVA.lead_jet_c15_eta",
    "lead_jet_constit16_eta := VBFMVA.lead_jet_c16_eta",
    "lead_jet_constit17_eta := VBFMVA.lead_jet_c17_eta",
    "lead_jet_constit18_eta := VBFMVA.lead_jet_c18_eta",
    "lead_jet_constit19_eta := VBFMVA.lead_jet_c19_eta",
    "lead_jet_constit20_eta := VBFMVA.lead_jet_c20_eta",
    "lead_jet_constit21_eta := VBFMVA.lead_jet_c21_eta",
    "lead_jet_constit22_eta := VBFMVA.lead_jet_c22_eta",
    "lead_jet_constit23_eta := VBFMVA.lead_jet_c23_eta",
    "lead_jet_constit24_eta := VBFMVA.lead_jet_c24_eta",
    "lead_jet_constit25_eta := VBFMVA.lead_jet_c25_eta",
    "lead_jet_constit26_eta := VBFMVA.lead_jet_c26_eta",
    "lead_jet_constit27_eta := VBFMVA.lead_jet_c27_eta",
    "lead_jet_constit28_eta := VBFMVA.lead_jet_c28_eta",
    "lead_jet_constit29_eta := VBFMVA.lead_jet_c29_eta",
    "lead_jet_constit30_eta := VBFMVA.lead_jet_c30_eta",
    "lead_jet_constit31_eta := VBFMVA.lead_jet_c31_eta",
    "lead_jet_constit32_eta := VBFMVA.lead_jet_c32_eta",
    "lead_jet_constit33_eta := VBFMVA.lead_jet_c33_eta",
    "lead_jet_constit34_eta := VBFMVA.lead_jet_c34_eta",
    "lead_jet_constit35_eta := VBFMVA.lead_jet_c35_eta",
    "lead_jet_constit36_eta := VBFMVA.lead_jet_c36_eta",
    "lead_jet_constit37_eta := VBFMVA.lead_jet_c37_eta",
    "lead_jet_constit38_eta := VBFMVA.lead_jet_c38_eta",
    "lead_jet_constit39_eta := VBFMVA.lead_jet_c39_eta",
    "lead_jet_constit40_eta := VBFMVA.lead_jet_c40_eta",
    "lead_jet_constit41_eta := VBFMVA.lead_jet_c41_eta",
    "lead_jet_constit42_eta := VBFMVA.lead_jet_c42_eta",
    "lead_jet_constit43_eta := VBFMVA.lead_jet_c43_eta",
    "lead_jet_constit44_eta := VBFMVA.lead_jet_c44_eta",
    "lead_jet_constit45_eta := VBFMVA.lead_jet_c45_eta",
    "lead_jet_constit46_eta := VBFMVA.lead_jet_c46_eta",
    "lead_jet_constit47_eta := VBFMVA.lead_jet_c47_eta",
    "lead_jet_constit48_eta := VBFMVA.lead_jet_c48_eta",
    "lead_jet_constit49_eta := VBFMVA.lead_jet_c49_eta",
    "lead_jet_constit50_eta := VBFMVA.lead_jet_c50_eta",
    "lead_jet_constit51_eta := VBFMVA.lead_jet_c51_eta",
    "lead_jet_constit52_eta := VBFMVA.lead_jet_c52_eta",
    "lead_jet_constit53_eta := VBFMVA.lead_jet_c53_eta",
    "lead_jet_constit54_eta := VBFMVA.lead_jet_c54_eta",
    "lead_jet_constit55_eta := VBFMVA.lead_jet_c55_eta",
    "lead_jet_constit56_eta := VBFMVA.lead_jet_c56_eta",
    "lead_jet_constit57_eta := VBFMVA.lead_jet_c57_eta",
    "lead_jet_constit58_eta := VBFMVA.lead_jet_c58_eta",
    "lead_jet_constit59_eta := VBFMVA.lead_jet_c59_eta",
    "lead_jet_constit60_eta := VBFMVA.lead_jet_c60_eta",

    "lead_jet_constit1_phi := VBFMVA.lead_jet_c1_phi",
    "lead_jet_constit2_phi := VBFMVA.lead_jet_c2_phi",
    "lead_jet_constit3_phi := VBFMVA.lead_jet_c3_phi",
    "lead_jet_constit4_phi := VBFMVA.lead_jet_c4_phi",
    "lead_jet_constit5_phi := VBFMVA.lead_jet_c5_phi",
    "lead_jet_constit6_phi := VBFMVA.lead_jet_c6_phi",
    "lead_jet_constit7_phi := VBFMVA.lead_jet_c7_phi",
    "lead_jet_constit8_phi := VBFMVA.lead_jet_c8_phi",
    "lead_jet_constit9_phi := VBFMVA.lead_jet_c9_phi",
    "lead_jet_constit10_phi := VBFMVA.lead_jet_c10_phi",
    "lead_jet_constit11_phi := VBFMVA.lead_jet_c11_phi",
    "lead_jet_constit12_phi := VBFMVA.lead_jet_c12_phi",
    "lead_jet_constit13_phi := VBFMVA.lead_jet_c13_phi",
    "lead_jet_constit14_phi := VBFMVA.lead_jet_c14_phi",
    "lead_jet_constit15_phi := VBFMVA.lead_jet_c15_phi",
    "lead_jet_constit16_phi := VBFMVA.lead_jet_c16_phi",
    "lead_jet_constit17_phi := VBFMVA.lead_jet_c17_phi",
    "lead_jet_constit18_phi := VBFMVA.lead_jet_c18_phi",
    "lead_jet_constit19_phi := VBFMVA.lead_jet_c19_phi",
    "lead_jet_constit20_phi := VBFMVA.lead_jet_c20_phi",
    "lead_jet_constit21_phi := VBFMVA.lead_jet_c21_phi",
    "lead_jet_constit22_phi := VBFMVA.lead_jet_c22_phi",
    "lead_jet_constit23_phi := VBFMVA.lead_jet_c23_phi",
    "lead_jet_constit24_phi := VBFMVA.lead_jet_c24_phi",
    "lead_jet_constit25_phi := VBFMVA.lead_jet_c25_phi",
    "lead_jet_constit26_phi := VBFMVA.lead_jet_c26_phi",
    "lead_jet_constit27_phi := VBFMVA.lead_jet_c27_phi",
    "lead_jet_constit28_phi := VBFMVA.lead_jet_c28_phi",
    "lead_jet_constit29_phi := VBFMVA.lead_jet_c29_phi",
    "lead_jet_constit30_phi := VBFMVA.lead_jet_c30_phi",
    "lead_jet_constit31_phi := VBFMVA.lead_jet_c31_phi",
    "lead_jet_constit32_phi := VBFMVA.lead_jet_c32_phi",
    "lead_jet_constit33_phi := VBFMVA.lead_jet_c33_phi",
    "lead_jet_constit34_phi := VBFMVA.lead_jet_c34_phi",
    "lead_jet_constit35_phi := VBFMVA.lead_jet_c35_phi",
    "lead_jet_constit36_phi := VBFMVA.lead_jet_c36_phi",
    "lead_jet_constit37_phi := VBFMVA.lead_jet_c37_phi",
    "lead_jet_constit38_phi := VBFMVA.lead_jet_c38_phi",
    "lead_jet_constit39_phi := VBFMVA.lead_jet_c39_phi",
    "lead_jet_constit40_phi := VBFMVA.lead_jet_c40_phi",
    "lead_jet_constit41_phi := VBFMVA.lead_jet_c41_phi",
    "lead_jet_constit42_phi := VBFMVA.lead_jet_c42_phi",
    "lead_jet_constit43_phi := VBFMVA.lead_jet_c43_phi",
    "lead_jet_constit44_phi := VBFMVA.lead_jet_c44_phi",
    "lead_jet_constit45_phi := VBFMVA.lead_jet_c45_phi",
    "lead_jet_constit46_phi := VBFMVA.lead_jet_c46_phi",
    "lead_jet_constit47_phi := VBFMVA.lead_jet_c47_phi",
    "lead_jet_constit48_phi := VBFMVA.lead_jet_c48_phi",
    "lead_jet_constit49_phi := VBFMVA.lead_jet_c49_phi",
    "lead_jet_constit50_phi := VBFMVA.lead_jet_c50_phi",
    "lead_jet_constit51_phi := VBFMVA.lead_jet_c51_phi",
    "lead_jet_constit52_phi := VBFMVA.lead_jet_c52_phi",
    "lead_jet_constit53_phi := VBFMVA.lead_jet_c53_phi",
    "lead_jet_constit54_phi := VBFMVA.lead_jet_c54_phi",
    "lead_jet_constit55_phi := VBFMVA.lead_jet_c55_phi",
    "lead_jet_constit56_phi := VBFMVA.lead_jet_c56_phi",
    "lead_jet_constit57_phi := VBFMVA.lead_jet_c57_phi",
    "lead_jet_constit58_phi := VBFMVA.lead_jet_c58_phi",
    "lead_jet_constit59_phi := VBFMVA.lead_jet_c59_phi",
    "lead_jet_constit60_phi := VBFMVA.lead_jet_c60_phi",

    "lead_jet_constit1_charge := VBFMVA.lead_jet_c1_charge",
    "lead_jet_constit2_charge := VBFMVA.lead_jet_c2_charge",
    "lead_jet_constit3_charge := VBFMVA.lead_jet_c3_charge",
    "lead_jet_constit4_charge := VBFMVA.lead_jet_c4_charge",
    "lead_jet_constit5_charge := VBFMVA.lead_jet_c5_charge",
    "lead_jet_constit6_charge := VBFMVA.lead_jet_c6_charge",
    "lead_jet_constit7_charge := VBFMVA.lead_jet_c7_charge",
    "lead_jet_constit8_charge := VBFMVA.lead_jet_c8_charge",
    "lead_jet_constit9_charge := VBFMVA.lead_jet_c9_charge",
    "lead_jet_constit10_charge := VBFMVA.lead_jet_c10_charge",
    "lead_jet_constit11_charge := VBFMVA.lead_jet_c11_charge",
    "lead_jet_constit12_charge := VBFMVA.lead_jet_c12_charge",
    "lead_jet_constit13_charge := VBFMVA.lead_jet_c13_charge",
    "lead_jet_constit14_charge := VBFMVA.lead_jet_c14_charge",
    "lead_jet_constit15_charge := VBFMVA.lead_jet_c15_charge",
    "lead_jet_constit16_charge := VBFMVA.lead_jet_c16_charge",
    "lead_jet_constit17_charge := VBFMVA.lead_jet_c17_charge",
    "lead_jet_constit18_charge := VBFMVA.lead_jet_c18_charge",
    "lead_jet_constit19_charge := VBFMVA.lead_jet_c19_charge",
    "lead_jet_constit20_charge := VBFMVA.lead_jet_c20_charge",
    "lead_jet_constit21_charge := VBFMVA.lead_jet_c21_charge",
    "lead_jet_constit22_charge := VBFMVA.lead_jet_c22_charge",
    "lead_jet_constit23_charge := VBFMVA.lead_jet_c23_charge",
    "lead_jet_constit24_charge := VBFMVA.lead_jet_c24_charge",
    "lead_jet_constit25_charge := VBFMVA.lead_jet_c25_charge",
    "lead_jet_constit26_charge := VBFMVA.lead_jet_c26_charge",
    "lead_jet_constit27_charge := VBFMVA.lead_jet_c27_charge",
    "lead_jet_constit28_charge := VBFMVA.lead_jet_c28_charge",
    "lead_jet_constit29_charge := VBFMVA.lead_jet_c29_charge",
    "lead_jet_constit30_charge := VBFMVA.lead_jet_c30_charge",
    "lead_jet_constit31_charge := VBFMVA.lead_jet_c31_charge",
    "lead_jet_constit32_charge := VBFMVA.lead_jet_c32_charge",
    "lead_jet_constit33_charge := VBFMVA.lead_jet_c33_charge",
    "lead_jet_constit34_charge := VBFMVA.lead_jet_c34_charge",
    "lead_jet_constit35_charge := VBFMVA.lead_jet_c35_charge",
    "lead_jet_constit36_charge := VBFMVA.lead_jet_c36_charge",
    "lead_jet_constit37_charge := VBFMVA.lead_jet_c37_charge",
    "lead_jet_constit38_charge := VBFMVA.lead_jet_c38_charge",
    "lead_jet_constit39_charge := VBFMVA.lead_jet_c39_charge",
    "lead_jet_constit40_charge := VBFMVA.lead_jet_c40_charge",
    "lead_jet_constit41_charge := VBFMVA.lead_jet_c41_charge",
    "lead_jet_constit42_charge := VBFMVA.lead_jet_c42_charge",
    "lead_jet_constit43_charge := VBFMVA.lead_jet_c43_charge",
    "lead_jet_constit44_charge := VBFMVA.lead_jet_c44_charge",
    "lead_jet_constit45_charge := VBFMVA.lead_jet_c45_charge",
    "lead_jet_constit46_charge := VBFMVA.lead_jet_c46_charge",
    "lead_jet_constit47_charge := VBFMVA.lead_jet_c47_charge",
    "lead_jet_constit48_charge := VBFMVA.lead_jet_c48_charge",
    "lead_jet_constit49_charge := VBFMVA.lead_jet_c49_charge",
    "lead_jet_constit50_charge := VBFMVA.lead_jet_c50_charge",
    "lead_jet_constit51_charge := VBFMVA.lead_jet_c51_charge",
    "lead_jet_constit52_charge := VBFMVA.lead_jet_c52_charge",
    "lead_jet_constit53_charge := VBFMVA.lead_jet_c53_charge",
    "lead_jet_constit54_charge := VBFMVA.lead_jet_c54_charge",
    "lead_jet_constit55_charge := VBFMVA.lead_jet_c55_charge",
    "lead_jet_constit56_charge := VBFMVA.lead_jet_c56_charge",
    "lead_jet_constit57_charge := VBFMVA.lead_jet_c57_charge",
    "lead_jet_constit58_charge := VBFMVA.lead_jet_c58_charge",
    "lead_jet_constit59_charge := VBFMVA.lead_jet_c59_charge",
    "lead_jet_constit60_charge := VBFMVA.lead_jet_c60_charge",

    "lead_jet_constit1_pt := VBFMVA.lead_jet_c1_pt",
    "lead_jet_constit2_pt := VBFMVA.lead_jet_c2_pt",
    "lead_jet_constit3_pt := VBFMVA.lead_jet_c3_pt",
    "lead_jet_constit4_pt := VBFMVA.lead_jet_c4_pt",
    "lead_jet_constit5_pt := VBFMVA.lead_jet_c5_pt",
    "lead_jet_constit6_pt := VBFMVA.lead_jet_c6_pt",
    "lead_jet_constit7_pt := VBFMVA.lead_jet_c7_pt",
    "lead_jet_constit8_pt := VBFMVA.lead_jet_c8_pt",
    "lead_jet_constit9_pt := VBFMVA.lead_jet_c9_pt",
    "lead_jet_constit10_pt := VBFMVA.lead_jet_c10_pt",
    "lead_jet_constit11_pt := VBFMVA.lead_jet_c11_pt",
    "lead_jet_constit12_pt := VBFMVA.lead_jet_c12_pt",
    "lead_jet_constit13_pt := VBFMVA.lead_jet_c13_pt",
    "lead_jet_constit14_pt := VBFMVA.lead_jet_c14_pt",
    "lead_jet_constit15_pt := VBFMVA.lead_jet_c15_pt",
    "lead_jet_constit16_pt := VBFMVA.lead_jet_c16_pt",
    "lead_jet_constit17_pt := VBFMVA.lead_jet_c17_pt",
    "lead_jet_constit18_pt := VBFMVA.lead_jet_c18_pt",
    "lead_jet_constit19_pt := VBFMVA.lead_jet_c19_pt",
    "lead_jet_constit20_pt := VBFMVA.lead_jet_c20_pt",
    "lead_jet_constit21_pt := VBFMVA.lead_jet_c21_pt",
    "lead_jet_constit22_pt := VBFMVA.lead_jet_c22_pt",
    "lead_jet_constit23_pt := VBFMVA.lead_jet_c23_pt",
    "lead_jet_constit24_pt := VBFMVA.lead_jet_c24_pt",
    "lead_jet_constit25_pt := VBFMVA.lead_jet_c25_pt",
    "lead_jet_constit26_pt := VBFMVA.lead_jet_c26_pt",
    "lead_jet_constit27_pt := VBFMVA.lead_jet_c27_pt",
    "lead_jet_constit28_pt := VBFMVA.lead_jet_c28_pt",
    "lead_jet_constit29_pt := VBFMVA.lead_jet_c29_pt",
    "lead_jet_constit30_pt := VBFMVA.lead_jet_c30_pt",
    "lead_jet_constit31_pt := VBFMVA.lead_jet_c31_pt",
    "lead_jet_constit32_pt := VBFMVA.lead_jet_c32_pt",
    "lead_jet_constit33_pt := VBFMVA.lead_jet_c33_pt",
    "lead_jet_constit34_pt := VBFMVA.lead_jet_c34_pt",
    "lead_jet_constit35_pt := VBFMVA.lead_jet_c35_pt",
    "lead_jet_constit36_pt := VBFMVA.lead_jet_c36_pt",
    "lead_jet_constit37_pt := VBFMVA.lead_jet_c37_pt",
    "lead_jet_constit38_pt := VBFMVA.lead_jet_c38_pt",
    "lead_jet_constit39_pt := VBFMVA.lead_jet_c39_pt",
    "lead_jet_constit40_pt := VBFMVA.lead_jet_c40_pt",
    "lead_jet_constit41_pt := VBFMVA.lead_jet_c41_pt",
    "lead_jet_constit42_pt := VBFMVA.lead_jet_c42_pt",
    "lead_jet_constit43_pt := VBFMVA.lead_jet_c43_pt",
    "lead_jet_constit44_pt := VBFMVA.lead_jet_c44_pt",
    "lead_jet_constit45_pt := VBFMVA.lead_jet_c45_pt",
    "lead_jet_constit46_pt := VBFMVA.lead_jet_c46_pt",
    "lead_jet_constit47_pt := VBFMVA.lead_jet_c47_pt",
    "lead_jet_constit48_pt := VBFMVA.lead_jet_c48_pt",
    "lead_jet_constit49_pt := VBFMVA.lead_jet_c49_pt",
    "lead_jet_constit50_pt := VBFMVA.lead_jet_c50_pt",
    "lead_jet_constit51_pt := VBFMVA.lead_jet_c51_pt",
    "lead_jet_constit52_pt := VBFMVA.lead_jet_c52_pt",
    "lead_jet_constit53_pt := VBFMVA.lead_jet_c53_pt",
    "lead_jet_constit54_pt := VBFMVA.lead_jet_c54_pt",
    "lead_jet_constit55_pt := VBFMVA.lead_jet_c55_pt",
    "lead_jet_constit56_pt := VBFMVA.lead_jet_c56_pt",
    "lead_jet_constit57_pt := VBFMVA.lead_jet_c57_pt",
    "lead_jet_constit58_pt := VBFMVA.lead_jet_c58_pt",
    "lead_jet_constit59_pt := VBFMVA.lead_jet_c59_pt",
    "lead_jet_constit60_pt := VBFMVA.lead_jet_c60_pt",

    "lead_jet_constit1_energy := VBFMVA.lead_jet_c1_energy",
    "lead_jet_constit2_energy := VBFMVA.lead_jet_c2_energy",
    "lead_jet_constit3_energy := VBFMVA.lead_jet_c3_energy",
    "lead_jet_constit4_energy := VBFMVA.lead_jet_c4_energy",
    "lead_jet_constit5_energy := VBFMVA.lead_jet_c5_energy",
    "lead_jet_constit6_energy := VBFMVA.lead_jet_c6_energy",
    "lead_jet_constit7_energy := VBFMVA.lead_jet_c7_energy",
    "lead_jet_constit8_energy := VBFMVA.lead_jet_c8_energy",
    "lead_jet_constit9_energy := VBFMVA.lead_jet_c9_energy",
    "lead_jet_constit10_energy := VBFMVA.lead_jet_c10_energy",
    "lead_jet_constit11_energy := VBFMVA.lead_jet_c11_energy",
    "lead_jet_constit12_energy := VBFMVA.lead_jet_c12_energy",
    "lead_jet_constit13_energy := VBFMVA.lead_jet_c13_energy",
    "lead_jet_constit14_energy := VBFMVA.lead_jet_c14_energy",
    "lead_jet_constit15_energy := VBFMVA.lead_jet_c15_energy",
    "lead_jet_constit16_energy := VBFMVA.lead_jet_c16_energy",
    "lead_jet_constit17_energy := VBFMVA.lead_jet_c17_energy",
    "lead_jet_constit18_energy := VBFMVA.lead_jet_c18_energy",
    "lead_jet_constit19_energy := VBFMVA.lead_jet_c19_energy",
    "lead_jet_constit20_energy := VBFMVA.lead_jet_c20_energy",
    "lead_jet_constit21_energy := VBFMVA.lead_jet_c21_energy",
    "lead_jet_constit22_energy := VBFMVA.lead_jet_c22_energy",
    "lead_jet_constit23_energy := VBFMVA.lead_jet_c23_energy",
    "lead_jet_constit24_energy := VBFMVA.lead_jet_c24_energy",
    "lead_jet_constit25_energy := VBFMVA.lead_jet_c25_energy",
    "lead_jet_constit26_energy := VBFMVA.lead_jet_c26_energy",
    "lead_jet_constit27_energy := VBFMVA.lead_jet_c27_energy",
    "lead_jet_constit28_energy := VBFMVA.lead_jet_c28_energy",
    "lead_jet_constit29_energy := VBFMVA.lead_jet_c29_energy",
    "lead_jet_constit30_energy := VBFMVA.lead_jet_c30_energy",
    "lead_jet_constit31_energy := VBFMVA.lead_jet_c31_energy",
    "lead_jet_constit32_energy := VBFMVA.lead_jet_c32_energy",
    "lead_jet_constit33_energy := VBFMVA.lead_jet_c33_energy",
    "lead_jet_constit34_energy := VBFMVA.lead_jet_c34_energy",
    "lead_jet_constit35_energy := VBFMVA.lead_jet_c35_energy",
    "lead_jet_constit36_energy := VBFMVA.lead_jet_c36_energy",
    "lead_jet_constit37_energy := VBFMVA.lead_jet_c37_energy",
    "lead_jet_constit38_energy := VBFMVA.lead_jet_c38_energy",
    "lead_jet_constit39_energy := VBFMVA.lead_jet_c39_energy",
    "lead_jet_constit40_energy := VBFMVA.lead_jet_c40_energy",
    "lead_jet_constit41_energy := VBFMVA.lead_jet_c41_energy",
    "lead_jet_constit42_energy := VBFMVA.lead_jet_c42_energy",
    "lead_jet_constit43_energy := VBFMVA.lead_jet_c43_energy",
    "lead_jet_constit44_energy := VBFMVA.lead_jet_c44_energy",
    "lead_jet_constit45_energy := VBFMVA.lead_jet_c45_energy",
    "lead_jet_constit46_energy := VBFMVA.lead_jet_c46_energy",
    "lead_jet_constit47_energy := VBFMVA.lead_jet_c47_energy",
    "lead_jet_constit48_energy := VBFMVA.lead_jet_c48_energy",
    "lead_jet_constit49_energy := VBFMVA.lead_jet_c49_energy",
    "lead_jet_constit50_energy := VBFMVA.lead_jet_c50_energy",
    "lead_jet_constit51_energy := VBFMVA.lead_jet_c51_energy",
    "lead_jet_constit52_energy := VBFMVA.lead_jet_c52_energy",
    "lead_jet_constit53_energy := VBFMVA.lead_jet_c53_energy",
    "lead_jet_constit54_energy := VBFMVA.lead_jet_c54_energy",
    "lead_jet_constit55_energy := VBFMVA.lead_jet_c55_energy",
    "lead_jet_constit56_energy := VBFMVA.lead_jet_c56_energy",
    "lead_jet_constit57_energy := VBFMVA.lead_jet_c57_energy",
    "lead_jet_constit58_energy := VBFMVA.lead_jet_c58_energy",
    "lead_jet_constit59_energy := VBFMVA.lead_jet_c59_energy",
    "lead_jet_constit60_energy := VBFMVA.lead_jet_c60_energy",

    "sublead_jet_constit1_eta := VBFMVA.sublead_jet_c1_eta",
    "sublead_jet_constit2_eta := VBFMVA.sublead_jet_c2_eta",
    "sublead_jet_constit3_eta := VBFMVA.sublead_jet_c3_eta",
    "sublead_jet_constit4_eta := VBFMVA.sublead_jet_c4_eta",
    "sublead_jet_constit5_eta := VBFMVA.sublead_jet_c5_eta",
    "sublead_jet_constit6_eta := VBFMVA.sublead_jet_c6_eta",
    "sublead_jet_constit7_eta := VBFMVA.sublead_jet_c7_eta",
    "sublead_jet_constit8_eta := VBFMVA.sublead_jet_c8_eta",
    "sublead_jet_constit9_eta := VBFMVA.sublead_jet_c9_eta",
    "sublead_jet_constit10_eta := VBFMVA.sublead_jet_c10_eta",
    "sublead_jet_constit11_eta := VBFMVA.sublead_jet_c11_eta",
    "sublead_jet_constit12_eta := VBFMVA.sublead_jet_c12_eta",
    "sublead_jet_constit13_eta := VBFMVA.sublead_jet_c13_eta",
    "sublead_jet_constit14_eta := VBFMVA.sublead_jet_c14_eta",
    "sublead_jet_constit15_eta := VBFMVA.sublead_jet_c15_eta",
    "sublead_jet_constit16_eta := VBFMVA.sublead_jet_c16_eta",
    "sublead_jet_constit17_eta := VBFMVA.sublead_jet_c17_eta",
    "sublead_jet_constit18_eta := VBFMVA.sublead_jet_c18_eta",
    "sublead_jet_constit19_eta := VBFMVA.sublead_jet_c19_eta",
    "sublead_jet_constit20_eta := VBFMVA.sublead_jet_c20_eta",
    "sublead_jet_constit21_eta := VBFMVA.sublead_jet_c21_eta",
    "sublead_jet_constit22_eta := VBFMVA.sublead_jet_c22_eta",
    "sublead_jet_constit23_eta := VBFMVA.sublead_jet_c23_eta",
    "sublead_jet_constit24_eta := VBFMVA.sublead_jet_c24_eta",
    "sublead_jet_constit25_eta := VBFMVA.sublead_jet_c25_eta",
    "sublead_jet_constit26_eta := VBFMVA.sublead_jet_c26_eta",
    "sublead_jet_constit27_eta := VBFMVA.sublead_jet_c27_eta",
    "sublead_jet_constit28_eta := VBFMVA.sublead_jet_c28_eta",
    "sublead_jet_constit29_eta := VBFMVA.sublead_jet_c29_eta",
    "sublead_jet_constit30_eta := VBFMVA.sublead_jet_c30_eta",
    "sublead_jet_constit31_eta := VBFMVA.sublead_jet_c31_eta",
    "sublead_jet_constit32_eta := VBFMVA.sublead_jet_c32_eta",
    "sublead_jet_constit33_eta := VBFMVA.sublead_jet_c33_eta",
    "sublead_jet_constit34_eta := VBFMVA.sublead_jet_c34_eta",
    "sublead_jet_constit35_eta := VBFMVA.sublead_jet_c35_eta",
    "sublead_jet_constit36_eta := VBFMVA.sublead_jet_c36_eta",
    "sublead_jet_constit37_eta := VBFMVA.sublead_jet_c37_eta",
    "sublead_jet_constit38_eta := VBFMVA.sublead_jet_c38_eta",
    "sublead_jet_constit39_eta := VBFMVA.sublead_jet_c39_eta",
    "sublead_jet_constit40_eta := VBFMVA.sublead_jet_c40_eta",
    "sublead_jet_constit41_eta := VBFMVA.sublead_jet_c41_eta",
    "sublead_jet_constit42_eta := VBFMVA.sublead_jet_c42_eta",
    "sublead_jet_constit43_eta := VBFMVA.sublead_jet_c43_eta",
    "sublead_jet_constit44_eta := VBFMVA.sublead_jet_c44_eta",
    "sublead_jet_constit45_eta := VBFMVA.sublead_jet_c45_eta",
    "sublead_jet_constit46_eta := VBFMVA.sublead_jet_c46_eta",
    "sublead_jet_constit47_eta := VBFMVA.sublead_jet_c47_eta",
    "sublead_jet_constit48_eta := VBFMVA.sublead_jet_c48_eta",
    "sublead_jet_constit49_eta := VBFMVA.sublead_jet_c49_eta",
    "sublead_jet_constit50_eta := VBFMVA.sublead_jet_c50_eta",
    "sublead_jet_constit51_eta := VBFMVA.sublead_jet_c51_eta",
    "sublead_jet_constit52_eta := VBFMVA.sublead_jet_c52_eta",
    "sublead_jet_constit53_eta := VBFMVA.sublead_jet_c53_eta",
    "sublead_jet_constit54_eta := VBFMVA.sublead_jet_c54_eta",
    "sublead_jet_constit55_eta := VBFMVA.sublead_jet_c55_eta",
    "sublead_jet_constit56_eta := VBFMVA.sublead_jet_c56_eta",
    "sublead_jet_constit57_eta := VBFMVA.sublead_jet_c57_eta",
    "sublead_jet_constit58_eta := VBFMVA.sublead_jet_c58_eta",
    "sublead_jet_constit59_eta := VBFMVA.sublead_jet_c59_eta",
    "sublead_jet_constit60_eta := VBFMVA.sublead_jet_c60_eta",

    "sublead_jet_constit1_phi := VBFMVA.sublead_jet_c1_phi",
    "sublead_jet_constit2_phi := VBFMVA.sublead_jet_c2_phi",
    "sublead_jet_constit3_phi := VBFMVA.sublead_jet_c3_phi",
    "sublead_jet_constit4_phi := VBFMVA.sublead_jet_c4_phi",
    "sublead_jet_constit5_phi := VBFMVA.sublead_jet_c5_phi",
    "sublead_jet_constit6_phi := VBFMVA.sublead_jet_c6_phi",
    "sublead_jet_constit7_phi := VBFMVA.sublead_jet_c7_phi",
    "sublead_jet_constit8_phi := VBFMVA.sublead_jet_c8_phi",
    "sublead_jet_constit9_phi := VBFMVA.sublead_jet_c9_phi",
    "sublead_jet_constit10_phi := VBFMVA.sublead_jet_c10_phi",
    "sublead_jet_constit11_phi := VBFMVA.sublead_jet_c11_phi",
    "sublead_jet_constit12_phi := VBFMVA.sublead_jet_c12_phi",
    "sublead_jet_constit13_phi := VBFMVA.sublead_jet_c13_phi",
    "sublead_jet_constit14_phi := VBFMVA.sublead_jet_c14_phi",
    "sublead_jet_constit15_phi := VBFMVA.sublead_jet_c15_phi",
    "sublead_jet_constit16_phi := VBFMVA.sublead_jet_c16_phi",
    "sublead_jet_constit17_phi := VBFMVA.sublead_jet_c17_phi",
    "sublead_jet_constit18_phi := VBFMVA.sublead_jet_c18_phi",
    "sublead_jet_constit19_phi := VBFMVA.sublead_jet_c19_phi",
    "sublead_jet_constit20_phi := VBFMVA.sublead_jet_c20_phi",
    "sublead_jet_constit21_phi := VBFMVA.sublead_jet_c21_phi",
    "sublead_jet_constit22_phi := VBFMVA.sublead_jet_c22_phi",
    "sublead_jet_constit23_phi := VBFMVA.sublead_jet_c23_phi",
    "sublead_jet_constit24_phi := VBFMVA.sublead_jet_c24_phi",
    "sublead_jet_constit25_phi := VBFMVA.sublead_jet_c25_phi",
    "sublead_jet_constit26_phi := VBFMVA.sublead_jet_c26_phi",
    "sublead_jet_constit27_phi := VBFMVA.sublead_jet_c27_phi",
    "sublead_jet_constit28_phi := VBFMVA.sublead_jet_c28_phi",
    "sublead_jet_constit29_phi := VBFMVA.sublead_jet_c29_phi",
    "sublead_jet_constit30_phi := VBFMVA.sublead_jet_c30_phi",
    "sublead_jet_constit31_phi := VBFMVA.sublead_jet_c31_phi",
    "sublead_jet_constit32_phi := VBFMVA.sublead_jet_c32_phi",
    "sublead_jet_constit33_phi := VBFMVA.sublead_jet_c33_phi",
    "sublead_jet_constit34_phi := VBFMVA.sublead_jet_c34_phi",
    "sublead_jet_constit35_phi := VBFMVA.sublead_jet_c35_phi",
    "sublead_jet_constit36_phi := VBFMVA.sublead_jet_c36_phi",
    "sublead_jet_constit37_phi := VBFMVA.sublead_jet_c37_phi",
    "sublead_jet_constit38_phi := VBFMVA.sublead_jet_c38_phi",
    "sublead_jet_constit39_phi := VBFMVA.sublead_jet_c39_phi",
    "sublead_jet_constit40_phi := VBFMVA.sublead_jet_c40_phi",
    "sublead_jet_constit41_phi := VBFMVA.sublead_jet_c41_phi",
    "sublead_jet_constit42_phi := VBFMVA.sublead_jet_c42_phi",
    "sublead_jet_constit43_phi := VBFMVA.sublead_jet_c43_phi",
    "sublead_jet_constit44_phi := VBFMVA.sublead_jet_c44_phi",
    "sublead_jet_constit45_phi := VBFMVA.sublead_jet_c45_phi",
    "sublead_jet_constit46_phi := VBFMVA.sublead_jet_c46_phi",
    "sublead_jet_constit47_phi := VBFMVA.sublead_jet_c47_phi",
    "sublead_jet_constit48_phi := VBFMVA.sublead_jet_c48_phi",
    "sublead_jet_constit49_phi := VBFMVA.sublead_jet_c49_phi",
    "sublead_jet_constit50_phi := VBFMVA.sublead_jet_c50_phi",
    "sublead_jet_constit51_phi := VBFMVA.sublead_jet_c51_phi",
    "sublead_jet_constit52_phi := VBFMVA.sublead_jet_c52_phi",
    "sublead_jet_constit53_phi := VBFMVA.sublead_jet_c53_phi",
    "sublead_jet_constit54_phi := VBFMVA.sublead_jet_c54_phi",
    "sublead_jet_constit55_phi := VBFMVA.sublead_jet_c55_phi",
    "sublead_jet_constit56_phi := VBFMVA.sublead_jet_c56_phi",
    "sublead_jet_constit57_phi := VBFMVA.sublead_jet_c57_phi",
    "sublead_jet_constit58_phi := VBFMVA.sublead_jet_c58_phi",
    "sublead_jet_constit59_phi := VBFMVA.sublead_jet_c59_phi",
    "sublead_jet_constit60_phi := VBFMVA.sublead_jet_c60_phi",

    "sublead_jet_constit1_charge := VBFMVA.sublead_jet_c1_charge",
    "sublead_jet_constit2_charge := VBFMVA.sublead_jet_c2_charge",
    "sublead_jet_constit3_charge := VBFMVA.sublead_jet_c3_charge",
    "sublead_jet_constit4_charge := VBFMVA.sublead_jet_c4_charge",
    "sublead_jet_constit5_charge := VBFMVA.sublead_jet_c5_charge",
    "sublead_jet_constit6_charge := VBFMVA.sublead_jet_c6_charge",
    "sublead_jet_constit7_charge := VBFMVA.sublead_jet_c7_charge",
    "sublead_jet_constit8_charge := VBFMVA.sublead_jet_c8_charge",
    "sublead_jet_constit9_charge := VBFMVA.sublead_jet_c9_charge",
    "sublead_jet_constit10_charge := VBFMVA.sublead_jet_c10_charge",
    "sublead_jet_constit11_charge := VBFMVA.sublead_jet_c11_charge",
    "sublead_jet_constit12_charge := VBFMVA.sublead_jet_c12_charge",
    "sublead_jet_constit13_charge := VBFMVA.sublead_jet_c13_charge",
    "sublead_jet_constit14_charge := VBFMVA.sublead_jet_c14_charge",
    "sublead_jet_constit15_charge := VBFMVA.sublead_jet_c15_charge",
    "sublead_jet_constit16_charge := VBFMVA.sublead_jet_c16_charge",
    "sublead_jet_constit17_charge := VBFMVA.sublead_jet_c17_charge",
    "sublead_jet_constit18_charge := VBFMVA.sublead_jet_c18_charge",
    "sublead_jet_constit19_charge := VBFMVA.sublead_jet_c19_charge",
    "sublead_jet_constit20_charge := VBFMVA.sublead_jet_c20_charge",
    "sublead_jet_constit21_charge := VBFMVA.sublead_jet_c21_charge",
    "sublead_jet_constit22_charge := VBFMVA.sublead_jet_c22_charge",
    "sublead_jet_constit23_charge := VBFMVA.sublead_jet_c23_charge",
    "sublead_jet_constit24_charge := VBFMVA.sublead_jet_c24_charge",
    "sublead_jet_constit25_charge := VBFMVA.sublead_jet_c25_charge",
    "sublead_jet_constit26_charge := VBFMVA.sublead_jet_c26_charge",
    "sublead_jet_constit27_charge := VBFMVA.sublead_jet_c27_charge",
    "sublead_jet_constit28_charge := VBFMVA.sublead_jet_c28_charge",
    "sublead_jet_constit29_charge := VBFMVA.sublead_jet_c29_charge",
    "sublead_jet_constit30_charge := VBFMVA.sublead_jet_c30_charge",
    "sublead_jet_constit31_charge := VBFMVA.sublead_jet_c31_charge",
    "sublead_jet_constit32_charge := VBFMVA.sublead_jet_c32_charge",
    "sublead_jet_constit33_charge := VBFMVA.sublead_jet_c33_charge",
    "sublead_jet_constit34_charge := VBFMVA.sublead_jet_c34_charge",
    "sublead_jet_constit35_charge := VBFMVA.sublead_jet_c35_charge",
    "sublead_jet_constit36_charge := VBFMVA.sublead_jet_c36_charge",
    "sublead_jet_constit37_charge := VBFMVA.sublead_jet_c37_charge",
    "sublead_jet_constit38_charge := VBFMVA.sublead_jet_c38_charge",
    "sublead_jet_constit39_charge := VBFMVA.sublead_jet_c39_charge",
    "sublead_jet_constit40_charge := VBFMVA.sublead_jet_c40_charge",
    "sublead_jet_constit41_charge := VBFMVA.sublead_jet_c41_charge",
    "sublead_jet_constit42_charge := VBFMVA.sublead_jet_c42_charge",
    "sublead_jet_constit43_charge := VBFMVA.sublead_jet_c43_charge",
    "sublead_jet_constit44_charge := VBFMVA.sublead_jet_c44_charge",
    "sublead_jet_constit45_charge := VBFMVA.sublead_jet_c45_charge",
    "sublead_jet_constit46_charge := VBFMVA.sublead_jet_c46_charge",
    "sublead_jet_constit47_charge := VBFMVA.sublead_jet_c47_charge",
    "sublead_jet_constit48_charge := VBFMVA.sublead_jet_c48_charge",
    "sublead_jet_constit49_charge := VBFMVA.sublead_jet_c49_charge",
    "sublead_jet_constit50_charge := VBFMVA.sublead_jet_c50_charge",
    "sublead_jet_constit51_charge := VBFMVA.sublead_jet_c51_charge",
    "sublead_jet_constit52_charge := VBFMVA.sublead_jet_c52_charge",
    "sublead_jet_constit53_charge := VBFMVA.sublead_jet_c53_charge",
    "sublead_jet_constit54_charge := VBFMVA.sublead_jet_c54_charge",
    "sublead_jet_constit55_charge := VBFMVA.sublead_jet_c55_charge",
    "sublead_jet_constit56_charge := VBFMVA.sublead_jet_c56_charge",
    "sublead_jet_constit57_charge := VBFMVA.sublead_jet_c57_charge",
    "sublead_jet_constit58_charge := VBFMVA.sublead_jet_c58_charge",
    "sublead_jet_constit59_charge := VBFMVA.sublead_jet_c59_charge",
    "sublead_jet_constit60_charge := VBFMVA.sublead_jet_c60_charge",

    "sublead_jet_constit1_pt := VBFMVA.sublead_jet_c1_pt",
    "sublead_jet_constit2_pt := VBFMVA.sublead_jet_c2_pt",
    "sublead_jet_constit3_pt := VBFMVA.sublead_jet_c3_pt",
    "sublead_jet_constit4_pt := VBFMVA.sublead_jet_c4_pt",
    "sublead_jet_constit5_pt := VBFMVA.sublead_jet_c5_pt",
    "sublead_jet_constit6_pt := VBFMVA.sublead_jet_c6_pt",
    "sublead_jet_constit7_pt := VBFMVA.sublead_jet_c7_pt",
    "sublead_jet_constit8_pt := VBFMVA.sublead_jet_c8_pt",
    "sublead_jet_constit9_pt := VBFMVA.sublead_jet_c9_pt",
    "sublead_jet_constit10_pt := VBFMVA.sublead_jet_c10_pt",
    "sublead_jet_constit11_pt := VBFMVA.sublead_jet_c11_pt",
    "sublead_jet_constit12_pt := VBFMVA.sublead_jet_c12_pt",
    "sublead_jet_constit13_pt := VBFMVA.sublead_jet_c13_pt",
    "sublead_jet_constit14_pt := VBFMVA.sublead_jet_c14_pt",
    "sublead_jet_constit15_pt := VBFMVA.sublead_jet_c15_pt",
    "sublead_jet_constit16_pt := VBFMVA.sublead_jet_c16_pt",
    "sublead_jet_constit17_pt := VBFMVA.sublead_jet_c17_pt",
    "sublead_jet_constit18_pt := VBFMVA.sublead_jet_c18_pt",
    "sublead_jet_constit19_pt := VBFMVA.sublead_jet_c19_pt",
    "sublead_jet_constit20_pt := VBFMVA.sublead_jet_c20_pt",
    "sublead_jet_constit21_pt := VBFMVA.sublead_jet_c21_pt",
    "sublead_jet_constit22_pt := VBFMVA.sublead_jet_c22_pt",
    "sublead_jet_constit23_pt := VBFMVA.sublead_jet_c23_pt",
    "sublead_jet_constit24_pt := VBFMVA.sublead_jet_c24_pt",
    "sublead_jet_constit25_pt := VBFMVA.sublead_jet_c25_pt",
    "sublead_jet_constit26_pt := VBFMVA.sublead_jet_c26_pt",
    "sublead_jet_constit27_pt := VBFMVA.sublead_jet_c27_pt",
    "sublead_jet_constit28_pt := VBFMVA.sublead_jet_c28_pt",
    "sublead_jet_constit29_pt := VBFMVA.sublead_jet_c29_pt",
    "sublead_jet_constit30_pt := VBFMVA.sublead_jet_c30_pt",
    "sublead_jet_constit31_pt := VBFMVA.sublead_jet_c31_pt",
    "sublead_jet_constit32_pt := VBFMVA.sublead_jet_c32_pt",
    "sublead_jet_constit33_pt := VBFMVA.sublead_jet_c33_pt",
    "sublead_jet_constit34_pt := VBFMVA.sublead_jet_c34_pt",
    "sublead_jet_constit35_pt := VBFMVA.sublead_jet_c35_pt",
    "sublead_jet_constit36_pt := VBFMVA.sublead_jet_c36_pt",
    "sublead_jet_constit37_pt := VBFMVA.sublead_jet_c37_pt",
    "sublead_jet_constit38_pt := VBFMVA.sublead_jet_c38_pt",
    "sublead_jet_constit39_pt := VBFMVA.sublead_jet_c39_pt",
    "sublead_jet_constit40_pt := VBFMVA.sublead_jet_c40_pt",
    "sublead_jet_constit41_pt := VBFMVA.sublead_jet_c41_pt",
    "sublead_jet_constit42_pt := VBFMVA.sublead_jet_c42_pt",
    "sublead_jet_constit43_pt := VBFMVA.sublead_jet_c43_pt",
    "sublead_jet_constit44_pt := VBFMVA.sublead_jet_c44_pt",
    "sublead_jet_constit45_pt := VBFMVA.sublead_jet_c45_pt",
    "sublead_jet_constit46_pt := VBFMVA.sublead_jet_c46_pt",
    "sublead_jet_constit47_pt := VBFMVA.sublead_jet_c47_pt",
    "sublead_jet_constit48_pt := VBFMVA.sublead_jet_c48_pt",
    "sublead_jet_constit49_pt := VBFMVA.sublead_jet_c49_pt",
    "sublead_jet_constit50_pt := VBFMVA.sublead_jet_c50_pt",
    "sublead_jet_constit51_pt := VBFMVA.sublead_jet_c51_pt",
    "sublead_jet_constit52_pt := VBFMVA.sublead_jet_c52_pt",
    "sublead_jet_constit53_pt := VBFMVA.sublead_jet_c53_pt",
    "sublead_jet_constit54_pt := VBFMVA.sublead_jet_c54_pt",
    "sublead_jet_constit55_pt := VBFMVA.sublead_jet_c55_pt",
    "sublead_jet_constit56_pt := VBFMVA.sublead_jet_c56_pt",
    "sublead_jet_constit57_pt := VBFMVA.sublead_jet_c57_pt",
    "sublead_jet_constit58_pt := VBFMVA.sublead_jet_c58_pt",
    "sublead_jet_constit59_pt := VBFMVA.sublead_jet_c59_pt",
    "sublead_jet_constit60_pt := VBFMVA.sublead_jet_c60_pt",

    "sublead_jet_constit1_energy := VBFMVA.sublead_jet_c1_energy",
    "sublead_jet_constit2_energy := VBFMVA.sublead_jet_c2_energy",
    "sublead_jet_constit3_energy := VBFMVA.sublead_jet_c3_energy",
    "sublead_jet_constit4_energy := VBFMVA.sublead_jet_c4_energy",
    "sublead_jet_constit5_energy := VBFMVA.sublead_jet_c5_energy",
    "sublead_jet_constit6_energy := VBFMVA.sublead_jet_c6_energy",
    "sublead_jet_constit7_energy := VBFMVA.sublead_jet_c7_energy",
    "sublead_jet_constit8_energy := VBFMVA.sublead_jet_c8_energy",
    "sublead_jet_constit9_energy := VBFMVA.sublead_jet_c9_energy",
    "sublead_jet_constit10_energy := VBFMVA.sublead_jet_c10_energy",
    "sublead_jet_constit11_energy := VBFMVA.sublead_jet_c11_energy",
    "sublead_jet_constit12_energy := VBFMVA.sublead_jet_c12_energy",
    "sublead_jet_constit13_energy := VBFMVA.sublead_jet_c13_energy",
    "sublead_jet_constit14_energy := VBFMVA.sublead_jet_c14_energy",
    "sublead_jet_constit15_energy := VBFMVA.sublead_jet_c15_energy",
    "sublead_jet_constit16_energy := VBFMVA.sublead_jet_c16_energy",
    "sublead_jet_constit17_energy := VBFMVA.sublead_jet_c17_energy",
    "sublead_jet_constit18_energy := VBFMVA.sublead_jet_c18_energy",
    "sublead_jet_constit19_energy := VBFMVA.sublead_jet_c19_energy",
    "sublead_jet_constit20_energy := VBFMVA.sublead_jet_c20_energy",
    "sublead_jet_constit21_energy := VBFMVA.sublead_jet_c21_energy",
    "sublead_jet_constit22_energy := VBFMVA.sublead_jet_c22_energy",
    "sublead_jet_constit23_energy := VBFMVA.sublead_jet_c23_energy",
    "sublead_jet_constit24_energy := VBFMVA.sublead_jet_c24_energy",
    "sublead_jet_constit25_energy := VBFMVA.sublead_jet_c25_energy",
    "sublead_jet_constit26_energy := VBFMVA.sublead_jet_c26_energy",
    "sublead_jet_constit27_energy := VBFMVA.sublead_jet_c27_energy",
    "sublead_jet_constit28_energy := VBFMVA.sublead_jet_c28_energy",
    "sublead_jet_constit29_energy := VBFMVA.sublead_jet_c29_energy",
    "sublead_jet_constit30_energy := VBFMVA.sublead_jet_c30_energy",
    "sublead_jet_constit31_energy := VBFMVA.sublead_jet_c31_energy",
    "sublead_jet_constit32_energy := VBFMVA.sublead_jet_c32_energy",
    "sublead_jet_constit33_energy := VBFMVA.sublead_jet_c33_energy",
    "sublead_jet_constit34_energy := VBFMVA.sublead_jet_c34_energy",
    "sublead_jet_constit35_energy := VBFMVA.sublead_jet_c35_energy",
    "sublead_jet_constit36_energy := VBFMVA.sublead_jet_c36_energy",
    "sublead_jet_constit37_energy := VBFMVA.sublead_jet_c37_energy",
    "sublead_jet_constit38_energy := VBFMVA.sublead_jet_c38_energy",
    "sublead_jet_constit39_energy := VBFMVA.sublead_jet_c39_energy",
    "sublead_jet_constit40_energy := VBFMVA.sublead_jet_c40_energy",
    "sublead_jet_constit41_energy := VBFMVA.sublead_jet_c41_energy",
    "sublead_jet_constit42_energy := VBFMVA.sublead_jet_c42_energy",
    "sublead_jet_constit43_energy := VBFMVA.sublead_jet_c43_energy",
    "sublead_jet_constit44_energy := VBFMVA.sublead_jet_c44_energy",
    "sublead_jet_constit45_energy := VBFMVA.sublead_jet_c45_energy",
    "sublead_jet_constit46_energy := VBFMVA.sublead_jet_c46_energy",
    "sublead_jet_constit47_energy := VBFMVA.sublead_jet_c47_energy",
    "sublead_jet_constit48_energy := VBFMVA.sublead_jet_c48_energy",
    "sublead_jet_constit49_energy := VBFMVA.sublead_jet_c49_energy",
    "sublead_jet_constit50_energy := VBFMVA.sublead_jet_c50_energy",
    "sublead_jet_constit51_energy := VBFMVA.sublead_jet_c51_energy",
    "sublead_jet_constit52_energy := VBFMVA.sublead_jet_c52_energy",
    "sublead_jet_constit53_energy := VBFMVA.sublead_jet_c53_energy",
    "sublead_jet_constit54_energy := VBFMVA.sublead_jet_c54_energy",
    "sublead_jet_constit55_energy := VBFMVA.sublead_jet_c55_energy",
    "sublead_jet_constit56_energy := VBFMVA.sublead_jet_c56_energy",
    "sublead_jet_constit57_energy := VBFMVA.sublead_jet_c57_energy",
    "sublead_jet_constit58_energy := VBFMVA.sublead_jet_c58_energy",
    "sublead_jet_constit59_energy := VBFMVA.sublead_jet_c59_energy",
    "sublead_jet_constit60_energy := VBFMVA.sublead_jet_c60_energy",

    "subsublead_jet_constit1_eta := VBFMVA.subsublead_jet_c1_eta",
    "subsublead_jet_constit2_eta := VBFMVA.subsublead_jet_c2_eta",
    "subsublead_jet_constit3_eta := VBFMVA.subsublead_jet_c3_eta",
    "subsublead_jet_constit4_eta := VBFMVA.subsublead_jet_c4_eta",
    "subsublead_jet_constit5_eta := VBFMVA.subsublead_jet_c5_eta",
    "subsublead_jet_constit6_eta := VBFMVA.subsublead_jet_c6_eta",
    "subsublead_jet_constit7_eta := VBFMVA.subsublead_jet_c7_eta",
    "subsublead_jet_constit8_eta := VBFMVA.subsublead_jet_c8_eta",
    "subsublead_jet_constit9_eta := VBFMVA.subsublead_jet_c9_eta",
    "subsublead_jet_constit10_eta := VBFMVA.subsublead_jet_c10_eta",
    "subsublead_jet_constit11_eta := VBFMVA.subsublead_jet_c11_eta",
    "subsublead_jet_constit12_eta := VBFMVA.subsublead_jet_c12_eta",
    "subsublead_jet_constit13_eta := VBFMVA.subsublead_jet_c13_eta",
    "subsublead_jet_constit14_eta := VBFMVA.subsublead_jet_c14_eta",
    "subsublead_jet_constit15_eta := VBFMVA.subsublead_jet_c15_eta",
    "subsublead_jet_constit16_eta := VBFMVA.subsublead_jet_c16_eta",
    "subsublead_jet_constit17_eta := VBFMVA.subsublead_jet_c17_eta",
    "subsublead_jet_constit18_eta := VBFMVA.subsublead_jet_c18_eta",
    "subsublead_jet_constit19_eta := VBFMVA.subsublead_jet_c19_eta",
    "subsublead_jet_constit20_eta := VBFMVA.subsublead_jet_c20_eta",
    "subsublead_jet_constit21_eta := VBFMVA.subsublead_jet_c21_eta",
    "subsublead_jet_constit22_eta := VBFMVA.subsublead_jet_c22_eta",
    "subsublead_jet_constit23_eta := VBFMVA.subsublead_jet_c23_eta",
    "subsublead_jet_constit24_eta := VBFMVA.subsublead_jet_c24_eta",
    "subsublead_jet_constit25_eta := VBFMVA.subsublead_jet_c25_eta",
    "subsublead_jet_constit26_eta := VBFMVA.subsublead_jet_c26_eta",
    "subsublead_jet_constit27_eta := VBFMVA.subsublead_jet_c27_eta",
    "subsublead_jet_constit28_eta := VBFMVA.subsublead_jet_c28_eta",
    "subsublead_jet_constit29_eta := VBFMVA.subsublead_jet_c29_eta",
    "subsublead_jet_constit30_eta := VBFMVA.subsublead_jet_c30_eta",
    "subsublead_jet_constit31_eta := VBFMVA.subsublead_jet_c31_eta",
    "subsublead_jet_constit32_eta := VBFMVA.subsublead_jet_c32_eta",
    "subsublead_jet_constit33_eta := VBFMVA.subsublead_jet_c33_eta",
    "subsublead_jet_constit34_eta := VBFMVA.subsublead_jet_c34_eta",
    "subsublead_jet_constit35_eta := VBFMVA.subsublead_jet_c35_eta",
    "subsublead_jet_constit36_eta := VBFMVA.subsublead_jet_c36_eta",
    "subsublead_jet_constit37_eta := VBFMVA.subsublead_jet_c37_eta",
    "subsublead_jet_constit38_eta := VBFMVA.subsublead_jet_c38_eta",
    "subsublead_jet_constit39_eta := VBFMVA.subsublead_jet_c39_eta",
    "subsublead_jet_constit40_eta := VBFMVA.subsublead_jet_c40_eta",
    "subsublead_jet_constit41_eta := VBFMVA.subsublead_jet_c41_eta",
    "subsublead_jet_constit42_eta := VBFMVA.subsublead_jet_c42_eta",
    "subsublead_jet_constit43_eta := VBFMVA.subsublead_jet_c43_eta",
    "subsublead_jet_constit44_eta := VBFMVA.subsublead_jet_c44_eta",
    "subsublead_jet_constit45_eta := VBFMVA.subsublead_jet_c45_eta",
    "subsublead_jet_constit46_eta := VBFMVA.subsublead_jet_c46_eta",
    "subsublead_jet_constit47_eta := VBFMVA.subsublead_jet_c47_eta",
    "subsublead_jet_constit48_eta := VBFMVA.subsublead_jet_c48_eta",
    "subsublead_jet_constit49_eta := VBFMVA.subsublead_jet_c49_eta",
    "subsublead_jet_constit50_eta := VBFMVA.subsublead_jet_c50_eta",
    "subsublead_jet_constit51_eta := VBFMVA.subsublead_jet_c51_eta",
    "subsublead_jet_constit52_eta := VBFMVA.subsublead_jet_c52_eta",
    "subsublead_jet_constit53_eta := VBFMVA.subsublead_jet_c53_eta",
    "subsublead_jet_constit54_eta := VBFMVA.subsublead_jet_c54_eta",
    "subsublead_jet_constit55_eta := VBFMVA.subsublead_jet_c55_eta",
    "subsublead_jet_constit56_eta := VBFMVA.subsublead_jet_c56_eta",
    "subsublead_jet_constit57_eta := VBFMVA.subsublead_jet_c57_eta",
    "subsublead_jet_constit58_eta := VBFMVA.subsublead_jet_c58_eta",
    "subsublead_jet_constit59_eta := VBFMVA.subsublead_jet_c59_eta",
    "subsublead_jet_constit60_eta := VBFMVA.subsublead_jet_c60_eta",

    "subsublead_jet_constit1_phi := VBFMVA.subsublead_jet_c1_phi",
    "subsublead_jet_constit2_phi := VBFMVA.subsublead_jet_c2_phi",
    "subsublead_jet_constit3_phi := VBFMVA.subsublead_jet_c3_phi",
    "subsublead_jet_constit4_phi := VBFMVA.subsublead_jet_c4_phi",
    "subsublead_jet_constit5_phi := VBFMVA.subsublead_jet_c5_phi",
    "subsublead_jet_constit6_phi := VBFMVA.subsublead_jet_c6_phi",
    "subsublead_jet_constit7_phi := VBFMVA.subsublead_jet_c7_phi",
    "subsublead_jet_constit8_phi := VBFMVA.subsublead_jet_c8_phi",
    "subsublead_jet_constit9_phi := VBFMVA.subsublead_jet_c9_phi",
    "subsublead_jet_constit10_phi := VBFMVA.subsublead_jet_c10_phi",
    "subsublead_jet_constit11_phi := VBFMVA.subsublead_jet_c11_phi",
    "subsublead_jet_constit12_phi := VBFMVA.subsublead_jet_c12_phi",
    "subsublead_jet_constit13_phi := VBFMVA.subsublead_jet_c13_phi",
    "subsublead_jet_constit14_phi := VBFMVA.subsublead_jet_c14_phi",
    "subsublead_jet_constit15_phi := VBFMVA.subsublead_jet_c15_phi",
    "subsublead_jet_constit16_phi := VBFMVA.subsublead_jet_c16_phi",
    "subsublead_jet_constit17_phi := VBFMVA.subsublead_jet_c17_phi",
    "subsublead_jet_constit18_phi := VBFMVA.subsublead_jet_c18_phi",
    "subsublead_jet_constit19_phi := VBFMVA.subsublead_jet_c19_phi",
    "subsublead_jet_constit20_phi := VBFMVA.subsublead_jet_c20_phi",
    "subsublead_jet_constit21_phi := VBFMVA.subsublead_jet_c21_phi",
    "subsublead_jet_constit22_phi := VBFMVA.subsublead_jet_c22_phi",
    "subsublead_jet_constit23_phi := VBFMVA.subsublead_jet_c23_phi",
    "subsublead_jet_constit24_phi := VBFMVA.subsublead_jet_c24_phi",
    "subsublead_jet_constit25_phi := VBFMVA.subsublead_jet_c25_phi",
    "subsublead_jet_constit26_phi := VBFMVA.subsublead_jet_c26_phi",
    "subsublead_jet_constit27_phi := VBFMVA.subsublead_jet_c27_phi",
    "subsublead_jet_constit28_phi := VBFMVA.subsublead_jet_c28_phi",
    "subsublead_jet_constit29_phi := VBFMVA.subsublead_jet_c29_phi",
    "subsublead_jet_constit30_phi := VBFMVA.subsublead_jet_c30_phi",
    "subsublead_jet_constit31_phi := VBFMVA.subsublead_jet_c31_phi",
    "subsublead_jet_constit32_phi := VBFMVA.subsublead_jet_c32_phi",
    "subsublead_jet_constit33_phi := VBFMVA.subsublead_jet_c33_phi",
    "subsublead_jet_constit34_phi := VBFMVA.subsublead_jet_c34_phi",
    "subsublead_jet_constit35_phi := VBFMVA.subsublead_jet_c35_phi",
    "subsublead_jet_constit36_phi := VBFMVA.subsublead_jet_c36_phi",
    "subsublead_jet_constit37_phi := VBFMVA.subsublead_jet_c37_phi",
    "subsublead_jet_constit38_phi := VBFMVA.subsublead_jet_c38_phi",
    "subsublead_jet_constit39_phi := VBFMVA.subsublead_jet_c39_phi",
    "subsublead_jet_constit40_phi := VBFMVA.subsublead_jet_c40_phi",
    "subsublead_jet_constit41_phi := VBFMVA.subsublead_jet_c41_phi",
    "subsublead_jet_constit42_phi := VBFMVA.subsublead_jet_c42_phi",
    "subsublead_jet_constit43_phi := VBFMVA.subsublead_jet_c43_phi",
    "subsublead_jet_constit44_phi := VBFMVA.subsublead_jet_c44_phi",
    "subsublead_jet_constit45_phi := VBFMVA.subsublead_jet_c45_phi",
    "subsublead_jet_constit46_phi := VBFMVA.subsublead_jet_c46_phi",
    "subsublead_jet_constit47_phi := VBFMVA.subsublead_jet_c47_phi",
    "subsublead_jet_constit48_phi := VBFMVA.subsublead_jet_c48_phi",
    "subsublead_jet_constit49_phi := VBFMVA.subsublead_jet_c49_phi",
    "subsublead_jet_constit50_phi := VBFMVA.subsublead_jet_c50_phi",
    "subsublead_jet_constit51_phi := VBFMVA.subsublead_jet_c51_phi",
    "subsublead_jet_constit52_phi := VBFMVA.subsublead_jet_c52_phi",
    "subsublead_jet_constit53_phi := VBFMVA.subsublead_jet_c53_phi",
    "subsublead_jet_constit54_phi := VBFMVA.subsublead_jet_c54_phi",
    "subsublead_jet_constit55_phi := VBFMVA.subsublead_jet_c55_phi",
    "subsublead_jet_constit56_phi := VBFMVA.subsublead_jet_c56_phi",
    "subsublead_jet_constit57_phi := VBFMVA.subsublead_jet_c57_phi",
    "subsublead_jet_constit58_phi := VBFMVA.subsublead_jet_c58_phi",
    "subsublead_jet_constit59_phi := VBFMVA.subsublead_jet_c59_phi",
    "subsublead_jet_constit60_phi := VBFMVA.subsublead_jet_c60_phi",

    "subsublead_jet_constit1_charge := VBFMVA.subsublead_jet_c1_charge",
    "subsublead_jet_constit2_charge := VBFMVA.subsublead_jet_c2_charge",
    "subsublead_jet_constit3_charge := VBFMVA.subsublead_jet_c3_charge",
    "subsublead_jet_constit4_charge := VBFMVA.subsublead_jet_c4_charge",
    "subsublead_jet_constit5_charge := VBFMVA.subsublead_jet_c5_charge",
    "subsublead_jet_constit6_charge := VBFMVA.subsublead_jet_c6_charge",
    "subsublead_jet_constit7_charge := VBFMVA.subsublead_jet_c7_charge",
    "subsublead_jet_constit8_charge := VBFMVA.subsublead_jet_c8_charge",
    "subsublead_jet_constit9_charge := VBFMVA.subsublead_jet_c9_charge",
    "subsublead_jet_constit10_charge := VBFMVA.subsublead_jet_c10_charge",
    "subsublead_jet_constit11_charge := VBFMVA.subsublead_jet_c11_charge",
    "subsublead_jet_constit12_charge := VBFMVA.subsublead_jet_c12_charge",
    "subsublead_jet_constit13_charge := VBFMVA.subsublead_jet_c13_charge",
    "subsublead_jet_constit14_charge := VBFMVA.subsublead_jet_c14_charge",
    "subsublead_jet_constit15_charge := VBFMVA.subsublead_jet_c15_charge",
    "subsublead_jet_constit16_charge := VBFMVA.subsublead_jet_c16_charge",
    "subsublead_jet_constit17_charge := VBFMVA.subsublead_jet_c17_charge",
    "subsublead_jet_constit18_charge := VBFMVA.subsublead_jet_c18_charge",
    "subsublead_jet_constit19_charge := VBFMVA.subsublead_jet_c19_charge",
    "subsublead_jet_constit20_charge := VBFMVA.subsublead_jet_c20_charge",
    "subsublead_jet_constit21_charge := VBFMVA.subsublead_jet_c21_charge",
    "subsublead_jet_constit22_charge := VBFMVA.subsublead_jet_c22_charge",
    "subsublead_jet_constit23_charge := VBFMVA.subsublead_jet_c23_charge",
    "subsublead_jet_constit24_charge := VBFMVA.subsublead_jet_c24_charge",
    "subsublead_jet_constit25_charge := VBFMVA.subsublead_jet_c25_charge",
    "subsublead_jet_constit26_charge := VBFMVA.subsublead_jet_c26_charge",
    "subsublead_jet_constit27_charge := VBFMVA.subsublead_jet_c27_charge",
    "subsublead_jet_constit28_charge := VBFMVA.subsublead_jet_c28_charge",
    "subsublead_jet_constit29_charge := VBFMVA.subsublead_jet_c29_charge",
    "subsublead_jet_constit30_charge := VBFMVA.subsublead_jet_c30_charge",
    "subsublead_jet_constit31_charge := VBFMVA.subsublead_jet_c31_charge",
    "subsublead_jet_constit32_charge := VBFMVA.subsublead_jet_c32_charge",
    "subsublead_jet_constit33_charge := VBFMVA.subsublead_jet_c33_charge",
    "subsublead_jet_constit34_charge := VBFMVA.subsublead_jet_c34_charge",
    "subsublead_jet_constit35_charge := VBFMVA.subsublead_jet_c35_charge",
    "subsublead_jet_constit36_charge := VBFMVA.subsublead_jet_c36_charge",
    "subsublead_jet_constit37_charge := VBFMVA.subsublead_jet_c37_charge",
    "subsublead_jet_constit38_charge := VBFMVA.subsublead_jet_c38_charge",
    "subsublead_jet_constit39_charge := VBFMVA.subsublead_jet_c39_charge",
    "subsublead_jet_constit40_charge := VBFMVA.subsublead_jet_c40_charge",
    "subsublead_jet_constit41_charge := VBFMVA.subsublead_jet_c41_charge",
    "subsublead_jet_constit42_charge := VBFMVA.subsublead_jet_c42_charge",
    "subsublead_jet_constit43_charge := VBFMVA.subsublead_jet_c43_charge",
    "subsublead_jet_constit44_charge := VBFMVA.subsublead_jet_c44_charge",
    "subsublead_jet_constit45_charge := VBFMVA.subsublead_jet_c45_charge",
    "subsublead_jet_constit46_charge := VBFMVA.subsublead_jet_c46_charge",
    "subsublead_jet_constit47_charge := VBFMVA.subsublead_jet_c47_charge",
    "subsublead_jet_constit48_charge := VBFMVA.subsublead_jet_c48_charge",
    "subsublead_jet_constit49_charge := VBFMVA.subsublead_jet_c49_charge",
    "subsublead_jet_constit50_charge := VBFMVA.subsublead_jet_c50_charge",
    "subsublead_jet_constit51_charge := VBFMVA.subsublead_jet_c51_charge",
    "subsublead_jet_constit52_charge := VBFMVA.subsublead_jet_c52_charge",
    "subsublead_jet_constit53_charge := VBFMVA.subsublead_jet_c53_charge",
    "subsublead_jet_constit54_charge := VBFMVA.subsublead_jet_c54_charge",
    "subsublead_jet_constit55_charge := VBFMVA.subsublead_jet_c55_charge",
    "subsublead_jet_constit56_charge := VBFMVA.subsublead_jet_c56_charge",
    "subsublead_jet_constit57_charge := VBFMVA.subsublead_jet_c57_charge",
    "subsublead_jet_constit58_charge := VBFMVA.subsublead_jet_c58_charge",
    "subsublead_jet_constit59_charge := VBFMVA.subsublead_jet_c59_charge",
    "subsublead_jet_constit60_charge := VBFMVA.subsublead_jet_c60_charge",

    "subsublead_jet_constit1_pt := VBFMVA.subsublead_jet_c1_pt",
    "subsublead_jet_constit2_pt := VBFMVA.subsublead_jet_c2_pt",
    "subsublead_jet_constit3_pt := VBFMVA.subsublead_jet_c3_pt",
    "subsublead_jet_constit4_pt := VBFMVA.subsublead_jet_c4_pt",
    "subsublead_jet_constit5_pt := VBFMVA.subsublead_jet_c5_pt",
    "subsublead_jet_constit6_pt := VBFMVA.subsublead_jet_c6_pt",
    "subsublead_jet_constit7_pt := VBFMVA.subsublead_jet_c7_pt",
    "subsublead_jet_constit8_pt := VBFMVA.subsublead_jet_c8_pt",
    "subsublead_jet_constit9_pt := VBFMVA.subsublead_jet_c9_pt",
    "subsublead_jet_constit10_pt := VBFMVA.subsublead_jet_c10_pt",
    "subsublead_jet_constit11_pt := VBFMVA.subsublead_jet_c11_pt",
    "subsublead_jet_constit12_pt := VBFMVA.subsublead_jet_c12_pt",
    "subsublead_jet_constit13_pt := VBFMVA.subsublead_jet_c13_pt",
    "subsublead_jet_constit14_pt := VBFMVA.subsublead_jet_c14_pt",
    "subsublead_jet_constit15_pt := VBFMVA.subsublead_jet_c15_pt",
    "subsublead_jet_constit16_pt := VBFMVA.subsublead_jet_c16_pt",
    "subsublead_jet_constit17_pt := VBFMVA.subsublead_jet_c17_pt",
    "subsublead_jet_constit18_pt := VBFMVA.subsublead_jet_c18_pt",
    "subsublead_jet_constit19_pt := VBFMVA.subsublead_jet_c19_pt",
    "subsublead_jet_constit20_pt := VBFMVA.subsublead_jet_c20_pt",
    "subsublead_jet_constit21_pt := VBFMVA.subsublead_jet_c21_pt",
    "subsublead_jet_constit22_pt := VBFMVA.subsublead_jet_c22_pt",
    "subsublead_jet_constit23_pt := VBFMVA.subsublead_jet_c23_pt",
    "subsublead_jet_constit24_pt := VBFMVA.subsublead_jet_c24_pt",
    "subsublead_jet_constit25_pt := VBFMVA.subsublead_jet_c25_pt",
    "subsublead_jet_constit26_pt := VBFMVA.subsublead_jet_c26_pt",
    "subsublead_jet_constit27_pt := VBFMVA.subsublead_jet_c27_pt",
    "subsublead_jet_constit28_pt := VBFMVA.subsublead_jet_c28_pt",
    "subsublead_jet_constit29_pt := VBFMVA.subsublead_jet_c29_pt",
    "subsublead_jet_constit30_pt := VBFMVA.subsublead_jet_c30_pt",
    "subsublead_jet_constit31_pt := VBFMVA.subsublead_jet_c31_pt",
    "subsublead_jet_constit32_pt := VBFMVA.subsublead_jet_c32_pt",
    "subsublead_jet_constit33_pt := VBFMVA.subsublead_jet_c33_pt",
    "subsublead_jet_constit34_pt := VBFMVA.subsublead_jet_c34_pt",
    "subsublead_jet_constit35_pt := VBFMVA.subsublead_jet_c35_pt",
    "subsublead_jet_constit36_pt := VBFMVA.subsublead_jet_c36_pt",
    "subsublead_jet_constit37_pt := VBFMVA.subsublead_jet_c37_pt",
    "subsublead_jet_constit38_pt := VBFMVA.subsublead_jet_c38_pt",
    "subsublead_jet_constit39_pt := VBFMVA.subsublead_jet_c39_pt",
    "subsublead_jet_constit40_pt := VBFMVA.subsublead_jet_c40_pt",
    "subsublead_jet_constit41_pt := VBFMVA.subsublead_jet_c41_pt",
    "subsublead_jet_constit42_pt := VBFMVA.subsublead_jet_c42_pt",
    "subsublead_jet_constit43_pt := VBFMVA.subsublead_jet_c43_pt",
    "subsublead_jet_constit44_pt := VBFMVA.subsublead_jet_c44_pt",
    "subsublead_jet_constit45_pt := VBFMVA.subsublead_jet_c45_pt",
    "subsublead_jet_constit46_pt := VBFMVA.subsublead_jet_c46_pt",
    "subsublead_jet_constit47_pt := VBFMVA.subsublead_jet_c47_pt",
    "subsublead_jet_constit48_pt := VBFMVA.subsublead_jet_c48_pt",
    "subsublead_jet_constit49_pt := VBFMVA.subsublead_jet_c49_pt",
    "subsublead_jet_constit50_pt := VBFMVA.subsublead_jet_c50_pt",
    "subsublead_jet_constit51_pt := VBFMVA.subsublead_jet_c51_pt",
    "subsublead_jet_constit52_pt := VBFMVA.subsublead_jet_c52_pt",
    "subsublead_jet_constit53_pt := VBFMVA.subsublead_jet_c53_pt",
    "subsublead_jet_constit54_pt := VBFMVA.subsublead_jet_c54_pt",
    "subsublead_jet_constit55_pt := VBFMVA.subsublead_jet_c55_pt",
    "subsublead_jet_constit56_pt := VBFMVA.subsublead_jet_c56_pt",
    "subsublead_jet_constit57_pt := VBFMVA.subsublead_jet_c57_pt",
    "subsublead_jet_constit58_pt := VBFMVA.subsublead_jet_c58_pt",
    "subsublead_jet_constit59_pt := VBFMVA.subsublead_jet_c59_pt",
    "subsublead_jet_constit60_pt := VBFMVA.subsublead_jet_c60_pt",

    "subsublead_jet_constit1_energy := VBFMVA.subsublead_jet_c1_energy",
    "subsublead_jet_constit2_energy := VBFMVA.subsublead_jet_c2_energy",
    "subsublead_jet_constit3_energy := VBFMVA.subsublead_jet_c3_energy",
    "subsublead_jet_constit4_energy := VBFMVA.subsublead_jet_c4_energy",
    "subsublead_jet_constit5_energy := VBFMVA.subsublead_jet_c5_energy",
    "subsublead_jet_constit6_energy := VBFMVA.subsublead_jet_c6_energy",
    "subsublead_jet_constit7_energy := VBFMVA.subsublead_jet_c7_energy",
    "subsublead_jet_constit8_energy := VBFMVA.subsublead_jet_c8_energy",
    "subsublead_jet_constit9_energy := VBFMVA.subsublead_jet_c9_energy",
    "subsublead_jet_constit10_energy := VBFMVA.subsublead_jet_c10_energy",
    "subsublead_jet_constit11_energy := VBFMVA.subsublead_jet_c11_energy",
    "subsublead_jet_constit12_energy := VBFMVA.subsublead_jet_c12_energy",
    "subsublead_jet_constit13_energy := VBFMVA.subsublead_jet_c13_energy",
    "subsublead_jet_constit14_energy := VBFMVA.subsublead_jet_c14_energy",
    "subsublead_jet_constit15_energy := VBFMVA.subsublead_jet_c15_energy",
    "subsublead_jet_constit16_energy := VBFMVA.subsublead_jet_c16_energy",
    "subsublead_jet_constit17_energy := VBFMVA.subsublead_jet_c17_energy",
    "subsublead_jet_constit18_energy := VBFMVA.subsublead_jet_c18_energy",
    "subsublead_jet_constit19_energy := VBFMVA.subsublead_jet_c19_energy",
    "subsublead_jet_constit20_energy := VBFMVA.subsublead_jet_c20_energy",
    "subsublead_jet_constit21_energy := VBFMVA.subsublead_jet_c21_energy",
    "subsublead_jet_constit22_energy := VBFMVA.subsublead_jet_c22_energy",
    "subsublead_jet_constit23_energy := VBFMVA.subsublead_jet_c23_energy",
    "subsublead_jet_constit24_energy := VBFMVA.subsublead_jet_c24_energy",
    "subsublead_jet_constit25_energy := VBFMVA.subsublead_jet_c25_energy",
    "subsublead_jet_constit26_energy := VBFMVA.subsublead_jet_c26_energy",
    "subsublead_jet_constit27_energy := VBFMVA.subsublead_jet_c27_energy",
    "subsublead_jet_constit28_energy := VBFMVA.subsublead_jet_c28_energy",
    "subsublead_jet_constit29_energy := VBFMVA.subsublead_jet_c29_energy",
    "subsublead_jet_constit30_energy := VBFMVA.subsublead_jet_c30_energy",
    "subsublead_jet_constit31_energy := VBFMVA.subsublead_jet_c31_energy",
    "subsublead_jet_constit32_energy := VBFMVA.subsublead_jet_c32_energy",
    "subsublead_jet_constit33_energy := VBFMVA.subsublead_jet_c33_energy",
    "subsublead_jet_constit34_energy := VBFMVA.subsublead_jet_c34_energy",
    "subsublead_jet_constit35_energy := VBFMVA.subsublead_jet_c35_energy",
    "subsublead_jet_constit36_energy := VBFMVA.subsublead_jet_c36_energy",
    "subsublead_jet_constit37_energy := VBFMVA.subsublead_jet_c37_energy",
    "subsublead_jet_constit38_energy := VBFMVA.subsublead_jet_c38_energy",
    "subsublead_jet_constit39_energy := VBFMVA.subsublead_jet_c39_energy",
    "subsublead_jet_constit40_energy := VBFMVA.subsublead_jet_c40_energy",
    "subsublead_jet_constit41_energy := VBFMVA.subsublead_jet_c41_energy",
    "subsublead_jet_constit42_energy := VBFMVA.subsublead_jet_c42_energy",
    "subsublead_jet_constit43_energy := VBFMVA.subsublead_jet_c43_energy",
    "subsublead_jet_constit44_energy := VBFMVA.subsublead_jet_c44_energy",
    "subsublead_jet_constit45_energy := VBFMVA.subsublead_jet_c45_energy",
    "subsublead_jet_constit46_energy := VBFMVA.subsublead_jet_c46_energy",
    "subsublead_jet_constit47_energy := VBFMVA.subsublead_jet_c47_energy",
    "subsublead_jet_constit48_energy := VBFMVA.subsublead_jet_c48_energy",
    "subsublead_jet_constit49_energy := VBFMVA.subsublead_jet_c49_energy",
    "subsublead_jet_constit50_energy := VBFMVA.subsublead_jet_c50_energy",
    "subsublead_jet_constit51_energy := VBFMVA.subsublead_jet_c51_energy",
    "subsublead_jet_constit52_energy := VBFMVA.subsublead_jet_c52_energy",
    "subsublead_jet_constit53_energy := VBFMVA.subsublead_jet_c53_energy",
    "subsublead_jet_constit54_energy := VBFMVA.subsublead_jet_c54_energy",
    "subsublead_jet_constit55_energy := VBFMVA.subsublead_jet_c55_energy",
    "subsublead_jet_constit56_energy := VBFMVA.subsublead_jet_c56_energy",
    "subsublead_jet_constit57_energy := VBFMVA.subsublead_jet_c57_energy",
    "subsublead_jet_constit58_energy := VBFMVA.subsublead_jet_c58_energy",
    "subsublead_jet_constit59_energy := VBFMVA.subsublead_jet_c59_energy",
    "subsublead_jet_constit60_energy := VBFMVA.subsublead_jet_c60_energy",
]

matching_photon = [
    "dijet_jet1_match := leadingJet_match",
    "dijet_jet2_match := subLeadingJet_match",
    "prompt_pho_1 := diPhoton.leadingPhoton.genMatchType()",
    "prompt_pho_2 := diPhoton.subLeadingPhoton.genMatchType()"
]

cloneTagSequenceForEachSystematic(process,
                                  systlabels=systlabels,
                                  phosystlabels=phosystlabels,
                                  jetsystlabels=jetsystlabels,
                                  jetSystematicsInputTags=jetSystematicsInputTags,
                                  ZPlusJetMode=2)

all_variables = var.dipho_variables + var.dijet_variables + new_variables

if customize.processId != "Data":
    all_variables += matching_photon# + jet_syst_weights
    all_variables += var.stxs_truth_variables

cats = []

if customize.dumpJetSysTrees and customize.processId != "Data" :
    for syst in (jetsystlabels+phosystlabels):
        systcutstring = "hasSyst(\"%s\") "%syst
        cats += [
            ("GeneralDipho_%s"%syst,"%s"%systcutstring,0)]#,
cats += [
    ("GeneralDipho","1",0)
]

cfgTools.addCategories(process.vbfTagDumper,
                       cats,
                       variables  = all_variables,
                       histograms = []
)

process.vbfTagDumper.nameTemplate = "$PROCESS_$SQRTS_$CLASSNAME_$SUBCAT_$LABEL"
from HLTrigger.HLTfilters.hltHighLevel_cfi import hltHighLevel
#FIXME could check if this is actually being executed, with the normal command (i.e. not my uAOD)
hlt_paths = []

for dset in customize.metaConditions["TriggerPaths"]:
    if customize.datasetName():
        if dset in customize.datasetName():
            hlt_paths.extend(customize.metaConditions["TriggerPaths"][dset])

process.hltHighLevel= hltHighLevel.clone(HLTPaths = cms.vstring(hlt_paths))

process.options      = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

# ee bad supercluster filter on data
process.load('RecoMET.METFilters.eeBadScFilter_cfi')
process.eeBadScFilter.EERecHitSource = cms.InputTag("reducedEgamma","reducedEERecHits")

process.dataRequirements = cms.Sequence()
if customize.processId == "Data":
    process.dataRequirements += process.hltHighLevel
    process.dataRequirements += process.eeBadScFilter

# Split WH and ZH
process.genFilter = cms.Sequence()
if (customize.processId.count("wh") or customize.processId.count("zh")) and not customize.processId.count("wzh"):
    process.load("flashgg/Systematics/VHFilter_cfi")
    process.genFilter += process.VHFilter
    process.VHFilter.chooseW = bool(customize.processId.count("wh"))
    process.VHFilter.chooseZ = bool(customize.processId.count("zh"))

# Split out prompt-fake or fake-fake
process.finalFilter = cms.Sequence()
if (customize.processId.count("qcd") or customize.processId.count("gjet")) and customize.processId.count("fake"):
    process.load("flashgg/Systematics/PromptFakeFilter_cfi")
    process.finalFilter += process.PromptFakeFilter
    if (customize.processId.count("promptfake")):
        process.PromptFakeFilter.doPromptFake = cms.bool(True)
        process.PromptFakeFilter.doFakeFake = cms.bool(False)
        process.PromptFakeFilter.doBoth = cms.bool(False)
    elif (customize.processId.count("fakefake")):
        process.PromptFakeFilter.doPromptFake = cms.bool(False)
        process.PromptFakeFilter.doFakeFake = cms.bool(True)
        process.PromptFakeFilter.doBoth = cms.bool(False)
    elif (customize.processId.count("anyfake")):
        process.PromptFakeFilter.doPromptFake = cms.bool(False)
        process.PromptFakeFilter.doFakeFake = cms.bool(False)
        process.PromptFakeFilter.doBoth = cms.bool(True)
    else:
        raise Exception,"Mis-configuration of python for prompt-fake filter"

process.p = cms.Path(process.dataRequirements
                     * process.genFilter
                     #* process.flashggUpdatedIdMVADiPhotons #replaced by version below now...
                     * process.flashggDifferentialPhoIdInputsCorrection
                     * process.flashggDiPhotonSystematics
                     * process.flashggMetSystematics
                     * process.flashggMuonSystematics
                     * process.flashggElectronSystematics
                     * (process.flashggUnpackedJets
                        * process.ak4PFCHSL1FastL2L3CorrectorChain
                        * process.jetSystematicsSequence)
                     * (process.flashggTagSequence
                        + process.systematicsTagSequences)
                     * process.flashggSystTagMerger
                     * process.finalFilter
                     * process.vbfTagDumper
                     )

print "--- Dumping modules that take diphotons as input: ---"
mns = process.p.moduleNames()
for mn in mns:
    module = getattr(process,mn)
    if hasattr(module,"src") and type(module.src) == type(cms.InputTag("")) and module.src.value().count("DiPhoton"):
        print str(module),module.src
    elif hasattr(module,"DiPhotonTag"):
        print str(module),module.DiPhotonTag
print
printSystematicInfo(process)

## rerun rivet for stage 1p1 info
if customize.useParentDataset:
    runRivetSequence(process, customize.metaConditions, customize.processId)

# call the customization
customize(process)
