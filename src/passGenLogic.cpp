#include "../includes/passGenLogic.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory>

void passGenHelper::genLogic(char* cBuffer, int (*buffErrHandler)(char*), char* index, int percent, int length) {
	unsigned int seed = static_cast<unsigned int>(time(nullptr));
		srand(seed);

		cBuffer = (char*)malloc((length + 1) * sizeof(char));
		if (buffErrHandler(cBuffer) == -1) {
				exit(-1);
		}

	    for (int i = 0; i < length + 1; i++) {
	    	cBuffer[i] = index[rand() %percent];
	    }
	    cBuffer[length] = '\0';

	    printf("%s\n", cBuffer);
		free(cBuffer);
}
