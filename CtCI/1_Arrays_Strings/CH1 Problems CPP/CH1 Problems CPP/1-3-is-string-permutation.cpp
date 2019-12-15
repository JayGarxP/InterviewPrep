#include "pch.h"
#include "1-3-is-string-permutation.hpp"
#include <algorithm> 
bool arePermutations(string left, string right) 
{
	// first blind pass on paper
	
	// need to be same length same cardinality to be permutations
	if (left.length() != right.length())
	{
		return false;
	}

	// use std::sort on std::string; then compare each element
	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	for (size_t i = 0; i < left.length(); i++)
	{
		if (left[i] != right[i])
		{
			return false;
		}
	}

	return true;

}