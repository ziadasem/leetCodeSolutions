#include <functional>
#include <mutex>
class FooBar {
private:
    std::mutex mtx;
    std::condition_variable cv;
    bool waitForBar;
    int n;

public:
    FooBar(int n) {
        this->n = n;
        waitForBar = false;
    }

    void foo(std::function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] { return waitForBar == false;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            waitForBar = true;
            cv.notify_one();
        }
    }

    void bar(std::function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] { return waitForBar == true;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();  
            waitForBar = false;
            cv.notify_one(); 
        }
    }
};