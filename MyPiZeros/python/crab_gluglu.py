from CRABClient.UserUtilities import config

config = config()

config.General.requestName = 'MyCRABJob'  # Choose a unique name
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'  # Use 'Analysis' if processing existing data
config.JobType.psetName = 'Photons_rajdeep_dr_cfg.py'  # Dummy PSet required
config.JobType.scriptExe = 'runSkim_crab.sh'  # Your shell script
config.JobType.inputFiles = ['runSkim_crab.sh']  # Ensure script is sent with the job
config.JobType.outputFiles = ['output.root']  # Modify as needed
config.JobType.sendExternalFolder = True  # To access CMSSW if needed

# Input Data
config.Data.inputDataset = '/GluGluHToGG_M-125_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL18RECO-106X_upgrade2018_realistic_v11_L1v1-v2/AODSIM'  # Update this
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1  # Adjust as needed

# Output storage on EOS
config.Data.outLFNDirBase = '/store/user/s/sosaha/'  # EOS storage path
config.Data.publication = False
config.Data.ignoreLocality = True  # Ensures job runs even if data isn't at CERN

# Run job at CERN
config.Site.storageSite = 'T2_CH_CERN'
config.Site.whitelist = ['T2_*'] 
