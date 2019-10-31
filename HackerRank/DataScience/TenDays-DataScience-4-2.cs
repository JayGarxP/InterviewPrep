using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    // To fix rounding errors caused by bad factorial function,
    // stole function and 0 index logic from RodneyShag    
    static void Main(String[] args) {

        double rejectRate = 0.12;
        double batchSize = 10;
        int numRejects = 2;
           double ratio = rejectRate;
        
        double p = ratio; // ratio / (1 + ratio);
        int    n = (int)batchSize;
        
        // Calculate cumulative distribution function, 0-2 inclusive rejects
        // x is k
        double result = 0;
        for (int x = numRejects; x <= n; x++) {
            result += binomial(n, x, p);
        }

double noMoreThanTwoResult = Math.Round(result,3);

// attempt to get 2+ exclusive amount rejects
        //result = 1 - result; // can't just do this
double greaterThanTwoRejectsResult = 0.0;
n = 10; // k = 8 (trials - at least failures); p is now 100% - 12% since > isntead of <= AKA NOT rejected

  for (int x = 8; x <= n; x++) {
            greaterThanTwoRejectsResult += binomial(n, x, 1-p);
        }

        Console.WriteLine(Math.Round(greaterThanTwoRejectsResult,3));

        Console.WriteLine(noMoreThanTwoResult);
    }

// return null in Java changed to return 0 in C#
// there is no primitive vs special box Integer vs int in C# unlike Java,
// so a C# value type can't be NULL, will exit early when x == n to not be off by one
  private static double binomial(int n, int x, double p) {
        if (p < 0 || p > 1 || n < 0 || x < 0 || x > n) {
            return 0;
        }
        return combinations(n, x) * Math.Pow(p, x) * Math.Pow(1 - p, n - x);
    }
    
    private static long combinations(int n, int x) {
        if (n < 0 || x < 0 || x > n) {
            return 0;
        }
        return factorial(n) / ( factorial(x) * factorial(n - x) );
    }
    
    // This was the initial culprit, 
    // the 0! == 1 edge case was missing from the factorial function I stole
    // off a terrible website. This was the real cause of "rounding" errors
    // Literally missed this EXACT edge case in a live programming interview BTW
    // before making this mistake again here...
    // 0! zero factorial is ONE!!! NOT ZERO!!!!
    private static long factorial (int n) {
        if (n < 0) {
            return 0;
        }
        long result = 1;
        while (n > 0) {
            result *= n--;
        }
        return result;
    }

}
