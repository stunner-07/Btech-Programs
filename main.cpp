#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter the size of memory: ";
    int n, i, c=0, m=1;
    cin>>n;
    int arr[n]={0};
    while(m)
    {
        cout<<"Enter the size of file: ";
        int t;
        cin>>t;
        c=0;
            for(i=0; i<n; i++)
            {

                if(arr[i]==0)
                    c++;
                else
                    c=0;
                if(c==t)
                {
                    //arr[i]=1;
                    arr[i-c+1]=2;
                    for(int j=i-c+2; j<=i; j++)
                        arr[j]=1;
                    break;

                }
            }

            if(c<t)
            cout<<"Not enough space!"<<endl;
            else
                cout<<"Space has been allocated."<<endl;
            cout<<"Do you want to ccontinue(1/0): ";
            cin>>m;
    }

    for(i=0; i<n; i++)
        cout<<arr[i]<<endl;
}
