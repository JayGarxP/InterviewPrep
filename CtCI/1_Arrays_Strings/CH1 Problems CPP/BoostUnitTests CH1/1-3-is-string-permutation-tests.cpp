#include <boost/test/unit_test.hpp> // precompiled

// project being tested
#include "../CH1 Problems CPP/pch.h"
// TODO: Is linking to .cpp instead of .hpp an anti-pattern of Boost-test unit testing? Get linker errors if I just use .hpp?
#include "../CH1 Problems CPP/1-3-is-string-permutation.cpp"
#include <string>

BOOST_AUTO_TEST_CASE(test_1_3_permutation)
{
	string source = "paperclip";

	string permutation = "ppplierac";
	string permutationRip = "rppplieca";
	string permutationApr = "ilcppreap";

	string evilShort = "paper";
	string evilMsn = "ppxlierac";
	string evilDupe = "paierclip";


	BOOST_TEST(arePermutations(source, permutation));
	BOOST_TEST(arePermutations(source, permutationRip));
	BOOST_TEST(arePermutations(source, permutationApr));

	BOOST_TEST(arePermutations(source, evilShort) == false);
	BOOST_TEST(arePermutations(source, evilMsn) == false);
	BOOST_TEST(arePermutations(source, evilDupe) == false);
}