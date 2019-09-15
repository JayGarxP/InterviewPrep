#include "print_image_to_console.hpp"


void PrintMultiArray (boost::multi_array_ref<uint32_t, 2> array_to_print, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        std::cout << std::endl;
        for (int j = 0; j < cols; ++j)
        {
            if(array_to_print[i][j] < 10)
                {
                    std::cout << array_to_print[i][j] << "  ";
                }
                else
                {
                std::cout << array_to_print[i][j] << ' ';
                }
        }

    }

    std::cout << std::endl;
}

void PrintMultArrayBlocks (boost::multi_array_ref<uint32_t, 2> array_to_print, int rows, int cols)
{
    short blockHeight = 2;
    short blockWidth = 2;
    int numBlocks = (rows * cols) / (blockHeight * blockWidth);
    int rowIndexOffset = 0;
    int colIndexOffset = 0;

    for (int blockCount = 1; blockCount < numBlocks+1; ++blockCount)
    {
        std::cout <<"\nOn block: " << blockCount << std::endl;

        for (int i = 0; i < blockHeight; ++i)
        {
            std::cout << std::endl;
            for (int j = 0; j < blockWidth; ++j)
            {
//                int rowIndex = i + (blockCount / blockWidth);
//                int colIndex = j + (blockCount * blockWidth);
                int rowIndex = i + rowIndexOffset;
                int colIndex = j + colIndexOffset;

                std::cout << array_to_print[rowIndex][colIndex];

                if(array_to_print[rowIndex][colIndex] < 10)
                {
                     std::cout << "  ";
                }
                else
                {
                     std::cout << ' ';
                }

            }

        }

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

    std::cout << std::endl;
}

