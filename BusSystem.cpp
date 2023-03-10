
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>//gets,puts
#include<fstream>//txtfile
using namespace std;

class Login{
	public:
		int id;
    	string pass;
    	string *password;
    	void info(){
			cout<<"Enter your id\n";
			cin>>id;
			pass = *password;
			cout<<"Enter password"<<endl;
			cin>>pass;
		}
		void displayinfo(){
			cout<<"Id:"<<id<<endl;
        	cout<<"Password:"<<pass<<endl;
  	
		}
	
};

class Details{
	public:
	char bname[100];
	int bno;
	char bp[100];
	char dest[100];
	float fare;
	int seats;
	int d,m,y;
	
	void getdetails(){
		cout<<"Enter the details as follows\n";
        cout<<"bus no:";
        cin>>bno;
        cout<<"bus name:";
        gets(bname);
        cout<<"Boarding point:";
        gets(bp);
        cout<<"Destination pt:";
        gets(dest);
        cout<<" fare per ticket:";
        cin>>fare;
        cout<<"Date of travel:";
        cin>>d>>m>>y;
	}
	
	void displaydetails(){
		cout<<"\t\t Bus name :"<<bname<<endl;
	   	cout<<"\t\t Bus number :"<<bno<<endl;
	   	cout<<"\t\t Boarding point :"<<bp<<endl;
		cout<<"\t\t Destination :"<<dest<<endl;
		cout<<"\t\t Bus fare :"<<fare<<endl;
	  	cout<< "\t\t Number of seats:"<<seats<<endl;
		cout<<d<<"-"<<m<<"-"<<y<<endl;
	}

	
};
class Reservation: public Details{
	public:
		int i;
		string pname;
	   	char age;
	   	void getres(){
				for(int i=0; i<=seats; i++){
					cout<<"Passenger name :\n";
	   	   			cin>>pname;
	   	   			cout<<"Passengers age :\n\n";
	   	   			cin>>age;
	   			}
		   }
	   	void reservationdetails(){
			   	cout<<"\t\tPassengers Name"<<pname<<endl;
				cout<<"\t\tPassengers Age"<<age<<endl;
	   	   	   	cout<<"\t\t Bus name :"<<bname<<endl;
	   	   	   	cout<<"\t\t Bus number :"<<bno<<endl;
	   	   	   	cout<<"\t\t Boarding point :"<<bp<<endl;
	   	   	   	cout<<"\t\t Destination :"<<dest<<endl;
	   	   	   	cout<<"\t\t Bus fare :"<<fare<<endl;
	   	   	   	cout<< "\t\t Number of seats:"<<seats<<endl;
	   	   	   	cout<<d<<"-"<<m<<"-"<<y<<endl;
		   }
	
};
class Cancell: public Reservation{
	public:
		void cancell(){
			cout<<"Bus number\n";
			cin>>bno;
			cout<<"Bus name\n";
			cin>>bname;
	   		cout<<"destination\n";
	   		cin>>dest;
	   		cout<<"Passenger name\n";
			cin>>pname;
			cout<<"Passanger age\n";
			cin>>age;
	   		cout<<"Number of seats\n";
	   		cin>>seats;
	   		cout<<"date\n";
	   		cin>>d>>m>>y;
		}
	   	
	   	void showcancell(){
			   	cout<<"\n CANCELLATION\n";
				cout<<"Date :"<<d<<"-"<<m<<"-"<<y<<endl;
		   }
	
	
};
void administrator();
void user();
//void reserve();
void title()
{
	system("cls");
	
	cout<<"\n\n\n";
	cout<<"\t\t\t##################################################################\n\n";
	cout<<"\t\t\t:::::::::::::::::WELCOME TO BUS BOOKING SYSTEM::::::::::::::::::::\n\n";
	cout<<"\t\t\t###################################################################\n\n\n\n";
	
}
int main(int argc, char** argv)
{
	title();
	int ch;

	
	do{
		system("cls");
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t\t\t MAIN MENU\n\n";
		cout<<"1.Admin "<<endl;
		cout<<"2.User"<<endl;
		cout<<"3.Exit\n\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		cout<<endl;
		
		switch(ch){
			case 1:
				administrator();
				break;
				case 2:
					user();
					break;
						case 3:
							cout<<"exit\n";
							break;
		}	
	}while(ch !=3);
}

	void administrator(){
		string password;
    	string pass="codewithc";
    	
    	title();
    	cout<<"Enter your password\n";
    	cin>>password;
    	cout<<endl;
    	Details a;
    	fstream myfile;
    	int ch;
    
    	if(pass != password)
		{
			cout<<"wrong password\n";
		}
		if(pass == password){
			char c;
			do{
				system("cls");
				cout<<"\n\n\n";
				cout<<"\t\t\t////////////////////////////////////////////\n\n";
				cout<<"\t\t\t*********WELCOME TO ADMIN MENU*********\n\n";
				cout<<"\t\t\t//////////////////////////////////////////////\n\n\n\n";
				cout<<"1.Display  or Alter Data\n";
				cout<<"2.Add Details\n";
            	cout<<"3.Display Details\n";
			//	cout<<"4.User management\n";
            	cout<<"4.Display Passenger Details\n";
				cout<<"5.Return to Main Menu\n\n";
            	cout<<"Enter your choice:\n";
            	cin>>c;
            	
            	switch(c){
					case 1:
						myfile.open("Details.txt",ios::binary);//to display data as it appears
						do{
							
							myfile.write((char*)& a,sizeof(a));
							cout<<"To add new record, press(Y)\n";
							cin>>c;
							a.bname;
							a.bno;
							a.bp;
							a.getdetails();
						}
						while(c=='Y');
						myfile.close();
					break;
				
					case 2:
						myfile.open("Details.txt",ios::in|ios::out|ios::binary|ios::app);
                		a.getdetails();
                		myfile.write((char *) & a,sizeof(a));
               	   	    myfile.close();
               	   	    break;
               	   	case 3:
               	   		myfile.open("Details.txt",ios::in|ios::out|ios::binary|ios::app);
						myfile.seekg(0);
						while(myfile.read((char *) & a,sizeof(a))){
                   	   	  a.displaydetails();
						}
							
               	   	    myfile.close();
               	   	    break;
               	   	case 4:
               	   		a.displaydetails();
               	   		break;
 	 	 			
						}
						
				}while(ch != 5);
				myfile.close();
			}
			
		}
		/*
void reserve(){
	int ch;
	do{
		cout<<"1.reserve\n";
		cin>>ch;
		if(ch==1){
			Details a;
			Reservation b;
			fstream  det,res;
			time_t t;
			det.open("deta.txt",ios::in|ios::out|ios::binary);
			res.open("rest.txt",ios::in|ios::out|ios::binary|ios::app);
			int ch;
			b.reservationdetails();
			while(det.read((char *) &a,sizeof(a)))
				if(b.bno==a.bno){
					
				}
		}
	}
	while(ch=1);
}*/
void user(){
	Login a;
	int ch;
	string pass;
	string *password;
	
	system("cls");
	cout<<"********************************************\n";
	cout<<"         .........USER MENU.........         \n";
	cout<<"                    *****                    \n";
	 
	 fstream myfile;
	 myfile.open("user.txt",ios::in|ios::out|ios::binary);
	 int id;
	 cout<<"Enter your id\n";
	 cin>>id;
	 cout<<"Enter your password\n";
	 cin>>pass;
	 //pass= *password;
	 while(myfile.read((char*)& a,sizeof(a))){
	 	if(a.id==id)//password
		 {
		 	
		 do{
		 	cout<<" 1.reserve\n 2.cancell\n 3.back to menu\n";
		 	cout<<"Enter your choice"<<endl;
		 	cin>>ch;
		 	cout<<endl;
		 	
		 	switch (ch){
			 case 1:
			 //	reserve();
			 cout<<"reserved"<<endl;
			 	break;
			 case 2:
			 	//cancell();
			 	cout<<"cancell\n";
			 	break;
			 }
		 }
		 while(ch !=3);
		 
	 	 }
	  	  else{
	 	    cout<<"incorrect id"<<endl;
 	   	  }
	 }
}
 	   	  
		 		 		
	
