ifeq ($(strip $(PyMySampleProductionMyPiZeros)),)
PyMySampleProductionMyPiZeros := self/src/MySampleProduction/MyPiZeros/python
src_MySampleProduction_MyPiZeros_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/MySampleProduction/MyPiZeros/python)
PyMySampleProductionMyPiZeros_files := $(patsubst src/MySampleProduction/MyPiZeros/python/%,%,$(wildcard $(foreach dir,src/MySampleProduction/MyPiZeros/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyMySampleProductionMyPiZeros_LOC_USE := self  
PyMySampleProductionMyPiZeros_PACKAGE := self/src/MySampleProduction/MyPiZeros/python
ALL_PRODS += PyMySampleProductionMyPiZeros
PyMySampleProductionMyPiZeros_INIT_FUNC        += $$(eval $$(call PythonProduct,PyMySampleProductionMyPiZeros,src/MySampleProduction/MyPiZeros/python,src_MySampleProduction_MyPiZeros_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyMySampleProductionMyPiZeros,src/MySampleProduction/MyPiZeros/python))
endif
ALL_COMMONRULES += src_MySampleProduction_MyPiZeros_python
src_MySampleProduction_MyPiZeros_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_MySampleProduction_MyPiZeros_python,src/MySampleProduction/MyPiZeros/python,PYTHON))
