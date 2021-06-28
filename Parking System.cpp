#include <iostream>
#include<bits/stdc++.h>
#include <windows.h>
using namespace std;

class Car{
public:
    string name;
    long int contactNo;
};

Car generateNewParking(){
    Car newCar;
    string name;
    long int num;
    cout<<"\t\t\t\t\tEnter your Name: ";
    // getline(cin, name);
    cin>>name;
    newCar.name = name;
    cout<<"\t\t\t\t\tEnter your Contact Number: ";
    cin>>num;
    newCar.contactNo = num;
    return newCar;
}

bool deleteCar(map<int, Car> &carsData){
    int uniqueID;
    cout<<"\t\t\t\t\tEnter your Unique Parking Id: ";
    cin>>uniqueID;
    auto it = carsData.find(uniqueID);
    if(it == carsData.end()){
        cout<<"\t\t\t\tUnique Id does not Exist, Please check once again!"<<endl<<endl;
        return false;
    }
    Car car = carsData[uniqueID];
    cout<<"\t\t\t\t\tName: "<<car.name<<endl;
    cout<<"\t\t\t\t\tContact Number: "<<car.contactNo<<endl;
    cout<<"\t\t\t\t\tPress 1 if Information is correct, else press 0 : ";
    int isYourCar;
    cin>>isYourCar;
    if(isYourCar == 1){
        carsData.erase(uniqueID);
        cout<<"\t\t\t\tYour Tichet is successfully deregistered !"<<endl<<endl;
        return true;
    }
    else{
        cout<<"\t\t\t\tPlease check your Unique Id!"<<endl<<endl;
        return false;
    }
}

void showDetails(){
    cout<<endl;
    cout<<"\t\t\t\tFor Bicycles:    10 rupees/hour per vehicle"<<endl;
    cout<<"\t\t\t\tFor Bikes:       20 rupees/hour per vehicle"<<endl;
    cout<<"\t\t\t\tFor Sedan Cars:  30 rupees/hour per vehicle"<<endl;
    cout<<"\t\t\t\tFor SUV Cars:    40 rupees/hour per vehicle"<<endl;
    cout<<"\t\t\t\tFor Pickups:     50 rupees/hour per vehicle"<<endl;
}

int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    int totalCars = 100, currCars = 0, menuChoose, runMainLoop = 1,uniqueID = 4689;
    map<int, Car> carsData;
    cout<<endl<<endl;
    while(runMainLoop){

        cout<<endl;
        cout<<"\t\t\t1 > Check Availability of Slot"<<endl;
        cout<<"\t\t\t2 > Check Parking Fees Details"<<endl;
        cout<<"\t\t\t3 > Generate New Parking Ticket"<<endl;
        cout<<"\t\t\t4 > Deregister your car"<<endl;
        cout<<"\t\t\t5 > Exit Menu"<<endl<<endl;
        cout<<"\t\t\t\tChoose Option: ";
        cin>>menuChoose;
        if(menuChoose==5){
            break;
        }
        switch(menuChoose){
    case 1:
        {
            int availableSlots = totalCars - currCars;
            cout<<endl;
            if(availableSlots == 0){
                cout<<endl<<"\t\t\t\t>>> Sorry to Say, No Parking Slots is Available!"<<endl<<endl;
            }
            else{
                cout<<"\t\t\t\t>>> "<<availableSlots<<" slots are available"<<endl<<endl;
            }
        }
        break;
    case 2:
        {
            showDetails();
        }
        break;
    case 3:
        {
            cout<<"\t\t\t\tGenerating New Parking Ticket"<<endl;
            Car newCar = generateNewParking();
            cout<<endl<<"\t\t\t\tUnique Parking Id: "<<uniqueID<<" , DO NOT FORGET"<<endl<<endl;;
            carsData[uniqueID--] = newCar;
            currCars++;
        }
        break;
    case 4:
        {
            cout<<"\t\t\t\tDeregister Ticket"<<endl;
            if(deleteCar(carsData)){
                currCars--;
            }
        }
        break;
    default:
        {
            cout<<"\t\t\t\tPlease Choose a Valid Option!"<<endl<<endl;
        }
        }
    }
    return 0;
}