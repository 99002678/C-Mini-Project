#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10

using namespace std;


class medicineType	
{
public:

    void takeOrder();
    void deleteOrder(); 
    void modify(); 
	void orderList(); 
	void dailySummary(); 
	void exit();  
	medicineType();

};

 medicineType::medicineType ()
{

}		


struct node 
{
	int recieptNumber;
	string customerName;
	int phnumber;
	string address;
	string emailId;
	string date;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Probiotics","Paracetamol","Zintac(500mg)","Crocin","Rantac","Isosorbate Dinitrate",
	"Anacin(500mg)","Dolo 650","Instamet","Cardivas"};
	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	double total;

	node *prev;
	node *next;
	node *link; 

}*q, *temp;		 


node *startPtr = NULL;
node *head = NULL;
node *last = NULL;




void medicineType::takeOrder()		
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	std::cout <<"\nAdd Order Details\n";
	std::cout <<"_____________________________________ \n\n";

	node *temp;
	temp=new node;

				std::cout <<"**************************************************************************\n";
				std::cout<<"DRUGS ID"<<"\tDRUGS TYPE"<<"   \t\tDRUGS NAME"<<"           DRUGS PRICE(Rs)"<<endl;
				std::cout <<"**************************************************************************\n";
                std::cout<<"0001"<<"\t"<<"\taniline analgesics"<<"\t\t"<<"    Probiotics"<<"			Rs 2.00"<<endl;
                std::cout<<"0002"<<"\t"<<"\tAspirin"<<"\t\t"<<"               Paracetamol"<<"		    Rs 3.00"<<endl;
                std::cout<<"0003"<<"\t"<<"\tcimetidine"<<"\t\t"<<"            Zintac(500mg)"<<"		    Rs 1.00"<<endl;
                std::cout<<"0004"<<"\t"<<"\tditerpenoids"<<"\t\t"<<"          Crocin"<<"		        Rs 4.00"<<endl;
                std::cout<<"0005"<<"\t"<<"\tcimetidine"<<"\t\t"<<"            Rantac"<<"	 	        Rs 1.00"<<endl;
                std::cout<<"0006"<<"\t"<<"\tIsosorbate Dinitrate"<<"\t\t"<<"  Isosol   "<<"             Rs 5.00"<<endl;
                std::cout<<"0007"<<"\t"<<"\t salicylate"<<"\t\t"<<"           Anacin(500mg)"<<"		    Rs 7.00"<<endl;
                std::cout<<"0008"<<"\t"<<"\tAspirin"<<"\t\t"<<"               Dolo 650"<<"			    Rs 4.00"<<endl;
                std::cout<<"0009"<<"\t"<<"\t biguanides"<<"\t\t"<<"           Istamet"<<"			    Rs 3.00"<<endl;
                std::cout<<"0010"<<"\t"<<"\tBeta-Blockers"<<"\t\t"<<"         Cardivas"<<"		        Rs 5.00"<<endl;
                std::cout<<" "<<endl;
    
	temp = new node;

	std::cout<< "Enter Customer Name: ";
	std::cin>> temp->customerName;
	std::cout<<"Enter Date : ";
	std::cin>>temp->date;
	std::cout<<"Enter EmailId:";
	std::cin>>temp->emailId;
	std::cout<<"Enter Address:";
	std::cin>>temp->address;
	std::cout<<"Enter phone:";
	std::cin>>temp->phnumber;




	
	std::cout << "How many Medicine would you like to order:"<< endl;
	std::cout<<"( Maximum is 10 order for each transaction ) \n";
	std::cout << "  " ;
	std::cin >> temp->x;
	if (temp->x >10)
	{
		std::cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		std::cout << "Please enter your selection : "<<endl;
		std::cin>> temp->menu2[i];
        std::cout<< "Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        std::cout << "How many medicine do you want: ";
        std::cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        std::cout << "The amount You need to pay is: " << temp->amount[i]<<"Rs "<<endl;
        system("PAUSE");
                      
	}
	std::cout<<"***************************************************************************"<<endl;
    std::cout << "Order Taken Successfully"<<endl;
    std::cout<<"***************************************************************************"<<endl;
    std::cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    std::cout<<"***************************************************************************"<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(startPtr!=NULL)
	{
		temp->next=startPtr;
	}
	startPtr=temp;
	system("cls");
}
}


void medicineType::orderList()		
{
	int i, num, num2;	
	bool found;			
	system("cls");
	node *temp;

	temp=startPtr;
	found = false;
	
	std::cout<<" Enter the Reciept Number To Print The Reciept\n";
	std::cin>>num2;
	std::cout<<"\n";
	std::cout<<"***************************************************************************"<<endl;
	std::cout <<"\t\tHere is the Order list\n"; 
	std::cout<<"***************************************************************************"<<endl;


	if(temp == NULL) 
	{
		std::cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->recieptNumber==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	
        {
		std::cout <<"Reciept Number : "<<temp->recieptNumber;
		std::cout <<"\n";
		std::cout<<"Customer Name: "<<temp->customerName<<endl;
				
		std::cout<<"Order Date : "<<temp->date<<endl;
				
		std::cout<<"_____________________________________________________________________________"<<endl;
			
		std::cout << "===============================================================================" << endl;
		std::cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		std::cout << "=======++==================++================++===============++===============" << endl;
		for (i=0;i<temp->x;i++)
		{
			std::cout << temp->type <<"  \t\t";
			std::cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			std::cout<<temp->quantity[i] <<"\t\t";
			std::cout<< temp->amount[i]<<"Rs "<<endl;
			std::cout<<"_________________________________________________________________________________"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		std::cout<<"Total Bill is : "<<temp->total;
		std::cout<<"\n";
		std::cout << "Type the exact amount You need to pay: ";
        std::cin >> num;

		std::cout <<"\n";
		std::cout <<"\n";
		std::cout<<"Payment Done\nThank You\n";
		std::cout <<"\n_______________________________________________________________________________\n";
		}


}
}	


void medicineType::deleteOrder()	
{
	system("cls");
	int i, num, count;
    std::cout<<"Enter the data you want to delete \n";
    std::cin>>num;
    node *q;
	node *temp;
	bool found;

	if(startPtr == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(startPtr->recieptNumber == num)
		{
			q = startPtr;
			startPtr = startPtr->next;
			count--;
			if(startPtr == NULL)
			last = NULL;
			delete q;
			std::cout<<"The Reciept was Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = startPtr;
			q = startPtr->next;
	
		while((!found) && (q != NULL))
		{
  			if(q->recieptNumber != num) 
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q) 
				last = temp;
				delete q;
				std::cout<<"The Reciept was Deleted Successfully"<<endl;
			}
			else
				std::cout<<"The item to be deleted is not found in the list."<<endl;
			}
		} 
}	

void medicineType::modify()	{
 system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = startPtr;
 std::cout<<"Enter Receipt Number To Modify: ";
 std::cin>>sid;
 if (temp==NULL && sid==0)
 {
    std::cout<<"SORRY!!!!!!!! NO RECORD TO MODIFY..!"<<endl;
 }

 else{
 	while(temp !=NULL && !found)
	{
		if (temp->recieptNumber==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	std::cout << "Change  Order Number: ";
    std::cin >> temp->recieptNumber;
	std::cout<< "Change Customer Name: ";
	std::cin>> temp->customerName;
	std::cout<<"Change Date : ";
	std::cin>>temp->date;
	std::cout << "How many New Medicine would you like to Change:"<< endl;
	std::cout<<"( Maximum is 10 order for each transaction ) \n";
	std::cout << "  " ;
	std::cin >> temp->x;
	if (temp->x >10)
	{
		std::cout << "Your order is exceeding the maximum count of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		std::cout << "Please enter your selection to modify: "<<endl;
		std::cin>> temp->menu2[i];
        std::cout<< "Change Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        std::cout << "How many New medicine do you want: ";
        std::cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        std::cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<"Rs "<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");
	
	}

 std::cout<<"RECORD MODIFIED....!"<<endl;
 }
 else 
 {
 	if(temp != NULL && temp->recieptNumber != sid)
 	{
 	std::cout<<"Invalid Reciept Number...!"<<endl;
    }
 }
}
}
}		

void medicineType::dailySummary()	{
	int i,num;
	system("cls");
	node *temp ;

	temp=startPtr;


	if(temp == NULL) 
	{
		std::cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else{
		std::cout<<"\n";
		std::cout<<"==========================================================================="<<endl;
		std::cout <<" \t\tHere is the Daily Summary of All Orders \n"; 
		std::cout<<"==========================================================================="<<endl;

		while(temp!=NULL)
		{
		
				std::cout <<"Reciept Number : "<<temp->recieptNumber;
				std::cout <<"\n";
				std::cout<<"Customer Name: "<<temp->customerName<<endl;
				
				std::cout<<"Order Date : "<<temp->date<<endl;
				
				std::cout<<"____________________________________________________________________________"<<endl;
			
				std::cout << "==========================================================================" << endl;
				std::cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				std::cout << "=======++==================++================++===============++==========" << endl;
			for (i=0;i<temp->x;i++)
			{
				std::cout << temp->type <<"  \t\t";
				std::cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
				std::cout<<temp->quantity[i] <<"\t\t";
				std::cout<< temp->amount[i]<<"Rs "<<endl;
				std::cout<<"_____________________________________________________________________________"<<endl;
			}
			
			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			std::cout<<"Total Bill is : "<<temp->total;
		
			std::cout <<"\n";
			std::cout <<"\n";
			std::cout <<"\n_______________________________________________________________________________\n";
				
			temp=temp->next;
		}
	}
}		
void medicineType::exit() 
{
	std::cout<<"\nYou choose to exit.\n"<<endl;
}

int main()
{

	system("COLOR 79");		
	medicineType medicine;
	int menu;
	do
	{
		system("cls");
		std::cout<<"\t\t\tPharmacy Management System - UNIMAS\n";
		std::cout<<"\t\t**************************************************\n\n";
		std::cout<<"\t\t**************************************************\n";
		std::cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		std::cout<<"\t\t||\t2. delete latest Medicine order\t\t ||\n";
		std::cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
		std::cout<<"\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		std::cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		std::cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		std::cout<<"\t\t**************************************************\n";
		std::cout<<"Enter choice: ";

		std::cin>>menu;

		switch (menu)
		{
		case 1:
			{
				medicine.takeOrder();	
				break;
			}	
		
		
		case 2:
			{
				medicine.deleteOrder();	
				system("PAUSE");
				break;
			}	
			
		case 3:
			{
				medicine.modify();
				system("PAUSE");
				break;
			}	

		case 4:
			{
				medicine.orderList();	
				system("PAUSE");
				break;
			}	
		case 5:
			{
				medicine.dailySummary();	
				system("PAUSE");
				break;
			}	
        case 6:
			{
				medicine.exit();	
				goto a;
				break;
			}	

		
		default:
			{
				std::cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}
		}
	}while(menu!=6);
	a://goto
	std::cout<<"thank you"<<endl;
	system ("PAUSE");
	return 0;
}
