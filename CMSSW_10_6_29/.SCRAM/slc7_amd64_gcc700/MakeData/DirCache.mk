ifeq ($(strip $(Photon_Skimmer)),)
Photon_Skimmer := self/src/MySampleProduction/MyPiZeros/plugins
PLUGINS:=yes
Photon_Skimmer_files := $(patsubst src/MySampleProduction/MyPiZeros/plugins/%,%,$(foreach file,Photon_Skimmer.cc,$(eval xfile:=$(wildcard src/MySampleProduction/MyPiZeros/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/MySampleProduction/MyPiZeros/plugins/$(file). Please fix src/MySampleProduction/MyPiZeros/plugins/BuildFile.))))
Photon_Skimmer_BuildFile    := $(WORKINGDIR)/cache/bf/src/MySampleProduction/MyPiZeros/plugins/BuildFile
Photon_Skimmer_LOC_USE := self  DataFormats/TrackReco DataFormats/EgammaCandidates DataFormats/PatCandidates DataFormats/HepMCCandidate FWCore/Framework FWCore/ServiceRegistry CommonTools/UtilAlgos FWCore/ParameterSet FWCore/PluginManager Geometry/CaloTopology Geometry/EcalAlgo DataFormats/EgammaReco DataFormats/MuonReco DataFormats/Common DataFormats/VertexReco DataFormats/EcalDetId DataFormats/EcalRecHit DataFormats/Candidate RecoEgamma/PhotonIdentification RecoEgamma/EgammaIsolationAlgos RecoEcal/EgammaCoreTools DataFormats/Math DataFormats/JetReco SimDataFormats/PileupSummaryInfo SimDataFormats/CaloHit Geometry/CaloGeometry Geometry/Records Geometry/HcalCommonData Calibration/Tools root rootminuit clhep rootrflx rootmath
Photon_Skimmer_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,Photon_Skimmer,Photon_Skimmer,$(SCRAMSTORENAME_LIB),src/MySampleProduction/MyPiZeros/plugins))
Photon_Skimmer_PACKAGE := self/src/MySampleProduction/MyPiZeros/plugins
ALL_PRODS += Photon_Skimmer
MySampleProduction/MyPiZeros_forbigobj+=Photon_Skimmer
Photon_Skimmer_INIT_FUNC        += $$(eval $$(call Library,Photon_Skimmer,src/MySampleProduction/MyPiZeros/plugins,src_MySampleProduction_MyPiZeros_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
Photon_Skimmer_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,Photon_Skimmer,src/MySampleProduction/MyPiZeros/plugins))
endif
ifeq ($(strip $(Photon_RefinedRecHit_NTuplizer)),)
Photon_RefinedRecHit_NTuplizer := self/src/MySampleProduction/MyPiZeros/plugins
PLUGINS:=yes
Photon_RefinedRecHit_NTuplizer_files := $(patsubst src/MySampleProduction/MyPiZeros/plugins/%,%,$(foreach file,Photon_RefinedRecHit_NTuplizer.cc,$(eval xfile:=$(wildcard src/MySampleProduction/MyPiZeros/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/MySampleProduction/MyPiZeros/plugins/$(file). Please fix src/MySampleProduction/MyPiZeros/plugins/BuildFile.))))
Photon_RefinedRecHit_NTuplizer_BuildFile    := $(WORKINGDIR)/cache/bf/src/MySampleProduction/MyPiZeros/plugins/BuildFile
Photon_RefinedRecHit_NTuplizer_LOC_USE := self  DataFormats/TrackReco DataFormats/EgammaCandidates DataFormats/PatCandidates DataFormats/HepMCCandidate FWCore/Framework FWCore/ServiceRegistry CommonTools/UtilAlgos FWCore/ParameterSet FWCore/PluginManager Geometry/CaloTopology Geometry/EcalAlgo DataFormats/EgammaReco DataFormats/MuonReco DataFormats/Common DataFormats/VertexReco DataFormats/EcalDetId DataFormats/EcalRecHit DataFormats/Candidate RecoEgamma/PhotonIdentification RecoEgamma/EgammaIsolationAlgos RecoEcal/EgammaCoreTools DataFormats/Math DataFormats/JetReco SimDataFormats/PileupSummaryInfo SimDataFormats/CaloHit Geometry/CaloGeometry Geometry/Records Geometry/HcalCommonData Calibration/Tools root rootminuit clhep rootrflx rootmath boost rootxmlio
Photon_RefinedRecHit_NTuplizer_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,Photon_RefinedRecHit_NTuplizer,Photon_RefinedRecHit_NTuplizer,$(SCRAMSTORENAME_LIB),src/MySampleProduction/MyPiZeros/plugins))
Photon_RefinedRecHit_NTuplizer_PACKAGE := self/src/MySampleProduction/MyPiZeros/plugins
ALL_PRODS += Photon_RefinedRecHit_NTuplizer
MySampleProduction/MyPiZeros_forbigobj+=Photon_RefinedRecHit_NTuplizer
Photon_RefinedRecHit_NTuplizer_INIT_FUNC        += $$(eval $$(call Library,Photon_RefinedRecHit_NTuplizer,src/MySampleProduction/MyPiZeros/plugins,src_MySampleProduction_MyPiZeros_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
Photon_RefinedRecHit_NTuplizer_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,Photon_RefinedRecHit_NTuplizer,src/MySampleProduction/MyPiZeros/plugins))
endif
ALL_COMMONRULES += src_MySampleProduction_MyPiZeros_plugins
src_MySampleProduction_MyPiZeros_plugins_parent := MySampleProduction/MyPiZeros
src_MySampleProduction_MyPiZeros_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_MySampleProduction_MyPiZeros_plugins,src/MySampleProduction/MyPiZeros/plugins,PLUGINS))
