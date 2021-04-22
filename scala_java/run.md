https://lampwww.epfl.ch/~michelou/scala/using-scala-from-java.html

##### run scala through java

```bash
scalac TestCom.scala
javac -cp $SCALA_HOME/lib/scala-library.jar:. MainJava.java
java -cp $SCALA_HOME/lib/scala-library.jar:. MainJava
```

##### run jni to call scala by using c

in foo.c

set class path as follow

```bash
options[0].optionString = "-Djava.class.path=/Users/haoboxuxu/opt/scala-2.13.4/lib/scala-library.jar:.";
```

don't use $SCALA_HOME even you've set in your bash profile

