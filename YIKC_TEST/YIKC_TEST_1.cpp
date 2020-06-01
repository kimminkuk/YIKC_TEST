#include "YIKC_TEST_1.h"

YIKC_TEST_1::YIKC_TEST_1()
{
	err = 0x12345678;
	N = 0;
	M = 0;
	virus_num = 0;
	spread_right = 0;
	spread_bottom = 0;
	spread_left = 0;
	spread_top = 0;
	spread_end = 1;
	MAP_RESULT = 0;
	T1_R, T1_C, T2_R, T2_C = 0;
	
	for (int i = 0; i < tower_count; i++) {
		tower[i] = { 0 };
	}
}

void YIKC_TEST_1::YIKC1_SETERROR()
{
	printf("errcode:%08X\n",err);
	printf("TEST FAIL ERROR\n");
	return;
}

int YIKC_TEST_1::MAP(const int COL, const int ROW)
{
	if (COL < 3 || ROW > 8) 
	{
		YIKC1_SETERROR();
		return err;
	}
	N = COL;
	M = ROW;
	virus = new int* [N]();
	virus_pt = new int* [N]();
	lab = new int* [N]();
	lab_tower = new int* [N]();
	def_tower = new int* [N]();
	spread_finish = new int* [N]();
	input_data = new int* [N]();

	for (int i = 0; i < N; i++)
	{
		virus[i] = new int[M]();
		virus_pt[i] = new int[M]();
		lab[i] = new int[M]();
		lab_tower[i] = new int[M]();
		def_tower[i] = new int[M]();
		spread_finish[i] = new int[M]();
		input_data[i] = new int[M]();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%d", &input_data[i][j]);
			if (input_data[i][j] == 2) virus_num++;
			if (input_data[i][j] < 0 || input_data[i][j] > 2)
			{
				YIKC1_SETERROR();
				return err;
			}
		}
	}

	if (virus_num < 2 || virus_num > 10)
	{
		YIKC1_SETERROR();
		return err;
	}

//case1
// virus[0][0] = 2;
// virus[1][5] = 2;
// lab_tower[0][4] = 1;
// lab_tower[0][5] = 1;
// lab_tower[1][2] = 1;
// lab_tower[1][4] = 1;
// lab_tower[2][1] = 1;
// lab_tower[2][2] = 1;
// lab_tower[2][4] = 1;
// lab_tower[3][1] = 1;
// lab_tower[4][5] = 1;
// lab_tower[4][6] = 1;
// lab_tower[5][1] = 1;
// lab_tower[6][1] = 1;

//case2
//CASE2	virus[1][5] = 2;
//CASE2	virus[2][5] = 2;
//CASE2	virus[3][5] = 2;
//CASE2	lab_tower[1][0] = 1;
//CASE2	lab_tower[2][0] = 1;
//CASE2	lab_tower[2][1] = 1;
//CASE2	lab_tower[2][2] = 1;
 
//	//case 3
//	virus[0][0] = 2;
//	virus[0][7] = 2;
//	virus[1][0] = 2;
//	virus[1][7] = 2;
//	virus[2][0] = 2;
//	virus[2][7] = 2;
//	virus[3][0] = 2;
//	virus[3][7] = 2;
//	virus[4][0] = 2;
//	virus[4][7] = 2;
	
	AREA();
	MAP_RESULT = AREA_TOWER();
		
    return MAP_RESULT;
}

int YIKC_TEST_1::AREA()
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{

			if (input_data[i][j] == 2) 
			{
				lab[i][j] = 2;
				virus[i][j] = 2;
			}
			else if (input_data[i][j] == 1)
			{
				lab[i][j] = 1;
			}
			else
			{
				lab[i][j] = 0;
			}
		}
	}



	return 0;
}

int YIKC_TEST_1::AREA_TOWER()
{
	int def_wall_cnt_3 = 1;
	int cc = 0;

#if 1
	int loop = 0;
	SAFE_RESULT = new int[(N * M)*(N*M)*(N*M)]();
	
	for (int cnt = 0; cnt < N * M; cnt++) 
	{
		T1_C = cnt / M;
		T1_R = cnt % M;
		if (lab[T1_C][T1_R] == 0)
		{
			lab[T1_C][T1_R] = 1; //tower 1 on
			for (int cnt2 = 0; cnt2 < N * M; cnt2++)
			{
				T2_C = cnt2 / M;
				T2_R = cnt2 % M;
				if (lab[T2_C][T2_R] == 0)
				{
					lab[T2_C][T2_R] = 1; //tower2 on
					for (int i = 0; i < N; i++)
					{
						for (int j = 0; j < M; j++)
						{
							if (lab[i][j] == 0 && def_wall_cnt_3 == 1)
							{
								def_wall_cnt_3=0;
								lab[i][j] = 1;

								if (def_wall_cnt_3 == 0)
								{
									loop++;
									SAFE_RESULT[cc] = AREA_VIRUS();
									cc++;
									def_wall_cnt_3 = 1;
									lab[i][j] = 0;
									AREA_INIT();
								}
							}
						}
					}

					lab[T2_C][T2_R] = 0; //tower2 off
				}
			}

			lab[T1_C][T1_R] = 0; //tower 1 off
		}
	}

	int small = 0;
	for (int i = 0; i < (N * M)*(N*M)*(N*M); i++) 
	{	
		if ((small < SAFE_RESULT[i]) && (SAFE_RESULT[i] < N*M)) 
		{
			small = SAFE_RESULT[i];
		}
	}
#endif
	return small;
}

void YIKC_TEST_1::AREA_INIT()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (input_data[i][j] == 2)
			{
				lab[i][j] = 2;
				virus[i][j] = 2;
			}
			else if (input_data[i][j] == 1)
			{
				lab[i][j] = 1;
			}
			else
			{
				lab[i][j] = 0;
			}
		}
	}
	lab[T1_C][T1_R] = 1;
	lab[T2_C][T2_R] = 1;

	//CASE 2
//    lab[1][5] = 2;
//    lab[2][5] = 2;
//    lab[3][5] = 2;
//    lab[1][0] = 1;
//    lab[2][0] = 1;
//    lab[2][1] = 1;
//    lab[2][2] = 1;

//CASE1
//	lab[0][0] = 2;
//	lab[1][5] = 2;
//	lab[0][4] = 1;
//	lab[0][5] = 1;
//	lab[1][2] = 1;
//	lab[1][4] = 1;
//	lab[2][1] = 1;
//	lab[2][2] = 1;
//	lab[2][4] = 1;
//	lab[3][1] = 1;
//	lab[4][5] = 1;
//	lab[4][6] = 1;
//	lab[5][1] = 1;
//	lab[6][1] = 1;

//	//CASE3
//	lab[0][0] = 2;
//	lab[0][7] = 2;
//	lab[1][0] = 2;
//	lab[1][7] = 2;
//	lab[2][0] = 2;
//	lab[2][7] = 2;
//	lab[3][0] = 2;
//	lab[3][7] = 2;
//	lab[4][0] = 2;
//	lab[4][7] = 2;

}

int YIKC_TEST_1::AREA_VIRUS()
{
	int ACTION = 0;
	spread_end = 1;
		while (spread_end) 
		{
			ACTION = 1;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					spread_finish[i][j] = 0;
				}
			}

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					spread_right = 0;
					spread_top = 0;
					spread_left = 0;
					spread_bottom = 0;

					if (lab[i][j] == 2)
					{
						//virus spread
						//1) 0,0
						spread_end = 0;
						spread_right++;
						spread_top--;
						spread_left--;
						spread_bottom++;
						if (M > j + spread_right)
						{
							if (lab[i][j + spread_right] == 1)
							{
								spread_right--;
							}
							else if (lab[i][j + spread_right] == 2)
							{

							}
							else
							{
								virus[i][j + spread_right] = 2;
								lab[i][j + spread_right] = 2;
								spread_end = 1;
								spread_finish[i][j + spread_right] = 1;
							}
						}

						if (0 <= i + spread_top)
						{
							if (lab[i + spread_top][j] == 1)
							{
								spread_top++;
							}
							else if (lab[i + spread_top][j] == 2)
							{

							}
							else
							{
								virus[i + spread_top][j] = 2;
								lab[i + spread_top][j] = 2;
								spread_end = 1;
								spread_finish[i + spread_top][j] = 1;
							}
						}

						if (0 <= j + spread_left)
						{
							if (lab[i][j + spread_left] == 1)
							{
								spread_left++;
							}
							else if (lab[i][j + spread_left] == 2)
							{
							}
							else
							{
								virus[i][j + spread_left] = 2;
								lab[i][j + spread_left] = 2;
								spread_end = 1;
								spread_finish[i][j + spread_left] = 1;
							}
						}

						if (N > i + spread_bottom)
						{
							if (lab[i + spread_bottom][j] == 1)
							{
								spread_bottom--;
							}
							else if (lab[i + spread_bottom][j] == 2)
							{
								spread_finish[i + spread_bottom][j] = 0;
							}
							else
							{
								virus[i + spread_bottom][j] = 2;
								lab[i + spread_bottom][j] = 2;
								spread_end = 1;
								spread_finish[i + spread_bottom][j] = 1;
							}
						}               	
					}
				}
			}

			for (int i = N-1; i > 0; i--)
			{
				for (int j = M-1; j > 0; j--)
				{
					spread_right = 0;
					spread_top = 0;
					spread_left = 0;
					spread_bottom = 0;

					if (lab[i][j] == 2)
					{
						//virus spread
						//1) 0,0
						spread_end = 0;
						spread_right++;
						spread_top--;
						spread_left--;
						spread_bottom++;
						if (M > j + spread_right)
						{
							if (lab[i][j + spread_right] == 1)
							{
								spread_right--;
							}
							else if (lab[i][j + spread_right] == 2)
							{

							}
							else
							{
								virus[i][j + spread_right] = 2;
								lab[i][j + spread_right] = 2;
								spread_end = 1;
								spread_finish[i][j + spread_right] = 1;
							}
						}

						if (0 <= i + spread_top)
						{
							if (lab[i + spread_top][j] == 1)
							{
								spread_top++;
							}
							else if (lab[i + spread_top][j] == 2)
							{

							}
							else
							{
								virus[i + spread_top][j] = 2;
								lab[i + spread_top][j] = 2;
								spread_end = 1;
								spread_finish[i + spread_top][j] = 1;
							}
						}

						if (0 <= j + spread_left)
						{
							if (lab[i][j + spread_left] == 1)
							{
								spread_left++;
							}
							else if (lab[i][j + spread_left] == 2)
							{
							}
							else
							{
								virus[i][j + spread_left] = 2;
								lab[i][j + spread_left] = 2;
								spread_end = 1;
								spread_finish[i][j + spread_left] = 1;
							}
						}
					
						if (N > i + spread_bottom)
						{
							if (lab[i + spread_bottom][j] == 1)
							{
								spread_bottom--;
							}
							else if (lab[i + spread_bottom][j] == 2)
							{
								spread_finish[i + spread_bottom][j] = 0;
							}
							else
							{
								virus[i + spread_bottom][j] = 2;
								lab[i + spread_bottom][j] = 2;
								spread_end = 1;
								spread_finish[i + spread_bottom][j] = 1;
							}
						}
					}
				}
			}

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					
					if (spread_finish[i][j] == 1) 
					{
						spread_end = 1;
					}
				}
			}
		}

	//Safe Area
    MAP_RESULT = 0;
	if (ACTION == 1) 
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (lab[i][j] == 0)
				{
					MAP_RESULT++;
				}
			}
		}
	}

	return MAP_RESULT;
}
