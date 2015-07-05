//Big integer handling class, header file
//class declaration

#include <string>
#include <vector>

#ifndef BIGINT_H
#define BIGINT_H

using namespace std;

class BigInt{
	//BigInt();
public:
		string sumInt(string, string);
		string subInt(string, string);
		string multXInt(string, string);
		
private:
		int whileInt(vector<int>&);
		string vecToString(vector<int>&);
};

#endif
