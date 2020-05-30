#pragma once
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;
// 1.eㅈvaluation : = exp(eㅈ...실행)
//2. exp := term에서 +,- 를 한다.
//3. term := factor에서 *,-를한다. 
//4. factor := exp를 number로 나눈다.
//5. number := digit으로 숫자를 만들다. 
//6. digit = 숫자

//e ㅈ valuation := exp 
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

