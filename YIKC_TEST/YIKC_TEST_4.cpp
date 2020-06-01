#include "YIKC_TEST_4.h"

#define SHMOO_FAIL(_DATA,i,t) ( ( *(_DATA+t) >> (i)) & 1 )

void YIKC_TEST_4::SHMOO()
{
	unsigned int _DATA[9] = 
	{ 
		0xFFFFFFFF, 0xFFFFFFFF, 0xFFF00007, 0xFFC00007,
	    0xFF800003, 0xFFE00001, 0xFFE0000F, 0xFFFF81FF, 0xFFFFFFFF
	};
	char SHMOO_FAIL_PASS[9][64] = { '0' };

	for (int t = 0; t < timing_range; t++) {
		for (int i = 0; i < 32; i++) {
			if (SHMOO_FAIL(_DATA, i, t)) SHMOO_FAIL_PASS[t][i] = 'F';
			else SHMOO_FAIL_PASS[t][i] = '.';
		}
		printf("%dns %08X : %s \n", timing_start + t, _DATA[t], *(SHMOO_FAIL_PASS + t));
	}
	return;

}