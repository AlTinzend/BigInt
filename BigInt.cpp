//Big integer member-function definitions.

#include <iostream>
#include "BigInt.h"


/////////////////////////////////////////////////
////Multiplies string no. a by string no. b//////
/////////////////////////////////////////////////
string BigInt::multXInt(string a, string b){
	int zeros, counter(0);
	string temp;
	string passer;
	string total = "0";
	vector<int> vec;

	//find bigger string to optimise algorithm
	if(b.size() > a.size()){
		temp = b;
		b = a;
		a = temp;
	}
	else if(a.size() == b.size()){
		if(a[0] < b[0]){
			temp = b;
			b = a;
			a = temp;
		}
	}

	//convert larger string a to vector of ints
	for(unsigned int i = 0; i < a.length(); i++){
		int a1 = a[i] - 48;
		vec.push_back(a1);
	}

	//create vector to store answer
	
	counter = b.size();
	while(counter--){				//step through smaller string
		passer = "";
		int m = b[counter] - 48;
		int carry = 0;
		int hold;
		vector<int> vec1(vec.size(), 0);
		for(int j = vec.size()-1; j >= 0; --j){//multiply larger string
			hold = m*vec[j] + carry;		   //by each digit of smaller
			carry = 0;
			if(hold > 9){
				vec1[j] = hold%10;
				carry = hold/10;
			}
			else{
				vec1[j] = hold;
				carry = 0;
			}			
		}

		//Add remaining carry to front of mult vector
		if(carry != 0){
			vec1.insert(vec1.begin(), carry);
			carry = 0;
		}

		//Add zeros for different layer of mult eg"0"for tens,"00" for 100s etc
		
		zeros = b.size() - (counter+1);
		string zs = "";
		while(zeros--){
			zs = zs + "0";
		}

		//convert this layer of multiplication to string
		passer = vecToString(vec1) + zs;
		total = sumInt(total, passer);
	}
	return total;

	
}

////////////////////////////////////////////
//////Iterates through vector of ints///////
////////////////////////////////////////////
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
//////////////////////////////////////////
////Adds no. string a to no. string b/////
//////////////////////////////////////////
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

//////////////////////////////////////////////
///Subtracts no. string b from no. string a///
//////////////////////////////////////////////
string BigInt::subInt(string a, string b){
	string c;
	int carry = 0;
	int sizea = a.size();
	int sizeb = b.size();
	int diff = sizea - sizeb;
	if(diff < 0){diff *= (-1);}

	vector<int> alpha;
	vector<int> beta;
	vector<int> subtract;

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
	//step trough subtracting ints
	for(int j = a.size()-1; j >= 0; j--){   
		int sub = alpha[j] - (beta[j] + carry);
		if(carry == 1){carry = 0;}
		if(sub < 0){
				subtract.push_back(sub + 10);
				carry = 1;
			}
		else{subtract.push_back(sub);}
	}
	if(carry == 1){subtract.push_back(1);}

	//convert int vec to string.
	for(unsigned int x = 0; x < subtract.size(); x++){
		char y = subtract[x] + 48;
		c = y + c;
	}
	//Remove preceeding zeros.
	while(c[0]== '0'){c.erase(c.begin());} 
	return c;
}

/////////////////////////////////////////
/////Int Vector to String conversion/////
/////////////////////////////////////////
string BigInt::vecToString(vector<int>& funcVec){
	char member;
	string conv = "";
	for(unsigned int i = 0; i < funcVec.size(); ++i){
		member = funcVec[i] + 48;
		conv = conv + member;
	}
	return conv;
}
