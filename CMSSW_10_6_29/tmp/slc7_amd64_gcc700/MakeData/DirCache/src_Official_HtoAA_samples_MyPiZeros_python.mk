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
