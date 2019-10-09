using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
/*
Hackerank 10 days of datascience statistics
Day 0 : A Mean Median Mode
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
        Console.WriteLine(CalculateMean(X));
        Console.WriteLine(CalculateMedian(X));
        Console.WriteLine(CalculateMode(X));
        //Console.WriteLine(CalculateMode_LINQ(X.ToArray()));

    }

    public static double CalculateMean(List<int> DataSet)
    {
        double totall = 0f;
        foreach(var num in DataSet)
        {
            totall += num;
        }

        return Math.Round((totall / DataSet.Count), 1);

    }

// assume dataset is already sorted
// for the k-order opmtimal algo: https://stackoverflow.com/questions/4140719/calculate-median-in-c-sharp
      public static double CalculateMedian(List<int> ASC_DataSet)
    {
        // where lower middle index would be if dataset was 
        // sorted into array in ascending order
        int lowerMiddleIndex = (ASC_DataSet.Count - 1) / 2;
        int[] ASC_Array = ASC_DataSet.ToArray();

// average the two lower middle values together; / by 2.0 to remain double
        double median = ((ASC_Array[lowerMiddleIndex] + 
        ASC_Array[lowerMiddleIndex + 1]) / 2.0);

// round to one decimal place.
        return Math.Round(median, 1);

    }

public static int CalculateMode(List<int> DataSet)
{
    // add values to dictionary, if already in dictionary
    // update parralel key num : val count collection
    Dictionary<int, int> dictNumOcc = 
    new Dictionary<int, int>();

    foreach(int elem in DataSet)
    {
        // Hackerank uses too old of .NET for this
        //bool added = dictNumOcc.TryAdd (elem, 1);
     
     int value = 0;
if (dictNumOcc.TryGetValue(elem, out value))
{
    // exists
    dictNumOcc[elem]++;
}
else
{
    // key does not exist
    dictNumOcc.Add(elem, 1);
}
        
    }

    int highestOccurence = -1;
    int lowestMode = -1;

foreach(var paire in dictNumOcc)
{
    if(paire.Value == highestOccurence)
    {
        // overwrite if lower key, order matters now, but the list is sorted, dict is added in order so??? might work???
        if(paire.Key < lowestMode)
        {
            lowestMode = paire.Key;
        }
    }
    else if(paire.Value > highestOccurence)
    {
        highestOccurence = paire.Value;
        lowestMode = paire.Key;
    }
}

    return lowestMode;


}


// Easy way to get mode using LINQ
// https://www.csharpstar.com/csharp-find-the-most-frequent-element-in-an-array/
    public static int CalculateMode_LINQ(int[] numbers)
        {
            var groups = numbers.GroupBy(x => x);
            var largest = groups.OrderByDescending(x => x.Count()).First();
            //Console.WriteLine("The most common number is {0} and it appears {1} times", largest.Key, largest.Count());
            return largest.Key;
        }
 
}
