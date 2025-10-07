#include <bits/stdc++.h>

using namespace std;

void thread_work1(const string &str) {
    cout << "str is " << str << endl;
}

class background_task {
public:
    void operator()() {
        std::cout << "background_task called" << std::endl;
    }
};

int main() {
    string str1 = "hello";
    // 1、初始化一个线程
    thread t1(thread_work1, str1);
    // 2、主线程等待子线程退出，主线程等子线程执行完成才接着执行
    t1.join();

    // 3、仿函数
    thread t2((background_task()));
    t2.join();

    // 4、lambda表达式
    thread t3([](const string &str) {
        cout << "str is" << str << endl;
    },
              str1);
    t3.join();
    return 0;
}