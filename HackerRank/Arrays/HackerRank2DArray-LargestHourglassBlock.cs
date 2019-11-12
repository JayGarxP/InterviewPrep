using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Solution {

    // Complete the hourglassSum function below. http://hr.gs/abbdcb
    static int hourglassSum(int[][] arr) {
// row i  col j

// for loop that runs 16 times
// accumulate 3 x 3 block of arr[][] vals skipping 4 and 6 'hourglass curves'
// compare to max val if accumulated val is larger set that as new max val
// reset hourglass starting index

// 4 rows by 4 columns of starting hourglass indeces

int maxHourGlassSum = -999; // 0 fails test if all hourglasses are negative; it is incorrectly preserved

for (int i = 0; i < 4; i++)
{
    for (int j = 0; j < 4; j++)
    {
        // accumulate hourglass values
        int hourGlassSum = 0;
        for (int hgRow = 0; hgRow < 3; hgRow++)
        {
            for (int hgCol = 0; hgCol < 3; hgCol++)
            {
                // don't add the 4 and 6 'curves' of hourglass!
                if(!    (hgRow == 1 && hgCol != 1))
                {
                hourGlassSum += arr[i + hgRow][j + hgCol];
                }
            }

        }

        // test max
        if (hourGlassSum > maxHourGlassSum)
        {
            maxHourGlassSum = hourGlassSum;
        }
    }
}





return maxHourGlassSum;

    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int[][] arr = new int[6][];

        for (int i = 0; i < 6; i++) {
            arr[i] = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
        }

        int result = hourglassSum(arr);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}