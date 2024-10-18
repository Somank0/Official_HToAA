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
  TLorentzVector pPho1_al_gen, pPho2_al_gen;
  TLorentzVector pPho1_asl_gen, pPho2_asl_gen;
  TLorentzVector p1reco, p2reco,pTreco;
  Long64_t nentries = fChain->GetEntriesFast();
 
  Long64_t nbytes = 0, nb = 0;
  Long64_t nbytes2 = 0, nb2 = 0;
  int decade = 0;
   int veto_count =0;

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
   if(A_lead_Pho_Gen_Pt->size() <2){
	cout<<"A1 eta"<<"\t"<<A_lead_Gen_eta->at(0)<<endl;
	cout<<"A1 eta"<<"\t"<<A_lead_Gen_pt->at(0)<<endl;
	veto_count = veto_count+1;
		}
    if(A_lead_Pho_Gen_Pt->size() <2 || A_sublead_Pho_Gen_Pt->size()<2){
	continue;} 
    fillhist = 0;
        pHgen.SetPtEtaPhiM(H_Gen_pt->at(0), H_Gen_eta->at(0), H_Gen_phi->at(0), H_Gen_mass->at(0));

	if(A_lead_Pho_Gen_Pt->size() <2)
	  {
		continue;
	  }
//if (jentry==10){break;}
//cout<< "Entry no." << "\t"<<jentry<< "\t" <<"No. of Gen photons"<<"\t"<< A_lead_Pho_Gen_Pt->size()+A_sublead_Pho_Gen_Pt->size()<<endl;
        
        pA_lead_gen.SetPtEtaPhiM(A_lead_Gen_pt->at(0),A_lead_Gen_eta->at(0),A_lead_Gen_phi->at(0),A_lead_Gen_mass->at(0));
	pA_sublead_gen.SetPtEtaPhiM(A_sublead_Gen_pt->at(0),A_sublead_Gen_eta->at(0),A_sublead_Gen_phi->at(0),A_sublead_Gen_mass->at(0));
        pPho1_al_gen.SetPtEtaPhiE(A_lead_Pho_Gen_Pt->at(0),A_lead_Pho_Gen_Eta->at(0),A_lead_Pho_Gen_Phi->at(0),A_lead_Pho_Gen_E->at(0));
        pPho2_al_gen.SetPtEtaPhiE(A_lead_Pho_Gen_Pt->at(1),A_lead_Pho_Gen_Eta->at(1),A_lead_Pho_Gen_Phi->at(1),A_lead_Pho_Gen_E->at(1));
        pPho1_asl_gen.SetPtEtaPhiE(A_sublead_Pho_Gen_Pt->at(0),A_sublead_Pho_Gen_Eta->at(0),A_sublead_Pho_Gen_Phi->at(0),A_sublead_Pho_Gen_E->at(0));
	pPho2_asl_gen.SetPtEtaPhiE(A_sublead_Pho_Gen_Pt->at(1),A_sublead_Pho_Gen_Eta->at(1),A_sublead_Pho_Gen_Phi->at(1),A_sublead_Pho_Gen_E->at(1));
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
        
        float gen_al_pho1_pt = pPho1_al_gen.Pt();
        float gen_al_pho1_eta=pPho1_al_gen.Eta();
	float gen_al_pho1_phi = pPho1_al_gen.Phi();
        float gen_al_pho1_E = pPho1_al_gen.Energy();
	float gen_al_pho2_pt = pPho2_al_gen.Pt();
	float gen_al_pho2_eta = pPho2_al_gen.Eta();
        float gen_al_pho2_phi = pPho2_al_gen.Phi();
        float gen_al_pho2_E = pPho2_al_gen.Energy();
        float al_angle_pho1_pho2 = pPho1_al_gen.Angle(pPho2_al_gen.Vect());

        float gen_asl_pho1_pt = pPho1_asl_gen.Pt();
	float gen_asl_pho1_eta = pPho1_asl_gen.Eta();
	float gen_asl_pho1_phi = pPho1_asl_gen.Phi();
    	float gen_asl_pho1_E = pPho1_asl_gen.Energy();
	float gen_asl_pho2_pt = pPho2_asl_gen.Pt();
	float gen_asl_pho2_eta = pPho2_asl_gen.Eta();
	float gen_asl_pho2_phi = pPho2_asl_gen.Phi();
	float gen_asl_pho2_E = pPho2_asl_gen.Energy();
	float asl_angle_pho1_pho2 = pPho1_asl_gen.Angle(pPho2_asl_gen.Vect());

	bool A_lead_EB = abs(gen_a_lead_eta)<1.44;
        bool A_lead_EE = (abs(gen_a_lead_eta)>=1.44 && abs(gen_a_lead_eta)<=2.5);
  	bool A_sublead_EB = abs(gen_a_sublead_eta)<1.44;
	bool A_sublead_EE = (abs(gen_a_sublead_eta)>=1.44 && abs(gen_a_sublead_eta)<=2.5);

	vector<vector<float>*> Pho_hit_x = {Hit_X_Pho1,Hit_X_Pho2,Hit_X_Pho3, Hit_X_Pho4};
        vector<vector<float>*> Pho_hit_y = {Hit_Y_Pho1, Hit_Y_Pho2, Hit_Y_Pho3, Hit_Y_Pho4};
        vector<vector<float>*> Pho_hit_z = {Hit_Z_Pho1,Hit_Z_Pho2,Hit_Z_Pho3,Hit_Z_Pho4};
	vector<vector<float>*> Pho_hit_E = {RecHitEnPho1,RecHitEnPho2,RecHitEnPho3,RecHitEnPho4};
  	vector<vector<float>*> Pho_hit_frac={RecHitFracPho1,RecHitFracPho2,RecHitFracPho3,RecHitFracPho4};
	vector<vector<float>*> Pho_hit_eta = {Hit_Eta_Pho1,Hit_Eta_Pho2,Hit_Eta_Pho3,Hit_Eta_Pho4};
	vector<vector<float>*> Pho_hit_phi = {Hit_Phi_Pho1,Hit_Phi_Pho2,Hit_Phi_Pho3,Hit_Phi_Pho4};

	vector<vector<float>*> ES_Pho_hit_x = {Hit_ES_X_Pho1,Hit_ES_X_Pho2,Hit_ES_X_Pho3, Hit_ES_X_Pho4};
        vector<vector<float>*> ES_Pho_hit_y = {Hit_ES_Y_Pho1, Hit_ES_Y_Pho2, Hit_ES_Y_Pho3, Hit_ES_Y_Pho4};
        vector<vector<float>*> ES_Pho_hit_z = {Hit_ES_Z_Pho1,Hit_ES_Z_Pho2,Hit_ES_Z_Pho3,Hit_ES_Z_Pho4};
	vector<vector<float>*> ES_Pho_hit_E = {ES_RecHitEnPho1,ES_RecHitEnPho2,ES_RecHitEnPho3,ES_RecHitEnPho4};
	vector<vector<float>*> ES_Pho_hit_eta = {Hit_ES_Eta_Pho1,Hit_ES_Eta_Pho2,Hit_ES_Eta_Pho3,Hit_ES_Eta_Pho4};
	vector<vector<float>*> ES_Pho_hit_phi = {Hit_ES_Phi_Pho1,Hit_ES_Phi_Pho2,Hit_ES_Phi_Pho3,Hit_ES_Phi_Pho4};

        Gen_H_Mass->Fill(Gen_H_mass);        Gen_H_Pt->Fill(Gen_H_pt);        Gen_H_Eta->Fill(Gen_H_eta);        Gen_H_Phi ->Fill(Gen_H_phi);        Gen_H_E ->Fill(Gen_H_En);        Gen_H_LB->Fill(Gen_H_lb);
       
	Gen_A_lead_mass->Fill(gen_a_lead_mass); Gen_A_lead_pt->Fill(gen_a_lead_pt);  Gen_A_lead_eta->Fill(gen_a_lead_eta);  Gen_A_lead_phi->Fill(gen_a_lead_phi); 
	Gen_A_lead_E->Fill(gen_a_lead_E); Gen_A_lead_LB->Fill(gen_a_lead_LB);
        
	Gen_A_sublead_mass->Fill(gen_a_sublead_mass); Gen_A_sublead_pt->Fill(gen_a_sublead_pt); Gen_A_sublead_eta->Fill(gen_a_sublead_eta); Gen_A_sublead_phi->Fill(gen_a_sublead_phi); 
	Gen_A_sublead_E->Fill(gen_a_sublead_E);     Gen_A_sublead_LB->Fill(gen_a_sublead_LB);

        Al_Asl_angle->Fill(angle_A1_A2);        Asl_E_by_Al_E->Fill(gen_a_lead_E/gen_a_sublead_E);
       
	Gen_pho1_al_pt->Fill(gen_al_pho1_pt);        Gen_pho1_al_eta->Fill(gen_al_pho1_eta);        Gen_pho1_al_phi->Fill(gen_al_pho1_phi);        Gen_pho1_al_E->Fill(gen_al_pho1_E);
        Gen_pho2_al_pt->Fill(gen_al_pho2_pt);        Gen_pho2_al_eta->Fill(gen_al_pho2_eta);        Gen_pho2_al_phi->Fill(gen_al_pho2_phi);        Gen_pho2_al_E->Fill(gen_al_pho2_E); 

        Gen_pho1_asl_pt->Fill(gen_asl_pho1_pt);        Gen_pho1_asl_eta->Fill(gen_asl_pho1_eta);	Gen_pho1_asl_phi ->Fill(gen_asl_pho1_phi);	Gen_pho1_asl_E ->Fill(gen_asl_pho1_E);
	Gen_pho2_asl_pt->Fill(gen_asl_pho2_pt); 	Gen_pho2_asl_eta->Fill(gen_asl_pho2_eta);	Gen_pho2_asl_phi ->Fill(gen_asl_pho2_phi);	Gen_pho2_asl_E ->Fill(gen_asl_pho2_E);

	al_pho1_by_pho2_pt->Fill(gen_al_pho1_pt/gen_al_pho2_pt);	al_pho1_by_pho2_E ->Fill(gen_al_pho1_E/gen_al_pho2_E);		al_pho1_pho2_angle->Fill(al_angle_pho1_pho2);		   	
	asl_pho1_by_pho2_pt->Fill(gen_asl_pho1_pt/gen_asl_pho2_pt);	asl_pho1_by_pho2_E->Fill(gen_asl_pho1_E/gen_asl_pho2_E);	asl_pho1_pho2_angle->Fill(asl_angle_pho1_pho2);
        
	if (abs(gen_a_lead_eta) <1.44){
        	a_eb_pT->Fill(gen_a_lead_pt); 	a_eb_lb->Fill(gen_a_lead_LB); 	a_eb_pho_angle->Fill(al_angle_pho1_pho2);}
	if (abs(gen_a_sublead_eta) <1.44){
		a_eb_pT->Fill(gen_a_sublead_pt); a_eb_lb->Fill(gen_a_sublead_LB); a_eb_pho_angle->Fill(asl_angle_pho1_pho2);}
	if (abs(gen_a_lead_eta)>=1.44 && abs(gen_a_lead_eta)<=2.5){
		a_ee_pT->Fill(gen_a_lead_pt); 	a_ee_lb->Fill(gen_a_lead_LB);	a_ee_pho_angle->Fill(al_angle_pho1_pho2);}
	if (abs(gen_a_sublead_eta)>=1.44 && abs(gen_a_sublead_eta)<=2.5);{
		a_ee_pT->Fill(gen_a_sublead_pt);	a_ee_lb->Fill(gen_a_sublead_LB);	a_ee_pho_angle->Fill(asl_angle_pho1_pho2);}
        
	if (abs(gen_a_lead_eta)<1.44 && abs(gen_a_sublead_eta)<1.44){ aa_angle_ebeb->Fill(angle_A1_A2);}
	if (abs(gen_a_lead_eta) >=1.44 && abs(gen_a_lead_eta)<=2.5 && abs(gen_a_sublead_eta)>=1.44 && abs(gen_a_sublead_eta)<=2.5){aa_angle_eeee->Fill(angle_A1_A2);}
	if(abs(gen_a_lead_eta)<1.44 &&  abs(gen_a_sublead_eta)>=1.44 && abs(gen_a_sublead_eta)<=2.5){aa_angle_ebee->Fill(angle_A1_A2);}
	if(abs(gen_a_sublead_eta) <1.44 && abs(gen_a_lead_eta) >=1.44 && abs(gen_a_lead_eta)<=2.5){aa_angle_ebee->Fill(angle_A1_A2);}


// ================================================= 2D Histograms =======================================================
	Al_eta_vs_Asl_eta->Fill(gen_a_lead_eta,gen_a_sublead_eta);
	Al_pt_vs_Asl_pt->Fill(gen_a_lead_pt,gen_a_sublead_pt);
	Al_p_vs_Asl_p->Fill(pA_lead_gen.P(),pA_sublead_gen.P());
	Al_mass_vs_Asl_mass ->Fill(gen_a_lead_mass,gen_a_sublead_mass);
	al_pho_eta1_eta2->Fill(gen_al_pho1_eta,gen_al_pho2_eta);
	asl_pho_eta1_eta2->Fill(gen_asl_pho1_eta,gen_asl_pho2_eta);
	al_pho_p1_p2 ->Fill(pPho1_al_gen.P(),pPho2_al_gen.P());
	asl_pho_p1_p2 ->Fill(pPho1_asl_gen.P(),pPho2_asl_gen.P());
	if(A_lead_EB){
	for (int i=0; i<A_flags->size();i++){
		if(A_flags->at(i)==0){
			float tot_unc_E=0;
		//cout<<"A_lead_eta"<<"\t"<<gen_a_lead_eta<<endl;
			for(int k=0; k< Pho_hit_x[i]->size();k++){
				a_eb_rechit_x->Fill(Pho_hit_x[i]->at(k));
				a_eb_rechit_y->Fill(Pho_hit_y[i]->at(k));
				a_eb_rechit_eta->Fill(Pho_hit_eta[i]->at(k));
		//cout<<Pho_hit_eta[i]->at(k)<<endl;

				a_eb_rechit_phi->Fill(Pho_hit_phi[i]->at(k));
				a_eb_hit_eta_phi->Fill(Pho_hit_eta[i]->at(k),Pho_hit_phi[i]->at(k));
				a_eb_hit_xy->Fill(Pho_hit_x[i]->at(k),Pho_hit_y[i]->at(k));
				a_eb_hit_eta_phi_En->Fill(Pho_hit_eta[i]->at(k),Pho_hit_phi[i]->at(k),Pho_hit_E[i]->at(k));
				a_eb_hit_xy_En->Fill(Pho_hit_x[i]->at(k),Pho_hit_y[i]->at(k),Pho_hit_E[i]->at(k));
			if(Pho_hit_frac[i]->at(k)<0){tot_unc_E = tot_unc_E + Pho_hit_E[i]->at(k);}
					}
			Tot_unc_E->Fill(tot_unc_E);
			Tot_unc_E_eb->Fill(tot_unc_E);
				}
			}
		}	
	if(A_sublead_EB){
	for (int i=0; i<A_flags->size();i++){
		if(A_flags->at(i)==1){
			float tot_unc_E = 0;
			for(int k=0; k< Pho_hit_x[i]->size();k++){
				a_eb_rechit_x->Fill(Pho_hit_x[i]->at(k));
				a_eb_rechit_y->Fill(Pho_hit_y[i]->at(k));
                                a_eb_rechit_eta->Fill(Pho_hit_eta[i]->at(k));
                                a_eb_rechit_phi->Fill(Pho_hit_phi[i]->at(k));
				a_eb_hit_eta_phi->Fill(Pho_hit_eta[i]->at(k),Pho_hit_phi[i]->at(k));
                                a_eb_hit_xy->Fill(Pho_hit_x[i]->at(k),Pho_hit_y[i]->at(k));
                                a_eb_hit_eta_phi_En->Fill(Pho_hit_eta[i]->at(k),Pho_hit_phi[i]->at(k),Pho_hit_E[i]->at(k));
                                a_eb_hit_xy_En->Fill(Pho_hit_x[i]->at(k),Pho_hit_y[i]->at(k),Pho_hit_E[i]->at(k));
			if(Pho_hit_frac[i]->at(k)<0){tot_unc_E = tot_unc_E + Pho_hit_E[i]->at(k);}
					}
			Tot_unc_E->Fill(tot_unc_E);
			Tot_unc_E_eb->Fill(tot_unc_E);
				}
			}
		}	
       
	if(A_lead_EE){
	for (int i=0; i<A_flags->size();i++){
		if(A_flags->at(i)==0){
			float tot_unc_E=0;
//cout<<"A_lead_eta"<<"\t"<<gen_a_lead_eta<<endl;
			for(int k=0; k< Pho_hit_x[i]->size();k++){
				a_ee_rechit_x->Fill(Pho_hit_x[i]->at(k));
				a_ee_rechit_y->Fill(Pho_hit_y[i]->at(k));
				a_ee_rechit_eta->Fill(Pho_hit_eta[i]->at(k));
//cout<<Pho_hit_eta[i]->at(k)<<endl;
				a_ee_rechit_phi->Fill(Pho_hit_phi[i]->at(k));
				a_ee_hit_eta_phi->Fill(Pho_hit_eta[i]->at(k),Pho_hit_phi[i]->at(k));
				a_ee_hit_xy->Fill(Pho_hit_x[i]->at(k),Pho_hit_y[i]->at(k));
				a_ee_hit_eta_phi_En->Fill(Pho_hit_eta[i]->at(k),Pho_hit_phi[i]->at(k),Pho_hit_E[i]->at(k));
				a_ee_hit_xy_En->Fill(Pho_hit_x[i]->at(k),Pho_hit_y[i]->at(k),Pho_hit_E[i]->at(k));
			if(Pho_hit_frac[i]->at(k)<0){tot_unc_E = tot_unc_E + Pho_hit_E[i]->at(k);}
					}
			Tot_unc_E->Fill(tot_unc_E);
			Tot_unc_E_ee->Fill(tot_unc_E);
				}
			}
		}	
	if(A_sublead_EE){
	for (int i=0; i<A_flags->size();i++){
		if(A_flags->at(i)==1){
		float tot_unc_E=0;
			for(int k=0; k< Pho_hit_x[i]->size();k++){
				a_ee_rechit_x->Fill(Pho_hit_x[i]->at(k));
				a_ee_rechit_y->Fill(Pho_hit_y[i]->at(k));
				a_ee_rechit_eta->Fill(Pho_hit_eta[i]->at(k));
				a_ee_rechit_phi->Fill(Pho_hit_phi[i]->at(k));
				a_ee_hit_xy->Fill(Pho_hit_x[i]->at(k),Pho_hit_y[i]->at(k));
				a_ee_hit_eta_phi->Fill(Pho_hit_eta[i]->at(k),Pho_hit_phi[i]->at(k));
				a_ee_hit_eta_phi_En->Fill(Pho_hit_eta[i]->at(k),Pho_hit_phi[i]->at(k),Pho_hit_E[i]->at(k));
                                a_ee_hit_xy_En->Fill(Pho_hit_x[i]->at(k),Pho_hit_y[i]->at(k),Pho_hit_E[i]->at(k));
		if(Pho_hit_frac[i]->at(k)<0){tot_unc_E = tot_unc_E + Pho_hit_E[i]->at(k);}
					}
			Tot_unc_E->Fill(tot_unc_E);
			Tot_unc_E_ee->Fill(tot_unc_E);
				}
			}
		}	
 
 }
 cout<<"Veto Counts:"<<"\t"<<veto_count<<endl;
}
