public class MainJava {
    public static void callScala() {
    	System.out.println("java callScala");
        new TestCom().hello(); // [1]
        TestCom.hallo();  // [2] (static)
        TestCom$.MODULE$.hello();  // [3] (hidden static)
    }
    public static void main(String[] args) {
        System.out.println("java main");
        callScala();
    }
}