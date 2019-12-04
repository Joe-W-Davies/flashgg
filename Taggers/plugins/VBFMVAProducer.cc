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
        float n_constits_;

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
        float lead_jet_c1_phi_;
        float lead_jet_c2_phi_;
        float lead_jet_c3_phi_;
        float lead_jet_c4_phi_;
        float lead_jet_c5_phi_;
        float lead_jet_c6_phi_;
        float lead_jet_c7_phi_;
        float lead_jet_c8_phi_;
        float lead_jet_c1_charge_;
        float lead_jet_c2_charge_;
        float lead_jet_c3_charge_;
        float lead_jet_c4_charge_;
        float lead_jet_c5_charge_;
        float lead_jet_c6_charge_;
        float lead_jet_c7_charge_;
        float lead_jet_c8_charge_;
        float lead_jet_c1_pt_;
        float lead_jet_c2_pt_;
        float lead_jet_c3_pt_;
        float lead_jet_c4_pt_;
        float lead_jet_c5_pt_;
        float lead_jet_c6_pt_;
        float lead_jet_c7_pt_;
        float lead_jet_c8_pt_;
        float lead_jet_c1_energy_;
        float lead_jet_c2_energy_;
        float lead_jet_c3_energy_;
        float lead_jet_c4_energy_;
        float lead_jet_c5_energy_;
        float lead_jet_c6_energy_;
        float lead_jet_c7_energy_;
        float lead_jet_c8_energy_;

        float sublead_jet_c1_eta_;
        float sublead_jet_c2_eta_;
        float sublead_jet_c3_eta_;
        float sublead_jet_c4_eta_;
        float sublead_jet_c5_eta_;
        float sublead_jet_c6_eta_;
        float sublead_jet_c7_eta_;
        float sublead_jet_c8_eta_;
        float sublead_jet_c1_phi_;
        float sublead_jet_c2_phi_;
        float sublead_jet_c3_phi_;
        float sublead_jet_c4_phi_;
        float sublead_jet_c5_phi_;
        float sublead_jet_c6_phi_;
        float sublead_jet_c7_phi_;
        float sublead_jet_c8_phi_;
        float sublead_jet_c1_charge_;
        float sublead_jet_c2_charge_;
        float sublead_jet_c3_charge_;
        float sublead_jet_c4_charge_;
        float sublead_jet_c5_charge_;
        float sublead_jet_c6_charge_;
        float sublead_jet_c7_charge_;
        float sublead_jet_c8_charge_;
        float sublead_jet_c1_pt_;
        float sublead_jet_c2_pt_;
        float sublead_jet_c3_pt_;
        float sublead_jet_c4_pt_;
        float sublead_jet_c5_pt_;
        float sublead_jet_c6_pt_;
        float sublead_jet_c7_pt_;
        float sublead_jet_c8_pt_;
        float sublead_jet_c1_energy_;
        float sublead_jet_c2_energy_;
        float sublead_jet_c3_energy_;
        float sublead_jet_c4_energy_;
        float sublead_jet_c5_energy_;
        float sublead_jet_c6_energy_;
        float sublead_jet_c7_energy_;
        float sublead_jet_c8_energy_;

        float subsublead_jet_c1_eta_;
        float subsublead_jet_c2_eta_;
        float subsublead_jet_c3_eta_;
        float subsublead_jet_c4_eta_;
        float subsublead_jet_c5_eta_;
        float subsublead_jet_c6_eta_;
        float subsublead_jet_c7_eta_;
        float subsublead_jet_c8_eta_;
        float subsublead_jet_c1_phi_;
        float subsublead_jet_c2_phi_;
        float subsublead_jet_c3_phi_;
        float subsublead_jet_c4_phi_;
        float subsublead_jet_c5_phi_;
        float subsublead_jet_c6_phi_;
        float subsublead_jet_c7_phi_;
        float subsublead_jet_c8_phi_;
        float subsublead_jet_c1_charge_;
        float subsublead_jet_c2_charge_;
        float subsublead_jet_c3_charge_;
        float subsublead_jet_c4_charge_;
        float subsublead_jet_c5_charge_;
        float subsublead_jet_c6_charge_;
        float subsublead_jet_c7_charge_;
        float subsublead_jet_c8_charge_;
        float subsublead_jet_c1_pt_;
        float subsublead_jet_c2_pt_;
        float subsublead_jet_c3_pt_;
        float subsublead_jet_c4_pt_;
        float subsublead_jet_c5_pt_;
        float subsublead_jet_c6_pt_;
        float subsublead_jet_c7_pt_;
        float subsublead_jet_c8_pt_;
        float subsublead_jet_c1_energy_;
        float subsublead_jet_c2_energy_;
        float subsublead_jet_c3_energy_;
        float subsublead_jet_c4_energy_;
        float subsublead_jet_c5_energy_;
        float subsublead_jet_c6_energy_;
        float subsublead_jet_c7_energy_;
        float subsublead_jet_c8_energy_;

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
      
        n_constits_       = -999.;

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
        lead_jet_c1_phi_  = -999.;
        lead_jet_c2_phi_  = -999.;
        lead_jet_c3_phi_  = -999.;
        lead_jet_c4_phi_  = -999.;
        lead_jet_c5_phi_  = -999.;
        lead_jet_c6_phi_  = -999.;
        lead_jet_c7_phi_  = -999.;
        lead_jet_c8_phi_  = -999.;
        lead_jet_c1_charge_ = -999.;
        lead_jet_c2_charge_ = -999.;
        lead_jet_c3_charge_ = -999.;
        lead_jet_c4_charge_ = -999.;
        lead_jet_c5_charge_ = -999.;
        lead_jet_c6_charge_ = -999.;
        lead_jet_c7_charge_ = -999.;
        lead_jet_c8_charge_ = -999.;
        lead_jet_c1_pt_ = -999.;
        lead_jet_c2_pt_ = -999.;
        lead_jet_c3_pt_ = -999.;
        lead_jet_c4_pt_ = -999.;
        lead_jet_c5_pt_ = -999.;
        lead_jet_c6_pt_ = -999.;
        lead_jet_c7_pt_ = -999.;
        lead_jet_c8_pt_ = -999.;
        lead_jet_c1_energy_ = -999.;
        lead_jet_c2_energy_ = -999.;
        lead_jet_c3_energy_ = -999.;
        lead_jet_c4_energy_ = -999.;
        lead_jet_c5_energy_ = -999.;
        lead_jet_c6_energy_ = -999.;
        lead_jet_c7_energy_ = -999.;
        lead_jet_c8_energy_ = -999.;

        sublead_jet_c1_eta_  = -999.;
        sublead_jet_c2_eta_  = -999.;
        sublead_jet_c3_eta_  = -999.;
        sublead_jet_c4_eta_  = -999.;
        sublead_jet_c5_eta_  = -999.;
        sublead_jet_c6_eta_  = -999.;
        sublead_jet_c7_eta_  = -999.;
        sublead_jet_c8_eta_  = -999.;
        sublead_jet_c1_phi_  = -999.;
        sublead_jet_c2_phi_  = -999.;
        sublead_jet_c3_phi_  = -999.;
        sublead_jet_c4_phi_  = -999.;
        sublead_jet_c5_phi_  = -999.;
        sublead_jet_c6_phi_  = -999.;
        sublead_jet_c7_phi_  = -999.;
        sublead_jet_c8_phi_  = -999.;
        sublead_jet_c1_charge_ = -999.;
        sublead_jet_c2_charge_ = -999.;
        sublead_jet_c3_charge_ = -999.;
        sublead_jet_c4_charge_ = -999.;
        sublead_jet_c5_charge_ = -999.;
        sublead_jet_c6_charge_ = -999.;
        sublead_jet_c7_charge_ = -999.;
        sublead_jet_c8_charge_ = -999.;
        sublead_jet_c1_pt_ = -999.;
        sublead_jet_c2_pt_ = -999.;
        sublead_jet_c3_pt_ = -999.;
        sublead_jet_c4_pt_ = -999.;
        sublead_jet_c5_pt_ = -999.;
        sublead_jet_c6_pt_ = -999.;
        sublead_jet_c7_pt_ = -999.;
        sublead_jet_c8_pt_ = -999.;
        sublead_jet_c1_energy_ = -999.;
        sublead_jet_c2_energy_ = -999.;
        sublead_jet_c3_energy_ = -999.;
        sublead_jet_c4_energy_ = -999.;
        sublead_jet_c5_energy_ = -999.;
        sublead_jet_c6_energy_ = -999.;
        sublead_jet_c7_energy_ = -999.;
        sublead_jet_c8_energy_ = -999.;

        subsublead_jet_c1_eta_  = -999.;
        subsublead_jet_c2_eta_  = -999.;
        subsublead_jet_c3_eta_  = -999.;
        subsublead_jet_c4_eta_  = -999.;
        subsublead_jet_c5_eta_  = -999.;
        subsublead_jet_c6_eta_  = -999.;
        subsublead_jet_c7_eta_  = -999.;
        subsublead_jet_c8_eta_  = -999.;
        subsublead_jet_c1_phi_  = -999.;
        subsublead_jet_c2_phi_  = -999.;
        subsublead_jet_c3_phi_  = -999.;
        subsublead_jet_c4_phi_  = -999.;
        subsublead_jet_c5_phi_  = -999.;
        subsublead_jet_c6_phi_  = -999.;
        subsublead_jet_c7_phi_  = -999.;
        subsublead_jet_c8_phi_  = -999.;
        subsublead_jet_c1_charge_ = -999.;
        subsublead_jet_c2_charge_ = -999.;
        subsublead_jet_c3_charge_ = -999.;
        subsublead_jet_c4_charge_ = -999.;
        subsublead_jet_c5_charge_ = -999.;
        subsublead_jet_c6_charge_ = -999.;
        subsublead_jet_c7_charge_ = -999.;
        subsublead_jet_c8_charge_ = -999.;
        subsublead_jet_c1_pt_ = -999.;
        subsublead_jet_c2_pt_ = -999.;
        subsublead_jet_c3_pt_ = -999.;
        subsublead_jet_c4_pt_ = -999.;
        subsublead_jet_c5_pt_ = -999.;
        subsublead_jet_c6_pt_ = -999.;
        subsublead_jet_c7_pt_ = -999.;
        subsublead_jet_c8_pt_ = -999.;
        subsublead_jet_c1_energy_ = -999.;
        subsublead_jet_c2_energy_ = -999.;
        subsublead_jet_c3_energy_ = -999.;
        subsublead_jet_c4_energy_ = -999.;
        subsublead_jet_c5_energy_ = -999.;
        subsublead_jet_c6_energy_ = -999.;
        subsublead_jet_c7_energy_ = -999.;
        subsublead_jet_c8_energy_ = -999.;

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
        
        if (_MVAMethod != ""){
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

            n_constits_       = -999.;
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
            lead_jet_c1_phi_  = -999.;
            lead_jet_c2_phi_  = -999.;
            lead_jet_c3_phi_  = -999.;
            lead_jet_c4_phi_  = -999.;
            lead_jet_c5_phi_  = -999.;
            lead_jet_c6_phi_  = -999.;
            lead_jet_c7_phi_  = -999.;
            lead_jet_c8_phi_  = -999.;
            lead_jet_c1_charge_ = -999.;
            lead_jet_c2_charge_ = -999.;
            lead_jet_c3_charge_ = -999.;
            lead_jet_c4_charge_ = -999.;
            lead_jet_c5_charge_ = -999.;
            lead_jet_c6_charge_ = -999.;
            lead_jet_c7_charge_ = -999.;
            lead_jet_c8_charge_ = -999.;
            lead_jet_c1_pt_ = -999.;
            lead_jet_c2_pt_ = -999.;
            lead_jet_c3_pt_ = -999.;
            lead_jet_c4_pt_ = -999.;
            lead_jet_c5_pt_ = -999.;
            lead_jet_c6_pt_ = -999.;
            lead_jet_c7_pt_ = -999.;
            lead_jet_c8_pt_ = -999.;
            lead_jet_c1_energy_ = -999.;
            lead_jet_c2_energy_ = -999.;
            lead_jet_c3_energy_ = -999.;
            lead_jet_c4_energy_ = -999.;
            lead_jet_c5_energy_ = -999.;
            lead_jet_c6_energy_ = -999.;
            lead_jet_c7_energy_ = -999.;
            lead_jet_c8_energy_ = -999.;
            
            sublead_jet_c1_eta_  = -999.;
            sublead_jet_c2_eta_  = -999.;
            sublead_jet_c3_eta_  = -999.;
            sublead_jet_c4_eta_  = -999.;
            sublead_jet_c5_eta_  = -999.;
            sublead_jet_c6_eta_  = -999.;
            sublead_jet_c7_eta_  = -999.;
            sublead_jet_c8_eta_  = -999.;
            sublead_jet_c1_phi_  = -999.;
            sublead_jet_c2_phi_  = -999.;
            sublead_jet_c3_phi_  = -999.;
            sublead_jet_c4_phi_  = -999.;
            sublead_jet_c5_phi_  = -999.;
            sublead_jet_c6_phi_  = -999.;
            sublead_jet_c7_phi_  = -999.;
            sublead_jet_c8_phi_  = -999.;
            sublead_jet_c1_charge_ = -999.;
            sublead_jet_c2_charge_ = -999.;
            sublead_jet_c3_charge_ = -999.;
            sublead_jet_c4_charge_ = -999.;
            sublead_jet_c5_charge_ = -999.;
            sublead_jet_c6_charge_ = -999.;
            sublead_jet_c7_charge_ = -999.;
            sublead_jet_c8_charge_ = -999.;
            sublead_jet_c1_pt_ = -999.;
            sublead_jet_c2_pt_ = -999.;
            sublead_jet_c3_pt_ = -999.;
            sublead_jet_c4_pt_ = -999.;
            sublead_jet_c5_pt_ = -999.;
            sublead_jet_c6_pt_ = -999.;
            sublead_jet_c7_pt_ = -999.;
            sublead_jet_c8_pt_ = -999.;
            sublead_jet_c1_energy_ = -999.;
            sublead_jet_c2_energy_ = -999.;
            sublead_jet_c3_energy_ = -999.;
            sublead_jet_c4_energy_ = -999.;
            sublead_jet_c5_energy_ = -999.;
            sublead_jet_c6_energy_ = -999.;
            sublead_jet_c7_energy_ = -999.;
            sublead_jet_c8_energy_ = -999.;

            subsublead_jet_c1_eta_  = -999.;
            subsublead_jet_c2_eta_  = -999.;
            subsublead_jet_c3_eta_  = -999.;
            subsublead_jet_c4_eta_  = -999.;
            subsublead_jet_c5_eta_  = -999.;
            subsublead_jet_c6_eta_  = -999.;
            subsublead_jet_c7_eta_  = -999.;
            subsublead_jet_c8_eta_  = -999.;
            subsublead_jet_c1_phi_  = -999.;
            subsublead_jet_c2_phi_  = -999.;
            subsublead_jet_c3_phi_  = -999.;
            subsublead_jet_c4_phi_  = -999.;
            subsublead_jet_c5_phi_  = -999.;
            subsublead_jet_c6_phi_  = -999.;
            subsublead_jet_c7_phi_  = -999.;
            subsublead_jet_c8_phi_  = -999.;
            subsublead_jet_c1_charge_ = -999.;
            subsublead_jet_c2_charge_ = -999.;
            subsublead_jet_c3_charge_ = -999.;
            subsublead_jet_c4_charge_ = -999.;
            subsublead_jet_c5_charge_ = -999.;
            subsublead_jet_c6_charge_ = -999.;
            subsublead_jet_c7_charge_ = -999.;
            subsublead_jet_c8_charge_ = -999.;
            subsublead_jet_c1_pt_ = -999.;
            subsublead_jet_c2_pt_ = -999.;
            subsublead_jet_c3_pt_ = -999.;
            subsublead_jet_c4_pt_ = -999.;
            subsublead_jet_c5_pt_ = -999.;
            subsublead_jet_c6_pt_ = -999.;
            subsublead_jet_c7_pt_ = -999.;
            subsublead_jet_c8_pt_ = -999.;
            subsublead_jet_c1_energy_ = -999.;
            subsublead_jet_c2_energy_ = -999.;
            subsublead_jet_c3_energy_ = -999.;
            subsublead_jet_c4_energy_ = -999.;
            subsublead_jet_c5_energy_ = -999.;
            subsublead_jet_c6_energy_ = -999.;
            subsublead_jet_c7_energy_ = -999.;
            subsublead_jet_c8_energy_ = -999.;

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
                  if(n_jets_count==1){
                    lead_jet_pt_ = jet->pt();
                    test_lead_jet_eta_ = jet->eta();
                  }
                  //std::cout << "n_jets_count = : " << n_jets_count <<std::endl;
                  //std::cout << "JET pt is " << jet->pt() << std::endl;
                  if (fjet.hasConstituentInfo()) {

                    std::vector<float> theConstitInfo = fjet.getConstituentInfo();
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
                    if(n_jets_count==1){//leading jet since pts are ordered
                      for(unsigned int i = 0; i< 8; i++){
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
                      } 
                    }
                    if(n_jets_count==2){//subleading jet since pts are ordered
                      for(unsigned int i = 0; i< 8; i++){
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
                      } 
                    }
                    if(n_jets_count==3){//subleading jet since pts are ordered
                      for(unsigned int i = 0; i<8 ; i++){
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
            

            if (_MVAMethod != "") {
                mvares.vbfMvaResult_value = VbfMva_->EvaluateMVA( _MVAMethod.c_str() );
                //mvares.vbfMvaResult_value = VbfMva_->GetProba( _MVAMethod.c_str() );
            }
            
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

            mvares.n_constits        = n_constits_;

            mvares.lead_jet_pt    = lead_jet_pt_ ;
            mvares.test_lead_jet_eta    = test_lead_jet_eta_ ;

            mvares.lead_jet_c1_eta = lead_jet_c1_eta_;
            //std::cout << "lead eta c1: " << lead_jet_c1_eta_;
            mvares.lead_jet_c2_eta = lead_jet_c2_eta_;
            //std::cout << "lead eta c2: " << lead_jet_c2_eta_;
            mvares.lead_jet_c3_eta = lead_jet_c3_eta_;
            //std::cout << "lead eta c3: " << lead_jet_c3_eta_;
            mvares.lead_jet_c4_eta = lead_jet_c4_eta_;
            //std::cout << "lead eta c4: " << lead_jet_c4_eta_;
            mvares.lead_jet_c5_eta = lead_jet_c5_eta_;
            //std::cout << "lead eta c5: " << lead_jet_c5_eta_;
            mvares.lead_jet_c6_eta = lead_jet_c6_eta_;
            //std::cout << "lead eta c6: " << lead_jet_c6_eta_;
            mvares.lead_jet_c7_eta = lead_jet_c7_eta_;
            //std::cout << "lead eta c7: " << lead_jet_c7_eta_;
            mvares.lead_jet_c8_eta = lead_jet_c8_eta_;
            //std::cout << "lead eta c8: " << lead_jet_c8_eta_;
            mvares.lead_jet_c1_phi = lead_jet_c1_phi_;
            mvares.lead_jet_c2_phi = lead_jet_c2_phi_;
            mvares.lead_jet_c3_phi = lead_jet_c3_phi_;
            mvares.lead_jet_c4_phi = lead_jet_c4_phi_;
            mvares.lead_jet_c5_phi = lead_jet_c5_phi_;
            mvares.lead_jet_c6_phi = lead_jet_c6_phi_;
            mvares.lead_jet_c7_phi = lead_jet_c7_phi_;
            mvares.lead_jet_c8_phi = lead_jet_c8_phi_;
            mvares.lead_jet_c1_charge =  lead_jet_c1_charge_;
            mvares.lead_jet_c2_charge =  lead_jet_c2_charge_;
            mvares.lead_jet_c3_charge =  lead_jet_c3_charge_;
            mvares.lead_jet_c4_charge =  lead_jet_c4_charge_;
            mvares.lead_jet_c5_charge =  lead_jet_c5_charge_;
            mvares.lead_jet_c6_charge =  lead_jet_c6_charge_;
            mvares.lead_jet_c7_charge =  lead_jet_c7_charge_;
            mvares.lead_jet_c8_charge =  lead_jet_c8_charge_;
            mvares.lead_jet_c1_pt = lead_jet_c1_pt_;
            mvares.lead_jet_c2_pt = lead_jet_c2_pt_;
            mvares.lead_jet_c3_pt = lead_jet_c3_pt_;
            mvares.lead_jet_c4_pt = lead_jet_c4_pt_;
            mvares.lead_jet_c5_pt = lead_jet_c5_pt_;
            mvares.lead_jet_c6_pt = lead_jet_c6_pt_;
            mvares.lead_jet_c7_pt = lead_jet_c7_pt_;
            mvares.lead_jet_c8_pt = lead_jet_c8_pt_;
            mvares.lead_jet_c1_energy = lead_jet_c1_energy_;
            mvares.lead_jet_c2_energy = lead_jet_c2_energy_;
            mvares.lead_jet_c3_energy = lead_jet_c3_energy_;
            mvares.lead_jet_c4_energy = lead_jet_c4_energy_;
            mvares.lead_jet_c5_energy = lead_jet_c5_energy_;
            mvares.lead_jet_c6_energy = lead_jet_c6_energy_;
            mvares.lead_jet_c7_energy = lead_jet_c7_energy_;
            mvares.lead_jet_c8_energy = lead_jet_c8_energy_;

            mvares.sublead_jet_c1_eta = sublead_jet_c1_eta_;
            //std::cout << "sub lead eta c1: " << sublead_jet_c1_eta_;
            mvares.sublead_jet_c2_eta = sublead_jet_c2_eta_;
            //std::cout << "sub lead eta c2: " << sublead_jet_c2_eta_;
            mvares.sublead_jet_c3_eta = sublead_jet_c3_eta_;
            //std::cout << "sub lead eta c3: " << sublead_jet_c3_eta_;
            mvares.sublead_jet_c4_eta = sublead_jet_c4_eta_;
            //std::cout << "sub lead eta c4: " << sublead_jet_c4_eta_;
            mvares.sublead_jet_c5_eta = sublead_jet_c5_eta_;
            //std::cout << "sub lead eta c5: " << sublead_jet_c5_eta_;
            mvares.sublead_jet_c6_eta = sublead_jet_c6_eta_;
            //std::cout << "sub lead eta c6: " << sublead_jet_c6_eta_;
            mvares.sublead_jet_c7_eta = sublead_jet_c7_eta_;
            //std::cout << "sub lead eta c7: " << sublead_jet_c7_eta_;
            mvares.sublead_jet_c8_eta = sublead_jet_c8_eta_;
            //std::cout << "sub lead eta c8: " << sublead_jet_c8_eta_;
            mvares.sublead_jet_c1_phi = sublead_jet_c1_phi_;
            mvares.sublead_jet_c2_phi = sublead_jet_c2_phi_;
            mvares.sublead_jet_c3_phi = sublead_jet_c3_phi_;
            mvares.sublead_jet_c4_phi = sublead_jet_c4_phi_;
            mvares.sublead_jet_c5_phi = sublead_jet_c5_phi_;
            mvares.sublead_jet_c6_phi = sublead_jet_c6_phi_;
            mvares.sublead_jet_c7_phi = sublead_jet_c7_phi_;
            mvares.sublead_jet_c8_phi = sublead_jet_c8_phi_;
            mvares.sublead_jet_c1_charge =  sublead_jet_c1_charge_;
            mvares.sublead_jet_c2_charge =  sublead_jet_c2_charge_;
            mvares.sublead_jet_c3_charge =  sublead_jet_c3_charge_;
            mvares.sublead_jet_c4_charge =  sublead_jet_c4_charge_;
            mvares.sublead_jet_c5_charge =  sublead_jet_c5_charge_;
            mvares.sublead_jet_c6_charge =  sublead_jet_c6_charge_;
            mvares.sublead_jet_c7_charge =  sublead_jet_c7_charge_;
            mvares.sublead_jet_c8_charge =  sublead_jet_c8_charge_;
            mvares.sublead_jet_c1_pt = sublead_jet_c1_pt_;
            mvares.sublead_jet_c2_pt = sublead_jet_c2_pt_;
            mvares.sublead_jet_c3_pt = sublead_jet_c3_pt_;
            mvares.sublead_jet_c4_pt = sublead_jet_c4_pt_;
            mvares.sublead_jet_c5_pt = sublead_jet_c5_pt_;
            mvares.sublead_jet_c6_pt = sublead_jet_c6_pt_;
            mvares.sublead_jet_c7_pt = sublead_jet_c7_pt_;
            mvares.sublead_jet_c8_pt = sublead_jet_c8_pt_;
            mvares.sublead_jet_c1_energy = sublead_jet_c1_energy_;
            mvares.sublead_jet_c2_energy = sublead_jet_c2_energy_;
            mvares.sublead_jet_c3_energy = sublead_jet_c3_energy_;
            mvares.sublead_jet_c4_energy = sublead_jet_c4_energy_;
            mvares.sublead_jet_c5_energy = sublead_jet_c5_energy_;
            mvares.sublead_jet_c6_energy = sublead_jet_c6_energy_;
            mvares.sublead_jet_c7_energy = sublead_jet_c7_energy_;
            mvares.sublead_jet_c8_energy = sublead_jet_c8_energy_;

            mvares.subsublead_jet_c1_eta = subsublead_jet_c1_eta_;
            //std::cout << "sub sub lead eta c1: " << subsublead_jet_c1_eta_;
            mvares.subsublead_jet_c2_eta = subsublead_jet_c2_eta_;
            //std::cout << "sub sub lead eta c2: " << subsublead_jet_c2_eta_;
            mvares.subsublead_jet_c3_eta = subsublead_jet_c3_eta_;
            //std::cout << "sub sub lead eta c3: " << subsublead_jet_c3_eta_;
            mvares.subsublead_jet_c4_eta = subsublead_jet_c4_eta_;
            //std::cout << "sub sub lead eta c4: " << subsublead_jet_c4_eta_;
            mvares.subsublead_jet_c5_eta = subsublead_jet_c5_eta_;
            //std::cout << "sub sub lead eta c5: " << subsublead_jet_c5_eta_;
            mvares.subsublead_jet_c6_eta = subsublead_jet_c6_eta_;
            //std::cout << "sub sub lead eta c6: " << subsublead_jet_c6_eta_;
            mvares.subsublead_jet_c7_eta = subsublead_jet_c7_eta_;
            //std::cout << "sub sub lead eta c7: " << subsublead_jet_c7_eta_;
            mvares.subsublead_jet_c8_eta = subsublead_jet_c8_eta_;
            //std::cout << "sub sub lead eta c8: " << subsublead_jet_c8_eta_;
            mvares.subsublead_jet_c1_phi = subsublead_jet_c1_phi_;
            mvares.subsublead_jet_c2_phi = subsublead_jet_c2_phi_;
            mvares.subsublead_jet_c3_phi = subsublead_jet_c3_phi_;
            mvares.subsublead_jet_c4_phi = subsublead_jet_c4_phi_;
            mvares.subsublead_jet_c5_phi = subsublead_jet_c5_phi_;
            mvares.subsublead_jet_c6_phi = subsublead_jet_c6_phi_;
            mvares.subsublead_jet_c7_phi = subsublead_jet_c7_phi_;
            mvares.subsublead_jet_c8_phi = subsublead_jet_c8_phi_;
            mvares.subsublead_jet_c1_charge =  subsublead_jet_c1_charge_;
            mvares.subsublead_jet_c2_charge =  subsublead_jet_c2_charge_;
            mvares.subsublead_jet_c3_charge =  subsublead_jet_c3_charge_;
            mvares.subsublead_jet_c4_charge =  subsublead_jet_c4_charge_;
            mvares.subsublead_jet_c5_charge =  subsublead_jet_c5_charge_;
            mvares.subsublead_jet_c6_charge =  subsublead_jet_c6_charge_;
            mvares.subsublead_jet_c7_charge =  subsublead_jet_c7_charge_;
            mvares.subsublead_jet_c8_charge =  subsublead_jet_c8_charge_;
            mvares.subsublead_jet_c1_pt = subsublead_jet_c1_pt_;
            mvares.subsublead_jet_c2_pt = subsublead_jet_c2_pt_;
            mvares.subsublead_jet_c3_pt = subsublead_jet_c3_pt_;
            mvares.subsublead_jet_c4_pt = subsublead_jet_c4_pt_;
            mvares.subsublead_jet_c5_pt = subsublead_jet_c5_pt_;
            mvares.subsublead_jet_c6_pt = subsublead_jet_c6_pt_;
            mvares.subsublead_jet_c7_pt = subsublead_jet_c7_pt_;
            mvares.subsublead_jet_c8_pt = subsublead_jet_c8_pt_;
            mvares.subsublead_jet_c1_energy = subsublead_jet_c1_energy_;
            mvares.subsublead_jet_c2_energy = subsublead_jet_c2_energy_;
            mvares.subsublead_jet_c3_energy = subsublead_jet_c3_energy_;
            mvares.subsublead_jet_c4_energy = subsublead_jet_c4_energy_;
            mvares.subsublead_jet_c5_energy = subsublead_jet_c5_energy_;
            mvares.subsublead_jet_c6_energy = subsublead_jet_c6_energy_;
            mvares.subsublead_jet_c7_energy = subsublead_jet_c7_energy_;
            mvares.subsublead_jet_c8_energy = subsublead_jet_c8_energy_;

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

