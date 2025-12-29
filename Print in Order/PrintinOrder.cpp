#include <functional>
#include <mutex>
class Foo {
private:
    int step;
    std::mutex mtx;
    std::condition_variable cv;

public:
    Foo() { step = 1 ;}

    void first(std::function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        step ++;
        cv.notify_all();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return step == 2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        step ++;
        cv.notify_all();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return step == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};