//NULL Object Design Pattern

#include <iostream>
using namespace std;

class Vehicle
{
    public:
    virtual void tankCapacity() = 0;
    virtual void sittingCapacity() = 0;
};

class Car : public Vehicle
{
    public:
    void tankCapacity() {
        cout << "Tank capacity of car: 40L" << endl;
    }
    
    void sittingCapacity() {
        cout << "Sitting capacity of car: 5" << endl;
    }
};

class Bike : public Vehicle
{
    public:
    void tankCapacity() {
        cout << "Tank capacity of bike: 10L" << endl;
    }
    
    void sittingCapacity() {
        cout << "Sitting capacity of car: 2" << endl;
    }
};

class NullVehicle : public Vehicle
{
    public:
    void tankCapacity() {
        cout << "Tank capacity of NullVehicle: 0L" << endl;
    }
    
    void sittingCapacity() {
        cout << "Sitting capacity of NullVehicle: 0" << endl;
    }
};

class VehicleFactory
{
    public:
    Vehicle* getVehicle(string userInput) {
        if(userInput == "Car")
            return (new Car);
            
        else if(userInput == "Bike")
            return (new Bike); 
            
        else
            return (new NullVehicle);
    }
};

int main() {
	VehicleFactory *vehicleMaker = new VehicleFactory;
	Vehicle *VehicleObjPtr;
	
	VehicleObjPtr = vehicleMaker->getVehicle("Car");
	VehicleObjPtr->sittingCapacity();
	
	VehicleObjPtr = vehicleMaker->getVehicle("Bike");
	VehicleObjPtr->tankCapacity();
	
	VehicleObjPtr = vehicleMaker->getVehicle("Scooty");
	VehicleObjPtr->sittingCapacity();
	return 0;
}