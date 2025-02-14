#include "../includes/CommandHandler.hpp"
#include "../includes/passGen.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <vector>
#include <memory>
#include <cstdlib>
#include <string>
#include <unordered_map>


void helpCommand::exec() {
	printf(
			"Usage: passGen [options] <passwordLength>\n"
	        "Options:\n"
	        "  --simple : Generate a simple password using letters (a-z).\n"
	        "  --normal : Generate a normal password using letters (a-z) and digits (0-9).\n"
	        "  --strong : Generate a strong password using letters (a-z), digits (0-9), and symbols.\n"
	        "  -h       : Display this help message.\n"
	    );
}

void versionCommand::exec() {
	printf(
			"Current version: %i.%i.%i\n",
			password_generator_VERSION_MAJOR,
			password_generator_VERSION_MINOR,
			password_generator_VERSION_PATCH
		);
}

void passwordCommand::exec() {
	std::unique_ptr<passHandler> handle = std::make_unique<passHandler>();
	std::unique_ptr<passGen> passgen = handle->handler(iparams);

	if (passgen) {
		passgen->generate();
		exit(EXIT_SUCCESS);
	} else {
		fprintf(stderr, "Error occurred on handling commands, run the program with \" --help \" for more details.\n");
		exit(EXIT_FAILURE);
	}

}

void passwordCommand::getParams(passwordCommandParams& params) {
	iparams.mode = params.mode;
	iparams.length = params.length;

}

void commandHandler::misUse(const commandStruct& commands) {
	fprintf(
			stderr,
			"Unrecognized command or misuse of the program, run %s --help for further clarification.\n",
			commands.argVector[0]
	);

}

std::unique_ptr<Command> commandHandler::handleCommand(const commandStruct& commands) {
	const char** argv = commands.argVector;
	const int argc = commands.argCounter;

	if (argc == 2) {
		if (strcmp(argv[1], "--help") == 0) {
			std::unique_ptr<helpCommand> command = std::make_unique<helpCommand>();
			return command;

		} else if(strcmp(argv[1], "--version") == 0) {
			std::unique_ptr<versionCommand> command = std::make_unique<versionCommand>();
			return command;

		} else {
			misUse(commands);
			return nullptr;

		}
	} else if (argc == 4) {
		if(strcmp(argv[1], "--generate") == 0) {
			passwordCommandParams params;
			params.mode = argv[2];
			params.length = std::stoi(argv[3], nullptr, 10);

			std::unique_ptr<passwordCommand> command = std::make_unique<passwordCommand>();
			command->getParams(params);
			command->exec();
			return command;

		} else {
			misUse(commands);
			return nullptr;

		}
	} else {
		misUse(commands);
		return nullptr;

	}

}
