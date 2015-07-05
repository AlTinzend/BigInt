#include <iostream>
#include "BigInt.h"

int main()
{
	BigInt add;
	char action;
	string num1, num2;
	while(num1 != "x"){
		cout<<"Enter two large integers seperated by operand(+,-,*):"<<endl;
		cin>>num1>>action>>num2;
			if(action == '+'){
				cout<<add.sumInt(num1, num2);
				cout<<endl;
			}
			else if(action == '-'){
				cout<<add.subInt(num1, num2);
				cout<<endl;
			}
			else if(action == '*'){
				cout<<add.multXInt(num1, num2);
				cout<<endl;
			}
			else{cout<<"Error unknown request.\n";}
		
	}
	cout<<endl;
	system ("pause");
	return 0;
}
