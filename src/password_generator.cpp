#include "../includes/CommandHandler.hpp"
#include "version.h"

#include <stdio.h>

int main(int argc,const char** argv) {
	commandStruct cmdStruct;
	cmdStruct.argCounter = argc;
	cmdStruct.argVector = argv;

	std::unique_ptr<commandHandler> handler = std::make_unique<commandHandler>();
	if(!handler) {
		fprintf(
				stderr,
				"Error occurred on handling input parameters, exiting...\n"
		);
		return 1;

	}

	std::unique_ptr<Command> command = handler->handleCommand(cmdStruct);

	if (command) {
		command->exec();

	} else {
		fprintf(stderr, "Error occurred on command execution process, exiting...\n");
		return 1;

	}

	return 0;
}
