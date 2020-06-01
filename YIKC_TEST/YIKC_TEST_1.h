#pragma once
#include "YIKC_TEST.h"

class YIKC_TEST_1
{
public:
	YIKC_TEST_1();
	void YIKC1_SETERROR();
	int MAP(const int col, const int row);
	int AREA();
	int AREA_TOWER();
	int AREA_VIRUS();
	void AREA_INIT();

	uint32_t err;
	int N;
	int M;
	int tower[3];
	int tower_count = 3;
	int T1_C;
	int T1_R;
	int T2_C;
	int T2_R;

	int** input_data;
	int** virus;
	int** virus_pt;
	int** lab;
	int** lab_tower;
	int** def_tower;
	int virus_num;
	int spread_right;
	int spread_left;
	int spread_top;
	int spread_bottom;
	int spread_end;
	int** spread_finish;
	int MAP_RESULT = 0;
	int* SAFE_RESULT;
};

