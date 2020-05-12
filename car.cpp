#include "car.h"
#include <fstream>


//default constructor
Car :: Car() {
    vin = "0";
    make = "none";
    model = "none";
    year = 0;
    price = 0.0;
    
}

//This will set the stuff for the cars
Car :: Car(string v, string ma, string mo, int y, double p) {
    vin = v;
    make = ma;
    model = mo;
    year = y;
    price = p;
   
}

string Car :: setVin(string v) {
    v = vin;
    return v;
}

string Car :: setMake(string m) {
    m = make;
    return m;
}

string Car :: setModel(string mo) {
    mo = model;
    return mo;
}

int Car :: setYear(int y) {
    y = year;
    return y;
}

double Car :: setPrice(double p) {
    p = price;
    return p;
}

string Car :: getVin()  {
    return vin;
}

string Car :: getMake() {
    return make;
}

string Car :: getModel() {
    return model;
}

int Car :: getYear() {
    return year;
}

double Car :: getPrice() {
    return price;
}




//implement the == overload
bool Car::operator == (const Car& secondCar) const {
    return(vin == secondCar.vin);
}



void Car :: printCar() {
    cout << "Make: " << getMake() << endl;
    cout << "Model: " << getModel() << endl;
    cout << "Vin: " << getVin() << endl;
    cout << "Year: " << getYear() << endl;
    cout << "Price: $" << getPrice() << endl;
    
    
}

//Used Car
usedCar :: usedCar() : Car() {
    miles = 0;
}

usedCar :: usedCar(string v, string ma, string mo, int y, double p , int m) :
    Car(v, ma, mo, y, p) {
    
    miles = m;
}

int usedCar :: setMiles(int m) {
    m = miles;
    return m;
}

int usedCar :: getMiles () {
    return miles;
}

void usedCar::printUsed() {
    Car::printCar();
    cout << "Miles: " << getMiles() << endl;
    cout << endl;
}






//New Car

newCar :: newCar() :Car() {
    warranty = "none";
}

newCar :: newCar(string v, string ma, string mo, int y, double p , string w) :
    Car(v, ma, mo, y, p) {
    
    warranty = w;
}

string newCar :: setWarranty(string w) {
    w = warranty;
    return w;
}

string newCar :: getWarranty () {
    return warranty;
}


void newCar::print() {
    Car::printCar();
    cout << "Warranty: " << getWarranty() << endl;
    cout << endl;
}


