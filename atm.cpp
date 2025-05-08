#include "header.h"
class DSA
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
			fin.open("data");
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
			fin.seekg(0);
			p=new char*[cc];
			for(i=0;i<lc;i++)
			{
				p[i]=new char[cc];
				while((fin.getline(p[i],cc)))
				{
					s.push_back(p[i]);
				}
			}
			my_split(s);
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
						name[k]=s[i][j];
						k++;
					}
					else if(flag==1)
					{
						name[k]='\0';
						acc_no=acc_no*10+(s[i][j]-48);
					}
					else if(flag==2)
					{
						pin=pin*10+(s[i][j]-48);
					}
					else if(flag==3)
					{
						bal=bal*10+(s[i][j]-48);
					}
				}
				data(name,acc_no,pin,bal);
			}
		}
		void data(char *name,int acc_no,int pin,double bal)
		{
			n=new dll;
			n->name=name;
			n->acc_no=acc_no;
			n->pin=pin;
			n->bal=bal;
			n->w=0;
			n->d=0;
			add_last();
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
		void print()
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
l1:		dll *ptr=head;
		dll *ptr1=head;
		string name;int pin;
		int acc_no,op,flag=0,flag1=0;
		while(1)
		{
			cout<<"1) by user_name"<<endl;
			cout<<"2) by account number"<<endl;
			cout<<"-----------------------------"<<endl;
			cout<<"enter the option"<<endl;
			cin>>op;
			if(op==1)
			{
				cout<<"enter user_name"<<endl;
				cin>>name;
				while(ptr)
				{
					if((ptr->name)==name)
					{
						cout<<(ptr->name)<<endl;
						cout<<"1) generate new atm pin"<<endl;
						cout<<"2) atm pin is available"<<endl;
						cout<<"---------------------------"<<endl;
						cout<<"enter the option"<<endl;
						cin>>op;
						if(op==1)
						{
							cout<<"enter new pin"<<endl;
							cin>>pin;
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
								nc++;
							if(nc!=4)
							{
								cout<<"please enter must  4 digit  pin"<<endl;
								goto l1;
							}
							while(ptr1)
							{
								if((ptr1->pin)==pin)
								{
									cout<<"1) withdraw amount"<<endl;
									cout<<"2) deposit_amount"<<endl;
									cout<<"3) balance enquiry"<<endl;
									cout<<"4) transaction details"<<endl;
									cout<<"--------------------------------------------"<<endl;
									cin>>op;
									switch(op)
									{
										case 1:withdraw(pin);break;
										case 2:deposit(pin);break;
										case 3:balance(pin);break;
										case 4:transaction_info(pin);break;
									}
									flag=1;
								}
								ptr1=ptr1->next;
							}
							if(flag==0)
							{
								cout<<"atm pin is wrong"<<endl;
								goto l1;
							}
						}
						flag1=1;
					}
					if(flag1==0)
					{
						cout<<"wrong user name entered"<<endl;
						goto l1;
					}
					ptr=ptr->next;
				}
				goto l1;
			}
			else if(op==2)
			{
				cout<<"enter account_number"<<endl;
				cin>>acc_no;
				while(ptr)
				{
					if((ptr->acc_no)==acc_no)
					{
						cout<<"1) generate new atm pin"<<endl;
						cout<<"2) atm pin is available"<<endl;
							cout<<"---------------------------"<<endl;
							cout<<"enter the option"<<endl;
							cin>>op;
							if(op==1)
							{
								cout<<"enter new pin"<<endl;
								cin>>pin;
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
									nc++;
								if(nc!=4)
								{
									cout<<"please enter must  4 digit  pin"<<endl;
									goto l1;
								}
								while(ptr1)
								{
									if((ptr1->pin)==pin)
									{
										cout<<"1) withdraw amount"<<endl;
										cout<<"2) deposit_amount"<<endl;
										cout<<"3) balance enquiry"<<endl;
										cout<<"4) transaction details"<<endl;
										cout<<"--------------------------------------------"<<endl;
										cin>>op;
										switch(op)
										{
											case 1:withdraw(pin);break;
											case 2:deposit(pin);break;
											case 3:balance(pin);break;
											case 4:transaction_info(pin);break;
										}
										flag=1;
									}
									ptr1=ptr1->next;
								}
								if(flag==0)
								{
									cout<<"atm pin is wrong"<<endl;
									goto l1;
								}
							}
						}
						else
						{
							cout<<"wrong account number entered"<<endl;
							goto l1;
						}
						ptr=ptr->next;

					}
					goto l1;
				}
				else
				{
					cout<<"invalid option"<<endl;
					goto l1;
				}
			}
		}
		void withdraw(int pin)
		{
			dll *ptr=head;
			int wa;
			while(ptr)
			{
				if((ptr->pin)==pin)
				{
					cout<<"enter the amount to withdraw"<<endl;
					cin>>wa;
					if(wa<100)
					{
						cout<<"minimum amount to withdraw is 100 "<<endl;
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
