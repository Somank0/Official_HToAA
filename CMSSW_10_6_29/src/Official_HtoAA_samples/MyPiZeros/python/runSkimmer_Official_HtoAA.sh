#!/usr/bin/bash

if [ -z $1 ] ; then
  echo "Please use: ./runSkimmer [massMin(MeV)] [massMax(MeV)] [stepSize(MeV)]" && exit 1;
fi
if [ -z $2 ] ; then
  echo "Please use: ./runSkimmer [massMin(MeV)] [massMax(MeV)] [stepSize(MeV)]" && exit 2;
fi
if [ -z $3 ] ; then
  echo "Please use: ./runSkimmer [massMin(MeV)] [massMax(MeV)] [stepSize(MeV)]" && exit 3;
fi

cmsenv;

#===================================== M_a = 1 GeV dataset ===========================================================
: << 'Comment'
files=(/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/42E324BA-45F1-EA11-B48C-E0071B7A25E0.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/404CA5AD-43F0-EA11-A328-0023AEFF2BD0.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/523F3079-41F1-EA11-BB24-0CC47AD24D32.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/00B123F7-FBF0-EA11-B576-008CFAC94188.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/0240A338-91F0-EA11-95E1-008CFAC94188.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/0C904C0D-7DF0-EA11-A7F3-008CFAE4532C.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/2064F39E-89F0-EA11-A358-008CFAE4516C.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/22332C72-89F0-EA11-B3D4-008CFAC94188.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/30D8F35E-12F1-EA11-B3C2-008CFAC93EF8.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/3270F569-85F0-EA11-8F5C-008CFAE45164.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/365323F0-BCF0-EA11-9A28-008CFAC94264.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/3E83F9D0-A5F0-EA11-BF96-008CFAC91100.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/4287D50A-79F0-EA11-AB8F-008CFAE450DC.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/42C7304F-16F1-EA11-AFDC-008CFAC93EB0.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/48533648-95F0-EA11-A88E-008CFAE45290.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/4AE381F5-DCF0-EA11-8118-008CFAC93BA0.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/54E695AE-99F0-EA11-9110-008CFAC94150.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/5C1B4DCB-0AF1-EA11-B680-008CFAC94138.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/60037467-D4F0-EA11-9F98-008CFAC91A3C.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/60F9C140-F3F0-EA11-889F-008CFAE4501C.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/62CBD86A-E8F0-EA11-8314-008CFAC94000.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/68D55936-91F0-EA11-A0EB-008CFAC93BE0.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/6E081ECF-C8F0-EA11-86D3-008CFAE45054.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/78B17D90-EFF0-EA11-A716-008CFAE45420.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/967A960D-7DF0-EA11-920F-008CFAC93D4C.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/9A71CA86-9DF0-EA11-92C3-008CFAC910E4.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/AE5B2DAC-D0F0-EA11-92E2-008CFAC91C00.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/B44D4FA5-A9F0-EA11-8AED-008CFAC94188.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/BA636D43-E0F0-EA11-B669-008CFAE4546C.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/C2C65789-81F0-EA11-ACC2-008CFAC910E4.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/D8257C8B-81F0-EA11-98CC-008CFAC910E4.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/D8C56C8E-B1F0-EA11-8DFA-008CFAC93BE0.root
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/DC576290-B5F0-EA11-AE7B-008CFAEBDBDC.root
 /store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/DE55A2C6-02F1-EA11-93A1-008CFAC93D24.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/E8315071-8DF0-EA11-B1F0-008CFAC93F44.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/F66374FD-C4F0-EA11-A5FF-008CFAC93D24.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/F85B001B-86F0-EA11-B380-008CFAC94188.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/F88A8750-C1F1-EA11-9BEB-008CFAC93C54.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/1A6CA068-F7F0-EA11-BF8D-A4BF0112BD0E.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/BEDA527D-B9F0-EA11-A2DA-BC97E128CE91.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/04CEA0EA-4BF1-EA11-B7FD-B02628272370.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/1EBA3E19-A2F0-EA11-A363-842B2B163FE6.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/40EA75AD-16F0-EA11-96D0-1866DAEB5C74.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/E2DBB888-64F0-EA11-8863-20040FE9AD58.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/EA9B08FD-45F1-EA11-A3AC-DCF401E5F4B0.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/F0098AA3-78F0-EA11-B629-1866DAEB5C74.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/B6A59F0A-03F1-EA11-8F43-B02628DEC200.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/042C75B8-0AF1-EA11-98A9-0CC47AFF2C2E.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/80626729-90F1-EA11-8991-B02628412510.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/5E9CB1BC-F0F0-EA11-A987-525400623DCD.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/FAC1D5E0-45F1-EA11-A9D1-C4346BC8D390.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/64EE0B12-07F1-EA11-8326-14187764311A.root 
/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/403E1825-3EF1-EA11-B97D-1C34DA62A118.root)

dataset="MA_1GeV"
Comment
files=(/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1p6GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/100000/08548F26-7AF0-EA11-9367-0CC47AF9B1B2.root)
#/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1p6GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/100000/88B44102-7DF7-EA11-828B-20CF3027A6DA.root)
dataset="MA_1p6GeV"
#===============================================================================================================================================================
for i in ${files[@]};
do
#root://cms-xrd-global.cern.ch//
#echo "Running Skimmer on $folder/${i}_AToGG_RECO_M1000.0.root"
cmsRun Photons_rajdeep_dr_cfg.py inputFile=${i} datasetname=$dataset
echo "Skimming done"
done
