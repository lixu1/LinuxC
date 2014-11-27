线程相关函数
==================

遇到问题：
===============================
undefined reference to 'pthread_create'
undefined reference to 'pthread_join'
--------------------
问题原因：
    pthread 库不是 Linux 系统默认的库，连接时需要使用静态库 libpthread.a，所以在使用pthread_create()创建线程，以及调用 pthread_atfork()函数建立fork处理程序时，需要链接该库。

问题解决：
    在编译中要加 -lpthread参数
    gcc thread.c -o thread -lpthread
    thread.c为你些的源文件，不要忘了加上头文件#include<pthread.h>
./5_thread_exit_status
运行结果中的第一个线程的退出信息是一些无用值，原因是该线程使用局部变量存储信息结构。后面的3个线程分别使用malloc函数分配内存，全局变量，main函数的局部变量的方式存储退出信息。可保证退出信息结构存储区域的有效性。

