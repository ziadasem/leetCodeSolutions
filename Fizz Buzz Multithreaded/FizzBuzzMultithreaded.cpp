#include <functional>
#include <mutex>
class FizzBuzz {
private:
    int n;
    int i;
    std::mutex mtx;
    std::condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(std::function<void()> printFizz) {
        while(i <= n)
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{ return ( (i % 3 == 0 && i % 5 != 0) || (i > n)) ;});
            if (i > n) break;
            printFizz();
            i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(std::function<void()> printBuzz) {
        while(i <= n)
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{ return (i % 3 != 0 && i % 5 == 0) || (i > n) ;});
            if (i > n) break;
            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(std::function<void()> printFizzBuzz) {
        while(i <= n)
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{ return (i % 3 == 0 && i % 5 == 0) || (i > n) ;});
            if (i > n) break;
            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(std::function<void(int)> printNumber) {
        while(i<= n)
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{ return (i % 3 != 0 && i % 5 != 0) || (i > n);});
            if (i > n) { return;}
            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};