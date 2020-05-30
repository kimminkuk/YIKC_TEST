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

void YIKC_TEST_2::space__()
{
	while ((*G_ptr == 32))
	{
		G_ptr++;
	}
}

double YIKC_TEST_2::exp__()
{

	double term_ = term__();

	space__();

	while ((*G_ptr == '+') || (*G_ptr == '-'))
	{
		if (*G_ptr == '+') 
		{
			G_ptr++;
			term_ = term_ + term__();
		}
		else if (*G_ptr == '-')
		{
			G_ptr++;
			term_ = term_ - term__();
		}
	}
	return term_;
}

double YIKC_TEST_2::term__()
{
	double factor_ = factor__();

	space__();

	while ((*G_ptr == '*') || (*G_ptr == '/'))
	{
		if (*G_ptr == '*')
		{
			G_ptr++;
			factor_ = factor_ * term__();
		}
		else if (*G_ptr == '/')
		{
			G_ptr++;
			factor_ = factor_ / term__();
		}
	}
	return factor_;
}

double YIKC_TEST_2::factor__()
{
	double number_ = number__();	
	space__();
	if (G_index > 0) 
	{
		number_ = number_ / pow(10,G_index);
	}
	if (*G_ptr == '(') 
	{
		G_ptr++;
		number_ = exp__();
		if (*G_ptr == ')')
		{
			G_ptr++;
			return number_;
		}
	}
	else if ( (*G_ptr >= '0') && (*G_ptr <= '9') ) 
	{
		while(1)
		{
			if ((*G_ptr >= '0') && (*G_ptr <= '9'))
			{
				number_ = number_ * 10;
				number_ = number_ + (*G_ptr - '0');
				G_ptr++;
			}
			else break;
		}
		return number_;
	}

	return number_;
}

double YIKC_TEST_2::number__()
{
	double digit_ = digit__();
	space__();
	G_index = 0;
	if ( (*G_ptr == '.') )
	{
		G_ptr++;
		while (1)
		{
			if ((*G_ptr >= '0') && (*G_ptr <= '9'))
			{
				digit_ = digit_ * 10;
				digit_ = digit_ + (*G_ptr - '0');
				G_ptr++;
				G_index++;
			}
			else break;
		}
	}
	return digit_;
}

double YIKC_TEST_2::digit__()
{
	int digit = 0;
	space__();

	while (1)
	{
		if ((*G_ptr >= '0') && (*G_ptr <= '9'))
		{
			digit = digit * 10;
			digit = digit + (*G_ptr - '0');
			G_ptr++;
		}
		else break;
	}
	
	return digit;
}

double YIKC_TEST_2::TG__(const char* str_TG)
{
	//position
	G_ptr = str_TG;
	space__();
	TG_result = exp__();
	
	return TG_result;
}

double YIKC_TEST_2::SETERROR()
{
	printf("end");
	return 0;
}

YIKC_TEST_2::YIKC_TEST_2()
{
	G_index = 0;
	G_ptr = NULL;
	TG_result = 0;
}
