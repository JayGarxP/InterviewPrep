using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
/*
Hackerank 10 days of datascience statistics
Day 1 : Quartiles
https://www.hackerrank.com/challenges/s10-basic-statistics/problem
JP F.
*/
class Solution {
    static void Main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution 
            Use the median to divide the ordered data set into two halves.
        If there is an odd number of data points in the original ordered data set, do not include the median (the central value in the ordered list) in either half.
        If there is an even number of data points in the original ordered data set, split this data set exactly in half.
    The lower quartile value is the median of the lower half of the data. The upper quartile value is the median of the upper half of the data.*/

// can also do this: 
 // int i = Convert.ToInt32(Console.ReadLine());
  //      int[] list = Console.ReadLine().Split().Select(int.Parse).ToArray();

        int N = Int32.Parse(Console.ReadLine());
        string xString = Console.ReadLine();
        string[] Xstringsss = xString.Split(' ');
        List<int> X = new List<int>();
        for(int i = 0; i < Xstringsss.Length; i++)
        {
        try
       {
            int numVal = Int32.Parse(Xstringsss[i]);
            //Console.WriteLine(numVal);
            X.Add(numVal);
       }
       catch (FormatException e)
       {
           Console.WriteLine(e.Message);
       } 
        }

// default List<numeric>.Sort() is ascending order
X.Sort();
int[] AscendingData = X.ToArray();
// https://docs.microsoft.com/en-us/dotnet/api/system.array.copy?view=netframework-4.8
// public static void Copy (Array sourceArray, int sourceIndex, Array destinationArray, int destinationIndex, int length);

// should be way to do this without making subarrays?
int q1Size = N / 2;
Console.WriteLine(CalculateMedian(AscendingData, q1Size));
Console.WriteLine(CalculateMedian(AscendingData, N));
int q3StartIndex = N / 2;
int q3Size = -1;
if( N % 2 != 0)
{
    // if odd number of elements in dataset, skip the median; don't start q3 at median
    q3StartIndex++;
}

//q3StartIndex = 5; // 4 size
q3Size = N - q3StartIndex;

int[] UpperQuartileSet = new int[q3Size];
Array.Copy(AscendingData, q3StartIndex,
UpperQuartileSet, 0, q3Size);

Console.WriteLine(CalculateMedian(UpperQuartileSet, q3Size));

    } //end main



// assume dataset is already sorted
// for the k-order opmtimal algo: https://stackoverflow.com/questions/4140719/calculate-median-in-c-sharp
// if integer data set already sorted, could have a third parameter for index start; index end; then would not need a subarray.
      public static double CalculateMedian(int[] ASC_DataSet, int DataSetCount)
    {
        double median = 0;
         int tempIndex = (DataSetCount / 2);

        // if even count of dataset, avg the two middle values rounded to 1 decimal point
        if(DataSetCount % 2 == 0)
        {
            median = (ASC_DataSet[tempIndex] + ASC_DataSet[tempIndex - 1]) / 2.0;

        }
        else
        {
            // odd data set return the middle data point.
            // integer division will round down to make the index correct.
            median = ASC_DataSet[tempIndex];
        }



// round to one decimal place.
        return Math.Round(median, 1);

    }


}