/*
Car inventory system
Ryan Kaszubski 
*/

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "car.h"

using namespace std;

//globals
//so every function an access the car inventory vector

//new cars
vector<newCar*> newCars;
//used cars
vector<usedCar*> usedCars;
//leased new cars
vector<newCar*> leased;
//sold used cars
vector<usedCar*> sold;


void loadCars() {
    
    //This loads 5 new and used cars into the inventory
    
    //newCar(string v, string ma, string mo, int y, double p , string w)
    newCars.push_back(new newCar("U8tboymgOf", "Ford", "Focus", 2018, 18000.00, "Ford Warranty"));
    
    newCars.push_back(new newCar("zw7X5cGxRe", "Chevy", "Cruize", 2019, 20000.00, "Chevy Warranty"));
    
    newCars.push_back(new newCar("BYBnkVrkhc", "Tesla", "Model M", 2020, 40000.00, "Tesla Warranty"));
    
    newCars.push_back(new newCar("8E3dfRa3fJ", "Proche", "911 Carrera", 2020, 97000.00, "Expensive car warranty"));
    
    newCars.push_back(new newCar("odwLNoc1ak", "Chevy", "Equinox", 2020, 23000.00, "Ripoff warranty"));
    
    
    //usedCar(string v, string ma, string mo, int y, double p , int m)
    usedCars.push_back(new usedCar("smjdROfCzY", "Ford", "Tarus", 2017, 21774.00, 13898));
    
    usedCars.push_back(new usedCar("VBOSIREpyD", "Jeep", "Compass", 2018, 19995.00, 16827));
    
    usedCars.push_back(new usedCar("gCI7pGspu8", "Dodge", "Durango", 2017, 24094.00, 47751));
    
    usedCars.push_back(new usedCar("Q3dzSVDW6q", "Honda", "Accord", 2017, 19999.99, 16852));
    
    usedCars.push_back(new usedCar("WywvmAJfz2", "Volkswagen", "Jetta", 2013, 10248.00, 17563));
}

void search(string type) {
    
    //the search will be done using the cars vin number
    //print that specific car
   
    
    
    bool found = false;
    
    string vin;
    string make;
    string model;
   
    //search using vin
    
    if(type == "Vin" || type == "vin") {
        cout << "Enter the vin: ";
        cin >> vin;
        cout << endl;
        cout << "Searching by vin" << endl;
    for(int i = 0; i < newCars.size(); i++) {
        if((*newCars[i]).getVin() == vin) {
            cout << "Found " << vin << endl;
             (*newCars[i]).print();
             found = true;
        }
    }
    
    for(int j = 0; j < usedCars.size(); j++) {
        if((*usedCars[j]).getVin() == vin) {
            cout << "Found " << vin << endl;
            (*usedCars[j]).printUsed();
            found = true;
        }
    }
    
}
    //search by make
    else if(type == "Make" || type == "make") {
        cout << "Enter the make: ";
        cin >> make;
        cout << endl;
        cout << "Searching by make" << endl;
        for(int i = 0; i < newCars.size(); i++) {
            if((*newCars[i]).getMake() == make) {
                cout << "Found " << make << endl;
                 (*newCars[i]).print();
                 found = true;
            }
        }
        
        for(int j = 0; j < usedCars.size(); j++) {
            if((*usedCars[j]).getMake() == make) {
                cout << "Found " << make << endl;
                (*usedCars[j]).printUsed();
                found = true;
            }
        }
        
        
    }
    //search by model
    else if(type == "Model" || type == "model") {
        cout << "Enter the model: ";
        cin >> model;
        cout << endl;

        cout << "Searching by model" << endl;
        for(int i = 0; i < newCars.size(); i++) {
            if((*newCars[i]).getModel() == model) {
                cout << "Found " << model << endl;
                 (*newCars[i]).print();
                 found = true;
            }
        }
        
        for(int j = 0; j < usedCars.size(); j++) {
            if((*usedCars[j]).getModel() == model) {
                cout << "Found " << model << endl;
                (*usedCars[j]).printUsed();
                found = true;
            }
        }
        
       
    }
    //display all used cars
    else if(type == "Used" || type == "used") {
        cout << "Used Cars" << endl;
        cout << "-----------" << endl;
        for(int j = 0; j < usedCars.size(); j++) {
            (*usedCars[j]).printUsed();
            found = true;
        }
        cout << endl;
    }
    //display all new cars
    else if(type == "New" || type == "new") {
        cout << "New Cars" << endl;
        cout << "-----------" << endl;
        for(int i = 0; i < newCars.size(); i++) {
            (*newCars[i]).print();
            found = true;
        }
        cout << endl;
    }
    //error if nothing is found
    else if(found != true) {
    
     throw logic_error("Error: Not found");
     }
    
    
    
}

void leaseCar(string type) {
    //search for the car by vin
    //put it into the sell and lease vectors
    string vin;
    bool found = false;
    cout << "Enter the vin to search for: ";
    cin >> vin;
    cout << endl;
    
    
    
      //lease new cars
      //searches by vin
    
        cout << "Searching by vin" << endl;
        for(int i = 0; i < newCars.size(); i++) {
            if((*newCars[i]).getVin() == vin) {
                cout << "Leasing... " << vin << endl;
                //puts the car into the leased vector
                leased.push_back((newCars[i]));
                //removes the car from the newCar vector
                newCars.erase(newCars.begin() + i);
                found = true;
            }
        }
        
        
    
    if(found != true) {
        throw logic_error("Error, car not found");
    }
  

}

void sellCar(string type) {
    string vin;
    bool found = false;
    cout << "Enter the vin to search for: ";
    cin >> vin;
    cout << endl;
    
    //sell used cars

        
        cout << "Searching by vin" << endl;
        for(int i = 0; i < usedCars.size(); i++) {
            if((*usedCars[i]).getVin() == vin) {
                cout << "Leasing... " << vin << endl;
                //puts the car into the leased vector
                sold.push_back((usedCars[i]));
                //removes the car from the newCar vector
                usedCars.erase(usedCars.begin() + i);
                found = true;
            }
        }
        if(found != true) {
        throw logic_error("Error, car not found");
    }
}

void returnLeasedCar() {
        //search for the car by vin
        //simply moves the car from the leased vector to the new car vector
        string vin;
        bool found = false;
        cout << "Enter the vin to search for: ";
        cin >> vin;
        cout << endl;
           
    
    cout << "Searching by vin" << endl;
        for(int i = 0; i < leased.size(); i++) {
            if((*leased[i]).getVin() == vin) {
                cout << "Returning... " << vin << endl;
                //puts the car into the used cars vector
                newCars.push_back((leased[i]));
                //removes the car from the newCar vector
                leased.erase(leased.begin() + i);
                found = true;
                }
            }
            
            
        
        if(found != true) {
            throw logic_error("Error, car not found");
        }
      
}
    

void addCar() {
    
    //Add a new car to the system
    string addVin;
    string addMake;
    string addModel;
    int addYear;
    double addprice;
    string addWarranty;
    int addMiles;
    
    int usedOrNew;
    cout << "Is this new (1) or used (2)? ";
    cin >> usedOrNew;
    
    
        try {
            
            if(usedOrNew == 1) {
                cout << "Enter a vin: ";
                cin >> addVin;
                cout << endl;
                
                cout << "Enter a make: ";
                cin >> addMake;
                cout << endl;
                
                cout << "Enter a model: ";
                cin >> addModel;
                cout << endl;
                
                cout << "Enter a year: ";
                cin >> addYear;
                cout << endl;
                
                cout << "Enter a price: ";
                cin >> addprice;
                cout << endl;
                
                cout << "Enter a warranty: ";
                cin >> addWarranty;
                cout << endl;
                
                //Loop through new cars to see if vin is matching
                //from overload
                
                
                for(int i = 0; i < newCars.size(); i++) {
                    if((*newCars[i]).getVin() == addVin) {
                        throw logic_error("Error, car already present");
                    }
                
                }
                newCars.push_back(new newCar(addVin, addMake, addModel, addYear, addprice, addWarranty));
                
            }
                
                else if(usedOrNew == 2) {
                    cout << "Enter a vin: ";
                    cin >> addVin;
                    cout << endl;
                    
                    cout << "Enter a make: ";
                    cin >> addMake;
                    cout << endl;
                    
                    cout << "Enter a model: ";
                    cin >> addModel;
                    cout << endl;
                    
                    cout << "Enter a year: ";
                    cin >> addYear;
                    cout << endl;
                    
                    cout << "Enter a price: ";
                    cin >> addprice;
                    cout << endl;
                    
                    cout << "Enter miles: ";
                    cin >> addMiles;
                    cout << endl;
                    
                    for(int i = 0; i < usedCars.size(); i++) {
                    if((*usedCars[i]).getVin() == addVin) {
                        throw logic_error("Error, car already present");
                        }
                    }
                    
                    usedCars.push_back(new usedCar(addVin, addMake, addModel, addYear, addprice, addMiles));

                    
                    
                }
                else{
                    throw logic_error("Error!! Please enter 1 for new, 2 for used");
                }
            
            }
         catch (logic_error &e) {
             cout << "----------------" << endl;
             cout << e.what() << endl;
             cout << endl;
        }
    
}
    


void showCars() {
    //just looops through the vector and displays everything
    cout << "New Cars" << endl;
    cout << "-----------" << endl;
    for(int i = 0; i < newCars.size(); i++) {
        (*newCars[i]).print();
    }
    cout << endl;
    cout << "Used Cars" << endl;
    cout << "-----------" << endl;
    for(int j = 0; j < usedCars.size(); j++) {
        (*usedCars[j]).printUsed();
    }
    cout << endl;
    
    cout << "Leased Cars" << endl;
    cout << "-----------" << endl;
    for(int k = 0; k < leased.size(); k++) {
        (*leased[k]).print();
    }
    cout << endl;
    
    cout << "Sold Cars" << endl;
    cout << "-----------" << endl;
    for(int l = 0; l < sold.size(); l++) {
        (*sold[l]).printUsed();
    }
    cout << endl;
    
    cout << "End of list" << endl;
    cout << "-----------" << endl;
    cout << endl;
}

void priceRange(int start, int finish) {
    
    bool inRange = false;
    cout << "Prices between " << start << " and " << finish << endl;
    //first check
    for(int i = 0; i < newCars.size(); i++) {
        if((*newCars[i]).getPrice() >= start && (*newCars[i]).getPrice() <= finish) {
            (*newCars[i]).print();
            inRange = true;
        }
    }
    
    for(int i = 0; i < usedCars.size(); i++) {
        if((*usedCars[i]).getPrice() >= start && (*usedCars[i]).getPrice() <= finish) {
            (*usedCars[i]).printUsed();
            inRange = true;
        }
    }
    
    if(inRange != true) {
        throw logic_error("None found");
    }
    
}


int main () {
   
    string userChoice;
   
    usedCar u;
    newCar n;
    
    //load cars to inventory
    loadCars();
    
    while(userChoice != "0") {
        
        cout << "Ryan's Car Dealership system" << endl;
        cout << "----------------------------" << endl;
        
        cout << "Main Menu" << endl;
        
        cout << "Please select option by number: " << endl;
        
        cout << "1. Search inventory" << endl;
        
        cout << "2. Sell/Lease a car" << endl;
        
        cout << "3. Return a car" << endl;
        
        cout << "4. Add car to inventory" << endl;
        
        cout << "5. Show Inventory" << endl;
        
        cout << "6. List in given price range" << endl;
        
        cout << "0. End program" << endl;
        
        cout << "Please select an option: ";
        cin >> userChoice;
        cout << endl;
        
        if(userChoice == "1") {
            string searchChoice;
           
            try {
                
                cout << "Search by make, model, new, used or vin: ";
                cin >> searchChoice;
                cout << endl;
                
                if(searchChoice == "Make" || searchChoice == "make" ||
                   searchChoice == "Model" || searchChoice == "model" ||
                   searchChoice == "New" || searchChoice == "new" ||
                   searchChoice == "Used" || searchChoice == "used" ||
                   searchChoice == "Vin" || searchChoice == "vin") {
                    
                    search(searchChoice);
                }
                else {
                    throw logic_error("Error, type make, model, new, used or vin.");
                }
                
                
                
            } catch (logic_error l) {
                cout << l.what();
                cout << endl;
            }
        }
        
        else if(userChoice == "2") {
            string newOrUsed;
            try {
                   
                   
                   cout << "Is the car new or used: ";
                   cin >> newOrUsed;
                   
                   if(newOrUsed == "New" || newOrUsed == "new") {
                       
                       leaseCar(newOrUsed);
                   }
                   
                   else if(newOrUsed == "Used" || newOrUsed == "used") {

                       sellCar(newOrUsed);
                       
                   }
                   else {
                       throw logic_error("Error: enter used or new.");
                   }
                   
                   
                   
               } catch (logic_error l) {
                   cout << l.what();
                   cout << endl;
               }
            
        
        }
        
        else if(userChoice == "3") {
           
            try {
                   
                returnLeasedCar();
                
            } catch (logic_error l) {
                   cout << l.what();
                   cout << endl;
               }
        }
        
        else if(userChoice == "4") {
            addCar();
        }
        
        else if(userChoice == "5") {
            showCars();
        }
        
        else if(userChoice == "6") {
            int low;
            int high;
            try {
              cout << "Enter the lowest price: ";
              cin >> low;
              cout << endl;
                
              cout << "Enter the lowest high: ";
              cin >> high;
              cout << endl;
                
              priceRange(low, high);
                
                
                
            } catch (logic_error l) {
                cout << l.what() << endl;
            }
            
            
            
            
        }
        
        
        else if(userChoice == "0") {
            cout << "Ending program..." << endl;
        }
        
        else {
            cout << "Error, please selection option 1 - 6 or 0" << endl;
        }
        
    }
    
    return 0;
}
