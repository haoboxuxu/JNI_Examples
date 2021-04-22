##### Setup and compile .class file 

```bash
for java
	javac Sample2.java
for scala
	scalac HelloScala.scala
for function descriptor
	javap -s -p Sample2
or 
	javap -s -p HelloScala
```



##### Compile .c on Mac

```bash
gcc -o foo foo.c -I/Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/include -L/Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/jre/lib/server -ljvm

if 'jni_md.h' file not found
 
sudo cp /Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/include/darwin/jni_md.h /Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/include
```

##### or

##### Compile .c on Linux

```bash
env setup
1. java env
2. JAVA_HOME
3. export LD_LIBRARY_PATH=/usr/lib/jvm/java-8-oracle/jre/lib/amd64/server
	 export LD_PRELOAD=/usr/sfw/lib/amd64/libgcc_s.so
   sudo R CMD javareconf

source /etc/profile
gcc -o foo foo.c -I/usr/lib/jvm/java-se-8u41-ri/include -I/usr/lib/jvm/java-se-8u41-ri/include/linux -L/usr/lib/jvm/java-se-8u41-ri/jre/lib/amd64/server -ljvm
chmod 775 foo
```



##### run compiled

```bash
./foo 
or
./foo.o
```



###### created by HaoboXu

