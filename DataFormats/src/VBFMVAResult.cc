#include "flashgg/DataFormats/interface/VBFMVAResult.h"


namespace flashgg {
    VBFMVAResult::VBFMVAResult () :
        leadJet                (),
        subleadJet             (),
        subsubleadJet          (),
        leadJet_ptr            (),
        subleadJet_ptr         (),
        subsubleadJet_ptr      (),
        hasValidVBFTriJet      (  0),
        n_rec_jets             ( -1),
        n_gen_jets             ( -1),
        n_diphotons            ( -1),
        dijet_leadEta          ( -9999. ),
        dijet_subleadEta       ( -9999. ),
        dijet_abs_dEta         ( -9999. ),
        dijet_LeadJPt          ( -9999. ),
        dijet_pt          ( -9999. ),
        dijet_SubJPt           ( -9999. ),
        dijet_Zep              ( -9999. ),
        dijet_dphi_trunc       ( -9999. ),
        dijet_dipho_dphi       ( -9999. ),
        dijet_dphi             ( -9999. ),
        dijet_Mjj              ( -9999. ),
        dijet_dy               ( -9999. ),
        dijet_leady            ( -9999. ),
        dijet_subleady         ( -9999. ),
        dijet_dipho_pt         ( -9999. ),
        dijet_minDRJetPho      ( -9999. ),
        dijet_centrality_gg    ( -9999. ),
        dijet_centrality_j3    ( -9999. ),
        dijet_centrality_g     ( -9999. ),
  
        constit_energy         ( -9999. ),
        n_constits             ( -9999. ),

        lead_jet_pt            ( -9999. ),
        test_lead_jet_eta            ( -9999. ),

        lead_jet_c1_eta       ( -9999. ),
        lead_jet_c2_eta      ( -9999. ),
        lead_jet_c3_eta      ( -9999. ),
        lead_jet_c4_eta      ( -9999. ),
        lead_jet_c5_eta      ( -9999. ),
        lead_jet_c6_eta      ( -9999. ),
        lead_jet_c7_eta      ( -9999. ),
        lead_jet_c8_eta      ( -9999. ),
        lead_jet_c1_phi      ( -9999. ),
        lead_jet_c2_phi      ( -9999. ),
        lead_jet_c3_phi      ( -9999. ),
        lead_jet_c4_phi      ( -9999. ),
        lead_jet_c5_phi      ( -9999. ),
        lead_jet_c6_phi      ( -9999. ),
        lead_jet_c7_phi      ( -9999. ),  
        lead_jet_c8_phi      ( -9999. ),
        lead_jet_c1_charge   ( -9999. ),
        lead_jet_c2_charge   ( -9999. ),
        lead_jet_c3_charge   ( -9999. ),
        lead_jet_c4_charge   ( -9999. ),
        lead_jet_c5_charge   ( -9999. ),
        lead_jet_c6_charge   ( -9999. ),
        lead_jet_c7_charge   ( -9999. ),
        lead_jet_c8_charge   ( -9999. ),
        lead_jet_c1_pt       ( -9999. ),
        lead_jet_c2_pt       ( -9999. ),
        lead_jet_c3_pt       ( -9999. ),
        lead_jet_c4_pt       ( -9999. ),
        lead_jet_c5_pt       ( -9999. ),
        lead_jet_c6_pt       ( -9999. ),
        lead_jet_c7_pt       ( -9999. ),
        lead_jet_c8_pt       ( -9999. ),
        lead_jet_c1_energy   ( -9999. ),
        lead_jet_c2_energy   ( -9999. ),
        lead_jet_c3_energy   ( -9999. ),
        lead_jet_c4_energy   ( -9999. ),
        lead_jet_c5_energy   ( -9999. ),
        lead_jet_c6_energy   ( -9999. ),
        lead_jet_c7_energy   ( -9999. ),
        lead_jet_c8_energy   ( -9999. ),

        sublead_jet_c1_eta       ( -9999. ),
        sublead_jet_c2_eta      ( -9999. ),
        sublead_jet_c3_eta      ( -9999. ),
        sublead_jet_c4_eta      ( -9999. ),
        sublead_jet_c5_eta      ( -9999. ),
        sublead_jet_c6_eta      ( -9999. ),
        sublead_jet_c7_eta      ( -9999. ),
        sublead_jet_c8_eta      ( -9999. ),
        sublead_jet_c1_phi      ( -9999. ),
        sublead_jet_c2_phi      ( -9999. ),
        sublead_jet_c3_phi      ( -9999. ),
        sublead_jet_c4_phi      ( -9999. ),
        sublead_jet_c5_phi      ( -9999. ),
        sublead_jet_c6_phi      ( -9999. ),
        sublead_jet_c7_phi      ( -9999. ),  
        sublead_jet_c8_phi      ( -9999. ),
        sublead_jet_c1_charge   ( -9999. ),
        sublead_jet_c2_charge   ( -9999. ),
        sublead_jet_c3_charge   ( -9999. ),
        sublead_jet_c4_charge   ( -9999. ),
        sublead_jet_c5_charge   ( -9999. ),
        sublead_jet_c6_charge   ( -9999. ),
        sublead_jet_c7_charge   ( -9999. ),
        sublead_jet_c8_charge   ( -9999. ),
        sublead_jet_c1_pt       ( -9999. ),
        sublead_jet_c2_pt       ( -9999. ),
        sublead_jet_c3_pt       ( -9999. ),
        sublead_jet_c4_pt       ( -9999. ),
        sublead_jet_c5_pt       ( -9999. ),
        sublead_jet_c6_pt       ( -9999. ),
        sublead_jet_c7_pt       ( -9999. ),
        sublead_jet_c8_pt       ( -9999. ),
        sublead_jet_c1_energy   ( -9999. ),
        sublead_jet_c2_energy   ( -9999. ),
        sublead_jet_c3_energy   ( -9999. ),
        sublead_jet_c4_energy   ( -9999. ),
        sublead_jet_c5_energy   ( -9999. ),
        sublead_jet_c6_energy   ( -9999. ),
        sublead_jet_c7_energy   ( -9999. ),
        sublead_jet_c8_energy   ( -9999. ),

        subsublead_jet_c1_eta       ( -9999. ),
        subsublead_jet_c2_eta      ( -9999. ),
        subsublead_jet_c3_eta      ( -9999. ),
        subsublead_jet_c4_eta      ( -9999. ),
        subsublead_jet_c5_eta      ( -9999. ),
        subsublead_jet_c6_eta      ( -9999. ),
        subsublead_jet_c7_eta      ( -9999. ),
        subsublead_jet_c8_eta      ( -9999. ),
        subsublead_jet_c1_phi      ( -9999. ),
        subsublead_jet_c2_phi      ( -9999. ),
        subsublead_jet_c3_phi      ( -9999. ),
        subsublead_jet_c4_phi      ( -9999. ),
        subsublead_jet_c5_phi      ( -9999. ),
        subsublead_jet_c6_phi      ( -9999. ),
        subsublead_jet_c7_phi      ( -9999. ),  
        subsublead_jet_c8_phi      ( -9999. ),
        subsublead_jet_c1_charge   ( -9999. ),
        subsublead_jet_c2_charge   ( -9999. ),
        subsublead_jet_c3_charge   ( -9999. ),
        subsublead_jet_c4_charge   ( -9999. ),
        subsublead_jet_c5_charge   ( -9999. ),
        subsublead_jet_c6_charge   ( -9999. ),
        subsublead_jet_c7_charge   ( -9999. ),
        subsublead_jet_c8_charge   ( -9999. ),
        subsublead_jet_c1_pt       ( -9999. ),
        subsublead_jet_c2_pt       ( -9999. ),
        subsublead_jet_c3_pt       ( -9999. ),
        subsublead_jet_c4_pt       ( -9999. ),
        subsublead_jet_c5_pt       ( -9999. ),
        subsublead_jet_c6_pt       ( -9999. ),
        subsublead_jet_c7_pt       ( -9999. ),
        subsublead_jet_c8_pt       ( -9999. ),
        subsublead_jet_c1_energy   ( -9999. ),
        subsublead_jet_c2_energy   ( -9999. ),
        subsublead_jet_c3_energy   ( -9999. ),
        subsublead_jet_c4_energy   ( -9999. ),
        subsublead_jet_c5_energy   ( -9999. ),
        subsublead_jet_c6_energy   ( -9999. ),
        subsublead_jet_c7_energy   ( -9999. ),
        subsublead_jet_c8_energy   ( -9999. ),


        dipho_PToM             ( -9999. ),
        leadPho_PToM           ( -9999. ),
        sublPho_PToM           ( -9999. ),
        
        vbfMvaResult_value     ( -9999. ),
        vbfMvaResult_value_bdt ( -9999. ),
        vbfMvaResult_value_bdtg( -9999. )
    {}
    
    VBFMVAResult::VBFMVAResult( edm::Ptr<VBFMVAResult> x )
    {
        leadJet          = x->leadJet;
        subleadJet       = x->subleadJet;
        
        leadJet_ptr      = x->leadJet_ptr;
        subleadJet_ptr   = x->subleadJet_ptr;
        
        // 3-jets additional variables
        subsubleadJet     = x->subsubleadJet;
        subsubleadJet_ptr = x->subsubleadJet_ptr;
        hasValidVBFTriJet = x->hasValidVBFTriJet;
        
        n_rec_jets       = x->n_rec_jets;
        n_gen_jets       = x->n_gen_jets;
        n_diphotons      = x->n_diphotons;
        
        dijet_leadEta    = x->dijet_leadEta    ;
        dijet_leadEta    = x->dijet_leadEta    ;
        
        dijet_subleadEta = x->dijet_subleadEta ;
        dijet_LeadJPt    = x->dijet_LeadJPt    ;
        dijet_pt         = x->dijet_pt    ;
        dijet_SubJPt     = x->dijet_SubJPt     ; 
        dijet_Zep        = x->dijet_Zep        ;
        
        dijet_dphi_trunc = x->dijet_dphi_trunc ;
        dijet_dipho_dphi = x->dijet_dipho_dphi ;
        dijet_dphi       = x->dijet_dphi ;
        dijet_dipho_pt   = x->dijet_dipho_pt   ;
        dijet_Mjj        = x->dijet_Mjj        ;

        constit_energy   = x->constit_energy   ;
        n_constits       = x->n_constits       ;

        lead_jet_pt      = x->lead_jet_pt   ;
        test_lead_jet_eta      = x->test_lead_jet_eta   ;

        lead_jet_c1_eta   =   x->lead_jet_c1_eta;
        lead_jet_c2_eta   =   x->lead_jet_c2_eta;      
        lead_jet_c3_eta   =   x->lead_jet_c3_eta;      
        lead_jet_c4_eta   =   x->lead_jet_c4_eta;      
        lead_jet_c5_eta   =   x->lead_jet_c5_eta;      
        lead_jet_c6_eta   =   x->lead_jet_c6_eta;      
        lead_jet_c7_eta   =   x->lead_jet_c7_eta;      
        lead_jet_c8_eta   =   x->lead_jet_c8_eta;      
        lead_jet_c1_phi   =   x->lead_jet_c1_phi;      
        lead_jet_c2_phi   =   x->lead_jet_c2_phi;      
        lead_jet_c3_phi   =   x->lead_jet_c3_phi;      
        lead_jet_c4_phi   =   x->lead_jet_c4_phi;      
        lead_jet_c5_phi   =   x->lead_jet_c5_phi;      
        lead_jet_c6_phi   =   x->lead_jet_c6_phi;      
        lead_jet_c7_phi   =   x->lead_jet_c7_phi;       
        lead_jet_c8_phi   =   x->lead_jet_c8_phi;      
        lead_jet_c1_charge =   x->lead_jet_c1_charge;   
        lead_jet_c2_charge =   x->lead_jet_c2_charge;   
        lead_jet_c3_charge =   x->lead_jet_c3_charge;   
        lead_jet_c4_charge =   x->lead_jet_c4_charge;   
        lead_jet_c5_charge =   x->lead_jet_c5_charge;   
        lead_jet_c6_charge =   x->lead_jet_c6_charge;   
        lead_jet_c7_charge =   x->lead_jet_c7_charge;   
        lead_jet_c8_charge =   x->lead_jet_c8_charge;   
        lead_jet_c1_pt =    x->lead_jet_c1_pt;       
        lead_jet_c2_pt =    x->lead_jet_c2_pt;       
        lead_jet_c3_pt =    x->lead_jet_c3_pt;       
        lead_jet_c4_pt =    x->lead_jet_c4_pt;       
        lead_jet_c5_pt =    x->lead_jet_c5_pt;       
        lead_jet_c6_pt =    x->lead_jet_c6_pt;       
        lead_jet_c7_pt =    x->lead_jet_c7_pt;       
        lead_jet_c8_pt =    x->lead_jet_c8_pt;       
        lead_jet_c1_energy = x->lead_jet_c1_energy;   
        lead_jet_c2_energy = x->lead_jet_c2_energy;   
        lead_jet_c3_energy = x->lead_jet_c3_energy;   
        lead_jet_c4_energy = x->lead_jet_c4_energy;   
        lead_jet_c5_energy = x->lead_jet_c5_energy;   
        lead_jet_c6_energy = x->lead_jet_c6_energy;   
        lead_jet_c7_energy = x->lead_jet_c7_energy;   
        lead_jet_c8_energy = x->lead_jet_c8_energy;   

        sublead_jet_c1_eta   =   x->sublead_jet_c1_eta;
        sublead_jet_c2_eta   =   x->sublead_jet_c2_eta;      
        sublead_jet_c3_eta   =   x->sublead_jet_c3_eta;      
        sublead_jet_c4_eta   =   x->sublead_jet_c4_eta;      
        sublead_jet_c5_eta   =   x->sublead_jet_c5_eta;      
        sublead_jet_c6_eta   =   x->sublead_jet_c6_eta;      
        sublead_jet_c7_eta   =   x->sublead_jet_c7_eta;      
        sublead_jet_c8_eta   =   x->sublead_jet_c8_eta;      
        sublead_jet_c1_phi   =   x->sublead_jet_c1_phi;      
        sublead_jet_c2_phi   =   x->sublead_jet_c2_phi;      
        sublead_jet_c3_phi   =   x->sublead_jet_c3_phi;      
        sublead_jet_c4_phi   =   x->sublead_jet_c4_phi;      
        sublead_jet_c5_phi   =   x->sublead_jet_c5_phi;      
        sublead_jet_c6_phi   =   x->sublead_jet_c6_phi;      
        sublead_jet_c7_phi   =   x->sublead_jet_c7_phi;       
        sublead_jet_c8_phi   =   x->sublead_jet_c8_phi;      
        sublead_jet_c1_charge =   x->sublead_jet_c1_charge;   
        sublead_jet_c2_charge =   x->sublead_jet_c2_charge;   
        sublead_jet_c3_charge =   x->sublead_jet_c3_charge;   
        sublead_jet_c4_charge =   x->sublead_jet_c4_charge;   
        sublead_jet_c5_charge =   x->sublead_jet_c5_charge;   
        sublead_jet_c6_charge =   x->sublead_jet_c6_charge;   
        sublead_jet_c7_charge =   x->sublead_jet_c7_charge;   
        sublead_jet_c8_charge =   x->sublead_jet_c8_charge;   
        sublead_jet_c1_pt =    x->sublead_jet_c1_pt;       
        sublead_jet_c2_pt =    x->sublead_jet_c2_pt;       
        sublead_jet_c3_pt =    x->sublead_jet_c3_pt;       
        sublead_jet_c4_pt =    x->sublead_jet_c4_pt;       
        sublead_jet_c5_pt =    x->sublead_jet_c5_pt;       
        sublead_jet_c6_pt =    x->sublead_jet_c6_pt;       
        sublead_jet_c7_pt =    x->sublead_jet_c7_pt;       
        sublead_jet_c8_pt =    x->sublead_jet_c8_pt;       
        sublead_jet_c1_energy = x->sublead_jet_c1_energy;   
        sublead_jet_c2_energy = x->sublead_jet_c2_energy;   
        sublead_jet_c3_energy = x->sublead_jet_c3_energy;   
        sublead_jet_c4_energy = x->sublead_jet_c4_energy;   
        sublead_jet_c5_energy = x->sublead_jet_c5_energy;   
        sublead_jet_c6_energy = x->sublead_jet_c6_energy;   
        sublead_jet_c7_energy = x->sublead_jet_c7_energy;   
        sublead_jet_c8_energy = x->sublead_jet_c8_energy;   
        
        subsublead_jet_c1_eta   =   x->subsublead_jet_c1_eta;
        subsublead_jet_c2_eta   =   x->subsublead_jet_c2_eta;      
        subsublead_jet_c3_eta   =   x->subsublead_jet_c3_eta;      
        subsublead_jet_c4_eta   =   x->subsublead_jet_c4_eta;      
        subsublead_jet_c5_eta   =   x->subsublead_jet_c5_eta;      
        subsublead_jet_c6_eta   =   x->subsublead_jet_c6_eta;      
        subsublead_jet_c7_eta   =   x->subsublead_jet_c7_eta;      
        subsublead_jet_c8_eta   =   x->subsublead_jet_c8_eta;      
        subsublead_jet_c1_phi   =   x->subsublead_jet_c1_phi;      
        subsublead_jet_c2_phi   =   x->subsublead_jet_c2_phi;      
        subsublead_jet_c3_phi   =   x->subsublead_jet_c3_phi;      
        subsublead_jet_c4_phi   =   x->subsublead_jet_c4_phi;      
        subsublead_jet_c5_phi   =   x->subsublead_jet_c5_phi;      
        subsublead_jet_c6_phi   =   x->subsublead_jet_c6_phi;      
        subsublead_jet_c7_phi   =   x->subsublead_jet_c7_phi;       
        subsublead_jet_c8_phi   =   x->subsublead_jet_c8_phi;      
        subsublead_jet_c1_charge =   x->subsublead_jet_c1_charge;   
        subsublead_jet_c2_charge =   x->subsublead_jet_c2_charge;   
        subsublead_jet_c3_charge =   x->subsublead_jet_c3_charge;   
        subsublead_jet_c4_charge =   x->subsublead_jet_c4_charge;   
        subsublead_jet_c5_charge =   x->subsublead_jet_c5_charge;   
        subsublead_jet_c6_charge =   x->subsublead_jet_c6_charge;   
        subsublead_jet_c7_charge =   x->subsublead_jet_c7_charge;   
        subsublead_jet_c8_charge =   x->subsublead_jet_c8_charge;   
        subsublead_jet_c1_pt =    x->subsublead_jet_c1_pt;       
        subsublead_jet_c2_pt =    x->subsublead_jet_c2_pt;       
        subsublead_jet_c3_pt =    x->subsublead_jet_c3_pt;       
        subsublead_jet_c4_pt =    x->subsublead_jet_c4_pt;       
        subsublead_jet_c5_pt =    x->subsublead_jet_c5_pt;       
        subsublead_jet_c6_pt =    x->subsublead_jet_c6_pt;       
        subsublead_jet_c7_pt =    x->subsublead_jet_c7_pt;       
        subsublead_jet_c8_pt =    x->subsublead_jet_c8_pt;       
        subsublead_jet_c1_energy = x->subsublead_jet_c1_energy;   
        subsublead_jet_c2_energy = x->subsublead_jet_c2_energy;   
        subsublead_jet_c3_energy = x->subsublead_jet_c3_energy;   
        subsublead_jet_c4_energy = x->subsublead_jet_c4_energy;   
        subsublead_jet_c5_energy = x->subsublead_jet_c5_energy;   
        subsublead_jet_c6_energy = x->subsublead_jet_c6_energy;   
        subsublead_jet_c7_energy = x->subsublead_jet_c7_energy;   
        subsublead_jet_c8_energy = x->subsublead_jet_c8_energy;   

        dipho_PToM       = x->dipho_PToM     ;
        leadPho_PToM     = x->leadPho_PToM   ;
        sublPho_PToM     = x->sublPho_PToM   ;
        dijet_minDRJetPho= x->dijet_minDRJetPho    ;

        dijet_centrality_gg = x->dijet_centrality_gg ;
        dijet_centrality_g  = x->dijet_centrality_g ;
        dijet_centrality_j3 = x->dijet_centrality_j3 ;
        
        dijet_leady      = x->dijet_leady    ;
        dijet_subleady   = x->dijet_subleady ;
        dijet_dy         = x->dijet_dy;
        
        // VBF MVA results different methods
        // need to be remove at some point ?
        vbfMvaResult_value      = x->vbfMvaResult_value;
        vbfMvaResult_value_bdt  = x->vbfMvaResult_value_bdt;
        vbfMvaResult_value_bdtg = x->vbfMvaResult_value_bdtg;
    }
}
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4

