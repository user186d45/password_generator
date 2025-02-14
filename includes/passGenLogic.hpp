#ifndef PASSGEN_LOGIC_HPP
#define PASSGEN_LOGIC_HPP

class passGenHelper {
public:
	void genLogic(char* cBuffer, int (*errHandle)(char*), char* index, int percent, int length);
};

#endif
