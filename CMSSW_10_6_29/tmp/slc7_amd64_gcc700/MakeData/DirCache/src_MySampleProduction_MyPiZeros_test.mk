ifeq ($(strip $(testMySampleProductionMyPiZerosTP)),)
testMySampleProductionMyPiZerosTP := self/src/MySampleProduction/MyPiZeros/test
testMySampleProductionMyPiZerosTP_files := $(patsubst src/MySampleProduction/MyPiZeros/test/%,%,$(foreach file,test_catch2_*.cc,$(eval xfile:=$(wildcard src/MySampleProduction/MyPiZeros/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/MySampleProduction/MyPiZeros/test/$(file). Please fix src/MySampleProduction/MyPiZeros/test/BuildFile.))))
testMySampleProductionMyPiZerosTP_TEST_RUNNER_CMD :=  testMySampleProductionMyPiZerosTP 
testMySampleProductionMyPiZerosTP_BuildFile    := $(WORKINGDIR)/cache/bf/src/MySampleProduction/MyPiZeros/test/BuildFile
testMySampleProductionMyPiZerosTP_LOC_USE := self  FWCore/TestProcessor catch2
testMySampleProductionMyPiZerosTP_PACKAGE := self/src/MySampleProduction/MyPiZeros/test
ALL_PRODS += testMySampleProductionMyPiZerosTP
testMySampleProductionMyPiZerosTP_INIT_FUNC        += $$(eval $$(call Binary,testMySampleProductionMyPiZerosTP,src/MySampleProduction/MyPiZeros/test,src_MySampleProduction_MyPiZeros_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
testMySampleProductionMyPiZerosTP_CLASS := TEST
else
$(eval $(call MultipleWarningMsg,testMySampleProductionMyPiZerosTP,src/MySampleProduction/MyPiZeros/test))
endif
ALL_COMMONRULES += src_MySampleProduction_MyPiZeros_test
src_MySampleProduction_MyPiZeros_test_parent := MySampleProduction/MyPiZeros
src_MySampleProduction_MyPiZeros_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_MySampleProduction_MyPiZeros_test,src/MySampleProduction/MyPiZeros/test,TEST))
