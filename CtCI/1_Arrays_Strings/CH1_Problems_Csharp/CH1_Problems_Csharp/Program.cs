using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CH1_Problems_Csharp
{
    class Program
    {
        /*
         * CTCi 1.1 JP Fallon
         * Cracking the Coding Interview Fifth Edition 
         * Chapter 1 Arrays and Strings
         * 1.1 pg.73
         * Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
         * */
        static void Main(string[] args)
        {

            // Time taken ~4 hours. On paper method failed, tried to do compare test string to rotations of itself char by char, special cases could sneak through
            // Wrote brute force method that can exit early.
            // Used C# HashSet to solve problem EZ
            // Found bit manipulation solution online, still just brute force but uses a bit field instead of many substrings
            // Typed in answers in book at the lowest point in this file. 149 more problems to go == 600 hours == 150 4 hour days at this rate.

            //string UTF16Test = "abcdeЇΘxyz"; // brute force and HashSet pass, BitwiseAccum fails, CtCI fails

            string Test = "abcdzexyz"; // all methods pass unique char check test;
        

            //bool IsStringUnique = IsStringUnique_BruteForce(Test);
            bool IsStringUnique = IsStringUnique_HashSet(Test);
            //bool IsStringUnique = IsStringUnique_BitwiseAccum(Test);
            //bool IsStringUnique = IsStringUnique_CTCi_Answer(Test);



            Console.WriteLine("String " + Test + " unique? " + IsStringUnique.ToString());
        }

        // Brute force with early exiting if found, and doesn't check same character twice.
        // Inner for loop checks substring of remaining unchecked characters against original test string.
        // Worth noting that this method does not use any c-style casts so it works with special characters and other human languages easiest IE UTF-16 the standard C# char spec
        // still uses String[index] = char though...
        static bool IsStringUnique_BruteForce(string Test)
        {
            bool IsUnique = true;

            //// assume char is UTF-16, casting back and forth won't ruin anything
            //char testChar = (char)('a' & 'a');
            //Console.WriteLine("testChar: " + testChar);
            //int zorTest = ('b' ^ 'b');
            // tried using rotations and bit shifts not working... Cannot find cool bit mask way to do this...

            // Brute force with early exits
            for (int i = 0; i < Test.Length && IsUnique == true; i++)
            {
                // for each char in string, compare it to every other char
                char target = Test[i];
                // only compare parts of string that haven't already been checked.
                string compareStr = Test.Substring(i + 1, Test.Length - (i + 1));

                for (int j = 0; j < compareStr.Length && IsUnique == true; j++)
                {
                    if (target == compareStr[j])
                    {
                        IsUnique = false;
                        Console.WriteLine("Duplicate '" + target + "' found in string " + Test);
                    }
                }

            }

            return IsUnique;
        }

        // https://stackoverflow.com/questions/4558754/define-what-is-a-hashset
        // Add each char of Test strings ascii value to a HashSet of integers, HashSet.Add() will return false if u try to add something already in set.
        static bool IsStringUnique_HashSet(string Test)
        {
            HashSet<int> asciiValueHS = new HashSet<int>();
            bool NoDuplicateChars = true;

            for (int i = 0; i < Test.Length && NoDuplicateChars == true; i++)
            {
                // The HashSet.Add() method will not add a duplicate value to the set and returns true if element was added
                NoDuplicateChars = asciiValueHS.Add(Test[i]);
            }

            // could do this if HashSet.Add() did not return  a bool that is true if element added was already in set.
            //return (Test.Length == asciiValueHS.Count);

            // If no repeat chars were added to the set of ascii values, then return true.
            return NoDuplicateChars;

        }

        // Accumulate ascii values into bitfield, if accum same value, exit.
        // This does not work on ascii beyond UTF-8 or on non-english.
        static bool IsStringUnique_BitwiseAccum(string Test)
        {
            // Accumulator field of bits starts zeroed out; add ones where a char was added, 
            int BitAccumField = 0; // This integer is used as a data structure...
            // for each char in Test string; 
            for (int i = 0; i < Test.Length; i++)
            {
                // subtract ascii 'a' from char at Test[i]
                // this only works on 'a'-'z' lowercase ascii in this case smallest bits of utf-16, everything else will break here.
                int asciiAdiff = (Test[i] - 'a');

                // Bit shift x0001 LEFT by the distance from a, in UTF-8 ~ 128 max digits
                //    if that ANDed with the bit accum field has any hot one bits in it, there was a duplicate.
                //    since that distance bit has already been accumulated in teh field.
                if ((BitAccumField & (1 << asciiAdiff)) != 0)
                {
                    return false;
                }

                // Accumulate asciiDiff bit into field with   field = field OR (field + asciiDiff hot bit) 
                BitAccumField |= (1 << asciiAdiff);

            }
            return true;

        }

        // Official answers below:
        // The 'no data structures' challenge is above in BitwiseAccum() which still uses an int as a data struct but oh well
        // Ask interviewer if chars are ascii or unicode to show "deep understanding of computer science" lol the first 8 bits of unicode == ascii, utf-8 is pretty much just ascii
        static bool IsStringUnique_CTCi_Answer(string Test)
        {
            // if 256 characters are possible in UTF-8 single byte, longer than that has repeats.
            // Of course, ascii is 128, utf-16 has 524,000 slots for characters, 1.1MIllion if you allow pointers (used for emojis usually)
            // The standard in may 2019 officially assigns 277,576 unique characters to UTF-16, mostly allocated towards logogram rich human languages and math symbols
            // so this short-circuit might not be as 'big brain' as advertised.
            if (Test.Length > 256)
            {
                return false;
            }
            bool[] char_set = new bool[256];

            for (int i = 0; i < Test.Length; i++)
            {
                int val = Test[i];
                // exit if char with val already found/hit.
                if (char_set[i] == true)
                {
                    return false;
                }
                // access boolean array with ascii index value; set char represented there to true/hit;
                //  will crash with fatal access exception if using any char above 256, very easy to do with UTF-16
                char_set[val] = true;
            }

            return true;

        }
    }
}
