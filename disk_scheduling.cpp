#include<bits/stdc++.h>
using namespace std;

int i;

void FCFS(vector<int> requests, int n, long long int head_move, int curr)
{
    cout<<"Order of requests entertained: ";
    for(int i=0;i<n;i++)
    cout<<requests[i]<<" ";
    cout<<endl;
    head_move = abs(curr-requests[0]);
    for(int i=1;i<n;i++)
        head_move+=abs(requests[i]-requests[i-1]);
    cout<<"Total movements of the head: "<<head_move<<endl;
}

void SSTF(vector<int> requests, int n, long long int head_move, int curr)
{
    int pos=0,min=abs(requests[0]-curr);
	cout<<"Order of requests entertained: ";
	for(i=0;i<n;i++)
	if(abs(requests[i]-curr)<min)
	{
	    pos=i;
		min=abs(requests[i]-curr);
	}
	cout<<requests[pos]<<" ";
	head_move=min;
	curr=requests[pos];
	requests.erase(requests.begin()+pos);
	while(requests.size())
	{
	    pos=0,min=abs(requests[0]-curr);
		for(i=0;i<requests.size();i++)
			if(abs(requests[i]-curr)<min)
			    {
					pos=i;
					min=abs(requests[i]-curr);
				}
		cout<<requests[pos]<<" ";
		head_move+=min;
		curr=requests[pos];
		requests.erase(requests.begin()+pos);
	}
	cout<<endl;
	cout<<"Total movements of the head: "<<head_move<<endl;
}

void SCAN(vector<int> requests, int n, long long int head_move, int curr, int cylinders)
{
    int dir;
	cout<<"Enter direction of head movement (0-left or 1-right): ";
	cin>>dir;
	sort(requests.begin(),requests.end());
	cout<<"Order of requests entertained: ";
	if(dir==0)
	{
		for(i=n-1;i>=0;i--)
		{
			if(requests[i]<=curr)
				break;
		}
		head_move=curr;
		int j;
		for(j=i;j>=0;j--)
			cout<<requests[j]<<" ";
		requests.erase(requests.begin(),requests.begin()+i+1);
		if(requests.size())
		{
			head_move+=requests[requests.size()-1];
			for(j=0;j<requests.size();j++)
				cout<<requests[j]<<" ";
				cout<<endl;
		}
		cout<<"Total movements of the head: "<<head_move<<endl;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(requests[i]>=curr)
				break;
		}
		head_move=cylinders -1 - curr;
		int j;
		for(j=i;j<requests.size();j++)
		    cout<<requests[j]<<" ";
		requests.erase(requests.begin() + i,requests.end());
		if(requests.size())
		{
		    head_move+=cylinders-1-requests[0];
			for(j=requests.size()-1;j>=0;j--)
				cout<<requests[j]<<" ";
				cout<<endl;
		}
		cout<<"Total movements of the head: "<<head_move<<endl;
    }
}

void C_SCAN(vector<int> requests, int n, long long int head_move, int curr, int cylinders)
{
    int dir;
	cout<<"Enter direction of head movement (0-left or 1-right): ";
	cin>>dir;
	sort(requests.begin(),requests.end());
	cout<<"Order of requests entertained: ";
	if(dir==0)
	{
		for(i=n-1;i>=0;i--)
		{
			if(requests[i]<=curr)
				break;
		}
		head_move=curr;
		int j;
		for(j=i;j>=0;j--)
		cout<<requests[j]<<" ";
		requests.erase(requests.begin(),requests.begin()+i+1);
		if(requests.size())
		{
			head_move+=cylinders-1;
			head_move+=cylinders - 1 - requests[0];
			for(j=requests.size()-1;j>=0;j--)
				cout<<requests[j]<<" ";
				cout<<endl;
		}
		cout<<"Total movements of the head: "<<head_move<<endl;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(requests[i]>=curr)
				break;
		}
		head_move=cylinders -1 - curr;
		int j;
		for(j=i;j<requests.size();j++)
			cout<<requests[j]<<" ";
	    requests.erase(requests.begin() + i,requests.end());
		if(requests.size())
		{
			head_move+=cylinders-1;
			head_move+=requests[requests.size()-1];
			for(j=0;j<requests.size();j++)
				cout<<requests[j]<<" ";
				cout<<endl;
		}
		cout<<"Total movements of the head: "<<head_move<<endl;
	}
}

void LOOK(vector<int> requests, int n, long long int head_move, int curr)
{
	int dir;
	cout<<"Enter direction of head movement (0-left or 1-right): ";
    cin>>dir;
	sort(requests.begin(),requests.end());
	cout<<"Order of requests entertained: ";
	if(dir==0)
	{
	    for(i=n-1;i>=0;i--)
		{
			if(requests[i]<=curr)
				break;
		}
		head_move=curr-requests[0];
		int j;
		for(j=i;j>=0;j--)
			cout<<requests[j]<<" ";
		int temp = requests[0];
		requests.erase(requests.begin(),requests.begin()+i+1);
		if(requests.size())
		{
			head_move+=requests[requests.size()-1] - temp;
			for(j=0;j<requests.size();j++)
				cout<<requests[j]<<" ";
				cout<<endl;
		}
		cout<<"Total movements of the head: "<<head_move<<endl;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(requests[i]>=curr)
				break;
		}
		head_move=requests[requests.size()-1] - curr;
		int j;
		for(j=i;j<requests.size();j++)
			cout<<requests[j]<<" ";
		int temp = requests[requests.size()-1];
		requests.erase(requests.begin() + i,requests.end());
		if(requests.size())
		{
			head_move+=temp-requests[0];
			for(j=requests.size()-1;j>=0;j--)
				cout<<requests[j]<<" ";
				cout<<endl;
		}

		cout<<"Total movements of the head: "<<head_move<<endl;
	}
}

void C_LOOK(vector<int> requests, int n, long long int head_move, int curr)
{
	int dir;
	cout<<"Enter direction of head movement (0 for left and 1 for right): ";
	cin>>dir;
	sort(requests.begin(),requests.end());
	cout<<"Order of requests entertained: ";
	if(dir==0)
	{
		for(i=n-1;i>=0;i--)
		{
			if(requests[i]<=curr)
				break;
		}
		head_move=curr-requests[0];
		int j;
		for(j=i;j>=0;j--)
	    	cout<<requests[j]<<" ";
		int temp = requests[0];
		requests.erase(requests.begin(),requests.begin()+i+1);
		if(requests.size())
		{
			head_move+=requests[requests.size()-1]-temp;
			head_move+=requests[requests.size()-1] - requests[0];
			for(j=requests.size()-1;j>=0;j--)
			cout<<requests[j]<<" ";
			cout<<endl;
		}
		cout<<"Total movements of the head: "<<head_move<<endl;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(requests[i]>=curr)
	    		break;
		}
		head_move=requests[requests.size()-1] - curr;
		int j;
		for(j=i;j<requests.size();j++)
			cout<<requests[j]<<" ";
		int temp = requests[requests.size()-1];
		requests.erase(requests.begin() + i,requests.end());
		if(requests.size())
		{
			head_move+=temp - requests[0];
			head_move+=requests[requests.size()-1] - requests[0];
			for(j=0;j<requests.size();j++)
				cout<<requests[j]<<" ";
			cout<<endl;
		}
		cout<<"Total movements of the head: "<<head_move<<endl;
	}
}

int main()
{
	int cylinders=0,n=0,curr=0;
	cout<<"Number of cylinders: ";
	cin>>cylinders;
	while(!n)
	{
	    cout<<"Enter the no of requests (min 1 and max 10) ";
        cin>>n;
    }
	cout<<"Current position of head: ";
	cin>>curr;
	vector<int> requests(n);
	cout<<"Enter the request queue: ";
	int i;
	for(i=0;i<n;i++)
        cin>>requests[i];
	int c;
	cout<<"Select an algorithm for disk scheduling:   ";
	cout<<"1. FCFS \t";
	cout<<"2. SSTF \t";
	cout<<"3. SCAN \t";
	cout<<"4. C-SCAN \t";
	cout<<"5. LOOK \t";
	cout<<"6. C_LOOK \t"<<endl;
	cout<<"Press a suitable key between 1-6: ";
	cin>>c;
	cout<<endl;
	long long int head_move=0;
	switch(c)
	{
		case 1:
		{
		    cout<<"FCFS ALGORITHM: "<<endl;
		    FCFS(requests, n, head_move, curr);
			break;
		}
		case 2:
		{
		    cout<<"SSTF ALGORITHM: "<<endl;
		    SSTF(requests, n, head_move, curr);
			break;

		}
		case 3:
		{
		    cout<<"SCAN ALGORITHM: "<<endl;
		    SCAN(requests, n, head_move, curr, cylinders);
			break;
		}
		case 4:
		{
		    cout<<"C-SACN ALGORITHM: "<<endl;
		    C_SCAN(requests, n, head_move, curr, cylinders);
			break;
		}
		case 5:
		{
		    cout<<"LOOK ALGORITHM: "<<endl;
		    LOOK(requests, n, head_move, curr);
			break;
		}
		case 6:
		{
		    cout<<"C-LOOK ALGORITHM: "<<endl;
		    C_LOOK(requests, n, head_move, curr);
			break;
		}
		default:
		{
			cout<<"Invalid choice"<<endl;
		}
	}
	return 0;
}
