#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

int main()
{	int num1,num2,num3,gus1,gus2,gus3,i,counterA,counterB ,lose=0 ,win=0; 
	char flag;
	while(true){
		cout<<"Want to play the game?(N/Y)"<<endl;
		cin>>flag;
		if (flag=='N'){
		cout<<"You have played" <<win+lose<<"times,"<<"won"<<win<<"times,"<<"lost"<<lose<<"times"<<endl; 
		break;}	
		//control whether to play again
	srand(time(NULL)) ;
	num1=rand()*10/(RAND_MAX+1);
	
	do{num2=rand()*10/(RAND_MAX+1);

	}while(num1==num2);
	
	do{num3=rand()*10/(RAND_MAX+1);
	
	}while(num3==num2||num3==num1);
	
	//generate three different numbers
	
	counterA=0;
	counterB=0;
	i=0;
	
	while(i<=6){
	    counterA=0; 
	    counterB=0; 
		cout<<"Please input your guess:\n";
		cin>>gus1>>gus2>>gus3;	
		if (gus1==num1)	counterA++;
		if (gus2==num2)	counterA++;
		if (gus3==num3)	counterA++;
		
		//the counting of A
		
		if (gus1==num2||gus1==num3)	counterB++;
		if (gus2==num1||gus2==num3)	counterB++;
		if (gus3==num1||gus3==num2)	counterB++;
		cout<<counterA<<"A"<<counterB<<"B"<<endl;
		i++;
		
		//the counting of B
		if (counterA==3)
		{
		win++;
		cout<<"Congratulations!You win!" <<endl;
		break;
		//the judge of win
		}		
	}
    if (i==7)
	{
	cout<<"Sorry,your chances are used out.And the answer is :"<<num1<<num2<<num3 <<endl;
	lose++;}
}
}	
