// YIKC_TEST.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "YIKC_TEST.h"
#include "YIKC_0521.cpp"
#include "YIKC_TEST_1.h"
#include "YIKC_TEST_2.h"

// :=   좌변은 우변에 의해 정의됨
//왼쪽은 OBJECT
//오른쪽은 정의를 표현

//1.eㅈvaluation := exp (eㅈ...실행)
//2. exp := term에서 +,- 를 한다.
//3. term := factor에서 *,-를한다. 
//4. factor := exp를 number로 나눈다.
//5. number := digit으로 숫자를 만들다. 
//6. digit = 숫자



int main()
{
	YIKC_TEST_1 TEST1;
	int N, M = 0;
	printf("세로, 가로 입력\n");
	scanf_s("%d %d,", &N, &M);
	int safe_area = TEST1.MAP(N, M);

	printf("안전 영역:%d\n", safe_area);

#if false
	YIKC_TEST_2 TEST2;
	double result[4] = { 0 };
	result[0] = TEST2.TG__("2+3*4");
	result[1] = TEST2.TG__("2*(3+4)");
	result[2] = TEST2.TG__("1.0/0.5");
	result[3] = TEST2.TG__("345/12");
	
	printf("1 %f\n", result[0]);
	printf("2 %f\n", result[1]);
	printf("3 %f\n", result[2]);
	printf("4 %f\n", result[3]);
#endif
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
