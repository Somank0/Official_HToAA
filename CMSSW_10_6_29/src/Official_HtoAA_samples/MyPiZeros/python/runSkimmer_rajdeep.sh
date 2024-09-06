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
#folder=fixedSample
#for ((i=$1 ; i<=$2 ; i+=$3));
#files=(8395948 8395949 8395950 8395951 8469823 8469824 8469827 8469826 8469825 8489062 8489053 8492293 8492294 8492295 8524230 8524231 8524232 8524224 8524229 8524226 8524227 8524223 8540541 8540540 8540538 8540532 8540533 8540536 8540529 8540539 8540528 8540531 8540535 8540537 8542512 8542517 8542514 8542519 8542515 8542511 8542518 8542513 8542516 8563751 8563760 8563753 8563757 8563763 8563755 8563765 8563762 8563764 8563761 8563758 8563759 8563756 8563752 8571059 8571061 8571064 8571057 8571058 8571060 8572988 8572989 8572992 8572991 8572984 8572983 8572985 8574765 8574760 8574761 8574759 8574758 8574762 8574769 )

#files=( 8875721 8875723 8875720 8875719 8883504 8883505 8883499 8883507 8883498 8883500 8883503 8904657 8904656 8933591 8933590 8933588 8933587 )
#files=( 9007197 9007198 9007196 9007189 9007191 9007193 9007190 9007195 9007194 9007192 )
#files=( 9120502 )

#Trache1
#folder=/eos/cms/store/group/dpg_ecal/alca_ecalcalib/ecalelf/ntuples/rchatter/Particle_Gun/;
#files=( 9007189 9007195 9025723 9029467 9007190 9007196 9025724 9029468 9007191 9007197 9025725 9007192 9007198 9025726 9007193 9025721 9025729 9007194 9025722 9029461 )
#for i in ${files[@]};
#do
#echo "Running Skimmer on $folder/${i}_AToGG_RECO_M2000.0.root"
#cmsRun Photons_rajdeep_dr_cfg.py inputFile=$folder/${i}_AToGG_RECO_M2000.0.root
#echo "Trache1 done"
#done

#Trache2
folder=/eos/cms/store/group/dpg_ecal/alca_ecalcalib/ecalelf/ntuples/rchatter/Particle_Gun/Tranche2/;
files=(9029460 9029469 9080449 9108981 9029462 9080445 9080450 9108983 9029463 9080446 9080451 9108987 9029464 9080447 9080452 9108988 9029466 9080448 9108980 9108989 )
#files=(9029460)
#for i in ${files[@]};
#do
#echo "Running Skimmer on $folder/${i}_AToGG_RECO_M2000.0.root"
#cmsRun Photons_rajdeep_dr_cfg.py inputFile=$folder/${i}_AToGG_RECO_M2000.0.root
#echo "Trache1 done"
#done

#Trache3
#folder=/eos/cms/store/group/dpg_ecal/alca_ecalcalib/ecalelf/ntuples/rchatter/Particle_Gun/Tranche3/;
#files=( 9120502 9120508 9131188 9131195 9120503 9120509 9131191 9131196 9120504 9120510 9131192 9131197 9120505 9120511 9131193 9139968 9120506 )
#files=( 9120512 ) 
#files=( 9131194 9139969 )

#Trache4
#folder=/eos/cms/store/group/dpg_ecal/alca_ecalcalib/ecalelf/ntuples/rchatter/Particle_Gun/Tranche4/;
#files=( 9155515 9155523 9164382 9164387 9155516 9155524 9164383 9164388 9155519 9164378 9164384 9201337 9155520 9164380 9164385 9201338 9155522 9164381 9164386 9201342 )
#files=(9201342)

for i in ${files[@]};
do
echo "Running Skimmer on $folder/${i}_AToGG_RECO_M2000.0.root"
cmsRun Photons_rajdeep_dr_cfg.py inputFile=$folder/${i}_AToGG_RECO_M2000.0.root
echo "Trache2 done"
done
