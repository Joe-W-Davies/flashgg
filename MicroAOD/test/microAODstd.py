import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils

process = cms.Process("FLASHggMicroAOD")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
#process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff") # gives deprecated message in 80X but still runs
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
from Configuration.AlCa.GlobalTag import GlobalTag

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( 18000 ) )
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 1000 )


sampleID=2

import os
### 2016
#process.GlobalTag = GlobalTag(process.GlobalTag, '', '')
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/B6126C44-89DF-E911-8408-801844E56C20.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/D816D0C7-AADD-E911-B124-782BCB1F0EB8.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/0A840A90-94DE-E911-B421-20040FE9C7DC.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/94A4656E-31E5-E911-BA8A-20040FF47804.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/A66E1D90-30E5-E911-813E-549F3525A200.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/0E006F31-30E5-E911-A944-20040FF492B8.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/FE50A4C5-2FE5-E911-9220-20040FE8EA44.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/7A902B6A-2FE5-E911-B3AE-1866DAEECFDC.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/8678C8CB-64E5-E911-A62E-20040FF469D4.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/54C98CEB-2FE5-E911-AFA5-1866DAEEB358.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/8A41AF98-2FE5-E911-A75B-20040FE9CF48.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/30000/48B62DB8-7CE5-E911-8D39-001EC94BA144.root"))


#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/240000/40699271-C2E0-E911-9E58-38EAA78E2C94.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/240000/D25D28F5-C2E0-E911-816E-38EAA78D8ACC.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/240000/A005D852-C2E0-E911-B2CA-38EAA78D8F94.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/240000/F261D452-C2E0-E911-A13B-38EAA78D8F94.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/240000/FE267206-F0E0-E911-98D0-8CDCD4A99D14.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/240000/E6F15CEB-EFE0-E911-8428-38EAA78E2C94.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/240000/EE251C49-F1E0-E911-9F27-0CC47AF97150.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv3/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v1/240000/FE7C2713-22E2-E911-AB13-8CDCD4A9A484.root"))

### 2017
#process.GlobalTag = GlobalTag(process.GlobalTag,'','')
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/0866D1A8-1941-E811-B61F-0CC47AF9B2E6.root"))
#    process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring('/store/mc/RunIISummer16MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/60000/024E4FA3-8BBC-E611-8E3D-00266CFFBE88.root'))
    #process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring('root://eoscms.cern.ch//eos/cms/store/mc/RunIIFall17MiniAOD/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8/MINIAODSIM/94X_mc2017_realistic_v10-v1/40000/4A2ACB0A-1BD9-E711-AF54-141877410316.root'))
#    process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring('root://eoscms.cern.ch//eos/cms/store/mc/RunIIFall17MiniAOD/GluGluToHHTo2B2G_node_SM_13TeV-madgraph/MINIAODSIM/94X_mc2017_realistic_v10-v1/00000/2E0E165D-8E05-E811-909C-FA163E80AE1F.root'))
#    process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring('file:/afs/cern.ch/user/s/sethzenz/work/public/GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8_94X_mc2017_realistic_v10-v1.root'))
#    process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/THQ_ctcvcp_HToGG_M125_13TeV-madgraph-pythia8_TuneCP5/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/90000/6E58A5DD-BF43-E811-8946-0023AEEEB538.root"))

ggH_2017 = [ "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/0866D1A8-1941-E811-B61F-0CC47AF9B2E6.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/80C04558-1E41-E811-A2DC-0CC47AF9B32A.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/28302678-2941-E811-B888-0025905C431A.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/7CB16DA1-2E41-E811-91A8-0025905C3E36.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/483B4607-3641-E811-8A87-0025905C42F4.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/B2658105-3641-E811-983D-0CC47AF9B2E2.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/A2A97E97-2241-E811-A59B-0CC47AB64E80.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/5E57F697-2241-E811-83DD-AC1F6B239D78.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/18C01BA3-2941-E811-BACB-0CC47AE0F33C.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/68C44EA3-2941-E811-A662-0CC47AB64AE2.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/744D3D98-2E41-E811-AEEA-AC1F6B23C88C.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/1210C893-2E41-E811-B0BF-AC1F6B23C9D6.root",
             "/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/38B7B421-3741-E811-B333-AC1F6B23C846.root" ]

VBF_2017 = ["/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/86A16154-6442-E811-A140-141877640173.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/D63FC35E-6442-E811-B4CD-001E6757EAA4.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/64202A48-6442-E811-AF0E-A0369F83637E.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/84774AB6-FF41-E811-911E-0CC47A78A4BA.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/6CB20AF5-6442-E811-8E02-008CFAC91BC4.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/74511D58-3E42-E811-8813-001EC94BA117.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/06254F5E-6442-E811-A88E-B499BAAC068A.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/12C96754-6442-E811-923E-509A4C730E2B.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/BCDCD85C-6442-E811-AD15-D8D385AF8AEA.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/7485D65D-6442-E811-BFB5-0CC47ABAC0CE.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/8A325454-6442-E811-934A-E0071B7A8550.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/42CE3655-6442-E811-BEE2-00266CF831A8.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/56B34018-EF41-E811-B541-02163E019F67.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/24FED675-6442-E811-B21F-FA163E066C15.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/786F6D54-2542-E811-A200-141877410512.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/64D897AD-2E42-E811-8C51-801844DEDDC8.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/6293F403-3B42-E811-BA7A-14187734413C.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/C63D9BA8-3B42-E811-84A5-842B2B09CE79.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/6E866B22-3D42-E811-AD44-14187734413C.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/AE9E9DC0-3C42-E811-BC55-D4AE527F338A.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/50C49AA4-3E42-E811-ACE3-A4BADB1CF89A.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/DA2E476E-4242-E811-B681-1866DAEA7EA8.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/9649835C-6442-E811-95F5-782BCB20E906.root",
            "/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/D66EBE48-6442-E811-AC7F-0025905D1E0A.root" ]

#ggH samples
process.GlobalTag = GlobalTag(process.GlobalTag, '', '')

process.source = cms.Source("PoolSource",
                             fileNames=cms.untracked.vstring("%s"%VBF_2017[sampleID]))

#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/0866D1A8-1941-E811-B61F-0CC47AF9B2E6.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/80C04558-1E41-E811-A2DC-0CC47AF9B32A.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/28302678-2941-E811-B888-0025905C431A.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/7CB16DA1-2E41-E811-91A8-0025905C3E36.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/483B4607-3641-E811-8A87-0025905C42F4.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/B2658105-3641-E811-983D-0CC47AF9B2E2.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/A2A97E97-2241-E811-A59B-0CC47AB64E80.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/5E57F697-2241-E811-83DD-AC1F6B239D78.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/18C01BA3-2941-E811-BACB-0CC47AE0F33C.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/68C44EA3-2941-E811-A662-0CC47AB64AE2.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/744D3D98-2E41-E811-AEEA-AC1F6B23C88C.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/1210C893-2E41-E811-B0BF-AC1F6B23C9D6.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/40000/38B7B421-3741-E811-B333-AC1F6B23C846.root"))

#VBF samples

#process.GlobalTag = GlobalTag(process.GlobalTag, '', '')
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/86A16154-6442-E811-A140-141877640173.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/D63FC35E-6442-E811-B4CD-001E6757EAA4.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/64202A48-6442-E811-AF0E-A0369F83637E.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/84774AB6-FF41-E811-911E-0CC47A78A4BA.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/6CB20AF5-6442-E811-8E02-008CFAC91BC4.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/74511D58-3E42-E811-8813-001EC94BA117.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/06254F5E-6442-E811-A88E-B499BAAC068A.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/12C96754-6442-E811-923E-509A4C730E2B.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/BCDCD85C-6442-E811-AD15-D8D385AF8AEA.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/7485D65D-6442-E811-BFB5-0CC47ABAC0CE.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/8A325454-6442-E811-934A-E0071B7A8550.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/42CE3655-6442-E811-BEE2-00266CF831A8.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/56B34018-EF41-E811-B541-02163E019F67.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/24FED675-6442-E811-B21F-FA163E066C15.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/786F6D54-2542-E811-A200-141877410512.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/64D897AD-2E42-E811-8C51-801844DEDDC8.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/6293F403-3B42-E811-BA7A-14187734413C.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/C63D9BA8-3B42-E811-84A5-842B2B09CE79.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/6E866B22-3D42-E811-AD44-14187734413C.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/AE9E9DC0-3C42-E811-BC55-D4AE527F338A.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/50C49AA4-3E42-E811-ACE3-A4BADB1CF89A.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/DA2E476E-4242-E811-B681-1866DAEA7EA8.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/9649835C-6442-E811-95F5-782BCB20E906.root"))
#process.source = cms.Source("PoolSource",
#                             fileNames=cms.untracked.vstring("/store/mc/RunIIFall17MiniAODv2/VBFHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/10000/D66EBE48-6442-E811-AC7F-0025905D1E0A.root"))


### 2018
     # process.GlobalTag = GlobalTag(process.GlobalTag,'100X_upgrade2018_realistic_v10','')
     # process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/data/Run2018B/DoubleMuon/MINIAOD/PromptReco-v1/000/317/080/00000/4E78B565-8464-E811-BF54-02163E01A0FC.root"))
    #process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/data/Run2018D/EGamma/MINIAOD/PromptReco-v2/000/322/106/00000/9A1C4C91-1EB3-E811-A238-02163E0150CE.root"))
    #process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/data/Run2018D/DoubleMuon/MINIAOD/PromptReco-v2/000/320/673/00000/0A83E8DF-EB97-E811-AE18-FA163E192E5D.root"))
    # process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/mc/RunIISpring18MiniAOD/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/MINIAODSIM/100X_upgrade2018_realistic_v10-v2/10000/F24C5C06-FF47-E811-9C2F-FA163EC3CAD1.root"))

process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService")
process.RandomNumberGeneratorService.flashggRandomizedPhotons = cms.PSet(
          initialSeed = cms.untracked.uint32(16253245)
        )

#process.GlobalTag = GlobalTag(process.GlobalTag,'92X_upgrade2017_realistic_v10','')
#process.source.fileNames=cms.untracked.vstring("/store/mc/RunIISummer17MiniAOD/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/MINIAODSIM/92X_upgrade2017_realistic_v10_ext1-v2/10000/00F9D855-E293-E711-B625-02163E014200.root")

# 2017 Data
#process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/data/Run2017A/DoubleEG/MINIAOD/PromptReco-v2/000/296/173/00000/C24ABCFB-644C-E711-8A5E-02163E01A21C.root"))

# Legacy ReReco
#process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/data/Run2016B/SingleElectron/MINIAOD/18Apr2017_ver1-v1/120000/40167FB6-6237-E711-934A-001E67E69E05.root"))

#Moriond17 MC
#process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/mc/RunIISummer16MiniAODv2/GluGluHToGG_M-125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/60000/024E4FA3-8BBC-E611-8E3D-00266CFFBE88.root"))

#80x reminiAOD data
#process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/data/Run2016G/DoubleEG/MINIAOD/03Feb2017-v1/100000/002F14FF-D0EA-E611-952E-008CFA197AF4.root"))

#80x signal
#process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/mc/RunIISpring16MiniAODv2/GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8/MINIAODSIM/PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14_ext2-v1/10000/6A31A211-063B-E611-98EC-001E67F8F727.root")) # ggH 125 miniAODv2
#process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/mc/RunIISpring16MiniAODv2/ttHJetToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8_v2/MINIAODSIM/PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/80000/267A1DB4-3D3B-E611-9AD2-003048C559C4.root")) # ttH 125 miniAODv2

#80x data
#process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("/store/data/Run2016B/DoubleEG/MINIAOD/PromptReco-v2/000/273/158/00000/1E5ABF54-E019-E611-AAED-02163E01293F.root")) # /DoubleEG/Run2016B-PromptReco-v2/MINIAOD


process.MessageLogger.cerr.threshold = 'ERROR' # can't get suppressWarning to work: disable all warnings for now
# process.MessageLogger.suppressWarning.extend(['SimpleMemoryCheck','MemoryCheck']) # this would have been better...

# Uncomment the following if you notice you have a memory leak
# This is a lightweight tool to digg further
#process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
#                                        ignoreTotal = cms.untracked.int32(1),
#                                        monitorPssAndPrivate = cms.untracked.bool(True)
#                                       )

process.load("flashgg/MicroAOD/flashggMicroAODSequence_cff")

# NEEDED FOR ANYTHING PRIOR TO reMiniAOD
#process.weightsCount.pileupInfo = "addPileupInfo"


from flashgg.MicroAOD.flashggMicroAODOutputCommands_cff import microAODDefaultOutputCommand
process.out = cms.OutputModule("PoolOutputModule", fileName = cms.untracked.string('/afs/cern.ch/work/d/davies/flashgg/CMSSW_10_6_1_patch2/src/flashgg/VBF_uAOD_2020_Feb_file_%i_%s_15K_events_LOCAL.root'%(sampleID,VBF_2017[sampleID][-12:-5])),
                               outputCommands = microAODDefaultOutputCommand
                               )


# All jets are now handled in MicroAODCustomize.py
# Switch from PFCHS to PUPPI with puppi=1 argument (both if puppi=2)

process.p = cms.Path(process.flashggMicroAODSequence)
process.e = cms.EndPath(process.out)

# Uncomment these lines to run the example commissioning module and send its output to root
#process.commissioning = cms.EDAnalyzer('flashggCommissioning',
#                                       PhotonTag=cms.untracked.InputTag('flashggPhotons'),
#                                       DiPhotonTag = cms.untracked.InputTag('flashggDiPhotons'),
#                                       VertexTag=cms.untracked.InputTag('offlineSlimmedPrimaryVertices')
#)
#process.TFileService = cms.Service("TFileService",
#                                   fileName = cms.string("commissioningTree.root")
#)
#process.p *= process.commissioning
from flashgg.MicroAOD.MicroAODCustomize import customize

customize(process)


if "DY" in customize.datasetName or "SingleElectron" in customize.datasetName or "DoubleEG" in customize.datasetName or "EGamma" in customize.datasetName:
    customize.customizeHLT(process)

#open('dump.py', 'w').write(process.dumpPython())
