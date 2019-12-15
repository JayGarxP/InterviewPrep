#include <boost/test/unit_test.hpp> // precompiled

// project being tested
#include "../CH1 Problems CPP/pch.h"
//#include "../CH1 Problems CPP/1-2-reverse-c-string.h"
// using .cpp because of symbol lookup fail to get local char* off stack...
#include "../CH1 Problems CPP/1-2-reverse-c-string.cpp"
#include <string>

BOOST_AUTO_TEST_CASE(test_1_2_reverse)
{
	const char* labor = "Labor";
	
	const char* hmmm = reverse(labor);

	string hmmmString = hmmm;

	BOOST_TEST("robaL" == hmmmString);
}