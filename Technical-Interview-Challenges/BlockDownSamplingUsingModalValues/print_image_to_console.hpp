
// Print the multi-arrays that represent the image and its downsampling
#include <iostream>
#include "boost/multi_array.hpp"
void PrintMultiArray (boost::multi_array_ref<uint32_t, 2> array_to_print, int rows, int cols);

void PrintMultArrayBlocks (boost::multi_array_ref<uint32_t, 2> array_to_print, int rows, int cols);
