#include "../includes/passGen.hpp"
#include "../includes/passGenLogic.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory>
#include <time.h>

int passGen::buffErrHandler(char* InBuff) {
	if (InBuff == nullptr) {
	        printf("Error occurred on allocating buffer.\n");
	        return 1;
	    }
	return 0;
}

void easyPass::generate() {
	passGenHelper helper;
	helper.genLogic(cBuffer, buffErrHandler, index, 52, length);
}

void easyPass::getParams(passwordCommandParams& params) {
	mode = params.mode;
	length = params.length;
}

void normalPass::generate() {
	passGenHelper helper;
	helper.genLogic(cBuffer, buffErrHandler, index, 62, length);
}

void normalPass::getParams(passwordCommandParams& params) {
	mode = params.mode;
	length = params.length;
}

void strongPass::generate() {
	passGenHelper helper;
	helper.genLogic(cBuffer, buffErrHandler, index, 74, length);
}

void strongPass::getParams(passwordCommandParams& params) {
	mode = params.mode;
	length = params.length;
}

std::unique_ptr<passGen> passHandler::handler(passwordCommandParams& params){
	if (strcmp(params.mode, "--simple") == 0) {
		std::unique_ptr<easyPass> pass = std::make_unique<easyPass>();
		pass->getParams(params);
		return pass;

	} else if(strcmp(params.mode, "--normal") == 0) {
		std::unique_ptr<normalPass> pass = std::make_unique<normalPass>();
		pass->getParams(params);
		return pass;

	} else if(strcmp(params.mode, "--strong") == 0) {
		std::unique_ptr<strongPass> pass = std::make_unique<strongPass>();
		pass->getParams(params);
		return pass;

	} else {
		return nullptr;

	}
}

