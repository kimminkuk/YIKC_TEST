#include "YIKC_TEST_3.h"

#define BIT_FAIL(TEST_BIT, j, z) ((*(TEST_BIT + j) >> (z)) & 1)

void YIKC_TEST_3::YIELD()
{
	float yield_result = 0;

    unsigned int TEST_BIT[3][4] = {
        {0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF},
        {0x10000001, 0xC000C000, 0xAAAAAAAA, 0xFFFFFFFF}
    };

    int fail_memory = 0;

    for (int i = 0; i < TEST_INPUT; i++)
    {
        for (int j = 0; j < TEST_DUTNUM; j++)
        {
            for (int z = 0; z < 32; z++)
            {
                if (BIT_FAIL(TEST_BIT[i], j, z)) fail_memory++;
            }
        }
        printf("%08X %08X %08X %08X fail = %d, yield = %.1f%\n",
            TEST_BIT[i][0], TEST_BIT[i][1], TEST_BIT[i][2], TEST_BIT[i][3],
            fail_memory, 100 - ((float)fail_memory / DUT * 100)
        );
        fail_memory = 0;
    }
	
	return;
}