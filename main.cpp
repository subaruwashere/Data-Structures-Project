#include<iostream>
using namespace std;

//patient node class representing individual records
class Patient{
	public:
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
int main(){
	return 0;
}