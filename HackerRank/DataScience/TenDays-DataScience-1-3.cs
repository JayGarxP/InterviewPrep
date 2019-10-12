using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
/*
Hackerank 10 days of datascience statistics
Day 1 : Standard Deviation
https://www.hackerrank.com/challenges/s10-basic-statistics/problem
JP F.
*/
class Solution {
    static void Main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */
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
        Console.WriteLine(CalculateStdDev(X, N));
       

    }// end main

    public static double CalculateStdDev(List<int> DataSet, int DataSetMemberCount)
    {

// first check if DataMember count is != DataSet.Count; if true throw exception

        double mew = CalculateMean(DataSet, 14);
        double distancesFromMean = 0;
        // for each X term, accumulate (Xi - mew)^2
        // then divide by N terms; then sqrt that quotient
        foreach(int elem in DataSet)
        {
            distancesFromMean += (((double)elem - mew) * ((double)elem - mew));
        }

        double avgDistFromMean = (distancesFromMean / (double)DataSet.Count);

        double stdDeviation = Math.Sqrt(avgDistFromMean);

        return Math.Round(stdDeviation, 1);

    }

    public static double CalculateMean(List<int> DataSet, int decimalPrecision)
    {
        double totall = 0f;
        foreach(var num in DataSet)
        {
            totall += num;
        }

        return Math.Round((totall / DataSet.Count), decimalPrecision);

    }

}

