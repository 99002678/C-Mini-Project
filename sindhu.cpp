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