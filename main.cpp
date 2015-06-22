#include <iostream>
#include "BigInt.h"

int main()
{
	BigInt add;
	int g;
	string sum1, sum2;
	vector<int> vec;
	//for(unsigned int i = 0; i < 2; ++i){}
	while(sum1 != "x"){
		cout<<"Enter two large integers:";
		cin>>sum1>>sum2;
		cout<<add.sumInt(sum1, sum2); 
		cout<<endl;
		cout<<add.multInt(sum1, sum2);
		cout<<endl;
	}
	cout<<endl;
	system ("pause");
	return 0;
}
