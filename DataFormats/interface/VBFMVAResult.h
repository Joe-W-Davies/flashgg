#ifndef FLASHgg_VBFMVAResult_h
#define FLASHgg_VBFMVAResult_h

#include "DataFormats/Common/interface/Ptr.h"
#include "flashgg/DataFormats/interface/DiPhotonCandidate.h"
#include "flashgg/DataFormats/interface/Jet.h"

namespace flashgg {
    
    class VBFMVAResult
    {
        
    public:
        VBFMVAResult();
        VBFMVAResult( edm::Ptr<VBFMVAResult> );
        virtual ~VBFMVAResult() {}
        // diJet Info
        //flashgg::Jet leadJet;
        //flashgg::Jet subleadJet;
        // 3rd jet
        //flashgg::Jet subsubleadJet;
        reco::Candidate::LorentzVector leadJet;
        reco::Candidate::LorentzVector subleadJet;
        reco::Candidate::LorentzVector subsubleadJet;
        
        edm::Ptr<flashgg::Jet> leadJet_ptr;
        edm::Ptr<flashgg::Jet> subleadJet_ptr;
        // 3rd jet
        edm::Ptr<flashgg::Jet> subsubleadJet_ptr; 
        // 4-vec of the 3 jets
        
        
        bool hasValidVBFTriJet;
        
        // di-photon info 
        // flashgg::DiPhotonCandidate diphoton;
        
        // event based variables
        int  n_rec_jets;
        int  n_gen_jets;
        int  n_diphotons;
        
        // Input variables
        float dijet_leadEta ;
        float dijet_subleadEta;
        float dijet_abs_dEta;
        float dijet_LeadJPt ;
        float dijet_pt ;
        float dijet_SubJPt;
        float dijet_Zep;
        float dijet_dphi_trunc;
        float dijet_dipho_dphi;
        float dijet_dphi;
        float dijet_Mjj;
        float dijet_dy;
        float dijet_leady ;
        float dijet_subleady;
        float dijet_dipho_pt;
        float dijet_minDRJetPho;
        float dijet_centrality_gg;
        float dijet_centrality_j3;
        float dijet_centrality_g ;

        float constit_energy;
        float n_constits;
 
        float lead_jet_pt;
        float test_lead_jet_eta;
        //flattened constit variables for lead, sublead and subsublead jets

        float lead_jet_c1_eta;
        float lead_jet_c2_eta;
        float lead_jet_c3_eta;
        float lead_jet_c4_eta;
        float lead_jet_c5_eta;
        float lead_jet_c6_eta;
        float lead_jet_c7_eta;
        float lead_jet_c8_eta;
        float lead_jet_c1_phi;
        float lead_jet_c2_phi;
        float lead_jet_c3_phi;
        float lead_jet_c4_phi;
        float lead_jet_c5_phi;
        float lead_jet_c6_phi;
        float lead_jet_c7_phi;
        float lead_jet_c8_phi;
        float lead_jet_c1_charge;
        float lead_jet_c2_charge;
        float lead_jet_c3_charge;
        float lead_jet_c4_charge;
        float lead_jet_c5_charge;
        float lead_jet_c6_charge;
        float lead_jet_c7_charge;
        float lead_jet_c8_charge;
        float lead_jet_c1_pt;
        float lead_jet_c2_pt;
        float lead_jet_c3_pt;
        float lead_jet_c4_pt;
        float lead_jet_c5_pt;
        float lead_jet_c6_pt;
        float lead_jet_c7_pt;
        float lead_jet_c8_pt;
        float lead_jet_c1_energy;
        float lead_jet_c2_energy;
        float lead_jet_c3_energy;
        float lead_jet_c4_energy;
        float lead_jet_c5_energy;
        float lead_jet_c6_energy;
        float lead_jet_c7_energy;
        float lead_jet_c8_energy;

        float sublead_jet_c1_eta;
        float sublead_jet_c2_eta;
        float sublead_jet_c3_eta;
        float sublead_jet_c4_eta;
        float sublead_jet_c5_eta;
        float sublead_jet_c6_eta;
        float sublead_jet_c7_eta;
        float sublead_jet_c8_eta;
        float sublead_jet_c1_phi;
        float sublead_jet_c2_phi;
        float sublead_jet_c3_phi;
        float sublead_jet_c4_phi;
        float sublead_jet_c5_phi;
        float sublead_jet_c6_phi;
        float sublead_jet_c7_phi;
        float sublead_jet_c8_phi;
        float sublead_jet_c1_charge;
        float sublead_jet_c2_charge;
        float sublead_jet_c3_charge;
        float sublead_jet_c4_charge;
        float sublead_jet_c5_charge;
        float sublead_jet_c6_charge;
        float sublead_jet_c7_charge;
        float sublead_jet_c8_charge;
        float sublead_jet_c1_pt;
        float sublead_jet_c2_pt;
        float sublead_jet_c3_pt;
        float sublead_jet_c4_pt;
        float sublead_jet_c5_pt;
        float sublead_jet_c6_pt;
        float sublead_jet_c7_pt;
        float sublead_jet_c8_pt;
        float sublead_jet_c1_energy;
        float sublead_jet_c2_energy;
        float sublead_jet_c3_energy;
        float sublead_jet_c4_energy;
        float sublead_jet_c5_energy;
        float sublead_jet_c6_energy;
        float sublead_jet_c7_energy;
        float sublead_jet_c8_energy;

        float subsublead_jet_c1_eta;
        float subsublead_jet_c2_eta;
        float subsublead_jet_c3_eta;
        float subsublead_jet_c4_eta;
        float subsublead_jet_c5_eta;
        float subsublead_jet_c6_eta;
        float subsublead_jet_c7_eta;
        float subsublead_jet_c8_eta;
        float subsublead_jet_c1_phi;
        float subsublead_jet_c2_phi;
        float subsublead_jet_c3_phi;
        float subsublead_jet_c4_phi;
        float subsublead_jet_c5_phi;
        float subsublead_jet_c6_phi;
        float subsublead_jet_c7_phi;
        float subsublead_jet_c8_phi;
        float subsublead_jet_c1_charge;
        float subsublead_jet_c2_charge;
        float subsublead_jet_c3_charge;
        float subsublead_jet_c4_charge;
        float subsublead_jet_c5_charge;
        float subsublead_jet_c6_charge;
        float subsublead_jet_c7_charge;
        float subsublead_jet_c8_charge;
        float subsublead_jet_c1_pt;
        float subsublead_jet_c2_pt;
        float subsublead_jet_c3_pt;
        float subsublead_jet_c4_pt;
        float subsublead_jet_c5_pt;
        float subsublead_jet_c6_pt;
        float subsublead_jet_c7_pt;
        float subsublead_jet_c8_pt;
        float subsublead_jet_c1_energy;
        float subsublead_jet_c2_energy;
        float subsublead_jet_c3_energy;
        float subsublead_jet_c4_energy;
        float subsublead_jet_c5_energy;
        float subsublead_jet_c6_energy;
        float subsublead_jet_c7_energy;
        float subsublead_jet_c8_energy;

        // some VH had variables
        float ptV; 
        float etaV; 
        float phiV; 
        float cosThetaStar; 
        
        float dipho_PToM;
        float leadPho_PToM;
        float sublPho_PToM;
        
        // some 3-jet based variables 
        
        float VBFMVAValue() const {return vbfMvaResult_value;}
        
        // Output
        float vbfMvaResult_value;
        float vbfMvaResult_value_bdt;
        float vbfMvaResult_value_bdtg;
    };
    
    typedef std::map<edm::Ptr<DiPhotonCandidate>, VBFMVAResult> VBFMVAResultMap;
    
}

#endif
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4

