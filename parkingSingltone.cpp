#include <iostream>

class ParkingSingltone{
private:
    static ParkingSingltone* instance;
    int parkedCars;
    

    ParkingSingltone() : parkedCars(0){}
    
public:
    static ParkingSingltone& getInstance(){
        if(instance==nullptr){
            instance=new ParkingSingltone();
        }
        return *instance;
    }
    
    void park(){
        parkedCars++;
    }
    
    int getCount(){
        return parkedCars;
    }
    
};
ParkingSingltone* ParkingSingltone::instance=nullptr;


int main(int argc,const char* argv[]){

    ParkingSingltone& p1 = ParkingSingltone::getInstance();
    ParkingSingltone& p2 = ParkingSingltone::getInstance();

    p1.park();
    p2.park();

    std::cout << p1.getCount(); 
    
    return 0;
}