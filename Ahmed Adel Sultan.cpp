#include<iostream>

using namespace std;


class EmployeesData{
	struct Employee{
		string id , firstName , lastName , category , mode;
		double salary;
		Employee *next;
	};
	
	Employee *head;
	Employee *teal;
	int length=0;
	
	public :
		EmployeesData(string firstName , string lastName , string id , double salary , string category){
			
			Employee *newEmployee= new Employee;
			firstName=="admin" ? newEmployee->mode="admin" : newEmployee->mode="guest";
			newEmployee->firstName=firstName;
			newEmployee->lastName=lastName;
			newEmployee->id=id;
			newEmployee->salary=salary;
			newEmployee->category=category;
				
			length++;
			newEmployee->next=NULL;
			head=newEmployee;
			teal=newEmployee;
		}
		
		
		bool isEmpty(){
			return length==0;
		}
		
		
		void AddToEnd(string userID,string firstName , string lastName , string id , double salary , string category){
				Employee *cur = new Employee;
				cur=head;
				int pos=-1;
				string userMode;
				
				for(int i=0;i<length;i++){
					if(cur->id==userID){
						pos=i;
						cur->mode=="admin"?userMode="admin" : userMode="guest";
						break;
					}
					cur=cur->next;
				}
					
				if(pos==-1){
					cout<<"The Employee Not Found"<<endl;
					return;
				}
				
				if(userMode=="guest"){
					cout<<"Sorry, You Are UnAuthorized To Do this Action"<<endl;
						cout<<"\n"<<endl;
					return;
				}
				Employee *newEmployee= new Employee;
				newEmployee->mode="guest";
				newEmployee->firstName=firstName;
				newEmployee->lastName=lastName;
				newEmployee->id=id;
				newEmployee->salary=salary;
				newEmployee->category=category;
				if(isEmpty()){
					head=teal=newEmployee;
					newEmployee->next=NULL;
				}else{
					teal->next=newEmployee;
					newEmployee->next=NULL;
					teal=newEmployee;
				}
				length++;
		}
		
		void updateEmployeeData(string userID,string firstName , string lastName , string id , double salary , string category){
			Employee *cur = new Employee;
				cur=head;
				int pos=-1;
				string userMode;
				
				for(int i=0;i<length;i++){
					if(cur->id==userID){
						pos=i;
						cur->mode=="admin"?userMode="admin" : userMode="guest";
						break;
					}
					cur=cur->next;
				}
				
				if(userMode=="guest"){
					cout<<"Sorry, You Are UnAuthorized To Do this Action"<<endl;
					cout<<"\n"<<endl;
					return;
				}
				
				cur=head;
				
				for(int i=0;i<length;i++){
					if(cur->id==id){					
						cur->firstName=firstName;
						cur->lastName=lastName;
						cur->id=id;
						cur->salary=salary;
						cur->category=category;
						break;
					}
					cur=cur->next;
				}
				if(pos==-1){
					cout<<"The Employee Not Found"<<endl;
					return;
				}	
					
		}
		
		
		void DeleteEmployee(string userID, string id) {
    		Employee *cur = head;
    		int pos = -1;
    		string userMode;

    		for (int i = 0; i < length; i++) {
        		if (cur->id == userID) {
            		pos = i;
            		userMode = (cur->mode == "admin") ? "admin" : "guest";
            		break;
        		}
        		cur = cur->next;
    		}

    		if (pos == -1) {
        		cout << "The User Not Found" << endl;
        		return;
   		 	}

    		if (userMode == "guest") {
       		    cout << "Sorry, You Are Unauthorized To Do this Action" << endl;
        		cout << "\n" << endl;
        		return;
    		}

    		cur = head;
    		Employee *prev = NULL;

    		for (int i = 0; i < length; i++) {
        		if (cur->id == id) {
            		if (prev == NULL) { 
                		head = cur->next;
                		if (head == NULL) { 
                		    teal = NULL;
                		}
            		} else {
               			prev->next = cur->next;
               			if (cur->next == NULL) {
                    		teal = prev;
                		}
            		}
            		cout << "The Employee With ID " << id << " Deleted Successfully" << endl;
            		cout << "\n" << endl;
            		delete cur;
            		length--;
            		return;
        		}
        		prev = cur;
        		cur = cur->next;
   			}

    		cout << "The Employee Not Found" << endl;
		}

		void sortBySalary(string type) {
    		if (length <= 1) return; 

    		bool swapped;
    		do {
        		swapped = false;
       			Employee* cur = head;
        		Employee* prev = NULL;
        		Employee* next = NULL;

        		while (cur != NULL && cur->next != NULL) {
            		next = cur->next;
            		bool shouldSwap = (type == "asc") ? (cur->salary > next->salary) : (cur->salary < next->salary);

            		if (shouldSwap) {
                		if (prev == NULL) {
                    		head = next;
                		} else {
                    		prev->next = next;
                		}
                		cur->next = next->next;
                		next->next = cur;

                		swapped = true;
                		prev = next;
            		} else {
                		prev = cur;
                		cur = cur->next;
            		}
        		}
    		} while (swapped);

    		Employee* temp = head;
   			while (temp->next != NULL) {
        		temp = temp->next;
    		}
    		teal = temp;
		}

		
		void displayEmployeeData(string id){
			if(isEmpty()){
				cout<<"The Employees List is Empty"<<endl;
				return;
			}else{
				Employee *cur = new Employee;
				cur=head;
				int pos=-1;
				
				for(int i=0;i<length;i++){
					if(cur->id==id){
						pos=i;
						break;
					}
					cur=cur->next;
				}
					
				if(pos==-1){
					cout<<"The Employee Not Found"<<endl;
					return;
				}
				
				cout<<"Employee Data : "<<endl;
				cout<<"======================================="<<endl;
				cout<<"\n";
		
				cout<<"Employee's ID : "<<cur->id<<endl;
				cout<<"Employee's First Name : "<<cur->firstName<<endl;
				cout<<"Employee's Last Name : "<<cur->lastName<<endl;
				cout<<"Employee's Salary : "<<cur->salary<<endl;
				cout<<"Employee's category : "<<cur->category<<endl;
				cout<<"======================================="<<endl;
				cur=cur->next;		
			}
		}
		
		
		
		void displayACertainNumberOfEmployeesData(int number){
			if(isEmpty()){
				cout<<"The Employees List is Empty"<<endl;
				return;
			}else{
				
				Employee *cur = new Employee;
				cur=head;
				cout<<"Employees Data : "<<endl;
				cout<<"======================================="<<endl;
				cout<<"\n";
				number=number>length?length:number;
				for(int i=0;i<number;i++){
					cout<<"Employee's ID : "<<cur->id<<endl;
					cout<<"Employee's First Name : "<<cur->firstName<<endl;
					cout<<"Employee's Last Name : "<<cur->lastName<<endl;
					cout<<"Employee's Salary : "<<cur->salary<<endl;
						cout<<"Employee's category : "<<cur->category<<endl;
					cout<<"======================================="<<endl;
					cur=cur->next;
				}
			}
		}
		
		void displayEmployeesData(){
			if(isEmpty()){
				cout<<"The Employees List is Empty"<<endl;
				return;
			}else{
				Employee *cur = new Employee;
				cur=head;
				cout<<"Employees Data : "<<endl;
				cout<<"======================================="<<endl;
				cout<<"\n";
			
				while(cur!=NULL){
					cout<<"Employee's ID : "<<cur->id<<endl;
					cout<<"Employee's First Name : "<<cur->firstName<<endl;
					cout<<"Employee's Last Name : "<<cur->lastName<<endl;
					cout<<"Employee's Salary : "<<cur->salary<<endl;
					cout<<"Employee's Category : "<<cur->category<<endl;
					cout<<"Employee's Mode : "<<cur->mode<<endl;
					cout<<"======================================="<<endl;
					cur=cur->next;
				}
			}
		}
	
};

int main(){
	EmployeesData employee("admin" , "Sultan" , "1" , 2000," Working ");
    
    employee.AddToEnd("1","Ahmed" , "sultan" , "2" , 2000 , "working");
    employee.AddToEnd("1","Mohamed" , "Ali" , "3" , 2000 , "non working");
    employee.updateEmployeeData("2" , "salma" , "sultan" , "2" , 2000 , "non working");
	employee.DeleteEmployee("1" , "2");
	employee.AddToEnd("1","sara" , "ahmed" , "4" , 5000 , "working");
	employee.sortBySalary("desc");
	employee.displayEmployeesData();
}
