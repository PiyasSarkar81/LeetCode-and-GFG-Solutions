class ParkingSystem {
public:
    int big;
    int b=0;
    int midium;
    int m=0;
    int small;
    int s=0;
    ParkingSystem(int big, int midium, int small) {
        this->big = big;
        this->midium = midium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if(carType==1 && b<big){
                b++;
                return true;
        }else if(carType==2 && m<midium){
                m++;
                return true;
        }else if(carType==3 && s<small){
                s++;
                return true;
        }else {
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */