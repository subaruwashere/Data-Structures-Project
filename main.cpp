#include<iostream>
using namespace std;

//patient node class representing individual records				//=====Data Structures Project=====
class Patient{														//=====Afraz Haider 72935=====
	public:															//=====Ali Azhar 74095=====
		int patientId;
		string name;
		int age;
		string disease;
		string contact_number;
		Patient *next;
		
		//Constructor
		Patient(int id, string n, int a, string dis, string contact){
			patientId = id;
			name = n;
			age = a;
			disease = dis;
			contact_number = contact;
			next = NULL;
		}
};

class HospitalSystem{
	private:
		Patient* front;
		Patient* rear;
		int patientCount;
	
	public:
		//Constructor
		HospitalSystem(){
			front = NULL;
			rear = NULL;
			patientCount = 0;
		}
		// values initialized
		
		
};
int main(){
	int choice;
	do{
		cout<<"\n===================================\n";
		cout<<"    Hospital Management System\n";
		cout<<"===================================\n";
		cout<<"1. Add Patient\n";
		cout<<"2. Serve Patient\n";
		cout<<"3. Search Patient\n";
		cout<<"4. Update Patient\n";
		cout<<"5. Remove Patient\n";
		cout<<"6. Display Waiting Patients\n";
		cout<<"7. Count Patients\n";
		cout<<"8. Exit\n";
		cout<<"------------------------------\n";
		cout<<"Enter your choice (1-8): ";
		cin>>choice;
		
		if(choice>8 || choice < 1){
			cout<<"Invalid Input! PLease enter a number between 1 and 8.\n";
			cin.clear();	//to prevent error by wrong input
			cin.ignore(1000, '\n');	//clears buffer
			continue;
		}
		
		switch(choice){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				cout<<"Exiting Program.....\n";
				break;
		}
	}while(choice!= 8);
	
	return 0;
}