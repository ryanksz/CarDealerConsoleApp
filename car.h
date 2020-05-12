#include <iostream>
#pragma once
using namespace std;


class Car {
    protected:
        string vin;
        string make;
        string model;
        int year;
        double price;
        
    public:
        Car();
        Car(string, string, string, int, double);
        
        
        string setVin(string vin);
        string getVin();

        string setMake(string make);
        string getMake();

        string setModel(string model);
        string getModel();

        int setYear(int year);
        int getYear();
        
        double setPrice(double price);
        double getPrice();
    
    
        //overload to be used to see if cars are the same
        bool operator==(const Car& secondCar) const;
        
        void printCar();

};


//Used Car

class usedCar : public Car {
    private:
        int miles;
    public:
        usedCar();
        usedCar(string, string, string, int, double, int);

        int setMiles(int);
        int getMiles();
    
    
        void printUsed();
};

//New Car

class newCar : public Car {
    private:
        string warranty;
    public:
        newCar();
        newCar(string, string, string, int, double, string w);

        string setWarranty(string w);
        string getWarranty();
    
    
        void print();
};

