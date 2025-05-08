#include "header.h" // header inclusion for structure member
class DSA // creating the linked list reading data from file
{
	public:
		int i,j,k;
		char **p,ch;
		char date[20];
		vector<string> s;
		dll *n;
		dll *n1;
		int lc=0,cc=0;
		DSA()
		{
			ifstream fin;
			fin.open("data"); //read the data from the file for atm functional operation
			if(fin.fail())
			{
				cout<<"no data file is present"<<endl;
				return;
			}
			while((ch=fin.get())!=-1)
			{
				if(ch=='\n')
					lc++;
				cc++;
			}
			fin.clear();
			fin.seekg(0);           //rewinding of file pointer to intial location
			p=new char*[cc];       //allocating 2d array to storing data
			for(i=0;i<lc;i++)
			{
				p[i]=new char[cc];
				while((fin.getline(p[i],cc)))
				{
					s.push_back(p[i]);       //storing into string array of all file
				}
			}
			my_split(s);          // to saparating for required like user_name , account number , pin and balance .
			print();
		}
		void my_split(vector<string> &s)
		{
			char name[20];
			int pin;
			int acc_no,flag=0;
			double bal;
			for(i=0;i<lc-2;i++)
			{
				acc_no=0;
				pin=0;
				bal=0;
				flag=0;
				for(j=0,k=0;s[i][j];j++)
				{
					if(s[i][j]==' ')
					{
						flag++;
					}
					else if(flag==0)
					{
						name[k]=s[i][j];                     //for user name
						k++;
					}
					else if(flag==1)
					{
						name[k]='\0';
						acc_no=acc_no*10+(s[i][j]-48);        //for account number
					}
					else if(flag==2)
					{
						pin=pin*10+(s[i][j]-48);         // for pin
					}
					else if(flag==3)
					{
						bal=bal*10+(s[i][j]-48);       // for balance
					}
				}
				data(name,acc_no,pin,bal);   //sending user_name ,account_number, pin and balance data for creating double linked list
			}
		}
		void data(char *name,int acc_no,int pin,double bal)
		{
			n=new dll; // new node
			n->name=name;
			n->acc_no=acc_no;
			n->pin=pin;
			n->bal=bal;
			n->w=0;
			n->d=0;
			add_last();          // creating liked list
		}
		void add_last()
		{
			if(head==0)
			{
				n->next=head;
				n->prev=head;
				head=n;
			}
			else
			{
				dll *ptr=head;
				while(ptr->next!=0)
					ptr=ptr->next;
				n->next=ptr->next;
				n->prev=ptr;
				ptr->next=n;
			}
		}
		void print()                     // printing linked list data
		{
			dll *ptr=head;
			cout<<"printing node data"<<endl;
			while(ptr!=0)
			{
				cout<<(ptr->name)<<" "<<(ptr->acc_no)<<" "<<(ptr->pin)<<" "<<(ptr->bal)<<endl;
				ptr=ptr->next;
			}
		}

};
class ATM:public DSA
{
	public:
		int num,nc;
		ATM()
		{
l1:		dll *ptr=head;           // pointing first head node for
		dll *ptr1=head;         // pointing first head node for
		string name;int pin;
		int acc_no,op,flag=0,flag1=0;
		while(1)            
		{
			cout<<"1) by user_name"<<endl; 
			cout<<"2) by account number"<<endl;
			cout<<"-----------------------------"<<endl;
			cout<<"enter the option"<<endl;
			cin>>op;   // menue option for do operation either user_name nor  account number instead of card insert
			if(op==1) // for username based operation
			{
				cout<<"enter user_name"<<endl;
				cin>>name;        // for username 
				while(ptr)
				{
					if((ptr->name)==name)  // if user_name found move further 
					{
						cout<<(ptr->name)<<endl;
						cout<<"1) generate new atm pin"<<endl; 
						cout<<"2) atm pin is available"<<endl; 
						cout<<"---------------------------"<<endl;
						cout<<"enter the option"<<endl; //asking user wheather the pin want to generate or its already available
						cin>>op;
						if(op==1)                      // if user want to generate pin move further
						{
							cout<<"enter new pin"<<endl;
							cin>>pin;   // setting new pin
							ptr->pin=pin;
							cout<<"atm pin is setting wait for minute ...."<<endl;
							sleep(2);
							cout<<"atm pin is set"<<endl;

						}
						else
						{
							cout<<"enter ATM PIN"<<endl;
							cin>>pin;             //if pin is available
							for(num=pin,nc=0;num;num=num/10)
								nc++;               //counting the pin digits is whether is four or exceeds 
							if(nc!=4)                  //if pin exceeds greater than 4 print error message
							{ 
								cout<<"please enter must  4 digit  pin"<<endl;
								goto l1;
							}
							while(ptr1)
							{
								if((ptr1->pin)==pin)  // if pin is found with respect to user_name 
								{
									cout<<"1) withdraw amount"<<endl;
									cout<<"2) deposit_amount"<<endl;
									cout<<"3) balance enquiry"<<endl;
									cout<<"4) transaction details"<<endl;
									cout<<"--------------------------------------------"<<endl;
									cin>>op;         //asking operation for withdraw, deposit, balance enquiry or transaction information 
									switch(op)
									{
										case 1:withdraw(pin);break;    // for widrawing amount respect to user_name
										case 2:deposit(pin);break;    // for depositing amount respect to user_name
										case 3:balance(pin);break;    //for balance enquiry respect to user_name
										case 4:transaction_info(pin);break; //for transaction details respect to user_name
									}
									flag=1;
								}
								ptr1=ptr1->next; // traversing ponter ptr1 in forward upto null or moving linked list upto null pointer
							}
							if(flag==0)  //checking flag wheather the pin is available or not 
							{
								cout<<"atm pin is wrong"<<endl; //if pin is not found displaying error message
								goto l1; // again moving in backward to intial process
							}
						}
						flag1=1; 
					}
					if(flag1==0) //checking username is found or not
					{
						cout<<"wrong user name entered"<<endl; //if username found displaying error message 
						goto l1; //again moving in backward  to intial process
					}
					ptr=ptr->next; //traversing ponter ptr in forward upto null or moving linked list upto null pointer
				}
				goto l1;
			}
			else if(op==2) // for account_number basec operation
			{
				cout<<"enter account_number"<<endl;
				cin>>acc_no; //account number
				while(ptr)
				{
					if((ptr->acc_no)==acc_no) // if account_number found move further 
					{
						cout<<"1) generate new atm pin"<<endl;
						cout<<"2) atm pin is available"<<endl;
							cout<<"---------------------------"<<endl;
							cout<<"enter the option"<<endl;
							cin>>op;                              //asking user wheather the pin want to generate or its already available
							if(op==1)                  // if user want to generate pin move further
							{
								cout<<"enter new pin"<<endl;
								cin>>pin; // setting new pin
								ptr->pin=pin;
								cout<<"atm pin is setting wait for minute ...."<<endl;
								sleep(2);
								cout<<"atm pin is set"<<endl;
							}
							else
							{
								cout<<"enter ATM PIN"<<endl;
								cin>>pin;
								for(num=pin,nc=0;num;num=num/10)
									nc++; //counting the pin digits is whether is four or exceeds 
								if(nc!=4)             //if pin exceeds greater than 4 print error message
								{
									cout<<"please enter must  4 digit  pin"<<endl;
									goto l1;
								}
								while(ptr1)
								{
									if((ptr1->pin)==pin) // if pin is found with respect to account_number 
									{
										cout<<"1) withdraw amount"<<endl;
										cout<<"2) deposit_amount"<<endl;
										cout<<"3) balance enquiry"<<endl;
										cout<<"4) transaction details"<<endl;
										cout<<"--------------------------------------------"<<endl;
										cin>>op;         //asking operation for withdraw, deposit, balance enquiry or transaction information 
										switch(op)
										{
											case 1:withdraw(pin);break;  // for widrawing amount respect to account_number
											case 2:deposit(pin);break;   // for depositing amount respect to account_number
											case 3:balance(pin);break;  // for balance enquiry respect to account_number
											case 4:transaction_info(pin);break;   // for transaction details respect to account_number
										}
										flag=1;
									}
									ptr1=ptr1->next;    // traversing ponter ptr1 in forward upto null or moving linked list upto null pointer
								}
								if(flag==0)        //checking flag wheather the pin is available or not 
								{
									cout<<"atm pin is wrong"<<endl;  //if pin is not found displaying error message
									goto l1; // again moving in backward to intial process
								}
								flag1=1;
							}
						}
						else if(flag1==0) //checking username is found or not
						{
							cout<<"wrong account number entered"<<endl; //if username found displaying error message 
							goto l1;
						}
						ptr=ptr->next;// traversing ponter ptr1 in forward upto null or moving linked list upto null pointer
					}
					goto l1; // traversing ponter ptr1 in forward upto null or moving linked list upto null pointer
				}
				else
				{
					cout<<"invalid option"<<endl; //if option is wrong displaying invalid message
					goto l1;                 // again moving in backward to intial process
				}
			}
		}
		void withdraw(int pin) // function defination for withdraw
		{
			dll *ptr=head;
			int wa;
			while(ptr)       
			{
				if((ptr->pin)==pin) //checking pin linked list with respect to pin
				{
					cout<<"enter the amount to withdraw"<<endl;
					cin>>wa; // asking the user for withdrawing amount
					if(wa<100)  // checking condition wheather the entered amount is less than 100
					{
						cout<<"minimum amount to withdraw is 100 "<<endl; //
						return;
					}
					cout<<"withdrawing an amount please wait for a minute ..."<<endl;
					sleep(2);
					ptr->bal-=wa;
					ptr->w=wa;
				}
				ptr=ptr->next;
			}
			cout<<"withdrawing amount is completed"<<endl;
			return;
		}
		void deposit(int pin)
		{
			dll *ptr=head;
			int wa;
			while(ptr!=0)
			{
				if((ptr->pin)==pin)
				{
					cout<<"enter the amount to deposit"<<endl;
					cin>>wa;
					if(wa<100)
					{
						cout<<"minimum amount to depositing is 100 "<<endl;
						return;
					}
					cout<<"depositing an amount please wait for a minute ..."<<endl;
					sleep(2);
					ptr->bal+=wa;
					ptr->d=wa;
				}
				ptr=ptr->next;
			}
			cout<<"The deposit transaction has been completed successfully"<<endl;
			return;
		}
		void balance(int pin)
		{
			dll *ptr=head;
			while(ptr)
			{
				if((ptr->pin)==pin)
				{
					cout<<"your account balance is :- "<<endl;
					cout<<(ptr->bal)<<endl;
				}
				ptr=ptr->next;
			}
			return;
		}
		void transaction_info(int pin)
		{
			int p=pin;
			print_td(p);
			return;
		}
		void print_td(int &pin)
		{
			dll *last=head;
			cout<<"printing transaction details"<<endl;
			cout<<"name      "<<" "<<"accountnumber"<<" "<<"account_balance "<<"withdraw ammount "<<"deposit "<<endl;
			while(last)
			{
				if((last->pin)==pin)
				{
					cout<<(last->name)<<" "<<(last->acc_no)<<" "<<(last->bal)<<"    "<<(last->w)<<"      "<<(last->d)<<endl;
				}
				last=last->next;
			}
		}
};
int main()
{
	ATM a;
	a.print();
}
