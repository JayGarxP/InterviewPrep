#include "boost/multi_array.hpp"

/* DownsampleMultArrayBlocks
* array_to_ds is original image to downsample,
* rows are the North to South 'row major' of original image
* cols are the West to East columns of original image
* l_downsampling is which sub-l iteration of downsampling the original image will be downsampled into
// return downsampled image;
*/
boost::multi_array<uint32_t, 2> DownsampleMultArrayBlocks (boost::multi_array_ref<uint32_t, 2> array_to_ds, int rows, int cols, int l_downsampling);

void OutputAllDownsamplings (boost::multi_array_ref<uint32_t, 2> array_to_ds, int rows, int cols, int l_d_max);
