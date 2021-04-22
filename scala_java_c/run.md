https://lampwww.epfl.ch/~michelou/scala/using-scala-from-java.html

##### run scala through java

```
scalac TestCom.scala
javac -cp $SCALA_HOME/lib/scala-library.jar:. MainJava.java
java -cp $SCALA_HOME/lib/scala-library.jar:. MainJava
```

##### run jni to call scala by using c

javac -cp <jar you want to include>;<jar you want to include> <source.java>

```
javap -s -p MainJava
```

