#include<iostream>
using namespace std;
struct employee{
	string name,id,adress;
	int contact,salary;
};
employee e[20];
 int member=0;
 void data()
 {
 	int choice;
 	cout<<"Enter number of Employee";
 	cin>>choice;
 	for(int i=member;i<member+choice;i++)
 	{
 		cout<<"Enter data of employee "<<i+1<<" : "<<endl;
 		cout<<"Name : ";
 		cin>>e[i].name;
 		cout<<"ID : ";
 		cin>>e[i].id;
 		cout<<"Adress : ";
 		cin>>e[i].adress;
 		cout<<"Salary : ";
 		cin>>e[i].salary;
 		cout<<"Contact : ";
 		cin>>e[i].contact;
		  
	}
 	member=member +choice;
}
void show()
{
	if(member!=0)
	{
		for(int i=0;i<member;i++)
		{
			cout<<"data of Employee "<<i+1<<endl;
			cout<<"Name : "<<e[i].name<<endl;
			cout<<"ID : "<<e[i].id<<endl;
			cout<<"Adress : "<<e[i].id<<endl;
			cout<<"Contact : "<<e[i].contact;
			cout<<"Salary : "<<e[i].salary;
		}
	}
	else
	{
		cout<<"There is no data in this number";
	}
}
void search()
	{
		if(member !=0)
		{
			string id;
			cout<<"Enter the name of the id : ";
			cin>>id;
			for(int i= 0;i<member;i++)
			{
				if(id==e[i].id)
				{
					cout<<"data of Employee "<<i+1<<endl;
					cout<<"Name : "<<e[i].name<<endl;
					cout<<"ID : "<<e[i].id<<endl;
					cout<<"Adress : "<<e[i].id<<endl;
					cout<<"Contact : "<<e[i].contact;
					cout<<"Salary : "<<e[i].salary;
					break;
					if (id!=e[i].id)
					{
					cout<<"No such record is found ";
					}
				}
			}
		}
		else
		{
		cout<<"no record is found...";
		}
	}
void update()
{
	if(member!=0)
	{
		string id;
		cout<<"Enter the name of the id : ";
		cin>>id;
		for(int i= 0;i<member;i++)
			{
				if(id==e[i].id)
				{
					cout<<"Previous Data "<<endl;
					cout<<"data of Employee "<<i+1<<endl;
					cout<<"Name : "<<e[i].name<<endl;
					cout<<"ID : "<<e[i].id<<endl;
					cout<<"Adress : "<<e[i].id<<endl;
					cout<<"Contact : "<<e[i].contact<<endl;
					cout<<"Salary : "<<e[i].salary<<endl;
					cout<<"Enter new data "<<endl;
					cout<<"Name : ";
 					cin>>e[i].name;
 					cout<<"ID : ";
 					cin>>e[i].id;
 					cout<<"Adress : ";
 					cin>>e[i].adress;
 					cout<<"Salary : ";
 					cin>>e[i].salary;
 					cout<<"Contact : ";
 					cin>>e[i].contact;
					break;
				
				if (id!=e[i].id)
				{
					cout<<"No such record is found ";
				}
			}
		}
	}
	else
	{
	cout<<"no record is found...";
	}
}
void del()
{
		if (member!=0)
		{
			int choice;
			cout<<"Press 1 to delete all data"<<endl;
			cout<<"Press 2 to delete data of specific id "<<endl;
			cin>>choice;
				if (choice == 1)
			{
				cout<<"Your all data is deleted"<<endl;
			}
			else if (choice==2)
			{
				string id;
				cout<<"Enter the name of the id : ";
				cin>>id;
				for(int i=0;i<member;i++){
						if(id==e[i].id)	
				
					for(int j=i;j<member;j++){
					
					
					e[j].name==e[j+1].name;
					e[j].id==e[j+1].id;
					e[j].adress==e[j+1].adress;
					e[j].contact==e[j+1].contact;
					e[j].salary==e[j+1].salary;
					member--;
					cout<<"Your data is deleted";
					break;
			}
			
		
				if(id!=e[i].id)
			{
			cout<<"No such record is found..";
			}
				}
			
			
			}
		}
	
	
		else
{
	cout<<"no record is found";
}


}
 main()
{
	
	string username,password;
	cout<<"\n\t\tEmployee Management System";
	cout<<"\n\tSign Up";
	cout<<"\n\tUsername : ";
	cin>>username;
	cout<<"\n\tPassword : ";
	cin>>password;

	cout<<"\n\t\tYour account is created successfully.....";
	
	start:
	cout<<"\n\tLogin";
	
	string user,pass;
	
	
	while (true){
		cout<<"\n\tUsername : ";
		cin>>user;
		
		cout<<"\n\tPassword : ";
		cin>>pass;
		
		if (username==user && password==pass)
		{
			int user;
			
			while (1){
				cout<<"\n\nPress 1 to enter data"<<endl;
				cout<<"Press 2 to show data"<<endl;
				cout<<"Press 3 to search data"<<endl;
				cout<<"Press 4 to update data"<<endl;
				cout<<"Press 5 to delete data";
				cout<<"Press 6 to logout"<<endl;
				cout<<"Press 7 to exit"<<endl;
				cin>>user;
				
				switch(user)
				{
					case 1:
					data();
					break;
					
					case 2:
						show();
						break;
						
						case 3:
						search();
						break;
						
						 case 4:
						 update();
						 break;
						 	
							 case 5:
							del();
							 break;
							 
							 case 6:
									goto start;			
				}
			}
			
			break;
		}
		else 
		{
			cout<<"Invalid Usernmae or Password";
		}
	}

}
