#include<bits/stdc++.h>
using namespace std;

class Bank
{
	public:
	string name;
	int account_number;
	string type_account;
	float balance;
	void indetail(string na,int n,string t,float ba)
	{
		name=na;
		account_number=n;
		type_account=t;
		balance=ba;
	}
	void depost(float money)
	{
		balance+=money;
	}
	void withdraw(float wmoney)
	{
		if(wmoney<=balance)
		{
		   balance-=wmoney;
		   cout<<"Withdrawl done rupees "<<wmoney<<endl;
	    }
		else
		cout<<"Insufficent funds"<<endl;
		cout<<"Avaiable Funds are "<<balance<<endl;
	}
	void funds_available()
	{
		cout<<"Name of the account Holder "<<name<<endl;
		cout<<"Avaiable Funds are "<<balance<<endl;
	}
};
int main()
{
	Bank c1;
	c1.indetail("Mukesh",9342624272843294,"savings_account",2000);
	c1.depost(20.0);
	c1.funds_available();
	c1.withdraw(20);
	c1.withdraw(4000);
	
}
