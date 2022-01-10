#include <iostream>
#include <thread>
#include <mutex>
#include "Semaphore.h"
#include <process.h>

using namespace std;

mutex mtx;
Semaphore semaphore;

void thread1() {
    mtx.lock();

    for (char ch = 'a'; ch <= 'z'; ch++) {
        cout << ch << " ";
    }
    cout << endl;

    mtx.unlock();
}

void thread2() {
   
    mtx.lock();

    for (int i = 0; i < 33; i++) {
        cout << i << " ";
    }
    cout << endl;

    mtx.unlock();
}

void thread3() {
    mtx.lock();

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        cout << ch << " ";
    }
    cout << endl;

    mtx.unlock();
}

void mutex_init() {
    thread t1(thread1); // thread1 is running
    thread t2(thread2); // thread2 is running
    thread t3(thread3); // thread3 is running
    t1.join();  // main thread waits for t1 to finish
    t2.join();  // main thread waits for t2 to finish
    t3.join();  // main thread waits for t3 to finish
}

void semaphoreThread1() {
    semaphore.wait();
    for (char ch = 'a'; ch <= 'z'; ch++) {
        cout << ch << " ";
    }
    cout << endl;
    semaphore.post();
}

void semaphoreThread2() {
    semaphore.wait();
    for (int i = 0; i < 33; i++) {
        cout << i << " ";
    }
    cout << endl;
    semaphore.post();

}

void semaphoreThread3() {
    semaphore.wait();
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        cout << ch << " ";
    }
    cout << endl;
    semaphore.post();

}

void semaphore_init() {
    thread t1(semaphoreThread1); // thread1 is running
    thread t2(semaphoreThread2); // thread2 is running
    thread t3(semaphoreThread3); // thread3 is running
    t1.join();  // main thread waits for t1 to finish
    t2.join();  // main thread waits for t2 to finish
    t3.join();  // main thread waits for t3 to finish
}

int main() {
    semaphore_init();
   // mutex_init();

    return 0;
}