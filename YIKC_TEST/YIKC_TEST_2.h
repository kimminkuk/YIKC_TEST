#pragma once
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;
// 1.e��valuation : = exp(e��...����)
//2. exp := term���� +,- �� �Ѵ�.
//3. term := factor���� *,-���Ѵ�. 
//4. factor := exp�� number�� ������.
//5. number := digit���� ���ڸ� �����. 
//6. digit = ����

//e �� valuation := exp 
//exp := term [ [ '+' | '-' ] term ] 
//term := factor [ [ '* ' | '/' ] factor ] 
//factor = '(' exp ')' | number 
//number : = digit+ [ '.' digit+ ] 
//digit := '0'..'9' 

class YIKC_TEST_2
{

	
public:
	YIKC_TEST_2();
	double term(string str_term);
	double exp(string str_exp);
	double factor(string str_factor);
	double number(string str_number);
	double SETERROR();
	double TG(string str_TG);
	int digit(string str_digit);
};

