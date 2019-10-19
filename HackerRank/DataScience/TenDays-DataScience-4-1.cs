using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */
        double chanceBoy = 1.09;
        double chanceGirl = 1;
// binomial distribution vars
int x, n;
        double p, q;

// 1 child born per birth
// what proportion of Russian fam with 6 children have AT LEAST 3 boys?

x = 3;
n = 6;
// p(boy) = boychance / chancegirl + chance boy 
// just that over everything it can be
p = chanceBoy / (chanceGirl + chanceBoy);
//Console.WriteLine("P is " + p.ToString());
q = 1 - p;
//Console.WriteLine("Q is " + q.ToString());


// checkout this cool factorial snippet kids!
// http://www.luschny.de/math/factorial/csharp/FactorialPoorMans.cs.html

//binomial distro b(x,n,p) ==
// (n!/((x!)*((n-x)!))  *  p^x   * q^(n-x)


double binDist = 0;

// accumulate value of binDist x times for "AT LEAST"
  //for (int x = 3; x <= n; x++) {
   //         result += binomial(n, x, p);
    //    }
for(int i = x; i < n; i++)
{
 binDist +=
    Combination(n, i) * 
    Math.Pow(p, i) *
Math.Pow(q, n - i);
}


Console.WriteLine(Math.Round(binDist, 3));
// should get 0.6957
    }
// https://www.codeproject.com/Tips/262142/Calculate-the-Factorial-of-an-Intiger-in-Csharp
public static int Factorial(int input)
{
    int answer = 0;
    int count = 0;

    if (input >= 0)
    {
        count = 1;
        while (count <= input)
        {
            if (count == 1)
            {
                answer= 1;
                count++;
            }
            else
            {
                answer = count * answer;
                count++;
            }
        }
    }

    return answer;
}

public static double Combination(int nObjects, int rSampleSize)
{

int nFacto = Factorial(nObjects);
//Console.WriteLine(nFacto);
int xFacto = Factorial(rSampleSize);
//Console.WriteLine(xFacto);

int nxDiffFacto = Factorial((nObjects - rSampleSize));
//Console.WriteLine(nxDiffFacto);

double Combinations =  
(   
((double)(nFacto)) 
/ 
(   (double)( ((double)xFacto) * ((double)nxDiffFacto))    )
);

return Combinations;
}

}
