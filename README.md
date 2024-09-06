#To get official HToAA samples
Go to das and search for 

"dataset=/HAHMHToAA_AToGG_MA-*GeV_TuneCUETP8M1_PSweights_13TeV-madgraph_pythia8/RunIISummer16DR80Premix-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/AODSIM" 

#Incase some samples are on Tape , create a rucio rule (as follows) to get a copy of those on disk.

source /cvmfs/cms.cern.ch/rucio/setup-py3.sh

export RUCIO_ACCOUNT=[username]

rucio add-rule scope:/name/of/the/dataset [no. of copies] [disk storage name] --lifetime <in seconds> 

Replace scope with cms (if accessing a CMS dataset) or any other scope as required.



