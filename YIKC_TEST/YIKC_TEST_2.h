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
	double SETERROR();

	double TG__(const char* str_TG);
	double exp__();
	double term__();
	double factor__();
	double number__();
	double digit__();

	double G_index;
	double TG_result;
	const char* G_ptr;
};

