#include<iostream>
using namespace std;

class Player{
	static int matchstick;
	static int counter;

	public:
		static void turn(){
			int n;
			if(matchstick==1)
				{
					cout<<"You lost."<<endl;
					exit(0);
				}
			if(counter%2==0){
				cout<<"Enter the matchsticks:";
				cin>>n;
				matchstick-=n;
				counter++;
				cout<<"The remaining matchsticks are:"<<matchstick<<endl;
			}
			else{
				n=(matchstick-1)%5;
				cout<<"The computer took "<<n<<" matchsticks."<<endl;
				matchstick-=n;
				counter++;
			}
		}

};

int Player::matchstick=21;
int Player::counter=0;

int main(){
	Player user,computer;
	while(1){
		user.turn();
		computer.turn();
	}
}