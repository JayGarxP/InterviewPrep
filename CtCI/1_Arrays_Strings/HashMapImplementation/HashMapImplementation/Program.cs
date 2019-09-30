using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace HashMapImplementation
{
    /*
     * Reviewing what a hashmap actually is, I use it all the time, 
     * but don't actually understand what it is or how it works.
     * https://youtu.be/s8YcbwVl-HI
     * */
    class Program
    {
        static Hashtable userInfoHash;
        static List<UserInfo> userInfoList;
        static Stopwatch SW;
    
        static void Main(string[] args)
        {
            userInfoHash = new Hashtable();
            userInfoList = new List<UserInfo>();
            SW = new Stopwatch();

            // Add to hashtable and list
            for (int i = 0; i < 5000000; i++)
            {
                // add useri value with key i
                userInfoHash.Add(i, "user" + i);
                // add to list as well
                userInfoList.Add(new UserInfo(i, "user" + i));
            }


            Console.WriteLine(AverageLookupTimeRoughEstimate(1, 2000000, GetUserFromList_Find).ToString());   

            //// remove from hashtable
            //if (userInfoHash.ContainsKey(0))
            //{
            //    userInfoHash.Remove(0);
            //}

            //// setting value
            //if (userInfoHash.ContainsKey(1))
            //{
            //    userInfoHash[1] = "replacementName";
            //}

            //// Looping through hashtable
            //foreach (DictionaryEntry entry in userInfoHash)
            //{
            //    Console.WriteLine("Key: " + entry.Key + 
            //        " // Value: " + entry.Value);
            //}



            // how to use built-in c# hashmap, what is hashmap.

            // Build own hashmap

            // make own hashing function

            // Test performance of all three.

        }

        /* Hashtable is a collection of key value pairs
           Key is an indexer
           Value is accessed by key; Value = Hashtable[key];
           Hashtables are best collection for lookup times, every value has unique key, O(1) constant time to lookup

         
         */

            // brute force list search
        public static string GetUserFromList_BruteForceSearch(int userId)
        {
            for (int i = 0; i < userInfoList.Count; i++)
            {
                if (userInfoList[i].userId == userId)
                {
                    return userInfoList[i].userName;
                }
            }

            return string.Empty;
        }

        // List.Find() search
        public static string GetUserFromList_Find(int userId)
        {
            return userInfoList.Find(x => x.userId == userId).userName;
        }

        public static string GetUserFromHashTable(int userId)
        {
            return (string)userInfoHash[userId];
        }

        public delegate string GetUserInfoUserName(int userId);

        public static float AverageLookupTimeRoughEstimate(int minRandomVal, int maxRandomVal, GetUserInfoUserName lookupFunction, int cycles = 5)
        {
            // access
            Random randomUserGen = new Random();
            int randomUser = -1;

            SW.Start();
            float startTime = 0f;
            float endTime = 0f;
            float deltaTime = 0f;
            float averageTime = 0f;

            //int cycles = 5;
            int cycle = 0;
            string userName = string.Empty;

            // compare list to hashtable with full range of random users
            while (cycle < cycles)
            {
                // same random user for both
                randomUser = randomUserGen.Next(minRandomVal, maxRandomVal);
                // set a starting timestamp
                startTime = SW.ElapsedMilliseconds;
                // perform time sensitive operation
                //userName = GetUserFromList_BruteForceSearch(randomUser);
                // userName = userInfoList.Find(x => x.userId == randomUser).userName;
                userName = lookupFunction(randomUser); // ACTUALLY WORKING WOW!!!

                // set an ending timestamp
                endTime = SW.ElapsedMilliseconds;
                // print out the change in time
                deltaTime = endTime - startTime;

                averageTime += deltaTime;

                //Console.WriteLine("Time taken to retrieve " + userName + " FROM LIST "
                //    + string.Format("{0:0.##}", deltaTime) + "ms");


                //// set a starting timestamp
                //startTime = SW.ElapsedMilliseconds;
                //// perform time sensitive operation
                //userName = (string)userInfoHash[randomUser];
                //// set an ending timestamp
                //endTime = SW.ElapsedMilliseconds;
                //// print out the change in time
                //deltaTime = endTime - startTime;

                //Console.WriteLine("Time taken to retrieve " + userName + " FROM H@$HTABLE "
                //    + string.Format("{0:0.##}", deltaTime) + "ms");



                cycle++;
            }

            return averageTime / cycles;

        }

}

    // type for list to demonstrate hashtable speed
    struct UserInfo
    {
        public int userId;
        public string userName;
        public UserInfo(int id, string name)
        {
            userId = id;
            userName = name;
        }
    }

  
}
