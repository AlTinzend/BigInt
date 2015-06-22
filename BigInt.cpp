//Big integer member-function definitions.

#include <iostream>
#include "BigInt.h"

string BigInt::multInt(string a, string b){
	vector<int> vec;
	string c = b;
	for(unsigned int i = 0; i < a.size(); ++i){
		int t = a[i] - 48;
		vec.push_back(t);
	}
	whileInt(vec);
	while(whileInt(vec)){b = sumInt(b, c);}
	return b;
}

int BigInt::whileInt(vector<int>& funcvec){
	int zerosearch = 0;
	for(unsigned int k = 0; k < funcvec.size(); ++k){
		if(funcvec[k] == 0){zerosearch++;}
		if(zerosearch == funcvec.size()){return 0;}
	}
	int iter = funcvec.size()-1;
	int carry = 0;
	if(funcvec[iter] != 0){
		funcvec[iter] -= 1;
		return 1;
	}
	else{
		carry = 1;
		while(carry == 1 && iter >= 0){
			funcvec[iter] = 9;
			iter--;
			if(funcvec[iter] > 0){
				funcvec[iter] -= 1;
				return 1;
			}
			else{
				funcvec[iter] = 9;
				carry = 1;
			}			
	    }
		return 0;
	}
}

string BigInt::sumInt(string a, string b){
	string c;
	int carry = 0;
	int sizea = a.size();
	int sizeb = b.size();
	int diff = sizea - sizeb;
	if(diff < 0){diff *= (-1);}

	vector<int> alpha;
	vector<int> beta;
	vector<int> sum;

	//create string of zeros to pad smaller string
	string padding;
	while(diff--){padding += '0';}

	//pad the smaller string
	if(sizea > sizeb){b = padding + b;}
	else if(sizeb > sizea){a = padding + a;}
	else{}
	
	//convert string a to vector of ints
	for(unsigned int i = 0; i <= a.length()-1; i++){
		int a1 = a[i] - 48;
		alpha.push_back(a1);
	}
	
	//convert string b to vector of ints
	for(unsigned int k = 0; k <= b.length()-1; k++){
		int b1 = b[k] - 48;
		beta.push_back(b1);
	}
	//step trough smaller adding ints
	for(int j = b.size()-1; j >= 0; j--){   
		int add = beta[j] + alpha[j] + carry;
		if(carry == 1){carry = 0;}
		if(add >= 10){
				sum.push_back(add%10);
				carry = 1;
			}
		else{sum.push_back(add);}
	}
	if(carry == 1){sum.push_back(1);}

	//convert int vec to string.
	for(unsigned int x = 0; x < sum.size(); x++){
		char y = sum[x] + 48;
		c = y + c;
	}
	return c;
}
