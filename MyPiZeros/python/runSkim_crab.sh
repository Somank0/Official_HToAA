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
cd /eos/user/s/sosaha/HToAA_official_samples/CMSSW_10_6_29/src/Official_HtoAA_samples/MyPiZeros/python;
cmsenv;
#========================================== M_a = 0.8 GeV =====================================================
#dataset="MA_0p8GeV"
#files=$(dasgoclient --query="file dataset=/HAHMHToAA_AToGG_MA-0p8GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/RunIISummer16DR80Premix-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/AODSIM")

#===================================== M_a = 1 GeV dataset ===========================================================
#dataset="MA_1GeV"
#files=$(dasgoclient --query="file dataset=/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/RunIISummer16DR80Premix-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/AODSIM")
#====================================== M_a = 1.2 GeV dataset====================================================================
dataset="MA_1p2GeV"
files=$(dasgoclient --query="file dataset=/HAHMHToAA_AToGG_MA-1p2GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/RunIISummer16DR80Premix-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/AODSIM")
#====================================== M_a = 1.6 GeV dataset ========================================================
#dataset="MA_1p6GeV"
#files=$(dasgoclient --query="file dataset=/HAHMHToAA_AToGG_MA-1p6GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/RunIISummer16DR80Premix-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/AODSIM")
#============================================================================================================
#dataset="MA_0p6GeV"
#files=$(dasgoclient --query="file dataset=/HAHMHToAA_AToGG_MA-0p6GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/RunIISummer16DR80Premix-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/AODSIM")
#================================================================================================================
#dataset="MA_2GeV"
#files=$(dasgoclient --query="file dataset=/HAHMHToAA_AToGG_MA-2GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/RunIISummer16DR80Premix-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/AODSIM")
#========================================================================================================
dataset="crab_test"
files=$(dasgoclient --query="file dataset=/GluGluHToGG_M-125_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL18RECO-106X_upgrade2018_realistic_v11_L1v1-v2/AODSIM")
for i in ${files[@]};
do
#root://cms-xrd-global.cern.ch//
#echo "Running Skimmer on $folder/${i}_AToGG_RECO_M1000.0.root"
cmsRun Photons_rajdeep_dr_cfg.py inputFile=${i} datasetname=$dataset
echo "Skimming done"
done
