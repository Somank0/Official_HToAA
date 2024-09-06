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
files=(/store/mc/RunIISummer16DR80Premix/HAHMHToAA_AToGG_MA-1GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/42E324BA-45F1-EA11-B48C-E0071B7A25E0.root)

for i in ${files[@]};
do
echo "Running Skimmer on $folder/${i}_AToGG_RECO_M1000.0.root"
cmsRun Photons_rajdeep_dr_cfg.py inputFile="root://cms-xrd-global.cern.ch//${i}"
echo "Skimming done"
done
