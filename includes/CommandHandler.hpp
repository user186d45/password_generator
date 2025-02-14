#pragma once

#include "../build/default/version.h"
#include "./passGen.hpp"

#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

#include <memory>

class Command {
public:
	virtual void exec() = 0;
	virtual ~Command() = default;
};

class helpCommand : public Command {
public:

	helpCommand() = default;
	virtual ~helpCommand() = default;

	void exec() override;
};

class versionCommand: public Command {
public:

	versionCommand() = default;
	virtual ~versionCommand() = default;

	void exec() override;
};

struct passwordCommandParams {
	const char* mode;
	int length;

};

class passwordCommand : public Command {
public:

	passwordCommand() = default;
	virtual ~passwordCommand() = default;

	void exec() override;

	void getParams(passwordCommandParams& params);

private:
	passwordCommandParams iparams; // internal params
};


struct commandStruct {
	const char** argVector = nullptr;
	int argCounter = 0;
};


class commandHandler {
public:
	std::unique_ptr<Command> handleCommand(const commandStruct& commands);

private:
	void misUse(const commandStruct& commands);
};


#endif
