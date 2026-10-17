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
		
		//1. Add Patient
		void addPatient(){
			int id, age;
			string name, disease, contact_number;
			
			cout<<"-----Add New Patient-----\n";
			cout<<"Enter Patient ID: ";
			while(!(cin >> id)){
				cout<<"Invalid Input! Enter Numeric ID: ";
				cin.clear();				//prevents errors
				cin.ignore(10000, '\n');		//clears buffer
			}
			
			cout<<"Enter Name: ";
			cin.ignore();
			getline(cin, name); 	//to read whole input including spaces
			
			cout<<"Enter Age: ";
			while(!(cin >> age || age < 1)){
				cout<<"Invalid Age! Enter a Valid Age: ";
				cin.clear();
				cin.ignore(10000, '\n');	//clear buffer
			}
			
			cout<<"Enter Disease/Condition: ";
			cin.ignore();
			getline(cin, disease); //read full sentence
			
			cout<<"Enter Contact Number: ";
			getline(cin, contact_number);
		
		
			//add to queue
			Patient* newPatient = new Patient(id, name, age, disease, contact_number);
			
			if(rear == NULL){
				front = rear = newPatient;
			}
			else{
				rear->next = newPatient;
				rear = newPatient;
			}
			patientCount++; 	//increase count of patients by 1
			
			cout<<"Patient Added to the waiting queue successfully!\n\n";
		}
		//----------------------------------------------------------------------------
		
		//2. Serve Patient
		void servePatient(){
			if(front == NULL){
				cout<<"No patients in the waiting queue\n";
				return;
			}
			Patient* temp = front;
			cout<<"-----Serving Patient-----\n";
			cout<<"ID: "<<temp->patientId<<"\n";
			cout<<"Name: "<<temp->name<<"\n";
			cout<<"Age: "<<temp->age<<"\n";
			cout<<"Disease: "<<temp->disease<<"\n";
			cout<<"---------------------------\n";
			
			front = front->next;
			
			//if front becomes null, rear must also be null
			if(front == NULL){
				rear = NULL;
			}
			delete temp;
			patientCount--; //decrease patient count by 1
			cout<<"Patient is served and removed from the queue!";
		}
		
		//helping function for searching by id (for internal use)
		Patient* searchPatientByID(int id, bool display = true){
			Patient* current = front;
			while( current != NULL){
				if(current->patientId == id){
					if(display){
						cout<<"-----Patient Found-----\n";
						cout<<"ID:      "<<current->patientId<<endl;
						cout<<"Name:    "<<current->name<<endl;
						cout<<"Age:     "<<current->age<<endl;
						cout<<"Disease: "<<current->disease<<endl;
						cout<<"Contact: "<<current->contact_number<<endl;
					}
					return current;
				}
				current = current->next;
			}
			if(display)
				cout<<"Patient Not Found! Try a different ID.\n";
			return NULL;
		}
		
		//3. Search Patient
		void searchPatient(){
			int id;
			cout<<"Enter Patient ID to search: ";
			cin>>id;
			searchPatientByID(id, true);
		}
};
int main(){
	HospitalSystem system;
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
				system.addPatient();
				break;
			case 2:
				system.servePatient();
				break;
			case 3:
				system.searchPatient();
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