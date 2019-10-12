using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
/*
Hackerank 10 days of datascience statistics
Day 1 : InterQuartile Range
https://www.hackerrank.com/challenges/s10-basic-statistics/problem
JP F.
*/
class Solution {
    static void Main(String[] args) {
        int N = Int32.Parse(Console.ReadLine());
        string xString = Console.ReadLine();
        string fString = Console.ReadLine();
        string[] Xstringsss = xString.Split(' ');
        string[] Fstringsss = fString.Split(' ');
       List<int> S = new List<int>();
        for(int i = 0; i < Xstringsss.Length; i++)
        {
        try
       {
            int numVal = Int32.Parse(Xstringsss[i]);
            int freqVal = Int32.Parse(Fstringsss[i]);
            for(int j = 0; j < freqVal; j++)
            {
                S.Add(numVal);
            }
       }
       catch (FormatException e)
       {
           Console.WriteLine(e.Message);
       } 
        }

// default List<numeric>.Sort() is ascending order
 S.Sort();
int[] AscendingData = S.ToArray();



double iqr = CalcIQR(AscendingData, AscendingData.Length);

if(iqr % 1 == 0)
Console.WriteLine(iqr.ToString() + ".0");
else
Console.WriteLine(iqr);

    } //end main

// Interquartile range of dataset;
// tested with:
//6
//7 15 36 39 40 41
public static double CalcIQR(int[] ASC_DataSet, int elemCount)
{
    double iqr = 0.0;
     int medianIndex = elemCount / 2;

     bool oddDataSetSize = true;
        if(elemCount % 2 == 0)
        {
            // evenly divides by two; set element count is EVEN
            oddDataSetSize = false;
        }

// If there is an odd number of data points in the original ordered data set, do not include the median (the central value in the ordered list) in either half.
        if(oddDataSetSize)
        {
            // IQR = Q3 - Q1;
            iqr = CalculateMedian(ASC_DataSet, medianIndex + 1, elemCount - 1) 
            - CalculateMedian(ASC_DataSet, 0, medianIndex - 1);
        }else
        {
            // If there is an even number of data points in the original ordered data set, split this data set exactly in half.
               iqr = CalculateMedian(ASC_DataSet, medianIndex, elemCount - 1) 
            - CalculateMedian(ASC_DataSet, 0, medianIndex - 1);
        }

    return Math.Round(iqr, 1);
}

// assume dataset is already sorted
// for the k-order opmtimal algo: https://stackoverflow.com/questions/4140719/calculate-median-in-c-sharp
      public static double CalculateMedian(int[] ASC_DataSet, int StartIndex, int EndIndex)
    {
        // first check if startI or EndI is out of bounds; with another param probs

        double median = 0;
       //int medianIndexofSet = ASC_DataSetSize / 2;

   int SubsetSize = (EndIndex - StartIndex) + 1;
        
        int halfSubsetVal = SubsetSize / 2;
        int middleIndexofSubset = halfSubsetVal + StartIndex;

        if(SubsetSize % 2 == 0)
        {
           // even elements in subset, avg
             median = (ASC_DataSet[middleIndexofSubset] + 
            ASC_DataSet[middleIndexofSubset - 1]) / 2.0;
        }else
        {
            // Odd total elements in subset, pick out middle
               median = ASC_DataSet[middleIndexofSubset];
        }


// round to one decimal place.
        return Math.Round(median, 1);
    }


}