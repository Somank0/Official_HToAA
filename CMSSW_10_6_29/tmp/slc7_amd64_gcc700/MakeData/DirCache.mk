ALL_SUBSYSTEMS+=Official_HtoAA_samples
subdirs_src_Official_HtoAA_samples = src_Official_HtoAA_samples_MyPiZeros
ALL_PACKAGES += Official_HtoAA_samples/MyPiZeros
subdirs_src_Official_HtoAA_samples_MyPiZeros := src_Official_HtoAA_samples_MyPiZeros_plugins src_Official_HtoAA_samples_MyPiZeros_python src_Official_HtoAA_samples_MyPiZeros_test
ifeq ($(strip $(PyOfficial_HtoAA_samplesMyPiZeros)),)
PyOfficial_HtoAA_samplesMyPiZeros := self/src/Official_HtoAA_samples/MyPiZeros/python
src_Official_HtoAA_samples_MyPiZeros_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Official_HtoAA_samples/MyPiZeros/python)
PyOfficial_HtoAA_samplesMyPiZeros_files := $(patsubst src/Official_HtoAA_samples/MyPiZeros/python/%,%,$(wildcard $(foreach dir,src/Official_HtoAA_samples/MyPiZeros/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyOfficial_HtoAA_samplesMyPiZeros_LOC_USE := self  
PyOfficial_HtoAA_samplesMyPiZeros_PACKAGE := self/src/Official_HtoAA_samples/MyPiZeros/python
ALL_PRODS += PyOfficial_HtoAA_samplesMyPiZeros
PyOfficial_HtoAA_samplesMyPiZeros_INIT_FUNC        += $$(eval $$(call PythonProduct,PyOfficial_HtoAA_samplesMyPiZeros,src/Official_HtoAA_samples/MyPiZeros/python,src_Official_HtoAA_samples_MyPiZeros_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyOfficial_HtoAA_samplesMyPiZeros,src/Official_HtoAA_samples/MyPiZeros/python))
endif
ALL_COMMONRULES += src_Official_HtoAA_samples_MyPiZeros_python
src_Official_HtoAA_samples_MyPiZeros_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Official_HtoAA_samples_MyPiZeros_python,src/Official_HtoAA_samples/MyPiZeros/python,PYTHON))
ifeq ($(strip $(testMySampleProductionMyPiZerosTP)),)
testMySampleProductionMyPiZerosTP := self/src/Official_HtoAA_samples/MyPiZeros/test
testMySampleProductionMyPiZerosTP_files := $(patsubst src/Official_HtoAA_samples/MyPiZeros/test/%,%,$(foreach file,test_catch2_*.cc,$(eval xfile:=$(wildcard src/Official_HtoAA_samples/MyPiZeros/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/Official_HtoAA_samples/MyPiZeros/test/$(file). Please fix src/Official_HtoAA_samples/MyPiZeros/test/BuildFile.))))
testMySampleProductionMyPiZerosTP_TEST_RUNNER_CMD :=  testMySampleProductionMyPiZerosTP 
testMySampleProductionMyPiZerosTP_BuildFile    := $(WORKINGDIR)/cache/bf/src/Official_HtoAA_samples/MyPiZeros/test/BuildFile
testMySampleProductionMyPiZerosTP_LOC_USE := self  FWCore/TestProcessor catch2
testMySampleProductionMyPiZerosTP_PACKAGE := self/src/Official_HtoAA_samples/MyPiZeros/test
ALL_PRODS += testMySampleProductionMyPiZerosTP
testMySampleProductionMyPiZerosTP_INIT_FUNC        += $$(eval $$(call Binary,testMySampleProductionMyPiZerosTP,src/Official_HtoAA_samples/MyPiZeros/test,src_Official_HtoAA_samples_MyPiZeros_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
testMySampleProductionMyPiZerosTP_CLASS := TEST
else
$(eval $(call MultipleWarningMsg,testMySampleProductionMyPiZerosTP,src/Official_HtoAA_samples/MyPiZeros/test))
endif
ALL_COMMONRULES += src_Official_HtoAA_samples_MyPiZeros_test
src_Official_HtoAA_samples_MyPiZeros_test_parent := Official_HtoAA_samples/MyPiZeros
src_Official_HtoAA_samples_MyPiZeros_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Official_HtoAA_samples_MyPiZeros_test,src/Official_HtoAA_samples/MyPiZeros/test,TEST))
