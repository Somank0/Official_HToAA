#ifndef ANALYZEHGCMuons_H
#define ANALYZEHGCMuons_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "HGCNtupleVariables.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TText.h"
#include "TH3F.h"
#include "TGraph.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TFrame.h"
#include "TFile.h"
#include "TKey.h"
#include "TLorentzVector.h"
#include "TDirectory.h"
#include "TVirtualHistPainter.h"
#include "TPaveStats.h"
#include "TLatex.h"

void PaintOverflow(TH1 *h)
{
  // This function paint the histogram h with an extra bin for overflows

  const char *name = h->GetName();
  const char *title = h->GetTitle();
  Int_t nx = h->GetNbinsX() + 1;
  Double_t x1 = h->GetBinLowEdge(1);
  Double_t bw = h->GetBinWidth(nx);
  Double_t x2 = h->GetBinLowEdge(nx) + bw;

  // Book a temporary histogram having ab extra bin for overflows
  TH1F *htmp = new TH1F("rebinned", title, nx, x1, x2);

  // Fill the new hitogram including the extra bin for overflows
  for (Int_t i = 1; i <= nx; i++)
  {
    htmp->Fill(htmp->GetBinCenter(i), h->GetBinContent(i));
  }

  // Fill the underflows
  htmp->Fill(x1 - 1, h->GetBinContent(0));

  // Restore the number of entries
  htmp->SetEntries(h->GetEntries());

  // Draw the temporary histogram
  htmp->Draw();
  TText *t = new TText(x2 - bw / 2, h->GetBinContent(nx), "Overflow");
  t->SetTextAngle(90);
  t->SetTextAlign(12);
  t->SetTextSize(0.03);
  ;
  t->Draw();
}
class AnalyzeHGCMuons : public HGCNtupleVariables
{

public:
  AnalyzeHGCMuons(const TString &inputFileList = "foo.txt", const char *outFileName = "histo.root", const char *dataset = "data", const char *massP="0.1");
  ~AnalyzeHGCMuons();
  Bool_t FillChain(TChain *chain, TChain *chain2, const TString &inputFileList);
  void graphHist(TH2F *hist, char title[], char name[]);
  Long64_t LoadTree(Long64_t entry);
  void EventLoop(const char *);
  void BookHistogram(const char *);
  void graphSide(TH1F *hist1, TH1F *hist2, string name,string x_title, string y_title);
  void graphSide(TH2F *hist1, TH2F *hist2, string name, string x_title, string y_title);
  void graphOverlay(TH2F *hist1, TH2F *hist2, string name,string x_title,string y_title);
  void graphOverlay(TH1F *hist1, TH1F *hist2, string name,string x_title,string y_title);
  void graphOverlay(TH1F *hist1, TH1F *hist2, TH1F *hist4,string name,string x_title,string y_title);
  void graphOverlay(TH1F *hist1, TH1F *hist2,TH1F *hist4,TH1F *hist5, string name,string x_title,string y_title);
  void graphOverlayLogy(TH1F *hist1, TH1F *hist2,TH1F *hist4,TH1F *hist5, string name,string x_title,string y_title);
  void DrawHist(TH1F *hist1, string name, string x_title, string y_title);
  void DrawHistLogy(TH1F *hist1, string name, string x_title, string y_title);
  void DrawHist(TH2F *hist1, string name, string x_title, string y_title);
  void DrawHistTXT(TH2F *hits, string name, string x_title, string y_title);
  void DrawHistNoStat(TH2F *hist1, string name, string x_title, string y_title);
  int fillhist = 1;
  /*int ctr_twogen = 0;
  int ctr_mcut = 0;
  int ctr_tworeco = 0;
  int ctr_onereco = 0;
  int ctr_onedr = 0;
  int ctr_twodr = 0;*/
//  string mass = "1.8";
  string gamma = "";
  string mass = "1.8";

  TFile *oFile;
  TDirectory *d_Layer1;

  /*TTree *treeout;
  double M_m_gen;
  double M_m_reco;
  double M_p_gen;
  double M_pt_gen;
  double M_eta_gen;
  double M_phi_gen;
  vector<float> M_pt_reco;
  vector<float> M_eta_reco;
  vector<float> M_phi_reco;
  vector<float> M_E_reco;

  vector<float> *M_HitX1;
  bool M_EEFlag1;
  bool M_EEFlag2;
  vector<float> *M_HitY1;
  vector<float> *M_HitZ1;
  vector<float> *M_HitEta1;
  vector<float> *M_HitPhi1;
  vector<float> *M_HitiEta1;
  vector<float> *M_HitiPhi1;
  vector<float> *M_HitEn1;
  vector<float> *M_HitET1;
  vector<float> *M_HitEZ1;
  vector<float> *M_HitX2;
  vector<float> *M_HitY2;
  vector<float> *M_HitZ2;
  vector<float> *M_HitEta2;
  vector<float> *M_HitPhi2;
  vector<float> *M_HitiEta2;
  vector<float> *M_HitiPhi2;
  vector<float> *M_HitEn2;
  vector<float> *M_HitET2;
  vector<float> *M_HitEZ2;
  vector<float> M_SigIEIE1;
  vector<float> M_SigIEIE2;
  vector<float> M_SigIPhiIPhi1;
  vector<float> M_SigIPhiIPhi2;
  vector<float> M_R9_Pho1;
  vector<float> M_R9_Pho2;
  
  vector<float> *M_ES_HitX1;
  vector<float> *M_ES_HitY1;
  vector<float> *M_ES_HitZ1;
  vector<float> *M_ES_HitEta1;
  vector<float> *M_ES_HitPhi1;
  vector<float> *M_ES_HitEn1;
  vector<float> *M_ES_HitX2;
  vector<float> *M_ES_HitY2;
  vector<float> *M_ES_HitZ2;
  vector<float> *M_ES_HitEta2;
  vector<float> *M_ES_HitPhi2;
  vector<float> *M_ES_HitEn2;

  double M_EBM;
  double M_angle_gen;
  int M_event;
  int M_lumi;
  int M_run;*/
  //  float m_gen;

//========================Declare Historgrams==============================================

// ================================== 1D histograms =========================================
TH1F *Gen_H_Mass;
TH1F *Gen_H_Pt;
TH1F *Gen_H_Eta;
TH1F *Gen_H_Phi;
TH1F *Gen_H_E;
TH1F *Gen_H_LB;

TH1F *Gen_A_lead_mass;
TH1F *Gen_A_lead_pt;
TH1F *Gen_A_lead_eta;
TH1F *Gen_A_lead_phi;
TH1F *Gen_A_lead_E;
TH1F *Gen_A_lead_LB;

TH1F *Gen_A_sublead_mass;
TH1F *Gen_A_sublead_pt;
TH1F *Gen_A_sublead_eta;
TH1F *Gen_A_sublead_phi;
TH1F *Gen_A_sublead_E;
TH1F *Gen_A_sublead_LB;
TH1F *Al_Asl_angle;
TH1F *Asl_E_by_Al_E;

TH1F *Gen_pho1_al_pt;
TH1F *Gen_pho1_al_eta;
TH1F *Gen_pho1_al_phi;
TH1F *Gen_pho1_al_E;
TH1F *Gen_pho2_al_pt;
TH1F *Gen_pho2_al_eta;
TH1F *Gen_pho2_al_phi;
TH1F *Gen_pho2_al_E;

TH1F *Gen_pho1_asl_pt;
TH1F *Gen_pho1_asl_eta;
TH1F *Gen_pho1_asl_phi;
TH1F *Gen_pho1_asl_E;
TH1F *Gen_pho2_asl_pt;
TH1F *Gen_pho2_asl_eta;
TH1F *Gen_pho2_asl_phi;
TH1F *Gen_pho2_asl_E;
TH1F *al_pho1_by_pho2_pt;
TH1F *asl_pho1_by_pho2_pt;
TH1F *al_pho1_by_pho2_E;
TH1F *asl_pho1_by_pho2_E;

TH1F *al_pho1_pho2_angle;
TH1F *asl_pho1_pho2_angle;
TH1F *a_eb_pT;
TH1F *a_ee_pT;
TH1F *a_ee_lb;
TH1F *a_eb_lb;
TH1F *aa_angle_ebeb;
TH1F *aa_angle_ebee;
TH1F *aa_angle_eeee;

TH1F *a_eb_pho_angle;
TH1F *a_ee_pho_angle; 

TH1F *a_eb_rechit_x;
TH1F *a_ee_rechit_x;
TH1F *a_eb_rechit_y;
TH1F *a_ee_rechit_y;
TH1F *a_eb_rechit_eta;
TH1F *a_eb_rechit_phi;
TH1F *a_ee_rechit_eta;
TH1F *a_ee_rechit_phi;
TH1F *Tot_unc_E;
TH1F *Tot_unc_E_eb;
TH1F *Tot_unc_E_ee;
// ============================================= 2D histograms =======================================
TH2F *Al_mass_vs_Asl_mass;
TH2F *Al_eta_vs_Asl_eta; 
TH2F *Al_pt_vs_Asl_pt;
TH2F *Al_p_vs_Asl_p;
TH2F *asl_pho_eta1_eta2;
TH2F *al_pho_eta1_eta2;
TH2F *al_pho_p1_p2;
TH2F *asl_pho_p1_p2;
TH2F *a_eb_hit_eta_phi;
TH2F *a_eb_hit_xy;
TH2F *a_ee_hit_xy;
TH2F *a_ee_hit_eta_phi;
TH2F *a_eb_hit_eta_phi_En;
TH2F *a_eb_hit_xy_En;
TH2F *a_ee_hit_xy_En;
TH2F *a_ee_hit_eta_phi_En;
};
#endif

#ifdef ANALYZEHGCMuons_cxx

void AnalyzeHGCMuons::BookHistogram(const char *outFileName)
{

  //  char hname[200], htit[200];
  //  double xlow = 0.0,  xhigh = 2000.0;
  //  int nbins = 2000;

  oFile = new TFile(outFileName, "recreate");
  oFile->cd();
  if (fillhist)
  { //Define histograms
 Gen_H_Mass		= new TH1F ("Gen_H_mass"	, "Gen_H_mass"	, 1000 , 120 , 130 );
 Gen_H_Pt 		= new TH1F ("Gen_H_pT"		, "Gen_H_pT"	, 1000 , 0   , 400 );
 Gen_H_Eta		= new TH1F ("Gen_H_eta"		, "Gen_H_eta"	, 1000 , -8  , 8   );
 Gen_H_Phi		= new TH1F ("Gen_H_phi"		, "Gen_H_phi"	, 1000 , -4  , 4   );
 Gen_H_E        	= new TH1F ("Gen_H_E"         	, "Gen_H_E"  	, 1000 , 0   , 2000);
 Gen_H_LB       	= new TH1F ("Gen_H_LB"      	, "Gen_H_LB"    , 1000 , 0   , 30  );

 Gen_A_lead_mass	= new TH1F ("A1_mass"       , "A_lead_mass" , 1000 , 0   , 3   );
 Gen_A_lead_pt		= new TH1F ("A1_pT"         , "A_lead_pT"   , 1000 , 0   , 400 );
 Gen_A_lead_eta		= new TH1F ("A1_eta"        , "A_lead_eta"  , 1000 , -8  , 8   );
 Gen_A_lead_phi		= new TH1F ("A1_phi"        , "A_lead_phi"  , 1000 , -4  , 4   );
 Gen_A_lead_E		= new TH1F ("A1_E"          , "A_lead_E"    , 1000 , 0   , 2000);
 Gen_A_lead_LB		= new TH1F ("A1_LB"		, "A_lead_LB"	, 1000 , 0   , 2000);

 Gen_A_sublead_mass     = new TH1F ("A2_mass" , "A_sublead_mass" , 1000 , 0   , 3   );  
 Gen_A_sublead_pt       = new TH1F ("A2_pT"   , "A_sublead_pT"   , 1000 , 0   , 400 );
 Gen_A_sublead_eta      = new TH1F ("A2_eta"  , "A_sublead_eta"  , 1000 , -8  , 8   );  
 Gen_A_sublead_phi      = new TH1F ("A2_phi"  , "A_sublead_phi"  , 1000 , -4  , 4   );  
 Gen_A_sublead_E        = new TH1F ("A2_E"    , "A_sublead_E"    , 1000 , 0   , 2000);
 Gen_A_sublead_LB       = new TH1F ("A2_LB"   , "A_sublead_LB"   , 1000 , 0   , 2000);
 
 a_eb_pT		= new TH1F ("A_EB_pT" , "A_EB_pT"	, 1000  , 0 , 400);
 a_ee_pT		= new TH1F ("A_EE_pT" , "A_EE_pT"	, 1000  , 0,  400);
 a_eb_lb		= new TH1F ("A_EB_LB" , "A_EB_LB"	, 1000  , 0, 2000);
 a_ee_lb		= new TH1F ("A_EE_LB" , "A_EE_LB"	, 1000  , 0, 2000);
 aa_angle_ebeb		= new TH1F ("AA_angle_EBEB","AA_angle_EBEB",	1000	, 0  , 4);
 aa_angle_ebee		= new TH1F ("AA_angle_EBEE","AA_angle_EBEE",	1000	, 0  , 4);
 aa_angle_eeee		= new TH1F ("AA_angle_EEEE","AA_angle_EEEE",	1000	, 0  , 4);
 a_eb_pho_angle		= new TH1F ("A_EB_pho_angle","A_EB_pho_angle",	1000	, 0  , 4);
 a_ee_pho_angle		= new TH1F ("A_EE_pho_angle","A_EE_pho_angle" , 1000	, 0  , 4);


 Al_Asl_angle		= new TH1F ("Angle_bw_As"	, "Angle_bs_As"	   , 1000 , 0   ,  4  );
 Asl_E_by_Al_E		= new TH1F ("E_ratio_A2_A1"	, "E_ratio_sl_l"   , 1000 , 0   ,  20);
 Gen_pho1_al_pt		= new TH1F ("Pho1_A1_pt"	, "Pho1_al_pt"	   , 1000 , 0   ,  400);
 Gen_pho1_al_eta	= new TH1F ("Pho1_A1_eta"	, "Pho1_al_eta"	   , 1000 , -8  , 8 );
 Gen_pho1_al_phi	= new TH1F ("Pho1_A1_phi"	, "Pho1_al_phi"	   , 1000 , -4  , 4);
 Gen_pho1_al_E		= new TH1F ("Pho1_A1_E"		, "Pho1_al_E"	   , 1000 , 0   ,2000);
 Gen_pho2_al_pt		= new TH1F ("Pho2_A1_pt"	, "Pho2_al_pt"	   , 1000 , 0   ,  400);
 Gen_pho2_al_eta	= new TH1F ("Pho2_A1_eta"	, "Pho2_al_eta"	   , 1000 , -8  , 8 );
 Gen_pho2_al_phi	= new TH1F ("Pho2_A1_phi"	, "Pho2_al_phi"	   , 1000 , -4  , 4);
 Gen_pho2_al_E		= new TH1F ("Pho2_A1_E"		, "Pho2_al_E"	   , 1000 , 0   ,2000);
 Gen_pho1_asl_pt        = new TH1F ("Pho1_A2_pt"       , "Pho1_asl_pt"     , 1000 , 0   ,  400);
 Gen_pho1_asl_eta       = new TH1F ("Pho1_A2_eta"      , "Pho1_asl_eta"    , 1000 , -8  , 8 );
 Gen_pho1_asl_phi       = new TH1F ("Pho1_A2_phi"      , "Pho1_asl_phi"    , 1000 , -4  , 4);
 Gen_pho1_asl_E         = new TH1F ("Pho1_A2_E"        , "Pho1_asl_E"      , 1000 , 0   ,2000);
 Gen_pho2_asl_pt        = new TH1F ("Pho2_A2_pt"       , "Pho2_asl_pt"     , 1000 , 0   ,  400);
 Gen_pho2_asl_eta       = new TH1F ("Pho2_A2_eta"      , "Pho2_asl_eta"    , 1000 , -8  , 8 );
 Gen_pho2_asl_phi       = new TH1F ("Pho2_A2_phi"      , "Pho2_asl_phi"    , 1000 , -4  , 4);
 Gen_pho2_asl_E         = new TH1F ("Pho2_A2_E"        , "Pho2_asl_E"      , 1000 , 0   ,2000);
 al_pho1_by_pho2_pt	= new TH1F ("A1_pho1_by_pho2_pt", "al_pho1_by_pho2_pt",1000,0,20);
 al_pho1_by_pho2_E	= new TH1F ("A1_pho1_by_pho2_E"	, "al_pho1_by_pho2_E", 1000, 0, 20);
 asl_pho1_by_pho2_pt	= new TH1F ("A2_pho1_by_pho2_pt", "asl_pho1_by_pho2_pt",1000,0,20);
 asl_pho1_by_pho2_E	= new TH1F ("A2_pho1_by_pho2_E" , "asl_pho1_by_pho2_E", 1000, 0, 20); 
 al_pho1_pho2_angle	= new TH1F ("A1_pho1_pho2_angle", "A1_pho1_pho2_angle",1000,0, 4);
 asl_pho1_pho2_angle	= new TH1F ("A2_pho1_pho2_angle","A2_pho1_pho2_angle", 1000, 0, 4);
 a_eb_rechit_x		= new TH1F ("A_EB_hit_X"	, "A_EB_hit_X"	     , 1000, -160,160);
 a_eb_rechit_y		= new TH1F ("A_EB_hit_Y"	, "A_EB_hit_Y"	     , 1000, -160,160);
 a_eb_rechit_eta	= new TH1F ("A_EB_hit_eta"	, "A_EB_hit_eta"     , 1000, -1.8, 1.8);
 a_eb_rechit_phi	= new TH1F ("A_EB_hit_phi"	, "A_EB_hit_phi"     , 1000, -4,  4 );
 a_ee_rechit_x		= new TH1F ("A_EE_hit_x"	, "A_EE_hit_x"	     , 1000, -160,160);
 a_ee_rechit_y		= new TH1F ("A_EE_hit_y"	, "A_EE_hit_y"	     , 1000, -160,160);
 a_ee_rechit_eta	= new TH1F ("A_EE_hit_eta" 	, "A_EE_hit_eta"     , 1000, -3,3);
 a_ee_rechit_phi	= new TH1F ("A_EE_hit_phi"      , "A_EE_hit_phi"     , 1000, -4,4);
 Tot_unc_E		= new TH1F ("Tot_unc_E"		, "Tot_unc_E"	     , 1000, 0 , 2000);
 Tot_unc_E_eb		= new TH1F ("Tot_unc_E_eb"	, "Tot_unc_E_eb"     , 1000, 0 , 2000);
 Tot_unc_E_ee		= new TH1F ("Tot_unc_E_ee"	, "Tot_unc_E_ee"     , 1000, 0 , 2000);

//=========================================== 2D Histograms =========================================
Al_eta_vs_Asl_eta	= new TH2F ("A1_eta_A2_eta"	, "Al_eta_A_sl_eta" , 1000, -8 , 8, 1000, -8, 8);
Al_pt_vs_Asl_pt		= new TH2F ("A1_pt_A2_pt"	, "Al_pt_Asl_pt"    , 1000 , 0, 400,1000, 0 , 400);
Al_p_vs_Asl_p		= new TH2F ("A1_p_A2_p"		, "Al_p_Asl_p"	    , 1000, 0 , 2000, 1000, 0, 2000);
Al_mass_vs_Asl_mass	= new TH2F ("A1_mass_A2_mass"	, "Al_mass_Asl_mass", 1000, 0 , 3   , 1000 , 0, 3);
al_pho_eta1_eta2	= new TH2F ("A1_pho_eta1_eta2"	, "Al_pho_eta1_eta2", 1000, -8 , 8, 1000, -8, 8);
asl_pho_eta1_eta2       = new TH2F ("A2_pho_eta1_eta2" , "Asl_pho_eta1_eta2", 1000, -8 , 8, 1000, -8, 8);
al_pho_p1_p2		= new TH2F ("A1_pho_p1_p2"	, "Al_pho_p1_p2"    ,  1000 , 0, 2000, 1000, 0, 2000);  
asl_pho_p1_p2		= new TH2F ("A2_pho_p1_p2"	, "A_sl_pho_p1_p2"   , 1000 , 0, 2000, 1000, 0, 2000);
a_eb_hit_eta_phi	= new TH2F ("A_EB_hit_eta_phi"	, "A_EB_hit_eta_phi", 1000  ,-2,2,1000, -4,4);
a_eb_hit_xy		= new TH2F ("A_EB_hit_xy"	, "A_EB_hit_xy"	    , 1000  , -160,160, 1000, -160,160);
a_ee_hit_eta_phi	= new TH2F ("A_EE_hit_eta_phi"  , "A_EE_hit_eta_phi", 1000  ,-3,3,1000, -4,4);
a_ee_hit_xy		= new TH2F ("A_EE_hit_xy"       , "A_EE_hit_xy"     , 1000  , -160,160, 1000, -160,160); 
a_eb_hit_eta_phi_En	= new TH2F ("A_EB_hit_eta_phi_En", "A_EB_hit_eta_phi_En", 1000  ,-2,2,1000, -4,4);
a_eb_hit_xy_En		= new TH2F ("A_EB_hit_xy_En"	, "A_EB_hit_xy_En"	    , 1000  , -160,160, 1000, -160,160);
a_ee_hit_eta_phi_En	= new TH2F ("A_EE_hit_eta_phi_En"  , "A_EE_hit_eta_phi_En", 1000  ,-3,3,1000, -4,4);
a_ee_hit_xy_En		= new TH2F ("A_EE_hit_xy_En"       , "A_EE_hit_xy_En"     , 1000  , -160,160, 1000, -160,160); 
	}
  }

AnalyzeHGCMuons::AnalyzeHGCMuons(const TString &inputFileList, const char *outFileName, const char *dataset, const char *massP)
{
    TChain *tree = new TChain("nTuplelize/T");
  TChain *tree2;
  mass = string(massP);

  if (!FillChain(tree, tree2, inputFileList))
    {std::cerr << "Cannot get the tree " << std::endl;
  }
  else
  {
    std::cout << "Initiating analysis of dataset " << dataset << std::endl;  }

  HGCNtupleVariables::Init(tree, tree2);

  BookHistogram(outFileName);
//cout<<massP<<endl;
  /*treeout = new TTree("fordrn", "ForDRN");
  treeout->Branch("Hit_X_Pho1", &M_HitX1);
  treeout->Branch("EEFlag1", &M_EEFlag1);
  treeout->Branch("EEFlag2", &M_EEFlag2);
  treeout->Branch("Hit_Y_Pho1", &M_HitY1);
  treeout->Branch("Hit_Z_Pho1", &M_HitZ1);
  treeout->Branch("Hit_Eta_Pho1", &M_HitEta1);
  treeout->Branch("Hit_Phi_Pho1", &M_HitPhi1);
  treeout->Branch("Hit_iEta_Pho1", &M_HitiEta1);
  treeout->Branch("Hit_iPhi_Pho1", &M_HitiPhi1);
  treeout->Branch("Hit_X_Pho2", &M_HitX2);
  treeout->Branch("Hit_Y_Pho2", &M_HitY2);
  treeout->Branch("Hit_Z_Pho2", &M_HitZ2);
  treeout->Branch("Hit_Eta_Pho2", &M_HitEta2);
  treeout->Branch("Hit_Phi_Pho2", &M_HitPhi2);
  treeout->Branch("Hit_iEta_Pho2", &M_HitiEta2);
  treeout->Branch("Hit_iPhi_Pho2", &M_HitiPhi2);
  treeout->Branch("RecHitEnPho1", &M_HitEn1);
  //treeout->Branch("RecHitETPho1", &M_HitET1);
  //treeout->Branch("RecHitEZPho1", &M_HitEZ1);
  treeout->Branch("RecHitEnPho2", &M_HitEn2);
  //treeout->Branch("RecHitETPho2", &M_HitET2);
  //treeout->Branch("RecHitEZPho2", &M_HitEZ2);
  treeout->Branch("A_Gen_mass", &M_m_gen);
  //treeout->Branch("p_gen", &M_p_gen);
  treeout->Branch("pt_gen", &M_pt_gen);
  treeout->Branch("A_Gen_pt", &M_eta_gen);
  treeout->Branch("A_Gen_phi", &M_phi_gen);
  treeout->Branch("Pho_SigIEIE",&M_SigIEIE1);
  //treeout->Branch("SigIEIEPho2",&M_SigIEIE2);
  treeout->Branch("R9_Pho1",&M_R9_Pho1);
  treeout->Branch("R9_Pho2",&M_R9_Pho2);
  treeout->Branch("Pho_SigIPhiIPhiPhi",&M_SigIPhiIPhi1);
  //treeout->Branch("SigIPhiIPhiPho2",&M_SigIPhiIPhi2);

  treeout->Branch("Hit_ES_X_Pho1", &M_ES_HitX1);
  treeout->Branch("Hit_ES_Y_Pho1", &M_ES_HitY1);
  treeout->Branch("Hit_ES_Z_Pho1", &M_ES_HitZ1);
  treeout->Branch("Hit_ES_Eta_Pho1", &M_ES_HitEta1);
  treeout->Branch("Hit_ES_Phi_Pho1", &M_ES_HitPhi1);
  treeout->Branch("ES_RecHitEnPho1", &M_ES_HitEn1);
  treeout->Branch("Hit_ES_X_Pho2", &M_ES_HitX2);
  treeout->Branch("Hit_ES_Y_Pho2", &M_ES_HitY2);
  treeout->Branch("Hit_ES_Z_Pho2", &M_ES_HitZ2);
  treeout->Branch("Hit_ES_Eta_Pho2", &M_ES_HitEta2);
  treeout->Branch("Hit_ES_Phi_Pho2", &M_ES_HitPhi2);
  treeout->Branch("ES_RecHitEnPho2", &M_ES_HitEn2);*/
}

Bool_t AnalyzeHGCMuons::FillChain(TChain *chain, TChain *chain2, const TString &inputFileList)
{

  ifstream infile(inputFileList, ifstream::in);
  std::string buffer;

  if (!infile.is_open())
  {
    std::cerr << "** ERROR: Can't open '" << inputFileList << "' for input" << std::endl;
    return kFALSE;
  }

  std::cout << "TreeUtilities : FillChain " << std::endl;
  while (1)
  {
    infile >> buffer;
    if (!infile.good())
      break;
    // std::cout << "Adding tree from " << buffer.c_str() << std::endl;
    chain->Add(buffer.c_str());
    // chain2->Add(buffer.c_str());
  }
  std::cout << "No. of Entries in chain  : " << chain->GetEntries() << std::endl;
  // std::cout << "No. of Entries in chain2 : " << chain2->GetEntries() << std::endl;
  return kTRUE;
}

Long64_t AnalyzeHGCMuons::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!fChain)
    return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0)
    return centry;
  if (!fChain->InheritsFrom(TChain::Class()))
    return centry;
  TChain *chain = (TChain *)fChain;
  if (chain->GetTreeNumber() != fCurrent)
  {
    fCurrent = chain->GetTreeNumber();
    //    Notify();
  }
  // Modified By Chirayu
  return centry;
  // End Modified

  if (!fChain2)
    return -5;
  Long64_t centry2 = fChain2->LoadTree(entry);
  if (centry2 < 0)
    return centry2;
  if (!fChain2->InheritsFrom(TChain::Class()))
    return centry2;
  TChain *chain2 = (TChain *)fChain2;
  if (chain2->GetTreeNumber() != fCurrent)
  {
    fCurrent = chain->GetTreeNumber();
    //    Notify();
  }

  if (centry == centry2)
    return centry;
  else
    return -1;
}
void AnalyzeHGCMuons::DrawHist(TH1F *hist1,string name, string x_title="", string y_title="")
{
string Name = name + ";" + x_title + ";" + y_title;
TCanvas *C= new TCanvas("C","C",1000,1000);
C->cd();
hist1->Draw("hist");
hist1->SetTitle(Name.c_str());
hist1->GetXaxis()->CenterTitle(true);
hist1->GetYaxis()->CenterTitle(true);
hist1->Write();
C->Update();
TPaveStats *st1 = (TPaveStats*)hist1->GetListOfFunctions()->FindObject("stats");	
st1->SetX1NDC(.77); st1->SetX2NDC(.9);st1->SetY1NDC(.9); st1->SetY2NDC(.77);
st1->Draw();
C->Modified();
C->Write();
C->SaveAs((name + string(".png")).c_str());
C->SaveAs((name + string(".pdf")).c_str());

}
void AnalyzeHGCMuons::DrawHistLogy(TH1F *hist1,string name, string x_title="", string y_title="")
{
string Name = name + ";" + x_title + ";" + y_title;
TCanvas *C= new TCanvas("C","C",1000,1000);
C->cd();
hist1->Draw("hist");
hist1->SetTitle(Name.c_str());
hist1->GetXaxis()->CenterTitle(true);
hist1->GetYaxis()->CenterTitle(true);
hist1->Write();
C->SetLogy();
C->Update();
TPaveStats *st1 = (TPaveStats*)hist1->GetListOfFunctions()->FindObject("stats");	
st1->SetX1NDC(.77); st1->SetX2NDC(.9);st1->SetY1NDC(.9); st1->SetY2NDC(.77);
st1->Draw();
C->Modified();
C->Write();
C->SaveAs((name + string(".png")).c_str());
C->SaveAs((name + string(".pdf")).c_str());

}
void AnalyzeHGCMuons::DrawHistTXT(TH2F *hist1, string name, string x_title="", string y_title="")
{
string Name = name + ";" + x_title + ";" + y_title;
TCanvas *C1= new TCanvas (name.c_str(),"",1200,1000);
C1->SetRightMargin(0.15);
hist1->Draw("COLZ+TEXT");
hist1->SetTitle(Name.c_str());
hist1->GetXaxis()->CenterTitle(true);
hist1->GetYaxis()->CenterTitle(true);
C1->Update();
hist1->Write();
hist1->SetStats(0);
C1->Modified();
C1->Write();
C1->SaveAs((name + string(".png")).c_str());
C1->SaveAs((name + string(".pdf")).c_str());

}
void AnalyzeHGCMuons::DrawHist(TH2F *hist1, string name, string x_title="", string y_title="")
{
string Name = name + ";" + x_title + ";" + y_title;
TCanvas *C1= new TCanvas (name.c_str(),"",1200,1000);
C1->SetRightMargin(0.15);
hist1->Draw("COLZ");
hist1->SetTitle(Name.c_str());
hist1->GetXaxis()->CenterTitle(true);
hist1->GetYaxis()->CenterTitle(true);
hist1->Write();
C1->Modified();

C1->Update();
C1->Write();
C1->SaveAs((name + string(".png")).c_str());
C1->SaveAs((name + string(".pdf")).c_str());

}
void AnalyzeHGCMuons::DrawHistNoStat(TH2F *hist1, string name, string x_title="", string y_title="")
{
string Name = name + ";" + x_title + ";" + y_title;
TCanvas *C1= new TCanvas (name.c_str(),"",1200,1000);
C1->SetRightMargin(0.15);
hist1->Draw("COLZ");
hist1->SetTitle(Name.c_str());
hist1->GetXaxis()->CenterTitle(true);
hist1->GetYaxis()->CenterTitle(true);
C1->Update();
hist1->SetStats(0);
hist1->Write();
C1->Modified();

C1->Write();
C1->SaveAs((name + string(".png")).c_str());
C1->SaveAs((name + string(".pdf")).c_str());

}


void AnalyzeHGCMuons::graphSide(TH1F *hist1, TH1F *hist2, string name,string x_title="", string y_title="")
{
  TCanvas *c1 = new TCanvas(name.c_str(), "", 200, 10, 700, 500);
  c1->Divide(2, 1);
  c1->cd(1);
  hist1->Draw("colz");
  hist1->GetXaxis()->SetTitle(x_title.c_str());
  hist1->GetYaxis()->SetTitle(y_title.c_str());
  hist1->GetXaxis()->CenterTitle(true);
  hist1->GetYaxis()->CenterTitle(true);
  c1->cd(2);
  hist2->Draw("colz");
  hist2->GetXaxis()->SetTitle(x_title.c_str());
  hist2->GetYaxis()->SetTitle(y_title.c_str());
  hist2->GetXaxis()->CenterTitle(true);
  hist2->GetYaxis()->CenterTitle(true);
  c1->Update();
  c1->GetFrame()->SetBorderSize(12);
  c1->Modified();
  c1->Write();
  c1->SaveAs((name + string(".png")).c_str());
 c1->SaveAs((name + string(".pdf")).c_str());
}
void AnalyzeHGCMuons::graphSide(TH2F *hist1, TH2F *hist2, string name,string x_title, string y_title)
{
  TCanvas *c1 = new TCanvas(name.c_str(), "", 200, 10, 700, 500);
  c1->Divide(2, 1);
  c1->cd(1);
  hist1->Draw("colz");
  hist1->GetXaxis()->SetTitle(x_title.c_str());
  hist1->GetYaxis()->SetTitle(x_title.c_str());
  hist1->GetXaxis()->CenterTitle(true);
  hist1->GetYaxis()->CenterTitle(true);

  c1->cd(2);
  hist2->Draw("colz");
  hist1->GetXaxis()->SetTitle(x_title.c_str());
  hist1->GetYaxis()->SetTitle(x_title.c_str());
  hist1->GetXaxis()->CenterTitle(true);
  hist1->GetYaxis()->CenterTitle(true);

  c1->Update();
  c1->GetFrame()->SetBorderSize(12);
  c1->Modified();
  c1->Write();
  c1->SaveAs((name + string(".png")).c_str());
  c1->SaveAs((name + string(".png")).c_str());

}

void AnalyzeHGCMuons::graphOverlay(TH1F *hist1, TH1F *hist2, TH1F *hist4, TH1F *hist5, string name,string x_title="",string y_title="")
{ 
  string Name=name + ";"+ x_title + ";" + y_title;
  gStyle->SetOptStat(1111);
  THStack *hist3 = new THStack(name.c_str(), Name.c_str());
  hist1->SetLineColor(kRed);
  hist2->SetLineColor(kBlue);
  hist4->SetLineColor(kGreen);
  hist5->SetLineColor(kBlack);
  hist3->Add(hist1,"sames");
  hist3->Add(hist2,"sames");
  hist3->Add(hist4,"sames");
  hist3->Add(hist5,"sames");
  TCanvas *c3 = new TCanvas("c3", "c3", 1000, 1000);
  c3->cd();
  hist3->Draw("NOSTACK");
    hist3->Write();
  c3->Update();
  TPaveStats *st1 = (TPaveStats*)hist1->GetListOfFunctions()->FindObject("stats");	
  TPaveStats *st2 = (TPaveStats*)hist2->GetListOfFunctions()->FindObject("stats");	
  TPaveStats *st4 = (TPaveStats*)hist4->GetListOfFunctions()->FindObject("stats");	
  TPaveStats *st5 = (TPaveStats*)hist5->GetListOfFunctions()->FindObject("stats");	
st1->SetX1NDC(.7); st1->SetX2NDC(.9);st1->SetY1NDC(.7); st1->SetY2NDC(.6);
st2->SetX1NDC(.7); st2->SetX2NDC(.9);st2->SetY1NDC(.6); st2->SetY2NDC(.5);
st4->SetX1NDC(.7); st4->SetX2NDC(.9);st4->SetY1NDC(.5); st4->SetY2NDC(.4);
st5->SetX1NDC(.7); st5->SetX2NDC(.9);st5->SetY1NDC(.4); st5->SetY2NDC(.3);
st1->Draw();st2->Draw();
st4->Draw();st5->Draw();
  c3->Modified();
  c3->BuildLegend(0.7, 0.7, 0.9, 0.9, "");
  
  c3->Write();
 
  c3->SaveAs((name + string(".pdf")).c_str());
  c3->SaveAs((name + string(".png")).c_str());
}
void AnalyzeHGCMuons::graphOverlayLogy(TH1F *hist1, TH1F *hist2, TH1F *hist4, TH1F *hist5, string name,string x_title="",string y_title="")
{ 
  string Name=name + ";"+ x_title + ";" + y_title;
  gStyle->SetOptStat(1111);
  THStack *hist3 = new THStack(name.c_str(), Name.c_str());
  hist1->SetLineColor(kRed);
  hist2->SetLineColor(kBlue);
  hist4->SetLineColor(kGreen);
  hist5->SetLineColor(kBlack);
  hist3->Add(hist1,"sames");
  hist3->Add(hist2,"sames");
  hist3->Add(hist4,"sames");
  hist3->Add(hist5,"sames");
  TCanvas *c3 = new TCanvas("c3", "c3", 1000, 1000);
  c3->cd();
  c3->SetLogy();
  hist3->Draw("NOSTACK");
    hist3->Write();
  c3->Update();
  TPaveStats *st1 = (TPaveStats*)hist1->GetListOfFunctions()->FindObject("stats");	
  TPaveStats *st2 = (TPaveStats*)hist2->GetListOfFunctions()->FindObject("stats");	
  TPaveStats *st4 = (TPaveStats*)hist4->GetListOfFunctions()->FindObject("stats");	
  TPaveStats *st5 = (TPaveStats*)hist5->GetListOfFunctions()->FindObject("stats");	
st1->SetX1NDC(.7); st1->SetX2NDC(.9);st1->SetY1NDC(.7); st1->SetY2NDC(.6);
st2->SetX1NDC(.7); st2->SetX2NDC(.9);st2->SetY1NDC(.6); st2->SetY2NDC(.5);
st4->SetX1NDC(.7); st4->SetX2NDC(.9);st4->SetY1NDC(.5); st4->SetY2NDC(.4);
st5->SetX1NDC(.7); st5->SetX2NDC(.9);st5->SetY1NDC(.4); st5->SetY2NDC(.3);
st1->Draw();st2->Draw();
st4->Draw();st5->Draw();
  c3->Modified();
  c3->BuildLegend(0.7, 0.7, 0.9, 0.9, "");
  
  c3->Write();
 
  c3->SaveAs((name + string(".pdf")).c_str());
  c3->SaveAs((name + string(".png")).c_str());
}
void AnalyzeHGCMuons::graphOverlay(TH1F *hist1, TH1F *hist2, string name,string x_title ="",string y_title="")
{ 
  string Name =name + ";"+ x_title + ";" + y_title;
  gStyle->SetOptStat(1111);
  THStack *hist3 = new THStack(name.c_str(), name.c_str());
  hist1->SetLineColor(kRed);
  hist2->SetLineColor(kBlue);
  hist3->Add(hist1,"sames");
  hist3->Add(hist2,"sames");
   TCanvas *c3 = new TCanvas("c3", "c3", 1000, 1000);
 // c3->cd();
  hist3->Draw("NOSTACK");
  hist3->GetXaxis()->SetTitle(x_title.c_str());
  hist3->GetYaxis()->SetTitle(y_title.c_str());
   hist3->Write();
  c3->Update();
  TPaveStats *st1 = (TPaveStats*)hist1->GetListOfFunctions()->FindObject("stats");	
  TPaveStats *st2 = (TPaveStats*)hist2->GetListOfFunctions()->FindObject("stats");	
st1->SetX1NDC(.7); st1->SetX2NDC(.9);st1->SetY1NDC(.7); st1->SetY2NDC(.6);
st2->SetX1NDC(.7); st2->SetX2NDC(.9);st2->SetY1NDC(.6); st2->SetY2NDC(.5);
st1->Draw();st2->Draw();
  c3->Modified();
  c3->BuildLegend(0.7, 0.7, 0.9, 0.9, "");
 
  c3->Write();
 
  c3->SaveAs((name + string(".pdf")).c_str());
  c3->SaveAs((name + string(".png")).c_str());
}

void AnalyzeHGCMuons::graphOverlay(TH1F *hist1, TH1F *hist2, TH1F *hist4,  string name,string x_title="",string y_title="")
{
  string Name=name + ";"+ x_title + ";" + y_title;
   gStyle->SetOptStat(1111);
  //c3->cd();
  THStack *hist3 = new THStack(name.c_str(), Name.c_str());
  hist1->SetLineColor(kRed);
  hist2->SetLineColor(kBlue);
  hist4->SetLineColor(kGreen);
  
  hist3->Add(hist1,"sames");
  hist3->Add(hist2,"sames");
  hist3->Add(hist4,"sames");
  
  TCanvas *c3 = new TCanvas("c3", "c3", 1000, 1000);
  hist3->Draw("NOSTACK");
    hist3->Write();
  c3->Update();
  TPaveStats *st1 = (TPaveStats*)hist1->GetListOfFunctions()->FindObject("stats");	
  TPaveStats *st2 = (TPaveStats*)hist2->GetListOfFunctions()->FindObject("stats");	
  TPaveStats *st4 = (TPaveStats*)hist4->GetListOfFunctions()->FindObject("stats");	
  
st1->SetX1NDC(.7); st1->SetX2NDC(.9);st1->SetY1NDC(.7); st1->SetY2NDC(.6);
st2->SetX1NDC(.7); st2->SetX2NDC(.9);st2->SetY1NDC(.6); st1->SetY2NDC(.5);
st4->SetX1NDC(.7); st4->SetX2NDC(.9);st4->SetY1NDC(.5); st1->SetY2NDC(.4);

st1->Draw();st2->Draw();
st4->Draw();
  c3->Modified();
  c3->BuildLegend(0.7, 0.7, 0.9, 0.9, "");
  
  c3->Write();
 
  c3->SaveAs((name + string(".pdf")).c_str());
  c3->SaveAs((name + string(".png")).c_str());
}


void AnalyzeHGCMuons::graphHist(TH2F *hist, char title[], char name[])
{

  TCanvas *c1 = new TCanvas(name, title, 200, 10, 700, 500);
  TGraph *gr1 = new TGraph();
  for (int i = 0; i < hist->GetNbinsX(); i++)
  {
    for (int j = 0; j < hist->GetNbinsY(); j++)
    {
      double x = hist->GetXaxis()->GetBinCenter(i);
      double y = hist->GetYaxis()->GetBinCenter(j);
      gr1->SetPoint(gr1->GetN(), x, y);
    }
  }
  gr1->SetLineColor(2);
  gr1->SetLineWidth(4);
  gr1->SetMarkerStyle(0);
  gr1->SetTitle(title);
  gr1->GetXaxis()->SetTitle("Eta");
  gr1->GetYaxis()->SetTitle("Pt");
  gr1->Draw("ACP");
  gr1->Write(name);

  // TCanvas::Update() draws the frame, after which one can change it
  c1->Update();
  c1->GetFrame()->SetBorderSize(12);
  c1->Modified();
}
void DivideHistogramZValues(TH2F *hist, Double_t constant)
{
  Int_t nBinsX = hist->GetNbinsX();
  Int_t nBinsY = hist->GetNbinsY();

  // Iterate over each bin and divide the z-value by the constant
  for (Int_t i = 1; i <= nBinsX; i++)
  {
    for (Int_t j = 1; j <= nBinsY; j++)
    {
      Double_t binContent = hist->GetBinContent(i, j);
      Double_t newContent = binContent / constant;
      hist->SetBinContent(i, j, newContent);
    }
  }
}

AnalyzeHGCMuons::~AnalyzeHGCMuons()
{

  fillhist = 1;
  if (fillhist)
  {
/*
    TH1F *plotsToPrintTH1F[] = {
  a_gen_mass,
  a_gen_pt,
  a_gen_E,
  
  nGen,
  
  nreco,
   } ;
    TH1F *plotsToPrintTH1Flog[] = {};
    TH1F *plotsToPrintTH1Flog[] = {};

    TH1F *plotsSideBySideTH1F[][2] = {};
    TH1F *plotsOverlayTH1F[][2] = {};
    TH2F *plotsToPrintTH2F[] = {} ;
    TH2F *plotsSideBySideTH2F[][2] = {};
    TH2F *plotsOverlayTH2F[][2] = {};
    //DivideHistogramZValues(deta_dphi_gen, deta_dphi_gen->GetEntries());
    DivideHistogramZValues();
   
    TStyle *st1 = new TStyle("st1", "my style");
    st1->cd();
    st1->SetPaintTextFormat(".2f");
    st1->SetOptStat(111111);
    st1->SetFrameFillColor(10);
    st1->SetFillColor(10);
    st1->SetCanvasColor(10);

    for (auto i : plotsToPrintTH2F)
    {
      TCanvas *c3 = new TCanvas("c3", "c3", 1600, 1400);
      c3->SetLeftMargin(0.125);
      c3->cd();
      i->Draw("colz");
      i->Draw("colz");
      i->GetXaxis()->SetTitleSize(0.045);
      i->GetYaxis()->SetTitleSize(0.045);
      i->SetStats(0);
      c3->Update();
      c3->Modified();
      c3->Write(i->GetName());
      c3->SaveAs((string(i->GetName()) + string(".pdf")).c_str());
      c3->SaveAs((string(i->GetName()) + string(".png")).c_str());
    }
    for (auto i : plotsSideBySideTH2F)
    {
      auto p1 = i[0];
      auto p2 = i[1];
      string name = string(p1->GetName()) + "," + string(p2->GetName());
      graphSide(p1, p2, name);
    }
    for (auto i : plotsOverlayTH2F)
    {
      auto p1 = i[0];
      auto p2 = i[1];
      string name = string(p1->GetName()) + "+" + string(p2->GetName());
      graphOverlay(p1, p2, name);
    }
    for (auto i : plotsToPrintTH1F)
    {
      TCanvas *c3 = new TCanvas("c3", "c3", 1600, 1400);
      c3->cd();
  //c3->SetLogy();
      i->SetTitle((i->GetTitle()+string(" mass(MeV)=")+mass).c_str());
      cout<<i->GetTitle()<<endl;
      i->Draw("colz");
      c3->Update();
      c3->Modified();
      c3->Write(i->GetName());
      c3->SaveAs((string("0")+mass+string(i->GetName()) + string(".pdf")).c_str());
      c3->SaveAs((string("0")+mass+string(i->GetName()) + string(".png")).c_str());
    }
    for (auto i : plotsToPrintTH1Flog)
    {
      TCanvas *c3 = new TCanvas("c3", "c3", 1600, 1400);
      c3->cd();
  c3->SetLogy();
      i->SetTitle((i->GetTitle()+string(" mass(MeV)=")+mass).c_str());
      i->Draw("colz");
      c3->Update();
      c3->Modified();
      c3->Write(i->GetName());
      c3->SaveAs((string("0log")+mass+string(i->GetName()) + string(".pdf")).c_str());
      c3->SaveAs((string("0log")+mass+string(i->GetName()) + string(".png")).c_str());
    }
    for (auto i : plotsSideBySideTH1F)
    {
      auto p1 = i[0];
      auto p2 = i[1];
      string name = string(p1->GetName()) + "," + string(p2->GetName());
      graphSide(p1, p2, name);
    }
    for (auto i : plotsOverlayTH1F)
    {
      auto p1 = i[0];
      auto p2 = i[1];
      string name = string(p1->GetName()) + "+" + string(p2->GetName());
      graphOverlay(p1, p2, name);
    }
    
  graphOverlayLogy(angle_240_260,angle_490_510,angle_740_760,angle_990_1010,"Angle_between_gen_photons","Angle","");
  graphOverlay(ES_L1_hits,ES_L2_hits,"Number_of_ES_rechits","Absolute Z (in cm)","");
  //graphOverlay(ES_L1_hits_En_weighed,ES_L2_hits_En_weighed,"ES_hits_weighed_by_energy","Absolute Z coordinate (in cm)","");
  DrawHistNoStat(EE_XY_occupancy,"EE XY hits", "X in cm", "Y in cm");
  DrawHistNoStat(EE_XY_occu_En_weighed,"EE XY hits weighed by energy","X in cm","Y in cm");
  DrawHist(ES_L1_L2_hits_En_weighed,"ES_hits_weighed_by_energy","Absolute Z coordinate (in cm)","");
  DrawHistTXT(Gen_pho_sep,"Seperation between gen photons","#Delta #eta","#Delta #phi");
  DrawHist(Pho1_RechitE_vs_A_gen_E,"Photon1 total rechit energy vs energy of A","Energy of A","Total rechit energy");
  DrawHist(a_gen_mass,"Gen mass of A","Mass of A (in GeV)");
  DrawHist(a_gen_pt,"Gen pT of A","pT of A (in GeV)");
  DrawHist(a_gen_eta,"Gen eta of A","#eta");
  DrawHist(a_gen_phi,"Gen phi of A","#phi");
  DrawHist(a_gen_E,"Gen energy of A","A_gen_energy (in GeV)");
  DrawHistLogy(a_gen_gamma,"Lorentz boost of A","Lorentz boost");
  DrawHistNoStat(a_gen_eta_vs_phi,"Gen #eta vs #phi of A","|#eta|","#phi");
  DrawHistNoStat(a_gen_mass_vs_pt,"Gen mass vs pT of A","Mass of A (in GeV)","pT of A (in GeV)");
  DrawHist(nGen,"No. of Gen photons","no. of Gen photons");
  DrawHist(pho1_gen_eta,"Photon1 Gen #eta","#eta");
  DrawHist(pho1_gen_phi,"Photon1 Gen #phi","#phi");
  DrawHist(pho1_gen_pt,"Photon1 Gen pT","pT (in GeV)");
  DrawHist(pho2_gen_eta,"Photon2 Gen #eta","#eta");
  DrawHist(pho2_gen_phi,"Photon2 Gen #phi","#phi");
  DrawHist(pho2_gen_pt,"Photon2 Gen pT","pT (in GeV)");
*/// DrawHist(gen_eta1_vs_eta2,"Gen #eta_1 vs #eta_2","#eta1","eta2");
//for(int i=0; i< OneDHist.size(); i++){OneDHist.at(i)->Write();}
//for (int j=0; j<TwoDHist.size(); j++){TwoDHist.at(j)->Write();}
 
 }


  // if (!fChain || !fChain2) return;
  if (!fChain)
    return;
  delete fChain->GetCurrentFile();
  // delete fChain2->GetCurrentFile();
  oFile->cd();
  oFile->Write();
  // fChain->CloneTree(-1,"");
  oFile->Close();
}

#endif
// TODO: Pt condition in dR matching (later), Plots vs mass using jupyter notebook, Publish , Write explainations( tomorrow)
