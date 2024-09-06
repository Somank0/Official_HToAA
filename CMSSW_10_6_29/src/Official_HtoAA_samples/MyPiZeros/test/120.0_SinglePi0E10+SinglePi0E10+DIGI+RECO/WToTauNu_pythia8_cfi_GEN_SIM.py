# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: SinglePi0E10_pythia8_cfi --conditions auto:run1_mc -n 10 --eventcontent RAWSIM --relval 25000,100 -s GEN,SIM --datatier GEN-SIM --beamspot Realistic8TeVCollision --fileout file:step1.root
import FWCore.ParameterSet.Config as cms



process = cms.Process('SIM')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.Geometry.GeometrySimDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedRealistic8TeVCollision_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.SimIdeal_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

# Input source
process.source = cms.Source("EmptySource")

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('SinglePi0E10_pythia8_cfi nevts:10'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.RAWSIMoutput = cms.OutputModule("PoolOutputModule",
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    ),
    # compressionAlgorithm = cms.untracked.string('LZMA'),
    # compressionLevel = cms.untracked.int32(1),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM'),
        filterName = cms.untracked.string('')
    ),
    # eventAutoFlushCompressedSize = cms.untracked.int32(20971520),
    fileName = cms.untracked.string('file:step1WUncompressed.root'),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    # splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
process.genstepfilter.triggerConditions=cms.vstring("generation_step")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run1_mc', '')

#Pion Generation
#process.generator = cms.EDFilter("Pythia8EGun",
#    PGunParameters = cms.PSet(
#        AddAntiParticle = cms.bool(False),
#        MaxE = cms.double(50),
#        MaxEta = cms.double(3.0),
#        MaxPhi = cms.double(3.14159265359),
#        MinE = cms.double(10),
#        MinEta = cms.double(-3.0),
#        MinPhi = cms.double(-3.14159265359),
#        ParticleID = cms.vint32(25)
#        # ParticleID = cms.vint32(111)
#    ),
#    PythiaParameters = cms.PSet(
#        parameterSets = cms.vstring()
#    ),
#    Verbosity = cms.untracked.int32(0),
#    # firstRun = cms.untracked.uint32(1),
#    psethack = cms.string('single pi0 E 10')
#)
#W generation
process.generator = cms.EDFilter("Pythia8PtGun",
	PGunParameters = cms.PSet(
		AddAntiParticle = cms.bool(False),
		MaxEta = cms.double(2.4),
		MaxPhi = cms.double(3.14159265359),
		MaxPt = cms.double(160.0),
		MinEta = cms.double(-2.4),
		MinPhi = cms.double(-3.14159265359),
		MinPt = cms.double(0.0),
		ParticleID = cms.vint32(-24)
		),
		 initialSeed = cms.untracked.uint32(123456789),
		 engineName = cms.untracked.string('HepJamesRandom'),
		 PythiaParameters = cms.PSet(
			#parameterSets = cms.vstring('pythia8CommonSettings', 
			#			    'py8WDecaySettings', 
			#			    'pythiaTauJets'),
			parameterSets = cms.vstring('pythia8CommonSettings', 
						    'py8WDecaySettings'),
			py8WDecaySettings = cms.vstring('24:onMode = off'),
#							'24:onIfAny = 15 16'),
			pythia8CUEP8M1Settings = cms.vstring('Tune:pp 14', 
							     'Tune:ee 7', 
							     'MultipartonInteractions:pT0Ref=2.4024', 
							     'MultipartonInteractions:ecmPow=0.25208', 
							     'MultipartonInteractions:expPow=1.6'),
			pythia8CommonSettings = cms.vstring('Tune:preferLHAPDF = 2', 
							    'Main:timesAllowErrors = 10000', 
							    'Check:epTolErr = 0.01', 
							    'Beams:setProductionScalesFromLHEF = off', 
							    'SLHA:keepSM = on', 
							    'SLHA:minMassSM = 1000.', 
							    'ParticleDecays:limitTau0 = on', 
							    'ParticleDecays:tau0Max = 10', 
							    'ParticleDecays:allowPhotonRadiation = on'),
#			pythiaTauJets = cms.vstring(#'ParticleDecays:sophisticatedTau = 2', 
#				#'ParticleDecays:tauPolarization = 0', 
#				'15:onMode = off', 
#				'15:onIfAny = 211 -211 321 -321')
		)
	 )


# Path and EndPath definitions
process.generation_step = cms.Path(process.pgen)
process.simulation_step = cms.Path(process.psim)
process.genfiltersummary_step = cms.EndPath(process.genFilterSummary)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RAWSIMoutput_step = cms.EndPath(process.RAWSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.generation_step,process.genfiltersummary_step,process.simulation_step,process.endjob_step,process.RAWSIMoutput_step)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)
# filter all path with the production filter sequence
for path in process.paths:
	getattr(process,path).insert(0, process.generator)


# Customisation from command line

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
