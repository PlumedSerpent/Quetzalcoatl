#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

int main()
{	int num1,num2,num3,gus1,gus2,gus3,i,counterA,counterB ,lose=0 ,win=0; 
	char flag;
	while(true){
		cout<<"需要玩游戏吗？（N/Y)"<<endl;
		cin>>flag;
		if (flag=='N'){
		cout<<"你一共玩了" <<win+lose<<"局,"<<"赢了"<<win<<"局,"<<"输了"<<lose<<"局"<<endl; 
		break;}	
	srand(time(NULL)) ;
	num1=rand()*10/(RAND_MAX+1);
	
	do{num2=rand()*10/(RAND_MAX+1);

	}while(num1==num2);
	
	do{num3=rand()*10/(RAND_MAX+1);
	
	}while(num3==num2||num3==num1);
	cout<<num1<<num2<<num3<<endl;
	counterA=0;
	counterB=0;
	i=0;
	while(i<=6){
	    counterA=0; 
	    counterB=0; 
		cout<<"请输入你猜测的数字：\n";
		cin>>gus1>>gus2>>gus3;
		
		
		if (gus1==num1)	counterA++;
		if (gus2==num2)	counterA++;
		if (gus3==num3)	counterA++;
		
		
		if (gus1==num2||gus1==num3)	counterB++;
		if (gus2==num1||gus2==num3)	counterB++;
		if (gus3==num1||gus3==num2)	counterB++;
		
		
		cout<<counterA<<"A"<<counterB<<"B"<<endl;
		
		i++;
		if (counterA==3)
		{
		win++;
		cout<<"恭喜你，猜对了！" <<endl;
		break;}
		
	}
    if (i==7)
	{
	cout<<"很遗憾，你没有在规定次数内猜对。答案是："<<num1<<num2<<num3 <<endl;
	lose++;}
}
}	
