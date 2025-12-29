#include <mutex>
#include <functional>
#define ZERO_STATE 0
#define ODD_STATE  1
#define EVEN_STATE 2

class ZeroEvenOdd {
private:
    int n;
    int state;
    int currentNumber;
    std::mutex mtx;
    std::condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        state = 0;
        state = ZERO_STATE;
        currentNumber = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        for (int i = 0 ; i < n; ++i)
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] { return state == ZERO_STATE;});
            printNumber(0);
            if ( currentNumber % 2 == 0)
            {
               state = EVEN_STATE; 
            }else{
                state = ODD_STATE;
            }
            cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        while(1)
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{return state == EVEN_STATE || currentNumber > n;});
            if (currentNumber > n) return;
            printNumber(currentNumber++);
            state = ZERO_STATE;
            cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        while(1)
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{return state == ODD_STATE || currentNumber > n;});
            if (currentNumber > n) return;
            printNumber(currentNumber++);
            state = ZERO_STATE;
            cv.notify_all();
        }
    }
};