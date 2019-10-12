using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution
         https://www.hackerrank.com/challenges/s10-weighted-mean/problem
         Weighted Mean; JPF
        */
// assume input is well formed; otherwise would have tryparse and exception handling
        int N_arraySize = Int32.Parse(Console.ReadLine());

        string[] X_values = Console.ReadLine().Split(' ');
        int[] X = Array.ConvertAll(X_values, int.Parse);
        string[] W_weights = Console.ReadLine().Split(' ');
        int[] W = Array.ConvertAll(W_weights, int.Parse);

        double result = WeightedAvgToOneDecimal(X, W, N_arraySize);

        // natural numbers modulo 1 == 0 ;; have no decimal component
        if(result % 1 == 0)
        {   
            Console.WriteLine(result.ToString() + ".0");
        }else
        {
            Console.WriteLine(result);
        }
    }

    public static double WeightedAvgToOneDecimal(int[] Values, int[] Weights, int NumElems)
    {
// for each element in the parrallel arrays X & W
// accumulate X[i] Mult W[i] into a double: WANumerator
// accumulate W[i] + W[n] into another double: WADenominator
// On exit, all elements processed, decimal divide WAN / WAD for weighted avg

 double weightedAvg = 0;
        double WANumerator = 0;
        double WADenominator = 0;

for(int i = 0; i < NumElems; i++)
{
    WANumerator += (Values[i] * Weights[i]);
    WADenominator += Weights[i];
}

weightedAvg = (double)(WANumerator / WADenominator);

        return Math.Round(weightedAvg, 1);
    }
}