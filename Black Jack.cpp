#include <iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>
using namespace std;

double poker[52];
double SumPoint;
char flower[4][10]={"Spade","Heart","Club","Diomand"};//The flowers of pokers
int counter;

void wash(){
	int i;
	for(i=1;i<=10;i++){
		poker[i-1]=i;
		poker[i+9]=i;
		poker[i+19]=i;
		poker[i+29]=i;	}
	for(i=40;i<52;i++)
	poker[i]=0.5; } 
	//washing pokers by reassigning the value of the array.
	
	
 void display(int n) {
 	char ch;
	if (n<40){if(n%10==9){
	 	cout<<flower[n/10]<<"10"<<endl;}
 		else cout<<flower[n/10]<<" "<<n%10+1;
		}
 	 else {switch(n%3)
 		{ case 0:ch='J';break;
		  case 1:ch='Q';break;
	 	  case 2:ch='K';break;  } 
	  cout<<flower[n%4]<<" "<<ch;
	  
		 }
	 }
	 
	 
  double send(double control){
 	int n;
 	srand(time(NULL));	 
	  
 	n=rand()*52/(RAND_MAX+1)+1;
 	do {n=rand()*52/(RAND_MAX+1)+1;
	 	 }
	 while (poker[n]==12);
 	display(n);
 	control+=poker[n];
 	poker[n]=12;//make the cards sent by random are different.
 	return control;
	  } 
	  
	  
 int player(){
 	int counter=2;
	int boom1=1;
 	char flag;
 	
 	wash();
 	cout<<"Now you have :"; 
 	SumPoint=send(SumPoint);cout<<" and ";SumPoint=send(SumPoint);
 	while(true){
 		char flag1;
 		cout<<"   "<<endl; 
 		cout<<"Want another card?(N/Y)"<<endl;
 		cin>>flag1;
		if(flag1=='Y'||flag=='y'){
		SumPoint=send(SumPoint);
		cout<<endl;
		counter++;
		cout<<"You have "<<SumPoint<<" point"<<endl;	} 
		else{cout<<"Now your total point:"<<SumPoint<<endl;
			if(SumPoint>21)
			{cout<<"Boom!You have more than 21 points.Lose!"<< endl;boom1=2;}//if boom==2,then the computer needn't to play.
			break; } 
		if (SumPoint>21)
		{cout<<"Boom!You have more than 21 points.Lose!"<<endl;
		boom1=2;
		return false;} }
	 return boom1; } 
 int main(){
 	int boom;
 	double ComSum;
	 int ComCot;
	 char ch;
	 srand(time(NULL)) ;
	 
	 while(true){	cout<<"The game start!"<<endl;
		 wash();
		 SumPoint=0;
		 counter=2;
		 boom=player();
		 
		 
		 if(boom==1){	cout<<"Now it's my turn!"<<endl;
			 wash();
			 ComSum=0;
			 cout<<"Now I have :";
			 ComSum=send(ComSum);
			 cout<<" and ";
			 ComSum=send(ComSum);
			 cout<<endl;
			 ComCot=2;
			 char flag2;
			 while(true){	cout<<endl<<"Will I take one more card?"<<endl;//whether take another one.
			 	if (ComSum<SumPoint){
			 		cout<<"Yes,Of course!"<<endl;
			 		flag2='Y';ComCot++; }
				else {
				flag2='N';cout<<"No,I needn't one more."<<endl;}
			      	
				
			 if (flag2=='Y')ComSum=send(ComSum) ;
			 else{cout<<"I have"<<ComSum<<" points"<<endl;
				  if (ComSum>21)
				  {cout<<"I'm boomed!You win!"<<endl;}
	     		else{if (SumPoint>ComSum)cout<<"You win!"<<endl;
			 		else if (SumPoint<ComSum) cout<<"I win!You lose!"<<endl;
			 		else {
			 			if(counter>ComCot)cout<<"You win!"<<endl;//judege the winner.
			 			if(counter<ComCot)cout<<"I win!You lose!"<<endl;
			 			else cout<<"Oh,we are in a tie!"<<endl;  }
				  }		 
				 break;	}  
				 } 
			 }
			 break;}
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
  
