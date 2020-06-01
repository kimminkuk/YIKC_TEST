#pragma once

#include<stdio.h>
#include<stdint.h>

class YIKC_TEST_3
{
	const int TEST_INPUT = 3;
	const int TEST_DUTNUM = 4;
	const int DUT = 128;
	int fail_memory = 0;
	unsigned int TEST_BIT[3][4];

public:
	void YIELD();
};

