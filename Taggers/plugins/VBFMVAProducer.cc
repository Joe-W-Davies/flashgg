#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/EDMException.h"

#include "flashgg/DataFormats/interface/DiPhotonCandidate.h"
#include "flashgg/DataFormats/interface/Jet.h"
#include "flashgg/DataFormats/interface/VBFMVAResult.h"

#include "TMVA/Reader.h"
#include "TMath.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include <string>

#include "TLorentzVector.h"

using namespace std;
using namespace edm;

namespace flashgg {
    
    class VBFMVAProducer : public EDProducer
    {
        
    public:
        VBFMVAProducer( const ParameterSet & );
    private:
        void produce( Event &, const EventSetup & ) override;
        
        std::vector<edm::EDGetTokenT<View<flashgg::Jet> > > tokenJets_;
        EDGetTokenT<View<DiPhotonCandidate> > diPhotonToken_;
        //EDGetTokenT<View<flashgg::Jet> > jetTokenDz_;
        std::vector<edm::InputTag> inputTagJets_;

        unique_ptr<TMVA::Reader>VbfMva_;
        FileInPath vbfMVAweightfile_;
        string     _MVAMethod;
        bool       _usePuJetID;
        bool       _useJetID;
        bool       _merge3rdJet;
        double     _thirdJetDRCut;
        double     _rmsforwardCut;
        string     _JetIDLevel;
        double     _minDijetMinv;
        double     _drJetPhoton;
        
        std::vector<double> _pujid_wp_pt_bin_1;
        std::vector<double> _pujid_wp_pt_bin_2;
        std::vector<double> _pujid_wp_pt_bin_3;
        
        typedef std::vector<edm::Handle<edm::View<flashgg::Jet> > > JetCollectionVector;
        
        float dijet_leadEta_   ;
        float dijet_subleadEta_;
        float dijet_abs_dEta_;
        float dijet_LeadJPt_ ;
        float dijet_pt_ ;
        float dijet_SubJPt_  ;
        float dijet_Zep_     ;
        float dijet_dphi_trunc_;
        float dijet_dphi_;
        float dijet_dipho_dphi_;
        float dijet_Mjj_   ;
        float dijet_minDRJetPho_ ;
        float dijet_centrality_gg_;
        float dijet_centrality_j3_;
        float dijet_centrality_g_ ;
        float dijet_dy_    ;
        float dijet_leady_    ;
        float dijet_subleady_ ;
        float dijet_dipho_pt_ ;

        // some VH had variables
        float cosThetaStar_; 

        // add constituent jet info as a test
        float constit_energy_;

        float pt_J1_ ;
        float eta_J1_;
        float phi_J1_ ;
        float charge_J1_ ;
        float energy_J1_ ;
        float flav_J1_ ;

        float pt_J2_ ;
        float eta_J2_ ;
        float phi_J2_ ;
        float charge_J2_ ;
        float energy_J2_ ;
        float flav_J2_ ;

        float pt_J3_ ;
        float eta_J3_ ;
        float phi_J3_ ;
        float charge_J3_ ;
        float energy_J3_ ;
        float flav_J3_ ;

        float n_constits_;
        //std::vector<float> test_vec_;

        float lead_jet_pt_;
        float test_lead_jet_eta_;
        
        float lead_jet_c1_eta_;
        float lead_jet_c2_eta_;
        float lead_jet_c3_eta_;
        float lead_jet_c4_eta_;
        float lead_jet_c5_eta_;
        float lead_jet_c6_eta_;
        float lead_jet_c7_eta_;
        float lead_jet_c8_eta_;
        float lead_jet_c9_eta_;
        float lead_jet_c10_eta_;
        float lead_jet_c11_eta_;
        float lead_jet_c12_eta_;
        float lead_jet_c13_eta_;
        float lead_jet_c14_eta_;
        float lead_jet_c15_eta_;
        float lead_jet_c16_eta_;
        float lead_jet_c17_eta_;
        float lead_jet_c18_eta_;
        float lead_jet_c19_eta_;
        float lead_jet_c20_eta_;
        float lead_jet_c21_eta_;
        float lead_jet_c22_eta_;
        float lead_jet_c23_eta_;
        float lead_jet_c24_eta_;
        float lead_jet_c25_eta_;
        float lead_jet_c26_eta_;
        float lead_jet_c27_eta_;
        float lead_jet_c28_eta_;
        float lead_jet_c29_eta_;
        float lead_jet_c30_eta_;
        float lead_jet_c31_eta_;
        float lead_jet_c32_eta_;
        float lead_jet_c33_eta_;
        float lead_jet_c34_eta_;
        float lead_jet_c35_eta_;
        float lead_jet_c36_eta_;
        float lead_jet_c37_eta_;
        float lead_jet_c38_eta_;
        float lead_jet_c39_eta_;
        float lead_jet_c40_eta_;
        float lead_jet_c41_eta_;
        float lead_jet_c42_eta_;
        float lead_jet_c43_eta_;
        float lead_jet_c44_eta_;
        float lead_jet_c45_eta_;
        float lead_jet_c46_eta_;
        float lead_jet_c47_eta_;
        float lead_jet_c48_eta_;
        float lead_jet_c49_eta_;
        float lead_jet_c50_eta_;
        float lead_jet_c51_eta_;
        float lead_jet_c52_eta_;
        float lead_jet_c53_eta_;
        float lead_jet_c54_eta_;
        float lead_jet_c55_eta_;
        float lead_jet_c56_eta_;
        float lead_jet_c57_eta_;
        float lead_jet_c58_eta_;
        float lead_jet_c59_eta_;
        float lead_jet_c60_eta_;

        float lead_jet_c1_phi_;
        float lead_jet_c2_phi_;
        float lead_jet_c3_phi_;
        float lead_jet_c4_phi_;
        float lead_jet_c5_phi_;
        float lead_jet_c6_phi_;
        float lead_jet_c7_phi_;
        float lead_jet_c8_phi_;
        float lead_jet_c9_phi_;
        float lead_jet_c10_phi_;
        float lead_jet_c11_phi_;
        float lead_jet_c12_phi_;
        float lead_jet_c13_phi_;
        float lead_jet_c14_phi_;
        float lead_jet_c15_phi_;
        float lead_jet_c16_phi_;
        float lead_jet_c17_phi_;
        float lead_jet_c18_phi_;
        float lead_jet_c19_phi_;
        float lead_jet_c20_phi_;
        float lead_jet_c21_phi_;
        float lead_jet_c22_phi_;
        float lead_jet_c23_phi_;
        float lead_jet_c24_phi_;
        float lead_jet_c25_phi_;
        float lead_jet_c26_phi_;
        float lead_jet_c27_phi_;
        float lead_jet_c28_phi_;
        float lead_jet_c29_phi_;
        float lead_jet_c30_phi_;
        float lead_jet_c31_phi_;
        float lead_jet_c32_phi_;
        float lead_jet_c33_phi_;
        float lead_jet_c34_phi_;
        float lead_jet_c35_phi_;
        float lead_jet_c36_phi_;
        float lead_jet_c37_phi_;
        float lead_jet_c38_phi_;
        float lead_jet_c39_phi_;
        float lead_jet_c40_phi_;
        float lead_jet_c41_phi_;
        float lead_jet_c42_phi_;
        float lead_jet_c43_phi_;
        float lead_jet_c44_phi_;
        float lead_jet_c45_phi_;
        float lead_jet_c46_phi_;
        float lead_jet_c47_phi_;
        float lead_jet_c48_phi_;
        float lead_jet_c49_phi_;
        float lead_jet_c50_phi_;
        float lead_jet_c51_phi_;
        float lead_jet_c52_phi_;
        float lead_jet_c53_phi_;
        float lead_jet_c54_phi_;
        float lead_jet_c55_phi_;
        float lead_jet_c56_phi_;
        float lead_jet_c57_phi_;
        float lead_jet_c58_phi_;
        float lead_jet_c59_phi_;
        float lead_jet_c60_phi_;

        float lead_jet_c1_charge_;
        float lead_jet_c2_charge_;
        float lead_jet_c3_charge_;
        float lead_jet_c4_charge_;
        float lead_jet_c5_charge_;
        float lead_jet_c6_charge_;
        float lead_jet_c7_charge_;
        float lead_jet_c8_charge_;
        float lead_jet_c9_charge_;
        float lead_jet_c10_charge_;
        float lead_jet_c11_charge_;
        float lead_jet_c12_charge_;
        float lead_jet_c13_charge_;
        float lead_jet_c14_charge_;
        float lead_jet_c15_charge_;
        float lead_jet_c16_charge_;
        float lead_jet_c17_charge_;
        float lead_jet_c18_charge_;
        float lead_jet_c19_charge_;
        float lead_jet_c20_charge_;
        float lead_jet_c21_charge_;
        float lead_jet_c22_charge_;
        float lead_jet_c23_charge_;
        float lead_jet_c24_charge_;
        float lead_jet_c25_charge_;
        float lead_jet_c26_charge_;
        float lead_jet_c27_charge_;
        float lead_jet_c28_charge_;
        float lead_jet_c29_charge_;
        float lead_jet_c30_charge_;
        float lead_jet_c31_charge_;
        float lead_jet_c32_charge_;
        float lead_jet_c33_charge_;
        float lead_jet_c34_charge_;
        float lead_jet_c35_charge_;
        float lead_jet_c36_charge_;
        float lead_jet_c37_charge_;
        float lead_jet_c38_charge_;
        float lead_jet_c39_charge_;
        float lead_jet_c40_charge_;
        float lead_jet_c41_charge_;
        float lead_jet_c42_charge_;
        float lead_jet_c43_charge_;
        float lead_jet_c44_charge_;
        float lead_jet_c45_charge_;
        float lead_jet_c46_charge_;
        float lead_jet_c47_charge_;
        float lead_jet_c48_charge_;
        float lead_jet_c49_charge_;
        float lead_jet_c50_charge_;
        float lead_jet_c51_charge_;
        float lead_jet_c52_charge_;
        float lead_jet_c53_charge_;
        float lead_jet_c54_charge_;
        float lead_jet_c55_charge_;
        float lead_jet_c56_charge_;
        float lead_jet_c57_charge_;
        float lead_jet_c58_charge_;
        float lead_jet_c59_charge_;
        float lead_jet_c60_charge_;

        float lead_jet_c1_pt_;
        float lead_jet_c2_pt_;
        float lead_jet_c3_pt_;
        float lead_jet_c4_pt_;
        float lead_jet_c5_pt_;
        float lead_jet_c6_pt_;
        float lead_jet_c7_pt_;
        float lead_jet_c8_pt_;
        float lead_jet_c9_pt_;
        float lead_jet_c10_pt_;
        float lead_jet_c11_pt_;
        float lead_jet_c12_pt_;
        float lead_jet_c13_pt_;
        float lead_jet_c14_pt_;
        float lead_jet_c15_pt_;
        float lead_jet_c16_pt_;
        float lead_jet_c17_pt_;
        float lead_jet_c18_pt_;
        float lead_jet_c19_pt_;
        float lead_jet_c20_pt_;
        float lead_jet_c21_pt_;
        float lead_jet_c22_pt_;
        float lead_jet_c23_pt_;
        float lead_jet_c24_pt_;
        float lead_jet_c25_pt_;
        float lead_jet_c26_pt_;
        float lead_jet_c27_pt_;
        float lead_jet_c28_pt_;
        float lead_jet_c29_pt_;
        float lead_jet_c30_pt_;
        float lead_jet_c31_pt_;
        float lead_jet_c32_pt_;
        float lead_jet_c33_pt_;
        float lead_jet_c34_pt_;
        float lead_jet_c35_pt_;
        float lead_jet_c36_pt_;
        float lead_jet_c37_pt_;
        float lead_jet_c38_pt_;
        float lead_jet_c39_pt_;
        float lead_jet_c40_pt_;
        float lead_jet_c41_pt_;
        float lead_jet_c42_pt_;
        float lead_jet_c43_pt_;
        float lead_jet_c44_pt_;
        float lead_jet_c45_pt_;
        float lead_jet_c46_pt_;
        float lead_jet_c47_pt_;
        float lead_jet_c48_pt_;
        float lead_jet_c49_pt_;
        float lead_jet_c50_pt_;
        float lead_jet_c51_pt_;
        float lead_jet_c52_pt_;
        float lead_jet_c53_pt_;
        float lead_jet_c54_pt_;
        float lead_jet_c55_pt_;
        float lead_jet_c56_pt_;
        float lead_jet_c57_pt_;
        float lead_jet_c58_pt_;
        float lead_jet_c59_pt_;
        float lead_jet_c60_pt_;

        float lead_jet_c1_energy_;
        float lead_jet_c2_energy_;
        float lead_jet_c3_energy_;
        float lead_jet_c4_energy_;
        float lead_jet_c5_energy_;
        float lead_jet_c6_energy_;
        float lead_jet_c7_energy_;
        float lead_jet_c8_energy_;
        float lead_jet_c9_energy_;
        float lead_jet_c10_energy_;
        float lead_jet_c11_energy_;
        float lead_jet_c12_energy_;
        float lead_jet_c13_energy_;
        float lead_jet_c14_energy_;
        float lead_jet_c15_energy_;
        float lead_jet_c16_energy_;
        float lead_jet_c17_energy_;
        float lead_jet_c18_energy_;
        float lead_jet_c19_energy_;
        float lead_jet_c20_energy_;
        float lead_jet_c21_energy_;
        float lead_jet_c22_energy_;
        float lead_jet_c23_energy_;
        float lead_jet_c24_energy_;
        float lead_jet_c25_energy_;
        float lead_jet_c26_energy_;
        float lead_jet_c27_energy_;
        float lead_jet_c28_energy_;
        float lead_jet_c29_energy_;
        float lead_jet_c30_energy_;
        float lead_jet_c31_energy_;
        float lead_jet_c32_energy_;
        float lead_jet_c33_energy_;
        float lead_jet_c34_energy_;
        float lead_jet_c35_energy_;
        float lead_jet_c36_energy_;
        float lead_jet_c37_energy_;
        float lead_jet_c38_energy_;
        float lead_jet_c39_energy_;
        float lead_jet_c40_energy_;
        float lead_jet_c41_energy_;
        float lead_jet_c42_energy_;
        float lead_jet_c43_energy_;
        float lead_jet_c44_energy_;
        float lead_jet_c45_energy_;
        float lead_jet_c46_energy_;
        float lead_jet_c47_energy_;
        float lead_jet_c48_energy_;
        float lead_jet_c49_energy_;
        float lead_jet_c50_energy_;
        float lead_jet_c51_energy_;
        float lead_jet_c52_energy_;
        float lead_jet_c53_energy_;
        float lead_jet_c54_energy_;
        float lead_jet_c55_energy_;
        float lead_jet_c56_energy_;
        float lead_jet_c57_energy_;
        float lead_jet_c58_energy_;
        float lead_jet_c59_energy_;
        float lead_jet_c60_energy_;

        float sublead_jet_c1_eta_;
        float sublead_jet_c2_eta_;
        float sublead_jet_c3_eta_;
        float sublead_jet_c4_eta_;
        float sublead_jet_c5_eta_;
        float sublead_jet_c6_eta_;
        float sublead_jet_c7_eta_;
        float sublead_jet_c8_eta_;
        float sublead_jet_c9_eta_;
        float sublead_jet_c10_eta_;
        float sublead_jet_c11_eta_;
        float sublead_jet_c12_eta_;
        float sublead_jet_c13_eta_;
        float sublead_jet_c14_eta_;
        float sublead_jet_c15_eta_;
        float sublead_jet_c16_eta_;
        float sublead_jet_c17_eta_;
        float sublead_jet_c18_eta_;
        float sublead_jet_c19_eta_;
        float sublead_jet_c20_eta_;
        float sublead_jet_c21_eta_;
        float sublead_jet_c22_eta_;
        float sublead_jet_c23_eta_;
        float sublead_jet_c24_eta_;
        float sublead_jet_c25_eta_;
        float sublead_jet_c26_eta_;
        float sublead_jet_c27_eta_;
        float sublead_jet_c28_eta_;
        float sublead_jet_c29_eta_;
        float sublead_jet_c30_eta_;
        float sublead_jet_c31_eta_;
        float sublead_jet_c32_eta_;
        float sublead_jet_c33_eta_;
        float sublead_jet_c34_eta_;
        float sublead_jet_c35_eta_;
        float sublead_jet_c36_eta_;
        float sublead_jet_c37_eta_;
        float sublead_jet_c38_eta_;
        float sublead_jet_c39_eta_;
        float sublead_jet_c40_eta_;
        float sublead_jet_c41_eta_;
        float sublead_jet_c42_eta_;
        float sublead_jet_c43_eta_;
        float sublead_jet_c44_eta_;
        float sublead_jet_c45_eta_;
        float sublead_jet_c46_eta_;
        float sublead_jet_c47_eta_;
        float sublead_jet_c48_eta_;
        float sublead_jet_c49_eta_;
        float sublead_jet_c50_eta_;
        float sublead_jet_c51_eta_;
        float sublead_jet_c52_eta_;
        float sublead_jet_c53_eta_;
        float sublead_jet_c54_eta_;
        float sublead_jet_c55_eta_;
        float sublead_jet_c56_eta_;
        float sublead_jet_c57_eta_;
        float sublead_jet_c58_eta_;
        float sublead_jet_c59_eta_;
        float sublead_jet_c60_eta_;

        float sublead_jet_c1_phi_;
        float sublead_jet_c2_phi_;
        float sublead_jet_c3_phi_;
        float sublead_jet_c4_phi_;
        float sublead_jet_c5_phi_;
        float sublead_jet_c6_phi_;
        float sublead_jet_c7_phi_;
        float sublead_jet_c8_phi_;
        float sublead_jet_c9_phi_;
        float sublead_jet_c10_phi_;
        float sublead_jet_c11_phi_;
        float sublead_jet_c12_phi_;
        float sublead_jet_c13_phi_;
        float sublead_jet_c14_phi_;
        float sublead_jet_c15_phi_;
        float sublead_jet_c16_phi_;
        float sublead_jet_c17_phi_;
        float sublead_jet_c18_phi_;
        float sublead_jet_c19_phi_;
        float sublead_jet_c20_phi_;
        float sublead_jet_c21_phi_;
        float sublead_jet_c22_phi_;
        float sublead_jet_c23_phi_;
        float sublead_jet_c24_phi_;
        float sublead_jet_c25_phi_;
        float sublead_jet_c26_phi_;
        float sublead_jet_c27_phi_;
        float sublead_jet_c28_phi_;
        float sublead_jet_c29_phi_;
        float sublead_jet_c30_phi_;
        float sublead_jet_c31_phi_;
        float sublead_jet_c32_phi_;
        float sublead_jet_c33_phi_;
        float sublead_jet_c34_phi_;
        float sublead_jet_c35_phi_;
        float sublead_jet_c36_phi_;
        float sublead_jet_c37_phi_;
        float sublead_jet_c38_phi_;
        float sublead_jet_c39_phi_;
        float sublead_jet_c40_phi_;
        float sublead_jet_c41_phi_;
        float sublead_jet_c42_phi_;
        float sublead_jet_c43_phi_;
        float sublead_jet_c44_phi_;
        float sublead_jet_c45_phi_;
        float sublead_jet_c46_phi_;
        float sublead_jet_c47_phi_;
        float sublead_jet_c48_phi_;
        float sublead_jet_c49_phi_;
        float sublead_jet_c50_phi_;
        float sublead_jet_c51_phi_;
        float sublead_jet_c52_phi_;
        float sublead_jet_c53_phi_;
        float sublead_jet_c54_phi_;
        float sublead_jet_c55_phi_;
        float sublead_jet_c56_phi_;
        float sublead_jet_c57_phi_;
        float sublead_jet_c58_phi_;
        float sublead_jet_c59_phi_;
        float sublead_jet_c60_phi_;

        float sublead_jet_c1_charge_;
        float sublead_jet_c2_charge_;
        float sublead_jet_c3_charge_;
        float sublead_jet_c4_charge_;
        float sublead_jet_c5_charge_;
        float sublead_jet_c6_charge_;
        float sublead_jet_c7_charge_;
        float sublead_jet_c8_charge_;
        float sublead_jet_c9_charge_;
        float sublead_jet_c10_charge_;
        float sublead_jet_c11_charge_;
        float sublead_jet_c12_charge_;
        float sublead_jet_c13_charge_;
        float sublead_jet_c14_charge_;
        float sublead_jet_c15_charge_;
        float sublead_jet_c16_charge_;
        float sublead_jet_c17_charge_;
        float sublead_jet_c18_charge_;
        float sublead_jet_c19_charge_;
        float sublead_jet_c20_charge_;
        float sublead_jet_c21_charge_;
        float sublead_jet_c22_charge_;
        float sublead_jet_c23_charge_;
        float sublead_jet_c24_charge_;
        float sublead_jet_c25_charge_;
        float sublead_jet_c26_charge_;
        float sublead_jet_c27_charge_;
        float sublead_jet_c28_charge_;
        float sublead_jet_c29_charge_;
        float sublead_jet_c30_charge_;
        float sublead_jet_c31_charge_;
        float sublead_jet_c32_charge_;
        float sublead_jet_c33_charge_;
        float sublead_jet_c34_charge_;
        float sublead_jet_c35_charge_;
        float sublead_jet_c36_charge_;
        float sublead_jet_c37_charge_;
        float sublead_jet_c38_charge_;
        float sublead_jet_c39_charge_;
        float sublead_jet_c40_charge_;
        float sublead_jet_c41_charge_;
        float sublead_jet_c42_charge_;
        float sublead_jet_c43_charge_;
        float sublead_jet_c44_charge_;
        float sublead_jet_c45_charge_;
        float sublead_jet_c46_charge_;
        float sublead_jet_c47_charge_;
        float sublead_jet_c48_charge_;
        float sublead_jet_c49_charge_;
        float sublead_jet_c50_charge_;
        float sublead_jet_c51_charge_;
        float sublead_jet_c52_charge_;
        float sublead_jet_c53_charge_;
        float sublead_jet_c54_charge_;
        float sublead_jet_c55_charge_;
        float sublead_jet_c56_charge_;
        float sublead_jet_c57_charge_;
        float sublead_jet_c58_charge_;
        float sublead_jet_c59_charge_;
        float sublead_jet_c60_charge_;

        float sublead_jet_c1_pt_;
        float sublead_jet_c2_pt_;
        float sublead_jet_c3_pt_;
        float sublead_jet_c4_pt_;
        float sublead_jet_c5_pt_;
        float sublead_jet_c6_pt_;
        float sublead_jet_c7_pt_;
        float sublead_jet_c8_pt_;
        float sublead_jet_c9_pt_;
        float sublead_jet_c10_pt_;
        float sublead_jet_c11_pt_;
        float sublead_jet_c12_pt_;
        float sublead_jet_c13_pt_;
        float sublead_jet_c14_pt_;
        float sublead_jet_c15_pt_;
        float sublead_jet_c16_pt_;
        float sublead_jet_c17_pt_;
        float sublead_jet_c18_pt_;
        float sublead_jet_c19_pt_;
        float sublead_jet_c20_pt_;
        float sublead_jet_c21_pt_;
        float sublead_jet_c22_pt_;
        float sublead_jet_c23_pt_;
        float sublead_jet_c24_pt_;
        float sublead_jet_c25_pt_;
        float sublead_jet_c26_pt_;
        float sublead_jet_c27_pt_;
        float sublead_jet_c28_pt_;
        float sublead_jet_c29_pt_;
        float sublead_jet_c30_pt_;
        float sublead_jet_c31_pt_;
        float sublead_jet_c32_pt_;
        float sublead_jet_c33_pt_;
        float sublead_jet_c34_pt_;
        float sublead_jet_c35_pt_;
        float sublead_jet_c36_pt_;
        float sublead_jet_c37_pt_;
        float sublead_jet_c38_pt_;
        float sublead_jet_c39_pt_;
        float sublead_jet_c40_pt_;
        float sublead_jet_c41_pt_;
        float sublead_jet_c42_pt_;
        float sublead_jet_c43_pt_;
        float sublead_jet_c44_pt_;
        float sublead_jet_c45_pt_;
        float sublead_jet_c46_pt_;
        float sublead_jet_c47_pt_;
        float sublead_jet_c48_pt_;
        float sublead_jet_c49_pt_;
        float sublead_jet_c50_pt_;
        float sublead_jet_c51_pt_;
        float sublead_jet_c52_pt_;
        float sublead_jet_c53_pt_;
        float sublead_jet_c54_pt_;
        float sublead_jet_c55_pt_;
        float sublead_jet_c56_pt_;
        float sublead_jet_c57_pt_;
        float sublead_jet_c58_pt_;
        float sublead_jet_c59_pt_;
        float sublead_jet_c60_pt_;

        float sublead_jet_c1_energy_;
        float sublead_jet_c2_energy_;
        float sublead_jet_c3_energy_;
        float sublead_jet_c4_energy_;
        float sublead_jet_c5_energy_;
        float sublead_jet_c6_energy_;
        float sublead_jet_c7_energy_;
        float sublead_jet_c8_energy_;
        float sublead_jet_c9_energy_;
        float sublead_jet_c10_energy_;
        float sublead_jet_c11_energy_;
        float sublead_jet_c12_energy_;
        float sublead_jet_c13_energy_;
        float sublead_jet_c14_energy_;
        float sublead_jet_c15_energy_;
        float sublead_jet_c16_energy_;
        float sublead_jet_c17_energy_;
        float sublead_jet_c18_energy_;
        float sublead_jet_c19_energy_;
        float sublead_jet_c20_energy_;
        float sublead_jet_c21_energy_;
        float sublead_jet_c22_energy_;
        float sublead_jet_c23_energy_;
        float sublead_jet_c24_energy_;
        float sublead_jet_c25_energy_;
        float sublead_jet_c26_energy_;
        float sublead_jet_c27_energy_;
        float sublead_jet_c28_energy_;
        float sublead_jet_c29_energy_;
        float sublead_jet_c30_energy_;
        float sublead_jet_c31_energy_;
        float sublead_jet_c32_energy_;
        float sublead_jet_c33_energy_;
        float sublead_jet_c34_energy_;
        float sublead_jet_c35_energy_;
        float sublead_jet_c36_energy_;
        float sublead_jet_c37_energy_;
        float sublead_jet_c38_energy_;
        float sublead_jet_c39_energy_;
        float sublead_jet_c40_energy_;
        float sublead_jet_c41_energy_;
        float sublead_jet_c42_energy_;
        float sublead_jet_c43_energy_;
        float sublead_jet_c44_energy_;
        float sublead_jet_c45_energy_;
        float sublead_jet_c46_energy_;
        float sublead_jet_c47_energy_;
        float sublead_jet_c48_energy_;
        float sublead_jet_c49_energy_;
        float sublead_jet_c50_energy_;
        float sublead_jet_c51_energy_;
        float sublead_jet_c52_energy_;
        float sublead_jet_c53_energy_;
        float sublead_jet_c54_energy_;
        float sublead_jet_c55_energy_;
        float sublead_jet_c56_energy_;
        float sublead_jet_c57_energy_;
        float sublead_jet_c58_energy_;
        float sublead_jet_c59_energy_;
        float sublead_jet_c60_energy_;

        float subsublead_jet_c1_eta_;
        float subsublead_jet_c2_eta_;
        float subsublead_jet_c3_eta_;
        float subsublead_jet_c4_eta_;
        float subsublead_jet_c5_eta_;
        float subsublead_jet_c6_eta_;
        float subsublead_jet_c7_eta_;
        float subsublead_jet_c8_eta_;
        float subsublead_jet_c9_eta_;
        float subsublead_jet_c10_eta_;
        float subsublead_jet_c11_eta_;
        float subsublead_jet_c12_eta_;
        float subsublead_jet_c13_eta_;
        float subsublead_jet_c14_eta_;
        float subsublead_jet_c15_eta_;
        float subsublead_jet_c16_eta_;
        float subsublead_jet_c17_eta_;
        float subsublead_jet_c18_eta_;
        float subsublead_jet_c19_eta_;
        float subsublead_jet_c20_eta_;
        float subsublead_jet_c21_eta_;
        float subsublead_jet_c22_eta_;
        float subsublead_jet_c23_eta_;
        float subsublead_jet_c24_eta_;
        float subsublead_jet_c25_eta_;
        float subsublead_jet_c26_eta_;
        float subsublead_jet_c27_eta_;
        float subsublead_jet_c28_eta_;
        float subsublead_jet_c29_eta_;
        float subsublead_jet_c30_eta_;
        float subsublead_jet_c31_eta_;
        float subsublead_jet_c32_eta_;
        float subsublead_jet_c33_eta_;
        float subsublead_jet_c34_eta_;
        float subsublead_jet_c35_eta_;
        float subsublead_jet_c36_eta_;
        float subsublead_jet_c37_eta_;
        float subsublead_jet_c38_eta_;
        float subsublead_jet_c39_eta_;
        float subsublead_jet_c40_eta_;
        float subsublead_jet_c41_eta_;
        float subsublead_jet_c42_eta_;
        float subsublead_jet_c43_eta_;
        float subsublead_jet_c44_eta_;
        float subsublead_jet_c45_eta_;
        float subsublead_jet_c46_eta_;
        float subsublead_jet_c47_eta_;
        float subsublead_jet_c48_eta_;
        float subsublead_jet_c49_eta_;
        float subsublead_jet_c50_eta_;
        float subsublead_jet_c51_eta_;
        float subsublead_jet_c52_eta_;
        float subsublead_jet_c53_eta_;
        float subsublead_jet_c54_eta_;
        float subsublead_jet_c55_eta_;
        float subsublead_jet_c56_eta_;
        float subsublead_jet_c57_eta_;
        float subsublead_jet_c58_eta_;
        float subsublead_jet_c59_eta_;
        float subsublead_jet_c60_eta_;

        float subsublead_jet_c1_phi_;
        float subsublead_jet_c2_phi_;
        float subsublead_jet_c3_phi_;
        float subsublead_jet_c4_phi_;
        float subsublead_jet_c5_phi_;
        float subsublead_jet_c6_phi_;
        float subsublead_jet_c7_phi_;
        float subsublead_jet_c8_phi_;
        float subsublead_jet_c9_phi_;
        float subsublead_jet_c10_phi_;
        float subsublead_jet_c11_phi_;
        float subsublead_jet_c12_phi_;
        float subsublead_jet_c13_phi_;
        float subsublead_jet_c14_phi_;
        float subsublead_jet_c15_phi_;
        float subsublead_jet_c16_phi_;
        float subsublead_jet_c17_phi_;
        float subsublead_jet_c18_phi_;
        float subsublead_jet_c19_phi_;
        float subsublead_jet_c20_phi_;
        float subsublead_jet_c21_phi_;
        float subsublead_jet_c22_phi_;
        float subsublead_jet_c23_phi_;
        float subsublead_jet_c24_phi_;
        float subsublead_jet_c25_phi_;
        float subsublead_jet_c26_phi_;
        float subsublead_jet_c27_phi_;
        float subsublead_jet_c28_phi_;
        float subsublead_jet_c29_phi_;
        float subsublead_jet_c30_phi_;
        float subsublead_jet_c31_phi_;
        float subsublead_jet_c32_phi_;
        float subsublead_jet_c33_phi_;
        float subsublead_jet_c34_phi_;
        float subsublead_jet_c35_phi_;
        float subsublead_jet_c36_phi_;
        float subsublead_jet_c37_phi_;
        float subsublead_jet_c38_phi_;
        float subsublead_jet_c39_phi_;
        float subsublead_jet_c40_phi_;
        float subsublead_jet_c41_phi_;
        float subsublead_jet_c42_phi_;
        float subsublead_jet_c43_phi_;
        float subsublead_jet_c44_phi_;
        float subsublead_jet_c45_phi_;
        float subsublead_jet_c46_phi_;
        float subsublead_jet_c47_phi_;
        float subsublead_jet_c48_phi_;
        float subsublead_jet_c49_phi_;
        float subsublead_jet_c50_phi_;
        float subsublead_jet_c51_phi_;
        float subsublead_jet_c52_phi_;
        float subsublead_jet_c53_phi_;
        float subsublead_jet_c54_phi_;
        float subsublead_jet_c55_phi_;
        float subsublead_jet_c56_phi_;
        float subsublead_jet_c57_phi_;
        float subsublead_jet_c58_phi_;
        float subsublead_jet_c59_phi_;
        float subsublead_jet_c60_phi_;

        float subsublead_jet_c1_charge_;
        float subsublead_jet_c2_charge_;
        float subsublead_jet_c3_charge_;
        float subsublead_jet_c4_charge_;
        float subsublead_jet_c5_charge_;
        float subsublead_jet_c6_charge_;
        float subsublead_jet_c7_charge_;
        float subsublead_jet_c8_charge_;
        float subsublead_jet_c9_charge_;
        float subsublead_jet_c10_charge_;
        float subsublead_jet_c11_charge_;
        float subsublead_jet_c12_charge_;
        float subsublead_jet_c13_charge_;
        float subsublead_jet_c14_charge_;
        float subsublead_jet_c15_charge_;
        float subsublead_jet_c16_charge_;
        float subsublead_jet_c17_charge_;
        float subsublead_jet_c18_charge_;
        float subsublead_jet_c19_charge_;
        float subsublead_jet_c20_charge_;
        float subsublead_jet_c21_charge_;
        float subsublead_jet_c22_charge_;
        float subsublead_jet_c23_charge_;
        float subsublead_jet_c24_charge_;
        float subsublead_jet_c25_charge_;
        float subsublead_jet_c26_charge_;
        float subsublead_jet_c27_charge_;
        float subsublead_jet_c28_charge_;
        float subsublead_jet_c29_charge_;
        float subsublead_jet_c30_charge_;
        float subsublead_jet_c31_charge_;
        float subsublead_jet_c32_charge_;
        float subsublead_jet_c33_charge_;
        float subsublead_jet_c34_charge_;
        float subsublead_jet_c35_charge_;
        float subsublead_jet_c36_charge_;
        float subsublead_jet_c37_charge_;
        float subsublead_jet_c38_charge_;
        float subsublead_jet_c39_charge_;
        float subsublead_jet_c40_charge_;
        float subsublead_jet_c41_charge_;
        float subsublead_jet_c42_charge_;
        float subsublead_jet_c43_charge_;
        float subsublead_jet_c44_charge_;
        float subsublead_jet_c45_charge_;
        float subsublead_jet_c46_charge_;
        float subsublead_jet_c47_charge_;
        float subsublead_jet_c48_charge_;
        float subsublead_jet_c49_charge_;
        float subsublead_jet_c50_charge_;
        float subsublead_jet_c51_charge_;
        float subsublead_jet_c52_charge_;
        float subsublead_jet_c53_charge_;
        float subsublead_jet_c54_charge_;
        float subsublead_jet_c55_charge_;
        float subsublead_jet_c56_charge_;
        float subsublead_jet_c57_charge_;
        float subsublead_jet_c58_charge_;
        float subsublead_jet_c59_charge_;
        float subsublead_jet_c60_charge_;

        float subsublead_jet_c1_pt_;
        float subsublead_jet_c2_pt_;
        float subsublead_jet_c3_pt_;
        float subsublead_jet_c4_pt_;
        float subsublead_jet_c5_pt_;
        float subsublead_jet_c6_pt_;
        float subsublead_jet_c7_pt_;
        float subsublead_jet_c8_pt_;
        float subsublead_jet_c9_pt_;
        float subsublead_jet_c10_pt_;
        float subsublead_jet_c11_pt_;
        float subsublead_jet_c12_pt_;
        float subsublead_jet_c13_pt_;
        float subsublead_jet_c14_pt_;
        float subsublead_jet_c15_pt_;
        float subsublead_jet_c16_pt_;
        float subsublead_jet_c17_pt_;
        float subsublead_jet_c18_pt_;
        float subsublead_jet_c19_pt_;
        float subsublead_jet_c20_pt_;
        float subsublead_jet_c21_pt_;
        float subsublead_jet_c22_pt_;
        float subsublead_jet_c23_pt_;
        float subsublead_jet_c24_pt_;
        float subsublead_jet_c25_pt_;
        float subsublead_jet_c26_pt_;
        float subsublead_jet_c27_pt_;
        float subsublead_jet_c28_pt_;
        float subsublead_jet_c29_pt_;
        float subsublead_jet_c30_pt_;
        float subsublead_jet_c31_pt_;
        float subsublead_jet_c32_pt_;
        float subsublead_jet_c33_pt_;
        float subsublead_jet_c34_pt_;
        float subsublead_jet_c35_pt_;
        float subsublead_jet_c36_pt_;
        float subsublead_jet_c37_pt_;
        float subsublead_jet_c38_pt_;
        float subsublead_jet_c39_pt_;
        float subsublead_jet_c40_pt_;
        float subsublead_jet_c41_pt_;
        float subsublead_jet_c42_pt_;
        float subsublead_jet_c43_pt_;
        float subsublead_jet_c44_pt_;
        float subsublead_jet_c45_pt_;
        float subsublead_jet_c46_pt_;
        float subsublead_jet_c47_pt_;
        float subsublead_jet_c48_pt_;
        float subsublead_jet_c49_pt_;
        float subsublead_jet_c50_pt_;
        float subsublead_jet_c51_pt_;
        float subsublead_jet_c52_pt_;
        float subsublead_jet_c53_pt_;
        float subsublead_jet_c54_pt_;
        float subsublead_jet_c55_pt_;
        float subsublead_jet_c56_pt_;
        float subsublead_jet_c57_pt_;
        float subsublead_jet_c58_pt_;
        float subsublead_jet_c59_pt_;
        float subsublead_jet_c60_pt_;

        float subsublead_jet_c1_energy_;
        float subsublead_jet_c2_energy_;
        float subsublead_jet_c3_energy_;
        float subsublead_jet_c4_energy_;
        float subsublead_jet_c5_energy_;
        float subsublead_jet_c6_energy_;
        float subsublead_jet_c7_energy_;
        float subsublead_jet_c8_energy_;
        float subsublead_jet_c9_energy_;
        float subsublead_jet_c10_energy_;
        float subsublead_jet_c11_energy_;
        float subsublead_jet_c12_energy_;
        float subsublead_jet_c13_energy_;
        float subsublead_jet_c14_energy_;
        float subsublead_jet_c15_energy_;
        float subsublead_jet_c16_energy_;
        float subsublead_jet_c17_energy_;
        float subsublead_jet_c18_energy_;
        float subsublead_jet_c19_energy_;
        float subsublead_jet_c20_energy_;
        float subsublead_jet_c21_energy_;
        float subsublead_jet_c22_energy_;
        float subsublead_jet_c23_energy_;
        float subsublead_jet_c24_energy_;
        float subsublead_jet_c25_energy_;
        float subsublead_jet_c26_energy_;
        float subsublead_jet_c27_energy_;
        float subsublead_jet_c28_energy_;
        float subsublead_jet_c29_energy_;
        float subsublead_jet_c30_energy_;
        float subsublead_jet_c31_energy_;
        float subsublead_jet_c32_energy_;
        float subsublead_jet_c33_energy_;
        float subsublead_jet_c34_energy_;
        float subsublead_jet_c35_energy_;
        float subsublead_jet_c36_energy_;
        float subsublead_jet_c37_energy_;
        float subsublead_jet_c38_energy_;
        float subsublead_jet_c39_energy_;
        float subsublead_jet_c40_energy_;
        float subsublead_jet_c41_energy_;
        float subsublead_jet_c42_energy_;
        float subsublead_jet_c43_energy_;
        float subsublead_jet_c44_energy_;
        float subsublead_jet_c45_energy_;
        float subsublead_jet_c46_energy_;
        float subsublead_jet_c47_energy_;
        float subsublead_jet_c48_energy_;
        float subsublead_jet_c49_energy_;
        float subsublead_jet_c50_energy_;
        float subsublead_jet_c51_energy_;
        float subsublead_jet_c52_energy_;
        float subsublead_jet_c53_energy_;
        float subsublead_jet_c54_energy_;
        float subsublead_jet_c55_energy_;
        float subsublead_jet_c56_energy_;
        float subsublead_jet_c57_energy_;
        float subsublead_jet_c58_energy_;
        float subsublead_jet_c59_energy_;
        float subsublead_jet_c60_energy_;

        float dipho_PToM_  ;
        float leadPho_PToM_;
        float sublPho_PToM_;

    };
    
    VBFMVAProducer::VBFMVAProducer( const ParameterSet &iConfig ) :
        diPhotonToken_( consumes<View<flashgg::DiPhotonCandidate> >( iConfig.getParameter<InputTag> ( "DiPhotonTag" ) ) ),
        //jetTokenDz_( consumes<View<flashgg::Jet> >( iConfig.getParameter<InputTag>( "JetTag" ) ) ),
        inputTagJets_ ( iConfig.getParameter<std::vector<edm::InputTag> >( "inputTagJets" ) ),
        _MVAMethod    ( iConfig.getParameter<string> ( "MVAMethod"    ) ),
        _usePuJetID   ( iConfig.getParameter<bool>   ( "UsePuJetID"   ) ),
        _useJetID     ( iConfig.getParameter<bool>   ( "UseJetID"     ) ),
        _merge3rdJet  ( iConfig.getParameter<bool>   ( "merge3rdJet"  ) ),
        _thirdJetDRCut( iConfig.getParameter<double> ( "thirdJetDRCut") ),
        _rmsforwardCut( iConfig.getParameter<double> ( "rmsforwardCut") ),
        _JetIDLevel   ( iConfig.getParameter<string> ( "JetIDLevel"   ) ),
        _minDijetMinv ( iConfig.getParameter<double> ( "MinDijetMinv" ) ),
        _drJetPhoton  ( iConfig.getParameter<double> ( "DrJetPhoton"  ) ),
        _pujid_wp_pt_bin_1  ( iConfig.getParameter<std::vector<double> > ( "pujidWpPtBin1" ) ),
        _pujid_wp_pt_bin_2  ( iConfig.getParameter<std::vector<double> > ( "pujidWpPtBin2" ) ),
        _pujid_wp_pt_bin_3  ( iConfig.getParameter<std::vector<double> > ( "pujidWpPtBin3" ) )
    {
        vbfMVAweightfile_ = iConfig.getParameter<edm::FileInPath>( "vbfMVAweightfile" );
        
        dijet_leadEta_    = -999.;
        dijet_subleadEta_ = -999.;
        dijet_abs_dEta_   = -999.;
        dijet_LeadJPt_    = -999.;
        dijet_pt_         = -999.;
        dijet_SubJPt_     = -999.;
        dijet_Zep_        = -999.;
        dijet_dphi_trunc_ = -999.;
        dijet_dipho_dphi_ = -999.;
        dijet_dphi_       = -999.;
        dijet_Mjj_        = -999.;
        dijet_dy_         = -999.;
        cosThetaStar_     = -999.; 
        constit_energy_   = -999.; 

        pt_J1_ = -999.;
        eta_J1_ = -999.;
        phi_J1_ = -999.;
        charge_J1_ = -999.;
        energy_J1_ = -999.;
        flav_J1_ = -999.;

        pt_J2_ = -999.;
        eta_J2_ = -999.;
        phi_J2_ = -999.;
        charge_J2_ = -999.;
        energy_J2_ = -999.;
        flav_J2_ = -999.;

        pt_J3_ = -999.;
        eta_J3_ = -999.;
        phi_J3_ = -999.;
        charge_J3_ = -999.;
        energy_J3_ = -999.;
        flav_J3_ = -999.;
      
        n_constits_       = -999.;
        //test_vec_.push_back(-999.);

        lead_jet_pt_      = -999;
        test_lead_jet_eta_      = -999;

        lead_jet_c1_eta_  = -999.;
        lead_jet_c2_eta_  = -999.;
        lead_jet_c3_eta_  = -999.;
        lead_jet_c4_eta_  = -999.;
        lead_jet_c5_eta_  = -999.;
        lead_jet_c6_eta_  = -999.;
        lead_jet_c7_eta_  = -999.;
        lead_jet_c8_eta_  = -999.;
        lead_jet_c9_eta_  = -999.;
        lead_jet_c10_eta_  = -999.;
        lead_jet_c11_eta_  = -999.;
        lead_jet_c12_eta_  = -999.;
        lead_jet_c13_eta_  = -999.;
        lead_jet_c14_eta_  = -999.;
        lead_jet_c15_eta_  = -999.;
        lead_jet_c16_eta_  = -999.;
        lead_jet_c17_eta_  = -999.;
        lead_jet_c18_eta_  = -999.;
        lead_jet_c19_eta_  = -999.;
        lead_jet_c20_eta_  = -999.;
        lead_jet_c21_eta_  = -999.;
        lead_jet_c22_eta_  = -999.;
        lead_jet_c23_eta_  = -999.;
        lead_jet_c24_eta_  = -999.;
        lead_jet_c25_eta_  = -999.;
        lead_jet_c26_eta_  = -999.;
        lead_jet_c27_eta_  = -999.;
        lead_jet_c28_eta_  = -999.;
        lead_jet_c29_eta_  = -999.;
        lead_jet_c30_eta_  = -999.;
        lead_jet_c31_eta_  = -999.;
        lead_jet_c32_eta_  = -999.;
        lead_jet_c33_eta_  = -999.;
        lead_jet_c34_eta_  = -999.;
        lead_jet_c35_eta_  = -999.;
        lead_jet_c36_eta_  = -999.;
        lead_jet_c37_eta_  = -999.;
        lead_jet_c38_eta_  = -999.;
        lead_jet_c39_eta_  = -999.;
        lead_jet_c40_eta_  = -999.;
        lead_jet_c41_eta_  = -999.;
        lead_jet_c42_eta_  = -999.;
        lead_jet_c43_eta_  = -999.;
        lead_jet_c44_eta_  = -999.;
        lead_jet_c45_eta_  = -999.;
        lead_jet_c46_eta_  = -999.;
        lead_jet_c47_eta_  = -999.;
        lead_jet_c48_eta_  = -999.;
        lead_jet_c49_eta_  = -999.;
        lead_jet_c50_eta_  = -999.;
        lead_jet_c51_eta_  = -999.;
        lead_jet_c52_eta_  = -999.;
        lead_jet_c53_eta_  = -999.;
        lead_jet_c54_eta_  = -999.;
        lead_jet_c55_eta_  = -999.;
        lead_jet_c56_eta_  = -999.;
        lead_jet_c57_eta_  = -999.;
        lead_jet_c58_eta_  = -999.;
        lead_jet_c59_eta_  = -999.;
        lead_jet_c60_eta_  = -999.;

        lead_jet_c1_phi_  = -999.;
        lead_jet_c2_phi_  = -999.;
        lead_jet_c3_phi_  = -999.;
        lead_jet_c4_phi_  = -999.;
        lead_jet_c5_phi_  = -999.;
        lead_jet_c6_phi_  = -999.;
        lead_jet_c7_phi_  = -999.;
        lead_jet_c8_phi_  = -999.;
        lead_jet_c9_phi_  = -999.;
        lead_jet_c10_phi_  = -999.;
        lead_jet_c11_phi_  = -999.;
        lead_jet_c12_phi_  = -999.;
        lead_jet_c13_phi_  = -999.;
        lead_jet_c14_phi_  = -999.;
        lead_jet_c15_phi_  = -999.;
        lead_jet_c16_phi_  = -999.;
        lead_jet_c17_phi_  = -999.;
        lead_jet_c18_phi_  = -999.;
        lead_jet_c19_phi_  = -999.;
        lead_jet_c20_phi_  = -999.;
        lead_jet_c21_phi_  = -999.;
        lead_jet_c22_phi_  = -999.;
        lead_jet_c23_phi_  = -999.;
        lead_jet_c24_phi_  = -999.;
        lead_jet_c25_phi_  = -999.;
        lead_jet_c26_phi_  = -999.;
        lead_jet_c27_phi_  = -999.;
        lead_jet_c28_phi_  = -999.;
        lead_jet_c29_phi_  = -999.;
        lead_jet_c30_phi_  = -999.;
        lead_jet_c31_phi_  = -999.;
        lead_jet_c32_phi_  = -999.;
        lead_jet_c33_phi_  = -999.;
        lead_jet_c34_phi_  = -999.;
        lead_jet_c35_phi_  = -999.;
        lead_jet_c36_phi_  = -999.;
        lead_jet_c37_phi_  = -999.;
        lead_jet_c38_phi_  = -999.;
        lead_jet_c39_phi_  = -999.;
        lead_jet_c40_phi_  = -999.;
        lead_jet_c41_phi_  = -999.;
        lead_jet_c42_phi_  = -999.;
        lead_jet_c43_phi_  = -999.;
        lead_jet_c44_phi_  = -999.;
        lead_jet_c45_phi_  = -999.;
        lead_jet_c46_phi_  = -999.;
        lead_jet_c47_phi_  = -999.;
        lead_jet_c48_phi_  = -999.;
        lead_jet_c49_phi_  = -999.;
        lead_jet_c50_phi_  = -999.;
        lead_jet_c51_phi_  = -999.;
        lead_jet_c52_phi_  = -999.;
        lead_jet_c53_phi_  = -999.;
        lead_jet_c54_phi_  = -999.;
        lead_jet_c55_phi_  = -999.;
        lead_jet_c56_phi_  = -999.;
        lead_jet_c57_phi_  = -999.;
        lead_jet_c58_phi_  = -999.;
        lead_jet_c59_phi_  = -999.;
        lead_jet_c60_phi_  = -999.;

        lead_jet_c1_charge_ = -999.;
        lead_jet_c2_charge_ = -999.;
        lead_jet_c3_charge_ = -999.;
        lead_jet_c4_charge_ = -999.;
        lead_jet_c5_charge_ = -999.;
        lead_jet_c6_charge_ = -999.;
        lead_jet_c7_charge_ = -999.;
        lead_jet_c8_charge_ = -999.;
        lead_jet_c9_charge_ = -999.;
        lead_jet_c10_charge_ = -999.;
        lead_jet_c11_charge_ = -999.;
        lead_jet_c12_charge_ = -999.;
        lead_jet_c13_charge_ = -999.;
        lead_jet_c14_charge_ = -999.;
        lead_jet_c15_charge_ = -999.;
        lead_jet_c16_charge_ = -999.;
        lead_jet_c17_charge_ = -999.;
        lead_jet_c18_charge_ = -999.;
        lead_jet_c19_charge_ = -999.;
        lead_jet_c20_charge_ = -999.;
        lead_jet_c21_charge_ = -999.;
        lead_jet_c22_charge_ = -999.;
        lead_jet_c23_charge_ = -999.;
        lead_jet_c24_charge_ = -999.;
        lead_jet_c25_charge_ = -999.;
        lead_jet_c26_charge_ = -999.;
        lead_jet_c27_charge_ = -999.;
        lead_jet_c28_charge_ = -999.;
        lead_jet_c29_charge_ = -999.;
        lead_jet_c30_charge_ = -999.;
        lead_jet_c31_charge_ = -999.;
        lead_jet_c32_charge_ = -999.;
        lead_jet_c33_charge_ = -999.;
        lead_jet_c34_charge_ = -999.;
        lead_jet_c35_charge_ = -999.;
        lead_jet_c36_charge_ = -999.;
        lead_jet_c37_charge_ = -999.;
        lead_jet_c38_charge_ = -999.;
        lead_jet_c39_charge_ = -999.;
        lead_jet_c40_charge_ = -999.;
        lead_jet_c41_charge_ = -999.;
        lead_jet_c42_charge_ = -999.;
        lead_jet_c43_charge_ = -999.;
        lead_jet_c44_charge_ = -999.;
        lead_jet_c45_charge_ = -999.;
        lead_jet_c46_charge_ = -999.;
        lead_jet_c47_charge_ = -999.;
        lead_jet_c48_charge_ = -999.;
        lead_jet_c49_charge_ = -999.;
        lead_jet_c50_charge_ = -999.;
        lead_jet_c51_charge_ = -999.;
        lead_jet_c52_charge_ = -999.;
        lead_jet_c53_charge_ = -999.;
        lead_jet_c54_charge_ = -999.;
        lead_jet_c55_charge_ = -999.;
        lead_jet_c56_charge_ = -999.;
        lead_jet_c57_charge_ = -999.;
        lead_jet_c58_charge_ = -999.;
        lead_jet_c59_charge_ = -999.;
        lead_jet_c60_charge_ = -999.;

        lead_jet_c1_pt_ = -999.;
        lead_jet_c2_pt_ = -999.;
        lead_jet_c3_pt_ = -999.;
        lead_jet_c4_pt_ = -999.;
        lead_jet_c5_pt_ = -999.;
        lead_jet_c6_pt_ = -999.;
        lead_jet_c7_pt_ = -999.;
        lead_jet_c8_pt_ = -999.;
        lead_jet_c9_pt_ = -999.;
        lead_jet_c10_pt_ = -999.;
        lead_jet_c11_pt_ = -999.;
        lead_jet_c12_pt_ = -999.;
        lead_jet_c13_pt_ = -999.;
        lead_jet_c14_pt_ = -999.;
        lead_jet_c15_pt_ = -999.;
        lead_jet_c16_pt_ = -999.;
        lead_jet_c17_pt_ = -999.;
        lead_jet_c18_pt_ = -999.;
        lead_jet_c19_pt_ = -999.;
        lead_jet_c20_pt_ = -999.;
        lead_jet_c21_pt_ = -999.;
        lead_jet_c22_pt_ = -999.;
        lead_jet_c23_pt_ = -999.;
        lead_jet_c24_pt_ = -999.;
        lead_jet_c25_pt_ = -999.;
        lead_jet_c26_pt_ = -999.;
        lead_jet_c27_pt_ = -999.;
        lead_jet_c28_pt_ = -999.;
        lead_jet_c29_pt_ = -999.;
        lead_jet_c30_pt_ = -999.;
        lead_jet_c31_pt_ = -999.;
        lead_jet_c32_pt_ = -999.;
        lead_jet_c33_pt_ = -999.;
        lead_jet_c34_pt_ = -999.;
        lead_jet_c35_pt_ = -999.;
        lead_jet_c36_pt_ = -999.;
        lead_jet_c37_pt_ = -999.;
        lead_jet_c38_pt_ = -999.;
        lead_jet_c39_pt_ = -999.;
        lead_jet_c40_pt_ = -999.;
        lead_jet_c41_pt_ = -999.;
        lead_jet_c42_pt_ = -999.;
        lead_jet_c43_pt_ = -999.;
        lead_jet_c44_pt_ = -999.;
        lead_jet_c45_pt_ = -999.;
        lead_jet_c46_pt_ = -999.;
        lead_jet_c47_pt_ = -999.;
        lead_jet_c48_pt_ = -999.;
        lead_jet_c49_pt_ = -999.;
        lead_jet_c50_pt_ = -999.;
        lead_jet_c51_pt_ = -999.;
        lead_jet_c52_pt_ = -999.;
        lead_jet_c53_pt_ = -999.;
        lead_jet_c54_pt_ = -999.;
        lead_jet_c55_pt_ = -999.;
        lead_jet_c56_pt_ = -999.;
        lead_jet_c57_pt_ = -999.;
        lead_jet_c58_pt_ = -999.;
        lead_jet_c59_pt_ = -999.;
        lead_jet_c60_pt_ = -999.;

        lead_jet_c1_energy_ = -999.;
        lead_jet_c2_energy_ = -999.;
        lead_jet_c3_energy_ = -999.;
        lead_jet_c4_energy_ = -999.;
        lead_jet_c5_energy_ = -999.;
        lead_jet_c6_energy_ = -999.;
        lead_jet_c7_energy_ = -999.;
        lead_jet_c8_energy_ = -999.;
        lead_jet_c9_energy_ = -999.;
        lead_jet_c10_energy_ = -999.;
        lead_jet_c11_energy_ = -999.;
        lead_jet_c12_energy_ = -999.;
        lead_jet_c13_energy_ = -999.;
        lead_jet_c14_energy_ = -999.;
        lead_jet_c15_energy_ = -999.;
        lead_jet_c16_energy_ = -999.;
        lead_jet_c17_energy_ = -999.;
        lead_jet_c18_energy_ = -999.;
        lead_jet_c19_energy_ = -999.;
        lead_jet_c20_energy_ = -999.;
        lead_jet_c21_energy_ = -999.;
        lead_jet_c22_energy_ = -999.;
        lead_jet_c23_energy_ = -999.;
        lead_jet_c24_energy_ = -999.;
        lead_jet_c25_energy_ = -999.;
        lead_jet_c26_energy_ = -999.;
        lead_jet_c27_energy_ = -999.;
        lead_jet_c28_energy_ = -999.;
        lead_jet_c29_energy_ = -999.;
        lead_jet_c30_energy_ = -999.;
        lead_jet_c31_energy_ = -999.;
        lead_jet_c32_energy_ = -999.;
        lead_jet_c33_energy_ = -999.;
        lead_jet_c34_energy_ = -999.;
        lead_jet_c35_energy_ = -999.;
        lead_jet_c36_energy_ = -999.;
        lead_jet_c37_energy_ = -999.;
        lead_jet_c38_energy_ = -999.;
        lead_jet_c39_energy_ = -999.;
        lead_jet_c40_energy_ = -999.;
        lead_jet_c41_energy_ = -999.;
        lead_jet_c42_energy_ = -999.;
        lead_jet_c43_energy_ = -999.;
        lead_jet_c44_energy_ = -999.;
        lead_jet_c45_energy_ = -999.;
        lead_jet_c46_energy_ = -999.;
        lead_jet_c47_energy_ = -999.;
        lead_jet_c48_energy_ = -999.;
        lead_jet_c49_energy_ = -999.;
        lead_jet_c50_energy_ = -999.;
        lead_jet_c51_energy_ = -999.;
        lead_jet_c52_energy_ = -999.;
        lead_jet_c53_energy_ = -999.;
        lead_jet_c54_energy_ = -999.;
        lead_jet_c55_energy_ = -999.;
        lead_jet_c56_energy_ = -999.;
        lead_jet_c57_energy_ = -999.;
        lead_jet_c58_energy_ = -999.;
        lead_jet_c59_energy_ = -999.;
        lead_jet_c60_energy_ = -999.;

        sublead_jet_c1_eta_  = -999.;
        sublead_jet_c2_eta_  = -999.;
        sublead_jet_c3_eta_  = -999.;
        sublead_jet_c4_eta_  = -999.;
        sublead_jet_c5_eta_  = -999.;
        sublead_jet_c6_eta_  = -999.;
        sublead_jet_c7_eta_  = -999.;
        sublead_jet_c8_eta_  = -999.;
        sublead_jet_c9_eta_  = -999.;
        sublead_jet_c10_eta_  = -999.;
        sublead_jet_c11_eta_  = -999.;
        sublead_jet_c12_eta_  = -999.;
        sublead_jet_c13_eta_  = -999.;
        sublead_jet_c14_eta_  = -999.;
        sublead_jet_c15_eta_  = -999.;
        sublead_jet_c16_eta_  = -999.;
        sublead_jet_c17_eta_  = -999.;
        sublead_jet_c18_eta_  = -999.;
        sublead_jet_c19_eta_  = -999.;
        sublead_jet_c20_eta_  = -999.;
        sublead_jet_c21_eta_  = -999.;
        sublead_jet_c22_eta_  = -999.;
        sublead_jet_c23_eta_  = -999.;
        sublead_jet_c24_eta_  = -999.;
        sublead_jet_c25_eta_  = -999.;
        sublead_jet_c26_eta_  = -999.;
        sublead_jet_c27_eta_  = -999.;
        sublead_jet_c28_eta_  = -999.;
        sublead_jet_c29_eta_  = -999.;
        sublead_jet_c30_eta_  = -999.;
        sublead_jet_c31_eta_  = -999.;
        sublead_jet_c32_eta_  = -999.;
        sublead_jet_c33_eta_  = -999.;
        sublead_jet_c34_eta_  = -999.;
        sublead_jet_c35_eta_  = -999.;
        sublead_jet_c36_eta_  = -999.;
        sublead_jet_c37_eta_  = -999.;
        sublead_jet_c38_eta_  = -999.;
        sublead_jet_c39_eta_  = -999.;
        sublead_jet_c40_eta_  = -999.;
        sublead_jet_c41_eta_  = -999.;
        sublead_jet_c42_eta_  = -999.;
        sublead_jet_c43_eta_  = -999.;
        sublead_jet_c44_eta_  = -999.;
        sublead_jet_c45_eta_  = -999.;
        sublead_jet_c46_eta_  = -999.;
        sublead_jet_c47_eta_  = -999.;
        sublead_jet_c48_eta_  = -999.;
        sublead_jet_c49_eta_  = -999.;
        sublead_jet_c50_eta_  = -999.;
        sublead_jet_c51_eta_  = -999.;
        sublead_jet_c52_eta_  = -999.;
        sublead_jet_c53_eta_  = -999.;
        sublead_jet_c54_eta_  = -999.;
        sublead_jet_c55_eta_  = -999.;
        sublead_jet_c56_eta_  = -999.;
        sublead_jet_c57_eta_  = -999.;
        sublead_jet_c58_eta_  = -999.;
        sublead_jet_c59_eta_  = -999.;
        sublead_jet_c60_eta_  = -999.;

        sublead_jet_c1_phi_  = -999.;
        sublead_jet_c2_phi_  = -999.;
        sublead_jet_c3_phi_  = -999.;
        sublead_jet_c4_phi_  = -999.;
        sublead_jet_c5_phi_  = -999.;
        sublead_jet_c6_phi_  = -999.;
        sublead_jet_c7_phi_  = -999.;
        sublead_jet_c8_phi_  = -999.;
        sublead_jet_c9_phi_  = -999.;
        sublead_jet_c10_phi_  = -999.;
        sublead_jet_c11_phi_  = -999.;
        sublead_jet_c12_phi_  = -999.;
        sublead_jet_c13_phi_  = -999.;
        sublead_jet_c14_phi_  = -999.;
        sublead_jet_c15_phi_  = -999.;
        sublead_jet_c16_phi_  = -999.;
        sublead_jet_c17_phi_  = -999.;
        sublead_jet_c18_phi_  = -999.;
        sublead_jet_c19_phi_  = -999.;
        sublead_jet_c20_phi_  = -999.;
        sublead_jet_c21_phi_  = -999.;
        sublead_jet_c22_phi_  = -999.;
        sublead_jet_c23_phi_  = -999.;
        sublead_jet_c24_phi_  = -999.;
        sublead_jet_c25_phi_  = -999.;
        sublead_jet_c26_phi_  = -999.;
        sublead_jet_c27_phi_  = -999.;
        sublead_jet_c28_phi_  = -999.;
        sublead_jet_c29_phi_  = -999.;
        sublead_jet_c30_phi_  = -999.;
        sublead_jet_c31_phi_  = -999.;
        sublead_jet_c32_phi_  = -999.;
        sublead_jet_c33_phi_  = -999.;
        sublead_jet_c34_phi_  = -999.;
        sublead_jet_c35_phi_  = -999.;
        sublead_jet_c36_phi_  = -999.;
        sublead_jet_c37_phi_  = -999.;
        sublead_jet_c38_phi_  = -999.;
        sublead_jet_c39_phi_  = -999.;
        sublead_jet_c40_phi_  = -999.;
        sublead_jet_c41_phi_  = -999.;
        sublead_jet_c42_phi_  = -999.;
        sublead_jet_c43_phi_  = -999.;
        sublead_jet_c44_phi_  = -999.;
        sublead_jet_c45_phi_  = -999.;
        sublead_jet_c46_phi_  = -999.;
        sublead_jet_c47_phi_  = -999.;
        sublead_jet_c48_phi_  = -999.;
        sublead_jet_c49_phi_  = -999.;
        sublead_jet_c50_phi_  = -999.;
        sublead_jet_c51_phi_  = -999.;
        sublead_jet_c52_phi_  = -999.;
        sublead_jet_c53_phi_  = -999.;
        sublead_jet_c54_phi_  = -999.;
        sublead_jet_c55_phi_  = -999.;
        sublead_jet_c56_phi_  = -999.;
        sublead_jet_c57_phi_  = -999.;
        sublead_jet_c58_phi_  = -999.;
        sublead_jet_c59_phi_  = -999.;
        sublead_jet_c60_phi_  = -999.;

        sublead_jet_c1_charge_ = -999.;
        sublead_jet_c2_charge_ = -999.;
        sublead_jet_c3_charge_ = -999.;
        sublead_jet_c4_charge_ = -999.;
        sublead_jet_c5_charge_ = -999.;
        sublead_jet_c6_charge_ = -999.;
        sublead_jet_c7_charge_ = -999.;
        sublead_jet_c8_charge_ = -999.;
        sublead_jet_c9_charge_ = -999.;
        sublead_jet_c10_charge_ = -999.;
        sublead_jet_c11_charge_ = -999.;
        sublead_jet_c12_charge_ = -999.;
        sublead_jet_c13_charge_ = -999.;
        sublead_jet_c14_charge_ = -999.;
        sublead_jet_c15_charge_ = -999.;
        sublead_jet_c16_charge_ = -999.;
        sublead_jet_c17_charge_ = -999.;
        sublead_jet_c18_charge_ = -999.;
        sublead_jet_c19_charge_ = -999.;
        sublead_jet_c20_charge_ = -999.;
        sublead_jet_c21_charge_ = -999.;
        sublead_jet_c22_charge_ = -999.;
        sublead_jet_c23_charge_ = -999.;
        sublead_jet_c24_charge_ = -999.;
        sublead_jet_c25_charge_ = -999.;
        sublead_jet_c26_charge_ = -999.;
        sublead_jet_c27_charge_ = -999.;
        sublead_jet_c28_charge_ = -999.;
        sublead_jet_c29_charge_ = -999.;
        sublead_jet_c30_charge_ = -999.;
        sublead_jet_c31_charge_ = -999.;
        sublead_jet_c32_charge_ = -999.;
        sublead_jet_c33_charge_ = -999.;
        sublead_jet_c34_charge_ = -999.;
        sublead_jet_c35_charge_ = -999.;
        sublead_jet_c36_charge_ = -999.;
        sublead_jet_c37_charge_ = -999.;
        sublead_jet_c38_charge_ = -999.;
        sublead_jet_c39_charge_ = -999.;
        sublead_jet_c40_charge_ = -999.;
        sublead_jet_c41_charge_ = -999.;
        sublead_jet_c42_charge_ = -999.;
        sublead_jet_c43_charge_ = -999.;
        sublead_jet_c44_charge_ = -999.;
        sublead_jet_c45_charge_ = -999.;
        sublead_jet_c46_charge_ = -999.;
        sublead_jet_c47_charge_ = -999.;
        sublead_jet_c48_charge_ = -999.;
        sublead_jet_c49_charge_ = -999.;
        sublead_jet_c50_charge_ = -999.;
        sublead_jet_c51_charge_ = -999.;
        sublead_jet_c52_charge_ = -999.;
        sublead_jet_c53_charge_ = -999.;
        sublead_jet_c54_charge_ = -999.;
        sublead_jet_c55_charge_ = -999.;
        sublead_jet_c56_charge_ = -999.;
        sublead_jet_c57_charge_ = -999.;
        sublead_jet_c58_charge_ = -999.;
        sublead_jet_c59_charge_ = -999.;
        sublead_jet_c60_charge_ = -999.;

        sublead_jet_c1_pt_ = -999.;
        sublead_jet_c2_pt_ = -999.;
        sublead_jet_c3_pt_ = -999.;
        sublead_jet_c4_pt_ = -999.;
        sublead_jet_c5_pt_ = -999.;
        sublead_jet_c6_pt_ = -999.;
        sublead_jet_c7_pt_ = -999.;
        sublead_jet_c8_pt_ = -999.;
        sublead_jet_c9_pt_ = -999.;
        sublead_jet_c10_pt_ = -999.;
        sublead_jet_c11_pt_ = -999.;
        sublead_jet_c12_pt_ = -999.;
        sublead_jet_c13_pt_ = -999.;
        sublead_jet_c14_pt_ = -999.;
        sublead_jet_c15_pt_ = -999.;
        sublead_jet_c16_pt_ = -999.;
        sublead_jet_c17_pt_ = -999.;
        sublead_jet_c18_pt_ = -999.;
        sublead_jet_c19_pt_ = -999.;
        sublead_jet_c20_pt_ = -999.;
        sublead_jet_c21_pt_ = -999.;
        sublead_jet_c22_pt_ = -999.;
        sublead_jet_c23_pt_ = -999.;
        sublead_jet_c24_pt_ = -999.;
        sublead_jet_c25_pt_ = -999.;
        sublead_jet_c26_pt_ = -999.;
        sublead_jet_c27_pt_ = -999.;
        sublead_jet_c28_pt_ = -999.;
        sublead_jet_c29_pt_ = -999.;
        sublead_jet_c30_pt_ = -999.;
        sublead_jet_c31_pt_ = -999.;
        sublead_jet_c32_pt_ = -999.;
        sublead_jet_c33_pt_ = -999.;
        sublead_jet_c34_pt_ = -999.;
        sublead_jet_c35_pt_ = -999.;
        sublead_jet_c36_pt_ = -999.;
        sublead_jet_c37_pt_ = -999.;
        sublead_jet_c38_pt_ = -999.;
        sublead_jet_c39_pt_ = -999.;
        sublead_jet_c40_pt_ = -999.;
        sublead_jet_c41_pt_ = -999.;
        sublead_jet_c42_pt_ = -999.;
        sublead_jet_c43_pt_ = -999.;
        sublead_jet_c44_pt_ = -999.;
        sublead_jet_c45_pt_ = -999.;
        sublead_jet_c46_pt_ = -999.;
        sublead_jet_c47_pt_ = -999.;
        sublead_jet_c48_pt_ = -999.;
        sublead_jet_c49_pt_ = -999.;
        sublead_jet_c50_pt_ = -999.;
        sublead_jet_c51_pt_ = -999.;
        sublead_jet_c52_pt_ = -999.;
        sublead_jet_c53_pt_ = -999.;
        sublead_jet_c54_pt_ = -999.;
        sublead_jet_c55_pt_ = -999.;
        sublead_jet_c56_pt_ = -999.;
        sublead_jet_c57_pt_ = -999.;
        sublead_jet_c58_pt_ = -999.;
        sublead_jet_c59_pt_ = -999.;
        sublead_jet_c60_pt_ = -999.;

        sublead_jet_c1_energy_ = -999.;
        sublead_jet_c2_energy_ = -999.;
        sublead_jet_c3_energy_ = -999.;
        sublead_jet_c4_energy_ = -999.;
        sublead_jet_c5_energy_ = -999.;
        sublead_jet_c6_energy_ = -999.;
        sublead_jet_c7_energy_ = -999.;
        sublead_jet_c8_energy_ = -999.;
        sublead_jet_c9_energy_ = -999.;
        sublead_jet_c10_energy_ = -999.;
        sublead_jet_c11_energy_ = -999.;
        sublead_jet_c12_energy_ = -999.;
        sublead_jet_c13_energy_ = -999.;
        sublead_jet_c14_energy_ = -999.;
        sublead_jet_c15_energy_ = -999.;
        sublead_jet_c16_energy_ = -999.;
        sublead_jet_c17_energy_ = -999.;
        sublead_jet_c18_energy_ = -999.;
        sublead_jet_c19_energy_ = -999.;
        sublead_jet_c20_energy_ = -999.;
        sublead_jet_c21_energy_ = -999.;
        sublead_jet_c22_energy_ = -999.;
        sublead_jet_c23_energy_ = -999.;
        sublead_jet_c24_energy_ = -999.;
        sublead_jet_c25_energy_ = -999.;
        sublead_jet_c26_energy_ = -999.;
        sublead_jet_c27_energy_ = -999.;
        sublead_jet_c28_energy_ = -999.;
        sublead_jet_c29_energy_ = -999.;
        sublead_jet_c30_energy_ = -999.;
        sublead_jet_c31_energy_ = -999.;
        sublead_jet_c32_energy_ = -999.;
        sublead_jet_c33_energy_ = -999.;
        sublead_jet_c34_energy_ = -999.;
        sublead_jet_c35_energy_ = -999.;
        sublead_jet_c36_energy_ = -999.;
        sublead_jet_c37_energy_ = -999.;
        sublead_jet_c38_energy_ = -999.;
        sublead_jet_c39_energy_ = -999.;
        sublead_jet_c40_energy_ = -999.;
        sublead_jet_c41_energy_ = -999.;
        sublead_jet_c42_energy_ = -999.;
        sublead_jet_c43_energy_ = -999.;
        sublead_jet_c44_energy_ = -999.;
        sublead_jet_c45_energy_ = -999.;
        sublead_jet_c46_energy_ = -999.;
        sublead_jet_c47_energy_ = -999.;
        sublead_jet_c48_energy_ = -999.;
        sublead_jet_c49_energy_ = -999.;
        sublead_jet_c50_energy_ = -999.;
        sublead_jet_c51_energy_ = -999.;
        sublead_jet_c52_energy_ = -999.;
        sublead_jet_c53_energy_ = -999.;
        sublead_jet_c54_energy_ = -999.;
        sublead_jet_c55_energy_ = -999.;
        sublead_jet_c56_energy_ = -999.;
        sublead_jet_c57_energy_ = -999.;
        sublead_jet_c58_energy_ = -999.;
        sublead_jet_c59_energy_ = -999.;
        sublead_jet_c60_energy_ = -999.;

        subsublead_jet_c1_eta_  = -999.;
        subsublead_jet_c2_eta_  = -999.;
        subsublead_jet_c3_eta_  = -999.;
        subsublead_jet_c4_eta_  = -999.;
        subsublead_jet_c5_eta_  = -999.;
        subsublead_jet_c6_eta_  = -999.;
        subsublead_jet_c7_eta_  = -999.;
        subsublead_jet_c8_eta_  = -999.;
        subsublead_jet_c9_eta_  = -999.;
        subsublead_jet_c10_eta_  = -999.;
        subsublead_jet_c11_eta_  = -999.;
        subsublead_jet_c12_eta_  = -999.;
        subsublead_jet_c13_eta_  = -999.;
        subsublead_jet_c14_eta_  = -999.;
        subsublead_jet_c15_eta_  = -999.;
        subsublead_jet_c16_eta_  = -999.;
        subsublead_jet_c17_eta_  = -999.;
        subsublead_jet_c18_eta_  = -999.;
        subsublead_jet_c19_eta_  = -999.;
        subsublead_jet_c20_eta_  = -999.;
        subsublead_jet_c21_eta_  = -999.;
        subsublead_jet_c22_eta_  = -999.;
        subsublead_jet_c23_eta_  = -999.;
        subsublead_jet_c24_eta_  = -999.;
        subsublead_jet_c25_eta_  = -999.;
        subsublead_jet_c26_eta_  = -999.;
        subsublead_jet_c27_eta_  = -999.;
        subsublead_jet_c28_eta_  = -999.;
        subsublead_jet_c29_eta_  = -999.;
        subsublead_jet_c30_eta_  = -999.;
        subsublead_jet_c31_eta_  = -999.;
        subsublead_jet_c32_eta_  = -999.;
        subsublead_jet_c33_eta_  = -999.;
        subsublead_jet_c34_eta_  = -999.;
        subsublead_jet_c35_eta_  = -999.;
        subsublead_jet_c36_eta_  = -999.;
        subsublead_jet_c37_eta_  = -999.;
        subsublead_jet_c38_eta_  = -999.;
        subsublead_jet_c39_eta_  = -999.;
        subsublead_jet_c40_eta_  = -999.;
        subsublead_jet_c41_eta_  = -999.;
        subsublead_jet_c42_eta_  = -999.;
        subsublead_jet_c43_eta_  = -999.;
        subsublead_jet_c44_eta_  = -999.;
        subsublead_jet_c45_eta_  = -999.;
        subsublead_jet_c46_eta_  = -999.;
        subsublead_jet_c47_eta_  = -999.;
        subsublead_jet_c48_eta_  = -999.;
        subsublead_jet_c49_eta_  = -999.;
        subsublead_jet_c50_eta_  = -999.;
        subsublead_jet_c51_eta_  = -999.;
        subsublead_jet_c52_eta_  = -999.;
        subsublead_jet_c53_eta_  = -999.;
        subsublead_jet_c54_eta_  = -999.;
        subsublead_jet_c55_eta_  = -999.;
        subsublead_jet_c56_eta_  = -999.;
        subsublead_jet_c57_eta_  = -999.;
        subsublead_jet_c58_eta_  = -999.;
        subsublead_jet_c59_eta_  = -999.;
        subsublead_jet_c60_eta_  = -999.;

        subsublead_jet_c1_phi_  = -999.;
        subsublead_jet_c2_phi_  = -999.;
        subsublead_jet_c3_phi_  = -999.;
        subsublead_jet_c4_phi_  = -999.;
        subsublead_jet_c5_phi_  = -999.;
        subsublead_jet_c6_phi_  = -999.;
        subsublead_jet_c7_phi_  = -999.;
        subsublead_jet_c8_phi_  = -999.;
        subsublead_jet_c9_phi_  = -999.;
        subsublead_jet_c10_phi_  = -999.;
        subsublead_jet_c11_phi_  = -999.;
        subsublead_jet_c12_phi_  = -999.;
        subsublead_jet_c13_phi_  = -999.;
        subsublead_jet_c14_phi_  = -999.;
        subsublead_jet_c15_phi_  = -999.;
        subsublead_jet_c16_phi_  = -999.;
        subsublead_jet_c17_phi_  = -999.;
        subsublead_jet_c18_phi_  = -999.;
        subsublead_jet_c19_phi_  = -999.;
        subsublead_jet_c20_phi_  = -999.;
        subsublead_jet_c21_phi_  = -999.;
        subsublead_jet_c22_phi_  = -999.;
        subsublead_jet_c23_phi_  = -999.;
        subsublead_jet_c24_phi_  = -999.;
        subsublead_jet_c25_phi_  = -999.;
        subsublead_jet_c26_phi_  = -999.;
        subsublead_jet_c27_phi_  = -999.;
        subsublead_jet_c28_phi_  = -999.;
        subsublead_jet_c29_phi_  = -999.;
        subsublead_jet_c30_phi_  = -999.;
        subsublead_jet_c31_phi_  = -999.;
        subsublead_jet_c32_phi_  = -999.;
        subsublead_jet_c33_phi_  = -999.;
        subsublead_jet_c34_phi_  = -999.;
        subsublead_jet_c35_phi_  = -999.;
        subsublead_jet_c36_phi_  = -999.;
        subsublead_jet_c37_phi_  = -999.;
        subsublead_jet_c38_phi_  = -999.;
        subsublead_jet_c39_phi_  = -999.;
        subsublead_jet_c40_phi_  = -999.;
        subsublead_jet_c41_phi_  = -999.;
        subsublead_jet_c42_phi_  = -999.;
        subsublead_jet_c43_phi_  = -999.;
        subsublead_jet_c44_phi_  = -999.;
        subsublead_jet_c45_phi_  = -999.;
        subsublead_jet_c46_phi_  = -999.;
        subsublead_jet_c47_phi_  = -999.;
        subsublead_jet_c48_phi_  = -999.;
        subsublead_jet_c49_phi_  = -999.;
        subsublead_jet_c50_phi_  = -999.;
        subsublead_jet_c51_phi_  = -999.;
        subsublead_jet_c52_phi_  = -999.;
        subsublead_jet_c53_phi_  = -999.;
        subsublead_jet_c54_phi_  = -999.;
        subsublead_jet_c55_phi_  = -999.;
        subsublead_jet_c56_phi_  = -999.;
        subsublead_jet_c57_phi_  = -999.;
        subsublead_jet_c58_phi_  = -999.;
        subsublead_jet_c59_phi_  = -999.;
        subsublead_jet_c60_phi_  = -999.;

        subsublead_jet_c1_charge_ = -999.;
        subsublead_jet_c2_charge_ = -999.;
        subsublead_jet_c3_charge_ = -999.;
        subsublead_jet_c4_charge_ = -999.;
        subsublead_jet_c5_charge_ = -999.;
        subsublead_jet_c6_charge_ = -999.;
        subsublead_jet_c7_charge_ = -999.;
        subsublead_jet_c8_charge_ = -999.;
        subsublead_jet_c9_charge_ = -999.;
        subsublead_jet_c10_charge_ = -999.;
        subsublead_jet_c11_charge_ = -999.;
        subsublead_jet_c12_charge_ = -999.;
        subsublead_jet_c13_charge_ = -999.;
        subsublead_jet_c14_charge_ = -999.;
        subsublead_jet_c15_charge_ = -999.;
        subsublead_jet_c16_charge_ = -999.;
        subsublead_jet_c17_charge_ = -999.;
        subsublead_jet_c18_charge_ = -999.;
        subsublead_jet_c19_charge_ = -999.;
        subsublead_jet_c20_charge_ = -999.;
        subsublead_jet_c21_charge_ = -999.;
        subsublead_jet_c22_charge_ = -999.;
        subsublead_jet_c23_charge_ = -999.;
        subsublead_jet_c24_charge_ = -999.;
        subsublead_jet_c25_charge_ = -999.;
        subsublead_jet_c26_charge_ = -999.;
        subsublead_jet_c27_charge_ = -999.;
        subsublead_jet_c28_charge_ = -999.;
        subsublead_jet_c29_charge_ = -999.;
        subsublead_jet_c30_charge_ = -999.;
        subsublead_jet_c31_charge_ = -999.;
        subsublead_jet_c32_charge_ = -999.;
        subsublead_jet_c33_charge_ = -999.;
        subsublead_jet_c34_charge_ = -999.;
        subsublead_jet_c35_charge_ = -999.;
        subsublead_jet_c36_charge_ = -999.;
        subsublead_jet_c37_charge_ = -999.;
        subsublead_jet_c38_charge_ = -999.;
        subsublead_jet_c39_charge_ = -999.;
        subsublead_jet_c40_charge_ = -999.;
        subsublead_jet_c41_charge_ = -999.;
        subsublead_jet_c42_charge_ = -999.;
        subsublead_jet_c43_charge_ = -999.;
        subsublead_jet_c44_charge_ = -999.;
        subsublead_jet_c45_charge_ = -999.;
        subsublead_jet_c46_charge_ = -999.;
        subsublead_jet_c47_charge_ = -999.;
        subsublead_jet_c48_charge_ = -999.;
        subsublead_jet_c49_charge_ = -999.;
        subsublead_jet_c50_charge_ = -999.;
        subsublead_jet_c51_charge_ = -999.;
        subsublead_jet_c52_charge_ = -999.;
        subsublead_jet_c53_charge_ = -999.;
        subsublead_jet_c54_charge_ = -999.;
        subsublead_jet_c55_charge_ = -999.;
        subsublead_jet_c56_charge_ = -999.;
        subsublead_jet_c57_charge_ = -999.;
        subsublead_jet_c58_charge_ = -999.;
        subsublead_jet_c59_charge_ = -999.;
        subsublead_jet_c60_charge_ = -999.;

        subsublead_jet_c1_pt_ = -999.;
        subsublead_jet_c2_pt_ = -999.;
        subsublead_jet_c3_pt_ = -999.;
        subsublead_jet_c4_pt_ = -999.;
        subsublead_jet_c5_pt_ = -999.;
        subsublead_jet_c6_pt_ = -999.;
        subsublead_jet_c7_pt_ = -999.;
        subsublead_jet_c8_pt_ = -999.;
        subsublead_jet_c9_pt_ = -999.;
        subsublead_jet_c10_pt_ = -999.;
        subsublead_jet_c11_pt_ = -999.;
        subsublead_jet_c12_pt_ = -999.;
        subsublead_jet_c13_pt_ = -999.;
        subsublead_jet_c14_pt_ = -999.;
        subsublead_jet_c15_pt_ = -999.;
        subsublead_jet_c16_pt_ = -999.;
        subsublead_jet_c17_pt_ = -999.;
        subsublead_jet_c18_pt_ = -999.;
        subsublead_jet_c19_pt_ = -999.;
        subsublead_jet_c20_pt_ = -999.;
        subsublead_jet_c21_pt_ = -999.;
        subsublead_jet_c22_pt_ = -999.;
        subsublead_jet_c23_pt_ = -999.;
        subsublead_jet_c24_pt_ = -999.;
        subsublead_jet_c25_pt_ = -999.;
        subsublead_jet_c26_pt_ = -999.;
        subsublead_jet_c27_pt_ = -999.;
        subsublead_jet_c28_pt_ = -999.;
        subsublead_jet_c29_pt_ = -999.;
        subsublead_jet_c30_pt_ = -999.;
        subsublead_jet_c31_pt_ = -999.;
        subsublead_jet_c32_pt_ = -999.;
        subsublead_jet_c33_pt_ = -999.;
        subsublead_jet_c34_pt_ = -999.;
        subsublead_jet_c35_pt_ = -999.;
        subsublead_jet_c36_pt_ = -999.;
        subsublead_jet_c37_pt_ = -999.;
        subsublead_jet_c38_pt_ = -999.;
        subsublead_jet_c39_pt_ = -999.;
        subsublead_jet_c40_pt_ = -999.;
        subsublead_jet_c41_pt_ = -999.;
        subsublead_jet_c42_pt_ = -999.;
        subsublead_jet_c43_pt_ = -999.;
        subsublead_jet_c44_pt_ = -999.;
        subsublead_jet_c45_pt_ = -999.;
        subsublead_jet_c46_pt_ = -999.;
        subsublead_jet_c47_pt_ = -999.;
        subsublead_jet_c48_pt_ = -999.;
        subsublead_jet_c49_pt_ = -999.;
        subsublead_jet_c50_pt_ = -999.;
        subsublead_jet_c51_pt_ = -999.;
        subsublead_jet_c52_pt_ = -999.;
        subsublead_jet_c53_pt_ = -999.;
        subsublead_jet_c54_pt_ = -999.;
        subsublead_jet_c55_pt_ = -999.;
        subsublead_jet_c56_pt_ = -999.;
        subsublead_jet_c57_pt_ = -999.;
        subsublead_jet_c58_pt_ = -999.;
        subsublead_jet_c59_pt_ = -999.;
        subsublead_jet_c60_pt_ = -999.;

        subsublead_jet_c1_energy_ = -999.;
        subsublead_jet_c2_energy_ = -999.;
        subsublead_jet_c3_energy_ = -999.;
        subsublead_jet_c4_energy_ = -999.;
        subsublead_jet_c5_energy_ = -999.;
        subsublead_jet_c6_energy_ = -999.;
        subsublead_jet_c7_energy_ = -999.;
        subsublead_jet_c8_energy_ = -999.;
        subsublead_jet_c9_energy_ = -999.;
        subsublead_jet_c10_energy_ = -999.;
        subsublead_jet_c11_energy_ = -999.;
        subsublead_jet_c12_energy_ = -999.;
        subsublead_jet_c13_energy_ = -999.;
        subsublead_jet_c14_energy_ = -999.;
        subsublead_jet_c15_energy_ = -999.;
        subsublead_jet_c16_energy_ = -999.;
        subsublead_jet_c17_energy_ = -999.;
        subsublead_jet_c18_energy_ = -999.;
        subsublead_jet_c19_energy_ = -999.;
        subsublead_jet_c20_energy_ = -999.;
        subsublead_jet_c21_energy_ = -999.;
        subsublead_jet_c22_energy_ = -999.;
        subsublead_jet_c23_energy_ = -999.;
        subsublead_jet_c24_energy_ = -999.;
        subsublead_jet_c25_energy_ = -999.;
        subsublead_jet_c26_energy_ = -999.;
        subsublead_jet_c27_energy_ = -999.;
        subsublead_jet_c28_energy_ = -999.;
        subsublead_jet_c29_energy_ = -999.;
        subsublead_jet_c30_energy_ = -999.;
        subsublead_jet_c31_energy_ = -999.;
        subsublead_jet_c32_energy_ = -999.;
        subsublead_jet_c33_energy_ = -999.;
        subsublead_jet_c34_energy_ = -999.;
        subsublead_jet_c35_energy_ = -999.;
        subsublead_jet_c36_energy_ = -999.;
        subsublead_jet_c37_energy_ = -999.;
        subsublead_jet_c38_energy_ = -999.;
        subsublead_jet_c39_energy_ = -999.;
        subsublead_jet_c40_energy_ = -999.;
        subsublead_jet_c41_energy_ = -999.;
        subsublead_jet_c42_energy_ = -999.;
        subsublead_jet_c43_energy_ = -999.;
        subsublead_jet_c44_energy_ = -999.;
        subsublead_jet_c45_energy_ = -999.;
        subsublead_jet_c46_energy_ = -999.;
        subsublead_jet_c47_energy_ = -999.;
        subsublead_jet_c48_energy_ = -999.;
        subsublead_jet_c49_energy_ = -999.;
        subsublead_jet_c50_energy_ = -999.;
        subsublead_jet_c51_energy_ = -999.;
        subsublead_jet_c52_energy_ = -999.;
        subsublead_jet_c53_energy_ = -999.;
        subsublead_jet_c54_energy_ = -999.;
        subsublead_jet_c55_energy_ = -999.;
        subsublead_jet_c56_energy_ = -999.;
        subsublead_jet_c57_energy_ = -999.;
        subsublead_jet_c58_energy_ = -999.;
        subsublead_jet_c59_energy_ = -999.;
        subsublead_jet_c60_energy_ = -999.;

        dipho_PToM_       = -999.;
        leadPho_PToM_     = -999.;
        sublPho_PToM_     = -999.;
        dijet_minDRJetPho_= -999.;
        dijet_centrality_gg_ = -999.;
        dijet_centrality_j3_ = -999.;
        dijet_centrality_g_  = -999.;
        dijet_dipho_pt_   = -999.;
        dijet_leady_      = -999.;
        dijet_subleady_   = -999.;
        
        if (_MVAMethod == "BDTG"){
            //std::cout << "booking Dijet VBF MVA method" << std::endl;
            VbfMva_.reset( new TMVA::Reader( "!Color:Silent" ) );
            // Run 1 legacy variables
            /*
            VbfMva_->AddVariable( "dijet_LeadJPt"     , &dijet_LeadJPt_    );
            VbfMva_->AddVariable( "dijet_SubJPt"      , &dijet_SubJPt_     );
            VbfMva_->AddVariable( "dijet_abs_dEta"    , &dijet_abs_dEta_   );
            VbfMva_->AddVariable( "dijet_Mjj"         , &dijet_Mjj_        );
            VbfMva_->AddVariable( "dijet_Zep"         , &dijet_Zep_        );
            VbfMva_->AddVariable( "dijet_dPhi_trunc"  , &dijet_dphi_trunc_ );
            VbfMva_->AddVariable( "leadPho_PToM"      , &leadPho_PToM_);
            VbfMva_->AddVariable( "sublPho_PToM"      , &sublPho_PToM_);
            */
            
            // Moriond17 variables
            VbfMva_->AddVariable( "dijet_LeadJPt"          , &dijet_LeadJPt_       );
            VbfMva_->AddVariable( "dijet_SubJPt"           , &dijet_SubJPt_        );
            VbfMva_->AddVariable( "dijet_abs_dEta"         , &dijet_abs_dEta_      );
            VbfMva_->AddVariable( "dijet_Mjj"              , &dijet_Mjj_           );
            VbfMva_->AddVariable( "dijet_centrality_gg"    , &dijet_centrality_gg_ );
            VbfMva_->AddVariable( "dijet_dipho_dphi_trunc" , &dijet_dphi_trunc_    );
            VbfMva_->AddVariable( "dijet_dphi"             , &dijet_dphi_          );
            VbfMva_->AddVariable( "dijet_minDRJetPho"      , &dijet_minDRJetPho_   );
            VbfMva_->AddVariable( "leadPho_PToM"           , &leadPho_PToM_        );
            VbfMva_->AddVariable( "sublPho_PToM"           , &sublPho_PToM_        );
            
            VbfMva_->BookMVA( _MVAMethod.c_str() , vbfMVAweightfile_.fullPath() );
        }
        else if (_MVAMethod == "Multi"){
            //std::cout << "booking multiclass VBF MVA method" << std::endl;
            VbfMva_.reset( new TMVA::Reader( "!Color:Silent" ) );
            VbfMva_->AddVariable( "dipho_lead_ptoM"        , &leadPho_PToM_        );  
            VbfMva_->AddVariable( "dipho_sublead_ptoM"     , &sublPho_PToM_        );  
            VbfMva_->AddVariable( "dijet_LeadJPt"          , &dijet_LeadJPt_       );  
            VbfMva_->AddVariable( "dijet_SubJPt"           , &dijet_SubJPt_        );  
            VbfMva_->AddVariable( "dijet_abs_dEta"         , &dijet_abs_dEta_      );  
            VbfMva_->AddVariable( "dijet_Mjj"              , &dijet_Mjj_           );  
            VbfMva_->AddVariable( "dijet_centrality"       , &dijet_centrality_gg_ );
            VbfMva_->AddVariable( "dijet_dphi"             , &dijet_dphi_          );  
            VbfMva_->AddVariable( "dijet_minDRJetPho"      , &dijet_minDRJetPho_   );  
            VbfMva_->AddVariable( "dijet_dipho_dphi_trunc" , &dijet_dphi_trunc_    );

            VbfMva_->BookMVA( _MVAMethod.c_str() , vbfMVAweightfile_.fullPath() );
        }
        for (unsigned i = 0 ; i < inputTagJets_.size() ; i++) {
            auto token = consumes<View<flashgg::Jet> >(inputTagJets_[i]);
            tokenJets_.push_back(token);
        }
        produces<vector<VBFMVAResult> >();
        
    }
    
    void VBFMVAProducer::produce( Event &evt, const EventSetup & )
    {
        Handle<View<flashgg::DiPhotonCandidate> > diPhotons;
        evt.getByToken( diPhotonToken_, diPhotons );
        
        JetCollectionVector Jets( inputTagJets_.size() );
        for( size_t j = 0; j < inputTagJets_.size(); ++j ) {
            evt.getByToken( tokenJets_[j], Jets[j] );
        }
        
        std::unique_ptr<vector<VBFMVAResult> > vbf_results( new vector<VBFMVAResult> );
        for( unsigned int candIndex = 0; candIndex < diPhotons->size() ; candIndex++ ) {
            
            flashgg::VBFMVAResult mvares;
            
            dijet_leadEta_    = -999.;
            dijet_subleadEta_ = -999.;
            dijet_abs_dEta_   = -999.;
            dijet_LeadJPt_    = -999.;
            dijet_pt_    = -999.;
            dijet_SubJPt_     = -999.;
            dijet_Zep_        = -999.;
            dijet_dphi_trunc_ = -999.;
            dijet_dipho_dphi_ = -999.;
            dijet_dphi_       = -999.;
            dijet_Mjj_        = -999.;
            dijet_dy_         = -999.;
            dijet_minDRJetPho_= -999.;
            dijet_dipho_pt_   = -999.;
            dijet_leady_      = -999.;
            dijet_subleady_   = -999.;
            dijet_centrality_gg_ = -999.;
            dijet_centrality_j3_ = -999.;
            dijet_centrality_g_  = -999.;
            cosThetaStar_     = -999.; 
            constit_energy_   = -999;

            pt_J1_ = -999.;
            eta_J1_ = -999.;
            phi_J1_ = -999.;
            charge_J1_ = -999.;
            energy_J1_ = -999.;
            flav_J1_ = -999.;

            pt_J2_ = -999.;
            eta_J2_ = -999.;
            phi_J2_ = -999.;
            charge_J2_ = -999.;
            energy_J2_ = -999.;
            flav_J2_ = -999.;

            pt_J3_ = -999.;
            eta_J3_ = -999.;
            phi_J3_ = -999.;
            charge_J3_ = -999.;
            energy_J3_ = -999.;
            flav_J3_ = -999.;

            n_constits_       = -999.;
            //test_vec_.push_back(-999.);
            lead_jet_pt_      = -999;
            test_lead_jet_eta_      = -999;
            
            lead_jet_c1_eta_  = -999.;
            lead_jet_c2_eta_  = -999.;
            lead_jet_c3_eta_  = -999.;
            lead_jet_c4_eta_  = -999.;
            lead_jet_c5_eta_  = -999.;
            lead_jet_c6_eta_  = -999.;
            lead_jet_c7_eta_  = -999.;
            lead_jet_c8_eta_  = -999.;
            lead_jet_c9_eta_  = -999.;
            lead_jet_c10_eta_  = -999.;
            lead_jet_c11_eta_  = -999.;
            lead_jet_c12_eta_  = -999.;
            lead_jet_c13_eta_  = -999.;
            lead_jet_c14_eta_  = -999.;
            lead_jet_c15_eta_  = -999.;
            lead_jet_c16_eta_  = -999.;
            lead_jet_c17_eta_  = -999.;
            lead_jet_c18_eta_  = -999.;
            lead_jet_c19_eta_  = -999.;
            lead_jet_c20_eta_  = -999.;
            lead_jet_c21_eta_  = -999.;
            lead_jet_c22_eta_  = -999.;
            lead_jet_c23_eta_  = -999.;
            lead_jet_c24_eta_  = -999.;
            lead_jet_c25_eta_  = -999.;
            lead_jet_c26_eta_  = -999.;
            lead_jet_c27_eta_  = -999.;
            lead_jet_c28_eta_  = -999.;
            lead_jet_c29_eta_  = -999.;
            lead_jet_c30_eta_  = -999.;
            lead_jet_c31_eta_  = -999.;
            lead_jet_c32_eta_  = -999.;
            lead_jet_c33_eta_  = -999.;
            lead_jet_c34_eta_  = -999.;
            lead_jet_c35_eta_  = -999.;
            lead_jet_c36_eta_  = -999.;
            lead_jet_c37_eta_  = -999.;
            lead_jet_c38_eta_  = -999.;
            lead_jet_c39_eta_  = -999.;
            lead_jet_c40_eta_  = -999.;
            lead_jet_c41_eta_  = -999.;
            lead_jet_c42_eta_  = -999.;
            lead_jet_c43_eta_  = -999.;
            lead_jet_c44_eta_  = -999.;
            lead_jet_c45_eta_  = -999.;
            lead_jet_c46_eta_  = -999.;
            lead_jet_c47_eta_  = -999.;
            lead_jet_c48_eta_  = -999.;
            lead_jet_c49_eta_  = -999.;
            lead_jet_c50_eta_  = -999.;
            lead_jet_c51_eta_  = -999.;
            lead_jet_c52_eta_  = -999.;
            lead_jet_c53_eta_  = -999.;
            lead_jet_c54_eta_  = -999.;
            lead_jet_c55_eta_  = -999.;
            lead_jet_c56_eta_  = -999.;
            lead_jet_c57_eta_  = -999.;
            lead_jet_c58_eta_  = -999.;
            lead_jet_c59_eta_  = -999.;
            lead_jet_c60_eta_  = -999.;

            lead_jet_c1_phi_  = -999.;
            lead_jet_c2_phi_  = -999.;
            lead_jet_c3_phi_  = -999.;
            lead_jet_c4_phi_  = -999.;
            lead_jet_c5_phi_  = -999.;
            lead_jet_c6_phi_  = -999.;
            lead_jet_c7_phi_  = -999.;
            lead_jet_c8_phi_  = -999.;
            lead_jet_c9_phi_  = -999.;
            lead_jet_c10_phi_  = -999.;
            lead_jet_c11_phi_  = -999.;
            lead_jet_c12_phi_  = -999.;
            lead_jet_c13_phi_  = -999.;
            lead_jet_c14_phi_  = -999.;
            lead_jet_c15_phi_  = -999.;
            lead_jet_c16_phi_  = -999.;
            lead_jet_c17_phi_  = -999.;
            lead_jet_c18_phi_  = -999.;
            lead_jet_c19_phi_  = -999.;
            lead_jet_c20_phi_  = -999.;
            lead_jet_c21_phi_  = -999.;
            lead_jet_c22_phi_  = -999.;
            lead_jet_c23_phi_  = -999.;
            lead_jet_c24_phi_  = -999.;
            lead_jet_c25_phi_  = -999.;
            lead_jet_c26_phi_  = -999.;
            lead_jet_c27_phi_  = -999.;
            lead_jet_c28_phi_  = -999.;
            lead_jet_c29_phi_  = -999.;
            lead_jet_c30_phi_  = -999.;
            lead_jet_c31_phi_  = -999.;
            lead_jet_c32_phi_  = -999.;
            lead_jet_c33_phi_  = -999.;
            lead_jet_c34_phi_  = -999.;
            lead_jet_c35_phi_  = -999.;
            lead_jet_c36_phi_  = -999.;
            lead_jet_c37_phi_  = -999.;
            lead_jet_c38_phi_  = -999.;
            lead_jet_c39_phi_  = -999.;
            lead_jet_c40_phi_  = -999.;
            lead_jet_c41_phi_  = -999.;
            lead_jet_c42_phi_  = -999.;
            lead_jet_c43_phi_  = -999.;
            lead_jet_c44_phi_  = -999.;
            lead_jet_c45_phi_  = -999.;
            lead_jet_c46_phi_  = -999.;
            lead_jet_c47_phi_  = -999.;
            lead_jet_c48_phi_  = -999.;
            lead_jet_c49_phi_  = -999.;
            lead_jet_c50_phi_  = -999.;
            lead_jet_c51_phi_  = -999.;
            lead_jet_c52_phi_  = -999.;
            lead_jet_c53_phi_  = -999.;
            lead_jet_c54_phi_  = -999.;
            lead_jet_c55_phi_  = -999.;
            lead_jet_c56_phi_  = -999.;
            lead_jet_c57_phi_  = -999.;
            lead_jet_c58_phi_  = -999.;
            lead_jet_c59_phi_  = -999.;
            lead_jet_c60_phi_  = -999.;

            lead_jet_c1_charge_ = -999.;
            lead_jet_c2_charge_ = -999.;
            lead_jet_c3_charge_ = -999.;
            lead_jet_c4_charge_ = -999.;
            lead_jet_c5_charge_ = -999.;
            lead_jet_c6_charge_ = -999.;
            lead_jet_c7_charge_ = -999.;
            lead_jet_c8_charge_ = -999.;
            lead_jet_c9_charge_ = -999.;
            lead_jet_c10_charge_ = -999.;
            lead_jet_c11_charge_ = -999.;
            lead_jet_c12_charge_ = -999.;
            lead_jet_c13_charge_ = -999.;
            lead_jet_c14_charge_ = -999.;
            lead_jet_c15_charge_ = -999.;
            lead_jet_c16_charge_ = -999.;
            lead_jet_c17_charge_ = -999.;
            lead_jet_c18_charge_ = -999.;
            lead_jet_c19_charge_ = -999.;
            lead_jet_c20_charge_ = -999.;
            lead_jet_c21_charge_ = -999.;
            lead_jet_c22_charge_ = -999.;
            lead_jet_c23_charge_ = -999.;
            lead_jet_c24_charge_ = -999.;
            lead_jet_c25_charge_ = -999.;
            lead_jet_c26_charge_ = -999.;
            lead_jet_c27_charge_ = -999.;
            lead_jet_c28_charge_ = -999.;
            lead_jet_c29_charge_ = -999.;
            lead_jet_c30_charge_ = -999.;
            lead_jet_c31_charge_ = -999.;
            lead_jet_c32_charge_ = -999.;
            lead_jet_c33_charge_ = -999.;
            lead_jet_c34_charge_ = -999.;
            lead_jet_c35_charge_ = -999.;
            lead_jet_c36_charge_ = -999.;
            lead_jet_c37_charge_ = -999.;
            lead_jet_c38_charge_ = -999.;
            lead_jet_c39_charge_ = -999.;
            lead_jet_c40_charge_ = -999.;
            lead_jet_c41_charge_ = -999.;
            lead_jet_c42_charge_ = -999.;
            lead_jet_c43_charge_ = -999.;
            lead_jet_c44_charge_ = -999.;
            lead_jet_c45_charge_ = -999.;
            lead_jet_c46_charge_ = -999.;
            lead_jet_c47_charge_ = -999.;
            lead_jet_c48_charge_ = -999.;
            lead_jet_c49_charge_ = -999.;
            lead_jet_c50_charge_ = -999.;
            lead_jet_c51_charge_ = -999.;
            lead_jet_c52_charge_ = -999.;
            lead_jet_c53_charge_ = -999.;
            lead_jet_c54_charge_ = -999.;
            lead_jet_c55_charge_ = -999.;
            lead_jet_c56_charge_ = -999.;
            lead_jet_c57_charge_ = -999.;
            lead_jet_c58_charge_ = -999.;
            lead_jet_c59_charge_ = -999.;
            lead_jet_c60_charge_ = -999.;

            lead_jet_c1_pt_ = -999.;
            lead_jet_c2_pt_ = -999.;
            lead_jet_c3_pt_ = -999.;
            lead_jet_c4_pt_ = -999.;
            lead_jet_c5_pt_ = -999.;
            lead_jet_c6_pt_ = -999.;
            lead_jet_c7_pt_ = -999.;
            lead_jet_c8_pt_ = -999.;
            lead_jet_c9_pt_ = -999.;
            lead_jet_c10_pt_ = -999.;
            lead_jet_c11_pt_ = -999.;
            lead_jet_c12_pt_ = -999.;
            lead_jet_c13_pt_ = -999.;
            lead_jet_c14_pt_ = -999.;
            lead_jet_c15_pt_ = -999.;
            lead_jet_c16_pt_ = -999.;
            lead_jet_c17_pt_ = -999.;
            lead_jet_c18_pt_ = -999.;
            lead_jet_c19_pt_ = -999.;
            lead_jet_c20_pt_ = -999.;
            lead_jet_c21_pt_ = -999.;
            lead_jet_c22_pt_ = -999.;
            lead_jet_c23_pt_ = -999.;
            lead_jet_c24_pt_ = -999.;
            lead_jet_c25_pt_ = -999.;
            lead_jet_c26_pt_ = -999.;
            lead_jet_c27_pt_ = -999.;
            lead_jet_c28_pt_ = -999.;
            lead_jet_c29_pt_ = -999.;
            lead_jet_c30_pt_ = -999.;
            lead_jet_c31_pt_ = -999.;
            lead_jet_c32_pt_ = -999.;
            lead_jet_c33_pt_ = -999.;
            lead_jet_c34_pt_ = -999.;
            lead_jet_c35_pt_ = -999.;
            lead_jet_c36_pt_ = -999.;
            lead_jet_c37_pt_ = -999.;
            lead_jet_c38_pt_ = -999.;
            lead_jet_c39_pt_ = -999.;
            lead_jet_c40_pt_ = -999.;
            lead_jet_c41_pt_ = -999.;
            lead_jet_c42_pt_ = -999.;
            lead_jet_c43_pt_ = -999.;
            lead_jet_c44_pt_ = -999.;
            lead_jet_c45_pt_ = -999.;
            lead_jet_c46_pt_ = -999.;
            lead_jet_c47_pt_ = -999.;
            lead_jet_c48_pt_ = -999.;
            lead_jet_c49_pt_ = -999.;
            lead_jet_c50_pt_ = -999.;
            lead_jet_c51_pt_ = -999.;
            lead_jet_c52_pt_ = -999.;
            lead_jet_c53_pt_ = -999.;
            lead_jet_c54_pt_ = -999.;
            lead_jet_c55_pt_ = -999.;
            lead_jet_c56_pt_ = -999.;
            lead_jet_c57_pt_ = -999.;
            lead_jet_c58_pt_ = -999.;
            lead_jet_c59_pt_ = -999.;
            lead_jet_c60_pt_ = -999.;

            lead_jet_c1_energy_ = -999.;
            lead_jet_c2_energy_ = -999.;
            lead_jet_c3_energy_ = -999.;
            lead_jet_c4_energy_ = -999.;
            lead_jet_c5_energy_ = -999.;
            lead_jet_c6_energy_ = -999.;
            lead_jet_c7_energy_ = -999.;
            lead_jet_c8_energy_ = -999.;
            lead_jet_c9_energy_ = -999.;
            lead_jet_c10_energy_ = -999.;
            lead_jet_c11_energy_ = -999.;
            lead_jet_c12_energy_ = -999.;
            lead_jet_c13_energy_ = -999.;
            lead_jet_c14_energy_ = -999.;
            lead_jet_c15_energy_ = -999.;
            lead_jet_c16_energy_ = -999.;
            lead_jet_c17_energy_ = -999.;
            lead_jet_c18_energy_ = -999.;
            lead_jet_c19_energy_ = -999.;
            lead_jet_c20_energy_ = -999.;
            lead_jet_c21_energy_ = -999.;
            lead_jet_c22_energy_ = -999.;
            lead_jet_c23_energy_ = -999.;
            lead_jet_c24_energy_ = -999.;
            lead_jet_c25_energy_ = -999.;
            lead_jet_c26_energy_ = -999.;
            lead_jet_c27_energy_ = -999.;
            lead_jet_c28_energy_ = -999.;
            lead_jet_c29_energy_ = -999.;
            lead_jet_c30_energy_ = -999.;
            lead_jet_c31_energy_ = -999.;
            lead_jet_c32_energy_ = -999.;
            lead_jet_c33_energy_ = -999.;
            lead_jet_c34_energy_ = -999.;
            lead_jet_c35_energy_ = -999.;
            lead_jet_c36_energy_ = -999.;
            lead_jet_c37_energy_ = -999.;
            lead_jet_c38_energy_ = -999.;
            lead_jet_c39_energy_ = -999.;
            lead_jet_c40_energy_ = -999.;
            lead_jet_c41_energy_ = -999.;
            lead_jet_c42_energy_ = -999.;
            lead_jet_c43_energy_ = -999.;
            lead_jet_c44_energy_ = -999.;
            lead_jet_c45_energy_ = -999.;
            lead_jet_c46_energy_ = -999.;
            lead_jet_c47_energy_ = -999.;
            lead_jet_c48_energy_ = -999.;
            lead_jet_c49_energy_ = -999.;
            lead_jet_c50_energy_ = -999.;
            lead_jet_c51_energy_ = -999.;
            lead_jet_c52_energy_ = -999.;
            lead_jet_c53_energy_ = -999.;
            lead_jet_c54_energy_ = -999.;
            lead_jet_c55_energy_ = -999.;
            lead_jet_c56_energy_ = -999.;
            lead_jet_c57_energy_ = -999.;
            lead_jet_c58_energy_ = -999.;
            lead_jet_c59_energy_ = -999.;
            lead_jet_c60_energy_ = -999.;

            sublead_jet_c1_eta_  = -999.;
            sublead_jet_c2_eta_  = -999.;
            sublead_jet_c3_eta_  = -999.;
            sublead_jet_c4_eta_  = -999.;
            sublead_jet_c5_eta_  = -999.;
            sublead_jet_c6_eta_  = -999.;
            sublead_jet_c7_eta_  = -999.;
            sublead_jet_c8_eta_  = -999.;
            sublead_jet_c9_eta_  = -999.;
            sublead_jet_c10_eta_  = -999.;
            sublead_jet_c11_eta_  = -999.;
            sublead_jet_c12_eta_  = -999.;
            sublead_jet_c13_eta_  = -999.;
            sublead_jet_c14_eta_  = -999.;
            sublead_jet_c15_eta_  = -999.;
            sublead_jet_c16_eta_  = -999.;
            sublead_jet_c17_eta_  = -999.;
            sublead_jet_c18_eta_  = -999.;
            sublead_jet_c19_eta_  = -999.;
            sublead_jet_c20_eta_  = -999.;
            sublead_jet_c21_eta_  = -999.;
            sublead_jet_c22_eta_  = -999.;
            sublead_jet_c23_eta_  = -999.;
            sublead_jet_c24_eta_  = -999.;
            sublead_jet_c25_eta_  = -999.;
            sublead_jet_c26_eta_  = -999.;
            sublead_jet_c27_eta_  = -999.;
            sublead_jet_c28_eta_  = -999.;
            sublead_jet_c29_eta_  = -999.;
            sublead_jet_c30_eta_  = -999.;
            sublead_jet_c31_eta_  = -999.;
            sublead_jet_c32_eta_  = -999.;
            sublead_jet_c33_eta_  = -999.;
            sublead_jet_c34_eta_  = -999.;
            sublead_jet_c35_eta_  = -999.;
            sublead_jet_c36_eta_  = -999.;
            sublead_jet_c37_eta_  = -999.;
            sublead_jet_c38_eta_  = -999.;
            sublead_jet_c39_eta_  = -999.;
            sublead_jet_c40_eta_  = -999.;
            sublead_jet_c41_eta_  = -999.;
            sublead_jet_c42_eta_  = -999.;
            sublead_jet_c43_eta_  = -999.;
            sublead_jet_c44_eta_  = -999.;
            sublead_jet_c45_eta_  = -999.;
            sublead_jet_c46_eta_  = -999.;
            sublead_jet_c47_eta_  = -999.;
            sublead_jet_c48_eta_  = -999.;
            sublead_jet_c49_eta_  = -999.;
            sublead_jet_c50_eta_  = -999.;
            sublead_jet_c51_eta_  = -999.;
            sublead_jet_c52_eta_  = -999.;
            sublead_jet_c53_eta_  = -999.;
            sublead_jet_c54_eta_  = -999.;
            sublead_jet_c55_eta_  = -999.;
            sublead_jet_c56_eta_  = -999.;
            sublead_jet_c57_eta_  = -999.;
            sublead_jet_c58_eta_  = -999.;
            sublead_jet_c59_eta_  = -999.;
            sublead_jet_c60_eta_  = -999.;

            sublead_jet_c1_phi_  = -999.;
            sublead_jet_c2_phi_  = -999.;
            sublead_jet_c3_phi_  = -999.;
            sublead_jet_c4_phi_  = -999.;
            sublead_jet_c5_phi_  = -999.;
            sublead_jet_c6_phi_  = -999.;
            sublead_jet_c7_phi_  = -999.;
            sublead_jet_c8_phi_  = -999.;
            sublead_jet_c9_phi_  = -999.;
            sublead_jet_c10_phi_  = -999.;
            sublead_jet_c11_phi_  = -999.;
            sublead_jet_c12_phi_  = -999.;
            sublead_jet_c13_phi_  = -999.;
            sublead_jet_c14_phi_  = -999.;
            sublead_jet_c15_phi_  = -999.;
            sublead_jet_c16_phi_  = -999.;
            sublead_jet_c17_phi_  = -999.;
            sublead_jet_c18_phi_  = -999.;
            sublead_jet_c19_phi_  = -999.;
            sublead_jet_c20_phi_  = -999.;
            sublead_jet_c21_phi_  = -999.;
            sublead_jet_c22_phi_  = -999.;
            sublead_jet_c23_phi_  = -999.;
            sublead_jet_c24_phi_  = -999.;
            sublead_jet_c25_phi_  = -999.;
            sublead_jet_c26_phi_  = -999.;
            sublead_jet_c27_phi_  = -999.;
            sublead_jet_c28_phi_  = -999.;
            sublead_jet_c29_phi_  = -999.;
            sublead_jet_c30_phi_  = -999.;
            sublead_jet_c31_phi_  = -999.;
            sublead_jet_c32_phi_  = -999.;
            sublead_jet_c33_phi_  = -999.;
            sublead_jet_c34_phi_  = -999.;
            sublead_jet_c35_phi_  = -999.;
            sublead_jet_c36_phi_  = -999.;
            sublead_jet_c37_phi_  = -999.;
            sublead_jet_c38_phi_  = -999.;
            sublead_jet_c39_phi_  = -999.;
            sublead_jet_c40_phi_  = -999.;
            sublead_jet_c41_phi_  = -999.;
            sublead_jet_c42_phi_  = -999.;
            sublead_jet_c43_phi_  = -999.;
            sublead_jet_c44_phi_  = -999.;
            sublead_jet_c45_phi_  = -999.;
            sublead_jet_c46_phi_  = -999.;
            sublead_jet_c47_phi_  = -999.;
            sublead_jet_c48_phi_  = -999.;
            sublead_jet_c49_phi_  = -999.;
            sublead_jet_c50_phi_  = -999.;
            sublead_jet_c51_phi_  = -999.;
            sublead_jet_c52_phi_  = -999.;
            sublead_jet_c53_phi_  = -999.;
            sublead_jet_c54_phi_  = -999.;
            sublead_jet_c55_phi_  = -999.;
            sublead_jet_c56_phi_  = -999.;
            sublead_jet_c57_phi_  = -999.;
            sublead_jet_c58_phi_  = -999.;
            sublead_jet_c59_phi_  = -999.;
            sublead_jet_c60_phi_  = -999.;

            sublead_jet_c1_charge_ = -999.;
            sublead_jet_c2_charge_ = -999.;
            sublead_jet_c3_charge_ = -999.;
            sublead_jet_c4_charge_ = -999.;
            sublead_jet_c5_charge_ = -999.;
            sublead_jet_c6_charge_ = -999.;
            sublead_jet_c7_charge_ = -999.;
            sublead_jet_c8_charge_ = -999.;
            sublead_jet_c9_charge_ = -999.;
            sublead_jet_c10_charge_ = -999.;
            sublead_jet_c11_charge_ = -999.;
            sublead_jet_c12_charge_ = -999.;
            sublead_jet_c13_charge_ = -999.;
            sublead_jet_c14_charge_ = -999.;
            sublead_jet_c15_charge_ = -999.;
            sublead_jet_c16_charge_ = -999.;
            sublead_jet_c17_charge_ = -999.;
            sublead_jet_c18_charge_ = -999.;
            sublead_jet_c19_charge_ = -999.;
            sublead_jet_c20_charge_ = -999.;
            sublead_jet_c21_charge_ = -999.;
            sublead_jet_c22_charge_ = -999.;
            sublead_jet_c23_charge_ = -999.;
            sublead_jet_c24_charge_ = -999.;
            sublead_jet_c25_charge_ = -999.;
            sublead_jet_c26_charge_ = -999.;
            sublead_jet_c27_charge_ = -999.;
            sublead_jet_c28_charge_ = -999.;
            sublead_jet_c29_charge_ = -999.;
            sublead_jet_c30_charge_ = -999.;
            sublead_jet_c31_charge_ = -999.;
            sublead_jet_c32_charge_ = -999.;
            sublead_jet_c33_charge_ = -999.;
            sublead_jet_c34_charge_ = -999.;
            sublead_jet_c35_charge_ = -999.;
            sublead_jet_c36_charge_ = -999.;
            sublead_jet_c37_charge_ = -999.;
            sublead_jet_c38_charge_ = -999.;
            sublead_jet_c39_charge_ = -999.;
            sublead_jet_c40_charge_ = -999.;
            sublead_jet_c41_charge_ = -999.;
            sublead_jet_c42_charge_ = -999.;
            sublead_jet_c43_charge_ = -999.;
            sublead_jet_c44_charge_ = -999.;
            sublead_jet_c45_charge_ = -999.;
            sublead_jet_c46_charge_ = -999.;
            sublead_jet_c47_charge_ = -999.;
            sublead_jet_c48_charge_ = -999.;
            sublead_jet_c49_charge_ = -999.;
            sublead_jet_c50_charge_ = -999.;
            sublead_jet_c51_charge_ = -999.;
            sublead_jet_c52_charge_ = -999.;
            sublead_jet_c53_charge_ = -999.;
            sublead_jet_c54_charge_ = -999.;
            sublead_jet_c55_charge_ = -999.;
            sublead_jet_c56_charge_ = -999.;
            sublead_jet_c57_charge_ = -999.;
            sublead_jet_c58_charge_ = -999.;
            sublead_jet_c59_charge_ = -999.;
            sublead_jet_c60_charge_ = -999.;

            sublead_jet_c1_pt_ = -999.;
            sublead_jet_c2_pt_ = -999.;
            sublead_jet_c3_pt_ = -999.;
            sublead_jet_c4_pt_ = -999.;
            sublead_jet_c5_pt_ = -999.;
            sublead_jet_c6_pt_ = -999.;
            sublead_jet_c7_pt_ = -999.;
            sublead_jet_c8_pt_ = -999.;
            sublead_jet_c9_pt_ = -999.;
            sublead_jet_c10_pt_ = -999.;
            sublead_jet_c11_pt_ = -999.;
            sublead_jet_c12_pt_ = -999.;
            sublead_jet_c13_pt_ = -999.;
            sublead_jet_c14_pt_ = -999.;
            sublead_jet_c15_pt_ = -999.;
            sublead_jet_c16_pt_ = -999.;
            sublead_jet_c17_pt_ = -999.;
            sublead_jet_c18_pt_ = -999.;
            sublead_jet_c19_pt_ = -999.;
            sublead_jet_c20_pt_ = -999.;
            sublead_jet_c21_pt_ = -999.;
            sublead_jet_c22_pt_ = -999.;
            sublead_jet_c23_pt_ = -999.;
            sublead_jet_c24_pt_ = -999.;
            sublead_jet_c25_pt_ = -999.;
            sublead_jet_c26_pt_ = -999.;
            sublead_jet_c27_pt_ = -999.;
            sublead_jet_c28_pt_ = -999.;
            sublead_jet_c29_pt_ = -999.;
            sublead_jet_c30_pt_ = -999.;
            sublead_jet_c31_pt_ = -999.;
            sublead_jet_c32_pt_ = -999.;
            sublead_jet_c33_pt_ = -999.;
            sublead_jet_c34_pt_ = -999.;
            sublead_jet_c35_pt_ = -999.;
            sublead_jet_c36_pt_ = -999.;
            sublead_jet_c37_pt_ = -999.;
            sublead_jet_c38_pt_ = -999.;
            sublead_jet_c39_pt_ = -999.;
            sublead_jet_c40_pt_ = -999.;
            sublead_jet_c41_pt_ = -999.;
            sublead_jet_c42_pt_ = -999.;
            sublead_jet_c43_pt_ = -999.;
            sublead_jet_c44_pt_ = -999.;
            sublead_jet_c45_pt_ = -999.;
            sublead_jet_c46_pt_ = -999.;
            sublead_jet_c47_pt_ = -999.;
            sublead_jet_c48_pt_ = -999.;
            sublead_jet_c49_pt_ = -999.;
            sublead_jet_c50_pt_ = -999.;
            sublead_jet_c51_pt_ = -999.;
            sublead_jet_c52_pt_ = -999.;
            sublead_jet_c53_pt_ = -999.;
            sublead_jet_c54_pt_ = -999.;
            sublead_jet_c55_pt_ = -999.;
            sublead_jet_c56_pt_ = -999.;
            sublead_jet_c57_pt_ = -999.;
            sublead_jet_c58_pt_ = -999.;
            sublead_jet_c59_pt_ = -999.;
            sublead_jet_c60_pt_ = -999.;

            sublead_jet_c1_energy_ = -999.;
            sublead_jet_c2_energy_ = -999.;
            sublead_jet_c3_energy_ = -999.;
            sublead_jet_c4_energy_ = -999.;
            sublead_jet_c5_energy_ = -999.;
            sublead_jet_c6_energy_ = -999.;
            sublead_jet_c7_energy_ = -999.;
            sublead_jet_c8_energy_ = -999.;
            sublead_jet_c9_energy_ = -999.;
            sublead_jet_c10_energy_ = -999.;
            sublead_jet_c11_energy_ = -999.;
            sublead_jet_c12_energy_ = -999.;
            sublead_jet_c13_energy_ = -999.;
            sublead_jet_c14_energy_ = -999.;
            sublead_jet_c15_energy_ = -999.;
            sublead_jet_c16_energy_ = -999.;
            sublead_jet_c17_energy_ = -999.;
            sublead_jet_c18_energy_ = -999.;
            sublead_jet_c19_energy_ = -999.;
            sublead_jet_c20_energy_ = -999.;
            sublead_jet_c21_energy_ = -999.;
            sublead_jet_c22_energy_ = -999.;
            sublead_jet_c23_energy_ = -999.;
            sublead_jet_c24_energy_ = -999.;
            sublead_jet_c25_energy_ = -999.;
            sublead_jet_c26_energy_ = -999.;
            sublead_jet_c27_energy_ = -999.;
            sublead_jet_c28_energy_ = -999.;
            sublead_jet_c29_energy_ = -999.;
            sublead_jet_c30_energy_ = -999.;
            sublead_jet_c31_energy_ = -999.;
            sublead_jet_c32_energy_ = -999.;
            sublead_jet_c33_energy_ = -999.;
            sublead_jet_c34_energy_ = -999.;
            sublead_jet_c35_energy_ = -999.;
            sublead_jet_c36_energy_ = -999.;
            sublead_jet_c37_energy_ = -999.;
            sublead_jet_c38_energy_ = -999.;
            sublead_jet_c39_energy_ = -999.;
            sublead_jet_c40_energy_ = -999.;
            sublead_jet_c41_energy_ = -999.;
            sublead_jet_c42_energy_ = -999.;
            sublead_jet_c43_energy_ = -999.;
            sublead_jet_c44_energy_ = -999.;
            sublead_jet_c45_energy_ = -999.;
            sublead_jet_c46_energy_ = -999.;
            sublead_jet_c47_energy_ = -999.;
            sublead_jet_c48_energy_ = -999.;
            sublead_jet_c49_energy_ = -999.;
            sublead_jet_c50_energy_ = -999.;
            sublead_jet_c51_energy_ = -999.;
            sublead_jet_c52_energy_ = -999.;
            sublead_jet_c53_energy_ = -999.;
            sublead_jet_c54_energy_ = -999.;
            sublead_jet_c55_energy_ = -999.;
            sublead_jet_c56_energy_ = -999.;
            sublead_jet_c57_energy_ = -999.;
            sublead_jet_c58_energy_ = -999.;
            sublead_jet_c59_energy_ = -999.;
            sublead_jet_c60_energy_ = -999.;

            subsublead_jet_c1_eta_  = -999.;
            subsublead_jet_c2_eta_  = -999.;
            subsublead_jet_c3_eta_  = -999.;
            subsublead_jet_c4_eta_  = -999.;
            subsublead_jet_c5_eta_  = -999.;
            subsublead_jet_c6_eta_  = -999.;
            subsublead_jet_c7_eta_  = -999.;
            subsublead_jet_c8_eta_  = -999.;
            subsublead_jet_c9_eta_  = -999.;
            subsublead_jet_c10_eta_  = -999.;
            subsublead_jet_c11_eta_  = -999.;
            subsublead_jet_c12_eta_  = -999.;
            subsublead_jet_c13_eta_  = -999.;
            subsublead_jet_c14_eta_  = -999.;
            subsublead_jet_c15_eta_  = -999.;
            subsublead_jet_c16_eta_  = -999.;
            subsublead_jet_c17_eta_  = -999.;
            subsublead_jet_c18_eta_  = -999.;
            subsublead_jet_c19_eta_  = -999.;
            subsublead_jet_c20_eta_  = -999.;
            subsublead_jet_c21_eta_  = -999.;
            subsublead_jet_c22_eta_  = -999.;
            subsublead_jet_c23_eta_  = -999.;
            subsublead_jet_c24_eta_  = -999.;
            subsublead_jet_c25_eta_  = -999.;
            subsublead_jet_c26_eta_  = -999.;
            subsublead_jet_c27_eta_  = -999.;
            subsublead_jet_c28_eta_  = -999.;
            subsublead_jet_c29_eta_  = -999.;
            subsublead_jet_c30_eta_  = -999.;
            subsublead_jet_c31_eta_  = -999.;
            subsublead_jet_c32_eta_  = -999.;
            subsublead_jet_c33_eta_  = -999.;
            subsublead_jet_c34_eta_  = -999.;
            subsublead_jet_c35_eta_  = -999.;
            subsublead_jet_c36_eta_  = -999.;
            subsublead_jet_c37_eta_  = -999.;
            subsublead_jet_c38_eta_  = -999.;
            subsublead_jet_c39_eta_  = -999.;
            subsublead_jet_c40_eta_  = -999.;
            subsublead_jet_c41_eta_  = -999.;
            subsublead_jet_c42_eta_  = -999.;
            subsublead_jet_c43_eta_  = -999.;
            subsublead_jet_c44_eta_  = -999.;
            subsublead_jet_c45_eta_  = -999.;
            subsublead_jet_c46_eta_  = -999.;
            subsublead_jet_c47_eta_  = -999.;
            subsublead_jet_c48_eta_  = -999.;
            subsublead_jet_c49_eta_  = -999.;
            subsublead_jet_c50_eta_  = -999.;
            subsublead_jet_c51_eta_  = -999.;
            subsublead_jet_c52_eta_  = -999.;
            subsublead_jet_c53_eta_  = -999.;
            subsublead_jet_c54_eta_  = -999.;
            subsublead_jet_c55_eta_  = -999.;
            subsublead_jet_c56_eta_  = -999.;
            subsublead_jet_c57_eta_  = -999.;
            subsublead_jet_c58_eta_  = -999.;
            subsublead_jet_c59_eta_  = -999.;
            subsublead_jet_c60_eta_  = -999.;

            subsublead_jet_c1_phi_  = -999.;
            subsublead_jet_c2_phi_  = -999.;
            subsublead_jet_c3_phi_  = -999.;
            subsublead_jet_c4_phi_  = -999.;
            subsublead_jet_c5_phi_  = -999.;
            subsublead_jet_c6_phi_  = -999.;
            subsublead_jet_c7_phi_  = -999.;
            subsublead_jet_c8_phi_  = -999.;
            subsublead_jet_c9_phi_  = -999.;
            subsublead_jet_c10_phi_  = -999.;
            subsublead_jet_c11_phi_  = -999.;
            subsublead_jet_c12_phi_  = -999.;
            subsublead_jet_c13_phi_  = -999.;
            subsublead_jet_c14_phi_  = -999.;
            subsublead_jet_c15_phi_  = -999.;
            subsublead_jet_c16_phi_  = -999.;
            subsublead_jet_c17_phi_  = -999.;
            subsublead_jet_c18_phi_  = -999.;
            subsublead_jet_c19_phi_  = -999.;
            subsublead_jet_c20_phi_  = -999.;
            subsublead_jet_c21_phi_  = -999.;
            subsublead_jet_c22_phi_  = -999.;
            subsublead_jet_c23_phi_  = -999.;
            subsublead_jet_c24_phi_  = -999.;
            subsublead_jet_c25_phi_  = -999.;
            subsublead_jet_c26_phi_  = -999.;
            subsublead_jet_c27_phi_  = -999.;
            subsublead_jet_c28_phi_  = -999.;
            subsublead_jet_c29_phi_  = -999.;
            subsublead_jet_c30_phi_  = -999.;
            subsublead_jet_c31_phi_  = -999.;
            subsublead_jet_c32_phi_  = -999.;
            subsublead_jet_c33_phi_  = -999.;
            subsublead_jet_c34_phi_  = -999.;
            subsublead_jet_c35_phi_  = -999.;
            subsublead_jet_c36_phi_  = -999.;
            subsublead_jet_c37_phi_  = -999.;
            subsublead_jet_c38_phi_  = -999.;
            subsublead_jet_c39_phi_  = -999.;
            subsublead_jet_c40_phi_  = -999.;
            subsublead_jet_c41_phi_  = -999.;
            subsublead_jet_c42_phi_  = -999.;
            subsublead_jet_c43_phi_  = -999.;
            subsublead_jet_c44_phi_  = -999.;
            subsublead_jet_c45_phi_  = -999.;
            subsublead_jet_c46_phi_  = -999.;
            subsublead_jet_c47_phi_  = -999.;
            subsublead_jet_c48_phi_  = -999.;
            subsublead_jet_c49_phi_  = -999.;
            subsublead_jet_c50_phi_  = -999.;
            subsublead_jet_c51_phi_  = -999.;
            subsublead_jet_c52_phi_  = -999.;
            subsublead_jet_c53_phi_  = -999.;
            subsublead_jet_c54_phi_  = -999.;
            subsublead_jet_c55_phi_  = -999.;
            subsublead_jet_c56_phi_  = -999.;
            subsublead_jet_c57_phi_  = -999.;
            subsublead_jet_c58_phi_  = -999.;
            subsublead_jet_c59_phi_  = -999.;
            subsublead_jet_c60_phi_  = -999.;

            subsublead_jet_c1_charge_ = -999.;
            subsublead_jet_c2_charge_ = -999.;
            subsublead_jet_c3_charge_ = -999.;
            subsublead_jet_c4_charge_ = -999.;
            subsublead_jet_c5_charge_ = -999.;
            subsublead_jet_c6_charge_ = -999.;
            subsublead_jet_c7_charge_ = -999.;
            subsublead_jet_c8_charge_ = -999.;
            subsublead_jet_c9_charge_ = -999.;
            subsublead_jet_c10_charge_ = -999.;
            subsublead_jet_c11_charge_ = -999.;
            subsublead_jet_c12_charge_ = -999.;
            subsublead_jet_c13_charge_ = -999.;
            subsublead_jet_c14_charge_ = -999.;
            subsublead_jet_c15_charge_ = -999.;
            subsublead_jet_c16_charge_ = -999.;
            subsublead_jet_c17_charge_ = -999.;
            subsublead_jet_c18_charge_ = -999.;
            subsublead_jet_c19_charge_ = -999.;
            subsublead_jet_c20_charge_ = -999.;
            subsublead_jet_c21_charge_ = -999.;
            subsublead_jet_c22_charge_ = -999.;
            subsublead_jet_c23_charge_ = -999.;
            subsublead_jet_c24_charge_ = -999.;
            subsublead_jet_c25_charge_ = -999.;
            subsublead_jet_c26_charge_ = -999.;
            subsublead_jet_c27_charge_ = -999.;
            subsublead_jet_c28_charge_ = -999.;
            subsublead_jet_c29_charge_ = -999.;
            subsublead_jet_c30_charge_ = -999.;
            subsublead_jet_c31_charge_ = -999.;
            subsublead_jet_c32_charge_ = -999.;
            subsublead_jet_c33_charge_ = -999.;
            subsublead_jet_c34_charge_ = -999.;
            subsublead_jet_c35_charge_ = -999.;
            subsublead_jet_c36_charge_ = -999.;
            subsublead_jet_c37_charge_ = -999.;
            subsublead_jet_c38_charge_ = -999.;
            subsublead_jet_c39_charge_ = -999.;
            subsublead_jet_c40_charge_ = -999.;
            subsublead_jet_c41_charge_ = -999.;
            subsublead_jet_c42_charge_ = -999.;
            subsublead_jet_c43_charge_ = -999.;
            subsublead_jet_c44_charge_ = -999.;
            subsublead_jet_c45_charge_ = -999.;
            subsublead_jet_c46_charge_ = -999.;
            subsublead_jet_c47_charge_ = -999.;
            subsublead_jet_c48_charge_ = -999.;
            subsublead_jet_c49_charge_ = -999.;
            subsublead_jet_c50_charge_ = -999.;
            subsublead_jet_c51_charge_ = -999.;
            subsublead_jet_c52_charge_ = -999.;
            subsublead_jet_c53_charge_ = -999.;
            subsublead_jet_c54_charge_ = -999.;
            subsublead_jet_c55_charge_ = -999.;
            subsublead_jet_c56_charge_ = -999.;
            subsublead_jet_c57_charge_ = -999.;
            subsublead_jet_c58_charge_ = -999.;
            subsublead_jet_c59_charge_ = -999.;
            subsublead_jet_c60_charge_ = -999.;

            subsublead_jet_c1_pt_ = -999.;
            subsublead_jet_c2_pt_ = -999.;
            subsublead_jet_c3_pt_ = -999.;
            subsublead_jet_c4_pt_ = -999.;
            subsublead_jet_c5_pt_ = -999.;
            subsublead_jet_c6_pt_ = -999.;
            subsublead_jet_c7_pt_ = -999.;
            subsublead_jet_c8_pt_ = -999.;
            subsublead_jet_c9_pt_ = -999.;
            subsublead_jet_c10_pt_ = -999.;
            subsublead_jet_c11_pt_ = -999.;
            subsublead_jet_c12_pt_ = -999.;
            subsublead_jet_c13_pt_ = -999.;
            subsublead_jet_c14_pt_ = -999.;
            subsublead_jet_c15_pt_ = -999.;
            subsublead_jet_c16_pt_ = -999.;
            subsublead_jet_c17_pt_ = -999.;
            subsublead_jet_c18_pt_ = -999.;
            subsublead_jet_c19_pt_ = -999.;
            subsublead_jet_c20_pt_ = -999.;
            subsublead_jet_c21_pt_ = -999.;
            subsublead_jet_c22_pt_ = -999.;
            subsublead_jet_c23_pt_ = -999.;
            subsublead_jet_c24_pt_ = -999.;
            subsublead_jet_c25_pt_ = -999.;
            subsublead_jet_c26_pt_ = -999.;
            subsublead_jet_c27_pt_ = -999.;
            subsublead_jet_c28_pt_ = -999.;
            subsublead_jet_c29_pt_ = -999.;
            subsublead_jet_c30_pt_ = -999.;
            subsublead_jet_c31_pt_ = -999.;
            subsublead_jet_c32_pt_ = -999.;
            subsublead_jet_c33_pt_ = -999.;
            subsublead_jet_c34_pt_ = -999.;
            subsublead_jet_c35_pt_ = -999.;
            subsublead_jet_c36_pt_ = -999.;
            subsublead_jet_c37_pt_ = -999.;
            subsublead_jet_c38_pt_ = -999.;
            subsublead_jet_c39_pt_ = -999.;
            subsublead_jet_c40_pt_ = -999.;
            subsublead_jet_c41_pt_ = -999.;
            subsublead_jet_c42_pt_ = -999.;
            subsublead_jet_c43_pt_ = -999.;
            subsublead_jet_c44_pt_ = -999.;
            subsublead_jet_c45_pt_ = -999.;
            subsublead_jet_c46_pt_ = -999.;
            subsublead_jet_c47_pt_ = -999.;
            subsublead_jet_c48_pt_ = -999.;
            subsublead_jet_c49_pt_ = -999.;
            subsublead_jet_c50_pt_ = -999.;
            subsublead_jet_c51_pt_ = -999.;
            subsublead_jet_c52_pt_ = -999.;
            subsublead_jet_c53_pt_ = -999.;
            subsublead_jet_c54_pt_ = -999.;
            subsublead_jet_c55_pt_ = -999.;
            subsublead_jet_c56_pt_ = -999.;
            subsublead_jet_c57_pt_ = -999.;
            subsublead_jet_c58_pt_ = -999.;
            subsublead_jet_c59_pt_ = -999.;
            subsublead_jet_c60_pt_ = -999.;

            subsublead_jet_c1_energy_ = -999.;
            subsublead_jet_c2_energy_ = -999.;
            subsublead_jet_c3_energy_ = -999.;
            subsublead_jet_c4_energy_ = -999.;
            subsublead_jet_c5_energy_ = -999.;
            subsublead_jet_c6_energy_ = -999.;
            subsublead_jet_c7_energy_ = -999.;
            subsublead_jet_c8_energy_ = -999.;
            subsublead_jet_c9_energy_ = -999.;
            subsublead_jet_c10_energy_ = -999.;
            subsublead_jet_c11_energy_ = -999.;
            subsublead_jet_c12_energy_ = -999.;
            subsublead_jet_c13_energy_ = -999.;
            subsublead_jet_c14_energy_ = -999.;
            subsublead_jet_c15_energy_ = -999.;
            subsublead_jet_c16_energy_ = -999.;
            subsublead_jet_c17_energy_ = -999.;
            subsublead_jet_c18_energy_ = -999.;
            subsublead_jet_c19_energy_ = -999.;
            subsublead_jet_c20_energy_ = -999.;
            subsublead_jet_c21_energy_ = -999.;
            subsublead_jet_c22_energy_ = -999.;
            subsublead_jet_c23_energy_ = -999.;
            subsublead_jet_c24_energy_ = -999.;
            subsublead_jet_c25_energy_ = -999.;
            subsublead_jet_c26_energy_ = -999.;
            subsublead_jet_c27_energy_ = -999.;
            subsublead_jet_c28_energy_ = -999.;
            subsublead_jet_c29_energy_ = -999.;
            subsublead_jet_c30_energy_ = -999.;
            subsublead_jet_c31_energy_ = -999.;
            subsublead_jet_c32_energy_ = -999.;
            subsublead_jet_c33_energy_ = -999.;
            subsublead_jet_c34_energy_ = -999.;
            subsublead_jet_c35_energy_ = -999.;
            subsublead_jet_c36_energy_ = -999.;
            subsublead_jet_c37_energy_ = -999.;
            subsublead_jet_c38_energy_ = -999.;
            subsublead_jet_c39_energy_ = -999.;
            subsublead_jet_c40_energy_ = -999.;
            subsublead_jet_c41_energy_ = -999.;
            subsublead_jet_c42_energy_ = -999.;
            subsublead_jet_c43_energy_ = -999.;
            subsublead_jet_c44_energy_ = -999.;
            subsublead_jet_c45_energy_ = -999.;
            subsublead_jet_c46_energy_ = -999.;
            subsublead_jet_c47_energy_ = -999.;
            subsublead_jet_c48_energy_ = -999.;
            subsublead_jet_c49_energy_ = -999.;
            subsublead_jet_c50_energy_ = -999.;
            subsublead_jet_c51_energy_ = -999.;
            subsublead_jet_c52_energy_ = -999.;
            subsublead_jet_c53_energy_ = -999.;
            subsublead_jet_c54_energy_ = -999.;
            subsublead_jet_c55_energy_ = -999.;
            subsublead_jet_c56_energy_ = -999.;
            subsublead_jet_c57_energy_ = -999.;
            subsublead_jet_c58_energy_ = -999.;
            subsublead_jet_c59_energy_ = -999.;
            subsublead_jet_c60_energy_ = -999.;

            dipho_PToM_       = -999.;
            leadPho_PToM_     = -999.;
            sublPho_PToM_     = -999.;
           
            // First find dijet by looking for highest-pt jets...
            std::pair <int, int>     dijet_indices( -1, -1 );
            std::pair <float, float> dijet_pts( -1., -1. );
            int jet_3_index = -1;
            int jet_3_pt    = -1;
                        
            float phi1 = diPhotons->ptrAt( candIndex )->leadingPhoton()->phi();
            float eta1 = diPhotons->ptrAt( candIndex )->leadingPhoton()->eta();
            float phi2 = diPhotons->ptrAt( candIndex )->subLeadingPhoton()->phi();
            float eta2 = diPhotons->ptrAt( candIndex )->subLeadingPhoton()->eta();
            
            bool hasValidVBFDiJet  = 0;
            bool hasValidVBFTriJet = 0;
            
            int  n_jets_count = 0;
            // take the jets corresponding to the diphoton candidate
            unsigned int jetCollectionIndex = diPhotons->ptrAt( candIndex )->jetCollectionIndex();
                        
            for( UInt_t jetLoop = 0; jetLoop < Jets[jetCollectionIndex]->size() ; jetLoop++ ) {
                Ptr<flashgg::Jet> jet  = Jets[jetCollectionIndex]->ptrAt( jetLoop );
                flashgg::Jet fjet = flashgg::Jet( *jet );
                Ptr<pat::Jet> patJet = Jets[jetCollectionIndex]->ptrAt( jetLoop );

                //if (jet->puJetId(diPhotons[candIndex]) <  PuIDCutoff) {continue;}
                if( _usePuJetID && !jet->passesPuJetId(diPhotons->ptrAt( candIndex ))){ continue;}
                if( _useJetID ){
                    if( _JetIDLevel == "Loose" && !jet->passesJetID  ( flashgg::Tight2017 ) ) continue;
                    if( _JetIDLevel == "Tight" && !jet->passesJetID  ( flashgg::Tight ) ) continue;
                    if( _JetIDLevel == "Tight2017" && !jet->passesJetID (flashgg::Tight2017 ) ) continue;
                }
                // rms cuts over 2.5 
                if( fabs( jet->eta() ) > 2.5 && jet->rms() > _rmsforwardCut ){ 
                    //std::cout << "("<< jet->eta()<< ")("<< jet->rms() <<").. jet rejected ::" << std::endl;
                    continue; 
                }
                // new PUJID for differents pt bins
                std::vector<std::pair<double,double> > eta_cuts_(4);
                eta_cuts_[0] = std::make_pair (0    ,2.50 );
                eta_cuts_[1] = std::make_pair (2.50 ,2.75 );
                eta_cuts_[2] = std::make_pair (2.75 ,3.00 );
                eta_cuts_[3] = std::make_pair (3.00 ,10);

                
                if ( (!_pujid_wp_pt_bin_1.empty())  &&
                     (!_pujid_wp_pt_bin_2.empty())  &&
                     (!_pujid_wp_pt_bin_3.empty())  ){
                    //std::cout << "VBFTagMVA::DEBUG  making the pujid --> "<< _pujid_wp_pt_bin_1.size() << std::endl;
                    bool pass=false;
                    for (UInt_t eta_bin=0; eta_bin < _pujid_wp_pt_bin_1.size(); eta_bin++ ){
                        //                        std::cout << inputTagJets_[0] 
                        //        << " eta-bin["<< eta_bin<< "] == " << eta_cuts_[eta_bin].first << "  :: "
                        //        << eta_cuts_[eta_bin].second
                        //        << " pt1: " << _pujid_wp_pt_bin_1[eta_bin]
                        //        << " pt2: " << _pujid_wp_pt_bin_2[eta_bin]
                        //        << " pt3: " << _pujid_wp_pt_bin_3[eta_bin]
                        //        << std::endl;
                        if ( fabs( jet->eta() ) >  eta_cuts_[eta_bin].first &&
                             fabs( jet->eta() ) <= eta_cuts_[eta_bin].second){
                            if ( jet->pt() >  20 &&
                                 jet->pt() <= 30 && jet->puJetIdMVA() > _pujid_wp_pt_bin_1[eta_bin] )
                                pass=true;
                            if ( jet->pt() >  30 &&
                                 jet->pt() <= 50 && jet->puJetIdMVA() > _pujid_wp_pt_bin_2[eta_bin] )
                                pass=true;
                            if ( jet->pt() >  50 &&
                                 jet->pt() <= 100&& jet->puJetIdMVA() > _pujid_wp_pt_bin_3[eta_bin] )
                                pass=true;
                            if (jet->pt() > 100) pass = true;
                        }
                    }
                    //                    std::cout << inputTagJets_[0] << " pt="<< jet->pt() << " :eta: "<< jet->eta() << " :mva: "<< jet->puJetIdMVA() << "  pass == " << pass << std::endl;
                    if (!pass) continue;
                }
                // within eta 4.7?
                if( fabs( jet->eta() ) > 4.7 ) { continue; }

                // close to lead photon?
                float dPhi = deltaPhi( jet->phi(), phi1 );
                float dEta = jet->eta() - eta1;
                if( sqrt( dPhi * dPhi + dEta * dEta ) < _drJetPhoton ) { continue; }
                
                // close to sublead photon?
                dPhi = deltaPhi( jet->phi(), phi2 );
                dEta = jet->eta() - eta2;
                if( sqrt( dPhi * dPhi + dEta * dEta ) < _drJetPhoton ) { continue; }
                
                if( jet->pt() > dijet_pts.first ) {
                    // if pt of this jet is higher than the one currently in lead position
                    // then shift back lead jet into sublead position...
                    dijet_indices.second = dijet_indices.first;
                    dijet_pts.second     = dijet_pts.first;
                    // .. and put the new jet as the lead jet.
                    dijet_indices.first = jetLoop;
                    dijet_pts.first     = jet->pt();
                    
                    // trijet indicies
                    //jet_3_index = dijet_indices.second;
                    //jet_3_pt    = dijet_pts.second;
                } else if( jet->pt() > dijet_pts.second ) { 
                    // for the 3rd jets
                    jet_3_index = dijet_indices.second;
                    jet_3_pt    = dijet_pts.second;
                    
                    // this condition is added here to force to have the leading 
                    // and subleading jets in two different hemispheres 
                    // if the jet's pt isn't as high as the lead jet's but i higher 
                    // than the sublead jet's The replace the sublead jet by this new jet.
                    dijet_indices.second = jetLoop;
                    dijet_pts.second     = jet->pt();
                    
                }else if( jet->pt() > jet_3_pt ){//&& dijet_indices.first != int(jetLoop) && dijet_indices.second != int(jetLoop))
                    jet_3_index = jetLoop;
                    jet_3_pt    = jet->pt();
                }
                if( jet->pt() > 30.0 ){
                  n_jets_count++;
                  //std::cout << "n_jets_count = : " << n_jets_count <<std::endl;
                  //std::cout << "JET pt is " << jet->pt() << std::endl;
                  if (fjet.hasConstituentInfo()) {
                    //fill the reco jet info:
                   if(n_jets_count==1){
                     pt_J1_ = jet->pt();
                     eta_J1_ = jet->eta();
                     phi_J1_ = jet->phi();
                     charge_J1_ = jet->charge();
                     energy_J1_ = jet->energy();
                     flav_J1_ = jet->partonFlavour();
                     } 
                   if(n_jets_count==2){
                     pt_J2_ = jet->pt();
                     eta_J2_ = jet->eta();
                     phi_J2_ = jet->phi();
                     charge_J2_ = jet->charge();
                     energy_J2_ = jet->energy();
                     flav_J2_ = jet->partonFlavour();
                     } 
                   if(n_jets_count==3){
                     pt_J3_ = jet->pt();
                     eta_J3_ = jet->eta();
                     phi_J3_ = jet->phi();
                     charge_J3_ = jet->charge();
                     energy_J3_ = jet->energy();
                     flav_J3_ = jet->partonFlavour();
                     } 

                    std::vector<float> theConstitInfo = fjet.getConstituentInfo();
                    //test_vec_ = theConstitInfo;
                    constit_energy_ = theConstitInfo[0];
                    unsigned int nConstituents = (theConstitInfo.size())/5;
                    //std::cout << "nConstits: " << nConstituents << std::endl; 
                    n_constits_ = nConstituents;

                    std::vector<float> etaVec;
                    std::vector<float> phiVec;
                    std::vector<float> chargeVec;
                    std::vector<float> ptVec;
                    std::vector<float> energyVec;

                    int index = 5;
                    unsigned int i =0;
                    //unsigned int nConstitsAbovePt = 0; 

                    for(i=0; i<nConstituents; i++){
                      index = 5*i;
                      //std::cout << "constit: " << i << std::endl;
                      //std::cout << "so indexer is: " << index << std::endl;
                      //std::cout << "eta: " << theConstitInfo[index]<< std::endl;
                      //std::cout << "phi: " << theConstitInfo[index+1]<< std::endl;
                      //std::cout << "charge: " << theConstitInfo[index+2]<< std::endl;
                      //std::cout << "pt: " << theConstitInfo[index+3]<< std::endl;
                      //std::cout << "energy: " << theConstitInfo[index+4]<< std::endl;
                      //std::cout << "the JET pt is: " << jet->pt() << std::endl;
                      //if( (theConstitInfo[index+3]/jet->pt()) > 0.05 ){
                      // fill vectors and unpack it later
                        //nConstitsAbovePt++;
                        etaVec.push_back(theConstitInfo[index]);
                        phiVec.push_back(theConstitInfo[index+1]);
                        chargeVec.push_back(theConstitInfo[index+2]);
                        ptVec.push_back(theConstitInfo[index+3]);
                        energyVec.push_back(theConstitInfo[index+4]);
                      //}
                      
                    }
                    //std::cout << "number of constits passing pt threshol: " << nConstitsAbovePt << std::endl;
                    //Now do a switch statement to unpack vectors
                    if(n_jets_count==1 ){//leading jet since pts are ordered
                      for(unsigned int i = 0; i< nConstituents; i++){
                        //std::cout << "the counter inside lead jet loop is at: " << i << std::endl;
                        if(i==0){
                          //fill lead jet constit 1
                          //std::cout << "filled lead constit 1" << std::endl;
                          lead_jet_c1_eta_ = etaVec[i];
                          lead_jet_c1_phi_ = phiVec[i];
                          lead_jet_c1_charge_ = chargeVec[i];
                          lead_jet_c1_pt_ = ptVec[i];
                          lead_jet_c1_energy_ = energyVec[i];
                        }
                        if(i==1){
                          //fill lead jet constit 2
                          //std::cout << "filled lead constit 2" << std::endl;
                          lead_jet_c2_eta_ = etaVec[i];
                          lead_jet_c2_phi_ = phiVec[i];
                          lead_jet_c2_charge_ = chargeVec[i];
                          lead_jet_c2_pt_ = ptVec[i];
                          lead_jet_c2_energy_ = energyVec[i];
                        }
                        if(i==2){
                          //fill lead jet constit 3
                          //std::cout << "filled lead constit 3" << std::endl;
                          lead_jet_c3_eta_ = etaVec[i];
                          lead_jet_c3_phi_ = phiVec[i];
                          lead_jet_c3_charge_ = chargeVec[i];
                          lead_jet_c3_pt_ = ptVec[i];
                          lead_jet_c3_energy_ = energyVec[i];
                        }
                        if(i==3){
                          //fill lead jet constit 4
                          //std::cout << "filled lead constit 4" << std::endl;
                          lead_jet_c4_eta_ = etaVec[i];
                          lead_jet_c4_phi_ = phiVec[i];
                          lead_jet_c4_charge_ = chargeVec[i];
                          lead_jet_c4_pt_ = ptVec[i];
                          lead_jet_c4_energy_ = energyVec[i];
                        }
                        if(i==4){
                          //fill lead jet constit 5
                          //std::cout << "filled lead constit 5" << std::endl;
                          lead_jet_c5_eta_ = etaVec[i];
                          lead_jet_c5_phi_ = phiVec[i];
                          lead_jet_c5_charge_ = chargeVec[i];
                          lead_jet_c5_pt_ = ptVec[i];
                          lead_jet_c5_energy_ = energyVec[i];
                        }
                        if(i==5){
                          //fill lead jet constit 6
                          //std::cout << "filled lead constit 6" << std::endl;
                          lead_jet_c6_eta_ = etaVec[i];
                          lead_jet_c6_phi_ = phiVec[i];
                          lead_jet_c6_charge_ = chargeVec[i];
                          lead_jet_c6_pt_ = ptVec[i];
                          lead_jet_c6_energy_ = energyVec[i];
                        }
                        if(i==6){
                          //fill lead jet constit 7
                          //std::cout << "filled lead constit 7" << std::endl;
                          lead_jet_c7_eta_ = etaVec[i];
                          lead_jet_c7_phi_ = phiVec[i];
                          lead_jet_c7_charge_ = chargeVec[i];
                          lead_jet_c7_pt_ = ptVec[i];
                          lead_jet_c7_energy_ = energyVec[i];
                        }
                        if(i==7){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c8_eta_ = etaVec[i];
                          lead_jet_c8_phi_ = phiVec[i];
                          lead_jet_c8_charge_ = chargeVec[i];
                          lead_jet_c8_pt_ = ptVec[i];
                          lead_jet_c8_energy_ = energyVec[i];
                        }
                        if(i==8){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c9_eta_ = etaVec[i];
                          lead_jet_c9_phi_ = phiVec[i];
                          lead_jet_c9_charge_ = chargeVec[i];
                          lead_jet_c9_pt_ = ptVec[i];
                          lead_jet_c9_energy_ = energyVec[i];
                        }
                        if(i==9){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c10_eta_ = etaVec[i];
                          lead_jet_c10_phi_ = phiVec[i];
                          lead_jet_c10_charge_ = chargeVec[i];
                          lead_jet_c10_pt_ = ptVec[i];
                          lead_jet_c10_energy_ = energyVec[i];
                        }
                        if(i==10){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c11_eta_ = etaVec[i];
                          lead_jet_c11_phi_ = phiVec[i];
                          lead_jet_c11_charge_ = chargeVec[i];
                          lead_jet_c11_pt_ = ptVec[i];
                          lead_jet_c11_energy_ = energyVec[i];
                        }
                        if(i==11){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c12_eta_ = etaVec[i];
                          lead_jet_c12_phi_ = phiVec[i];
                          lead_jet_c12_charge_ = chargeVec[i];
                          lead_jet_c12_pt_ = ptVec[i];
                          lead_jet_c12_energy_ = energyVec[i];
                        }
                        if(i==12){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c13_eta_ = etaVec[i];
                          lead_jet_c13_phi_ = phiVec[i];
                          lead_jet_c13_charge_ = chargeVec[i];
                          lead_jet_c13_pt_ = ptVec[i];
                          lead_jet_c13_energy_ = energyVec[i];
                        }
                        if(i==13){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c14_eta_ = etaVec[i];
                          lead_jet_c14_phi_ = phiVec[i];
                          lead_jet_c14_charge_ = chargeVec[i];
                          lead_jet_c14_pt_ = ptVec[i];
                          lead_jet_c14_energy_ = energyVec[i];
                        }
                        if(i==14){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c15_eta_ = etaVec[i];
                          lead_jet_c15_phi_ = phiVec[i];
                          lead_jet_c15_charge_ = chargeVec[i];
                          lead_jet_c15_pt_ = ptVec[i];
                          lead_jet_c15_energy_ = energyVec[i];
                        }
                        if(i==15){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c16_eta_ = etaVec[i];
                          lead_jet_c16_phi_ = phiVec[i];
                          lead_jet_c16_charge_ = chargeVec[i];
                          lead_jet_c16_pt_ = ptVec[i];
                          lead_jet_c16_energy_ = energyVec[i];
                        }
                        if(i==16){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c17_eta_ = etaVec[i];
                          lead_jet_c17_phi_ = phiVec[i];
                          lead_jet_c17_charge_ = chargeVec[i];
                          lead_jet_c17_pt_ = ptVec[i];
                          lead_jet_c17_energy_ = energyVec[i];
                        }
                        if(i==17){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c18_eta_ = etaVec[i];
                          lead_jet_c18_phi_ = phiVec[i];
                          lead_jet_c18_charge_ = chargeVec[i];
                          lead_jet_c18_pt_ = ptVec[i];
                          lead_jet_c18_energy_ = energyVec[i];
                        }
                        if(i==18){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c19_eta_ = etaVec[i];
                          lead_jet_c19_phi_ = phiVec[i];
                          lead_jet_c19_charge_ = chargeVec[i];
                          lead_jet_c19_pt_ = ptVec[i];
                          lead_jet_c19_energy_ = energyVec[i];
                        }
                        if(i==19){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c20_eta_ = etaVec[i];
                          lead_jet_c20_phi_ = phiVec[i];
                          lead_jet_c20_charge_ = chargeVec[i];
                          lead_jet_c20_pt_ = ptVec[i];
                          lead_jet_c20_energy_ = energyVec[i];
                        }
                        if(i==20){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c21_eta_ = etaVec[i];
                          lead_jet_c21_phi_ = phiVec[i];
                          lead_jet_c21_charge_ = chargeVec[i];
                          lead_jet_c21_pt_ = ptVec[i];
                          lead_jet_c21_energy_ = energyVec[i];
                        }
                        if(i==21){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c22_eta_ = etaVec[i];
                          lead_jet_c22_phi_ = phiVec[i];
                          lead_jet_c22_charge_ = chargeVec[i];
                          lead_jet_c22_pt_ = ptVec[i];
                          lead_jet_c22_energy_ = energyVec[i];
                        }
                        if(i==22){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c23_eta_ = etaVec[i];
                          lead_jet_c23_phi_ = phiVec[i];
                          lead_jet_c23_charge_ = chargeVec[i];
                          lead_jet_c23_pt_ = ptVec[i];
                          lead_jet_c23_energy_ = energyVec[i];
                        }
                        if(i==23){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c24_eta_ = etaVec[i];
                          lead_jet_c24_phi_ = phiVec[i];
                          lead_jet_c24_charge_ = chargeVec[i];
                          lead_jet_c24_pt_ = ptVec[i];
                          lead_jet_c24_energy_ = energyVec[i];
                        }
                        if(i==24){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c25_eta_ = etaVec[i];
                          lead_jet_c25_phi_ = phiVec[i];
                          lead_jet_c25_charge_ = chargeVec[i];
                          lead_jet_c25_pt_ = ptVec[i];
                          lead_jet_c25_energy_ = energyVec[i];
                        }
                        if(i==25){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c26_eta_ = etaVec[i];
                          lead_jet_c26_phi_ = phiVec[i];
                          lead_jet_c26_charge_ = chargeVec[i];
                          lead_jet_c26_pt_ = ptVec[i];
                          lead_jet_c26_energy_ = energyVec[i];
                        }
                        if(i==26){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c27_eta_ = etaVec[i];
                          lead_jet_c27_phi_ = phiVec[i];
                          lead_jet_c27_charge_ = chargeVec[i];
                          lead_jet_c27_pt_ = ptVec[i];
                          lead_jet_c27_energy_ = energyVec[i];
                        }
                        if(i==29){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c30_eta_ = etaVec[i];
                          lead_jet_c30_phi_ = phiVec[i];
                          lead_jet_c30_charge_ = chargeVec[i];
                          lead_jet_c30_pt_ = ptVec[i];
                          lead_jet_c30_energy_ = energyVec[i];
                        }
                        if(i==30){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c31_eta_ = etaVec[i];
                          lead_jet_c31_phi_ = phiVec[i];
                          lead_jet_c31_charge_ = chargeVec[i];
                          lead_jet_c31_pt_ = ptVec[i];
                          lead_jet_c31_energy_ = energyVec[i];
                        }
                        if(i==31){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c32_eta_ = etaVec[i];
                          lead_jet_c32_phi_ = phiVec[i];
                          lead_jet_c32_charge_ = chargeVec[i];
                          lead_jet_c32_pt_ = ptVec[i];
                          lead_jet_c32_energy_ = energyVec[i];
                        }
                        if(i==32){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c33_eta_ = etaVec[i];
                          lead_jet_c33_phi_ = phiVec[i];
                          lead_jet_c33_charge_ = chargeVec[i];
                          lead_jet_c33_pt_ = ptVec[i];
                          lead_jet_c33_energy_ = energyVec[i];
                        }
                        if(i==33){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c34_eta_ = etaVec[i];
                          lead_jet_c34_phi_ = phiVec[i];
                          lead_jet_c34_charge_ = chargeVec[i];
                          lead_jet_c34_pt_ = ptVec[i];
                          lead_jet_c34_energy_ = energyVec[i];
                        }
                        if(i==34){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c35_eta_ = etaVec[i];
                          lead_jet_c35_phi_ = phiVec[i];
                          lead_jet_c35_charge_ = chargeVec[i];
                          lead_jet_c35_pt_ = ptVec[i];
                          lead_jet_c35_energy_ = energyVec[i];
                        }
                        if(i==35){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c36_eta_ = etaVec[i];
                          lead_jet_c36_phi_ = phiVec[i];
                          lead_jet_c36_charge_ = chargeVec[i];
                          lead_jet_c36_pt_ = ptVec[i];
                          lead_jet_c36_energy_ = energyVec[i];
                        }
                        if(i==36){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c37_eta_ = etaVec[i];
                          lead_jet_c37_phi_ = phiVec[i];
                          lead_jet_c37_charge_ = chargeVec[i];
                          lead_jet_c37_pt_ = ptVec[i];
                          lead_jet_c37_energy_ = energyVec[i];
                        }
                        if(i==37){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c38_eta_ = etaVec[i];
                          lead_jet_c38_phi_ = phiVec[i];
                          lead_jet_c38_charge_ = chargeVec[i];
                          lead_jet_c38_pt_ = ptVec[i];
                          lead_jet_c38_energy_ = energyVec[i];
                        }
                        if(i==38){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c39_eta_ = etaVec[i];
                          lead_jet_c39_phi_ = phiVec[i];
                          lead_jet_c39_charge_ = chargeVec[i];
                          lead_jet_c39_pt_ = ptVec[i];
                          lead_jet_c39_energy_ = energyVec[i];
                        }
                        if(i==39){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c40_eta_ = etaVec[i];
                          lead_jet_c40_phi_ = phiVec[i];
                          lead_jet_c40_charge_ = chargeVec[i];
                          lead_jet_c40_pt_ = ptVec[i];
                          lead_jet_c40_energy_ = energyVec[i];
                        }
                        if(i==40){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c41_eta_ = etaVec[i];
                          lead_jet_c41_phi_ = phiVec[i];
                          lead_jet_c41_charge_ = chargeVec[i];
                          lead_jet_c41_pt_ = ptVec[i];
                          lead_jet_c41_energy_ = energyVec[i];
                        }
                        if(i==41){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c42_eta_ = etaVec[i];
                          lead_jet_c42_phi_ = phiVec[i];
                          lead_jet_c42_charge_ = chargeVec[i];
                          lead_jet_c42_pt_ = ptVec[i];
                          lead_jet_c42_energy_ = energyVec[i];
                        }
                        if(i==42){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c43_eta_ = etaVec[i];
                          lead_jet_c43_phi_ = phiVec[i];
                          lead_jet_c43_charge_ = chargeVec[i];
                          lead_jet_c43_pt_ = ptVec[i];
                          lead_jet_c43_energy_ = energyVec[i];
                        }
                        if(i==43){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c44_eta_ = etaVec[i];
                          lead_jet_c44_phi_ = phiVec[i];
                          lead_jet_c44_charge_ = chargeVec[i];
                          lead_jet_c44_pt_ = ptVec[i];
                          lead_jet_c44_energy_ = energyVec[i];
                        }
                        if(i==44){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c45_eta_ = etaVec[i];
                          lead_jet_c45_phi_ = phiVec[i];
                          lead_jet_c45_charge_ = chargeVec[i];
                          lead_jet_c45_pt_ = ptVec[i];
                          lead_jet_c45_energy_ = energyVec[i];
                        }
                        if(i==45){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c46_eta_ = etaVec[i];
                          lead_jet_c46_phi_ = phiVec[i];
                          lead_jet_c46_charge_ = chargeVec[i];
                          lead_jet_c46_pt_ = ptVec[i];
                          lead_jet_c46_energy_ = energyVec[i];
                        }
                        if(i==46){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c47_eta_ = etaVec[i];
                          lead_jet_c47_phi_ = phiVec[i];
                          lead_jet_c47_charge_ = chargeVec[i];
                          lead_jet_c47_pt_ = ptVec[i];
                          lead_jet_c47_energy_ = energyVec[i];
                        }
                        if(i==47){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c48_eta_ = etaVec[i];
                          lead_jet_c48_phi_ = phiVec[i];
                          lead_jet_c48_charge_ = chargeVec[i];
                          lead_jet_c48_pt_ = ptVec[i];
                          lead_jet_c48_energy_ = energyVec[i];
                        }
                        if(i==48){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c49_eta_ = etaVec[i];
                          lead_jet_c49_phi_ = phiVec[i];
                          lead_jet_c49_charge_ = chargeVec[i];
                          lead_jet_c49_pt_ = ptVec[i];
                          lead_jet_c49_energy_ = energyVec[i];
                        }
                        if(i==49){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c50_eta_ = etaVec[i];
                          lead_jet_c50_phi_ = phiVec[i];
                          lead_jet_c50_charge_ = chargeVec[i];
                          lead_jet_c50_pt_ = ptVec[i];
                          lead_jet_c50_energy_ = energyVec[i];
                        }
                        if(i==50){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c51_eta_ = etaVec[i];
                          lead_jet_c51_phi_ = phiVec[i];
                          lead_jet_c51_charge_ = chargeVec[i];
                          lead_jet_c51_pt_ = ptVec[i];
                          lead_jet_c51_energy_ = energyVec[i];
                        }
                        if(i==51){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c52_eta_ = etaVec[i];
                          lead_jet_c52_phi_ = phiVec[i];
                          lead_jet_c52_charge_ = chargeVec[i];
                          lead_jet_c52_pt_ = ptVec[i];
                          lead_jet_c52_energy_ = energyVec[i];
                        }
                        if(i==52){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c53_eta_ = etaVec[i];
                          lead_jet_c53_phi_ = phiVec[i];
                          lead_jet_c53_charge_ = chargeVec[i];
                          lead_jet_c53_pt_ = ptVec[i];
                          lead_jet_c53_energy_ = energyVec[i];
                        }
                        if(i==53){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c54_eta_ = etaVec[i];
                          lead_jet_c54_phi_ = phiVec[i];
                          lead_jet_c54_charge_ = chargeVec[i];
                          lead_jet_c54_pt_ = ptVec[i];
                          lead_jet_c54_energy_ = energyVec[i];
                        }
                        if(i==54){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c55_eta_ = etaVec[i];
                          lead_jet_c55_phi_ = phiVec[i];
                          lead_jet_c55_charge_ = chargeVec[i];
                          lead_jet_c55_pt_ = ptVec[i];
                          lead_jet_c55_energy_ = energyVec[i];
                        }
                        if(i==55){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c56_eta_ = etaVec[i];
                          lead_jet_c56_phi_ = phiVec[i];
                          lead_jet_c56_charge_ = chargeVec[i];
                          lead_jet_c56_pt_ = ptVec[i];
                          lead_jet_c56_energy_ = energyVec[i];
                        }
                        if(i==56){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c57_eta_ = etaVec[i];
                          lead_jet_c57_phi_ = phiVec[i];
                          lead_jet_c57_charge_ = chargeVec[i];
                          lead_jet_c57_pt_ = ptVec[i];
                          lead_jet_c57_energy_ = energyVec[i];
                        }
                        if(i==57){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c58_eta_ = etaVec[i];
                          lead_jet_c58_phi_ = phiVec[i];
                          lead_jet_c58_charge_ = chargeVec[i];
                          lead_jet_c58_pt_ = ptVec[i];
                          lead_jet_c58_energy_ = energyVec[i];
                        }
                        if(i==58){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c59_eta_ = etaVec[i];
                          lead_jet_c59_phi_ = phiVec[i];
                          lead_jet_c59_charge_ = chargeVec[i];
                          lead_jet_c59_pt_ = ptVec[i];
                          lead_jet_c59_energy_ = energyVec[i];
                        }
                        if(i==59){
                          //fill lead jet constit 8
                          //std::cout << "filled lead constit 8" << std::endl;
                          lead_jet_c60_eta_ = etaVec[i];
                          lead_jet_c60_phi_ = phiVec[i];
                          lead_jet_c60_charge_ = chargeVec[i];
                          lead_jet_c60_pt_ = ptVec[i];
                          lead_jet_c60_energy_ = energyVec[i];
                        }

                      } 
                    }
                    if(n_jets_count==2){//subleading jet since pts are ordered
                      for(unsigned int i = 0; i< nConstituents; i++){
                        //std::cout << "the counter inside sub lead jet loop is at: " << i << std::endl;
                        if(i==0){
                          //fill lead jet constit 1
                          //std::cout << "filled sub lead constit 1" << std::endl;
                          sublead_jet_c1_eta_ = etaVec[i];
                          sublead_jet_c1_phi_ = phiVec[i];
                          sublead_jet_c1_charge_ = chargeVec[i];
                          sublead_jet_c1_pt_ = ptVec[i];
                          sublead_jet_c1_energy_ = energyVec[i];
                          }
                        if(i==1){
                          //fill lead jet constit 2
                          //std::cout << "filled sub lead constit 2" << std::endl;
                          sublead_jet_c2_eta_ = etaVec[i];
                          sublead_jet_c2_phi_ = phiVec[i];
                          sublead_jet_c2_charge_ = chargeVec[i];
                          sublead_jet_c2_pt_ = ptVec[i];
                          sublead_jet_c2_energy_ = energyVec[i];
                          }
                        if(i==2){
                          //fill lead jet constit 3
                          //std::cout << "filled sub lead constit 3" << std::endl;
                          sublead_jet_c3_eta_ = etaVec[i];
                          sublead_jet_c3_phi_ = phiVec[i];
                          sublead_jet_c3_charge_ = chargeVec[i];
                          sublead_jet_c3_pt_ = ptVec[i];
                          sublead_jet_c3_energy_ = energyVec[i];
                          }
                        if(i==3){
                          //fill lead jet constit 4
                          //std::cout << "filled sub lead constit 4" << std::endl;
                          sublead_jet_c4_eta_ = etaVec[i];
                          sublead_jet_c4_phi_ = phiVec[i];
                          sublead_jet_c4_charge_ = chargeVec[i];
                          sublead_jet_c4_pt_ = ptVec[i];
                          sublead_jet_c4_energy_ = energyVec[i];
                          }
                        if(i==4){
                          //fill lead jet constit 5
                          //std::cout << "filled sub lead constit 5" << std::endl;
                          sublead_jet_c5_eta_ = etaVec[i];
                          sublead_jet_c5_phi_ = phiVec[i];
                          sublead_jet_c5_charge_ = chargeVec[i];
                          sublead_jet_c5_pt_ = ptVec[i];
                          sublead_jet_c5_energy_ = energyVec[i];
                          }
                        if(i==5){
                          //fill lead jet constit 6
                          //std::cout << "filled sub lead constit 6" << std::endl;
                          sublead_jet_c6_eta_ = etaVec[i];
                          sublead_jet_c6_phi_ = phiVec[i];
                          sublead_jet_c6_charge_ = chargeVec[i];
                          sublead_jet_c6_pt_ = ptVec[i];
                          sublead_jet_c6_energy_ = energyVec[i];
                          }
                        if(i==6){
                          //fill lead jet constit 7
                          //std::cout << "filled sub lead constit 7" << std::endl;
                          sublead_jet_c7_eta_ = etaVec[i];
                          sublead_jet_c7_phi_ = phiVec[i];
                          sublead_jet_c7_charge_ = chargeVec[i];
                          sublead_jet_c7_pt_ = ptVec[i];
                          sublead_jet_c7_energy_ = energyVec[i];
                          }
                        if(i==7){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c8_eta_ = etaVec[i];
                          sublead_jet_c8_phi_ = phiVec[i];
                          sublead_jet_c8_charge_ = chargeVec[i];
                          sublead_jet_c8_pt_ = ptVec[i];
                          sublead_jet_c8_energy_ = energyVec[i];
                        }
                        if(i==8){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c9_eta_ = etaVec[i];
                          sublead_jet_c9_phi_ = phiVec[i];
                          sublead_jet_c9_charge_ = chargeVec[i];
                          sublead_jet_c9_pt_ = ptVec[i];
                          sublead_jet_c9_energy_ = energyVec[i];
                        }
                        if(i==9){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c10_eta_ = etaVec[i];
                          sublead_jet_c10_phi_ = phiVec[i];
                          sublead_jet_c10_charge_ = chargeVec[i];
                          sublead_jet_c10_pt_ = ptVec[i];
                          sublead_jet_c10_energy_ = energyVec[i];
                        }
                        if(i==10){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c11_eta_ = etaVec[i];
                          sublead_jet_c11_phi_ = phiVec[i];
                          sublead_jet_c11_charge_ = chargeVec[i];
                          sublead_jet_c11_pt_ = ptVec[i];
                          sublead_jet_c11_energy_ = energyVec[i];
                        }
                        if(i==11){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c12_eta_ = etaVec[i];
                          sublead_jet_c12_phi_ = phiVec[i];
                          sublead_jet_c12_charge_ = chargeVec[i];
                          sublead_jet_c12_pt_ = ptVec[i];
                          sublead_jet_c12_energy_ = energyVec[i];
                        }
                        if(i==12){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c13_eta_ = etaVec[i];
                          sublead_jet_c13_phi_ = phiVec[i];
                          sublead_jet_c13_charge_ = chargeVec[i];
                          sublead_jet_c13_pt_ = ptVec[i];
                          sublead_jet_c13_energy_ = energyVec[i];
                        }
                        if(i==13){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c14_eta_ = etaVec[i];
                          sublead_jet_c14_phi_ = phiVec[i];
                          sublead_jet_c14_charge_ = chargeVec[i];
                          sublead_jet_c14_pt_ = ptVec[i];
                          sublead_jet_c14_energy_ = energyVec[i];
                        }
                        if(i==14){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c15_eta_ = etaVec[i];
                          sublead_jet_c15_phi_ = phiVec[i];
                          sublead_jet_c15_charge_ = chargeVec[i];
                          sublead_jet_c15_pt_ = ptVec[i];
                          sublead_jet_c15_energy_ = energyVec[i];
                        }
                        if(i==15){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c16_eta_ = etaVec[i];
                          sublead_jet_c16_phi_ = phiVec[i];
                          sublead_jet_c16_charge_ = chargeVec[i];
                          sublead_jet_c16_pt_ = ptVec[i];
                          sublead_jet_c16_energy_ = energyVec[i];
                        }
                        if(i==16){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c17_eta_ = etaVec[i];
                          sublead_jet_c17_phi_ = phiVec[i];
                          sublead_jet_c17_charge_ = chargeVec[i];
                          sublead_jet_c17_pt_ = ptVec[i];
                          sublead_jet_c17_energy_ = energyVec[i];
                        }
                        if(i==17){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c18_eta_ = etaVec[i];
                          sublead_jet_c18_phi_ = phiVec[i];
                          sublead_jet_c18_charge_ = chargeVec[i];
                          sublead_jet_c18_pt_ = ptVec[i];
                          sublead_jet_c18_energy_ = energyVec[i];
                        }
                        if(i==18){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c19_eta_ = etaVec[i];
                          sublead_jet_c19_phi_ = phiVec[i];
                          sublead_jet_c19_charge_ = chargeVec[i];
                          sublead_jet_c19_pt_ = ptVec[i];
                          sublead_jet_c19_energy_ = energyVec[i];
                        }
                        if(i==19){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c20_eta_ = etaVec[i];
                          sublead_jet_c20_phi_ = phiVec[i];
                          sublead_jet_c20_charge_ = chargeVec[i];
                          sublead_jet_c20_pt_ = ptVec[i];
                          sublead_jet_c20_energy_ = energyVec[i];
                        }
                        if(i==20){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c21_eta_ = etaVec[i];
                          sublead_jet_c21_phi_ = phiVec[i];
                          sublead_jet_c21_charge_ = chargeVec[i];
                          sublead_jet_c21_pt_ = ptVec[i];
                          sublead_jet_c21_energy_ = energyVec[i];
                        }
                        if(i==21){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c22_eta_ = etaVec[i];
                          sublead_jet_c22_phi_ = phiVec[i];
                          sublead_jet_c22_charge_ = chargeVec[i];
                          sublead_jet_c22_pt_ = ptVec[i];
                          sublead_jet_c22_energy_ = energyVec[i];
                        }
                        if(i==22){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c23_eta_ = etaVec[i];
                          sublead_jet_c23_phi_ = phiVec[i];
                          sublead_jet_c23_charge_ = chargeVec[i];
                          sublead_jet_c23_pt_ = ptVec[i];
                          sublead_jet_c23_energy_ = energyVec[i];
                        }
                        if(i==23){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c24_eta_ = etaVec[i];
                          sublead_jet_c24_phi_ = phiVec[i];
                          sublead_jet_c24_charge_ = chargeVec[i];
                          sublead_jet_c24_pt_ = ptVec[i];
                          sublead_jet_c24_energy_ = energyVec[i];
                        }
                        if(i==24){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c25_eta_ = etaVec[i];
                          sublead_jet_c25_phi_ = phiVec[i];
                          sublead_jet_c25_charge_ = chargeVec[i];
                          sublead_jet_c25_pt_ = ptVec[i];
                          sublead_jet_c25_energy_ = energyVec[i];
                        }
                        if(i==25){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c26_eta_ = etaVec[i];
                          sublead_jet_c26_phi_ = phiVec[i];
                          sublead_jet_c26_charge_ = chargeVec[i];
                          sublead_jet_c26_pt_ = ptVec[i];
                          sublead_jet_c26_energy_ = energyVec[i];
                        }
                        if(i==26){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c27_eta_ = etaVec[i];
                          sublead_jet_c27_phi_ = phiVec[i];
                          sublead_jet_c27_charge_ = chargeVec[i];
                          sublead_jet_c27_pt_ = ptVec[i];
                          sublead_jet_c27_energy_ = energyVec[i];
                        }
                        if(i==27){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c28_eta_ = etaVec[i];
                          sublead_jet_c28_phi_ = phiVec[i];
                          sublead_jet_c28_charge_ = chargeVec[i];
                          sublead_jet_c28_pt_ = ptVec[i];
                          sublead_jet_c28_energy_ = energyVec[i];
                        }
                        if(i==28){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c29_eta_ = etaVec[i];
                          sublead_jet_c29_phi_ = phiVec[i];
                          sublead_jet_c29_charge_ = chargeVec[i];
                          sublead_jet_c29_pt_ = ptVec[i];
                          sublead_jet_c29_energy_ = energyVec[i];
                        }
                        if(i==29){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c30_eta_ = etaVec[i];
                          sublead_jet_c30_phi_ = phiVec[i];
                          sublead_jet_c30_charge_ = chargeVec[i];
                          sublead_jet_c30_pt_ = ptVec[i];
                          sublead_jet_c30_energy_ = energyVec[i];
                        }
                        if(i==30){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c31_eta_ = etaVec[i];
                          sublead_jet_c31_phi_ = phiVec[i];
                          sublead_jet_c31_charge_ = chargeVec[i];
                          sublead_jet_c31_pt_ = ptVec[i];
                          sublead_jet_c31_energy_ = energyVec[i];
                        }
                        if(i==31){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c32_eta_ = etaVec[i];
                          sublead_jet_c32_phi_ = phiVec[i];
                          sublead_jet_c32_charge_ = chargeVec[i];
                          sublead_jet_c32_pt_ = ptVec[i];
                          sublead_jet_c32_energy_ = energyVec[i];
                        }
                        if(i==32){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c33_eta_ = etaVec[i];
                          sublead_jet_c33_phi_ = phiVec[i];
                          sublead_jet_c33_charge_ = chargeVec[i];
                          sublead_jet_c33_pt_ = ptVec[i];
                          sublead_jet_c33_energy_ = energyVec[i];
                        }
                        if(i==33){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c34_eta_ = etaVec[i];
                          sublead_jet_c34_phi_ = phiVec[i];
                          sublead_jet_c34_charge_ = chargeVec[i];
                          sublead_jet_c34_pt_ = ptVec[i];
                          sublead_jet_c34_energy_ = energyVec[i];
                        }
                        if(i==34){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c35_eta_ = etaVec[i];
                          sublead_jet_c35_phi_ = phiVec[i];
                          sublead_jet_c35_charge_ = chargeVec[i];
                          sublead_jet_c35_pt_ = ptVec[i];
                          sublead_jet_c35_energy_ = energyVec[i];
                        }
                        if(i==35){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c36_eta_ = etaVec[i];
                          sublead_jet_c36_phi_ = phiVec[i];
                          sublead_jet_c36_charge_ = chargeVec[i];
                          sublead_jet_c36_pt_ = ptVec[i];
                          sublead_jet_c36_energy_ = energyVec[i];
                        }
                        if(i==36){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c37_eta_ = etaVec[i];
                          sublead_jet_c37_phi_ = phiVec[i];
                          sublead_jet_c37_charge_ = chargeVec[i];
                          sublead_jet_c37_pt_ = ptVec[i];
                          sublead_jet_c37_energy_ = energyVec[i];
                        }
                        if(i==37){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c38_eta_ = etaVec[i];
                          sublead_jet_c38_phi_ = phiVec[i];
                          sublead_jet_c38_charge_ = chargeVec[i];
                          sublead_jet_c38_pt_ = ptVec[i];
                          sublead_jet_c38_energy_ = energyVec[i];
                        }
                        if(i==38){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c39_eta_ = etaVec[i];
                          sublead_jet_c39_phi_ = phiVec[i];
                          sublead_jet_c39_charge_ = chargeVec[i];
                          sublead_jet_c39_pt_ = ptVec[i];
                          sublead_jet_c39_energy_ = energyVec[i];
                        }
                        if(i==39){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c40_eta_ = etaVec[i];
                          sublead_jet_c40_phi_ = phiVec[i];
                          sublead_jet_c40_charge_ = chargeVec[i];
                          sublead_jet_c40_pt_ = ptVec[i];
                          sublead_jet_c40_energy_ = energyVec[i];
                        }
                        if(i==40){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c41_eta_ = etaVec[i];
                          sublead_jet_c41_phi_ = phiVec[i];
                          sublead_jet_c41_charge_ = chargeVec[i];
                          sublead_jet_c41_pt_ = ptVec[i];
                          sublead_jet_c41_energy_ = energyVec[i];
                        }
                        if(i==41){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c42_eta_ = etaVec[i];
                          sublead_jet_c42_phi_ = phiVec[i];
                          sublead_jet_c42_charge_ = chargeVec[i];
                          sublead_jet_c42_pt_ = ptVec[i];
                          sublead_jet_c42_energy_ = energyVec[i];
                        }
                        if(i==42){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c43_eta_ = etaVec[i];
                          sublead_jet_c43_phi_ = phiVec[i];
                          sublead_jet_c43_charge_ = chargeVec[i];
                          sublead_jet_c43_pt_ = ptVec[i];
                          sublead_jet_c43_energy_ = energyVec[i];
                        }
                        if(i==43){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c44_eta_ = etaVec[i];
                          sublead_jet_c44_phi_ = phiVec[i];
                          sublead_jet_c44_charge_ = chargeVec[i];
                          sublead_jet_c44_pt_ = ptVec[i];
                          sublead_jet_c44_energy_ = energyVec[i];
                        }
                        if(i==44){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c45_eta_ = etaVec[i];
                          sublead_jet_c45_phi_ = phiVec[i];
                          sublead_jet_c45_charge_ = chargeVec[i];
                          sublead_jet_c45_pt_ = ptVec[i];
                          sublead_jet_c45_energy_ = energyVec[i];
                        }
                        if(i==45){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c46_eta_ = etaVec[i];
                          sublead_jet_c46_phi_ = phiVec[i];
                          sublead_jet_c46_charge_ = chargeVec[i];
                          sublead_jet_c46_pt_ = ptVec[i];
                          sublead_jet_c46_energy_ = energyVec[i];
                        }
                        if(i==46){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c47_eta_ = etaVec[i];
                          sublead_jet_c47_phi_ = phiVec[i];
                          sublead_jet_c47_charge_ = chargeVec[i];
                          sublead_jet_c47_pt_ = ptVec[i];
                          sublead_jet_c47_energy_ = energyVec[i];
                        }
                        if(i==47){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c48_eta_ = etaVec[i];
                          sublead_jet_c48_phi_ = phiVec[i];
                          sublead_jet_c48_charge_ = chargeVec[i];
                          sublead_jet_c48_pt_ = ptVec[i];
                          sublead_jet_c48_energy_ = energyVec[i];
                        }
                        if(i==48){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c49_eta_ = etaVec[i];
                          sublead_jet_c49_phi_ = phiVec[i];
                          sublead_jet_c49_charge_ = chargeVec[i];
                          sublead_jet_c49_pt_ = ptVec[i];
                          sublead_jet_c49_energy_ = energyVec[i];
                        }
                        if(i==49){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c50_eta_ = etaVec[i];
                          sublead_jet_c50_phi_ = phiVec[i];
                          sublead_jet_c50_charge_ = chargeVec[i];
                          sublead_jet_c50_pt_ = ptVec[i];
                          sublead_jet_c50_energy_ = energyVec[i];
                        }
                        if(i==50){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c51_eta_ = etaVec[i];
                          sublead_jet_c51_phi_ = phiVec[i];
                          sublead_jet_c51_charge_ = chargeVec[i];
                          sublead_jet_c51_pt_ = ptVec[i];
                          sublead_jet_c51_energy_ = energyVec[i];
                        }
                        if(i==51){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c52_eta_ = etaVec[i];
                          sublead_jet_c52_phi_ = phiVec[i];
                          sublead_jet_c52_charge_ = chargeVec[i];
                          sublead_jet_c52_pt_ = ptVec[i];
                          sublead_jet_c52_energy_ = energyVec[i];
                        }
                        if(i==52){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c53_eta_ = etaVec[i];
                          sublead_jet_c53_phi_ = phiVec[i];
                          sublead_jet_c53_charge_ = chargeVec[i];
                          sublead_jet_c53_pt_ = ptVec[i];
                          sublead_jet_c53_energy_ = energyVec[i];
                        }
                        if(i==53){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c54_eta_ = etaVec[i];
                          sublead_jet_c54_phi_ = phiVec[i];
                          sublead_jet_c54_charge_ = chargeVec[i];
                          sublead_jet_c54_pt_ = ptVec[i];
                          sublead_jet_c54_energy_ = energyVec[i];
                        }
                        if(i==54){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c55_eta_ = etaVec[i];
                          sublead_jet_c55_phi_ = phiVec[i];
                          sublead_jet_c55_charge_ = chargeVec[i];
                          sublead_jet_c55_pt_ = ptVec[i];
                          sublead_jet_c55_energy_ = energyVec[i];
                        }
                        if(i==55){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c56_eta_ = etaVec[i];
                          sublead_jet_c56_phi_ = phiVec[i];
                          sublead_jet_c56_charge_ = chargeVec[i];
                          sublead_jet_c56_pt_ = ptVec[i];
                          sublead_jet_c56_energy_ = energyVec[i];
                        }
                        if(i==56){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c57_eta_ = etaVec[i];
                          sublead_jet_c57_phi_ = phiVec[i];
                          sublead_jet_c57_charge_ = chargeVec[i];
                          sublead_jet_c57_pt_ = ptVec[i];
                          sublead_jet_c57_energy_ = energyVec[i];
                        }
                        if(i==57){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c58_eta_ = etaVec[i];
                          sublead_jet_c58_phi_ = phiVec[i];
                          sublead_jet_c58_charge_ = chargeVec[i];
                          sublead_jet_c58_pt_ = ptVec[i];
                          sublead_jet_c58_energy_ = energyVec[i];
                        }
                        if(i==58){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c59_eta_ = etaVec[i];
                          sublead_jet_c59_phi_ = phiVec[i];
                          sublead_jet_c59_charge_ = chargeVec[i];
                          sublead_jet_c59_pt_ = ptVec[i];
                          sublead_jet_c59_energy_ = energyVec[i];
                        }
                        if(i==59){
                          //fill lead jet constit 8
                          //std::cout << "filled sub lead constit 8" << std::endl;
                          sublead_jet_c60_eta_ = etaVec[i];
                          sublead_jet_c60_phi_ = phiVec[i];
                          sublead_jet_c60_charge_ = chargeVec[i];
                          sublead_jet_c60_pt_ = ptVec[i];
                          sublead_jet_c60_energy_ = energyVec[i];
                        }
                      } 
                    }
                    if(n_jets_count==3){//subleading jet since pts are ordered
                      for(unsigned int i = 0; i< nConstituents ; i++){
                        //std::cout << "the counter inside sub sub lead jet loop is at: " << i << std::endl;
                        if(i==0){
                          //fill lead jet constit 1
                          //std::cout << "filled sub sub lead constit 1" << std::endl;
                          subsublead_jet_c1_eta_ = etaVec[i];
                          subsublead_jet_c1_phi_ = phiVec[i];
                          subsublead_jet_c1_charge_ = chargeVec[i];
                          subsublead_jet_c1_pt_ = ptVec[i];
                          subsublead_jet_c1_energy_ = energyVec[i];
                          }
                        if(i==1){
                          //fill lead jet constit 2
                          //std::cout << "filled sub sub lead constit 2" << std::endl;
                          subsublead_jet_c2_eta_ = etaVec[i];
                          subsublead_jet_c2_phi_ = phiVec[i];
                          subsublead_jet_c2_charge_ = chargeVec[i];
                          subsublead_jet_c2_pt_ = ptVec[i];
                          subsublead_jet_c2_energy_ = energyVec[i];
                          }
                        if(i==2){
                          //fill lead jet constit 3
                          //std::cout << "filled sub sub lead constit 3" << std::endl;
                          subsublead_jet_c3_eta_ = etaVec[i];
                          subsublead_jet_c3_phi_ = phiVec[i];
                          subsublead_jet_c3_charge_ = chargeVec[i];
                          subsublead_jet_c3_pt_ = ptVec[i];
                          subsublead_jet_c3_energy_ = energyVec[i];
                          }
                        if(i==3){
                          //fill lead jet constit 4
                          //std::cout << "filled sub sub lead constit 4" << std::endl;
                          subsublead_jet_c4_eta_ = etaVec[i];
                          subsublead_jet_c4_phi_ = phiVec[i];
                          subsublead_jet_c4_charge_ = chargeVec[i];
                          subsublead_jet_c4_pt_ = ptVec[i];
                          subsublead_jet_c4_energy_ = energyVec[i];
                          }
                        if(i==4){
                          //fill lead jet constit 5
                          //std::cout << "filled sub sub lead constit 5" << std::endl;
                          subsublead_jet_c5_eta_ = etaVec[i];
                          subsublead_jet_c5_phi_ = phiVec[i];
                          subsublead_jet_c5_charge_ = chargeVec[i];
                          subsublead_jet_c5_pt_ = ptVec[i];
                          subsublead_jet_c5_energy_ = energyVec[i];
                          }
                        if(i==5){
                          //fill lead jet constit 6
                          //std::cout << "filled sub sub lead constit 6" << std::endl;
                          subsublead_jet_c6_eta_ = etaVec[i];
                          subsublead_jet_c6_phi_ = phiVec[i];
                          subsublead_jet_c6_charge_ = chargeVec[i];
                          subsublead_jet_c6_pt_ = ptVec[i];
                          subsublead_jet_c6_energy_ = energyVec[i];
                          }
                        if(i==6){
                          //fill lead jet constit 7
                          //std::cout << "filled sub sub lead constit 7" << std::endl;
                          subsublead_jet_c7_eta_ = etaVec[i];
                          subsublead_jet_c7_phi_ = phiVec[i];
                          subsublead_jet_c7_charge_ = chargeVec[i];
                          subsublead_jet_c7_pt_ = ptVec[i];
                          subsublead_jet_c7_energy_ = energyVec[i];
                          }
                        if(i==7){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c8_eta_ = etaVec[i];
                          subsublead_jet_c8_phi_ = phiVec[i];
                          subsublead_jet_c8_charge_ = chargeVec[i];
                          subsublead_jet_c8_pt_ = ptVec[i];
                          subsublead_jet_c8_energy_ = energyVec[i];
                          }
                        if(i==8){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c9_eta_ = etaVec[i];
                          subsublead_jet_c9_phi_ = phiVec[i];
                          subsublead_jet_c9_charge_ = chargeVec[i];
                          subsublead_jet_c9_pt_ = ptVec[i];
                          subsublead_jet_c9_energy_ = energyVec[i];
                          }
                        if(i==9){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c10_eta_ = etaVec[i];
                          subsublead_jet_c10_phi_ = phiVec[i];
                          subsublead_jet_c10_charge_ = chargeVec[i];
                          subsublead_jet_c10_pt_ = ptVec[i];
                          subsublead_jet_c10_energy_ = energyVec[i];
                          }
                        if(i==10){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c11_eta_ = etaVec[i];
                          subsublead_jet_c11_phi_ = phiVec[i];
                          subsublead_jet_c11_charge_ = chargeVec[i];
                          subsublead_jet_c11_pt_ = ptVec[i];
                          subsublead_jet_c11_energy_ = energyVec[i];
                          }
                        if(i==11){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c12_eta_ = etaVec[i];
                          subsublead_jet_c12_phi_ = phiVec[i];
                          subsublead_jet_c12_charge_ = chargeVec[i];
                          subsublead_jet_c12_pt_ = ptVec[i];
                          subsublead_jet_c12_energy_ = energyVec[i];
                          }
                        if(i==12){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c13_eta_ = etaVec[i];
                          subsublead_jet_c13_phi_ = phiVec[i];
                          subsublead_jet_c13_charge_ = chargeVec[i];
                          subsublead_jet_c13_pt_ = ptVec[i];
                          subsublead_jet_c13_energy_ = energyVec[i];
                          }
                        if(i==13){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c14_eta_ = etaVec[i];
                          subsublead_jet_c14_phi_ = phiVec[i];
                          subsublead_jet_c14_charge_ = chargeVec[i];
                          subsublead_jet_c14_pt_ = ptVec[i];
                          subsublead_jet_c14_energy_ = energyVec[i];
                          }
                        if(i==14){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c15_eta_ = etaVec[i];
                          subsublead_jet_c15_phi_ = phiVec[i];
                          subsublead_jet_c15_charge_ = chargeVec[i];
                          subsublead_jet_c15_pt_ = ptVec[i];
                          subsublead_jet_c15_energy_ = energyVec[i];
                          }
                        if(i==15){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c16_eta_ = etaVec[i];
                          subsublead_jet_c16_phi_ = phiVec[i];
                          subsublead_jet_c16_charge_ = chargeVec[i];
                          subsublead_jet_c16_pt_ = ptVec[i];
                          subsublead_jet_c16_energy_ = energyVec[i];
                          }
                        if(i==16){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c17_eta_ = etaVec[i];
                          subsublead_jet_c17_phi_ = phiVec[i];
                          subsublead_jet_c17_charge_ = chargeVec[i];
                          subsublead_jet_c17_pt_ = ptVec[i];
                          subsublead_jet_c17_energy_ = energyVec[i];
                          }
                        if(i==17){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c18_eta_ = etaVec[i];
                          subsublead_jet_c18_phi_ = phiVec[i];
                          subsublead_jet_c18_charge_ = chargeVec[i];
                          subsublead_jet_c18_pt_ = ptVec[i];
                          subsublead_jet_c18_energy_ = energyVec[i];
                          }
                        if(i==18){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c19_eta_ = etaVec[i];
                          subsublead_jet_c19_phi_ = phiVec[i];
                          subsublead_jet_c19_charge_ = chargeVec[i];
                          subsublead_jet_c19_pt_ = ptVec[i];
                          subsublead_jet_c19_energy_ = energyVec[i];
                          }
                        if(i==19){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c20_eta_ = etaVec[i];
                          subsublead_jet_c20_phi_ = phiVec[i];
                          subsublead_jet_c20_charge_ = chargeVec[i];
                          subsublead_jet_c20_pt_ = ptVec[i];
                          subsublead_jet_c20_energy_ = energyVec[i];
                          }
                        if(i==20){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c21_eta_ = etaVec[i];
                          subsublead_jet_c21_phi_ = phiVec[i];
                          subsublead_jet_c21_charge_ = chargeVec[i];
                          subsublead_jet_c21_pt_ = ptVec[i];
                          subsublead_jet_c21_energy_ = energyVec[i];
                          }
                        if(i==21){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c22_eta_ = etaVec[i];
                          subsublead_jet_c22_phi_ = phiVec[i];
                          subsublead_jet_c22_charge_ = chargeVec[i];
                          subsublead_jet_c22_pt_ = ptVec[i];
                          subsublead_jet_c22_energy_ = energyVec[i];
                          }
                        if(i==22){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c23_eta_ = etaVec[i];
                          subsublead_jet_c23_phi_ = phiVec[i];
                          subsublead_jet_c23_charge_ = chargeVec[i];
                          subsublead_jet_c23_pt_ = ptVec[i];
                          subsublead_jet_c23_energy_ = energyVec[i];
                          }
                        if(i==23){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c24_eta_ = etaVec[i];
                          subsublead_jet_c24_phi_ = phiVec[i];
                          subsublead_jet_c24_charge_ = chargeVec[i];
                          subsublead_jet_c24_pt_ = ptVec[i];
                          subsublead_jet_c24_energy_ = energyVec[i];
                          }
                        if(i==24){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c25_eta_ = etaVec[i];
                          subsublead_jet_c25_phi_ = phiVec[i];
                          subsublead_jet_c25_charge_ = chargeVec[i];
                          subsublead_jet_c25_pt_ = ptVec[i];
                          subsublead_jet_c25_energy_ = energyVec[i];
                          }
                        if(i==25){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c26_eta_ = etaVec[i];
                          subsublead_jet_c26_phi_ = phiVec[i];
                          subsublead_jet_c26_charge_ = chargeVec[i];
                          subsublead_jet_c26_pt_ = ptVec[i];
                          subsublead_jet_c26_energy_ = energyVec[i];
                          }
                        if(i==26){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c27_eta_ = etaVec[i];
                          subsublead_jet_c27_phi_ = phiVec[i];
                          subsublead_jet_c27_charge_ = chargeVec[i];
                          subsublead_jet_c27_pt_ = ptVec[i];
                          subsublead_jet_c27_energy_ = energyVec[i];
                          }
                        if(i==27){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c28_eta_ = etaVec[i];
                          subsublead_jet_c28_phi_ = phiVec[i];
                          subsublead_jet_c28_charge_ = chargeVec[i];
                          subsublead_jet_c28_pt_ = ptVec[i];
                          subsublead_jet_c28_energy_ = energyVec[i];
                          }
                        if(i==28){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c29_eta_ = etaVec[i];
                          subsublead_jet_c29_phi_ = phiVec[i];
                          subsublead_jet_c29_charge_ = chargeVec[i];
                          subsublead_jet_c29_pt_ = ptVec[i];
                          subsublead_jet_c29_energy_ = energyVec[i];
                          }
                        if(i==29){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c30_eta_ = etaVec[i];
                          subsublead_jet_c30_phi_ = phiVec[i];
                          subsublead_jet_c30_charge_ = chargeVec[i];
                          subsublead_jet_c30_pt_ = ptVec[i];
                          subsublead_jet_c30_energy_ = energyVec[i];
                          }
                        if(i==30){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c31_eta_ = etaVec[i];
                          subsublead_jet_c31_phi_ = phiVec[i];
                          subsublead_jet_c31_charge_ = chargeVec[i];
                          subsublead_jet_c31_pt_ = ptVec[i];
                          subsublead_jet_c31_energy_ = energyVec[i];
                          }
                        if(i==31){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c32_eta_ = etaVec[i];
                          subsublead_jet_c32_phi_ = phiVec[i];
                          subsublead_jet_c32_charge_ = chargeVec[i];
                          subsublead_jet_c32_pt_ = ptVec[i];
                          subsublead_jet_c32_energy_ = energyVec[i];
                          }
                        if(i==32){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c33_eta_ = etaVec[i];
                          subsublead_jet_c33_phi_ = phiVec[i];
                          subsublead_jet_c33_charge_ = chargeVec[i];
                          subsublead_jet_c33_pt_ = ptVec[i];
                          subsublead_jet_c33_energy_ = energyVec[i];
                          }
                        if(i==33){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c34_eta_ = etaVec[i];
                          subsublead_jet_c34_phi_ = phiVec[i];
                          subsublead_jet_c34_charge_ = chargeVec[i];
                          subsublead_jet_c34_pt_ = ptVec[i];
                          subsublead_jet_c34_energy_ = energyVec[i];
                          }
                        if(i==34){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c35_eta_ = etaVec[i];
                          subsublead_jet_c35_phi_ = phiVec[i];
                          subsublead_jet_c35_charge_ = chargeVec[i];
                          subsublead_jet_c35_pt_ = ptVec[i];
                          subsublead_jet_c35_energy_ = energyVec[i];
                          }
                        if(i==35){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c36_eta_ = etaVec[i];
                          subsublead_jet_c36_phi_ = phiVec[i];
                          subsublead_jet_c36_charge_ = chargeVec[i];
                          subsublead_jet_c36_pt_ = ptVec[i];
                          subsublead_jet_c36_energy_ = energyVec[i];
                          }
                        if(i==36){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c37_eta_ = etaVec[i];
                          subsublead_jet_c37_phi_ = phiVec[i];
                          subsublead_jet_c37_charge_ = chargeVec[i];
                          subsublead_jet_c37_pt_ = ptVec[i];
                          subsublead_jet_c37_energy_ = energyVec[i];
                          }
                        if(i==37){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c38_eta_ = etaVec[i];
                          subsublead_jet_c38_phi_ = phiVec[i];
                          subsublead_jet_c38_charge_ = chargeVec[i];
                          subsublead_jet_c38_pt_ = ptVec[i];
                          subsublead_jet_c38_energy_ = energyVec[i];
                          }
                        if(i==38){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c39_eta_ = etaVec[i];
                          subsublead_jet_c39_phi_ = phiVec[i];
                          subsublead_jet_c39_charge_ = chargeVec[i];
                          subsublead_jet_c39_pt_ = ptVec[i];
                          subsublead_jet_c39_energy_ = energyVec[i];
                          }
                        if(i==39){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c40_eta_ = etaVec[i];
                          subsublead_jet_c40_phi_ = phiVec[i];
                          subsublead_jet_c40_charge_ = chargeVec[i];
                          subsublead_jet_c40_pt_ = ptVec[i];
                          subsublead_jet_c40_energy_ = energyVec[i];
                          }
                        if(i==40){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c41_eta_ = etaVec[i];
                          subsublead_jet_c41_phi_ = phiVec[i];
                          subsublead_jet_c41_charge_ = chargeVec[i];
                          subsublead_jet_c41_pt_ = ptVec[i];
                          subsublead_jet_c41_energy_ = energyVec[i];
                          }
                        if(i==41){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c42_eta_ = etaVec[i];
                          subsublead_jet_c42_phi_ = phiVec[i];
                          subsublead_jet_c42_charge_ = chargeVec[i];
                          subsublead_jet_c42_pt_ = ptVec[i];
                          subsublead_jet_c42_energy_ = energyVec[i];
                          }
                        if(i==42){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c43_eta_ = etaVec[i];
                          subsublead_jet_c43_phi_ = phiVec[i];
                          subsublead_jet_c43_charge_ = chargeVec[i];
                          subsublead_jet_c43_pt_ = ptVec[i];
                          subsublead_jet_c43_energy_ = energyVec[i];
                          }
                        if(i==43){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c44_eta_ = etaVec[i];
                          subsublead_jet_c44_phi_ = phiVec[i];
                          subsublead_jet_c44_charge_ = chargeVec[i];
                          subsublead_jet_c44_pt_ = ptVec[i];
                          subsublead_jet_c44_energy_ = energyVec[i];
                          }
                        if(i==44){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c45_eta_ = etaVec[i];
                          subsublead_jet_c45_phi_ = phiVec[i];
                          subsublead_jet_c45_charge_ = chargeVec[i];
                          subsublead_jet_c45_pt_ = ptVec[i];
                          subsublead_jet_c45_energy_ = energyVec[i];
                          }
                        if(i==45){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c46_eta_ = etaVec[i];
                          subsublead_jet_c46_phi_ = phiVec[i];
                          subsublead_jet_c46_charge_ = chargeVec[i];
                          subsublead_jet_c46_pt_ = ptVec[i];
                          subsublead_jet_c46_energy_ = energyVec[i];
                          }
                        if(i==46){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c47_eta_ = etaVec[i];
                          subsublead_jet_c47_phi_ = phiVec[i];
                          subsublead_jet_c47_charge_ = chargeVec[i];
                          subsublead_jet_c47_pt_ = ptVec[i];
                          subsublead_jet_c47_energy_ = energyVec[i];
                          }
                        if(i==47){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c48_eta_ = etaVec[i];
                          subsublead_jet_c48_phi_ = phiVec[i];
                          subsublead_jet_c48_charge_ = chargeVec[i];
                          subsublead_jet_c48_pt_ = ptVec[i];
                          subsublead_jet_c48_energy_ = energyVec[i];
                          }
                        if(i==48){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c49_eta_ = etaVec[i];
                          subsublead_jet_c49_phi_ = phiVec[i];
                          subsublead_jet_c49_charge_ = chargeVec[i];
                          subsublead_jet_c49_pt_ = ptVec[i];
                          subsublead_jet_c49_energy_ = energyVec[i];
                          }
                        if(i==49){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c50_eta_ = etaVec[i];
                          subsublead_jet_c50_phi_ = phiVec[i];
                          subsublead_jet_c50_charge_ = chargeVec[i];
                          subsublead_jet_c50_pt_ = ptVec[i];
                          subsublead_jet_c50_energy_ = energyVec[i];
                          }
                        if(i==50){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c51_eta_ = etaVec[i];
                          subsublead_jet_c51_phi_ = phiVec[i];
                          subsublead_jet_c51_charge_ = chargeVec[i];
                          subsublead_jet_c51_pt_ = ptVec[i];
                          subsublead_jet_c51_energy_ = energyVec[i];
                          }
                        if(i==51){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c52_eta_ = etaVec[i];
                          subsublead_jet_c52_phi_ = phiVec[i];
                          subsublead_jet_c52_charge_ = chargeVec[i];
                          subsublead_jet_c52_pt_ = ptVec[i];
                          subsublead_jet_c52_energy_ = energyVec[i];
                          }
                        if(i==52){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c53_eta_ = etaVec[i];
                          subsublead_jet_c53_phi_ = phiVec[i];
                          subsublead_jet_c53_charge_ = chargeVec[i];
                          subsublead_jet_c53_pt_ = ptVec[i];
                          subsublead_jet_c53_energy_ = energyVec[i];
                          }
                        if(i==53){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c54_eta_ = etaVec[i];
                          subsublead_jet_c54_phi_ = phiVec[i];
                          subsublead_jet_c54_charge_ = chargeVec[i];
                          subsublead_jet_c54_pt_ = ptVec[i];
                          subsublead_jet_c54_energy_ = energyVec[i];
                          }
                        if(i==54){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c55_eta_ = etaVec[i];
                          subsublead_jet_c55_phi_ = phiVec[i];
                          subsublead_jet_c55_charge_ = chargeVec[i];
                          subsublead_jet_c55_pt_ = ptVec[i];
                          subsublead_jet_c55_energy_ = energyVec[i];
                          }
                        if(i==55){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c56_eta_ = etaVec[i];
                          subsublead_jet_c56_phi_ = phiVec[i];
                          subsublead_jet_c56_charge_ = chargeVec[i];
                          subsublead_jet_c56_pt_ = ptVec[i];
                          subsublead_jet_c56_energy_ = energyVec[i];
                          }
                        if(i==56){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c57_eta_ = etaVec[i];
                          subsublead_jet_c57_phi_ = phiVec[i];
                          subsublead_jet_c57_charge_ = chargeVec[i];
                          subsublead_jet_c57_pt_ = ptVec[i];
                          subsublead_jet_c57_energy_ = energyVec[i];
                          }
                        if(i==57){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c58_eta_ = etaVec[i];
                          subsublead_jet_c58_phi_ = phiVec[i];
                          subsublead_jet_c58_charge_ = chargeVec[i];
                          subsublead_jet_c58_pt_ = ptVec[i];
                          subsublead_jet_c58_energy_ = energyVec[i];
                          }
                        if(i==58){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c59_eta_ = etaVec[i];
                          subsublead_jet_c59_phi_ = phiVec[i];
                          subsublead_jet_c59_charge_ = chargeVec[i];
                          subsublead_jet_c59_pt_ = ptVec[i];
                          subsublead_jet_c59_energy_ = energyVec[i];
                          }
                        if(i==59){
                          //fill lead jet constit 8
                          //std::cout << "filled sub sub lead constit 8" << std::endl;
                          subsublead_jet_c60_eta_ = etaVec[i];
                          subsublead_jet_c60_phi_ = phiVec[i];
                          subsublead_jet_c60_charge_ = chargeVec[i];
                          subsublead_jet_c60_pt_ = ptVec[i];
                          subsublead_jet_c60_energy_ = energyVec[i];
                          }
                        }
                      } 
                    
                  }
                }
                // if the jet's pt is neither higher than the lead jet or sublead jet, then forget it!
                if( dijet_indices.first != -1 && dijet_indices.second != -1 ) {hasValidVBFDiJet  = 1;}
                if( hasValidVBFDiJet          && jet_3_index != -1          ) {hasValidVBFTriJet = 1;}
            }
         
            //std::cout << "end of jet" << std::endl;     

            //Third jet deltaR cut and merge index finding
            int indexToMergeWithJ3(-1);
            //float thirdJetDRCut(1.8);

            //Getting the P4s
            std::vector<reco::Candidate::LorentzVector> diPhotonP4s(2);
            std::vector<reco::Candidate::LorentzVector> jetP4s;

            diPhotonP4s[0] = diPhotons->ptrAt( candIndex )->leadingPhoton()->p4(); 
            diPhotonP4s[1] = diPhotons->ptrAt( candIndex )->subLeadingPhoton()->p4(); 
            if ( hasValidVBFDiJet ) {
                jetP4s.push_back(Jets[jetCollectionIndex]->ptrAt(dijet_indices.first)->p4());
                jetP4s.push_back(Jets[jetCollectionIndex]->ptrAt(dijet_indices.second)->p4());
            }
            if ( hasValidVBFTriJet ) {
                
                jetP4s.push_back(Jets[jetCollectionIndex]->ptrAt(jet_3_index)->p4());

                float dR_13 = deltaR(jetP4s[0].eta(),jetP4s[0].phi(),jetP4s[2].eta(),jetP4s[2].phi());
                float dR_23 = deltaR(jetP4s[1].eta(),jetP4s[1].phi(),jetP4s[2].eta(),jetP4s[2].phi());
                
                if (dR_13 < dR_23) {
                    indexToMergeWithJ3 = dR_13 < _thirdJetDRCut ? 0 : -1;
                }else{
                    indexToMergeWithJ3 = dR_23 < _thirdJetDRCut ? 1 : -1;
                }

                if (dR_13 > _thirdJetDRCut && dR_23 > _thirdJetDRCut) {
                    hasValidVBFTriJet = 0;
                }
                
                //std::cout << "Third jet merge info:" << std::endl;
                //std::cout << setw(12) << dR_13 << setw(12) << dR_23 << setw(12) << indexToMergeWithJ3 << std::endl;
            }
           
            if( hasValidVBFDiJet ) {
                std::pair<reco::Candidate::LorentzVector,reco::Candidate::LorentzVector> dijetP4s;
                
                //std ::cout << "-->before  jet_1 pt:" << jetP4s[0].pt() << std::endl;
                //std ::cout << "-->before  jet_2 pt:" << jetP4s[1].pt() << std::endl;
                if (indexToMergeWithJ3 != -1 && _merge3rdJet ) {
                    //std::cout << "Hey I am merging jets : " << indexToMergeWithJ3+1 << " with jet 3" << std::endl;    
                    dijetP4s.first  = jetP4s[ indexToMergeWithJ3 == 0 ? 1 : 0 ];
                    dijetP4s.second = jetP4s[ indexToMergeWithJ3 ] + jetP4s[2];                 
                    if (dijetP4s.second.pt() > dijetP4s.first.pt()) { std::swap(dijetP4s.first, dijetP4s.second);}
                }else{
                    dijetP4s.first  = jetP4s[0];
                    dijetP4s.second = jetP4s[1];
                }
                
                //std ::cout << "-->after  jet_1 pt:" << dijetP4s.first.pt()  << std::endl;
                //std ::cout << "-->after  jet_2 pt:" << dijetP4s.second.pt() << std::endl;
                
                dijet_leadEta_    = dijetP4s.first.eta();
                dijet_subleadEta_ = dijetP4s.second.eta();
                
                dijet_abs_dEta_   = fabs( dijetP4s.first.eta() - dijetP4s.second.eta());
                
                dijet_LeadJPt_    = dijetP4s.first.pt();
                dijet_pt_    = (dijetP4s.first + dijetP4s.second).pt();
                dijet_SubJPt_     = dijetP4s.second.pt();
                
                dijet_dipho_dphi_ = fabs(reco::deltaPhi((dijetP4s.first + dijetP4s.second).phi(),(diPhotonP4s[0] + diPhotonP4s[1]).phi()));
                dijet_dphi_trunc_ = std::min((float) dijet_dipho_dphi_, (float) 2.9416);
                dijet_dphi_       = fabs(reco::deltaPhi(dijetP4s.first.phi(),dijetP4s.second.phi()));
                
                dijet_dipho_pt_   = (dijetP4s.first + dijetP4s.second + diPhotonP4s[0] + diPhotonP4s[1]).pt(); 
                
                dijet_Zep_           = fabs( (diPhotonP4s[0]+diPhotonP4s[1]).eta() - 0.5*(dijetP4s.first.eta()+dijetP4s.second.eta()) );
                dijet_centrality_gg_ = exp(-4*pow(dijet_Zep_/dijet_leadEta_,2));
                dijet_centrality_g_  = exp(-4*pow(fabs( diPhotonP4s[0].eta() - 0.5*(dijetP4s.first.eta()+dijetP4s.second.eta()) )/dijet_leadEta_,2));
                dijet_Mjj_           = (dijetP4s.first + dijetP4s.second).M();

                TLorentzVector diphoDijetSystem;
                diphoDijetSystem.SetPxPyPzE( (diPhotonP4s[0] + diPhotonP4s[1] + dijetP4s.first + dijetP4s.second).Px(), 
                                             (diPhotonP4s[0] + diPhotonP4s[1] + dijetP4s.first + dijetP4s.second).Py(),
                                             (diPhotonP4s[0] + diPhotonP4s[1] + dijetP4s.first + dijetP4s.second).Pz(),
                                             (diPhotonP4s[0] + diPhotonP4s[1] + dijetP4s.first + dijetP4s.second).E() );
                TLorentzVector diphoSystem; 
                diphoSystem.SetPxPyPzE( (diPhotonP4s[0] + diPhotonP4s[1]).Px(),
                                        (diPhotonP4s[0] + diPhotonP4s[1]).Py(),
                                        (diPhotonP4s[0] + diPhotonP4s[1]).Pz(),
                                        (diPhotonP4s[0] + diPhotonP4s[1]).E() );
                //std::cout << "Dipho system pt, eta, phi = " << diphoSystem.Pt() << ", " << diphoSystem.Eta() << ", " << diphoSystem.Phi() << std::endl;
                //std::cout << "DiphoDijet system pt, eta, phi = " << diphoDijetSystem.Pt() << ", " << diphoDijetSystem.Eta() << ", " << diphoDijetSystem.Phi() << std::endl;
                diphoSystem.Boost( -diphoDijetSystem.BoostVector() );
                //std::cout << "DiphoDijet system pt, eta, phi = " << diphoDijetSystem.Pt() << ", " << diphoDijetSystem.Eta() << ", " << diphoDijetSystem.Phi() << std::endl;
                cosThetaStar_ = -1. * diphoSystem.CosTheta();
                //std::cout << "Dipho system cos theta star" << cosThetaStar_ << std::endl;

                dipho_PToM_       = (diPhotonP4s[0] + diPhotonP4s[1]).Pt()/(diPhotonP4s[0] + diPhotonP4s[1]).M();
                leadPho_PToM_     = diPhotonP4s[0].pt()/(diPhotonP4s[0] + diPhotonP4s[1]).M();
                sublPho_PToM_     = diPhotonP4s[1].pt()/(diPhotonP4s[0] + diPhotonP4s[1]).M();
                
                dijet_minDRJetPho_ = std::min( std::min(deltaR( dijetP4s.first ,diPhotonP4s[0] ),
                                                        deltaR( dijetP4s.second,diPhotonP4s[0] )),
                                               std::min(deltaR( dijetP4s.first ,diPhotonP4s[1] ),
                                                        deltaR( dijetP4s.second,diPhotonP4s[1] ))        
                                              );
                
                dijet_dy_         = fabs( (dijetP4s.first + dijetP4s.second).Rapidity() - (diPhotonP4s[0] + diPhotonP4s[1]).Rapidity() );
                
                dijet_leady_      = dijetP4s.first.Rapidity();
                
                dijet_subleady_   = dijetP4s.second.Rapidity();
                
                //mvares.leadJet    = *Jets[jetCollectionIndex]->ptrAt( dijet_indices.first );
                //mvares.subleadJet = *Jets[jetCollectionIndex]->ptrAt( dijet_indices.second );
                mvares.leadJet        = dijetP4s.first;
                mvares.subleadJet     = dijetP4s.second;
                
                mvares.leadJet_ptr    = Jets[jetCollectionIndex]->ptrAt( dijet_indices.first );
                mvares.subleadJet_ptr = Jets[jetCollectionIndex]->ptrAt( dijet_indices.second );
                //mvares.diphoton       = *diPhotons->ptrAt( candIndex );
            } else if (dijet_indices.first != -1) {
                mvares.leadJet_ptr    = Jets[jetCollectionIndex]->ptrAt( dijet_indices.first );
                mvares.subleadJet_ptr = edm::Ptr<flashgg::Jet>();
                dijet_leadEta_         = Jets[jetCollectionIndex]->ptrAt( dijet_indices.first )->eta();
                dijet_LeadJPt_         = Jets[jetCollectionIndex]->ptrAt( dijet_indices.first )->pt();
            } else {
                mvares.leadJet_ptr    = edm::Ptr<flashgg::Jet>();
                mvares.subleadJet_ptr = edm::Ptr<flashgg::Jet>();
            }
            
            if ( hasValidVBFDiJet && hasValidVBFTriJet){
                //mvares.subsubleadJet     = *Jets[jetCollectionIndex]->ptrAt( jet_3_index );
                mvares.subsubleadJet     = Jets[jetCollectionIndex]->ptrAt( jet_3_index )->p4();
                mvares.subsubleadJet_ptr = Jets[jetCollectionIndex]->ptrAt( jet_3_index );
                mvares.hasValidVBFTriJet = 1;
            }else{
                mvares.subsubleadJet_ptr =  edm::Ptr<flashgg::Jet>();
            }
            

            if (_MVAMethod == "") {
                mvares.vbfMvaResult_value = VbfMva_->EvaluateMVA( _MVAMethod.c_str() );
                //mvares.vbfMvaResult_value = VbfMva_->GetProba( _MVAMethod.c_str() );
            }
            else if (_MVAMethod == "Multi") {                            
                mvares.vbfMvaResult_prob_bkg = VbfMva_->EvaluateMulticlass( 0, _MVAMethod.c_str() );
                mvares.vbfMvaResult_prob_ggH = VbfMva_->EvaluateMulticlass( 1, _MVAMethod.c_str() );
                mvares.vbfMvaResult_prob_VBF = VbfMva_->EvaluateMulticlass( 2, _MVAMethod.c_str() );
            }
            //std::cout << "VBFMVA probs are: " << std::endl;
            std::cout << "prob Bkg: " << VbfMva_->EvaluateMulticlass( 0, _MVAMethod.c_str() ) << std::endl;
            std::cout << "Prob ggH: " << VbfMva_->EvaluateMulticlass( 1, _MVAMethod.c_str() ) << std::endl;
            std::cout << "Prob VBF: " << VbfMva_->EvaluateMulticlass( 2, _MVAMethod.c_str() ) << std::endl;
            //
            //std::cout << "leadPhoPToM: " << leadPho_PToM_       << std::endl;  
            //std::cout << "subleadPhoPToM: " << sublPho_PToM_       << std::endl;
            //std::cout << "lead jet pt: " << dijet_LeadJPt_      << std::endl;
            //std::cout << "sublead jet pt: " << dijet_SubJPt_       << std::endl;
            //std::cout << "dijet dEta: " << dijet_abs_dEta_     << std::endl;
            //std::cout << "Mjj: " << dijet_Mjj_          << std::endl;
            //std::cout << "dijet centrality: " << dijet_centrality_gg_ << std::endl;
            //std::cout << "dijet diphi: " << dijet_dphi_         << std::endl;
            //std::cout << "min DR Jet Pho: " << dijet_minDRJetPho_  << std::endl;
            //std::cout << "dijet dphi trunc: " << dijet_dphi_trunc_   << std::endl;
            //std::cout << "" << std::endl;

            mvares.dijet_leadEta     = dijet_leadEta_ ;
            mvares.dijet_subleadEta  = dijet_subleadEta_ ;
            mvares.dijet_abs_dEta    = dijet_abs_dEta_ ;
            mvares.dijet_LeadJPt     = dijet_LeadJPt_ ;
            mvares.dijet_pt          = dijet_pt_ ;
            mvares.dijet_SubJPt      = dijet_SubJPt_ ;
            mvares.dijet_Zep         = dijet_Zep_ ;
            mvares.dijet_centrality_gg = dijet_centrality_gg_ ;
            mvares.dijet_centrality_g  = dijet_centrality_g_ ;
            mvares.dijet_dphi_trunc  = dijet_dphi_trunc_ ;
            mvares.dijet_dphi        = dijet_dphi_ ;
            mvares.dijet_dipho_dphi  = dijet_dipho_dphi_ ;
            mvares.dijet_Mjj         = dijet_Mjj_ ;
            mvares.n_rec_jets        = n_jets_count;
            mvares.cosThetaStar      = cosThetaStar_ ;
            mvares.constit_energy    = constit_energy_ ;

            mvares.pt_J1             = pt_J1_ ;
            mvares.eta_J1            = eta_J1_;
            mvares.phi_J1            = phi_J1_ ;
            mvares.charge_J1         = charge_J1_ ;
            mvares.energy_J1         = energy_J1_ ;
            mvares.flav_J1           = flav_J1_ ;

            mvares.pt_J2             = pt_J2_ ;
            mvares.eta_J2            = eta_J2_ ;
            mvares.phi_J2            = phi_J2_ ;
            mvares.charge_J2         = charge_J2_ ;
            mvares.energy_J2         = energy_J2_ ;
            mvares.flav_J2           = flav_J2_ ;

            mvares.pt_J3             = pt_J3_ ;
            mvares.eta_J3            = eta_J3_ ;
            mvares.phi_J3            = phi_J3_ ;
            mvares.charge_J3         = charge_J3_ ;
            mvares.energy_J3         = energy_J3_ ;
            mvares.flav_J3           = flav_J3_ ;

            mvares.n_constits        = n_constits_;
            //mvares.test_vec          = test_vec_ ;

            mvares.lead_jet_pt    = lead_jet_pt_ ;
            mvares.test_lead_jet_eta    = test_lead_jet_eta_ ;
             
            mvares.lead_jet_c1_eta = lead_jet_c1_eta_;
            mvares.lead_jet_c2_eta = lead_jet_c2_eta_;
            mvares.lead_jet_c3_eta = lead_jet_c3_eta_;
            mvares.lead_jet_c4_eta = lead_jet_c4_eta_;
            mvares.lead_jet_c5_eta = lead_jet_c5_eta_;
            mvares.lead_jet_c6_eta = lead_jet_c6_eta_;
            mvares.lead_jet_c7_eta = lead_jet_c7_eta_;
            mvares.lead_jet_c8_eta = lead_jet_c8_eta_;
            mvares.lead_jet_c9_eta = lead_jet_c9_eta_;
            mvares.lead_jet_c10_eta = lead_jet_c10_eta_;
            mvares.lead_jet_c11_eta = lead_jet_c11_eta_;
            mvares.lead_jet_c12_eta = lead_jet_c12_eta_;
            mvares.lead_jet_c13_eta = lead_jet_c13_eta_;
            mvares.lead_jet_c14_eta = lead_jet_c14_eta_;
            mvares.lead_jet_c15_eta = lead_jet_c15_eta_;
            mvares.lead_jet_c16_eta = lead_jet_c16_eta_;
            mvares.lead_jet_c17_eta = lead_jet_c17_eta_;
            mvares.lead_jet_c18_eta = lead_jet_c18_eta_;
            mvares.lead_jet_c19_eta = lead_jet_c19_eta_;
            mvares.lead_jet_c20_eta = lead_jet_c20_eta_;
            mvares.lead_jet_c21_eta = lead_jet_c21_eta_;
            mvares.lead_jet_c22_eta = lead_jet_c22_eta_;
            mvares.lead_jet_c23_eta = lead_jet_c23_eta_;
            mvares.lead_jet_c24_eta = lead_jet_c24_eta_;
            mvares.lead_jet_c25_eta = lead_jet_c25_eta_;
            mvares.lead_jet_c26_eta = lead_jet_c26_eta_;
            mvares.lead_jet_c27_eta = lead_jet_c27_eta_;
            mvares.lead_jet_c28_eta = lead_jet_c28_eta_;
            mvares.lead_jet_c29_eta = lead_jet_c29_eta_;
            mvares.lead_jet_c30_eta = lead_jet_c30_eta_;
            mvares.lead_jet_c31_eta = lead_jet_c31_eta_;
            mvares.lead_jet_c32_eta = lead_jet_c32_eta_;
            mvares.lead_jet_c33_eta = lead_jet_c33_eta_;
            mvares.lead_jet_c34_eta = lead_jet_c34_eta_;
            mvares.lead_jet_c35_eta = lead_jet_c35_eta_;
            mvares.lead_jet_c36_eta = lead_jet_c36_eta_;
            mvares.lead_jet_c37_eta = lead_jet_c37_eta_;
            mvares.lead_jet_c38_eta = lead_jet_c38_eta_;
            mvares.lead_jet_c39_eta = lead_jet_c39_eta_;
            mvares.lead_jet_c40_eta = lead_jet_c40_eta_;
            mvares.lead_jet_c41_eta = lead_jet_c41_eta_;
            mvares.lead_jet_c42_eta = lead_jet_c42_eta_;
            mvares.lead_jet_c43_eta = lead_jet_c43_eta_;
            mvares.lead_jet_c44_eta = lead_jet_c44_eta_;
            mvares.lead_jet_c45_eta = lead_jet_c45_eta_;
            mvares.lead_jet_c46_eta = lead_jet_c46_eta_;
            mvares.lead_jet_c47_eta = lead_jet_c47_eta_;
            mvares.lead_jet_c48_eta = lead_jet_c48_eta_;
            mvares.lead_jet_c49_eta = lead_jet_c49_eta_;
            mvares.lead_jet_c50_eta = lead_jet_c50_eta_;
            mvares.lead_jet_c51_eta = lead_jet_c51_eta_;
            mvares.lead_jet_c52_eta = lead_jet_c52_eta_;
            mvares.lead_jet_c53_eta = lead_jet_c53_eta_;
            mvares.lead_jet_c54_eta = lead_jet_c54_eta_;
            mvares.lead_jet_c55_eta = lead_jet_c55_eta_;
            mvares.lead_jet_c56_eta = lead_jet_c56_eta_;
            mvares.lead_jet_c57_eta = lead_jet_c57_eta_;
            mvares.lead_jet_c58_eta = lead_jet_c58_eta_;
            mvares.lead_jet_c59_eta = lead_jet_c59_eta_;
            mvares.lead_jet_c60_eta = lead_jet_c60_eta_;

            mvares.lead_jet_c1_phi = lead_jet_c1_phi_;
            mvares.lead_jet_c2_phi = lead_jet_c2_phi_;
            mvares.lead_jet_c3_phi = lead_jet_c3_phi_;
            mvares.lead_jet_c4_phi = lead_jet_c4_phi_;
            mvares.lead_jet_c5_phi = lead_jet_c5_phi_;
            mvares.lead_jet_c6_phi = lead_jet_c6_phi_;
            mvares.lead_jet_c7_phi = lead_jet_c7_phi_;
            mvares.lead_jet_c8_phi = lead_jet_c8_phi_;
            mvares.lead_jet_c9_phi = lead_jet_c9_phi_;
            mvares.lead_jet_c10_phi = lead_jet_c10_phi_;
            mvares.lead_jet_c11_phi = lead_jet_c11_phi_;
            mvares.lead_jet_c12_phi = lead_jet_c12_phi_;
            mvares.lead_jet_c13_phi = lead_jet_c13_phi_;
            mvares.lead_jet_c14_phi = lead_jet_c14_phi_;
            mvares.lead_jet_c15_phi = lead_jet_c15_phi_;
            mvares.lead_jet_c16_phi = lead_jet_c16_phi_;
            mvares.lead_jet_c17_phi = lead_jet_c17_phi_;
            mvares.lead_jet_c18_phi = lead_jet_c18_phi_;
            mvares.lead_jet_c19_phi = lead_jet_c19_phi_;
            mvares.lead_jet_c20_phi = lead_jet_c20_phi_;
            mvares.lead_jet_c21_phi = lead_jet_c21_phi_;
            mvares.lead_jet_c22_phi = lead_jet_c22_phi_;
            mvares.lead_jet_c23_phi = lead_jet_c23_phi_;
            mvares.lead_jet_c24_phi = lead_jet_c24_phi_;
            mvares.lead_jet_c25_phi = lead_jet_c25_phi_;
            mvares.lead_jet_c26_phi = lead_jet_c26_phi_;
            mvares.lead_jet_c27_phi = lead_jet_c27_phi_;
            mvares.lead_jet_c28_phi = lead_jet_c28_phi_;
            mvares.lead_jet_c29_phi = lead_jet_c29_phi_;
            mvares.lead_jet_c30_phi = lead_jet_c30_phi_;
            mvares.lead_jet_c31_phi = lead_jet_c31_phi_;
            mvares.lead_jet_c32_phi = lead_jet_c32_phi_;
            mvares.lead_jet_c33_phi = lead_jet_c33_phi_;
            mvares.lead_jet_c34_phi = lead_jet_c34_phi_;
            mvares.lead_jet_c35_phi = lead_jet_c35_phi_;
            mvares.lead_jet_c36_phi = lead_jet_c36_phi_;
            mvares.lead_jet_c37_phi = lead_jet_c37_phi_;
            mvares.lead_jet_c38_phi = lead_jet_c38_phi_;
            mvares.lead_jet_c39_phi = lead_jet_c39_phi_;
            mvares.lead_jet_c40_phi = lead_jet_c40_phi_;
            mvares.lead_jet_c41_phi = lead_jet_c41_phi_;
            mvares.lead_jet_c42_phi = lead_jet_c42_phi_;
            mvares.lead_jet_c43_phi = lead_jet_c43_phi_;
            mvares.lead_jet_c44_phi = lead_jet_c44_phi_;
            mvares.lead_jet_c45_phi = lead_jet_c45_phi_;
            mvares.lead_jet_c46_phi = lead_jet_c46_phi_;
            mvares.lead_jet_c47_phi = lead_jet_c47_phi_;
            mvares.lead_jet_c48_phi = lead_jet_c48_phi_;
            mvares.lead_jet_c49_phi = lead_jet_c49_phi_;
            mvares.lead_jet_c50_phi = lead_jet_c50_phi_;
            mvares.lead_jet_c51_phi = lead_jet_c51_phi_;
            mvares.lead_jet_c52_phi = lead_jet_c52_phi_;
            mvares.lead_jet_c53_phi = lead_jet_c53_phi_;
            mvares.lead_jet_c54_phi = lead_jet_c54_phi_;
            mvares.lead_jet_c55_phi = lead_jet_c55_phi_;
            mvares.lead_jet_c56_phi = lead_jet_c56_phi_;
            mvares.lead_jet_c57_phi = lead_jet_c57_phi_;
            mvares.lead_jet_c58_phi = lead_jet_c58_phi_;
            mvares.lead_jet_c59_phi = lead_jet_c59_phi_;
            mvares.lead_jet_c60_phi = lead_jet_c60_phi_;

            mvares.lead_jet_c1_charge =  lead_jet_c1_charge_;
            mvares.lead_jet_c2_charge =  lead_jet_c2_charge_;
            mvares.lead_jet_c3_charge =  lead_jet_c3_charge_;
            mvares.lead_jet_c4_charge =  lead_jet_c4_charge_;
            mvares.lead_jet_c5_charge =  lead_jet_c5_charge_;
            mvares.lead_jet_c6_charge =  lead_jet_c6_charge_;
            mvares.lead_jet_c7_charge =  lead_jet_c7_charge_;
            mvares.lead_jet_c8_charge =  lead_jet_c8_charge_;
            mvares.lead_jet_c9_charge =  lead_jet_c9_charge_;
            mvares.lead_jet_c10_charge =  lead_jet_c10_charge_;
            mvares.lead_jet_c11_charge =  lead_jet_c11_charge_;
            mvares.lead_jet_c12_charge =  lead_jet_c12_charge_;
            mvares.lead_jet_c13_charge =  lead_jet_c13_charge_;
            mvares.lead_jet_c14_charge =  lead_jet_c14_charge_;
            mvares.lead_jet_c15_charge =  lead_jet_c15_charge_;
            mvares.lead_jet_c16_charge =  lead_jet_c16_charge_;
            mvares.lead_jet_c17_charge =  lead_jet_c17_charge_;
            mvares.lead_jet_c18_charge =  lead_jet_c18_charge_;
            mvares.lead_jet_c19_charge =  lead_jet_c19_charge_;
            mvares.lead_jet_c20_charge =  lead_jet_c20_charge_;
            mvares.lead_jet_c21_charge =  lead_jet_c21_charge_;
            mvares.lead_jet_c22_charge =  lead_jet_c22_charge_;
            mvares.lead_jet_c23_charge =  lead_jet_c23_charge_;
            mvares.lead_jet_c24_charge =  lead_jet_c24_charge_;
            mvares.lead_jet_c25_charge =  lead_jet_c25_charge_;
            mvares.lead_jet_c26_charge =  lead_jet_c26_charge_;
            mvares.lead_jet_c27_charge =  lead_jet_c27_charge_;
            mvares.lead_jet_c28_charge =  lead_jet_c28_charge_;
            mvares.lead_jet_c29_charge =  lead_jet_c29_charge_;
            mvares.lead_jet_c30_charge =  lead_jet_c30_charge_;
            mvares.lead_jet_c31_charge =  lead_jet_c31_charge_;
            mvares.lead_jet_c32_charge =  lead_jet_c32_charge_;
            mvares.lead_jet_c33_charge =  lead_jet_c33_charge_;
            mvares.lead_jet_c34_charge =  lead_jet_c34_charge_;
            mvares.lead_jet_c35_charge =  lead_jet_c35_charge_;
            mvares.lead_jet_c36_charge =  lead_jet_c36_charge_;
            mvares.lead_jet_c37_charge =  lead_jet_c37_charge_;
            mvares.lead_jet_c38_charge =  lead_jet_c38_charge_;
            mvares.lead_jet_c39_charge =  lead_jet_c39_charge_;
            mvares.lead_jet_c40_charge =  lead_jet_c40_charge_;
            mvares.lead_jet_c41_charge =  lead_jet_c41_charge_;
            mvares.lead_jet_c42_charge =  lead_jet_c42_charge_;
            mvares.lead_jet_c43_charge =  lead_jet_c43_charge_;
            mvares.lead_jet_c44_charge =  lead_jet_c44_charge_;
            mvares.lead_jet_c45_charge =  lead_jet_c45_charge_;
            mvares.lead_jet_c46_charge =  lead_jet_c46_charge_;
            mvares.lead_jet_c47_charge =  lead_jet_c47_charge_;
            mvares.lead_jet_c48_charge =  lead_jet_c48_charge_;
            mvares.lead_jet_c49_charge =  lead_jet_c49_charge_;
            mvares.lead_jet_c50_charge =  lead_jet_c50_charge_;
            mvares.lead_jet_c51_charge =  lead_jet_c51_charge_;
            mvares.lead_jet_c52_charge =  lead_jet_c52_charge_;
            mvares.lead_jet_c53_charge =  lead_jet_c53_charge_;
            mvares.lead_jet_c54_charge =  lead_jet_c54_charge_;
            mvares.lead_jet_c55_charge =  lead_jet_c55_charge_;
            mvares.lead_jet_c56_charge =  lead_jet_c56_charge_;
            mvares.lead_jet_c57_charge =  lead_jet_c57_charge_;
            mvares.lead_jet_c58_charge =  lead_jet_c58_charge_;
            mvares.lead_jet_c59_charge =  lead_jet_c59_charge_;
            mvares.lead_jet_c60_charge =  lead_jet_c60_charge_;

            mvares.lead_jet_c1_pt = lead_jet_c1_pt_;
            mvares.lead_jet_c2_pt = lead_jet_c2_pt_;
            mvares.lead_jet_c3_pt = lead_jet_c3_pt_;
            mvares.lead_jet_c4_pt = lead_jet_c4_pt_;
            mvares.lead_jet_c5_pt = lead_jet_c5_pt_;
            mvares.lead_jet_c6_pt = lead_jet_c6_pt_;
            mvares.lead_jet_c7_pt = lead_jet_c7_pt_;
            mvares.lead_jet_c8_pt = lead_jet_c8_pt_;
            mvares.lead_jet_c9_pt = lead_jet_c9_pt_;
            mvares.lead_jet_c10_pt = lead_jet_c10_pt_;
            mvares.lead_jet_c11_pt = lead_jet_c11_pt_;
            mvares.lead_jet_c12_pt = lead_jet_c12_pt_;
            mvares.lead_jet_c13_pt = lead_jet_c13_pt_;
            mvares.lead_jet_c14_pt = lead_jet_c14_pt_;
            mvares.lead_jet_c15_pt = lead_jet_c15_pt_;
            mvares.lead_jet_c16_pt = lead_jet_c16_pt_;
            mvares.lead_jet_c17_pt = lead_jet_c17_pt_;
            mvares.lead_jet_c18_pt = lead_jet_c18_pt_;
            mvares.lead_jet_c19_pt = lead_jet_c19_pt_;
            mvares.lead_jet_c20_pt = lead_jet_c20_pt_;
            mvares.lead_jet_c21_pt = lead_jet_c21_pt_;
            mvares.lead_jet_c22_pt = lead_jet_c22_pt_;
            mvares.lead_jet_c23_pt = lead_jet_c23_pt_;
            mvares.lead_jet_c24_pt = lead_jet_c24_pt_;
            mvares.lead_jet_c25_pt = lead_jet_c25_pt_;
            mvares.lead_jet_c26_pt = lead_jet_c26_pt_;
            mvares.lead_jet_c27_pt = lead_jet_c27_pt_;
            mvares.lead_jet_c28_pt = lead_jet_c28_pt_;
            mvares.lead_jet_c29_pt = lead_jet_c29_pt_;
            mvares.lead_jet_c30_pt = lead_jet_c30_pt_;
            mvares.lead_jet_c31_pt = lead_jet_c31_pt_;
            mvares.lead_jet_c32_pt = lead_jet_c32_pt_;
            mvares.lead_jet_c33_pt = lead_jet_c33_pt_;
            mvares.lead_jet_c34_pt = lead_jet_c34_pt_;
            mvares.lead_jet_c35_pt = lead_jet_c35_pt_;
            mvares.lead_jet_c36_pt = lead_jet_c36_pt_;
            mvares.lead_jet_c37_pt = lead_jet_c37_pt_;
            mvares.lead_jet_c38_pt = lead_jet_c38_pt_;
            mvares.lead_jet_c39_pt = lead_jet_c39_pt_;
            mvares.lead_jet_c40_pt = lead_jet_c40_pt_;
            mvares.lead_jet_c41_pt = lead_jet_c41_pt_;
            mvares.lead_jet_c42_pt = lead_jet_c42_pt_;
            mvares.lead_jet_c43_pt = lead_jet_c43_pt_;
            mvares.lead_jet_c44_pt = lead_jet_c44_pt_;
            mvares.lead_jet_c45_pt = lead_jet_c45_pt_;
            mvares.lead_jet_c46_pt = lead_jet_c46_pt_;
            mvares.lead_jet_c47_pt = lead_jet_c47_pt_;
            mvares.lead_jet_c48_pt = lead_jet_c48_pt_;
            mvares.lead_jet_c49_pt = lead_jet_c49_pt_;
            mvares.lead_jet_c50_pt = lead_jet_c50_pt_;
            mvares.lead_jet_c51_pt = lead_jet_c51_pt_;
            mvares.lead_jet_c52_pt = lead_jet_c52_pt_;
            mvares.lead_jet_c53_pt = lead_jet_c53_pt_;
            mvares.lead_jet_c54_pt = lead_jet_c54_pt_;
            mvares.lead_jet_c55_pt = lead_jet_c55_pt_;
            mvares.lead_jet_c56_pt = lead_jet_c56_pt_;
            mvares.lead_jet_c57_pt = lead_jet_c57_pt_;
            mvares.lead_jet_c58_pt = lead_jet_c58_pt_;
            mvares.lead_jet_c59_pt = lead_jet_c59_pt_;
            mvares.lead_jet_c60_pt = lead_jet_c60_pt_;

            mvares.lead_jet_c1_energy = lead_jet_c1_energy_;
            mvares.lead_jet_c2_energy = lead_jet_c2_energy_;
            mvares.lead_jet_c3_energy = lead_jet_c3_energy_;
            mvares.lead_jet_c4_energy = lead_jet_c4_energy_;
            mvares.lead_jet_c5_energy = lead_jet_c5_energy_;
            mvares.lead_jet_c6_energy = lead_jet_c6_energy_;
            mvares.lead_jet_c7_energy = lead_jet_c7_energy_;
            mvares.lead_jet_c8_energy = lead_jet_c8_energy_;
            mvares.lead_jet_c9_energy = lead_jet_c9_energy_;
            mvares.lead_jet_c10_energy = lead_jet_c10_energy_;
            mvares.lead_jet_c11_energy = lead_jet_c11_energy_;
            mvares.lead_jet_c12_energy = lead_jet_c12_energy_;
            mvares.lead_jet_c13_energy = lead_jet_c13_energy_;
            mvares.lead_jet_c14_energy = lead_jet_c14_energy_;
            mvares.lead_jet_c15_energy = lead_jet_c15_energy_;
            mvares.lead_jet_c16_energy = lead_jet_c16_energy_;
            mvares.lead_jet_c17_energy = lead_jet_c17_energy_;
            mvares.lead_jet_c18_energy = lead_jet_c18_energy_;
            mvares.lead_jet_c19_energy = lead_jet_c19_energy_;
            mvares.lead_jet_c20_energy = lead_jet_c20_energy_;
            mvares.lead_jet_c21_energy = lead_jet_c21_energy_;
            mvares.lead_jet_c22_energy = lead_jet_c22_energy_;
            mvares.lead_jet_c23_energy = lead_jet_c23_energy_;
            mvares.lead_jet_c24_energy = lead_jet_c24_energy_;
            mvares.lead_jet_c25_energy = lead_jet_c25_energy_;
            mvares.lead_jet_c26_energy = lead_jet_c26_energy_;
            mvares.lead_jet_c27_energy = lead_jet_c27_energy_;
            mvares.lead_jet_c28_energy = lead_jet_c28_energy_;
            mvares.lead_jet_c29_energy = lead_jet_c29_energy_;
            mvares.lead_jet_c30_energy = lead_jet_c30_energy_;
            mvares.lead_jet_c31_energy = lead_jet_c31_energy_;
            mvares.lead_jet_c32_energy = lead_jet_c32_energy_;
            mvares.lead_jet_c33_energy = lead_jet_c33_energy_;
            mvares.lead_jet_c34_energy = lead_jet_c34_energy_;
            mvares.lead_jet_c35_energy = lead_jet_c35_energy_;
            mvares.lead_jet_c36_energy = lead_jet_c36_energy_;
            mvares.lead_jet_c37_energy = lead_jet_c37_energy_;
            mvares.lead_jet_c38_energy = lead_jet_c38_energy_;
            mvares.lead_jet_c39_energy = lead_jet_c39_energy_;
            mvares.lead_jet_c40_energy = lead_jet_c40_energy_;
            mvares.lead_jet_c41_energy = lead_jet_c41_energy_;
            mvares.lead_jet_c42_energy = lead_jet_c42_energy_;
            mvares.lead_jet_c43_energy = lead_jet_c43_energy_;
            mvares.lead_jet_c44_energy = lead_jet_c44_energy_;
            mvares.lead_jet_c45_energy = lead_jet_c45_energy_;
            mvares.lead_jet_c46_energy = lead_jet_c46_energy_;
            mvares.lead_jet_c47_energy = lead_jet_c47_energy_;
            mvares.lead_jet_c48_energy = lead_jet_c48_energy_;
            mvares.lead_jet_c49_energy = lead_jet_c49_energy_;
            mvares.lead_jet_c50_energy = lead_jet_c50_energy_;
            mvares.lead_jet_c51_energy = lead_jet_c51_energy_;
            mvares.lead_jet_c52_energy = lead_jet_c52_energy_;
            mvares.lead_jet_c53_energy = lead_jet_c53_energy_;
            mvares.lead_jet_c54_energy = lead_jet_c54_energy_;
            mvares.lead_jet_c55_energy = lead_jet_c55_energy_;
            mvares.lead_jet_c56_energy = lead_jet_c56_energy_;
            mvares.lead_jet_c57_energy = lead_jet_c57_energy_;
            mvares.lead_jet_c58_energy = lead_jet_c58_energy_;
            mvares.lead_jet_c59_energy = lead_jet_c59_energy_;
            mvares.lead_jet_c60_energy = lead_jet_c60_energy_;

            mvares.sublead_jet_c1_eta = sublead_jet_c1_eta_;
            mvares.sublead_jet_c2_eta = sublead_jet_c2_eta_;
            mvares.sublead_jet_c3_eta = sublead_jet_c3_eta_;
            mvares.sublead_jet_c4_eta = sublead_jet_c4_eta_;
            mvares.sublead_jet_c5_eta = sublead_jet_c5_eta_;
            mvares.sublead_jet_c6_eta = sublead_jet_c6_eta_;
            mvares.sublead_jet_c7_eta = sublead_jet_c7_eta_;
            mvares.sublead_jet_c8_eta = sublead_jet_c8_eta_;
            mvares.sublead_jet_c9_eta = sublead_jet_c9_eta_;
            mvares.sublead_jet_c10_eta = sublead_jet_c10_eta_;
            mvares.sublead_jet_c11_eta = sublead_jet_c11_eta_;
            mvares.sublead_jet_c12_eta = sublead_jet_c12_eta_;
            mvares.sublead_jet_c13_eta = sublead_jet_c13_eta_;
            mvares.sublead_jet_c14_eta = sublead_jet_c14_eta_;
            mvares.sublead_jet_c15_eta = sublead_jet_c15_eta_;
            mvares.sublead_jet_c16_eta = sublead_jet_c16_eta_;
            mvares.sublead_jet_c17_eta = sublead_jet_c17_eta_;
            mvares.sublead_jet_c18_eta = sublead_jet_c18_eta_;
            mvares.sublead_jet_c19_eta = sublead_jet_c19_eta_;
            mvares.sublead_jet_c20_eta = sublead_jet_c20_eta_;
            mvares.sublead_jet_c21_eta = sublead_jet_c21_eta_;
            mvares.sublead_jet_c22_eta = sublead_jet_c22_eta_;
            mvares.sublead_jet_c23_eta = sublead_jet_c23_eta_;
            mvares.sublead_jet_c24_eta = sublead_jet_c24_eta_;
            mvares.sublead_jet_c25_eta = sublead_jet_c25_eta_;
            mvares.sublead_jet_c26_eta = sublead_jet_c26_eta_;
            mvares.sublead_jet_c27_eta = sublead_jet_c27_eta_;
            mvares.sublead_jet_c28_eta = sublead_jet_c28_eta_;
            mvares.sublead_jet_c29_eta = sublead_jet_c29_eta_;
            mvares.sublead_jet_c30_eta = sublead_jet_c30_eta_;
            mvares.sublead_jet_c31_eta = sublead_jet_c31_eta_;
            mvares.sublead_jet_c32_eta = sublead_jet_c32_eta_;
            mvares.sublead_jet_c33_eta = sublead_jet_c33_eta_;
            mvares.sublead_jet_c34_eta = sublead_jet_c34_eta_;
            mvares.sublead_jet_c35_eta = sublead_jet_c35_eta_;
            mvares.sublead_jet_c36_eta = sublead_jet_c36_eta_;
            mvares.sublead_jet_c37_eta = sublead_jet_c37_eta_;
            mvares.sublead_jet_c38_eta = sublead_jet_c38_eta_;
            mvares.sublead_jet_c39_eta = sublead_jet_c39_eta_;
            mvares.sublead_jet_c40_eta = sublead_jet_c40_eta_;
            mvares.sublead_jet_c41_eta = sublead_jet_c41_eta_;
            mvares.sublead_jet_c42_eta = sublead_jet_c42_eta_;
            mvares.sublead_jet_c43_eta = sublead_jet_c43_eta_;
            mvares.sublead_jet_c44_eta = sublead_jet_c44_eta_;
            mvares.sublead_jet_c45_eta = sublead_jet_c45_eta_;
            mvares.sublead_jet_c46_eta = sublead_jet_c46_eta_;
            mvares.sublead_jet_c47_eta = sublead_jet_c47_eta_;
            mvares.sublead_jet_c48_eta = sublead_jet_c48_eta_;
            mvares.sublead_jet_c49_eta = sublead_jet_c49_eta_;
            mvares.sublead_jet_c50_eta = sublead_jet_c50_eta_;
            mvares.sublead_jet_c51_eta = sublead_jet_c51_eta_;
            mvares.sublead_jet_c52_eta = sublead_jet_c52_eta_;
            mvares.sublead_jet_c53_eta = sublead_jet_c53_eta_;
            mvares.sublead_jet_c54_eta = sublead_jet_c54_eta_;
            mvares.sublead_jet_c55_eta = sublead_jet_c55_eta_;
            mvares.sublead_jet_c56_eta = sublead_jet_c56_eta_;
            mvares.sublead_jet_c57_eta = sublead_jet_c57_eta_;
            mvares.sublead_jet_c58_eta = sublead_jet_c58_eta_;
            mvares.sublead_jet_c59_eta = sublead_jet_c59_eta_;
            mvares.sublead_jet_c60_eta = sublead_jet_c60_eta_;

            mvares.sublead_jet_c1_phi = sublead_jet_c1_phi_;
            mvares.sublead_jet_c2_phi = sublead_jet_c2_phi_;
            mvares.sublead_jet_c3_phi = sublead_jet_c3_phi_;
            mvares.sublead_jet_c4_phi = sublead_jet_c4_phi_;
            mvares.sublead_jet_c5_phi = sublead_jet_c5_phi_;
            mvares.sublead_jet_c6_phi = sublead_jet_c6_phi_;
            mvares.sublead_jet_c7_phi = sublead_jet_c7_phi_;
            mvares.sublead_jet_c8_phi = sublead_jet_c8_phi_;
            mvares.sublead_jet_c9_phi = sublead_jet_c9_phi_;
            mvares.sublead_jet_c10_phi = sublead_jet_c10_phi_;
            mvares.sublead_jet_c11_phi = sublead_jet_c11_phi_;
            mvares.sublead_jet_c12_phi = sublead_jet_c12_phi_;
            mvares.sublead_jet_c13_phi = sublead_jet_c13_phi_;
            mvares.sublead_jet_c14_phi = sublead_jet_c14_phi_;
            mvares.sublead_jet_c15_phi = sublead_jet_c15_phi_;
            mvares.sublead_jet_c16_phi = sublead_jet_c16_phi_;
            mvares.sublead_jet_c17_phi = sublead_jet_c17_phi_;
            mvares.sublead_jet_c18_phi = sublead_jet_c18_phi_;
            mvares.sublead_jet_c19_phi = sublead_jet_c19_phi_;
            mvares.sublead_jet_c20_phi = sublead_jet_c20_phi_;
            mvares.sublead_jet_c21_phi = sublead_jet_c21_phi_;
            mvares.sublead_jet_c22_phi = sublead_jet_c22_phi_;
            mvares.sublead_jet_c23_phi = sublead_jet_c23_phi_;
            mvares.sublead_jet_c24_phi = sublead_jet_c24_phi_;
            mvares.sublead_jet_c25_phi = sublead_jet_c25_phi_;
            mvares.sublead_jet_c26_phi = sublead_jet_c26_phi_;
            mvares.sublead_jet_c27_phi = sublead_jet_c27_phi_;
            mvares.sublead_jet_c28_phi = sublead_jet_c28_phi_;
            mvares.sublead_jet_c29_phi = sublead_jet_c29_phi_;
            mvares.sublead_jet_c30_phi = sublead_jet_c30_phi_;
            mvares.sublead_jet_c31_phi = sublead_jet_c31_phi_;
            mvares.sublead_jet_c32_phi = sublead_jet_c32_phi_;
            mvares.sublead_jet_c33_phi = sublead_jet_c33_phi_;
            mvares.sublead_jet_c34_phi = sublead_jet_c34_phi_;
            mvares.sublead_jet_c35_phi = sublead_jet_c35_phi_;
            mvares.sublead_jet_c36_phi = sublead_jet_c36_phi_;
            mvares.sublead_jet_c37_phi = sublead_jet_c37_phi_;
            mvares.sublead_jet_c38_phi = sublead_jet_c38_phi_;
            mvares.sublead_jet_c39_phi = sublead_jet_c39_phi_;
            mvares.sublead_jet_c40_phi = sublead_jet_c40_phi_;
            mvares.sublead_jet_c41_phi = sublead_jet_c41_phi_;
            mvares.sublead_jet_c42_phi = sublead_jet_c42_phi_;
            mvares.sublead_jet_c43_phi = sublead_jet_c43_phi_;
            mvares.sublead_jet_c44_phi = sublead_jet_c44_phi_;
            mvares.sublead_jet_c45_phi = sublead_jet_c45_phi_;
            mvares.sublead_jet_c46_phi = sublead_jet_c46_phi_;
            mvares.sublead_jet_c47_phi = sublead_jet_c47_phi_;
            mvares.sublead_jet_c48_phi = sublead_jet_c48_phi_;
            mvares.sublead_jet_c49_phi = sublead_jet_c49_phi_;
            mvares.sublead_jet_c50_phi = sublead_jet_c50_phi_;
            mvares.sublead_jet_c51_phi = sublead_jet_c51_phi_;
            mvares.sublead_jet_c52_phi = sublead_jet_c52_phi_;
            mvares.sublead_jet_c53_phi = sublead_jet_c53_phi_;
            mvares.sublead_jet_c54_phi = sublead_jet_c54_phi_;
            mvares.sublead_jet_c55_phi = sublead_jet_c55_phi_;
            mvares.sublead_jet_c56_phi = sublead_jet_c56_phi_;
            mvares.sublead_jet_c57_phi = sublead_jet_c57_phi_;
            mvares.sublead_jet_c58_phi = sublead_jet_c58_phi_;
            mvares.sublead_jet_c59_phi = sublead_jet_c59_phi_;
            mvares.sublead_jet_c60_phi = sublead_jet_c60_phi_;

            mvares.sublead_jet_c1_charge =  sublead_jet_c1_charge_;
            mvares.sublead_jet_c2_charge =  sublead_jet_c2_charge_;
            mvares.sublead_jet_c3_charge =  sublead_jet_c3_charge_;
            mvares.sublead_jet_c4_charge =  sublead_jet_c4_charge_;
            mvares.sublead_jet_c5_charge =  sublead_jet_c5_charge_;
            mvares.sublead_jet_c6_charge =  sublead_jet_c6_charge_;
            mvares.sublead_jet_c7_charge =  sublead_jet_c7_charge_;
            mvares.sublead_jet_c8_charge =  sublead_jet_c8_charge_;
            mvares.sublead_jet_c9_charge =  sublead_jet_c9_charge_;
            mvares.sublead_jet_c10_charge =  sublead_jet_c10_charge_;
            mvares.sublead_jet_c11_charge =  sublead_jet_c11_charge_;
            mvares.sublead_jet_c12_charge =  sublead_jet_c12_charge_;
            mvares.sublead_jet_c13_charge =  sublead_jet_c13_charge_;
            mvares.sublead_jet_c14_charge =  sublead_jet_c14_charge_;
            mvares.sublead_jet_c15_charge =  sublead_jet_c15_charge_;
            mvares.sublead_jet_c16_charge =  sublead_jet_c16_charge_;
            mvares.sublead_jet_c17_charge =  sublead_jet_c17_charge_;
            mvares.sublead_jet_c18_charge =  sublead_jet_c18_charge_;
            mvares.sublead_jet_c19_charge =  sublead_jet_c19_charge_;
            mvares.sublead_jet_c20_charge =  sublead_jet_c20_charge_;
            mvares.sublead_jet_c21_charge =  sublead_jet_c21_charge_;
            mvares.sublead_jet_c22_charge =  sublead_jet_c22_charge_;
            mvares.sublead_jet_c23_charge =  sublead_jet_c23_charge_;
            mvares.sublead_jet_c24_charge =  sublead_jet_c24_charge_;
            mvares.sublead_jet_c25_charge =  sublead_jet_c25_charge_;
            mvares.sublead_jet_c26_charge =  sublead_jet_c26_charge_;
            mvares.sublead_jet_c27_charge =  sublead_jet_c27_charge_;
            mvares.sublead_jet_c28_charge =  sublead_jet_c28_charge_;
            mvares.sublead_jet_c29_charge =  sublead_jet_c29_charge_;
            mvares.sublead_jet_c30_charge =  sublead_jet_c30_charge_;
            mvares.sublead_jet_c31_charge =  sublead_jet_c31_charge_;
            mvares.sublead_jet_c32_charge =  sublead_jet_c32_charge_;
            mvares.sublead_jet_c33_charge =  sublead_jet_c33_charge_;
            mvares.sublead_jet_c34_charge =  sublead_jet_c34_charge_;
            mvares.sublead_jet_c35_charge =  sublead_jet_c35_charge_;
            mvares.sublead_jet_c36_charge =  sublead_jet_c36_charge_;
            mvares.sublead_jet_c37_charge =  sublead_jet_c37_charge_;
            mvares.sublead_jet_c38_charge =  sublead_jet_c38_charge_;
            mvares.sublead_jet_c39_charge =  sublead_jet_c39_charge_;
            mvares.sublead_jet_c40_charge =  sublead_jet_c40_charge_;
            mvares.sublead_jet_c41_charge =  sublead_jet_c41_charge_;
            mvares.sublead_jet_c42_charge =  sublead_jet_c42_charge_;
            mvares.sublead_jet_c43_charge =  sublead_jet_c43_charge_;
            mvares.sublead_jet_c44_charge =  sublead_jet_c44_charge_;
            mvares.sublead_jet_c45_charge =  sublead_jet_c45_charge_;
            mvares.sublead_jet_c46_charge =  sublead_jet_c46_charge_;
            mvares.sublead_jet_c47_charge =  sublead_jet_c47_charge_;
            mvares.sublead_jet_c48_charge =  sublead_jet_c48_charge_;
            mvares.sublead_jet_c49_charge =  sublead_jet_c49_charge_;
            mvares.sublead_jet_c50_charge =  sublead_jet_c50_charge_;
            mvares.sublead_jet_c51_charge =  sublead_jet_c51_charge_;
            mvares.sublead_jet_c52_charge =  sublead_jet_c52_charge_;
            mvares.sublead_jet_c53_charge =  sublead_jet_c53_charge_;
            mvares.sublead_jet_c54_charge =  sublead_jet_c54_charge_;
            mvares.sublead_jet_c55_charge =  sublead_jet_c55_charge_;
            mvares.sublead_jet_c56_charge =  sublead_jet_c56_charge_;
            mvares.sublead_jet_c57_charge =  sublead_jet_c57_charge_;
            mvares.sublead_jet_c58_charge =  sublead_jet_c58_charge_;
            mvares.sublead_jet_c59_charge =  sublead_jet_c59_charge_;
            mvares.sublead_jet_c60_charge =  sublead_jet_c60_charge_;

            mvares.sublead_jet_c1_pt = sublead_jet_c1_pt_;
            mvares.sublead_jet_c2_pt = sublead_jet_c2_pt_;
            mvares.sublead_jet_c3_pt = sublead_jet_c3_pt_;
            mvares.sublead_jet_c4_pt = sublead_jet_c4_pt_;
            mvares.sublead_jet_c5_pt = sublead_jet_c5_pt_;
            mvares.sublead_jet_c6_pt = sublead_jet_c6_pt_;
            mvares.sublead_jet_c7_pt = sublead_jet_c7_pt_;
            mvares.sublead_jet_c8_pt = sublead_jet_c8_pt_;
            mvares.sublead_jet_c9_pt = sublead_jet_c9_pt_;
            mvares.sublead_jet_c10_pt = sublead_jet_c10_pt_;
            mvares.sublead_jet_c11_pt = sublead_jet_c11_pt_;
            mvares.sublead_jet_c12_pt = sublead_jet_c12_pt_;
            mvares.sublead_jet_c13_pt = sublead_jet_c13_pt_;
            mvares.sublead_jet_c14_pt = sublead_jet_c14_pt_;
            mvares.sublead_jet_c15_pt = sublead_jet_c15_pt_;
            mvares.sublead_jet_c16_pt = sublead_jet_c16_pt_;
            mvares.sublead_jet_c17_pt = sublead_jet_c17_pt_;
            mvares.sublead_jet_c18_pt = sublead_jet_c18_pt_;
            mvares.sublead_jet_c19_pt = sublead_jet_c19_pt_;
            mvares.sublead_jet_c20_pt = sublead_jet_c20_pt_;
            mvares.sublead_jet_c21_pt = sublead_jet_c21_pt_;
            mvares.sublead_jet_c22_pt = sublead_jet_c22_pt_;
            mvares.sublead_jet_c23_pt = sublead_jet_c23_pt_;
            mvares.sublead_jet_c24_pt = sublead_jet_c24_pt_;
            mvares.sublead_jet_c25_pt = sublead_jet_c25_pt_;
            mvares.sublead_jet_c26_pt = sublead_jet_c26_pt_;
            mvares.sublead_jet_c27_pt = sublead_jet_c27_pt_;
            mvares.sublead_jet_c28_pt = sublead_jet_c28_pt_;
            mvares.sublead_jet_c29_pt = sublead_jet_c29_pt_;
            mvares.sublead_jet_c30_pt = sublead_jet_c30_pt_;
            mvares.sublead_jet_c31_pt = sublead_jet_c31_pt_;
            mvares.sublead_jet_c32_pt = sublead_jet_c32_pt_;
            mvares.sublead_jet_c33_pt = sublead_jet_c33_pt_;
            mvares.sublead_jet_c34_pt = sublead_jet_c34_pt_;
            mvares.sublead_jet_c35_pt = sublead_jet_c35_pt_;
            mvares.sublead_jet_c36_pt = sublead_jet_c36_pt_;
            mvares.sublead_jet_c37_pt = sublead_jet_c37_pt_;
            mvares.sublead_jet_c38_pt = sublead_jet_c38_pt_;
            mvares.sublead_jet_c39_pt = sublead_jet_c39_pt_;
            mvares.sublead_jet_c40_pt = sublead_jet_c40_pt_;
            mvares.sublead_jet_c41_pt = sublead_jet_c41_pt_;
            mvares.sublead_jet_c42_pt = sublead_jet_c42_pt_;
            mvares.sublead_jet_c43_pt = sublead_jet_c43_pt_;
            mvares.sublead_jet_c44_pt = sublead_jet_c44_pt_;
            mvares.sublead_jet_c45_pt = sublead_jet_c45_pt_;
            mvares.sublead_jet_c46_pt = sublead_jet_c46_pt_;
            mvares.sublead_jet_c47_pt = sublead_jet_c47_pt_;
            mvares.sublead_jet_c48_pt = sublead_jet_c48_pt_;
            mvares.sublead_jet_c49_pt = sublead_jet_c49_pt_;
            mvares.sublead_jet_c50_pt = sublead_jet_c50_pt_;
            mvares.sublead_jet_c51_pt = sublead_jet_c51_pt_;
            mvares.sublead_jet_c52_pt = sublead_jet_c52_pt_;
            mvares.sublead_jet_c53_pt = sublead_jet_c53_pt_;
            mvares.sublead_jet_c54_pt = sublead_jet_c54_pt_;
            mvares.sublead_jet_c55_pt = sublead_jet_c55_pt_;
            mvares.sublead_jet_c56_pt = sublead_jet_c56_pt_;
            mvares.sublead_jet_c57_pt = sublead_jet_c57_pt_;
            mvares.sublead_jet_c58_pt = sublead_jet_c58_pt_;
            mvares.sublead_jet_c59_pt = sublead_jet_c59_pt_;
            mvares.sublead_jet_c60_pt = sublead_jet_c60_pt_;

            mvares.sublead_jet_c1_energy = sublead_jet_c1_energy_;
            mvares.sublead_jet_c2_energy = sublead_jet_c2_energy_;
            mvares.sublead_jet_c3_energy = sublead_jet_c3_energy_;
            mvares.sublead_jet_c4_energy = sublead_jet_c4_energy_;
            mvares.sublead_jet_c5_energy = sublead_jet_c5_energy_;
            mvares.sublead_jet_c6_energy = sublead_jet_c6_energy_;
            mvares.sublead_jet_c7_energy = sublead_jet_c7_energy_;
            mvares.sublead_jet_c8_energy = sublead_jet_c8_energy_;
            mvares.sublead_jet_c9_energy = sublead_jet_c9_energy_;
            mvares.sublead_jet_c10_energy = sublead_jet_c10_energy_;
            mvares.sublead_jet_c11_energy = sublead_jet_c11_energy_;
            mvares.sublead_jet_c12_energy = sublead_jet_c12_energy_;
            mvares.sublead_jet_c13_energy = sublead_jet_c13_energy_;
            mvares.sublead_jet_c14_energy = sublead_jet_c14_energy_;
            mvares.sublead_jet_c15_energy = sublead_jet_c15_energy_;
            mvares.sublead_jet_c16_energy = sublead_jet_c16_energy_;
            mvares.sublead_jet_c17_energy = sublead_jet_c17_energy_;
            mvares.sublead_jet_c18_energy = sublead_jet_c18_energy_;
            mvares.sublead_jet_c19_energy = sublead_jet_c19_energy_;
            mvares.sublead_jet_c20_energy = sublead_jet_c20_energy_;
            mvares.sublead_jet_c21_energy = sublead_jet_c21_energy_;
            mvares.sublead_jet_c22_energy = sublead_jet_c22_energy_;
            mvares.sublead_jet_c23_energy = sublead_jet_c23_energy_;
            mvares.sublead_jet_c24_energy = sublead_jet_c24_energy_;
            mvares.sublead_jet_c25_energy = sublead_jet_c25_energy_;
            mvares.sublead_jet_c26_energy = sublead_jet_c26_energy_;
            mvares.sublead_jet_c27_energy = sublead_jet_c27_energy_;
            mvares.sublead_jet_c28_energy = sublead_jet_c28_energy_;
            mvares.sublead_jet_c29_energy = sublead_jet_c29_energy_;
            mvares.sublead_jet_c30_energy = sublead_jet_c30_energy_;
            mvares.sublead_jet_c31_energy = sublead_jet_c31_energy_;
            mvares.sublead_jet_c32_energy = sublead_jet_c32_energy_;
            mvares.sublead_jet_c33_energy = sublead_jet_c33_energy_;
            mvares.sublead_jet_c34_energy = sublead_jet_c34_energy_;
            mvares.sublead_jet_c35_energy = sublead_jet_c35_energy_;
            mvares.sublead_jet_c36_energy = sublead_jet_c36_energy_;
            mvares.sublead_jet_c37_energy = sublead_jet_c37_energy_;
            mvares.sublead_jet_c38_energy = sublead_jet_c38_energy_;
            mvares.sublead_jet_c39_energy = sublead_jet_c39_energy_;
            mvares.sublead_jet_c40_energy = sublead_jet_c40_energy_;
            mvares.sublead_jet_c41_energy = sublead_jet_c41_energy_;
            mvares.sublead_jet_c42_energy = sublead_jet_c42_energy_;
            mvares.sublead_jet_c43_energy = sublead_jet_c43_energy_;
            mvares.sublead_jet_c44_energy = sublead_jet_c44_energy_;
            mvares.sublead_jet_c45_energy = sublead_jet_c45_energy_;
            mvares.sublead_jet_c46_energy = sublead_jet_c46_energy_;
            mvares.sublead_jet_c47_energy = sublead_jet_c47_energy_;
            mvares.sublead_jet_c48_energy = sublead_jet_c48_energy_;
            mvares.sublead_jet_c49_energy = sublead_jet_c49_energy_;
            mvares.sublead_jet_c50_energy = sublead_jet_c50_energy_;
            mvares.sublead_jet_c51_energy = sublead_jet_c51_energy_;
            mvares.sublead_jet_c52_energy = sublead_jet_c52_energy_;
            mvares.sublead_jet_c53_energy = sublead_jet_c53_energy_;
            mvares.sublead_jet_c54_energy = sublead_jet_c54_energy_;
            mvares.sublead_jet_c55_energy = sublead_jet_c55_energy_;
            mvares.sublead_jet_c56_energy = sublead_jet_c56_energy_;
            mvares.sublead_jet_c57_energy = sublead_jet_c57_energy_;
            mvares.sublead_jet_c58_energy = sublead_jet_c58_energy_;
            mvares.sublead_jet_c59_energy = sublead_jet_c59_energy_;
            mvares.sublead_jet_c60_energy = sublead_jet_c60_energy_;

            mvares.subsublead_jet_c1_eta = subsublead_jet_c1_eta_;
            mvares.subsublead_jet_c2_eta = subsublead_jet_c2_eta_;
            mvares.subsublead_jet_c3_eta = subsublead_jet_c3_eta_;
            mvares.subsublead_jet_c4_eta = subsublead_jet_c4_eta_;
            mvares.subsublead_jet_c5_eta = subsublead_jet_c5_eta_;
            mvares.subsublead_jet_c6_eta = subsublead_jet_c6_eta_;
            mvares.subsublead_jet_c7_eta = subsublead_jet_c7_eta_;
            mvares.subsublead_jet_c8_eta = subsublead_jet_c8_eta_;
            mvares.subsublead_jet_c9_eta = subsublead_jet_c9_eta_;
            mvares.subsublead_jet_c10_eta = subsublead_jet_c10_eta_;
            mvares.subsublead_jet_c11_eta = subsublead_jet_c11_eta_;
            mvares.subsublead_jet_c12_eta = subsublead_jet_c12_eta_;
            mvares.subsublead_jet_c13_eta = subsublead_jet_c13_eta_;
            mvares.subsublead_jet_c14_eta = subsublead_jet_c14_eta_;
            mvares.subsublead_jet_c15_eta = subsublead_jet_c15_eta_;
            mvares.subsublead_jet_c16_eta = subsublead_jet_c16_eta_;
            mvares.subsublead_jet_c17_eta = subsublead_jet_c17_eta_;
            mvares.subsublead_jet_c18_eta = subsublead_jet_c18_eta_;
            mvares.subsublead_jet_c19_eta = subsublead_jet_c19_eta_;
            mvares.subsublead_jet_c20_eta = subsublead_jet_c20_eta_;
            mvares.subsublead_jet_c21_eta = subsublead_jet_c21_eta_;
            mvares.subsublead_jet_c22_eta = subsublead_jet_c22_eta_;
            mvares.subsublead_jet_c23_eta = subsublead_jet_c23_eta_;
            mvares.subsublead_jet_c24_eta = subsublead_jet_c24_eta_;
            mvares.subsublead_jet_c25_eta = subsublead_jet_c25_eta_;
            mvares.subsublead_jet_c26_eta = subsublead_jet_c26_eta_;
            mvares.subsublead_jet_c27_eta = subsublead_jet_c27_eta_;
            mvares.subsublead_jet_c28_eta = subsublead_jet_c28_eta_;
            mvares.subsublead_jet_c29_eta = subsublead_jet_c29_eta_;
            mvares.subsublead_jet_c30_eta = subsublead_jet_c30_eta_;
            mvares.subsublead_jet_c31_eta = subsublead_jet_c31_eta_;
            mvares.subsublead_jet_c32_eta = subsublead_jet_c32_eta_;
            mvares.subsublead_jet_c33_eta = subsublead_jet_c33_eta_;
            mvares.subsublead_jet_c34_eta = subsublead_jet_c34_eta_;
            mvares.subsublead_jet_c35_eta = subsublead_jet_c35_eta_;
            mvares.subsublead_jet_c36_eta = subsublead_jet_c36_eta_;
            mvares.subsublead_jet_c37_eta = subsublead_jet_c37_eta_;
            mvares.subsublead_jet_c38_eta = subsublead_jet_c38_eta_;
            mvares.subsublead_jet_c39_eta = subsublead_jet_c39_eta_;
            mvares.subsublead_jet_c40_eta = subsublead_jet_c40_eta_;
            mvares.subsublead_jet_c41_eta = subsublead_jet_c41_eta_;
            mvares.subsublead_jet_c42_eta = subsublead_jet_c42_eta_;
            mvares.subsublead_jet_c43_eta = subsublead_jet_c43_eta_;
            mvares.subsublead_jet_c44_eta = subsublead_jet_c44_eta_;
            mvares.subsublead_jet_c45_eta = subsublead_jet_c45_eta_;
            mvares.subsublead_jet_c46_eta = subsublead_jet_c46_eta_;
            mvares.subsublead_jet_c47_eta = subsublead_jet_c47_eta_;
            mvares.subsublead_jet_c48_eta = subsublead_jet_c48_eta_;
            mvares.subsublead_jet_c49_eta = subsublead_jet_c49_eta_;
            mvares.subsublead_jet_c50_eta = subsublead_jet_c50_eta_;
            mvares.subsublead_jet_c51_eta = subsublead_jet_c51_eta_;
            mvares.subsublead_jet_c52_eta = subsublead_jet_c52_eta_;
            mvares.subsublead_jet_c53_eta = subsublead_jet_c53_eta_;
            mvares.subsublead_jet_c54_eta = subsublead_jet_c54_eta_;
            mvares.subsublead_jet_c55_eta = subsublead_jet_c55_eta_;
            mvares.subsublead_jet_c56_eta = subsublead_jet_c56_eta_;
            mvares.subsublead_jet_c57_eta = subsublead_jet_c57_eta_;
            mvares.subsublead_jet_c58_eta = subsublead_jet_c58_eta_;
            mvares.subsublead_jet_c59_eta = subsublead_jet_c59_eta_;
            mvares.subsublead_jet_c60_eta = subsublead_jet_c60_eta_;

            mvares.subsublead_jet_c1_phi = subsublead_jet_c1_phi_;
            mvares.subsublead_jet_c2_phi = subsublead_jet_c2_phi_;
            mvares.subsublead_jet_c3_phi = subsublead_jet_c3_phi_;
            mvares.subsublead_jet_c4_phi = subsublead_jet_c4_phi_;
            mvares.subsublead_jet_c5_phi = subsublead_jet_c5_phi_;
            mvares.subsublead_jet_c6_phi = subsublead_jet_c6_phi_;
            mvares.subsublead_jet_c7_phi = subsublead_jet_c7_phi_;
            mvares.subsublead_jet_c8_phi = subsublead_jet_c8_phi_;
            mvares.subsublead_jet_c9_phi = subsublead_jet_c9_phi_;
            mvares.subsublead_jet_c10_phi = subsublead_jet_c10_phi_;
            mvares.subsublead_jet_c11_phi = subsublead_jet_c11_phi_;
            mvares.subsublead_jet_c12_phi = subsublead_jet_c12_phi_;
            mvares.subsublead_jet_c13_phi = subsublead_jet_c13_phi_;
            mvares.subsublead_jet_c14_phi = subsublead_jet_c14_phi_;
            mvares.subsublead_jet_c15_phi = subsublead_jet_c15_phi_;
            mvares.subsublead_jet_c16_phi = subsublead_jet_c16_phi_;
            mvares.subsublead_jet_c17_phi = subsublead_jet_c17_phi_;
            mvares.subsublead_jet_c18_phi = subsublead_jet_c18_phi_;
            mvares.subsublead_jet_c19_phi = subsublead_jet_c19_phi_;
            mvares.subsublead_jet_c20_phi = subsublead_jet_c20_phi_;
            mvares.subsublead_jet_c21_phi = subsublead_jet_c21_phi_;
            mvares.subsublead_jet_c22_phi = subsublead_jet_c22_phi_;
            mvares.subsublead_jet_c23_phi = subsublead_jet_c23_phi_;
            mvares.subsublead_jet_c24_phi = subsublead_jet_c24_phi_;
            mvares.subsublead_jet_c25_phi = subsublead_jet_c25_phi_;
            mvares.subsublead_jet_c26_phi = subsublead_jet_c26_phi_;
            mvares.subsublead_jet_c27_phi = subsublead_jet_c27_phi_;
            mvares.subsublead_jet_c28_phi = subsublead_jet_c28_phi_;
            mvares.subsublead_jet_c29_phi = subsublead_jet_c29_phi_;
            mvares.subsublead_jet_c30_phi = subsublead_jet_c30_phi_;
            mvares.subsublead_jet_c31_phi = subsublead_jet_c31_phi_;
            mvares.subsublead_jet_c32_phi = subsublead_jet_c32_phi_;
            mvares.subsublead_jet_c33_phi = subsublead_jet_c33_phi_;
            mvares.subsublead_jet_c34_phi = subsublead_jet_c34_phi_;
            mvares.subsublead_jet_c35_phi = subsublead_jet_c35_phi_;
            mvares.subsublead_jet_c36_phi = subsublead_jet_c36_phi_;
            mvares.subsublead_jet_c37_phi = subsublead_jet_c37_phi_;
            mvares.subsublead_jet_c38_phi = subsublead_jet_c38_phi_;
            mvares.subsublead_jet_c39_phi = subsublead_jet_c39_phi_;
            mvares.subsublead_jet_c40_phi = subsublead_jet_c40_phi_;
            mvares.subsublead_jet_c41_phi = subsublead_jet_c41_phi_;
            mvares.subsublead_jet_c42_phi = subsublead_jet_c42_phi_;
            mvares.subsublead_jet_c43_phi = subsublead_jet_c43_phi_;
            mvares.subsublead_jet_c44_phi = subsublead_jet_c44_phi_;
            mvares.subsublead_jet_c45_phi = subsublead_jet_c45_phi_;
            mvares.subsublead_jet_c46_phi = subsublead_jet_c46_phi_;
            mvares.subsublead_jet_c47_phi = subsublead_jet_c47_phi_;
            mvares.subsublead_jet_c48_phi = subsublead_jet_c48_phi_;
            mvares.subsublead_jet_c49_phi = subsublead_jet_c49_phi_;
            mvares.subsublead_jet_c50_phi = subsublead_jet_c50_phi_;
            mvares.subsublead_jet_c51_phi = subsublead_jet_c51_phi_;
            mvares.subsublead_jet_c52_phi = subsublead_jet_c52_phi_;
            mvares.subsublead_jet_c53_phi = subsublead_jet_c53_phi_;
            mvares.subsublead_jet_c54_phi = subsublead_jet_c54_phi_;
            mvares.subsublead_jet_c55_phi = subsublead_jet_c55_phi_;
            mvares.subsublead_jet_c56_phi = subsublead_jet_c56_phi_;
            mvares.subsublead_jet_c57_phi = subsublead_jet_c57_phi_;
            mvares.subsublead_jet_c58_phi = subsublead_jet_c58_phi_;
            mvares.subsublead_jet_c59_phi = subsublead_jet_c59_phi_;
            mvares.subsublead_jet_c60_phi = subsublead_jet_c60_phi_;

            mvares.subsublead_jet_c1_charge =  subsublead_jet_c1_charge_;
            mvares.subsublead_jet_c2_charge =  subsublead_jet_c2_charge_;
            mvares.subsublead_jet_c3_charge =  subsublead_jet_c3_charge_;
            mvares.subsublead_jet_c4_charge =  subsublead_jet_c4_charge_;
            mvares.subsublead_jet_c5_charge =  subsublead_jet_c5_charge_;
            mvares.subsublead_jet_c6_charge =  subsublead_jet_c6_charge_;
            mvares.subsublead_jet_c7_charge =  subsublead_jet_c7_charge_;
            mvares.subsublead_jet_c8_charge =  subsublead_jet_c8_charge_;
            mvares.subsublead_jet_c9_charge =  subsublead_jet_c9_charge_;
            mvares.subsublead_jet_c10_charge =  subsublead_jet_c10_charge_;
            mvares.subsublead_jet_c11_charge =  subsublead_jet_c11_charge_;
            mvares.subsublead_jet_c12_charge =  subsublead_jet_c12_charge_;
            mvares.subsublead_jet_c13_charge =  subsublead_jet_c13_charge_;
            mvares.subsublead_jet_c14_charge =  subsublead_jet_c14_charge_;
            mvares.subsublead_jet_c15_charge =  subsublead_jet_c15_charge_;
            mvares.subsublead_jet_c16_charge =  subsublead_jet_c16_charge_;
            mvares.subsublead_jet_c17_charge =  subsublead_jet_c17_charge_;
            mvares.subsublead_jet_c18_charge =  subsublead_jet_c18_charge_;
            mvares.subsublead_jet_c19_charge =  subsublead_jet_c19_charge_;
            mvares.subsublead_jet_c20_charge =  subsublead_jet_c20_charge_;
            mvares.subsublead_jet_c21_charge =  subsublead_jet_c21_charge_;
            mvares.subsublead_jet_c22_charge =  subsublead_jet_c22_charge_;
            mvares.subsublead_jet_c23_charge =  subsublead_jet_c23_charge_;
            mvares.subsublead_jet_c24_charge =  subsublead_jet_c24_charge_;
            mvares.subsublead_jet_c25_charge =  subsublead_jet_c25_charge_;
            mvares.subsublead_jet_c26_charge =  subsublead_jet_c26_charge_;
            mvares.subsublead_jet_c27_charge =  subsublead_jet_c27_charge_;
            mvares.subsublead_jet_c28_charge =  subsublead_jet_c28_charge_;
            mvares.subsublead_jet_c29_charge =  subsublead_jet_c29_charge_;
            mvares.subsublead_jet_c30_charge =  subsublead_jet_c30_charge_;
            mvares.subsublead_jet_c31_charge =  subsublead_jet_c31_charge_;
            mvares.subsublead_jet_c32_charge =  subsublead_jet_c32_charge_;
            mvares.subsublead_jet_c33_charge =  subsublead_jet_c33_charge_;
            mvares.subsublead_jet_c34_charge =  subsublead_jet_c34_charge_;
            mvares.subsublead_jet_c35_charge =  subsublead_jet_c35_charge_;
            mvares.subsublead_jet_c36_charge =  subsublead_jet_c36_charge_;
            mvares.subsublead_jet_c37_charge =  subsublead_jet_c37_charge_;
            mvares.subsublead_jet_c38_charge =  subsublead_jet_c38_charge_;
            mvares.subsublead_jet_c39_charge =  subsublead_jet_c39_charge_;
            mvares.subsublead_jet_c40_charge =  subsublead_jet_c40_charge_;
            mvares.subsublead_jet_c41_charge =  subsublead_jet_c41_charge_;
            mvares.subsublead_jet_c42_charge =  subsublead_jet_c42_charge_;
            mvares.subsublead_jet_c43_charge =  subsublead_jet_c43_charge_;
            mvares.subsublead_jet_c44_charge =  subsublead_jet_c44_charge_;
            mvares.subsublead_jet_c45_charge =  subsublead_jet_c45_charge_;
            mvares.subsublead_jet_c46_charge =  subsublead_jet_c46_charge_;
            mvares.subsublead_jet_c47_charge =  subsublead_jet_c47_charge_;
            mvares.subsublead_jet_c48_charge =  subsublead_jet_c48_charge_;
            mvares.subsublead_jet_c49_charge =  subsublead_jet_c49_charge_;
            mvares.subsublead_jet_c50_charge =  subsublead_jet_c50_charge_;
            mvares.subsublead_jet_c51_charge =  subsublead_jet_c51_charge_;
            mvares.subsublead_jet_c52_charge =  subsublead_jet_c52_charge_;
            mvares.subsublead_jet_c53_charge =  subsublead_jet_c53_charge_;
            mvares.subsublead_jet_c54_charge =  subsublead_jet_c54_charge_;
            mvares.subsublead_jet_c55_charge =  subsublead_jet_c55_charge_;
            mvares.subsublead_jet_c56_charge =  subsublead_jet_c56_charge_;
            mvares.subsublead_jet_c57_charge =  subsublead_jet_c57_charge_;
            mvares.subsublead_jet_c58_charge =  subsublead_jet_c58_charge_;
            mvares.subsublead_jet_c59_charge =  subsublead_jet_c59_charge_;
            mvares.subsublead_jet_c60_charge =  subsublead_jet_c60_charge_;

            mvares.subsublead_jet_c1_pt = subsublead_jet_c1_pt_;
            mvares.subsublead_jet_c2_pt = subsublead_jet_c2_pt_;
            mvares.subsublead_jet_c3_pt = subsublead_jet_c3_pt_;
            mvares.subsublead_jet_c4_pt = subsublead_jet_c4_pt_;
            mvares.subsublead_jet_c5_pt = subsublead_jet_c5_pt_;
            mvares.subsublead_jet_c6_pt = subsublead_jet_c6_pt_;
            mvares.subsublead_jet_c7_pt = subsublead_jet_c7_pt_;
            mvares.subsublead_jet_c8_pt = subsublead_jet_c8_pt_;
            mvares.subsublead_jet_c9_pt = subsublead_jet_c9_pt_;
            mvares.subsublead_jet_c10_pt = subsublead_jet_c10_pt_;
            mvares.subsublead_jet_c11_pt = subsublead_jet_c11_pt_;
            mvares.subsublead_jet_c12_pt = subsublead_jet_c12_pt_;
            mvares.subsublead_jet_c13_pt = subsublead_jet_c13_pt_;
            mvares.subsublead_jet_c14_pt = subsublead_jet_c14_pt_;
            mvares.subsublead_jet_c15_pt = subsublead_jet_c15_pt_;
            mvares.subsublead_jet_c16_pt = subsublead_jet_c16_pt_;
            mvares.subsublead_jet_c17_pt = subsublead_jet_c17_pt_;
            mvares.subsublead_jet_c18_pt = subsublead_jet_c18_pt_;
            mvares.subsublead_jet_c19_pt = subsublead_jet_c19_pt_;
            mvares.subsublead_jet_c20_pt = subsublead_jet_c20_pt_;
            mvares.subsublead_jet_c21_pt = subsublead_jet_c21_pt_;
            mvares.subsublead_jet_c22_pt = subsublead_jet_c22_pt_;
            mvares.subsublead_jet_c23_pt = subsublead_jet_c23_pt_;
            mvares.subsublead_jet_c24_pt = subsublead_jet_c24_pt_;
            mvares.subsublead_jet_c25_pt = subsublead_jet_c25_pt_;
            mvares.subsublead_jet_c26_pt = subsublead_jet_c26_pt_;
            mvares.subsublead_jet_c27_pt = subsublead_jet_c27_pt_;
            mvares.subsublead_jet_c28_pt = subsublead_jet_c28_pt_;
            mvares.subsublead_jet_c29_pt = subsublead_jet_c29_pt_;
            mvares.subsublead_jet_c30_pt = subsublead_jet_c30_pt_;
            mvares.subsublead_jet_c31_pt = subsublead_jet_c31_pt_;
            mvares.subsublead_jet_c32_pt = subsublead_jet_c32_pt_;
            mvares.subsublead_jet_c33_pt = subsublead_jet_c33_pt_;
            mvares.subsublead_jet_c34_pt = subsublead_jet_c34_pt_;
            mvares.subsublead_jet_c35_pt = subsublead_jet_c35_pt_;
            mvares.subsublead_jet_c36_pt = subsublead_jet_c36_pt_;
            mvares.subsublead_jet_c37_pt = subsublead_jet_c37_pt_;
            mvares.subsublead_jet_c38_pt = subsublead_jet_c38_pt_;
            mvares.subsublead_jet_c39_pt = subsublead_jet_c39_pt_;
            mvares.subsublead_jet_c40_pt = subsublead_jet_c40_pt_;
            mvares.subsublead_jet_c41_pt = subsublead_jet_c41_pt_;
            mvares.subsublead_jet_c42_pt = subsublead_jet_c42_pt_;
            mvares.subsublead_jet_c43_pt = subsublead_jet_c43_pt_;
            mvares.subsublead_jet_c44_pt = subsublead_jet_c44_pt_;
            mvares.subsublead_jet_c45_pt = subsublead_jet_c45_pt_;
            mvares.subsublead_jet_c46_pt = subsublead_jet_c46_pt_;
            mvares.subsublead_jet_c47_pt = subsublead_jet_c47_pt_;
            mvares.subsublead_jet_c48_pt = subsublead_jet_c48_pt_;
            mvares.subsublead_jet_c49_pt = subsublead_jet_c49_pt_;
            mvares.subsublead_jet_c50_pt = subsublead_jet_c50_pt_;
            mvares.subsublead_jet_c51_pt = subsublead_jet_c51_pt_;
            mvares.subsublead_jet_c52_pt = subsublead_jet_c52_pt_;
            mvares.subsublead_jet_c53_pt = subsublead_jet_c53_pt_;
            mvares.subsublead_jet_c54_pt = subsublead_jet_c54_pt_;
            mvares.subsublead_jet_c55_pt = subsublead_jet_c55_pt_;
            mvares.subsublead_jet_c56_pt = subsublead_jet_c56_pt_;
            mvares.subsublead_jet_c57_pt = subsublead_jet_c57_pt_;
            mvares.subsublead_jet_c58_pt = subsublead_jet_c58_pt_;
            mvares.subsublead_jet_c59_pt = subsublead_jet_c59_pt_;
            mvares.subsublead_jet_c60_pt = subsublead_jet_c60_pt_;

            mvares.subsublead_jet_c1_energy = subsublead_jet_c1_energy_;
            mvares.subsublead_jet_c2_energy = subsublead_jet_c2_energy_;
            mvares.subsublead_jet_c3_energy = subsublead_jet_c3_energy_;
            mvares.subsublead_jet_c4_energy = subsublead_jet_c4_energy_;
            mvares.subsublead_jet_c5_energy = subsublead_jet_c5_energy_;
            mvares.subsublead_jet_c6_energy = subsublead_jet_c6_energy_;
            mvares.subsublead_jet_c7_energy = subsublead_jet_c7_energy_;
            mvares.subsublead_jet_c8_energy = subsublead_jet_c8_energy_;
            mvares.subsublead_jet_c9_energy = subsublead_jet_c9_energy_;
            mvares.subsublead_jet_c10_energy = subsublead_jet_c10_energy_;
            mvares.subsublead_jet_c11_energy = subsublead_jet_c11_energy_;
            mvares.subsublead_jet_c12_energy = subsublead_jet_c12_energy_;
            mvares.subsublead_jet_c13_energy = subsublead_jet_c13_energy_;
            mvares.subsublead_jet_c14_energy = subsublead_jet_c14_energy_;
            mvares.subsublead_jet_c15_energy = subsublead_jet_c15_energy_;
            mvares.subsublead_jet_c16_energy = subsublead_jet_c16_energy_;
            mvares.subsublead_jet_c17_energy = subsublead_jet_c17_energy_;
            mvares.subsublead_jet_c18_energy = subsublead_jet_c18_energy_;
            mvares.subsublead_jet_c19_energy = subsublead_jet_c19_energy_;
            mvares.subsublead_jet_c20_energy = subsublead_jet_c20_energy_;
            mvares.subsublead_jet_c21_energy = subsublead_jet_c21_energy_;
            mvares.subsublead_jet_c22_energy = subsublead_jet_c22_energy_;
            mvares.subsublead_jet_c23_energy = subsublead_jet_c23_energy_;
            mvares.subsublead_jet_c24_energy = subsublead_jet_c24_energy_;
            mvares.subsublead_jet_c25_energy = subsublead_jet_c25_energy_;
            mvares.subsublead_jet_c26_energy = subsublead_jet_c26_energy_;
            mvares.subsublead_jet_c27_energy = subsublead_jet_c27_energy_;
            mvares.subsublead_jet_c28_energy = subsublead_jet_c28_energy_;
            mvares.subsublead_jet_c29_energy = subsublead_jet_c29_energy_;
            mvares.subsublead_jet_c30_energy = subsublead_jet_c30_energy_;
            mvares.subsublead_jet_c31_energy = subsublead_jet_c31_energy_;
            mvares.subsublead_jet_c32_energy = subsublead_jet_c32_energy_;
            mvares.subsublead_jet_c33_energy = subsublead_jet_c33_energy_;
            mvares.subsublead_jet_c34_energy = subsublead_jet_c34_energy_;
            mvares.subsublead_jet_c35_energy = subsublead_jet_c35_energy_;
            mvares.subsublead_jet_c36_energy = subsublead_jet_c36_energy_;
            mvares.subsublead_jet_c37_energy = subsublead_jet_c37_energy_;
            mvares.subsublead_jet_c38_energy = subsublead_jet_c38_energy_;
            mvares.subsublead_jet_c39_energy = subsublead_jet_c39_energy_;
            mvares.subsublead_jet_c40_energy = subsublead_jet_c40_energy_;
            mvares.subsublead_jet_c41_energy = subsublead_jet_c41_energy_;
            mvares.subsublead_jet_c42_energy = subsublead_jet_c42_energy_;
            mvares.subsublead_jet_c43_energy = subsublead_jet_c43_energy_;
            mvares.subsublead_jet_c44_energy = subsublead_jet_c44_energy_;
            mvares.subsublead_jet_c45_energy = subsublead_jet_c45_energy_;
            mvares.subsublead_jet_c46_energy = subsublead_jet_c46_energy_;
            mvares.subsublead_jet_c47_energy = subsublead_jet_c47_energy_;
            mvares.subsublead_jet_c48_energy = subsublead_jet_c48_energy_;
            mvares.subsublead_jet_c49_energy = subsublead_jet_c49_energy_;
            mvares.subsublead_jet_c50_energy = subsublead_jet_c50_energy_;
            mvares.subsublead_jet_c51_energy = subsublead_jet_c51_energy_;
            mvares.subsublead_jet_c52_energy = subsublead_jet_c52_energy_;
            mvares.subsublead_jet_c53_energy = subsublead_jet_c53_energy_;
            mvares.subsublead_jet_c54_energy = subsublead_jet_c54_energy_;
            mvares.subsublead_jet_c55_energy = subsublead_jet_c55_energy_;
            mvares.subsublead_jet_c56_energy = subsublead_jet_c56_energy_;
            mvares.subsublead_jet_c57_energy = subsublead_jet_c57_energy_;
            mvares.subsublead_jet_c58_energy = subsublead_jet_c58_energy_;
            mvares.subsublead_jet_c59_energy = subsublead_jet_c59_energy_;
            mvares.subsublead_jet_c60_energy = subsublead_jet_c60_energy_;

            mvares.dipho_PToM        = dipho_PToM_ ;
            mvares.sublPho_PToM      = sublPho_PToM_ ;
            mvares.leadPho_PToM      = leadPho_PToM_ ;
            mvares.dijet_minDRJetPho = dijet_minDRJetPho_;
            mvares.dijet_dy          = dijet_dy_;
            mvares.dijet_dipho_pt    = dijet_dipho_pt_ ;
            mvares.dijet_leady       = dijet_leady_   ;
            mvares.dijet_subleady    = dijet_subleady_;
            
            vbf_results->push_back( mvares );
        }
        evt.put( std::move( vbf_results ) );
        //std::cout << "" << std::endl;
        //std::cout << "next event" << std::endl;
    }
}

typedef flashgg::VBFMVAProducer FlashggVBFMVAProducer;
DEFINE_FWK_MODULE( FlashggVBFMVAProducer );
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4

