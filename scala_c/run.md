##### run scala through c with jni

```
scalac TestCom.scala
gcc -o foo_scala foo_scala.c -I/Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/include -L/Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/jre/lib/server -ljvm
```

##### run jni to call scala by using c

```
javap -s -p TestCom
```

##### run

```
./foo_scala
```

