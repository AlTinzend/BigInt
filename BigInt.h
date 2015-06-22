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
		string multInt(string, string);
		
private:
		int whileInt(vector<int>&);

};

#endif
