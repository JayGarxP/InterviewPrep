using Microsoft.VisualStudio.TestTools.UnitTesting;
using FizzBuzzPrep;
using System.Collections.Generic;

namespace UnitTestFizzBuzz
{
    [TestClass]
    public class UnitTest_FizzBuzz
    {
        private FizzBuzz testFB;

       public  UnitTest_FizzBuzz()
        {
            testFB = new FizzBuzz();
        }

        [TestMethod]
        public void FizzBuzzPrintsCorrectly_1through5()
        {
            var result = testFB.WriteFizzBuzzesToList(1,5);
            var expectedResult = new List<string>() { "1", "2", "Fizz", "4", "Buzz" };

            int numLines = result.Count;
            // Same number of lines have been processed
            Assert.AreEqual(numLines, expectedResult.Count);

            bool haveSameValues = true;
            var resultArray = result.ToArray();
            var expectedResultArray = expectedResult.ToArray();
            for (int i = 0; i < numLines; i++)
            {
                if (resultArray[i] != expectedResultArray[i])
                {
                    haveSameValues = false;
                }
            }
            
            // same values in the correct order of test FB and real FB
            Assert.IsTrue(haveSameValues, "Expected Result values do not match live result values");
            
        }
    }
}
