#include <iostream>
#include <map>
#include <string>

using namespace std;

class Vehicle {
public:
    string license_number;
    string owner_name;
    string owner_dob;
    string sex;
    string owner_mobile_number;
    string license_expiry_date;
    string vehicle_model;

    //Vehicle details is geting stored...
    Vehicle(string license_number, string owner_name, string owner_mobile_number, string license_expiry_date, string vehicle_model, string owner_dob, string sex) {
        this->license_number = license_number;
        this->owner_name = owner_name;
        this->owner_mobile_number = owner_mobile_number;
        this->license_expiry_date = license_expiry_date;
        this->vehicle_model = vehicle_model;
        this->owner_dob = owner_dob;
        this->sex = sex;
    }

    //virtual key word is used for Run-time polymorphism.
    virtual void addFine(string fine_type, double amount) = 0;
    
    //virtual key word is used for Run-time polymorphism.
    //To print the basic details of vehicle excluding fines details.
    virtual void displayDetails() {
        cout<<"\t\t\t"<<" _________________"<<endl;
        cout<<"\t\t\t|\t\tVEHICLE  DETAILS\t        |"<<endl;
        cout<<"\t\t\t"<<" -----------------------------------------------"<<endl;
        cout << "\t\t\t| License Number: " << this->license_number <<"\t\t\t\t|" <<endl;
        cout << "\t\t\t| Name: " << this->owner_name <<"\t\t\t\t\t|" <<endl;
        cout<< "\t\t\t| DOB:"<< this->owner_dob<<"\t\t     "<< "SEX:"<< this->sex<<"\t|"<<endl;
        cout << "\t\t\t| Expiry Date: " << this->license_expiry_date <<"\t\t\t|" <<endl;
        cout << "\t\t\t| Mobile Number: " << this->owner_mobile_number <<"\t\t\t|" <<endl;
        cout << "\t\t\t| Vehicle Model: " << this->vehicle_model <<"\t\t\t\t|" <<endl;
    }                               
};


//Car =>let this was a child class of class Vehicle.......(Inheritance is used)....
class Car : public Vehicle {
public:
    //For storing Fines of a particular car.....(map data type is used).....
    map<string, double> fines;

    Car(string license_number, string owner_name, string owner_mobile_number, string license_expiry_date, string vehicle_model,string owner_dob,string sex)
        : Vehicle(license_number, owner_name, owner_mobile_number, license_expiry_date, vehicle_model,owner_dob,sex) {
        this->fines = {{"No Seatbelt", 0}, {"Overspeeding", 0}, {"Signal Jump", 0}, {"Drunk and Drive", 0}};
    }

    //This function => used to find the fines of each category for cars.....
    void addFine(string fine_type, double amount) override {
        this->fines[fine_type] += amount;
        cout << "Fine was applied..."<<endl;
    }

    //This function =>used to display all the details of a car along with fines.......
    void displayDetails() {
        Vehicle::displayDetails();
        cout<<"\t\t\t|\t\t\t\t\t\t|"<<endl;
        cout<<"\t\t\t|\t\t\t\t\t\t|"<<endl;
        cout << "\t\t\t| Fines: "<<"\t\t\t\t\t|"<<endl;
        for(auto const& fine : this->fines) {
            if(fine.first=="Drunk and Drive" || fine.first=="Overspeeding")
                cout <<"\t\t\t| \t " <<fine.first << ": " << fine.second <<"\t\t\t|"<< endl;
            else
                cout <<"\t\t\t| \t " <<fine.first << ": " << fine.second <<"\t\t\t\t|"<< endl;
        }
        cout<<"\t\t\t"<<" _________________"<<endl;
    }
};

//Bike, Auto, and Truck
//Bike =>a child class of class vehicle.....(inheritance is used)....
class Bike : public Vehicle {
public:
    //For storing Fines of a particular bike.....(map data type is used).....
    map<string, double> fines;

    Bike(string license_number, string owner_name, string owner_mobile_number, string license_expiry_date, string vehicle_model,string owner_dob,string sex)
        : Vehicle(license_number, owner_name, owner_mobile_number, license_expiry_date, vehicle_model,owner_dob,sex) {
        this->fines = {{"No Helmet", 0}, {"Overspeeding", 0}, {"Signal Jump", 0}, {"More than 3 people", 0}};
    }

    //This function => used to find the fines of each category for Bikes.....
    void addFine(string fine_type, double amount) override {
        this->fines[fine_type] += amount;
        cout << "Fine was applied..."<<endl;
    }

    //This function =>used to display all the details of a bike along with fines.......
    void displayDetails() {
        Vehicle::displayDetails();
        cout<<"\t\t\t"<<" -----------------------------------------------"<<endl;
        cout << "\t\t\t Fines: "<<endl;
        for(auto const& fine : this->fines) {
            
                cout <<"\t\t\t \t " <<fine.first << ": " << fine.second << endl;
        }
        cout<<"\t\t\t"<<" _________________"<<endl;
    }
};

//auto =>a child class of class vehicle....(inheritance is used).....
class Auto : public Vehicle {
public:
    //For storing Fines of a particular auto.....(map data type is used).....
    map<string, double> fines;

    Auto(string license_number, string owner_name, string owner_mobile_number, string license_expiry_date, string vehicle_model,string owner_dob,string sex)
        : Vehicle(license_number, owner_name, owner_mobile_number, license_expiry_date, vehicle_model,owner_dob,sex) {
        this->fines = {{"More than 5 people", 0}, {"Overspeeding", 0}, {"Signal Jump", 0}, {"Drunk and Drive", 0}};
    }

    //This function => used to find the fines of each category for Autos.....
    void addFine(string fine_type, double amount) override {
        this->fines[fine_type] += amount;
        cout << "Fine was applied..."<<endl;
    }

    //This function =>used to display all the details of a auto along with fines.......
    void displayDetails() {
       Vehicle::displayDetails();
        cout<<"\t\t\t"<<" -----------------------------------------------"<<endl;
        cout << "\t\t\t Fines: "<<endl;
        for(auto const& fine : this->fines) {
            
                cout <<"\t\t\t \t " <<fine.first << ": " << fine.second << endl;
        }
        cout<<"\t\t\t"<<" _________________"<<endl;
    }
};

//Truck =>a child class of class Vehicle....(inheritance is used)......
class Truck : public Vehicle {
public:
    //For storing Fines of a particular truck.....(map data type is used).....
    map<string, double> fines;

    Truck(string license_number, string owner_name, string owner_mobile_number, string license_expiry_date, string vehicle_model,string owner_dob,string sex)
        : Vehicle(license_number, owner_name, owner_mobile_number, license_expiry_date, vehicle_model,owner_dob,sex) {
        this->fines = {{"Overcapacity", 0}, {"Overspeeding", 0}, {"High Pollution", 0}};
    }

    //This function => used to find the fines of each category for Trucks.....
    void addFine(string fine_type, double amount) override {
        this->fines[fine_type] += amount;
        cout << "Fine was applied..."<<endl;
    }

    //This function =>used to display all the details of a truck along with fines.......
    void displayDetails() {
        Vehicle::displayDetails();
        cout<<"\t\t\t"<<" -----------------------------------------------"<<endl;
        cout << "\t\t\t Fines: "<<endl;
        for(auto const& fine : this->fines) {
            
                cout <<"\t\t\t \t " <<fine.first << ": " << fine.second << endl;
        }
        cout<<"\t\t\t"<<" _________________"<<endl;
    }
};

int main() {
    map<string, Vehicle*> vehicles; //Initializing vehicles[] of map datatype....
    int choice;
    int vehical_type;
    string owner_dob,sex;
    string license_number, owner_name, owner_mobile_number; 
    string license_expiry_date, vehicle_model, fine_type;
    double fine_amount;
    bool exits=false;

    //For login page......
    int flag;
    while(1)
    {
        string password;
        cout<<"Login to system..."<<endl;
        cout<<"password: ";
        cin>>password;
        if(password == "12345" || password == "14789")
        {
            cout<<"login was sucessful...."<<endl;
            flag = 1;
            break;
        }
        else{
            cout << "Incorrect password..."<<endl;
            flag =0;
        }
    }

    while(flag == 1 && exits!=true) {
        
        cout << "Choose an option:"<<endl; 
        cout<<"(1) Enter new vehicle details"<<endl;
        cout<<"(2) Search a vehicle details"<<endl;
        cout<<"(3) Add fine"<<endl;
        cout<<"(4)Exit"<<endl;

        cin >> choice;


        switch(choice) {
            
            case 1://Entering details of a new vehicle.....
                //Entering the type of vehicle.....
                cout<<"Vehical type:-"<<endl;
                    
                        cout<<"(1)Car"<<endl;
                        cout<<"(2)Bike"<<endl;
                        cout<<"(3)Auto"<<endl;
                        cout<<"(4)Truck"<<endl;

                cin>>vehical_type;

                cout << "Name: ";
                cin >> owner_name;

                cout <<"Date of birth (in XX/XX/XXXX format): ";
                cin >> owner_dob;
                
                cout <<"Sex: "<<endl;
                cout<<"M =>for male"<<endl;
                cout<<"F =>for female"<<endl;
                cin >> sex;
                
                cout << "Mobile Number(10 digit length....): ";
                cin >> owner_mobile_number;

                cout << "Enter License Number(5 characters......): ";
                cin >> license_number;

                cout << "License Expiry Date(in XX/XX/XXXX format): ";
                cin >> license_expiry_date;

                cout << "Vehicle Model: ";
                cin >> vehicle_model;
                
                switch(vehical_type){

                        case 1://If the vehicle is a Car......
                            vehicles[license_number] = new Car(license_number, owner_name, owner_mobile_number, license_expiry_date, vehicle_model,owner_dob,sex);
                            cout<<"Vehicle details successfully added.........."<<endl;
                            break;
                        case 2://If the vehicle is a Bike.......
                            vehicles[license_number] = new Bike(license_number, owner_name, owner_mobile_number, license_expiry_date, vehicle_model,owner_dob,sex);
                            cout<<"Vehicle details successfully added.........."<<endl;
                            break;
                        case 3://If the vehicle is a Auto........
                            vehicles[license_number] = new Auto(license_number, owner_name, owner_mobile_number, license_expiry_date, vehicle_model,owner_dob,sex);
                            cout<<"Vehicle details successfully added.........."<<endl;
                            break;
                        case 4://If the vehicle is a Truck...
                            vehicles[license_number] = new Truck(license_number, owner_name, owner_mobile_number, license_expiry_date, vehicle_model,owner_dob,sex);
                            cout<<"Vehicle details successfully added.........."<<endl;
                            break;
                        default :
                            cout<<"Your Vechical type doesn't exist";
                
                }
                break;
            
            case 2://To print the details of a vehicle.......
                
                cout << "Enter License Number:"<<endl;
                cin >> license_number;
                //what if the license number he asked doesn't exist....
                if(vehicles[license_number]==NULL)
                {
                    cout<<"This vehicle doesn't exist....."<<endl;
                }
                else{
                    vehicles[license_number]->displayDetails();
                }
                break;
            
            case 3://To add fine to a vehicle......
                
                //To find the Vehicle type...
                cout<<"Vehical type:-"<<endl;
                    
                        cout<<"(1)Car"<<endl;
                        cout<<"(2)Bike"<<endl;
                        cout<<"(3)Auto"<<endl;
                        cout<<"(4)Truck"<<endl;

                cin>>vehical_type;
                cout << "Enter License Number :"<<endl;
                cin >> license_number;
                switch(vehical_type){

                        case 1://If the vehicle is Car....
                            cout << "Fine Type (No Seatbelt, Overspeeding, Signal Jump, Drunk and Drive)"<<endl;
                            cin.ignore();  //fine type/category is selected...
                            getline(cin,fine_type);

                            cout << "Enter Fine Amount :"<<endl;
                            cin >>fine_amount;
                            //Updating/adding of the fines
                            vehicles[license_number]->addFine(fine_type, fine_amount);
                
                            break;
                        
                        case 2://If the vehicle is Bike....
                            cout << "Fine Type (No Helmet, Overspeeding, Signal Jump, More than 3 people)"<<endl;
                            cin.ignore();  //fine type/category is selected...
                            getline(cin,fine_type);

                            cout << "Enter Fine Amount :"<<endl;
                            cin >>fine_amount;
                            //Updating/adding of the fines
                            vehicles[license_number]->addFine(fine_type, fine_amount);
                            break;
                        
                        case 3://If the vehicle is Auto....
                            cout << "Fine Type (More than 5 people, Overspeeding, Signal Jump, Drunk and Drive)"<<endl;
                            cin.ignore();   //fine type/category is selected...
                            getline(cin,fine_type);

                            cout << "Enter Fine Amount :"<<endl;
                            cin >>fine_amount;
                            //Updating/adding of the fines
                            vehicles[license_number]->addFine(fine_type, fine_amount);
                            break;
                        
                        case 4://If the vehicle is Truck....
                            cout << "Fine Type (Overcapacity, Overspeeding, High Pollution)"<<endl;
                            cin.ignore(); //fine type/category is selected...
                            getline(cin,fine_type);

                            cout << "Enter Fine Amount :"<<endl;
                            cin >>fine_amount;
                            //Updating/adding of the fines
                            vehicles[license_number]->addFine(fine_type, fine_amount);
                            break;
                        default :
                            cout<<"Your Vechical type doesn't exist";
                }
                break;

            case 4://To ext the program........

                cout << "You exited sucessfully....." <<endl;
                exits = true;
                break;                    
            
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
    return 0;
}
