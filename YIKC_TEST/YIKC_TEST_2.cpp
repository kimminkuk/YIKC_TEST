#include "YIKC_TEST_2.h"
//using namespace std;
// 1.eㅈvaluation : = exp(eㅈ...실행)
//2. exp := term에서 +,- 를 한다.
//3. term := factor에서 *,-를한다. 
//4. factor := exp를 number로 나눈다.
//5. number := digit으로 숫자를 만들다. 
//6. digit = 숫자

//[]는 선택적인 옵션을 의미합니다.
//() 사용
//여러가지 옵션 중 반드시 하나를 선택하여야 할 때 사용합니다.
//{}는 0번 이상의 반복을 의미합니다.

//e ㅈ valuation := exp 
//exp := term [ [ '+' | '-' ] term ] 
//term := factor [ [ '* ' | '/' ] factor ] 
//factor = '(' exp ')' | number 
//number : = digit+ [ '.' digit+ ] 
//digit := '0'..'9' 
//2+3*4=14.0000

/*
3 02. 인라인 파싱으로 계산기 만들기

타이밍 제네레이터의 컴파일러에서 타이밍 계산에 인라인 계산 기능을 구현해달라는
고객사의 요청이 있었다.
타이밍 제네레이터는 시간 값의 범위가 nano second에서 milliseconds로 
범위가 커서 실수 연산을 처리해야 한다. 
연산식을 문자열로 입력으로 받아 그결과를 반환하는 루틴을 작성하시오.
계산기의 EBNF 형식은 아래와 같다.

e ㅈ valuation := exp 
exp := term [ [ '+' | '-' ] term ] 
term := factor [ [ '* ' | '/' ] factor ] 
factor = '(' exp ')' | number 
number : = digit+ [ '.' digit+ ] 
digit := '0'..'9'

  실행예제:   2+3*4 = 14.000000 
  2*(3+4) = 14.000000
  1.0/0.5 = 2.000000 
  345/12 = 28.750000
*/

const int err = 0x12345678;

double YIKC_TEST_2::exp(string str_exp)
{
	double term_= term(str_exp);
	
	if ('+') term_ = term_ + term(str_exp);
	else if ('-') term_ = term_ - term(str_exp);
	else return term_;
}

double YIKC_TEST_2::term(string str_term)
{
	double factor_ = factor(str_term);
	if ('*') factor_ = factor_ * factor(str_term);
	else if ('/') factor_ = factor_ / factor(str_term);
	else return factor_;
}

double YIKC_TEST_2::factor(string str_factor)
{
	double number_ = number(str_factor);

	return 0;
}

double YIKC_TEST_2::number(string str_nubmer)
{
	double num = digit(str_nubmer);

//	if (num >= 48 && num <= 57) num = atof(str_number.c_str());
	return 0;
}

int YIKC_TEST_2::digit(string str_digit)
{
	//int digit = 
	return 0;
}

double YIKC_TEST_2::TG(string str_TG)
{
	double get = str_TG[0];
	printf("str[0]:%f str[1]:%c str[2]:%c \n", get,str_TG[1],str_TG[2]);
	
	int len = str_TG.length();
	for (int i = 0; i < len; i++) {
		exp(str_TG.c_str());
	}
	
	printf("strlen:%d\n", len);
	return 0;
}

double YIKC_TEST_2::SETERROR()
{
	printf("end");
	return 0;
}

YIKC_TEST_2::YIKC_TEST_2()
{

}
