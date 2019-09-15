#include "block_downsampling.hpp"
#include "print_image_to_console.hpp"
#include "command_line_processing.hpp"
#include <deque>
#include <thread>
#include <unordered_map>
//#define DEBUG //uncomment for extra console output

boost::multi_array<uint32_t, 2> DownsampleMultArrayBlocks (boost::multi_array_ref<uint32_t, 2> array_to_ds, int rows, int cols, int l_downsampling)
{

    // image 'blocks' are always square and always powers of two
    int blockHeight = BaseTwoExponentiation(l_downsampling);
    int blockWidth = blockHeight;

    // blocks per image
    int numBlocks = (rows * cols) / (blockHeight * blockWidth);

    // The output image will be the mode of each block in same (0,0) origin row major order
    //      e.g. start in upper left corner, then go right until edge, then go down repeat,
    //           like reading a book.
    int outputRows = rows / blockHeight;
    int outputCols = cols / blockWidth;

    boost::multi_array<uint32_t, 2> outputArray{boost::extents[outputRows][outputCols]};

    // Create a deque to hold each blocks mode in order
    std::deque<uint32_t> modes = {};

    int rowIndexOffset = 0;
    int colIndexOffset = 0;
    int outputArrayIndex = 0;
    for (int blockCount = 1; blockCount < numBlocks+1; ++blockCount)
    {

#ifdef DEBUG
        std::cout <<"\nOn block: " << blockCount << std::endl;
#endif

// Insert all elements in unordered_map hash.
        std::unordered_map<int, uint32_t> hash;


        for (int i = 0; i < blockHeight; ++i)
        {

#ifdef DEBUG
            std::cout << std::endl;
#endif
            for (int j = 0; j < blockWidth; ++j)
            {
//                int rowIndex = i + (blockCount / blockWidth);
//                int colIndex = j + (blockCount * blockWidth);
                int rowIndex = i + rowIndexOffset;
                int colIndex = j + colIndexOffset;

#ifdef DEBUG
                std::cout << array_to_ds[rowIndex][colIndex];

                if(array_to_ds[rowIndex][colIndex] < 10)
                {
                    std::cout << "  ";
                }
                else
                {
                    std::cout << ' ';
                }
#endif

                // put value into hash??? count up collisions
                hash[array_to_ds[rowIndex][colIndex]]++;

            }

        }

        // https://www.geeksforgeeks.org/frequent-element-array/
        // find the max frequency
        uint32_t max_count = 0;
        uint32_t res = -1;
        for (auto i : hash)
        {
            if (max_count < i.second)
            {
                res = i.first;
                max_count = i.second;
            }
        }


#ifdef DEBUG
        std::cout << "\nMODE: " << res << std::endl;
#endif


        // store mode of block into modes deque
        modes.push_back(res);

        // calculate offsets for next block
        if(blockCount == (cols / blockWidth))
        {
            rowIndexOffset += blockHeight;
        }

        colIndexOffset += blockWidth;
        // reset column index offset if at right edge
        if(colIndexOffset == cols)
        {
            colIndexOffset = 0;
        }


    }

#ifdef DEBUG
    std::cout << std::endl;
#endif


    // assign mode to output array pixel representation of block
    // load outputArray up with mode deque values
    for(int i = 0; i < outputRows; ++i)
        for(int j = 0; j < outputCols; ++j)
        {
            outputArray[i][j] = modes.front();
            modes.pop_front();
        }

//std::cout << "l_downsampling: " << l_downsampling << std::endl;
// writing to console output at same time as other thread can ruin this output
    PrintMultiArray(outputArray, outputRows, outputCols);
    return outputArray;

}


void OutputAllDownsamplings (boost::multi_array_ref<uint32_t, 2> array_to_ds, int rows, int cols, int l_d_max)
{
    // Process each downsampled image as own thread, storing them in array for now.
    std::thread downsampleThreads[l_d_max];

    // Start thread for each downsampled image
    for(int i = 0; i < l_d_max; i++)
    {
        downsampleThreads[i] = std::thread(DownsampleMultArrayBlocks, array_to_ds, rows, cols, i+1);
    }

    // After starting/creating image threads, join/wait for them in separate loop after,
    //      this seems justifiable since the order doesn't matter and presumably
    //       all downsampled images must be created before use in the "Brain-Chamber"
    for(int i = 0; i < l_d_max; i++)
    {
        // might check thread ids and/or joinable() here later
        downsampleThreads[i].join();
        // https://thispointer.com/c11-multithreading-part-8-stdfuture-stdpromise-and-returning-values-from-thread/
        // should capture return values with future and promise as well.
    }

}
