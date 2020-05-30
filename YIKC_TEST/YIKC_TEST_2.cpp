#include "YIKC_TEST_2.h"
//using namespace std;
// 1.e��valuation : = exp(e��...����)
//2. exp := term���� +,- �� �Ѵ�.
//3. term := factor���� *,-���Ѵ�. 
//4. factor := exp�� number�� ������.
//5. number := digit���� ���ڸ� �����. 
//6. digit = ����

//[]�� �������� �ɼ��� �ǹ��մϴ�.
//() ���
//�������� �ɼ� �� �ݵ�� �ϳ��� �����Ͽ��� �� �� ����մϴ�.
//{}�� 0�� �̻��� �ݺ��� �ǹ��մϴ�.

//e �� valuation := exp 
//exp := term [ [ '+' | '-' ] term ] 
//term := factor [ [ '* ' | '/' ] factor ] 
//factor = '(' exp ')' | number 
//number : = digit+ [ '.' digit+ ] 
//digit := '0'..'9' 
//2+3*4=14.0000

/*
3 02. �ζ��� �Ľ����� ���� �����

Ÿ�̹� ���׷������� �����Ϸ����� Ÿ�̹� ��꿡 �ζ��� ��� ����� �����ش޶��
������ ��û�� �־���.
Ÿ�̹� ���׷����ʹ� �ð� ���� ������ nano second���� milliseconds�� 
������ Ŀ�� �Ǽ� ������ ó���ؾ� �Ѵ�. 
������� ���ڿ��� �Է����� �޾� �װ���� ��ȯ�ϴ� ��ƾ�� �ۼ��Ͻÿ�.
������ EBNF ������ �Ʒ��� ����.

e �� valuation := exp 
exp := term [ [ '+' | '-' ] term ] 
term := factor [ [ '* ' | '/' ] factor ] 
factor = '(' exp ')' | number 
number : = digit+ [ '.' digit+ ] 
digit := '0'..'9'

  ���࿹��:   2+3*4 = 14.000000 
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
