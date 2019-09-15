using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FizzBuzzPrep
{
    public class FizzBuzz
    {
        // Unit Tests for FizzBuzz methods

        // Modulo numbers
        short FizzNumber;
        short BuzzNumber;
        // Assuming that this condition IS dependent on Fizz and Buzz numbers for now.
        //short FizzBuzzNumber;

        //public string FizzBuzzOutput { get; private set; }

        public FizzBuzz()
        {
            FizzNumber = 3;
            BuzzNumber = 5;
        }

        public FizzBuzz(short fizzNum, short buzzNum)
        {
            this.FizzNumber = fizzNum;
            this.BuzzNumber = buzzNum;
        }

        private bool CalculateFizzBuzzNumber(short fizzNum, short buzzNum, int testValue)
        {
            return (testValue % fizzNum == 0 && testValue % buzzNum == 0);
        }

        public void PrintFizzBuzzes(int startValue = 1, int finishValue = 100)
        {
            for (int i = startValue; i <= finishValue; i++)
            {
                if( CalculateFizzBuzzNumber(FizzNumber, BuzzNumber, i) )
                {
                    Console.WriteLine("FizzBuzz");
                }
                else if (i % FizzNumber == 0)
                {
                    Console.WriteLine("Fizz");
                }
                else if (i % BuzzNumber == 0)
                {
                    Console.WriteLine("Buzz");
                }
                else
                {
                    Console.WriteLine(i);
                }
            }
        }

        public List<string> WriteFizzBuzzesToList(int startValue = 1, int finishValue = 100)
        {
            List<string> fizzBuzzOuputs = new List<string>();

            for (int i = startValue; i <= finishValue; i++)
            {
                if (CalculateFizzBuzzNumber(FizzNumber, BuzzNumber, i))
                {
                    fizzBuzzOuputs.Add("FizzBuzz");
                }
                else if (i % FizzNumber == 0)
                {
                    fizzBuzzOuputs.Add("Fizz");

                }
                else if (i % BuzzNumber == 0)
                {
                    fizzBuzzOuputs.Add("Buzz");
                }
                else
                {
                    fizzBuzzOuputs.Add(i.ToString());
                }
            }

            return fizzBuzzOuputs;
        }

        public void PrintFizzBuzzesFromList(List<string> input)
        {
            foreach (var line in input)
            {
                Console.WriteLine(line);
            }
        }

        public void PrintFizzBuzzesFromList( int startValue = 1, int finishValue = 100)
        {
            PrintFizzBuzzesFromList(WriteFizzBuzzesToList(startValue, finishValue));
        }

    }
}
