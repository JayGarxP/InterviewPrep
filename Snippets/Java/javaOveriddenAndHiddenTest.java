class A{
    int a = 5;
    String doA(){return "a1";}
    protected static String doA2(){return " a2 ";}
}

class B extends A{
    int b = 7;
    String doA(){return " b1 ";}
    public static String doA2(){return " b2 ";}
    
    void go(){
        A myA = new B();
        System.out.print(myA.doA() + myA.doA2() + myA.a);
    }
}


public class HelloWorld{

     public static void main(String []args){
         
         new B().go();
		 // output: b1 a2 5
		 // Public/Protected methods are inherited by subclass, but if static the method is 'hidden' instead of 'overridden'
		 // Since the A is superclass type it uses it's own static method not the subclass, and it can only see superclass fields
		 // A.b is inaccessible
        System.out.println("Hello World");
     }
}