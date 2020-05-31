#include "YIKC_TEST_1.h"

YIKC_TEST_1::YIKC_TEST_1()
{
	err = 0x12345678;
	N = 0;
	M = 0;
	virus_num = 2;
	spread_right = 0;
	spread_bottom = 0;
	spread_left = 0;
	spread_top = 0;
	spread_end = 1;
	MAP_RESULT = 0;

	for (int i = 0; i < tower_count; i++) {
		tower[i] = { 0 };
	}
}

void YIKC_TEST_1::YIKC1_SETERROR()
{
	printf("errcode:%08X\n",err);
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

	for (int i = 0; i < N; i++)
	{
		virus[i] = new int[M]();
		virus_pt[i] = new int[M]();
		lab[i] = new int[M]();
		lab_tower[i] = new int[M]();
		def_tower[i] = new int[M]();
		spread_finish[i] = new int[M]();
	}

//case1
//virus[0][0] = 2;
//virus[1][5] = 2;
//lab_tower[0][4] = 1;
//lab_tower[0][5] = 1;
//lab_tower[1][2] = 1;
//lab_tower[1][4] = 1;
//lab_tower[2][1] = 1;
//lab_tower[2][2] = 1;
//lab_tower[2][4] = 1;
//lab_tower[3][1] = 1;
//lab_tower[4][5] = 1;
//lab_tower[4][6] = 1;
//lab_tower[5][1] = 1;
//lab_tower[6][1] = 1;

//case2
	virus[1][5] = 2;
	virus[2][5] = 2;
	virus[3][5] = 2;
	lab_tower[1][0] = 1;
	lab_tower[2][0] = 1;
	lab_tower[2][1] = 1;
	lab_tower[2][2] = 1;
 
	//case 3
//case3	virus[0][0] = 2;
//case3	virus[0][7] = 2;
//case3	virus[1][0] = 2;
//case3	virus[1][7] = 2;
//case3	virus[2][0] = 2;
//case3	virus[2][7] = 2;
//case3	virus[3][0] = 2;
//case3	virus[3][7] = 2;
//case3	virus[4][0] = 2;
//case3	virus[4][7] = 2;
	
	//case4
//	virus[0][2] = 1;

	AREA();
	MAP_RESULT = AREA_TOWER();
//	AREA_VIRUS();
		
    return MAP_RESULT;
}

int YIKC_TEST_1::AREA()
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			if (virus[i][j] == 2) 
			{
				lab[i][j] = 2;
//				printf("%d ", virus[i][j]);
			}
			else if (lab_tower[i][j] == 1)
			{
				lab[i][j] = 1;
//				printf("%d ", lab_tower[i][j]);
			}
			else if (def_tower[i][j] == 1) 
			{
				lab[i][j] = 1;
//				printf("%d ", def_tower[i][j]);
			}
			else
			{
//				printf("%d ", lab[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}

int YIKC_TEST_1::AREA_TOWER()
{
//case1	def_tower[0][1] = 1;
//case1	def_tower[1][0] = 1;
//case1	def_tower[3][5] = 1;
//case1	lab[0][1] = 1;
//case1	lab[1][0] = 1;
//case1	lab[3][5] = 1;

	//case 2
//case2	def_tower[0][4] = 1;
//case2	def_tower[1][3] = 1;
//case2	def_tower[3][3] = 1;
//	lab[0][4] = 1;
//	lab[1][3] = 1;
//	lab[3][3] = 1;

	//case3
//case3	def_tower[5][0] = 1;
//case3	def_tower[6][1] = 1;
//case3	def_tower[7][2] = 1;
//case3	lab[5][0] = 1;
//case3	lab[6][1] = 1;
//case3	lab[7][2] = 1;

	int def_wall_cnt_1 = 1;
	int def_wall_cnt_2 = 1;
	int def_wall_cnt_3 = 1;

	int cc = 0;

#if 0
	for (int i = 0; i < 3; i++) 
	{
		for (int i = 0; i < N * M; i++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (lab[i][j] == 0 && def_wall_cnt > 0)
					{
						def_wall_cnt--;
						lab[i][j] = 1;
					}
					if (def_wall_cnt == 0)
					{
						AREA();
						def_wall_cnt = 3;
					}
				}
			}
		}
	}
#endif

	//lab[cnt/N][cnt] = 1;
	SAFE_RESULT = new int[(N * M)*(N*M)*(N*M)]();

	for (int cnt = 0; cnt < N * M; cnt++) 
	{
		if (lab[cnt / M][cnt % M] == 0) 
		{
			lab[cnt / M][cnt % M] = 1; //tower 1 on
			for (int cnt2 = 0; cnt2 < N * M; cnt2++)
			{
				if (lab[cnt2 / M][cnt2 % M] == 0)
				{
					lab[cnt2 / M][cnt2 % M] = 1; //tower2 on
					for (int i = 0; i < N; i++)
					{
						for (int j = 0; j < M; j++)
						{
							if (lab[i][j] == 0 && def_wall_cnt_3 > 0)
							{
								def_wall_cnt_3--;
								lab[i][j] = 1;

								if (def_wall_cnt_3 == 0)
								{
									SAFE_RESULT[cc] = AREA_VIRUS();
									cc++;
									def_wall_cnt_3 = 1;
									lab[i][j] = 0;
									//AREA_INIT();

									for (int i = 0; i < N; i++)
									{
										for (int j = 0; j < M; j++)
										{
											if(lab[i][j] == 0) lab[i][j] = 0;
										}
									}
									//CASE 2 
									lab[1][5] = 2;
									lab[2][5] = 2;
									lab[3][5] = 2;
									lab[1][0] = 1;
									lab[2][0] = 1;
									lab[2][1] = 1;
									lab[2][2] = 1;
									
								}
							}
						}
					}

					lab[cnt2 / M][cnt2 % M] = 0; //tower2 off
				}
			}

			lab[cnt / M][cnt % M] = 0; //tower 1 off
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
	printf("\nDefensive Wall\n\n\n");
//    AREA();
	return small;
}

void YIKC_TEST_1::AREA_INIT()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			lab[i][j] = 0;
		}
	}
	//CASE 2 
	lab[1][5] = 2;
	lab[2][5] = 2;
	lab[3][5] = 2;
	lab[1][0] = 1;
	lab[2][0] = 1;
	lab[2][1] = 1;
	lab[2][2] = 1;
}

int YIKC_TEST_1::AREA_VIRUS()
{
	printf("\nVirus Spread\n\n\n");
	
	int aa = 4;
		while (spread_end) 
		{
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
						//else spread_finish[i][j] = 0;

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
						//else spread_finish[i][j] = 0;

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
						//else spread_finish[i][j] = 0;

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
						//else spread_finish[i][j] = 0;                      	
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
						//else spread_finish[i][j] = 0;

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
						//else spread_finish[i][j] = 0;

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
						//else spread_finish[i][j] = 0;

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
						//else spread_finish[i][j] = 0;
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
#if 0
			for (int j = 0; j < M; j++)
			{
				for (int i = 0; i < N; i++)
				{
					spread_right = 0;
					spread_top = 0;
					spread_left = 0;
					spread_bottom = 0;

					if (virus[i][j] == 2)
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
							}
						}
						//else spread_finish[i][j] = 0;

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
							}
						}
						//else spread_finish[i][j] = 0;

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
							}
						}
						//else spread_finish[i][j] = 0;

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
							}
						}
						//else spread_finish[i][j] = 0;                      	
					}
				}
			}

			for (int i = N-1; i > 0; i--)
			{
				for (int j = 0; j < M; j++)
				{
					spread_right = 0;
					spread_top = 0;
					spread_left = 0;
					spread_bottom = 0;

					if (virus[i][j] == 2)
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
							}
						}
						//else spread_finish[i][j] = 0;

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
							}
						}
						//else spread_finish[i][j] = 0;

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
							}
						}
						//else spread_finish[i][j] = 0;

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
							}
						}
						//else spread_finish[i][j] = 0;                      	
					}
				}
			}
#endif

    MAP_RESULT = 0;
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

	return MAP_RESULT;
}
