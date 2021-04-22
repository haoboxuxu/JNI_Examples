#include <jni.h>
#include <string.h>
#include <stdio.h>
#define PATH_SEPARATOR ':'
// gcc -o foo_java foo_java.c -I/Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/include -L/Library/Java/JavaVirtualMachines/jdk1.8.0_271.jdk/Contents/Home/jre/lib/server -ljvm
int main() {
    JavaVMOption options[1];
    JNIEnv *env;
    JavaVM *jvm;
    JavaVMInitArgs vm_args;
     
    long status;
    jclass cls;
    jmethodID mid;
    jfieldID fid;
    jobject obj;
     
    options[0].optionString = "-Djava.class.path=/Users/haoboxuxu/opt/scala-2.13.4/lib/scala-library.jar:.";
    memset(&vm_args, 0, sizeof(vm_args));
    vm_args.version = JNI_VERSION_1_4;
    vm_args.nOptions = 1;
    vm_args.options = options;
     
    // 启动虚拟机
    status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
     
    if (status != JNI_ERR) {
        // 先获得class对象
        cls = (*env)->FindClass(env, "MainJava");
        if (cls != 0) {
            // 获取方法ID, 通过方法名和签名, 调用静态方法
            mid = (*env)->GetStaticMethodID(env, cls, "callScala", "()V");
            if (mid != 0) {
                (*env)->CallStaticObjectMethod(env, cls, mid);
            } else {
                printf("mid create failed\n");
            }
        } else {
            printf("cls create failed!\n");
        }
         
        (*jvm)->DestroyJavaVM(jvm);
        return 0;
    } else {
        printf("JVM created failed!\n");
        return -1;
    }
}