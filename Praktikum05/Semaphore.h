#ifndef MULTITHREADING_SEMAPHORE_H
#define MULTITHREADING_SEMAPHORE_H
#include <mutex>
#include <condition_variable>

class Semaphore {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int signal;

public:
    Semaphore(int signal_ = 1)
        : signal(signal_)
    {
    }

    /**
     * atomic function
     */
    inline void post() {
        std::unique_lock<std::mutex> lock(mtx);
        signal++;
        //notify the waiting thread
        //unblock(), waiting queue it not empty, wake up call thread from waiting queue
        cv.notify_one();
        /** Notify one
         * Unblocks one of the threads currently waiting for this condition.
         * If no threads are waiting, the function does nothing.
         */
    }
    /**
     * atomic function
     */
    inline void wait() {
        std::unique_lock<std::mutex> lock(mtx);
        if (signal <= 0) {
            // wait on the mutex until notify is called
            // block(), put this thread into waiting status, sleep and put in waiting queue
            cv.wait(lock);
        }
        if (signal > 0) {
            signal--;
        }
    }

};
#endif //MULTITHREADING_SEMAPHORE_H
