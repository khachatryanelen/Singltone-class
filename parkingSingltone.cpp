#include <iostream>
#include <mutex>

class ParkingSingltone {
private:
    static ParkingSingltone* instance;
    static std::mutex mtx;

    int parkedCars;

    ParkingSingltone() : parkedCars(0) {}

public:
    static ParkingSingltone& getInstance() {
        std::lock_guard<std::mutex> lock(mtx);

        if (instance == nullptr) {
            instance = new ParkingSingltone();
        }

        return *instance;
    }

    void park() {
        std::lock_guard<std::mutex> lock(mtx);
        parkedCars++;
    }

    int getCount() {
        std::lock_guard<std::mutex> lock(mtx);
        return parkedCars;
    }
};

ParkingSingltone* ParkingSingltone::instance = nullptr;
std::mutex ParkingSingltone::mtx;

int main() {

    ParkingSingltone& p1 = ParkingSingltone::getInstance();
    ParkingSingltone& p2 = ParkingSingltone::getInstance();

    p1.park();
    p2.park();

    std::cout << p1.getCount()<<std::endl;

    return 0;
}