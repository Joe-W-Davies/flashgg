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
process.load("flashgg.Taggers.flashggTagSequence_cfi")
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
'file:/afs/cern.ch/work/d/davies/flashgg/CMSSW_10_6_1_patch2/src/flashgg/myMicroAODOutputFileGGH10K.root'
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

    "lead_jet_flav            :=  tagTruth().flav_J1",
    "sub_lead_jet_flav        :=  tagTruth().flav_J2",
    "subsub_lead_jet_flav     :=  tagTruth().flav_J3",
    
    "n_constits := VBFMVA().n_constits",
                  
    "lead_jet_constit1_eta := VBFMVA.lead_jet_c1_eta",
    "lead_jet_constit2_eta := VBFMVA.lead_jet_c2_eta",
    "lead_jet_constit3_eta := VBFMVA.lead_jet_c3_eta",
    "lead_jet_constit4_eta := VBFMVA.lead_jet_c4_eta",
    "lead_jet_constit5_eta := VBFMVA.lead_jet_c5_eta",
    "lead_jet_constit6_eta := VBFMVA.lead_jet_c6_eta",
    "lead_jet_constit7_eta := VBFMVA.lead_jet_c7_eta",
    "lead_jet_constit8_eta := VBFMVA.lead_jet_c8_eta",
    "lead_jet_constit1_phi := VBFMVA.lead_jet_c1_phi",
    "lead_jet_constit2_phi := VBFMVA.lead_jet_c2_phi",
    "lead_jet_constit3_phi := VBFMVA.lead_jet_c3_phi",
    "lead_jet_constit4_phi := VBFMVA.lead_jet_c4_phi",
    "lead_jet_constit5_phi := VBFMVA.lead_jet_c5_phi",
    "lead_jet_constit6_phi := VBFMVA.lead_jet_c6_phi",
    "lead_jet_constit7_phi := VBFMVA.lead_jet_c7_phi",
    "lead_jet_constit8_phi := VBFMVA.lead_jet_c8_phi",
    "lead_jet_constit1_charge := VBFMVA.lead_jet_c1_charge",
    "lead_jet_constit2_charge := VBFMVA.lead_jet_c2_charge",
    "lead_jet_constit3_charge := VBFMVA.lead_jet_c3_charge",
    "lead_jet_constit4_charge := VBFMVA.lead_jet_c4_charge",
    "lead_jet_constit5_charge := VBFMVA.lead_jet_c5_charge",
    "lead_jet_constit6_charge := VBFMVA.lead_jet_c6_charge",
    "lead_jet_constit7_charge := VBFMVA.lead_jet_c7_charge",
    "lead_jet_constit8_charge := VBFMVA.lead_jet_c8_charge",
    "lead_jet_constit1_pt := VBFMVA.lead_jet_c1_pt",
    "lead_jet_constit2_pt := VBFMVA.lead_jet_c2_pt",
    "lead_jet_constit3_pt := VBFMVA.lead_jet_c3_pt",
    "lead_jet_constit4_pt := VBFMVA.lead_jet_c4_pt",
    "lead_jet_constit5_pt := VBFMVA.lead_jet_c5_pt",
    "lead_jet_constit6_pt := VBFMVA.lead_jet_c6_pt",
    "lead_jet_constit7_pt := VBFMVA.lead_jet_c7_pt",
    "lead_jet_constit8_pt := VBFMVA.lead_jet_c8_pt",
    "lead_jet_constit1_energy := VBFMVA.lead_jet_c1_energy",
    "lead_jet_constit2_energy := VBFMVA.lead_jet_c2_energy",
    "lead_jet_constit3_energy := VBFMVA.lead_jet_c3_energy",
    "lead_jet_constit4_energy := VBFMVA.lead_jet_c4_energy",
    "lead_jet_constit5_energy := VBFMVA.lead_jet_c5_energy",
    "lead_jet_constit6_energy := VBFMVA.lead_jet_c6_energy",
    "lead_jet_constit7_energy := VBFMVA.lead_jet_c7_energy",
    "lead_jet_constit8_energy := VBFMVA.lead_jet_c8_energy",
    "sublead_jet_constit1_eta := VBFMVA.sublead_jet_c1_eta",
    "sublead_jet_constit2_eta := VBFMVA.sublead_jet_c2_eta",
    "sublead_jet_constit3_eta := VBFMVA.sublead_jet_c3_eta",
    "sublead_jet_constit4_eta := VBFMVA.sublead_jet_c4_eta",
    "sublead_jet_constit5_eta := VBFMVA.sublead_jet_c5_eta",
    "sublead_jet_constit6_eta := VBFMVA.sublead_jet_c6_eta",
    "sublead_jet_constit7_eta := VBFMVA.sublead_jet_c7_eta",
    "sublead_jet_constit8_eta := VBFMVA.sublead_jet_c8_eta",
    "sublead_jet_constit1_phi := VBFMVA.sublead_jet_c1_phi",
    "sublead_jet_constit2_phi := VBFMVA.sublead_jet_c2_phi",
    "sublead_jet_constit3_phi := VBFMVA.sublead_jet_c3_phi",
    "sublead_jet_constit4_phi := VBFMVA.sublead_jet_c4_phi",
    "sublead_jet_constit5_phi := VBFMVA.sublead_jet_c5_phi",
    "sublead_jet_constit6_phi := VBFMVA.sublead_jet_c6_phi",
    "sublead_jet_constit7_phi := VBFMVA.sublead_jet_c7_phi",
    "sublead_jet_constit8_phi := VBFMVA.sublead_jet_c8_phi",
    "sublead_jet_constit1_charge := VBFMVA.sublead_jet_c1_charge",
    "sublead_jet_constit2_charge := VBFMVA.sublead_jet_c2_charge",
    "sublead_jet_constit3_charge := VBFMVA.sublead_jet_c3_charge",
    "sublead_jet_constit4_charge := VBFMVA.sublead_jet_c4_charge",
    "sublead_jet_constit5_charge := VBFMVA.sublead_jet_c5_charge",
    "sublead_jet_constit6_charge := VBFMVA.sublead_jet_c6_charge",
    "sublead_jet_constit7_charge := VBFMVA.sublead_jet_c7_charge",
    "sublead_jet_constit8_charge := VBFMVA.sublead_jet_c8_charge",
    "sublead_jet_constit1_pt := VBFMVA.sublead_jet_c1_pt",
    "sublead_jet_constit2_pt := VBFMVA.sublead_jet_c2_pt",
    "sublead_jet_constit3_pt := VBFMVA.sublead_jet_c3_pt",
    "sublead_jet_constit4_pt := VBFMVA.sublead_jet_c4_pt",
    "sublead_jet_constit5_pt := VBFMVA.sublead_jet_c5_pt",
    "sublead_jet_constit6_pt := VBFMVA.sublead_jet_c6_pt",
    "sublead_jet_constit7_pt := VBFMVA.sublead_jet_c7_pt",
    "sublead_jet_constit8_pt := VBFMVA.sublead_jet_c8_pt",
    "sublead_jet_constit1_energy := VBFMVA.sublead_jet_c1_energy",
    "sublead_jet_constit2_energy := VBFMVA.sublead_jet_c2_energy",
    "sublead_jet_constit3_energy := VBFMVA.sublead_jet_c3_energy",
    "sublead_jet_constit4_energy := VBFMVA.sublead_jet_c4_energy",
    "sublead_jet_constit5_energy := VBFMVA.sublead_jet_c5_energy",
    "sublead_jet_constit6_energy := VBFMVA.sublead_jet_c6_energy",
    "sublead_jet_constit7_energy := VBFMVA.sublead_jet_c7_energy",
    "sublead_jet_constit8_energy := VBFMVA.sublead_jet_c8_energy",
    "subsublead_jet_constit1_eta := VBFMVA.subsublead_jet_c1_eta",
    "subsublead_jet_constit2_eta := VBFMVA.subsublead_jet_c2_eta",
    "subsublead_jet_constit3_eta := VBFMVA.subsublead_jet_c3_eta",
    "subsublead_jet_constit4_eta := VBFMVA.subsublead_jet_c4_eta",
    "subsublead_jet_constit5_eta := VBFMVA.subsublead_jet_c5_eta",
    "subsublead_jet_constit6_eta := VBFMVA.subsublead_jet_c6_eta",
    "subsublead_jet_constit7_eta := VBFMVA.subsublead_jet_c7_eta",
    "subsublead_jet_constit8_eta := VBFMVA.subsublead_jet_c8_eta",
    "subsublead_jet_constit1_phi := VBFMVA.subsublead_jet_c1_phi",
    "subsublead_jet_constit2_phi := VBFMVA.subsublead_jet_c2_phi",
    "subsublead_jet_constit3_phi := VBFMVA.subsublead_jet_c3_phi",
    "subsublead_jet_constit4_phi := VBFMVA.subsublead_jet_c4_phi",
    "subsublead_jet_constit5_phi := VBFMVA.subsublead_jet_c5_phi",
    "subsublead_jet_constit6_phi := VBFMVA.subsublead_jet_c6_phi",
    "subsublead_jet_constit7_phi := VBFMVA.subsublead_jet_c7_phi",
    "subsublead_jet_constit8_phi := VBFMVA.subsublead_jet_c8_phi",
    "subsublead_jet_constit1_charge := VBFMVA.subsublead_jet_c1_charge",
    "subsublead_jet_constit2_charge := VBFMVA.subsublead_jet_c2_charge",
    "subsublead_jet_constit3_charge := VBFMVA.subsublead_jet_c3_charge",
    "subsublead_jet_constit4_charge := VBFMVA.subsublead_jet_c4_charge",
    "subsublead_jet_constit5_charge := VBFMVA.subsublead_jet_c5_charge",
    "subsublead_jet_constit6_charge := VBFMVA.subsublead_jet_c6_charge",
    "subsublead_jet_constit7_charge := VBFMVA.subsublead_jet_c7_charge",
    "subsublead_jet_constit8_charge := VBFMVA.subsublead_jet_c8_charge",
    "subsublead_jet_constit1_pt := VBFMVA.subsublead_jet_c1_pt",
    "subsublead_jet_constit2_pt := VBFMVA.subsublead_jet_c2_pt",
    "subsublead_jet_constit3_pt := VBFMVA.subsublead_jet_c3_pt",
    "subsublead_jet_constit4_pt := VBFMVA.subsublead_jet_c4_pt",
    "subsublead_jet_constit5_pt := VBFMVA.subsublead_jet_c5_pt",
    "subsublead_jet_constit6_pt := VBFMVA.subsublead_jet_c6_pt",
    "subsublead_jet_constit7_pt := VBFMVA.subsublead_jet_c7_pt",
    "subsublead_jet_constit8_pt := VBFMVA.subsublead_jet_c8_pt",
    "subsublead_jet_constit1_energy := VBFMVA.subsublead_jet_c1_energy",
    "subsublead_jet_constit2_energy := VBFMVA.subsublead_jet_c2_energy",
    "subsublead_jet_constit3_energy := VBFMVA.subsublead_jet_c3_energy",
    "subsublead_jet_constit4_energy := VBFMVA.subsublead_jet_c4_energy",
    "subsublead_jet_constit5_energy := VBFMVA.subsublead_jet_c5_energy",
    "subsublead_jet_constit6_energy := VBFMVA.subsublead_jet_c6_energy",
    "subsublead_jet_constit7_energy := VBFMVA.subsublead_jet_c7_energy",
    "subsublead_jet_constit8_energy := VBFMVA.subsublead_jet_c8_energy",
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
if customize.runOnZee:
    if customize.processId == "Data":
        process.hltHighLevel = hltHighLevel.clone(HLTPaths = cms.vstring("HLT_Ele32_WPTight_Gsf_L1DoubleEG_v**") )
else:
    process.hltHighLevel = hltHighLevel.clone(HLTPaths = cms.vstring("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v*"))

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
