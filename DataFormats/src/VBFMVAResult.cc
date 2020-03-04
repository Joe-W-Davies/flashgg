#include "flashgg/DataFormats/interface/VBFMVAResult.h"
#include <vector>


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

        pt_J1                  ( -9999. ),
        eta_J1                 ( -9999. ),
        phi_J1                 ( -9999. ),
        charge_J1              ( -9999. ),
        energy_J1              ( -9999. ),
        flav_J1                ( -9999. ),

        pt_J2                  ( -9999. ),
        eta_J2                 ( -9999. ),
        phi_J2                 ( -9999. ),
        charge_J2              ( -9999. ),
        energy_J2              ( -9999. ),
        flav_J2                ( -9999. ),

        pt_J3                  ( -9999. ),
        eta_J3                 ( -9999. ),
        phi_J3                 ( -9999. ),
        charge_J3              ( -9999. ),
        energy_J3              ( -9999. ),
        flav_J3                ( -9999. ),

        n_constits             ( -9999. ),

        //test_vec               { -9999. },


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
        lead_jet_c9_eta      ( -9999. ),
        lead_jet_c10_eta      ( -9999. ),
        lead_jet_c11_eta      ( -9999. ),
        lead_jet_c12_eta      ( -9999. ),
        lead_jet_c13_eta      ( -9999. ),
        lead_jet_c14_eta      ( -9999. ),
        lead_jet_c15_eta      ( -9999. ),
        lead_jet_c16_eta      ( -9999. ),
        lead_jet_c17_eta      ( -9999. ),
        lead_jet_c18_eta      ( -9999. ),
        lead_jet_c19_eta      ( -9999. ),
        lead_jet_c20_eta      ( -9999. ),
        lead_jet_c21_eta      ( -9999. ),
        lead_jet_c22_eta      ( -9999. ),
        lead_jet_c23_eta      ( -9999. ),
        lead_jet_c24_eta      ( -9999. ),
        lead_jet_c25_eta      ( -9999. ),
        lead_jet_c26_eta      ( -9999. ),
        lead_jet_c27_eta      ( -9999. ),
        lead_jet_c28_eta      ( -9999. ),
        lead_jet_c29_eta      ( -9999. ),
        lead_jet_c30_eta      ( -9999. ),
        lead_jet_c31_eta      ( -9999. ),
        lead_jet_c32_eta      ( -9999. ),
        lead_jet_c33_eta      ( -9999. ),
        lead_jet_c34_eta      ( -9999. ),
        lead_jet_c35_eta      ( -9999. ),
        lead_jet_c36_eta      ( -9999. ),
        lead_jet_c37_eta      ( -9999. ),
        lead_jet_c38_eta      ( -9999. ),
        lead_jet_c39_eta      ( -9999. ),
        lead_jet_c40_eta      ( -9999. ),
        lead_jet_c41_eta      ( -9999. ),
        lead_jet_c42_eta      ( -9999. ),
        lead_jet_c43_eta      ( -9999. ),
        lead_jet_c44_eta      ( -9999. ),
        lead_jet_c45_eta      ( -9999. ),
        lead_jet_c46_eta      ( -9999. ),
        lead_jet_c47_eta      ( -9999. ),
        lead_jet_c48_eta      ( -9999. ),
        lead_jet_c49_eta      ( -9999. ),
        lead_jet_c50_eta      ( -9999. ),
        lead_jet_c51_eta      ( -9999. ),
        lead_jet_c52_eta      ( -9999. ),
        lead_jet_c53_eta      ( -9999. ),
        lead_jet_c54_eta      ( -9999. ),
        lead_jet_c55_eta      ( -9999. ),
        lead_jet_c56_eta      ( -9999. ),
        lead_jet_c57_eta      ( -9999. ),
        lead_jet_c58_eta      ( -9999. ),
        lead_jet_c59_eta      ( -9999. ),
        lead_jet_c60_eta      ( -9999. ),

        lead_jet_c1_phi      ( -9999. ),
        lead_jet_c2_phi      ( -9999. ),
        lead_jet_c3_phi      ( -9999. ),
        lead_jet_c4_phi      ( -9999. ),
        lead_jet_c5_phi      ( -9999. ),
        lead_jet_c6_phi      ( -9999. ),
        lead_jet_c7_phi      ( -9999. ),  
        lead_jet_c8_phi      ( -9999. ),
        lead_jet_c9_phi      ( -9999. ),
        lead_jet_c10_phi      ( -9999. ),
        lead_jet_c11_phi      ( -9999. ),
        lead_jet_c12_phi      ( -9999. ),
        lead_jet_c13_phi      ( -9999. ),
        lead_jet_c14_phi      ( -9999. ),
        lead_jet_c15_phi      ( -9999. ),
        lead_jet_c16_phi      ( -9999. ),
        lead_jet_c17_phi      ( -9999. ),
        lead_jet_c18_phi      ( -9999. ),
        lead_jet_c19_phi      ( -9999. ),
        lead_jet_c20_phi      ( -9999. ),
        lead_jet_c21_phi      ( -9999. ),
        lead_jet_c22_phi      ( -9999. ),
        lead_jet_c23_phi      ( -9999. ),
        lead_jet_c24_phi      ( -9999. ),
        lead_jet_c25_phi      ( -9999. ),
        lead_jet_c26_phi      ( -9999. ),
        lead_jet_c27_phi      ( -9999. ),
        lead_jet_c28_phi      ( -9999. ),
        lead_jet_c29_phi      ( -9999. ),
        lead_jet_c30_phi      ( -9999. ),
        lead_jet_c31_phi      ( -9999. ),
        lead_jet_c32_phi      ( -9999. ),
        lead_jet_c33_phi      ( -9999. ),
        lead_jet_c34_phi      ( -9999. ),
        lead_jet_c35_phi      ( -9999. ),
        lead_jet_c36_phi      ( -9999. ),
        lead_jet_c37_phi      ( -9999. ),
        lead_jet_c38_phi      ( -9999. ),
        lead_jet_c39_phi      ( -9999. ),
        lead_jet_c40_phi      ( -9999. ),
        lead_jet_c41_phi      ( -9999. ),
        lead_jet_c42_phi      ( -9999. ),
        lead_jet_c43_phi      ( -9999. ),
        lead_jet_c44_phi      ( -9999. ),
        lead_jet_c45_phi      ( -9999. ),
        lead_jet_c46_phi      ( -9999. ),
        lead_jet_c47_phi      ( -9999. ),
        lead_jet_c48_phi      ( -9999. ),
        lead_jet_c49_phi      ( -9999. ),
        lead_jet_c50_phi      ( -9999. ),
        lead_jet_c51_phi      ( -9999. ),
        lead_jet_c52_phi      ( -9999. ),
        lead_jet_c53_phi      ( -9999. ),
        lead_jet_c54_phi      ( -9999. ),
        lead_jet_c55_phi      ( -9999. ),
        lead_jet_c56_phi      ( -9999. ),
        lead_jet_c57_phi      ( -9999. ),
        lead_jet_c58_phi      ( -9999. ),
        lead_jet_c59_phi      ( -9999. ),
        lead_jet_c60_phi      ( -9999. ),

        lead_jet_c1_charge   ( -9999. ),
        lead_jet_c2_charge   ( -9999. ),
        lead_jet_c3_charge   ( -9999. ),
        lead_jet_c4_charge   ( -9999. ),
        lead_jet_c5_charge   ( -9999. ),
        lead_jet_c6_charge   ( -9999. ),
        lead_jet_c7_charge   ( -9999. ),
        lead_jet_c8_charge   ( -9999. ),
        lead_jet_c9_charge   ( -9999. ),
        lead_jet_c10_charge   ( -9999. ),
        lead_jet_c11_charge   ( -9999. ),
        lead_jet_c12_charge   ( -9999. ),
        lead_jet_c13_charge   ( -9999. ),
        lead_jet_c14_charge   ( -9999. ),
        lead_jet_c15_charge   ( -9999. ),
        lead_jet_c16_charge   ( -9999. ),
        lead_jet_c17_charge   ( -9999. ),
        lead_jet_c18_charge   ( -9999. ),
        lead_jet_c19_charge   ( -9999. ),
        lead_jet_c20_charge   ( -9999. ),
        lead_jet_c21_charge   ( -9999. ),
        lead_jet_c22_charge   ( -9999. ),
        lead_jet_c23_charge   ( -9999. ),
        lead_jet_c24_charge   ( -9999. ),
        lead_jet_c25_charge   ( -9999. ),
        lead_jet_c26_charge   ( -9999. ),
        lead_jet_c27_charge   ( -9999. ),
        lead_jet_c28_charge   ( -9999. ),
        lead_jet_c29_charge   ( -9999. ),
        lead_jet_c30_charge   ( -9999. ),
        lead_jet_c31_charge   ( -9999. ),
        lead_jet_c32_charge   ( -9999. ),
        lead_jet_c33_charge   ( -9999. ),
        lead_jet_c34_charge   ( -9999. ),
        lead_jet_c35_charge   ( -9999. ),
        lead_jet_c36_charge   ( -9999. ),
        lead_jet_c37_charge   ( -9999. ),
        lead_jet_c38_charge   ( -9999. ),
        lead_jet_c39_charge   ( -9999. ),
        lead_jet_c40_charge   ( -9999. ),
        lead_jet_c41_charge   ( -9999. ),
        lead_jet_c42_charge   ( -9999. ),
        lead_jet_c43_charge   ( -9999. ),
        lead_jet_c44_charge   ( -9999. ),
        lead_jet_c45_charge   ( -9999. ),
        lead_jet_c46_charge   ( -9999. ),
        lead_jet_c47_charge   ( -9999. ),
        lead_jet_c48_charge   ( -9999. ),
        lead_jet_c49_charge   ( -9999. ),
        lead_jet_c50_charge   ( -9999. ),
        lead_jet_c51_charge   ( -9999. ),
        lead_jet_c52_charge   ( -9999. ),
        lead_jet_c53_charge   ( -9999. ),
        lead_jet_c54_charge   ( -9999. ),
        lead_jet_c55_charge   ( -9999. ),
        lead_jet_c56_charge   ( -9999. ),
        lead_jet_c57_charge   ( -9999. ),
        lead_jet_c58_charge   ( -9999. ),
        lead_jet_c59_charge   ( -9999. ),
        lead_jet_c60_charge   ( -9999. ),

        lead_jet_c1_pt       ( -9999. ),
        lead_jet_c2_pt       ( -9999. ),
        lead_jet_c3_pt       ( -9999. ),
        lead_jet_c4_pt       ( -9999. ),
        lead_jet_c5_pt       ( -9999. ),
        lead_jet_c6_pt       ( -9999. ),
        lead_jet_c7_pt       ( -9999. ),
        lead_jet_c8_pt       ( -9999. ),
        lead_jet_c9_pt       ( -9999. ),
        lead_jet_c10_pt       ( -9999. ),
        lead_jet_c11_pt       ( -9999. ),
        lead_jet_c12_pt       ( -9999. ),
        lead_jet_c13_pt       ( -9999. ),
        lead_jet_c14_pt       ( -9999. ),
        lead_jet_c15_pt       ( -9999. ),
        lead_jet_c16_pt       ( -9999. ),
        lead_jet_c17_pt       ( -9999. ),
        lead_jet_c18_pt       ( -9999. ),
        lead_jet_c19_pt       ( -9999. ),
        lead_jet_c20_pt       ( -9999. ),
        lead_jet_c21_pt       ( -9999. ),
        lead_jet_c22_pt       ( -9999. ),
        lead_jet_c23_pt       ( -9999. ),
        lead_jet_c24_pt       ( -9999. ),
        lead_jet_c25_pt       ( -9999. ),
        lead_jet_c26_pt       ( -9999. ),
        lead_jet_c27_pt       ( -9999. ),
        lead_jet_c28_pt       ( -9999. ),
        lead_jet_c29_pt       ( -9999. ),
        lead_jet_c30_pt       ( -9999. ),
        lead_jet_c31_pt       ( -9999. ),
        lead_jet_c32_pt       ( -9999. ),
        lead_jet_c33_pt       ( -9999. ),
        lead_jet_c34_pt       ( -9999. ),
        lead_jet_c35_pt       ( -9999. ),
        lead_jet_c36_pt       ( -9999. ),
        lead_jet_c37_pt       ( -9999. ),
        lead_jet_c38_pt       ( -9999. ),
        lead_jet_c39_pt       ( -9999. ),
        lead_jet_c40_pt       ( -9999. ),
        lead_jet_c41_pt       ( -9999. ),
        lead_jet_c42_pt       ( -9999. ),
        lead_jet_c43_pt       ( -9999. ),
        lead_jet_c44_pt       ( -9999. ),
        lead_jet_c45_pt       ( -9999. ),
        lead_jet_c46_pt       ( -9999. ),
        lead_jet_c47_pt       ( -9999. ),
        lead_jet_c48_pt       ( -9999. ),
        lead_jet_c49_pt       ( -9999. ),
        lead_jet_c50_pt       ( -9999. ),
        lead_jet_c51_pt       ( -9999. ),
        lead_jet_c52_pt       ( -9999. ),
        lead_jet_c53_pt       ( -9999. ),
        lead_jet_c54_pt       ( -9999. ),
        lead_jet_c55_pt       ( -9999. ),
        lead_jet_c56_pt       ( -9999. ),
        lead_jet_c57_pt       ( -9999. ),
        lead_jet_c58_pt       ( -9999. ),
        lead_jet_c59_pt       ( -9999. ),
        lead_jet_c60_pt       ( -9999. ),

        lead_jet_c1_energy   ( -9999. ),
        lead_jet_c2_energy   ( -9999. ),
        lead_jet_c3_energy   ( -9999. ),
        lead_jet_c4_energy   ( -9999. ),
        lead_jet_c5_energy   ( -9999. ),
        lead_jet_c6_energy   ( -9999. ),
        lead_jet_c7_energy   ( -9999. ),
        lead_jet_c8_energy   ( -9999. ),
        lead_jet_c9_energy   ( -9999. ),
        lead_jet_c10_energy   ( -9999. ),
        lead_jet_c11_energy   ( -9999. ),
        lead_jet_c12_energy   ( -9999. ),
        lead_jet_c13_energy   ( -9999. ),
        lead_jet_c14_energy   ( -9999. ),
        lead_jet_c15_energy   ( -9999. ),
        lead_jet_c16_energy   ( -9999. ),
        lead_jet_c17_energy   ( -9999. ),
        lead_jet_c18_energy   ( -9999. ),
        lead_jet_c19_energy   ( -9999. ),
        lead_jet_c20_energy   ( -9999. ),
        lead_jet_c21_energy   ( -9999. ),
        lead_jet_c22_energy   ( -9999. ),
        lead_jet_c23_energy   ( -9999. ),
        lead_jet_c24_energy   ( -9999. ),
        lead_jet_c25_energy   ( -9999. ),
        lead_jet_c26_energy   ( -9999. ),
        lead_jet_c27_energy   ( -9999. ),
        lead_jet_c28_energy   ( -9999. ),
        lead_jet_c29_energy   ( -9999. ),
        lead_jet_c30_energy   ( -9999. ),
        lead_jet_c31_energy   ( -9999. ),
        lead_jet_c32_energy   ( -9999. ),
        lead_jet_c33_energy   ( -9999. ),
        lead_jet_c34_energy   ( -9999. ),
        lead_jet_c35_energy   ( -9999. ),
        lead_jet_c36_energy   ( -9999. ),
        lead_jet_c37_energy   ( -9999. ),
        lead_jet_c38_energy   ( -9999. ),
        lead_jet_c39_energy   ( -9999. ),
        lead_jet_c40_energy   ( -9999. ),
        lead_jet_c41_energy   ( -9999. ),
        lead_jet_c42_energy   ( -9999. ),
        lead_jet_c43_energy   ( -9999. ),
        lead_jet_c44_energy   ( -9999. ),
        lead_jet_c45_energy   ( -9999. ),
        lead_jet_c46_energy   ( -9999. ),
        lead_jet_c47_energy   ( -9999. ),
        lead_jet_c48_energy   ( -9999. ),
        lead_jet_c49_energy   ( -9999. ),
        lead_jet_c50_energy   ( -9999. ),
        lead_jet_c51_energy   ( -9999. ),
        lead_jet_c52_energy   ( -9999. ),
        lead_jet_c53_energy   ( -9999. ),
        lead_jet_c54_energy   ( -9999. ),
        lead_jet_c55_energy   ( -9999. ),
        lead_jet_c56_energy   ( -9999. ),
        lead_jet_c57_energy   ( -9999. ),
        lead_jet_c58_energy   ( -9999. ),
        lead_jet_c59_energy   ( -9999. ),
        lead_jet_c60_energy   ( -9999. ),

        sublead_jet_c1_eta       ( -9999. ),
        sublead_jet_c2_eta      ( -9999. ),
        sublead_jet_c3_eta      ( -9999. ),
        sublead_jet_c4_eta      ( -9999. ),
        sublead_jet_c5_eta      ( -9999. ),
        sublead_jet_c6_eta      ( -9999. ),
        sublead_jet_c7_eta      ( -9999. ),
        sublead_jet_c8_eta      ( -9999. ),
        sublead_jet_c9_eta      ( -9999. ),
        sublead_jet_c10_eta      ( -9999. ),
        sublead_jet_c11_eta      ( -9999. ),
        sublead_jet_c12_eta      ( -9999. ),
        sublead_jet_c13_eta      ( -9999. ),
        sublead_jet_c14_eta      ( -9999. ),
        sublead_jet_c15_eta      ( -9999. ),
        sublead_jet_c16_eta      ( -9999. ),
        sublead_jet_c17_eta      ( -9999. ),
        sublead_jet_c18_eta      ( -9999. ),
        sublead_jet_c19_eta      ( -9999. ),
        sublead_jet_c20_eta      ( -9999. ),
        sublead_jet_c21_eta      ( -9999. ),
        sublead_jet_c22_eta      ( -9999. ),
        sublead_jet_c23_eta      ( -9999. ),
        sublead_jet_c24_eta      ( -9999. ),
        sublead_jet_c25_eta      ( -9999. ),
        sublead_jet_c26_eta      ( -9999. ),
        sublead_jet_c27_eta      ( -9999. ),
        sublead_jet_c28_eta      ( -9999. ),
        sublead_jet_c29_eta      ( -9999. ),
        sublead_jet_c30_eta      ( -9999. ),
        sublead_jet_c31_eta      ( -9999. ),
        sublead_jet_c32_eta      ( -9999. ),
        sublead_jet_c33_eta      ( -9999. ),
        sublead_jet_c34_eta      ( -9999. ),
        sublead_jet_c35_eta      ( -9999. ),
        sublead_jet_c36_eta      ( -9999. ),
        sublead_jet_c37_eta      ( -9999. ),
        sublead_jet_c38_eta      ( -9999. ),
        sublead_jet_c39_eta      ( -9999. ),
        sublead_jet_c40_eta      ( -9999. ),
        sublead_jet_c41_eta      ( -9999. ),
        sublead_jet_c42_eta      ( -9999. ),
        sublead_jet_c43_eta      ( -9999. ),
        sublead_jet_c44_eta      ( -9999. ),
        sublead_jet_c45_eta      ( -9999. ),
        sublead_jet_c46_eta      ( -9999. ),
        sublead_jet_c47_eta      ( -9999. ),
        sublead_jet_c48_eta      ( -9999. ),
        sublead_jet_c49_eta      ( -9999. ),
        sublead_jet_c50_eta      ( -9999. ),
        sublead_jet_c51_eta      ( -9999. ),
        sublead_jet_c52_eta      ( -9999. ),
        sublead_jet_c53_eta      ( -9999. ),
        sublead_jet_c54_eta      ( -9999. ),
        sublead_jet_c55_eta      ( -9999. ),
        sublead_jet_c56_eta      ( -9999. ),
        sublead_jet_c57_eta      ( -9999. ),
        sublead_jet_c58_eta      ( -9999. ),
        sublead_jet_c59_eta      ( -9999. ),
        sublead_jet_c60_eta      ( -9999. ),

        sublead_jet_c1_phi      ( -9999. ),
        sublead_jet_c2_phi      ( -9999. ),
        sublead_jet_c3_phi      ( -9999. ),
        sublead_jet_c4_phi      ( -9999. ),
        sublead_jet_c5_phi      ( -9999. ),
        sublead_jet_c6_phi      ( -9999. ),
        sublead_jet_c7_phi      ( -9999. ),  
        sublead_jet_c8_phi      ( -9999. ),
        sublead_jet_c9_phi      ( -9999. ),
        sublead_jet_c10_phi      ( -9999. ),
        sublead_jet_c11_phi      ( -9999. ),
        sublead_jet_c12_phi      ( -9999. ),
        sublead_jet_c13_phi      ( -9999. ),
        sublead_jet_c14_phi      ( -9999. ),
        sublead_jet_c15_phi      ( -9999. ),
        sublead_jet_c16_phi      ( -9999. ),
        sublead_jet_c17_phi      ( -9999. ),
        sublead_jet_c18_phi      ( -9999. ),
        sublead_jet_c19_phi      ( -9999. ),
        sublead_jet_c20_phi      ( -9999. ),
        sublead_jet_c21_phi      ( -9999. ),
        sublead_jet_c22_phi      ( -9999. ),
        sublead_jet_c23_phi      ( -9999. ),
        sublead_jet_c24_phi      ( -9999. ),
        sublead_jet_c25_phi      ( -9999. ),
        sublead_jet_c26_phi      ( -9999. ),
        sublead_jet_c27_phi      ( -9999. ),
        sublead_jet_c28_phi      ( -9999. ),
        sublead_jet_c29_phi      ( -9999. ),
        sublead_jet_c30_phi      ( -9999. ),
        sublead_jet_c31_phi      ( -9999. ),
        sublead_jet_c32_phi      ( -9999. ),
        sublead_jet_c33_phi      ( -9999. ),
        sublead_jet_c34_phi      ( -9999. ),
        sublead_jet_c35_phi      ( -9999. ),
        sublead_jet_c36_phi      ( -9999. ),
        sublead_jet_c37_phi      ( -9999. ),
        sublead_jet_c38_phi      ( -9999. ),
        sublead_jet_c39_phi      ( -9999. ),
        sublead_jet_c40_phi      ( -9999. ),
        sublead_jet_c41_phi      ( -9999. ),
        sublead_jet_c42_phi      ( -9999. ),
        sublead_jet_c43_phi      ( -9999. ),
        sublead_jet_c44_phi      ( -9999. ),
        sublead_jet_c45_phi      ( -9999. ),
        sublead_jet_c46_phi      ( -9999. ),
        sublead_jet_c47_phi      ( -9999. ),
        sublead_jet_c48_phi      ( -9999. ),
        sublead_jet_c49_phi      ( -9999. ),
        sublead_jet_c50_phi      ( -9999. ),
        sublead_jet_c51_phi      ( -9999. ),
        sublead_jet_c52_phi      ( -9999. ),
        sublead_jet_c53_phi      ( -9999. ),
        sublead_jet_c54_phi      ( -9999. ),
        sublead_jet_c55_phi      ( -9999. ),
        sublead_jet_c56_phi      ( -9999. ),
        sublead_jet_c57_phi      ( -9999. ),
        sublead_jet_c58_phi      ( -9999. ),
        sublead_jet_c59_phi      ( -9999. ),
        sublead_jet_c60_phi      ( -9999. ),

        sublead_jet_c1_charge   ( -9999. ),
        sublead_jet_c2_charge   ( -9999. ),
        sublead_jet_c3_charge   ( -9999. ),
        sublead_jet_c4_charge   ( -9999. ),
        sublead_jet_c5_charge   ( -9999. ),
        sublead_jet_c6_charge   ( -9999. ),
        sublead_jet_c7_charge   ( -9999. ),
        sublead_jet_c8_charge   ( -9999. ),
        sublead_jet_c9_charge   ( -9999. ),
        sublead_jet_c10_charge   ( -9999. ),
        sublead_jet_c11_charge   ( -9999. ),
        sublead_jet_c12_charge   ( -9999. ),
        sublead_jet_c13_charge   ( -9999. ),
        sublead_jet_c14_charge   ( -9999. ),
        sublead_jet_c15_charge   ( -9999. ),
        sublead_jet_c16_charge   ( -9999. ),
        sublead_jet_c17_charge   ( -9999. ),
        sublead_jet_c18_charge   ( -9999. ),
        sublead_jet_c19_charge   ( -9999. ),
        sublead_jet_c20_charge   ( -9999. ),
        sublead_jet_c21_charge   ( -9999. ),
        sublead_jet_c22_charge   ( -9999. ),
        sublead_jet_c23_charge   ( -9999. ),
        sublead_jet_c24_charge   ( -9999. ),
        sublead_jet_c25_charge   ( -9999. ),
        sublead_jet_c26_charge   ( -9999. ),
        sublead_jet_c27_charge   ( -9999. ),
        sublead_jet_c28_charge   ( -9999. ),
        sublead_jet_c29_charge   ( -9999. ),
        sublead_jet_c30_charge   ( -9999. ),
        sublead_jet_c31_charge   ( -9999. ),
        sublead_jet_c32_charge   ( -9999. ),
        sublead_jet_c33_charge   ( -9999. ),
        sublead_jet_c34_charge   ( -9999. ),
        sublead_jet_c35_charge   ( -9999. ),
        sublead_jet_c36_charge   ( -9999. ),
        sublead_jet_c37_charge   ( -9999. ),
        sublead_jet_c38_charge   ( -9999. ),
        sublead_jet_c39_charge   ( -9999. ),
        sublead_jet_c40_charge   ( -9999. ),
        sublead_jet_c41_charge   ( -9999. ),
        sublead_jet_c42_charge   ( -9999. ),
        sublead_jet_c43_charge   ( -9999. ),
        sublead_jet_c44_charge   ( -9999. ),
        sublead_jet_c45_charge   ( -9999. ),
        sublead_jet_c46_charge   ( -9999. ),
        sublead_jet_c47_charge   ( -9999. ),
        sublead_jet_c48_charge   ( -9999. ),
        sublead_jet_c49_charge   ( -9999. ),
        sublead_jet_c50_charge   ( -9999. ),
        sublead_jet_c51_charge   ( -9999. ),
        sublead_jet_c52_charge   ( -9999. ),
        sublead_jet_c53_charge   ( -9999. ),
        sublead_jet_c54_charge   ( -9999. ),
        sublead_jet_c55_charge   ( -9999. ),
        sublead_jet_c56_charge   ( -9999. ),
        sublead_jet_c57_charge   ( -9999. ),
        sublead_jet_c58_charge   ( -9999. ),
        sublead_jet_c59_charge   ( -9999. ),
        sublead_jet_c60_charge   ( -9999. ),

        sublead_jet_c1_pt       ( -9999. ),
        sublead_jet_c2_pt       ( -9999. ),
        sublead_jet_c3_pt       ( -9999. ),
        sublead_jet_c4_pt       ( -9999. ),
        sublead_jet_c5_pt       ( -9999. ),
        sublead_jet_c6_pt       ( -9999. ),
        sublead_jet_c7_pt       ( -9999. ),
        sublead_jet_c8_pt       ( -9999. ),
        sublead_jet_c9_pt       ( -9999. ),
        sublead_jet_c10_pt       ( -9999. ),
        sublead_jet_c11_pt       ( -9999. ),
        sublead_jet_c12_pt       ( -9999. ),
        sublead_jet_c13_pt       ( -9999. ),
        sublead_jet_c14_pt       ( -9999. ),
        sublead_jet_c15_pt       ( -9999. ),
        sublead_jet_c16_pt       ( -9999. ),
        sublead_jet_c17_pt       ( -9999. ),
        sublead_jet_c18_pt       ( -9999. ),
        sublead_jet_c19_pt       ( -9999. ),
        sublead_jet_c20_pt       ( -9999. ),
        sublead_jet_c21_pt       ( -9999. ),
        sublead_jet_c22_pt       ( -9999. ),
        sublead_jet_c23_pt       ( -9999. ),
        sublead_jet_c24_pt       ( -9999. ),
        sublead_jet_c25_pt       ( -9999. ),
        sublead_jet_c26_pt       ( -9999. ),
        sublead_jet_c27_pt       ( -9999. ),
        sublead_jet_c28_pt       ( -9999. ),
        sublead_jet_c29_pt       ( -9999. ),
        sublead_jet_c30_pt       ( -9999. ),
        sublead_jet_c31_pt       ( -9999. ),
        sublead_jet_c32_pt       ( -9999. ),
        sublead_jet_c33_pt       ( -9999. ),
        sublead_jet_c34_pt       ( -9999. ),
        sublead_jet_c35_pt       ( -9999. ),
        sublead_jet_c36_pt       ( -9999. ),
        sublead_jet_c37_pt       ( -9999. ),
        sublead_jet_c38_pt       ( -9999. ),
        sublead_jet_c39_pt       ( -9999. ),
        sublead_jet_c40_pt       ( -9999. ),
        sublead_jet_c41_pt       ( -9999. ),
        sublead_jet_c42_pt       ( -9999. ),
        sublead_jet_c43_pt       ( -9999. ),
        sublead_jet_c44_pt       ( -9999. ),
        sublead_jet_c45_pt       ( -9999. ),
        sublead_jet_c46_pt       ( -9999. ),
        sublead_jet_c47_pt       ( -9999. ),
        sublead_jet_c48_pt       ( -9999. ),
        sublead_jet_c49_pt       ( -9999. ),
        sublead_jet_c50_pt       ( -9999. ),
        sublead_jet_c51_pt       ( -9999. ),
        sublead_jet_c52_pt       ( -9999. ),
        sublead_jet_c53_pt       ( -9999. ),
        sublead_jet_c54_pt       ( -9999. ),
        sublead_jet_c55_pt       ( -9999. ),
        sublead_jet_c56_pt       ( -9999. ),
        sublead_jet_c57_pt       ( -9999. ),
        sublead_jet_c58_pt       ( -9999. ),
        sublead_jet_c59_pt       ( -9999. ),
        sublead_jet_c60_pt       ( -9999. ),

        sublead_jet_c1_energy   ( -9999. ),
        sublead_jet_c2_energy   ( -9999. ),
        sublead_jet_c3_energy   ( -9999. ),
        sublead_jet_c4_energy   ( -9999. ),
        sublead_jet_c5_energy   ( -9999. ),
        sublead_jet_c6_energy   ( -9999. ),
        sublead_jet_c7_energy   ( -9999. ),
        sublead_jet_c8_energy   ( -9999. ),
        sublead_jet_c9_energy   ( -9999. ),
        sublead_jet_c10_energy   ( -9999. ),
        sublead_jet_c11_energy   ( -9999. ),
        sublead_jet_c12_energy   ( -9999. ),
        sublead_jet_c13_energy   ( -9999. ),
        sublead_jet_c14_energy   ( -9999. ),
        sublead_jet_c15_energy   ( -9999. ),
        sublead_jet_c16_energy   ( -9999. ),
        sublead_jet_c17_energy   ( -9999. ),
        sublead_jet_c18_energy   ( -9999. ),
        sublead_jet_c19_energy   ( -9999. ),
        sublead_jet_c20_energy   ( -9999. ),
        sublead_jet_c21_energy   ( -9999. ),
        sublead_jet_c22_energy   ( -9999. ),
        sublead_jet_c23_energy   ( -9999. ),
        sublead_jet_c24_energy   ( -9999. ),
        sublead_jet_c25_energy   ( -9999. ),
        sublead_jet_c26_energy   ( -9999. ),
        sublead_jet_c27_energy   ( -9999. ),
        sublead_jet_c28_energy   ( -9999. ),
        sublead_jet_c29_energy   ( -9999. ),
        sublead_jet_c30_energy   ( -9999. ),
        sublead_jet_c31_energy   ( -9999. ),
        sublead_jet_c32_energy   ( -9999. ),
        sublead_jet_c33_energy   ( -9999. ),
        sublead_jet_c34_energy   ( -9999. ),
        sublead_jet_c35_energy   ( -9999. ),
        sublead_jet_c36_energy   ( -9999. ),
        sublead_jet_c37_energy   ( -9999. ),
        sublead_jet_c38_energy   ( -9999. ),
        sublead_jet_c39_energy   ( -9999. ),
        sublead_jet_c40_energy   ( -9999. ),
        sublead_jet_c41_energy   ( -9999. ),
        sublead_jet_c42_energy   ( -9999. ),
        sublead_jet_c43_energy   ( -9999. ),
        sublead_jet_c44_energy   ( -9999. ),
        sublead_jet_c45_energy   ( -9999. ),
        sublead_jet_c46_energy   ( -9999. ),
        sublead_jet_c47_energy   ( -9999. ),
        sublead_jet_c48_energy   ( -9999. ),
        sublead_jet_c49_energy   ( -9999. ),
        sublead_jet_c50_energy   ( -9999. ),
        sublead_jet_c51_energy   ( -9999. ),
        sublead_jet_c52_energy   ( -9999. ),
        sublead_jet_c53_energy   ( -9999. ),
        sublead_jet_c54_energy   ( -9999. ),
        sublead_jet_c55_energy   ( -9999. ),
        sublead_jet_c56_energy   ( -9999. ),
        sublead_jet_c57_energy   ( -9999. ),
        sublead_jet_c58_energy   ( -9999. ),
        sublead_jet_c59_energy   ( -9999. ),
        sublead_jet_c60_energy   ( -9999. ),


        subsublead_jet_c1_eta       ( -9999. ),
        subsublead_jet_c2_eta      ( -9999. ),
        subsublead_jet_c3_eta      ( -9999. ),
        subsublead_jet_c4_eta      ( -9999. ),
        subsublead_jet_c5_eta      ( -9999. ),
        subsublead_jet_c6_eta      ( -9999. ),
        subsublead_jet_c7_eta      ( -9999. ),
        subsublead_jet_c8_eta      ( -9999. ),
        subsublead_jet_c9_eta      ( -9999. ),
        subsublead_jet_c10_eta      ( -9999. ),
        subsublead_jet_c11_eta      ( -9999. ),
        subsublead_jet_c12_eta      ( -9999. ),
        subsublead_jet_c13_eta      ( -9999. ),
        subsublead_jet_c14_eta      ( -9999. ),
        subsublead_jet_c15_eta      ( -9999. ),
        subsublead_jet_c16_eta      ( -9999. ),
        subsublead_jet_c17_eta      ( -9999. ),
        subsublead_jet_c18_eta      ( -9999. ),
        subsublead_jet_c19_eta      ( -9999. ),
        subsublead_jet_c20_eta      ( -9999. ),
        subsublead_jet_c21_eta      ( -9999. ),
        subsublead_jet_c22_eta      ( -9999. ),
        subsublead_jet_c23_eta      ( -9999. ),
        subsublead_jet_c24_eta      ( -9999. ),
        subsublead_jet_c25_eta      ( -9999. ),
        subsublead_jet_c26_eta      ( -9999. ),
        subsublead_jet_c27_eta      ( -9999. ),
        subsublead_jet_c28_eta      ( -9999. ),
        subsublead_jet_c29_eta      ( -9999. ),
        subsublead_jet_c30_eta      ( -9999. ),
        subsublead_jet_c31_eta      ( -9999. ),
        subsublead_jet_c32_eta      ( -9999. ),
        subsublead_jet_c33_eta      ( -9999. ),
        subsublead_jet_c34_eta      ( -9999. ),
        subsublead_jet_c35_eta      ( -9999. ),
        subsublead_jet_c36_eta      ( -9999. ),
        subsublead_jet_c37_eta      ( -9999. ),
        subsublead_jet_c38_eta      ( -9999. ),
        subsublead_jet_c39_eta      ( -9999. ),
        subsublead_jet_c40_eta      ( -9999. ),
        subsublead_jet_c41_eta      ( -9999. ),
        subsublead_jet_c42_eta      ( -9999. ),
        subsublead_jet_c43_eta      ( -9999. ),
        subsublead_jet_c44_eta      ( -9999. ),
        subsublead_jet_c45_eta      ( -9999. ),
        subsublead_jet_c46_eta      ( -9999. ),
        subsublead_jet_c47_eta      ( -9999. ),
        subsublead_jet_c48_eta      ( -9999. ),
        subsublead_jet_c49_eta      ( -9999. ),
        subsublead_jet_c50_eta      ( -9999. ),
        subsublead_jet_c51_eta      ( -9999. ),
        subsublead_jet_c52_eta      ( -9999. ),
        subsublead_jet_c53_eta      ( -9999. ),
        subsublead_jet_c54_eta      ( -9999. ),
        subsublead_jet_c55_eta      ( -9999. ),
        subsublead_jet_c56_eta      ( -9999. ),
        subsublead_jet_c57_eta      ( -9999. ),
        subsublead_jet_c58_eta      ( -9999. ),
        subsublead_jet_c59_eta      ( -9999. ),
        subsublead_jet_c60_eta      ( -9999. ),

        subsublead_jet_c1_phi      ( -9999. ),
        subsublead_jet_c2_phi      ( -9999. ),
        subsublead_jet_c3_phi      ( -9999. ),
        subsublead_jet_c4_phi      ( -9999. ),
        subsublead_jet_c5_phi      ( -9999. ),
        subsublead_jet_c6_phi      ( -9999. ),
        subsublead_jet_c7_phi      ( -9999. ),  
        subsublead_jet_c8_phi      ( -9999. ),
        subsublead_jet_c9_phi      ( -9999. ),
        subsublead_jet_c10_phi      ( -9999. ),
        subsublead_jet_c11_phi      ( -9999. ),
        subsublead_jet_c12_phi      ( -9999. ),
        subsublead_jet_c13_phi      ( -9999. ),
        subsublead_jet_c14_phi      ( -9999. ),
        subsublead_jet_c15_phi      ( -9999. ),
        subsublead_jet_c16_phi      ( -9999. ),
        subsublead_jet_c17_phi      ( -9999. ),
        subsublead_jet_c18_phi      ( -9999. ),
        subsublead_jet_c19_phi      ( -9999. ),
        subsublead_jet_c20_phi      ( -9999. ),
        subsublead_jet_c21_phi      ( -9999. ),
        subsublead_jet_c22_phi      ( -9999. ),
        subsublead_jet_c23_phi      ( -9999. ),
        subsublead_jet_c24_phi      ( -9999. ),
        subsublead_jet_c25_phi      ( -9999. ),
        subsublead_jet_c26_phi      ( -9999. ),
        subsublead_jet_c27_phi      ( -9999. ),
        subsublead_jet_c28_phi      ( -9999. ),
        subsublead_jet_c29_phi      ( -9999. ),
        subsublead_jet_c30_phi      ( -9999. ),
        subsublead_jet_c31_phi      ( -9999. ),
        subsublead_jet_c32_phi      ( -9999. ),
        subsublead_jet_c33_phi      ( -9999. ),
        subsublead_jet_c34_phi      ( -9999. ),
        subsublead_jet_c35_phi      ( -9999. ),
        subsublead_jet_c36_phi      ( -9999. ),
        subsublead_jet_c37_phi      ( -9999. ),
        subsublead_jet_c38_phi      ( -9999. ),
        subsublead_jet_c39_phi      ( -9999. ),
        subsublead_jet_c40_phi      ( -9999. ),
        subsublead_jet_c41_phi      ( -9999. ),
        subsublead_jet_c42_phi      ( -9999. ),
        subsublead_jet_c43_phi      ( -9999. ),
        subsublead_jet_c44_phi      ( -9999. ),
        subsublead_jet_c45_phi      ( -9999. ),
        subsublead_jet_c46_phi      ( -9999. ),
        subsublead_jet_c47_phi      ( -9999. ),
        subsublead_jet_c48_phi      ( -9999. ),
        subsublead_jet_c49_phi      ( -9999. ),
        subsublead_jet_c50_phi      ( -9999. ),
        subsublead_jet_c51_phi      ( -9999. ),
        subsublead_jet_c52_phi      ( -9999. ),
        subsublead_jet_c53_phi      ( -9999. ),
        subsublead_jet_c54_phi      ( -9999. ),
        subsublead_jet_c55_phi      ( -9999. ),
        subsublead_jet_c56_phi      ( -9999. ),
        subsublead_jet_c57_phi      ( -9999. ),
        subsublead_jet_c58_phi      ( -9999. ),
        subsublead_jet_c59_phi      ( -9999. ),
        subsublead_jet_c60_phi      ( -9999. ),

        subsublead_jet_c1_charge   ( -9999. ),
        subsublead_jet_c2_charge   ( -9999. ),
        subsublead_jet_c3_charge   ( -9999. ),
        subsublead_jet_c4_charge   ( -9999. ),
        subsublead_jet_c5_charge   ( -9999. ),
        subsublead_jet_c6_charge   ( -9999. ),
        subsublead_jet_c7_charge   ( -9999. ),
        subsublead_jet_c8_charge   ( -9999. ),
        subsublead_jet_c9_charge   ( -9999. ),
        subsublead_jet_c10_charge   ( -9999. ),
        subsublead_jet_c11_charge   ( -9999. ),
        subsublead_jet_c12_charge   ( -9999. ),
        subsublead_jet_c13_charge   ( -9999. ),
        subsublead_jet_c14_charge   ( -9999. ),
        subsublead_jet_c15_charge   ( -9999. ),
        subsublead_jet_c16_charge   ( -9999. ),
        subsublead_jet_c17_charge   ( -9999. ),
        subsublead_jet_c18_charge   ( -9999. ),
        subsublead_jet_c19_charge   ( -9999. ),
        subsublead_jet_c20_charge   ( -9999. ),
        subsublead_jet_c21_charge   ( -9999. ),
        subsublead_jet_c22_charge   ( -9999. ),
        subsublead_jet_c23_charge   ( -9999. ),
        subsublead_jet_c24_charge   ( -9999. ),
        subsublead_jet_c25_charge   ( -9999. ),
        subsublead_jet_c26_charge   ( -9999. ),
        subsublead_jet_c27_charge   ( -9999. ),
        subsublead_jet_c28_charge   ( -9999. ),
        subsublead_jet_c29_charge   ( -9999. ),
        subsublead_jet_c30_charge   ( -9999. ),
        subsublead_jet_c31_charge   ( -9999. ),
        subsublead_jet_c32_charge   ( -9999. ),
        subsublead_jet_c33_charge   ( -9999. ),
        subsublead_jet_c34_charge   ( -9999. ),
        subsublead_jet_c35_charge   ( -9999. ),
        subsublead_jet_c36_charge   ( -9999. ),
        subsublead_jet_c37_charge   ( -9999. ),
        subsublead_jet_c38_charge   ( -9999. ),
        subsublead_jet_c39_charge   ( -9999. ),
        subsublead_jet_c40_charge   ( -9999. ),
        subsublead_jet_c41_charge   ( -9999. ),
        subsublead_jet_c42_charge   ( -9999. ),
        subsublead_jet_c43_charge   ( -9999. ),
        subsublead_jet_c44_charge   ( -9999. ),
        subsublead_jet_c45_charge   ( -9999. ),
        subsublead_jet_c46_charge   ( -9999. ),
        subsublead_jet_c47_charge   ( -9999. ),
        subsublead_jet_c48_charge   ( -9999. ),
        subsublead_jet_c49_charge   ( -9999. ),
        subsublead_jet_c50_charge   ( -9999. ),
        subsublead_jet_c51_charge   ( -9999. ),
        subsublead_jet_c52_charge   ( -9999. ),
        subsublead_jet_c53_charge   ( -9999. ),
        subsublead_jet_c54_charge   ( -9999. ),
        subsublead_jet_c55_charge   ( -9999. ),
        subsublead_jet_c56_charge   ( -9999. ),
        subsublead_jet_c57_charge   ( -9999. ),
        subsublead_jet_c58_charge   ( -9999. ),
        subsublead_jet_c59_charge   ( -9999. ),
        subsublead_jet_c60_charge   ( -9999. ),

        subsublead_jet_c1_pt       ( -9999. ),
        subsublead_jet_c2_pt       ( -9999. ),
        subsublead_jet_c3_pt       ( -9999. ),
        subsublead_jet_c4_pt       ( -9999. ),
        subsublead_jet_c5_pt       ( -9999. ),
        subsublead_jet_c6_pt       ( -9999. ),
        subsublead_jet_c7_pt       ( -9999. ),
        subsublead_jet_c8_pt       ( -9999. ),
        subsublead_jet_c9_pt       ( -9999. ),
        subsublead_jet_c10_pt       ( -9999. ),
        subsublead_jet_c11_pt       ( -9999. ),
        subsublead_jet_c12_pt       ( -9999. ),
        subsublead_jet_c13_pt       ( -9999. ),
        subsublead_jet_c14_pt       ( -9999. ),
        subsublead_jet_c15_pt       ( -9999. ),
        subsublead_jet_c16_pt       ( -9999. ),
        subsublead_jet_c17_pt       ( -9999. ),
        subsublead_jet_c18_pt       ( -9999. ),
        subsublead_jet_c19_pt       ( -9999. ),
        subsublead_jet_c20_pt       ( -9999. ),
        subsublead_jet_c21_pt       ( -9999. ),
        subsublead_jet_c22_pt       ( -9999. ),
        subsublead_jet_c23_pt       ( -9999. ),
        subsublead_jet_c24_pt       ( -9999. ),
        subsublead_jet_c25_pt       ( -9999. ),
        subsublead_jet_c26_pt       ( -9999. ),
        subsublead_jet_c27_pt       ( -9999. ),
        subsublead_jet_c28_pt       ( -9999. ),
        subsublead_jet_c29_pt       ( -9999. ),
        subsublead_jet_c30_pt       ( -9999. ),
        subsublead_jet_c31_pt       ( -9999. ),
        subsublead_jet_c32_pt       ( -9999. ),
        subsublead_jet_c33_pt       ( -9999. ),
        subsublead_jet_c34_pt       ( -9999. ),
        subsublead_jet_c35_pt       ( -9999. ),
        subsublead_jet_c36_pt       ( -9999. ),
        subsublead_jet_c37_pt       ( -9999. ),
        subsublead_jet_c38_pt       ( -9999. ),
        subsublead_jet_c39_pt       ( -9999. ),
        subsublead_jet_c40_pt       ( -9999. ),
        subsublead_jet_c41_pt       ( -9999. ),
        subsublead_jet_c42_pt       ( -9999. ),
        subsublead_jet_c43_pt       ( -9999. ),
        subsublead_jet_c44_pt       ( -9999. ),
        subsublead_jet_c45_pt       ( -9999. ),
        subsublead_jet_c46_pt       ( -9999. ),
        subsublead_jet_c47_pt       ( -9999. ),
        subsublead_jet_c48_pt       ( -9999. ),
        subsublead_jet_c49_pt       ( -9999. ),
        subsublead_jet_c50_pt       ( -9999. ),
        subsublead_jet_c51_pt       ( -9999. ),
        subsublead_jet_c52_pt       ( -9999. ),
        subsublead_jet_c53_pt       ( -9999. ),
        subsublead_jet_c54_pt       ( -9999. ),
        subsublead_jet_c55_pt       ( -9999. ),
        subsublead_jet_c56_pt       ( -9999. ),
        subsublead_jet_c57_pt       ( -9999. ),
        subsublead_jet_c58_pt       ( -9999. ),
        subsublead_jet_c59_pt       ( -9999. ),
        subsublead_jet_c60_pt       ( -9999. ),

        subsublead_jet_c1_energy   ( -9999. ),
        subsublead_jet_c2_energy   ( -9999. ),
        subsublead_jet_c3_energy   ( -9999. ),
        subsublead_jet_c4_energy   ( -9999. ),
        subsublead_jet_c5_energy   ( -9999. ),
        subsublead_jet_c6_energy   ( -9999. ),
        subsublead_jet_c7_energy   ( -9999. ),
        subsublead_jet_c8_energy   ( -9999. ),
        subsublead_jet_c9_energy   ( -9999. ),
        subsublead_jet_c10_energy   ( -9999. ),
        subsublead_jet_c11_energy   ( -9999. ),
        subsublead_jet_c12_energy   ( -9999. ),
        subsublead_jet_c13_energy   ( -9999. ),
        subsublead_jet_c14_energy   ( -9999. ),
        subsublead_jet_c15_energy   ( -9999. ),
        subsublead_jet_c16_energy   ( -9999. ),
        subsublead_jet_c17_energy   ( -9999. ),
        subsublead_jet_c18_energy   ( -9999. ),
        subsublead_jet_c19_energy   ( -9999. ),
        subsublead_jet_c20_energy   ( -9999. ),
        subsublead_jet_c21_energy   ( -9999. ),
        subsublead_jet_c22_energy   ( -9999. ),
        subsublead_jet_c23_energy   ( -9999. ),
        subsublead_jet_c24_energy   ( -9999. ),
        subsublead_jet_c25_energy   ( -9999. ),
        subsublead_jet_c26_energy   ( -9999. ),
        subsublead_jet_c27_energy   ( -9999. ),
        subsublead_jet_c28_energy   ( -9999. ),
        subsublead_jet_c29_energy   ( -9999. ),
        subsublead_jet_c30_energy   ( -9999. ),
        subsublead_jet_c31_energy   ( -9999. ),
        subsublead_jet_c32_energy   ( -9999. ),
        subsublead_jet_c33_energy   ( -9999. ),
        subsublead_jet_c34_energy   ( -9999. ),
        subsublead_jet_c35_energy   ( -9999. ),
        subsublead_jet_c36_energy   ( -9999. ),
        subsublead_jet_c37_energy   ( -9999. ),
        subsublead_jet_c38_energy   ( -9999. ),
        subsublead_jet_c39_energy   ( -9999. ),
        subsublead_jet_c40_energy   ( -9999. ),
        subsublead_jet_c41_energy   ( -9999. ),
        subsublead_jet_c42_energy   ( -9999. ),
        subsublead_jet_c43_energy   ( -9999. ),
        subsublead_jet_c44_energy   ( -9999. ),
        subsublead_jet_c45_energy   ( -9999. ),
        subsublead_jet_c46_energy   ( -9999. ),
        subsublead_jet_c47_energy   ( -9999. ),
        subsublead_jet_c48_energy   ( -9999. ),
        subsublead_jet_c49_energy   ( -9999. ),
        subsublead_jet_c50_energy   ( -9999. ),
        subsublead_jet_c51_energy   ( -9999. ),
        subsublead_jet_c52_energy   ( -9999. ),
        subsublead_jet_c53_energy   ( -9999. ),
        subsublead_jet_c54_energy   ( -9999. ),
        subsublead_jet_c55_energy   ( -9999. ),
        subsublead_jet_c56_energy   ( -9999. ),
        subsublead_jet_c57_energy   ( -9999. ),
        subsublead_jet_c58_energy   ( -9999. ),
        subsublead_jet_c59_energy   ( -9999. ),
        subsublead_jet_c60_energy   ( -9999. ),


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

        constit_energy   = x->constit_energy;

        pt_J1            = x->pt_J1;
        eta_J1           = x->eta_J1;
        phi_J1           = x->phi_J1;
        charge_J1        = x->charge_J1;
        energy_J1        = x->energy_J1;
        flav_J1          = x->energy_J1;

        pt_J2            = x->pt_J2;
        eta_J2           = x->eta_J2;
        phi_J2           = x->phi_J2;
        charge_J2        = x->charge_J2;
        energy_J2        = x->energy_J2;
        flav_J2          = x->energy_J2;

        pt_J3            = x->pt_J3;
        eta_J3           = x->eta_J3;
        phi_J3           = x->phi_J3;
        charge_J3        = x->charge_J3;
        energy_J3        = x->energy_J3;
        flav_J3          = x->energy_J3;

        n_constits       = x->n_constits       ;
        //test_vec         = x->test_vec         ;

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
        lead_jet_c9_eta   =   x->lead_jet_c9_eta;      
        lead_jet_c10_eta   =   x->lead_jet_c10_eta;      
        lead_jet_c11_eta   =   x->lead_jet_c11_eta;      
        lead_jet_c12_eta   =   x->lead_jet_c12_eta;      
        lead_jet_c13_eta   =   x->lead_jet_c13_eta;      
        lead_jet_c14_eta   =   x->lead_jet_c14_eta;      
        lead_jet_c15_eta   =   x->lead_jet_c15_eta;      
        lead_jet_c16_eta   =   x->lead_jet_c16_eta;      
        lead_jet_c17_eta   =   x->lead_jet_c17_eta;      
        lead_jet_c18_eta   =   x->lead_jet_c18_eta;      
        lead_jet_c19_eta   =   x->lead_jet_c19_eta;      
        lead_jet_c20_eta   =   x->lead_jet_c20_eta;      
        lead_jet_c21_eta   =   x->lead_jet_c21_eta;      
        lead_jet_c22_eta   =   x->lead_jet_c22_eta;      
        lead_jet_c23_eta   =   x->lead_jet_c23_eta;      
        lead_jet_c24_eta   =   x->lead_jet_c24_eta;      
        lead_jet_c25_eta   =   x->lead_jet_c25_eta;      
        lead_jet_c26_eta   =   x->lead_jet_c26_eta;      
        lead_jet_c27_eta   =   x->lead_jet_c27_eta;      
        lead_jet_c28_eta   =   x->lead_jet_c28_eta;      
        lead_jet_c29_eta   =   x->lead_jet_c29_eta;      
        lead_jet_c30_eta   =   x->lead_jet_c30_eta;      
        lead_jet_c31_eta   =   x->lead_jet_c31_eta;      
        lead_jet_c32_eta   =   x->lead_jet_c32_eta;      
        lead_jet_c33_eta   =   x->lead_jet_c33_eta;      
        lead_jet_c34_eta   =   x->lead_jet_c34_eta;      
        lead_jet_c35_eta   =   x->lead_jet_c35_eta;      
        lead_jet_c36_eta   =   x->lead_jet_c36_eta;      
        lead_jet_c37_eta   =   x->lead_jet_c37_eta;      
        lead_jet_c38_eta   =   x->lead_jet_c38_eta;      
        lead_jet_c39_eta   =   x->lead_jet_c39_eta;      
        lead_jet_c40_eta   =   x->lead_jet_c40_eta;      
        lead_jet_c41_eta   =   x->lead_jet_c41_eta;      
        lead_jet_c42_eta   =   x->lead_jet_c42_eta;      
        lead_jet_c43_eta   =   x->lead_jet_c43_eta;      
        lead_jet_c44_eta   =   x->lead_jet_c44_eta;      
        lead_jet_c45_eta   =   x->lead_jet_c45_eta;      
        lead_jet_c46_eta   =   x->lead_jet_c46_eta;      
        lead_jet_c47_eta   =   x->lead_jet_c47_eta;      
        lead_jet_c48_eta   =   x->lead_jet_c48_eta;      
        lead_jet_c49_eta   =   x->lead_jet_c49_eta;      
        lead_jet_c50_eta   =   x->lead_jet_c50_eta;      
        lead_jet_c51_eta   =   x->lead_jet_c51_eta;      
        lead_jet_c52_eta   =   x->lead_jet_c52_eta;      
        lead_jet_c53_eta   =   x->lead_jet_c53_eta;      
        lead_jet_c54_eta   =   x->lead_jet_c54_eta;      
        lead_jet_c55_eta   =   x->lead_jet_c55_eta;      
        lead_jet_c56_eta   =   x->lead_jet_c56_eta;      
        lead_jet_c57_eta   =   x->lead_jet_c57_eta;      
        lead_jet_c58_eta   =   x->lead_jet_c58_eta;      
        lead_jet_c59_eta   =   x->lead_jet_c59_eta;      
        lead_jet_c60_eta   =   x->lead_jet_c60_eta;      

        lead_jet_c1_phi   =   x->lead_jet_c1_phi;      
        lead_jet_c2_phi   =   x->lead_jet_c2_phi;      
        lead_jet_c3_phi   =   x->lead_jet_c3_phi;      
        lead_jet_c4_phi   =   x->lead_jet_c4_phi;      
        lead_jet_c5_phi   =   x->lead_jet_c5_phi;      
        lead_jet_c6_phi   =   x->lead_jet_c6_phi;      
        lead_jet_c7_phi   =   x->lead_jet_c7_phi;       
        lead_jet_c8_phi   =   x->lead_jet_c8_phi;      
        lead_jet_c9_phi   =   x->lead_jet_c9_phi;      
        lead_jet_c10_phi   =   x->lead_jet_c10_phi;      
        lead_jet_c11_phi   =   x->lead_jet_c11_phi;      
        lead_jet_c12_phi   =   x->lead_jet_c12_phi;      
        lead_jet_c13_phi   =   x->lead_jet_c13_phi;      
        lead_jet_c14_phi   =   x->lead_jet_c14_phi;      
        lead_jet_c15_phi   =   x->lead_jet_c15_phi;      
        lead_jet_c16_phi   =   x->lead_jet_c16_phi;      
        lead_jet_c17_phi   =   x->lead_jet_c17_phi;      
        lead_jet_c18_phi   =   x->lead_jet_c18_phi;      
        lead_jet_c19_phi   =   x->lead_jet_c19_phi;      
        lead_jet_c20_phi   =   x->lead_jet_c20_phi;      
        lead_jet_c21_phi   =   x->lead_jet_c21_phi;      
        lead_jet_c22_phi   =   x->lead_jet_c22_phi;      
        lead_jet_c23_phi   =   x->lead_jet_c23_phi;      
        lead_jet_c24_phi   =   x->lead_jet_c24_phi;      
        lead_jet_c25_phi   =   x->lead_jet_c25_phi;      
        lead_jet_c26_phi   =   x->lead_jet_c26_phi;      
        lead_jet_c27_phi   =   x->lead_jet_c27_phi;      
        lead_jet_c28_phi   =   x->lead_jet_c28_phi;      
        lead_jet_c29_phi   =   x->lead_jet_c29_phi;      
        lead_jet_c30_phi   =   x->lead_jet_c30_phi;      
        lead_jet_c31_phi   =   x->lead_jet_c31_phi;      
        lead_jet_c32_phi   =   x->lead_jet_c32_phi;      
        lead_jet_c33_phi   =   x->lead_jet_c33_phi;      
        lead_jet_c34_phi   =   x->lead_jet_c34_phi;      
        lead_jet_c35_phi   =   x->lead_jet_c35_phi;      
        lead_jet_c36_phi   =   x->lead_jet_c36_phi;      
        lead_jet_c37_phi   =   x->lead_jet_c37_phi;      
        lead_jet_c38_phi   =   x->lead_jet_c38_phi;      
        lead_jet_c39_phi   =   x->lead_jet_c39_phi;      
        lead_jet_c40_phi   =   x->lead_jet_c40_phi;      
        lead_jet_c41_phi   =   x->lead_jet_c41_phi;      
        lead_jet_c42_phi   =   x->lead_jet_c42_phi;      
        lead_jet_c43_phi   =   x->lead_jet_c43_phi;      
        lead_jet_c44_phi   =   x->lead_jet_c44_phi;      
        lead_jet_c45_phi   =   x->lead_jet_c45_phi;      
        lead_jet_c46_phi   =   x->lead_jet_c46_phi;      
        lead_jet_c47_phi   =   x->lead_jet_c47_phi;      
        lead_jet_c48_phi   =   x->lead_jet_c48_phi;      
        lead_jet_c49_phi   =   x->lead_jet_c49_phi;      
        lead_jet_c50_phi   =   x->lead_jet_c50_phi;      
        lead_jet_c51_phi   =   x->lead_jet_c51_phi;      
        lead_jet_c52_phi   =   x->lead_jet_c52_phi;      
        lead_jet_c53_phi   =   x->lead_jet_c53_phi;      
        lead_jet_c54_phi   =   x->lead_jet_c54_phi;      
        lead_jet_c55_phi   =   x->lead_jet_c55_phi;      
        lead_jet_c56_phi   =   x->lead_jet_c56_phi;      
        lead_jet_c57_phi   =   x->lead_jet_c57_phi;      
        lead_jet_c58_phi   =   x->lead_jet_c58_phi;      
        lead_jet_c59_phi   =   x->lead_jet_c59_phi;      
        lead_jet_c60_phi   =   x->lead_jet_c60_phi;      

        lead_jet_c1_charge =   x->lead_jet_c1_charge;   
        lead_jet_c2_charge =   x->lead_jet_c2_charge;   
        lead_jet_c3_charge =   x->lead_jet_c3_charge;   
        lead_jet_c4_charge =   x->lead_jet_c4_charge;   
        lead_jet_c5_charge =   x->lead_jet_c5_charge;   
        lead_jet_c6_charge =   x->lead_jet_c6_charge;   
        lead_jet_c7_charge =   x->lead_jet_c7_charge;   
        lead_jet_c8_charge =   x->lead_jet_c8_charge;   
        lead_jet_c9_charge =   x->lead_jet_c9_charge;   
        lead_jet_c10_charge =   x->lead_jet_c10_charge;   
        lead_jet_c11_charge =   x->lead_jet_c11_charge;   
        lead_jet_c12_charge =   x->lead_jet_c12_charge;   
        lead_jet_c13_charge =   x->lead_jet_c13_charge;   
        lead_jet_c14_charge =   x->lead_jet_c14_charge;   
        lead_jet_c15_charge =   x->lead_jet_c15_charge;   
        lead_jet_c16_charge =   x->lead_jet_c16_charge;   
        lead_jet_c17_charge =   x->lead_jet_c17_charge;   
        lead_jet_c18_charge =   x->lead_jet_c18_charge;   
        lead_jet_c19_charge =   x->lead_jet_c19_charge;   
        lead_jet_c20_charge =   x->lead_jet_c20_charge;   
        lead_jet_c21_charge =   x->lead_jet_c21_charge;   
        lead_jet_c22_charge =   x->lead_jet_c22_charge;   
        lead_jet_c23_charge =   x->lead_jet_c23_charge;   
        lead_jet_c24_charge =   x->lead_jet_c24_charge;   
        lead_jet_c25_charge =   x->lead_jet_c25_charge;   
        lead_jet_c26_charge =   x->lead_jet_c26_charge;   
        lead_jet_c27_charge =   x->lead_jet_c27_charge;   
        lead_jet_c28_charge =   x->lead_jet_c28_charge;   
        lead_jet_c29_charge =   x->lead_jet_c29_charge;   
        lead_jet_c30_charge =   x->lead_jet_c30_charge;   
        lead_jet_c31_charge =   x->lead_jet_c31_charge;   
        lead_jet_c32_charge =   x->lead_jet_c32_charge;   
        lead_jet_c33_charge =   x->lead_jet_c33_charge;   
        lead_jet_c34_charge =   x->lead_jet_c34_charge;   
        lead_jet_c35_charge =   x->lead_jet_c35_charge;   
        lead_jet_c36_charge =   x->lead_jet_c36_charge;   
        lead_jet_c37_charge =   x->lead_jet_c37_charge;   
        lead_jet_c38_charge =   x->lead_jet_c38_charge;   
        lead_jet_c39_charge =   x->lead_jet_c39_charge;   
        lead_jet_c40_charge =   x->lead_jet_c40_charge;   
        lead_jet_c41_charge =   x->lead_jet_c41_charge;   
        lead_jet_c42_charge =   x->lead_jet_c42_charge;   
        lead_jet_c43_charge =   x->lead_jet_c43_charge;   
        lead_jet_c44_charge =   x->lead_jet_c44_charge;   
        lead_jet_c45_charge =   x->lead_jet_c45_charge;   
        lead_jet_c46_charge =   x->lead_jet_c46_charge;   
        lead_jet_c47_charge =   x->lead_jet_c47_charge;   
        lead_jet_c48_charge =   x->lead_jet_c48_charge;   
        lead_jet_c49_charge =   x->lead_jet_c49_charge;   
        lead_jet_c50_charge =   x->lead_jet_c50_charge;   
        lead_jet_c51_charge =   x->lead_jet_c51_charge;   
        lead_jet_c52_charge =   x->lead_jet_c52_charge;   
        lead_jet_c53_charge =   x->lead_jet_c53_charge;   
        lead_jet_c54_charge =   x->lead_jet_c54_charge;   
        lead_jet_c55_charge =   x->lead_jet_c55_charge;   
        lead_jet_c56_charge =   x->lead_jet_c56_charge;   
        lead_jet_c57_charge =   x->lead_jet_c57_charge;   
        lead_jet_c58_charge =   x->lead_jet_c58_charge;   
        lead_jet_c59_charge =   x->lead_jet_c59_charge;   
        lead_jet_c60_charge =   x->lead_jet_c60_charge;   

        lead_jet_c1_pt =    x->lead_jet_c1_pt;       
        lead_jet_c2_pt =    x->lead_jet_c2_pt;       
        lead_jet_c3_pt =    x->lead_jet_c3_pt;       
        lead_jet_c4_pt =    x->lead_jet_c4_pt;       
        lead_jet_c5_pt =    x->lead_jet_c5_pt;       
        lead_jet_c6_pt =    x->lead_jet_c6_pt;       
        lead_jet_c7_pt =    x->lead_jet_c7_pt;       
        lead_jet_c8_pt =    x->lead_jet_c8_pt;       
        lead_jet_c9_pt =    x->lead_jet_c9_pt;       
        lead_jet_c10_pt =    x->lead_jet_c10_pt;       
        lead_jet_c11_pt =    x->lead_jet_c11_pt;       
        lead_jet_c12_pt =    x->lead_jet_c12_pt;       
        lead_jet_c13_pt =    x->lead_jet_c13_pt;       
        lead_jet_c14_pt =    x->lead_jet_c14_pt;       
        lead_jet_c15_pt =    x->lead_jet_c15_pt;       
        lead_jet_c16_pt =    x->lead_jet_c16_pt;       
        lead_jet_c17_pt =    x->lead_jet_c17_pt;       
        lead_jet_c18_pt =    x->lead_jet_c18_pt;       
        lead_jet_c19_pt =    x->lead_jet_c19_pt;       
        lead_jet_c20_pt =    x->lead_jet_c20_pt;       
        lead_jet_c21_pt =    x->lead_jet_c21_pt;       
        lead_jet_c22_pt =    x->lead_jet_c22_pt;       
        lead_jet_c23_pt =    x->lead_jet_c23_pt;       
        lead_jet_c24_pt =    x->lead_jet_c24_pt;       
        lead_jet_c25_pt =    x->lead_jet_c25_pt;       
        lead_jet_c26_pt =    x->lead_jet_c26_pt;       
        lead_jet_c27_pt =    x->lead_jet_c27_pt;       
        lead_jet_c28_pt =    x->lead_jet_c28_pt;       
        lead_jet_c29_pt =    x->lead_jet_c29_pt;       
        lead_jet_c30_pt =    x->lead_jet_c30_pt;       
        lead_jet_c31_pt =    x->lead_jet_c31_pt;       
        lead_jet_c32_pt =    x->lead_jet_c32_pt;       
        lead_jet_c33_pt =    x->lead_jet_c33_pt;       
        lead_jet_c34_pt =    x->lead_jet_c34_pt;       
        lead_jet_c35_pt =    x->lead_jet_c35_pt;       
        lead_jet_c36_pt =    x->lead_jet_c36_pt;       
        lead_jet_c37_pt =    x->lead_jet_c37_pt;       
        lead_jet_c38_pt =    x->lead_jet_c38_pt;       
        lead_jet_c39_pt =    x->lead_jet_c39_pt;       
        lead_jet_c40_pt =    x->lead_jet_c40_pt;       
        lead_jet_c41_pt =    x->lead_jet_c41_pt;       
        lead_jet_c42_pt =    x->lead_jet_c42_pt;       
        lead_jet_c43_pt =    x->lead_jet_c43_pt;       
        lead_jet_c44_pt =    x->lead_jet_c44_pt;       
        lead_jet_c45_pt =    x->lead_jet_c45_pt;       
        lead_jet_c46_pt =    x->lead_jet_c46_pt;       
        lead_jet_c47_pt =    x->lead_jet_c47_pt;       
        lead_jet_c48_pt =    x->lead_jet_c48_pt;       
        lead_jet_c49_pt =    x->lead_jet_c49_pt;       
        lead_jet_c50_pt =    x->lead_jet_c50_pt;       
        lead_jet_c51_pt =    x->lead_jet_c51_pt;       
        lead_jet_c52_pt =    x->lead_jet_c52_pt;       
        lead_jet_c53_pt =    x->lead_jet_c53_pt;       
        lead_jet_c54_pt =    x->lead_jet_c54_pt;       
        lead_jet_c55_pt =    x->lead_jet_c55_pt;       
        lead_jet_c56_pt =    x->lead_jet_c56_pt;       
        lead_jet_c57_pt =    x->lead_jet_c57_pt;       
        lead_jet_c58_pt =    x->lead_jet_c58_pt;       
        lead_jet_c59_pt =    x->lead_jet_c59_pt;       
        lead_jet_c60_pt =    x->lead_jet_c60_pt;       

        lead_jet_c1_energy = x->lead_jet_c1_energy;   
        lead_jet_c2_energy = x->lead_jet_c2_energy;   
        lead_jet_c3_energy = x->lead_jet_c3_energy;   
        lead_jet_c4_energy = x->lead_jet_c4_energy;   
        lead_jet_c5_energy = x->lead_jet_c5_energy;   
        lead_jet_c6_energy = x->lead_jet_c6_energy;   
        lead_jet_c7_energy = x->lead_jet_c7_energy;   
        lead_jet_c8_energy = x->lead_jet_c8_energy;   
        lead_jet_c9_energy = x->lead_jet_c9_energy;   
        lead_jet_c10_energy = x->lead_jet_c10_energy;   
        lead_jet_c11_energy = x->lead_jet_c11_energy;   
        lead_jet_c12_energy = x->lead_jet_c12_energy;   
        lead_jet_c13_energy = x->lead_jet_c13_energy;   
        lead_jet_c14_energy = x->lead_jet_c14_energy;   
        lead_jet_c15_energy = x->lead_jet_c15_energy;   
        lead_jet_c16_energy = x->lead_jet_c16_energy;   
        lead_jet_c17_energy = x->lead_jet_c17_energy;   
        lead_jet_c18_energy = x->lead_jet_c18_energy;   
        lead_jet_c19_energy = x->lead_jet_c19_energy;   
        lead_jet_c20_energy = x->lead_jet_c20_energy;   
        lead_jet_c21_energy = x->lead_jet_c21_energy;   
        lead_jet_c22_energy = x->lead_jet_c22_energy;   
        lead_jet_c23_energy = x->lead_jet_c23_energy;   
        lead_jet_c24_energy = x->lead_jet_c24_energy;   
        lead_jet_c25_energy = x->lead_jet_c25_energy;   
        lead_jet_c26_energy = x->lead_jet_c26_energy;   
        lead_jet_c27_energy = x->lead_jet_c27_energy;   
        lead_jet_c28_energy = x->lead_jet_c28_energy;   
        lead_jet_c29_energy = x->lead_jet_c29_energy;   
        lead_jet_c30_energy = x->lead_jet_c30_energy;   
        lead_jet_c31_energy = x->lead_jet_c31_energy;   
        lead_jet_c32_energy = x->lead_jet_c32_energy;   
        lead_jet_c33_energy = x->lead_jet_c33_energy;   
        lead_jet_c34_energy = x->lead_jet_c34_energy;   
        lead_jet_c35_energy = x->lead_jet_c35_energy;   
        lead_jet_c36_energy = x->lead_jet_c36_energy;   
        lead_jet_c37_energy = x->lead_jet_c37_energy;   
        lead_jet_c38_energy = x->lead_jet_c38_energy;   
        lead_jet_c39_energy = x->lead_jet_c39_energy;   
        lead_jet_c40_energy = x->lead_jet_c40_energy;   
        lead_jet_c41_energy = x->lead_jet_c41_energy;   
        lead_jet_c42_energy = x->lead_jet_c42_energy;   
        lead_jet_c43_energy = x->lead_jet_c43_energy;   
        lead_jet_c44_energy = x->lead_jet_c44_energy;   
        lead_jet_c45_energy = x->lead_jet_c45_energy;   
        lead_jet_c46_energy = x->lead_jet_c46_energy;   
        lead_jet_c47_energy = x->lead_jet_c47_energy;   
        lead_jet_c48_energy = x->lead_jet_c48_energy;   
        lead_jet_c49_energy = x->lead_jet_c49_energy;   
        lead_jet_c50_energy = x->lead_jet_c50_energy;   
        lead_jet_c51_energy = x->lead_jet_c51_energy;   
        lead_jet_c52_energy = x->lead_jet_c52_energy;   
        lead_jet_c53_energy = x->lead_jet_c53_energy;   
        lead_jet_c54_energy = x->lead_jet_c54_energy;   
        lead_jet_c55_energy = x->lead_jet_c55_energy;   
        lead_jet_c56_energy = x->lead_jet_c56_energy;   
        lead_jet_c57_energy = x->lead_jet_c57_energy;   
        lead_jet_c58_energy = x->lead_jet_c58_energy;   
        lead_jet_c59_energy = x->lead_jet_c59_energy;   
        lead_jet_c60_energy = x->lead_jet_c60_energy;   

        sublead_jet_c1_eta   =   x->sublead_jet_c1_eta;
        sublead_jet_c2_eta   =   x->sublead_jet_c2_eta;      
        sublead_jet_c3_eta   =   x->sublead_jet_c3_eta;      
        sublead_jet_c4_eta   =   x->sublead_jet_c4_eta;      
        sublead_jet_c5_eta   =   x->sublead_jet_c5_eta;      
        sublead_jet_c6_eta   =   x->sublead_jet_c6_eta;      
        sublead_jet_c7_eta   =   x->sublead_jet_c7_eta;      
        sublead_jet_c8_eta   =   x->sublead_jet_c8_eta;      
        sublead_jet_c9_eta   =   x->sublead_jet_c9_eta;      
        sublead_jet_c10_eta   =   x->sublead_jet_c10_eta;      
        sublead_jet_c11_eta   =   x->sublead_jet_c11_eta;      
        sublead_jet_c12_eta   =   x->sublead_jet_c12_eta;      
        sublead_jet_c13_eta   =   x->sublead_jet_c13_eta;      
        sublead_jet_c14_eta   =   x->sublead_jet_c14_eta;      
        sublead_jet_c15_eta   =   x->sublead_jet_c15_eta;      
        sublead_jet_c16_eta   =   x->sublead_jet_c16_eta;      
        sublead_jet_c17_eta   =   x->sublead_jet_c17_eta;      
        sublead_jet_c18_eta   =   x->sublead_jet_c18_eta;      
        sublead_jet_c19_eta   =   x->sublead_jet_c19_eta;      
        sublead_jet_c20_eta   =   x->sublead_jet_c20_eta;      
        sublead_jet_c21_eta   =   x->sublead_jet_c21_eta;      
        sublead_jet_c22_eta   =   x->sublead_jet_c22_eta;      
        sublead_jet_c23_eta   =   x->sublead_jet_c23_eta;      
        sublead_jet_c24_eta   =   x->sublead_jet_c24_eta;      
        sublead_jet_c25_eta   =   x->sublead_jet_c25_eta;      
        sublead_jet_c26_eta   =   x->sublead_jet_c26_eta;      
        sublead_jet_c27_eta   =   x->sublead_jet_c27_eta;      
        sublead_jet_c28_eta   =   x->sublead_jet_c28_eta;      
        sublead_jet_c29_eta   =   x->sublead_jet_c29_eta;      
        sublead_jet_c30_eta   =   x->sublead_jet_c30_eta;      
        sublead_jet_c31_eta   =   x->sublead_jet_c31_eta;      
        sublead_jet_c32_eta   =   x->sublead_jet_c32_eta;      
        sublead_jet_c33_eta   =   x->sublead_jet_c33_eta;      
        sublead_jet_c34_eta   =   x->sublead_jet_c34_eta;      
        sublead_jet_c35_eta   =   x->sublead_jet_c35_eta;      
        sublead_jet_c36_eta   =   x->sublead_jet_c36_eta;      
        sublead_jet_c37_eta   =   x->sublead_jet_c37_eta;      
        sublead_jet_c38_eta   =   x->sublead_jet_c38_eta;      
        sublead_jet_c39_eta   =   x->sublead_jet_c39_eta;      
        sublead_jet_c40_eta   =   x->sublead_jet_c40_eta;      
        sublead_jet_c41_eta   =   x->sublead_jet_c41_eta;      
        sublead_jet_c42_eta   =   x->sublead_jet_c42_eta;      
        sublead_jet_c43_eta   =   x->sublead_jet_c43_eta;      
        sublead_jet_c44_eta   =   x->sublead_jet_c44_eta;      
        sublead_jet_c45_eta   =   x->sublead_jet_c45_eta;      
        sublead_jet_c46_eta   =   x->sublead_jet_c46_eta;      
        sublead_jet_c47_eta   =   x->sublead_jet_c47_eta;      
        sublead_jet_c48_eta   =   x->sublead_jet_c48_eta;      
        sublead_jet_c49_eta   =   x->sublead_jet_c49_eta;      
        sublead_jet_c50_eta   =   x->sublead_jet_c50_eta;      
        sublead_jet_c51_eta   =   x->sublead_jet_c51_eta;      
        sublead_jet_c52_eta   =   x->sublead_jet_c52_eta;      
        sublead_jet_c53_eta   =   x->sublead_jet_c53_eta;      
        sublead_jet_c54_eta   =   x->sublead_jet_c54_eta;      
        sublead_jet_c55_eta   =   x->sublead_jet_c55_eta;      
        sublead_jet_c56_eta   =   x->sublead_jet_c56_eta;      
        sublead_jet_c57_eta   =   x->sublead_jet_c57_eta;      
        sublead_jet_c58_eta   =   x->sublead_jet_c58_eta;      
        sublead_jet_c59_eta   =   x->sublead_jet_c59_eta;      
        sublead_jet_c60_eta   =   x->sublead_jet_c60_eta;      

        sublead_jet_c1_phi   =   x->sublead_jet_c1_phi;      
        sublead_jet_c2_phi   =   x->sublead_jet_c2_phi;      
        sublead_jet_c3_phi   =   x->sublead_jet_c3_phi;      
        sublead_jet_c4_phi   =   x->sublead_jet_c4_phi;      
        sublead_jet_c5_phi   =   x->sublead_jet_c5_phi;      
        sublead_jet_c6_phi   =   x->sublead_jet_c6_phi;      
        sublead_jet_c7_phi   =   x->sublead_jet_c7_phi;       
        sublead_jet_c8_phi   =   x->sublead_jet_c8_phi;      
        sublead_jet_c9_phi   =   x->sublead_jet_c9_phi;      
        sublead_jet_c10_phi   =   x->sublead_jet_c10_phi;      
        sublead_jet_c11_phi   =   x->sublead_jet_c11_phi;      
        sublead_jet_c12_phi   =   x->sublead_jet_c12_phi;      
        sublead_jet_c13_phi   =   x->sublead_jet_c13_phi;      
        sublead_jet_c14_phi   =   x->sublead_jet_c14_phi;      
        sublead_jet_c15_phi   =   x->sublead_jet_c15_phi;      
        sublead_jet_c16_phi   =   x->sublead_jet_c16_phi;      
        sublead_jet_c17_phi   =   x->sublead_jet_c17_phi;      
        sublead_jet_c18_phi   =   x->sublead_jet_c18_phi;      
        sublead_jet_c19_phi   =   x->sublead_jet_c19_phi;      
        sublead_jet_c20_phi   =   x->sublead_jet_c20_phi;      
        sublead_jet_c21_phi   =   x->sublead_jet_c21_phi;      
        sublead_jet_c22_phi   =   x->sublead_jet_c22_phi;      
        sublead_jet_c23_phi   =   x->sublead_jet_c23_phi;      
        sublead_jet_c24_phi   =   x->sublead_jet_c24_phi;      
        sublead_jet_c25_phi   =   x->sublead_jet_c25_phi;      
        sublead_jet_c26_phi   =   x->sublead_jet_c26_phi;      
        sublead_jet_c27_phi   =   x->sublead_jet_c27_phi;      
        sublead_jet_c28_phi   =   x->sublead_jet_c28_phi;      
        sublead_jet_c29_phi   =   x->sublead_jet_c29_phi;      
        sublead_jet_c30_phi   =   x->sublead_jet_c30_phi;      
        sublead_jet_c31_phi   =   x->sublead_jet_c31_phi;      
        sublead_jet_c32_phi   =   x->sublead_jet_c32_phi;      
        sublead_jet_c33_phi   =   x->sublead_jet_c33_phi;      
        sublead_jet_c34_phi   =   x->sublead_jet_c34_phi;      
        sublead_jet_c35_phi   =   x->sublead_jet_c35_phi;      
        sublead_jet_c36_phi   =   x->sublead_jet_c36_phi;      
        sublead_jet_c37_phi   =   x->sublead_jet_c37_phi;      
        sublead_jet_c38_phi   =   x->sublead_jet_c38_phi;      
        sublead_jet_c39_phi   =   x->sublead_jet_c39_phi;      
        sublead_jet_c40_phi   =   x->sublead_jet_c40_phi;      
        sublead_jet_c41_phi   =   x->sublead_jet_c41_phi;      
        sublead_jet_c42_phi   =   x->sublead_jet_c42_phi;      
        sublead_jet_c43_phi   =   x->sublead_jet_c43_phi;      
        sublead_jet_c44_phi   =   x->sublead_jet_c44_phi;      
        sublead_jet_c45_phi   =   x->sublead_jet_c45_phi;      
        sublead_jet_c46_phi   =   x->sublead_jet_c46_phi;      
        sublead_jet_c47_phi   =   x->sublead_jet_c47_phi;      
        sublead_jet_c48_phi   =   x->sublead_jet_c48_phi;      
        sublead_jet_c49_phi   =   x->sublead_jet_c49_phi;      
        sublead_jet_c50_phi   =   x->sublead_jet_c50_phi;      
        sublead_jet_c51_phi   =   x->sublead_jet_c51_phi;      
        sublead_jet_c52_phi   =   x->sublead_jet_c52_phi;      
        sublead_jet_c53_phi   =   x->sublead_jet_c53_phi;      
        sublead_jet_c54_phi   =   x->sublead_jet_c54_phi;      
        sublead_jet_c55_phi   =   x->sublead_jet_c55_phi;      
        sublead_jet_c56_phi   =   x->sublead_jet_c56_phi;      
        sublead_jet_c57_phi   =   x->sublead_jet_c57_phi;      
        sublead_jet_c58_phi   =   x->sublead_jet_c58_phi;      
        sublead_jet_c59_phi   =   x->sublead_jet_c59_phi;      
        sublead_jet_c60_phi   =   x->sublead_jet_c60_phi;      

        sublead_jet_c1_charge =   x->sublead_jet_c1_charge;   
        sublead_jet_c2_charge =   x->sublead_jet_c2_charge;   
        sublead_jet_c3_charge =   x->sublead_jet_c3_charge;   
        sublead_jet_c4_charge =   x->sublead_jet_c4_charge;   
        sublead_jet_c5_charge =   x->sublead_jet_c5_charge;   
        sublead_jet_c6_charge =   x->sublead_jet_c6_charge;   
        sublead_jet_c7_charge =   x->sublead_jet_c7_charge;   
        sublead_jet_c8_charge =   x->sublead_jet_c8_charge;   
        sublead_jet_c9_charge =   x->sublead_jet_c9_charge;   
        sublead_jet_c10_charge =   x->sublead_jet_c10_charge;   
        sublead_jet_c11_charge =   x->sublead_jet_c11_charge;   
        sublead_jet_c12_charge =   x->sublead_jet_c12_charge;   
        sublead_jet_c13_charge =   x->sublead_jet_c13_charge;   
        sublead_jet_c14_charge =   x->sublead_jet_c14_charge;   
        sublead_jet_c15_charge =   x->sublead_jet_c15_charge;   
        sublead_jet_c16_charge =   x->sublead_jet_c16_charge;   
        sublead_jet_c17_charge =   x->sublead_jet_c17_charge;   
        sublead_jet_c18_charge =   x->sublead_jet_c18_charge;   
        sublead_jet_c19_charge =   x->sublead_jet_c19_charge;   
        sublead_jet_c20_charge =   x->sublead_jet_c20_charge;   
        sublead_jet_c21_charge =   x->sublead_jet_c21_charge;   
        sublead_jet_c22_charge =   x->sublead_jet_c22_charge;   
        sublead_jet_c23_charge =   x->sublead_jet_c23_charge;   
        sublead_jet_c24_charge =   x->sublead_jet_c24_charge;   
        sublead_jet_c25_charge =   x->sublead_jet_c25_charge;   
        sublead_jet_c26_charge =   x->sublead_jet_c26_charge;   
        sublead_jet_c27_charge =   x->sublead_jet_c27_charge;   
        sublead_jet_c28_charge =   x->sublead_jet_c28_charge;   
        sublead_jet_c29_charge =   x->sublead_jet_c29_charge;   
        sublead_jet_c30_charge =   x->sublead_jet_c30_charge;   
        sublead_jet_c31_charge =   x->sublead_jet_c31_charge;   
        sublead_jet_c32_charge =   x->sublead_jet_c32_charge;   
        sublead_jet_c33_charge =   x->sublead_jet_c33_charge;   
        sublead_jet_c34_charge =   x->sublead_jet_c34_charge;   
        sublead_jet_c35_charge =   x->sublead_jet_c35_charge;   
        sublead_jet_c36_charge =   x->sublead_jet_c36_charge;   
        sublead_jet_c37_charge =   x->sublead_jet_c37_charge;   
        sublead_jet_c38_charge =   x->sublead_jet_c38_charge;   
        sublead_jet_c39_charge =   x->sublead_jet_c39_charge;   
        sublead_jet_c40_charge =   x->sublead_jet_c40_charge;   
        sublead_jet_c41_charge =   x->sublead_jet_c41_charge;   
        sublead_jet_c42_charge =   x->sublead_jet_c42_charge;   
        sublead_jet_c43_charge =   x->sublead_jet_c43_charge;   
        sublead_jet_c44_charge =   x->sublead_jet_c44_charge;   
        sublead_jet_c45_charge =   x->sublead_jet_c45_charge;   
        sublead_jet_c46_charge =   x->sublead_jet_c46_charge;   
        sublead_jet_c47_charge =   x->sublead_jet_c47_charge;   
        sublead_jet_c48_charge =   x->sublead_jet_c48_charge;   
        sublead_jet_c49_charge =   x->sublead_jet_c49_charge;   
        sublead_jet_c50_charge =   x->sublead_jet_c50_charge;   
        sublead_jet_c51_charge =   x->sublead_jet_c51_charge;   
        sublead_jet_c52_charge =   x->sublead_jet_c52_charge;   
        sublead_jet_c53_charge =   x->sublead_jet_c53_charge;   
        sublead_jet_c54_charge =   x->sublead_jet_c54_charge;   
        sublead_jet_c55_charge =   x->sublead_jet_c55_charge;   
        sublead_jet_c56_charge =   x->sublead_jet_c56_charge;   
        sublead_jet_c57_charge =   x->sublead_jet_c57_charge;   
        sublead_jet_c58_charge =   x->sublead_jet_c58_charge;   
        sublead_jet_c59_charge =   x->sublead_jet_c59_charge;   
        sublead_jet_c60_charge =   x->sublead_jet_c60_charge;   

        sublead_jet_c1_pt =    x->sublead_jet_c1_pt;       
        sublead_jet_c2_pt =    x->sublead_jet_c2_pt;       
        sublead_jet_c3_pt =    x->sublead_jet_c3_pt;       
        sublead_jet_c4_pt =    x->sublead_jet_c4_pt;       
        sublead_jet_c5_pt =    x->sublead_jet_c5_pt;       
        sublead_jet_c6_pt =    x->sublead_jet_c6_pt;       
        sublead_jet_c7_pt =    x->sublead_jet_c7_pt;       
        sublead_jet_c8_pt =    x->sublead_jet_c8_pt;       
        sublead_jet_c9_pt =    x->sublead_jet_c9_pt;       
        sublead_jet_c10_pt =    x->sublead_jet_c10_pt;       
        sublead_jet_c11_pt =    x->sublead_jet_c11_pt;       
        sublead_jet_c12_pt =    x->sublead_jet_c12_pt;       
        sublead_jet_c13_pt =    x->sublead_jet_c13_pt;       
        sublead_jet_c14_pt =    x->sublead_jet_c14_pt;       
        sublead_jet_c15_pt =    x->sublead_jet_c15_pt;       
        sublead_jet_c16_pt =    x->sublead_jet_c16_pt;       
        sublead_jet_c17_pt =    x->sublead_jet_c17_pt;       
        sublead_jet_c18_pt =    x->sublead_jet_c18_pt;       
        sublead_jet_c19_pt =    x->sublead_jet_c19_pt;       
        sublead_jet_c20_pt =    x->sublead_jet_c20_pt;       
        sublead_jet_c21_pt =    x->sublead_jet_c21_pt;       
        sublead_jet_c22_pt =    x->sublead_jet_c22_pt;       
        sublead_jet_c23_pt =    x->sublead_jet_c23_pt;       
        sublead_jet_c24_pt =    x->sublead_jet_c24_pt;       
        sublead_jet_c25_pt =    x->sublead_jet_c25_pt;       
        sublead_jet_c26_pt =    x->sublead_jet_c26_pt;       
        sublead_jet_c27_pt =    x->sublead_jet_c27_pt;       
        sublead_jet_c28_pt =    x->sublead_jet_c28_pt;       
        sublead_jet_c29_pt =    x->sublead_jet_c29_pt;       
        sublead_jet_c30_pt =    x->sublead_jet_c30_pt;       
        sublead_jet_c31_pt =    x->sublead_jet_c31_pt;       
        sublead_jet_c32_pt =    x->sublead_jet_c32_pt;       
        sublead_jet_c33_pt =    x->sublead_jet_c33_pt;       
        sublead_jet_c34_pt =    x->sublead_jet_c34_pt;       
        sublead_jet_c35_pt =    x->sublead_jet_c35_pt;       
        sublead_jet_c36_pt =    x->sublead_jet_c36_pt;       
        sublead_jet_c37_pt =    x->sublead_jet_c37_pt;       
        sublead_jet_c38_pt =    x->sublead_jet_c38_pt;       
        sublead_jet_c39_pt =    x->sublead_jet_c39_pt;       
        sublead_jet_c40_pt =    x->sublead_jet_c40_pt;       
        sublead_jet_c41_pt =    x->sublead_jet_c41_pt;       
        sublead_jet_c42_pt =    x->sublead_jet_c42_pt;       
        sublead_jet_c43_pt =    x->sublead_jet_c43_pt;       
        sublead_jet_c44_pt =    x->sublead_jet_c44_pt;       
        sublead_jet_c45_pt =    x->sublead_jet_c45_pt;       
        sublead_jet_c46_pt =    x->sublead_jet_c46_pt;       
        sublead_jet_c47_pt =    x->sublead_jet_c47_pt;       
        sublead_jet_c48_pt =    x->sublead_jet_c48_pt;       
        sublead_jet_c49_pt =    x->sublead_jet_c49_pt;       
        sublead_jet_c50_pt =    x->sublead_jet_c50_pt;       
        sublead_jet_c51_pt =    x->sublead_jet_c51_pt;       
        sublead_jet_c52_pt =    x->sublead_jet_c52_pt;       
        sublead_jet_c53_pt =    x->sublead_jet_c53_pt;       
        sublead_jet_c54_pt =    x->sublead_jet_c54_pt;       
        sublead_jet_c55_pt =    x->sublead_jet_c55_pt;       
        sublead_jet_c56_pt =    x->sublead_jet_c56_pt;       
        sublead_jet_c57_pt =    x->sublead_jet_c57_pt;       
        sublead_jet_c58_pt =    x->sublead_jet_c58_pt;       
        sublead_jet_c59_pt =    x->sublead_jet_c59_pt;       
        sublead_jet_c60_pt =    x->sublead_jet_c60_pt;       

        sublead_jet_c1_energy = x->sublead_jet_c1_energy;   
        sublead_jet_c2_energy = x->sublead_jet_c2_energy;   
        sublead_jet_c3_energy = x->sublead_jet_c3_energy;   
        sublead_jet_c4_energy = x->sublead_jet_c4_energy;   
        sublead_jet_c5_energy = x->sublead_jet_c5_energy;   
        sublead_jet_c6_energy = x->sublead_jet_c6_energy;   
        sublead_jet_c7_energy = x->sublead_jet_c7_energy;   
        sublead_jet_c8_energy = x->sublead_jet_c8_energy;   
        sublead_jet_c9_energy = x->sublead_jet_c9_energy;   
        sublead_jet_c10_energy = x->sublead_jet_c10_energy;   
        sublead_jet_c11_energy = x->sublead_jet_c11_energy;   
        sublead_jet_c12_energy = x->sublead_jet_c12_energy;   
        sublead_jet_c13_energy = x->sublead_jet_c13_energy;   
        sublead_jet_c14_energy = x->sublead_jet_c14_energy;   
        sublead_jet_c15_energy = x->sublead_jet_c15_energy;   
        sublead_jet_c16_energy = x->sublead_jet_c16_energy;   
        sublead_jet_c17_energy = x->sublead_jet_c17_energy;   
        sublead_jet_c18_energy = x->sublead_jet_c18_energy;   
        sublead_jet_c19_energy = x->sublead_jet_c19_energy;   
        sublead_jet_c20_energy = x->sublead_jet_c20_energy;   
        sublead_jet_c21_energy = x->sublead_jet_c21_energy;   
        sublead_jet_c22_energy = x->sublead_jet_c22_energy;   
        sublead_jet_c23_energy = x->sublead_jet_c23_energy;   
        sublead_jet_c24_energy = x->sublead_jet_c24_energy;   
        sublead_jet_c25_energy = x->sublead_jet_c25_energy;   
        sublead_jet_c26_energy = x->sublead_jet_c26_energy;   
        sublead_jet_c27_energy = x->sublead_jet_c27_energy;   
        sublead_jet_c28_energy = x->sublead_jet_c28_energy;   
        sublead_jet_c29_energy = x->sublead_jet_c29_energy;   
        sublead_jet_c30_energy = x->sublead_jet_c30_energy;   
        sublead_jet_c31_energy = x->sublead_jet_c31_energy;   
        sublead_jet_c32_energy = x->sublead_jet_c32_energy;   
        sublead_jet_c33_energy = x->sublead_jet_c33_energy;   
        sublead_jet_c34_energy = x->sublead_jet_c34_energy;   
        sublead_jet_c35_energy = x->sublead_jet_c35_energy;   
        sublead_jet_c36_energy = x->sublead_jet_c36_energy;   
        sublead_jet_c37_energy = x->sublead_jet_c37_energy;   
        sublead_jet_c38_energy = x->sublead_jet_c38_energy;   
        sublead_jet_c39_energy = x->sublead_jet_c39_energy;   
        sublead_jet_c40_energy = x->sublead_jet_c40_energy;   
        sublead_jet_c41_energy = x->sublead_jet_c41_energy;   
        sublead_jet_c42_energy = x->sublead_jet_c42_energy;   
        sublead_jet_c43_energy = x->sublead_jet_c43_energy;   
        sublead_jet_c44_energy = x->sublead_jet_c44_energy;   
        sublead_jet_c45_energy = x->sublead_jet_c45_energy;   
        sublead_jet_c46_energy = x->sublead_jet_c46_energy;   
        sublead_jet_c47_energy = x->sublead_jet_c47_energy;   
        sublead_jet_c48_energy = x->sublead_jet_c48_energy;   
        sublead_jet_c49_energy = x->sublead_jet_c49_energy;   
        sublead_jet_c50_energy = x->sublead_jet_c50_energy;   
        sublead_jet_c51_energy = x->sublead_jet_c51_energy;   
        sublead_jet_c52_energy = x->sublead_jet_c52_energy;   
        sublead_jet_c53_energy = x->sublead_jet_c53_energy;   
        sublead_jet_c54_energy = x->sublead_jet_c54_energy;   
        sublead_jet_c55_energy = x->sublead_jet_c55_energy;   
        sublead_jet_c56_energy = x->sublead_jet_c56_energy;   
        sublead_jet_c57_energy = x->sublead_jet_c57_energy;   
        sublead_jet_c58_energy = x->sublead_jet_c58_energy;   
        sublead_jet_c59_energy = x->sublead_jet_c59_energy;   
        sublead_jet_c60_energy = x->sublead_jet_c60_energy;   

        
        subsublead_jet_c1_eta   =   x->subsublead_jet_c1_eta;
        subsublead_jet_c2_eta   =   x->subsublead_jet_c2_eta;      
        subsublead_jet_c3_eta   =   x->subsublead_jet_c3_eta;      
        subsublead_jet_c4_eta   =   x->subsublead_jet_c4_eta;      
        subsublead_jet_c5_eta   =   x->subsublead_jet_c5_eta;      
        subsublead_jet_c6_eta   =   x->subsublead_jet_c6_eta;      
        subsublead_jet_c7_eta   =   x->subsublead_jet_c7_eta;      
        subsublead_jet_c8_eta   =   x->subsublead_jet_c8_eta;      
        subsublead_jet_c9_eta   =   x->subsublead_jet_c9_eta;      
        subsublead_jet_c10_eta   =   x->subsublead_jet_c10_eta;      
        subsublead_jet_c11_eta   =   x->subsublead_jet_c11_eta;      
        subsublead_jet_c12_eta   =   x->subsublead_jet_c12_eta;      
        subsublead_jet_c13_eta   =   x->subsublead_jet_c13_eta;      
        subsublead_jet_c14_eta   =   x->subsublead_jet_c14_eta;      
        subsublead_jet_c15_eta   =   x->subsublead_jet_c15_eta;      
        subsublead_jet_c16_eta   =   x->subsublead_jet_c16_eta;      
        subsublead_jet_c17_eta   =   x->subsublead_jet_c17_eta;      
        subsublead_jet_c18_eta   =   x->subsublead_jet_c18_eta;      
        subsublead_jet_c19_eta   =   x->subsublead_jet_c19_eta;      
        subsublead_jet_c20_eta   =   x->subsublead_jet_c20_eta;      
        subsublead_jet_c21_eta   =   x->subsublead_jet_c21_eta;      
        subsublead_jet_c22_eta   =   x->subsublead_jet_c22_eta;      
        subsublead_jet_c23_eta   =   x->subsublead_jet_c23_eta;      
        subsublead_jet_c24_eta   =   x->subsublead_jet_c24_eta;      
        subsublead_jet_c25_eta   =   x->subsublead_jet_c25_eta;      
        subsublead_jet_c26_eta   =   x->subsublead_jet_c26_eta;      
        subsublead_jet_c27_eta   =   x->subsublead_jet_c27_eta;      
        subsublead_jet_c28_eta   =   x->subsublead_jet_c28_eta;      
        subsublead_jet_c29_eta   =   x->subsublead_jet_c29_eta;      
        subsublead_jet_c30_eta   =   x->subsublead_jet_c30_eta;      
        subsublead_jet_c31_eta   =   x->subsublead_jet_c31_eta;      
        subsublead_jet_c32_eta   =   x->subsublead_jet_c32_eta;      
        subsublead_jet_c33_eta   =   x->subsublead_jet_c33_eta;      
        subsublead_jet_c34_eta   =   x->subsublead_jet_c34_eta;      
        subsublead_jet_c35_eta   =   x->subsublead_jet_c35_eta;      
        subsublead_jet_c36_eta   =   x->subsublead_jet_c36_eta;      
        subsublead_jet_c37_eta   =   x->subsublead_jet_c37_eta;      
        subsublead_jet_c38_eta   =   x->subsublead_jet_c38_eta;      
        subsublead_jet_c39_eta   =   x->subsublead_jet_c39_eta;      
        subsublead_jet_c40_eta   =   x->subsublead_jet_c40_eta;      
        subsublead_jet_c41_eta   =   x->subsublead_jet_c41_eta;      
        subsublead_jet_c42_eta   =   x->subsublead_jet_c42_eta;      
        subsublead_jet_c43_eta   =   x->subsublead_jet_c43_eta;      
        subsublead_jet_c44_eta   =   x->subsublead_jet_c44_eta;      
        subsublead_jet_c45_eta   =   x->subsublead_jet_c45_eta;      
        subsublead_jet_c46_eta   =   x->subsublead_jet_c46_eta;      
        subsublead_jet_c47_eta   =   x->subsublead_jet_c47_eta;      
        subsublead_jet_c48_eta   =   x->subsublead_jet_c48_eta;      
        subsublead_jet_c49_eta   =   x->subsublead_jet_c49_eta;      
        subsublead_jet_c50_eta   =   x->subsublead_jet_c50_eta;      
        subsublead_jet_c51_eta   =   x->subsublead_jet_c51_eta;      
        subsublead_jet_c52_eta   =   x->subsublead_jet_c52_eta;      
        subsublead_jet_c53_eta   =   x->subsublead_jet_c53_eta;      
        subsublead_jet_c54_eta   =   x->subsublead_jet_c54_eta;      
        subsublead_jet_c55_eta   =   x->subsublead_jet_c55_eta;      
        subsublead_jet_c56_eta   =   x->subsublead_jet_c56_eta;      
        subsublead_jet_c57_eta   =   x->subsublead_jet_c57_eta;      
        subsublead_jet_c58_eta   =   x->subsublead_jet_c58_eta;      
        subsublead_jet_c59_eta   =   x->subsublead_jet_c59_eta;      
        subsublead_jet_c60_eta   =   x->subsublead_jet_c60_eta;      

        subsublead_jet_c1_phi   =   x->subsublead_jet_c1_phi;      
        subsublead_jet_c2_phi   =   x->subsublead_jet_c2_phi;      
        subsublead_jet_c3_phi   =   x->subsublead_jet_c3_phi;      
        subsublead_jet_c4_phi   =   x->subsublead_jet_c4_phi;      
        subsublead_jet_c5_phi   =   x->subsublead_jet_c5_phi;      
        subsublead_jet_c6_phi   =   x->subsublead_jet_c6_phi;      
        subsublead_jet_c7_phi   =   x->subsublead_jet_c7_phi;       
        subsublead_jet_c8_phi   =   x->subsublead_jet_c8_phi;      
        subsublead_jet_c9_phi   =   x->subsublead_jet_c9_phi;      
        subsublead_jet_c10_phi   =   x->subsublead_jet_c10_phi;      
        subsublead_jet_c11_phi   =   x->subsublead_jet_c11_phi;      
        subsublead_jet_c12_phi   =   x->subsublead_jet_c12_phi;      
        subsublead_jet_c13_phi   =   x->subsublead_jet_c13_phi;      
        subsublead_jet_c14_phi   =   x->subsublead_jet_c14_phi;      
        subsublead_jet_c15_phi   =   x->subsublead_jet_c15_phi;      
        subsublead_jet_c16_phi   =   x->subsublead_jet_c16_phi;      
        subsublead_jet_c17_phi   =   x->subsublead_jet_c17_phi;      
        subsublead_jet_c18_phi   =   x->subsublead_jet_c18_phi;      
        subsublead_jet_c19_phi   =   x->subsublead_jet_c19_phi;      
        subsublead_jet_c20_phi   =   x->subsublead_jet_c20_phi;      
        subsublead_jet_c21_phi   =   x->subsublead_jet_c21_phi;      
        subsublead_jet_c22_phi   =   x->subsublead_jet_c22_phi;      
        subsublead_jet_c23_phi   =   x->subsublead_jet_c23_phi;      
        subsublead_jet_c24_phi   =   x->subsublead_jet_c24_phi;      
        subsublead_jet_c25_phi   =   x->subsublead_jet_c25_phi;      
        subsublead_jet_c26_phi   =   x->subsublead_jet_c26_phi;      
        subsublead_jet_c27_phi   =   x->subsublead_jet_c27_phi;      
        subsublead_jet_c28_phi   =   x->subsublead_jet_c28_phi;      
        subsublead_jet_c29_phi   =   x->subsublead_jet_c29_phi;      
        subsublead_jet_c30_phi   =   x->subsublead_jet_c30_phi;      
        subsublead_jet_c31_phi   =   x->subsublead_jet_c31_phi;      
        subsublead_jet_c32_phi   =   x->subsublead_jet_c32_phi;      
        subsublead_jet_c33_phi   =   x->subsublead_jet_c33_phi;      
        subsublead_jet_c34_phi   =   x->subsublead_jet_c34_phi;      
        subsublead_jet_c35_phi   =   x->subsublead_jet_c35_phi;      
        subsublead_jet_c36_phi   =   x->subsublead_jet_c36_phi;      
        subsublead_jet_c37_phi   =   x->subsublead_jet_c37_phi;      
        subsublead_jet_c38_phi   =   x->subsublead_jet_c38_phi;      
        subsublead_jet_c39_phi   =   x->subsublead_jet_c39_phi;      
        subsublead_jet_c40_phi   =   x->subsublead_jet_c40_phi;      
        subsublead_jet_c41_phi   =   x->subsublead_jet_c41_phi;      
        subsublead_jet_c42_phi   =   x->subsublead_jet_c42_phi;      
        subsublead_jet_c43_phi   =   x->subsublead_jet_c43_phi;      
        subsublead_jet_c44_phi   =   x->subsublead_jet_c44_phi;      
        subsublead_jet_c45_phi   =   x->subsublead_jet_c45_phi;      
        subsublead_jet_c46_phi   =   x->subsublead_jet_c46_phi;      
        subsublead_jet_c47_phi   =   x->subsublead_jet_c47_phi;      
        subsublead_jet_c48_phi   =   x->subsublead_jet_c48_phi;      
        subsublead_jet_c49_phi   =   x->subsublead_jet_c49_phi;      
        subsublead_jet_c50_phi   =   x->subsublead_jet_c50_phi;      
        subsublead_jet_c51_phi   =   x->subsublead_jet_c51_phi;      
        subsublead_jet_c52_phi   =   x->subsublead_jet_c52_phi;      
        subsublead_jet_c53_phi   =   x->subsublead_jet_c53_phi;      
        subsublead_jet_c54_phi   =   x->subsublead_jet_c54_phi;      
        subsublead_jet_c55_phi   =   x->subsublead_jet_c55_phi;      
        subsublead_jet_c56_phi   =   x->subsublead_jet_c56_phi;      
        subsublead_jet_c57_phi   =   x->subsublead_jet_c57_phi;      
        subsublead_jet_c58_phi   =   x->subsublead_jet_c58_phi;      
        subsublead_jet_c59_phi   =   x->subsublead_jet_c59_phi;      
        subsublead_jet_c60_phi   =   x->subsublead_jet_c60_phi;      

        subsublead_jet_c1_charge =   x->subsublead_jet_c1_charge;   
        subsublead_jet_c2_charge =   x->subsublead_jet_c2_charge;   
        subsublead_jet_c3_charge =   x->subsublead_jet_c3_charge;   
        subsublead_jet_c4_charge =   x->subsublead_jet_c4_charge;   
        subsublead_jet_c5_charge =   x->subsublead_jet_c5_charge;   
        subsublead_jet_c6_charge =   x->subsublead_jet_c6_charge;   
        subsublead_jet_c7_charge =   x->subsublead_jet_c7_charge;   
        subsublead_jet_c8_charge =   x->subsublead_jet_c8_charge;   
        subsublead_jet_c9_charge =   x->subsublead_jet_c9_charge;   
        subsublead_jet_c10_charge =   x->subsublead_jet_c10_charge;   
        subsublead_jet_c11_charge =   x->subsublead_jet_c11_charge;   
        subsublead_jet_c12_charge =   x->subsublead_jet_c12_charge;   
        subsublead_jet_c13_charge =   x->subsublead_jet_c13_charge;   
        subsublead_jet_c14_charge =   x->subsublead_jet_c14_charge;   
        subsublead_jet_c15_charge =   x->subsublead_jet_c15_charge;   
        subsublead_jet_c16_charge =   x->subsublead_jet_c16_charge;   
        subsublead_jet_c17_charge =   x->subsublead_jet_c17_charge;   
        subsublead_jet_c18_charge =   x->subsublead_jet_c18_charge;   
        subsublead_jet_c19_charge =   x->subsublead_jet_c19_charge;   
        subsublead_jet_c20_charge =   x->subsublead_jet_c20_charge;   
        subsublead_jet_c21_charge =   x->subsublead_jet_c21_charge;   
        subsublead_jet_c22_charge =   x->subsublead_jet_c22_charge;   
        subsublead_jet_c23_charge =   x->subsublead_jet_c23_charge;   
        subsublead_jet_c24_charge =   x->subsublead_jet_c24_charge;   
        subsublead_jet_c25_charge =   x->subsublead_jet_c25_charge;   
        subsublead_jet_c26_charge =   x->subsublead_jet_c26_charge;   
        subsublead_jet_c27_charge =   x->subsublead_jet_c27_charge;   
        subsublead_jet_c28_charge =   x->subsublead_jet_c28_charge;   
        subsublead_jet_c29_charge =   x->subsublead_jet_c29_charge;   
        subsublead_jet_c30_charge =   x->subsublead_jet_c30_charge;   
        subsublead_jet_c31_charge =   x->subsublead_jet_c31_charge;   
        subsublead_jet_c32_charge =   x->subsublead_jet_c32_charge;   
        subsublead_jet_c33_charge =   x->subsublead_jet_c33_charge;   
        subsublead_jet_c34_charge =   x->subsublead_jet_c34_charge;   
        subsublead_jet_c35_charge =   x->subsublead_jet_c35_charge;   
        subsublead_jet_c36_charge =   x->subsublead_jet_c36_charge;   
        subsublead_jet_c37_charge =   x->subsublead_jet_c37_charge;   
        subsublead_jet_c38_charge =   x->subsublead_jet_c38_charge;   
        subsublead_jet_c39_charge =   x->subsublead_jet_c39_charge;   
        subsublead_jet_c40_charge =   x->subsublead_jet_c40_charge;   
        subsublead_jet_c41_charge =   x->subsublead_jet_c41_charge;   
        subsublead_jet_c42_charge =   x->subsublead_jet_c42_charge;   
        subsublead_jet_c43_charge =   x->subsublead_jet_c43_charge;   
        subsublead_jet_c44_charge =   x->subsublead_jet_c44_charge;   
        subsublead_jet_c45_charge =   x->subsublead_jet_c45_charge;   
        subsublead_jet_c46_charge =   x->subsublead_jet_c46_charge;   
        subsublead_jet_c47_charge =   x->subsublead_jet_c47_charge;   
        subsublead_jet_c48_charge =   x->subsublead_jet_c48_charge;   
        subsublead_jet_c49_charge =   x->subsublead_jet_c49_charge;   
        subsublead_jet_c50_charge =   x->subsublead_jet_c50_charge;   
        subsublead_jet_c51_charge =   x->subsublead_jet_c51_charge;   
        subsublead_jet_c52_charge =   x->subsublead_jet_c52_charge;   
        subsublead_jet_c53_charge =   x->subsublead_jet_c53_charge;   
        subsublead_jet_c54_charge =   x->subsublead_jet_c54_charge;   
        subsublead_jet_c55_charge =   x->subsublead_jet_c55_charge;   
        subsublead_jet_c56_charge =   x->subsublead_jet_c56_charge;   
        subsublead_jet_c57_charge =   x->subsublead_jet_c57_charge;   
        subsublead_jet_c58_charge =   x->subsublead_jet_c58_charge;   
        subsublead_jet_c59_charge =   x->subsublead_jet_c59_charge;   
        subsublead_jet_c60_charge =   x->subsublead_jet_c60_charge;   

        subsublead_jet_c1_pt =    x->subsublead_jet_c1_pt;       
        subsublead_jet_c2_pt =    x->subsublead_jet_c2_pt;       
        subsublead_jet_c3_pt =    x->subsublead_jet_c3_pt;       
        subsublead_jet_c4_pt =    x->subsublead_jet_c4_pt;       
        subsublead_jet_c5_pt =    x->subsublead_jet_c5_pt;       
        subsublead_jet_c6_pt =    x->subsublead_jet_c6_pt;       
        subsublead_jet_c7_pt =    x->subsublead_jet_c7_pt;       
        subsublead_jet_c8_pt =    x->subsublead_jet_c8_pt;       
        subsublead_jet_c9_pt =    x->subsublead_jet_c9_pt;       
        subsublead_jet_c10_pt =    x->subsublead_jet_c10_pt;       
        subsublead_jet_c11_pt =    x->subsublead_jet_c11_pt;       
        subsublead_jet_c12_pt =    x->subsublead_jet_c12_pt;       
        subsublead_jet_c13_pt =    x->subsublead_jet_c13_pt;       
        subsublead_jet_c14_pt =    x->subsublead_jet_c14_pt;       
        subsublead_jet_c15_pt =    x->subsublead_jet_c15_pt;       
        subsublead_jet_c16_pt =    x->subsublead_jet_c16_pt;       
        subsublead_jet_c17_pt =    x->subsublead_jet_c17_pt;       
        subsublead_jet_c18_pt =    x->subsublead_jet_c18_pt;       
        subsublead_jet_c19_pt =    x->subsublead_jet_c19_pt;       
        subsublead_jet_c20_pt =    x->subsublead_jet_c20_pt;       
        subsublead_jet_c21_pt =    x->subsublead_jet_c21_pt;       
        subsublead_jet_c22_pt =    x->subsublead_jet_c22_pt;       
        subsublead_jet_c23_pt =    x->subsublead_jet_c23_pt;       
        subsublead_jet_c24_pt =    x->subsublead_jet_c24_pt;       
        subsublead_jet_c25_pt =    x->subsublead_jet_c25_pt;       
        subsublead_jet_c26_pt =    x->subsublead_jet_c26_pt;       
        subsublead_jet_c27_pt =    x->subsublead_jet_c27_pt;       
        subsublead_jet_c28_pt =    x->subsublead_jet_c28_pt;       
        subsublead_jet_c29_pt =    x->subsublead_jet_c29_pt;       
        subsublead_jet_c30_pt =    x->subsublead_jet_c30_pt;       
        subsublead_jet_c31_pt =    x->subsublead_jet_c31_pt;       
        subsublead_jet_c32_pt =    x->subsublead_jet_c32_pt;       
        subsublead_jet_c33_pt =    x->subsublead_jet_c33_pt;       
        subsublead_jet_c34_pt =    x->subsublead_jet_c34_pt;       
        subsublead_jet_c35_pt =    x->subsublead_jet_c35_pt;       
        subsublead_jet_c36_pt =    x->subsublead_jet_c36_pt;       
        subsublead_jet_c37_pt =    x->subsublead_jet_c37_pt;       
        subsublead_jet_c38_pt =    x->subsublead_jet_c38_pt;       
        subsublead_jet_c39_pt =    x->subsublead_jet_c39_pt;       
        subsublead_jet_c40_pt =    x->subsublead_jet_c40_pt;       
        subsublead_jet_c41_pt =    x->subsublead_jet_c41_pt;       
        subsublead_jet_c42_pt =    x->subsublead_jet_c42_pt;       
        subsublead_jet_c43_pt =    x->subsublead_jet_c43_pt;       
        subsublead_jet_c44_pt =    x->subsublead_jet_c44_pt;       
        subsublead_jet_c45_pt =    x->subsublead_jet_c45_pt;       
        subsublead_jet_c46_pt =    x->subsublead_jet_c46_pt;       
        subsublead_jet_c47_pt =    x->subsublead_jet_c47_pt;       
        subsublead_jet_c48_pt =    x->subsublead_jet_c48_pt;       
        subsublead_jet_c49_pt =    x->subsublead_jet_c49_pt;       
        subsublead_jet_c50_pt =    x->subsublead_jet_c50_pt;       
        subsublead_jet_c51_pt =    x->subsublead_jet_c51_pt;       
        subsublead_jet_c52_pt =    x->subsublead_jet_c52_pt;       
        subsublead_jet_c53_pt =    x->subsublead_jet_c53_pt;       
        subsublead_jet_c54_pt =    x->subsublead_jet_c54_pt;       
        subsublead_jet_c55_pt =    x->subsublead_jet_c55_pt;       
        subsublead_jet_c56_pt =    x->subsublead_jet_c56_pt;       
        subsublead_jet_c57_pt =    x->subsublead_jet_c57_pt;       
        subsublead_jet_c58_pt =    x->subsublead_jet_c58_pt;       
        subsublead_jet_c59_pt =    x->subsublead_jet_c59_pt;       
        subsublead_jet_c60_pt =    x->subsublead_jet_c60_pt;       

        subsublead_jet_c1_energy = x->subsublead_jet_c1_energy;   
        subsublead_jet_c2_energy = x->subsublead_jet_c2_energy;   
        subsublead_jet_c3_energy = x->subsublead_jet_c3_energy;   
        subsublead_jet_c4_energy = x->subsublead_jet_c4_energy;   
        subsublead_jet_c5_energy = x->subsublead_jet_c5_energy;   
        subsublead_jet_c6_energy = x->subsublead_jet_c6_energy;   
        subsublead_jet_c7_energy = x->subsublead_jet_c7_energy;   
        subsublead_jet_c8_energy = x->subsublead_jet_c8_energy;   
        subsublead_jet_c9_energy = x->subsublead_jet_c9_energy;   
        subsublead_jet_c10_energy = x->subsublead_jet_c10_energy;   
        subsublead_jet_c11_energy = x->subsublead_jet_c11_energy;   
        subsublead_jet_c12_energy = x->subsublead_jet_c12_energy;   
        subsublead_jet_c13_energy = x->subsublead_jet_c13_energy;   
        subsublead_jet_c14_energy = x->subsublead_jet_c14_energy;   
        subsublead_jet_c15_energy = x->subsublead_jet_c15_energy;   
        subsublead_jet_c16_energy = x->subsublead_jet_c16_energy;   
        subsublead_jet_c17_energy = x->subsublead_jet_c17_energy;   
        subsublead_jet_c18_energy = x->subsublead_jet_c18_energy;   
        subsublead_jet_c19_energy = x->subsublead_jet_c19_energy;   
        subsublead_jet_c20_energy = x->subsublead_jet_c20_energy;   
        subsublead_jet_c21_energy = x->subsublead_jet_c21_energy;   
        subsublead_jet_c22_energy = x->subsublead_jet_c22_energy;   
        subsublead_jet_c23_energy = x->subsublead_jet_c23_energy;   
        subsublead_jet_c24_energy = x->subsublead_jet_c24_energy;   
        subsublead_jet_c25_energy = x->subsublead_jet_c25_energy;   
        subsublead_jet_c26_energy = x->subsublead_jet_c26_energy;   
        subsublead_jet_c27_energy = x->subsublead_jet_c27_energy;   
        subsublead_jet_c28_energy = x->subsublead_jet_c28_energy;   
        subsublead_jet_c29_energy = x->subsublead_jet_c29_energy;   
        subsublead_jet_c30_energy = x->subsublead_jet_c30_energy;   
        subsublead_jet_c31_energy = x->subsublead_jet_c31_energy;   
        subsublead_jet_c32_energy = x->subsublead_jet_c32_energy;   
        subsublead_jet_c33_energy = x->subsublead_jet_c33_energy;   
        subsublead_jet_c34_energy = x->subsublead_jet_c34_energy;   
        subsublead_jet_c35_energy = x->subsublead_jet_c35_energy;   
        subsublead_jet_c36_energy = x->subsublead_jet_c36_energy;   
        subsublead_jet_c37_energy = x->subsublead_jet_c37_energy;   
        subsublead_jet_c38_energy = x->subsublead_jet_c38_energy;   
        subsublead_jet_c39_energy = x->subsublead_jet_c39_energy;   
        subsublead_jet_c40_energy = x->subsublead_jet_c40_energy;   
        subsublead_jet_c41_energy = x->subsublead_jet_c41_energy;   
        subsublead_jet_c42_energy = x->subsublead_jet_c42_energy;   
        subsublead_jet_c43_energy = x->subsublead_jet_c43_energy;   
        subsublead_jet_c44_energy = x->subsublead_jet_c44_energy;   
        subsublead_jet_c45_energy = x->subsublead_jet_c45_energy;   
        subsublead_jet_c46_energy = x->subsublead_jet_c46_energy;   
        subsublead_jet_c47_energy = x->subsublead_jet_c47_energy;   
        subsublead_jet_c48_energy = x->subsublead_jet_c48_energy;   
        subsublead_jet_c49_energy = x->subsublead_jet_c49_energy;   
        subsublead_jet_c50_energy = x->subsublead_jet_c50_energy;   
        subsublead_jet_c51_energy = x->subsublead_jet_c51_energy;   
        subsublead_jet_c52_energy = x->subsublead_jet_c52_energy;   
        subsublead_jet_c53_energy = x->subsublead_jet_c53_energy;   
        subsublead_jet_c54_energy = x->subsublead_jet_c54_energy;   
        subsublead_jet_c55_energy = x->subsublead_jet_c55_energy;   
        subsublead_jet_c56_energy = x->subsublead_jet_c56_energy;   
        subsublead_jet_c57_energy = x->subsublead_jet_c57_energy;   
        subsublead_jet_c58_energy = x->subsublead_jet_c58_energy;   
        subsublead_jet_c59_energy = x->subsublead_jet_c59_energy;   
        subsublead_jet_c60_energy = x->subsublead_jet_c60_energy;   

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
