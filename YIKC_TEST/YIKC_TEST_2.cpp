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
