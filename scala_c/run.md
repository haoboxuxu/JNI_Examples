##### Setup and compile .class file 

```bash
for scala
	scalac TestCom.scala
for function descriptor
	javap -s -p TestCom
```

##### hint

in foo_scala.c
set options[0].optionString as follow, path is the scala home path to your os
don't use $SCALA_HOME even you've set in your bashprofile

```bash
-Djava.class.path=/Users/haoboxuxu/opt/scala-2.13.4/lib/scala-library.jar:.
```



##### Compile .c on Mac

```bash
gcc -o foo_scala foo_scala.c -I/Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/include -L/Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/jre/lib/server -ljvm

if 'jni_md.h' file not found
 
sudo cp /Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/include/darwin/jni_md.h /Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/include
```

##### or

##### Compile .c on Linux

```bash
env setup
1. setup java env and scala env
2. JAVA_HOME and SCALA_HOME
3. export LD_LIBRARY_PATH=/usr/lib/jvm/java-8-oracle/jre/lib/amd64/server
	 export LD_PRELOAD=/usr/sfw/lib/amd64/libgcc_s.so
   sudo R CMD javareconf

source /etc/profile
gcc -o foo_scala foo_scala.c -I/usr/lib/jvm/java-se-8u41-ri/include -I/usr/lib/jvm/java-se-8u41-ri/include/linux -L/usr/lib/jvm/java-se-8u41-ri/jre/lib/amd64/server -ljvm
chmod 775 foo
```



##### run scala through c with jni

```bash
./foo_scala
or
./foo_scala.o
```



###### created by HaoboXu

