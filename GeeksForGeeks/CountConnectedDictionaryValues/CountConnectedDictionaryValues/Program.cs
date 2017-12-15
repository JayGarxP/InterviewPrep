//using System;
//using System.Collections.Generic;
using System;
using System.Collections.Generic;
using System.Linq;
//using System.Text;
//using System.Threading.Tasks;

namespace CountConnectedDictionaryValues
{
    // In this example C is manager of A, 
    // C is also manager of B, F is manager 
    // of C and so on.
    //http://www.tutorialsteacher.com/csharp/csharp-dictionary
    class Solution
    {

        public class Employee
        {
            
            public string ID { get; set; }
            public List<string> reportingIDs { get; set; }

            //Number of employees directly reporting
            public int directPeonCount { get; set; }

            //Total number of employees reporting to this employee or any of their henchmen
            public int totalPeonCount { get; set; }

            public Employee()
            {
                reportingIDs = new List<string>();
            }
        };

        static void Main(String[] args)
        {
            //Assume identity is string from database NOT a char
            Dictionary<string, string> dict = new Dictionary<string, string>(){
        { "A", "C" }, //"Peon" key, "BOSS" value
        { "B", "C" },
        { "C", "F" },
        { "D", "E" },
        { "E", "F" },
        { "F", "F" }
    };
            //CEO reports to herself and CALLS THE SHOTS! YA FIYAD!
            string BigBossID;
          
            IDictionary<string, int> output = new Dictionary<string, int>(); // <BOSS id>, <Henchmen count>
                                                                             //https://stackoverflow.com/questions/1276763/how-do-i-get-the-list-of-keys-in-a-dictionary
            List<string> CGEmployees = dict.Keys.ToList();
            List<Employee> Company = new List<Employee>();

            foreach (string EmpId in CGEmployees)
            {
                output.Add(EmpId, 0);
                Employee staff = new Employee();

                    staff.ID = EmpId; //staff ID is key to be used as boss
                if (EmpId == dict[EmpId])
                {//Find BigBoss who reports to no one, not the IRS, not their family, not even God.
                    BigBossID = EmpId;
                }

                Company.Add(staff);
            }

            //Built staff w/ only IDs by switching dictionary Keys to Values sort of
            //Now find collisions and trace them until no reporting values are found and update the data in Employee correctly as you go.
            foreach (Employee staff in Company) {
                Console.WriteLine("Hi I'm " + staff.ID);
                foreach (KeyValuePair<string,string> bossID in dict) {
                    if (staff.ID == bossID.Value) {
                        Console.WriteLine(bossID.Value +" is the boss of: "+ bossID.Key);

                    }
                }

//                foreach (KeyValuePair<string, book> b in books) // or foreach(book b in books.Values)
//                {
//                    if (b.Value.title.Equals("some title", StringComparison.CurrentCultureIgnoreCase))
//                        return true
//}
            }

            Console.WriteLine("AI will have the capacity to suffer");
        }


        bool TraverseDictionary(List<String> ids, List<Employee> employees) {

            return false;
        }
    }
}