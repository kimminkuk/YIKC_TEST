// YIKC_TEST.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "YIKC_TEST.h"
#include "YIKC_TEST_1.h"
#include "YIKC_TEST_2.h"
#include "YIKC_TEST_3.h"
#include "YIKC_TEST_4.h"

// :=   좌변은 우변에 의해 정의됨
//왼쪽은 OBJECT
//오른쪽은 정의를 표현

//1.eㅈvaluation := exp (eㅈ...실행)
//2. exp := term에서 +,- 를 한다.
//3. term := factor에서 *,-를한다. 
//4. factor := exp를 number로 나눈다.
//5. number := digit으로 숫자를 만들다. 
//6. digit = 숫자


void YIKC1()
{
	YIKC_TEST_1 TEST1;
	int N, M = 0;
	printf("\n문제 [1]\n");
	scanf_s("%d %d", &N, &M);
	printf("\n");
	uint32_t safe_area = TEST1.MAP(N, M);

	printf("\n\n안전 영역:%d\n", safe_area);
	printf("\nTEST1 END\n\n");
}

void YIKC2()
{
	printf("\n문제 [2]\n");
	printf("ex) 2+3*4\n연산 입력:");
	YIKC_TEST_2 TEST2;
	char input[100];	
	cin >> input;

	double result_ = TEST2.TG__(input);
	printf("\n%s = %f\n\n", input, result_);
	printf("\nTEST2 END\n\n");
}

void YIKC3()
{
	printf("\n문제 [3]\n");
	YIKC_TEST_3 TEST3;
	TEST3.YIELD();
	printf("\nTEST3 END\n\n");
}

void YIKC4()
{
	printf("\n문제 [4]\n");
	YIKC_TEST_4 TEST4;
	TEST4.SHMOO();
	printf("\nTEST4 END\n\n");
}

int main()
{
	int test_num = 0;
	printf("\n코딩 역량 평가 자료\n\n\n");
	do {
		printf("TEST1:[1] TEST2:[2] TEST3:[3] TEST4:[4] TESTEND:[5]\n\n");
		printf("TEST 문제 번호 선택--->");
		scanf_s("%d", &test_num);

		switch (test_num)
		{
		    case 1:
			    YIKC1();
				break;
			case 2:
				YIKC2();
				break;
			case 3:
				YIKC3();
				break;
			case 4:
				YIKC4();
				break;
			default:
				printf("YIKC TEST END\n");
				break;
		}

	} while (test_num <= 4 && test_num > 0);

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
