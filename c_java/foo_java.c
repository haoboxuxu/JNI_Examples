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
     
    options[0].optionString = "-Djava.class.path=.";
    memset(&vm_args, 0, sizeof(vm_args));
    vm_args.version = JNI_VERSION_1_4;
    vm_args.nOptions = 1;
    vm_args.options = options;
     
    // 启动虚拟机
    status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
     
    if (status != JNI_ERR) {
        // 先获得class对象
        cls = (*env)->FindClass(env, "HelloJava");
        if (cls != 0) {
            // 获取方法ID, 通过方法名和签名, 调用静态方法
            mid = (*env)->GetStaticMethodID(env, cls, "sayHello1", "(Ljava/lang/String;)Ljava/lang/String;");
            if (mid != 0) {
                const char* name = "hbhb1";
                jstring arg = (*env)->NewStringUTF(env, name);
                jstring result = (jstring)(*env)->CallStaticObjectMethod(env, cls, mid, arg);
                const char* str = (*env)->GetStringUTFChars(env, result, 0);
                printf("Result of sayHello: %s\n", str);
                (*env)->ReleaseStringUTFChars(env, result, 0);
            } else {
                printf("mid create failed\n");
            }
             
            /*** 新建一个对象 ***/
            // 调用默认构造函数
             
            // 调用指定的构造函数, 构造函数的名字叫做<init>
            mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
            obj = (*env)->NewObject(env, cls, mid);
            if (obj == 0) {
                printf("object create failed!\n");
            }
            /*** 新建一个对象 ***/
            // 获取属性ID, 通过属性名和签名
            fid = (*env)->GetFieldID(env, cls, "name", "Ljava/lang/String;");
            if (fid != 0) {
                const char* name = "hbhb2";
                jstring arg = (*env)->NewStringUTF(env, name);
                (*env)->SetObjectField(env, obj, fid, arg); // 修改属性
            } else {
                printf("fid create failed!\n");
            }
             
            // 调用成员方法
            mid = (*env)->GetMethodID(env, cls, "sayHello2", "()Ljava/lang/String;");
            if (mid != 0) {
                jstring result = (jstring)(*env)->CallObjectMethod(env, obj, mid);
                const char* str = (*env)->GetStringUTFChars(env, result, 0);
                printf("Result of sayHello: %s\n", str);
                (*env)->ReleaseStringUTFChars(env, result, 0);
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