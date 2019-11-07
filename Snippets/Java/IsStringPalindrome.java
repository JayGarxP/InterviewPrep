//*******************************************************************
// Welcome to CompileJava!
// If you experience any issues, please contact us ('More Info')  -->
//*******************************************************************

import java.lang.Math; // headers MUST be above the first class

// one class needs to have a main() method
public class HelloWorld
{
  // arguments are passed using the text field below this editor
  public static void main(String[] args)
  {
    OtherClass myObject = new OtherClass("Hello World!");
    System.out.print(myObject);
    
    String palindromeTest = "Racecar";
    SpecialString testIP = new SpecialString(palindromeTest);
    System.out.print("is " + palindromeTest + " a palindrome: " + testIP.IsPalindrome());
  }
}

// you can add other public classes to this editor in any order
public class OtherClass
{
  private String message;
  private boolean answer = false;
  public OtherClass(String input)
  {
    message = "Why, " + input + " Isn't this something?\n\n";
  }
  public String toString()
  {
    return message;
  }
}

public class SpecialString
{
  private String word;
 
  public SpecialString(String word)
  {
    if (word == null)
    {
      this.word = "";
    }
    else
    {
       this.word = word;
    }
   
  
  }
  
  // return true if string is a palindrome, is "racecar" spelled same backwards and forwards case insensitive
  public boolean IsPalindrome()
  {
    // integer division is what we want, odd strings always pivot around middle letter
    int numberComparisons = word.length() / 2;
    boolean yesIsPalindrome = true;
     Character headLetter; // first letter
    Character tailLetter; // last letter
    
    // for number comparisons: see if first letter + i != last letter -i; then it is NOT palindrome
    for (int i = 0; (i < numberComparisons) && (yesIsPalindrome); i++)
    {
      headLetter = word.charAt(i);
      tailLetter = word.charAt(word.length() - (i + 1));
     
      // if letters are not equal; it is not a palindrome; exit;
      if (Character.toLowerCase(headLetter) != Character.toLowerCase(tailLetter))
      {
        yesIsPalindrome = false;
      }
      
    }
    
    return yesIsPalindrome;
  
  }

}