public class HelloJava {
    public String name;
     
    public static String sayHello1(String str) {
    	System.out.println("java static: sayHello");
        return "Hello, " + str + "!";
    }
     
    public String sayHello2() {
    	System.out.println("java: sayHello");
        return "Hello, " + name + "!";
    }
}