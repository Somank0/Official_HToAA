#define ANALYZEHGCMuons_cxx

#include "AnalyzeHGCMuons.h"
#include "TLorentzVector.h"
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int ctr = 0;
int main(int argc, char *argv[]) {

  if (argc < 2) {
    cerr << "Please give 3 arguments "
         << "runList "
         << " "
         << "outputFileName"
         << " "
         << "dataset" << endl;
    return -1;
  }
  const char *inputFileList = argv[1];
  const char *outFileName = argv[2];
  const char *data = argv[3];
  const char *massP = argv[4];

  cout<<massP<<endl;
  AnalyzeHGCMuons hgcmuons(inputFileList, outFileName, data,massP);
  // cout << "dataset " << data << " " << endl;

  hgcmuons.EventLoop(data);

  return 0;
}

double DeltaPhi(double phi1, double phi2) {
  double result = phi1 - phi2;
  while (result > M_PI)
    result -= 2 * M_PI;
  while (result <= -M_PI)
    result += 2 * M_PI;
  return result;
}
double DeltaEta(double eta1, double eta2){
double result= abs(eta1-eta2);
return result;
}
double DeltaR(double eta1, double phi1, double eta2, double phi2) {
  double deta = eta1 - eta2;
  double dphi = DeltaPhi(phi1, phi2);
  return std::sqrt(deta * deta + dphi * dphi);
}
double DeltaX(double x1, double x2){
  double result = abs(x1 - x2);
  return result;
}
double DeltaL(double x1, double x2, double y1, double y2){
  double dx = x1-x2;
  double dy = y1-y2;
  double result = sqrt(dx*dx + dy*dy);
  return result;
}
void AnalyzeHGCMuons::EventLoop(const char *data) {
  if (fChain == 0)
    return;

  TLorentzVector pA_lead_gen, pA_sublead_gen, pHgen;
  TLorentzVector p1reco, p2reco,pTreco;
  Long64_t nentries = fChain->GetEntriesFast();
 
  Long64_t nbytes = 0, nb = 0;
  Long64_t nbytes2 = 0, nb2 = 0;
  int decade = 0;

  for (Long64_t jentry = 0; jentry < nentries; jentry++) {

  
    // ==============print number of events done == == == == == == == =
    double progress = 10.0 * jentry / (1.0 * nentries);
    int k = int(progress);
    if (k > decade)
      // cout << 10 * k << " %" << endl;
      decade = k;

    // ===============read this entry == == == == == == == == == == ==
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0)
      break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;

    if(H_Gen_mass->size()==0){continue;} 
    fillhist = 0;
        pHgen.SetPtEtaPhiM(H_Gen_pt->at(0), H_Gen_eta->at(0), H_Gen_phi->at(0), H_Gen_mass->at(0));

	if(Pho_Gen_Pt->size() <4)
	  {
		continue;
	  }
cout<< "Entry no." << "\t"<<jentry<< "\t" <<"No. of Gen photons"<<"\t"<< Pho_Gen_Pt->size()<<endl;
        
        pA_lead_gen.SetPtEtaPhiM(A_lead_Gen_pt->at(0),A_lead_Gen_eta->at(0),A_lead_Gen_phi->at(0),A_lead_Gen_mass->at(0));
	pA_sublead_gen.SetPtEtaPhiM(A_sublead_Gen_pt->at(0),A_sublead_Gen_eta->at(0),A_sublead_Gen_phi->at(0),A_sublead_Gen_mass->at(0));
        //Defining gen quantities
        float Gen_H_mass = H_Gen_mass->at(0);
        float Gen_H_pt = H_Gen_pt->at(0);
        float Gen_H_eta = H_Gen_eta->at(0);
        float Gen_H_phi = H_Gen_phi->at(0);
        float Gen_H_lb = pHgen.Gamma();
        float Gen_H_En = pHgen.E();
        
        float gen_a_lead_mass = A_lead_Gen_mass->at(0);
        float gen_a_lead_pt = A_lead_Gen_pt->at(0);
        float gen_a_lead_eta = A_lead_Gen_eta->at(0);
        float gen_a_lead_phi = A_lead_Gen_phi->at(0);
        float gen_a_lead_E = pA_lead_gen.E();
        float gen_a_lead_LB = pA_lead_gen.Gamma();
 
        float gen_a_sublead_mass = A_sublead_Gen_mass->at(0);
        float gen_a_sublead_pt = A_sublead_Gen_pt->at(0);
        float gen_a_sublead_eta = A_sublead_Gen_eta->at(0);
        float gen_a_sublead_phi = A_sublead_Gen_phi->at(0);
        float gen_a_sublead_E = pA_sublead_gen.E();
        float gen_a_sublead_LB = pA_sublead_gen.Gamma();
        float angle_A1_A2 = pA_lead_gen.Angle(pA_sublead_gen.Vect());
        
        Gen_H_Mass->Fill(Gen_H_mass);
        Gen_H_Pt->Fill(Gen_H_pt);
        Gen_H_Eta->Fill(Gen_H_eta);
        Gen_H_Phi ->Fill(Gen_H_phi);
        Gen_H_E ->Fill(Gen_H_En);
        Gen_H_LB->Fill(Gen_H_lb);
        Gen_A_lead_mass->Fill(gen_a_lead_mass);
        Gen_A_lead_pt->Fill(gen_a_lead_pt);
        Gen_A_lead_eta->Fill(gen_a_lead_eta);
        Gen_A_lead_phi ->Fill(gen_a_lead_phi);
        Gen_A_lead_E->Fill(gen_a_lead_E);
        Gen_A_lead_LB->Fill(gen_a_lead_LB);
        Gen_A_sublead_mass->Fill(gen_a_sublead_mass);
        Gen_A_sublead_pt->Fill(gen_a_sublead_pt);
        Gen_A_sublead_eta->Fill(gen_a_sublead_eta);
        Gen_A_sublead_phi->Fill(gen_a_sublead_phi);
        Gen_A_sublead_E->Fill(gen_a_sublead_E);
        Gen_A_sublead_LB->Fill(gen_a_sublead_LB);
        Al_Asl_angle->Fill(angle_A1_A2);
 }
 
}
