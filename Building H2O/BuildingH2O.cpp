#include <functional>
#include <mutex>
#define H0_STATE  0
#define H1_STATE  1
#define O0_STATE  2
#define O1_STATE  3

class H2O {
private:
    int hydrogenState;
    int oxygenState;
    std::mutex mtx;
    std::condition_variable cv;
public:
    H2O() {
       hydrogenState =  H0_STATE;
       oxygenState   =  O0_STATE;
    }

    void hydrogen(std::function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return hydrogenState == H0_STATE || (oxygenState == O1_STATE && hydrogenState == H1_STATE);});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if (hydrogenState == H0_STATE){
            hydrogenState = H1_STATE;
        }else if (hydrogenState == H1_STATE){
             hydrogenState = H0_STATE;
             oxygenState = O0_STATE;
        }
        cv.notify_all();
    }

    void oxygen(std::function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return oxygenState == O0_STATE; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        if (oxygenState == O0_STATE)
        {
            oxygenState = O1_STATE;
        }
        cv.notify_all();
    }
};