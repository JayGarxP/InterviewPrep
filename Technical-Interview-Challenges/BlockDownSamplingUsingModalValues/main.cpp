/* main.cpp
* Block Downsampling Using Modal Values
* Joseph 'JP' Fallon for Eyewire 4/16/2019
* Built in codeblocks using GCC installed from MinGW w/ Boost 1.69
* with these compiler flags:
     -std=c++17 -std=c++0x -pthread
*    EZ binary distro for windows: https://nuwen.net/mingw.html
*
* Hardcoded to show the first example in DownsamplingAssignmentRevised.pdf
*    being downsampled in two dimensions with each 'l' as own thread.
*/
#include "boost/multi_array.hpp"
#include "command_line_processing.hpp"
#include "print_image_to_console.hpp"
#include "block_downsampling.hpp"
#include <cassert>
#include <iostream>
#include <string>


int main()
{
	// hardcoded first example from DownsamplingAssignmentRevised.pdf
    // 'd' == 2; two dimensions
    //TODO: command line arguments for dimension sizes
    short lOne = 2;
    short lTwo = 3;
    // max number of 'l' downsamplings; set to smallest power of two dimension
    short maxlDownsamplings = (lOne < lTwo) ? lOne : lTwo;

    // Will make these a list in the future to support 'd' dimensions
    int L1 = BaseTwoExponentiation(lOne);
    int L2 = BaseTwoExponentiation(lTwo);

    //std::cout << L1; // try to read from text file the 'image' later...

     // multi_array_ref likes contiguous block of memory...
     uint32_t example_image_cont[32] =
	 {
	     1,1,1,1,1,1,1,1,
         1,2,1,2,1,2,1,2,
         1,1,2,2,2,2,2,2,
         1,2,2,2,2,2,2,2
     };


// Declare original image // 4row X 8col hardcoded right now
	boost::multi_array_ref<uint32_t, 2> Image_OG{example_image_cont, boost::extents[L1][L2]};

// print original image just to see what it looks like
std::cout << "Original Image: " << std::endl;
PrintMultiArray (Image_OG, L1, L2);
std::cout << "\n\nDownsamplings: " << std::endl;

// somehow separate them into correct views then hash to find mode, then recreate array from mode then print
//      probably way to use multi_array_ref to avoid making redundant copies as well.

// calculate and print all downsamplings
OutputAllDownsamplings(Image_OG, L1, L2, maxlDownsamplings);


	return 0;
}



