#pragma once

#include "./CommandHandler.hpp"
#include <memory>

#ifndef PASSGEN_HPP
#define PASSGEN_HPP

struct passwordCommandParams;

class passGen {
public:
	virtual void generate() = 0;
	virtual ~passGen() = default;

	static int buffErrHandler(char* InBuff);

protected:
	const char* mode;
	int length;

	char* cBuffer = nullptr;
	char index[74] = {
	        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
	        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
	        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',
	        '3', '4', '5', '6', '7', '8', '9', '0', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
	        '-', '_'
	    };
};

class easyPass : public passGen {
public:
	void generate() override;
	void getParams(passwordCommandParams& params);
};

class normalPass: public passGen {
public:
	void generate() override;
	void getParams(passwordCommandParams& params);
};

class strongPass: public passGen {
public:
	void generate() override;
	void getParams(passwordCommandParams& params);
};

class passHandler {
public:
	std::unique_ptr<passGen> handler(passwordCommandParams& hParams);
};
#endif
