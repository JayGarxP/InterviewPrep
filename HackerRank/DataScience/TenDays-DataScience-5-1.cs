using System;
using System.Collections.Generic;
using System.IO;
// https://www.hackerrank.com/challenges/s10-geometric-distribution-1/problem
/*
Probability that machine produces defective product is 1/3; 
what is probability that the 1st defect is found during the 5th inspection???
print single line in Main() that is the answer rounded to 3 decimal places.
*/
class Solution {
    static void Main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */

        // allowed to hardcode solution
        // probability of first failure on specific attempt is geometric distribution
        //      which is negative binomial distrobution
            double n = 5;
            double p = 1.0/3.0;
     

        Console.WriteLine(GeoMetricDist(n,p));
    }

   // g, geometric dist chance = g(n,p) === q^(n-1) * p
        // where q is fail chance on any given experiment,
        // p is success chance 0 - 1 exclusive on any given experiment,
        // n is number of experiment trials 
    public static double GeoMetricDist(double numTrials, double trialSuccessChance)
    {
        double geometricDistribution = 0;

        double trialFailChance = 1 - trialSuccessChance;
        geometricDistribution = Math.Pow(trialFailChance, numTrials - 1)
         * trialSuccessChance;

        return Math.Round(geometricDistribution, 3);
    }
}
