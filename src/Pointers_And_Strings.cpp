//============================================================================
// Name        : Pointers_And_Strings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : 10_Pointers_And_Strings.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <exception>
#include <assert.h>

using namespace std;

//probably want these macros active during debug and not during release builds.  So in debug build
//project, properties,c++ general, paths and symbols, symbols tab, add a symbol MY_DEBUG_SYMBOL in this case
//set it to 1, unfortunately this does not work in Kepler
#define MY_DEBUG_SYMBOL
#ifdef MY_DEBUG_SYMBOL
#define FTRACE1( a )	cout<<a<<" ..Line #"<<__LINE__<<" ..in file "<<__FILE__<<"\n";
#define FTRACE2( a,b)	cout<<a<<b<<" ..Line #"<<__LINE__<<" ..in file "<<__FILE__<<"\n";

#else
	#define FTRACE1(a){  };
	#define FTRACE2(a,b){  };
#endif



void lookForTag(int lenString, char sTag[], int lenTagString, char* &pIter) {\
	FTRACE1("In lookForTag");

	for (int i = 0; i < lenString; i++) {
		//zoom along till we find the first char

		if (*(pIter + i) == sTag[0]) {
			//found an a, lets see if it could be the start of a beautiful thing
			if (strncmp((pIter + i), sTag, lenTagString) == 0) {
				//got it whohoo, now what?
				FTRACE2("myString contains",sTag);
				return;
			}
		}
	}
}

//
//bool myFunc(char *pin)
//{
//	if ( !pIn )
//		return false;
//
//	unsigned int len =strlen(pIn);
//}
int main() {
	char myString[50] = "I dont think there are 50 chars here";

	//how long is the string?
	int lenString = strlen(myString);

	//how long is array
	int lenArray = sizeof(myString) / sizeof(char);
	cout << "myString string is " << lenString << " chars long, array is "<< lenArray << " chars long.\n";

	//fine to dereference past the end of the string up to size of array
	for (int i = 0; i < lenArray; i++)
		cout << myString[i];
	cout << "*DONE*" << std::endl;

	//probably only want to see the portion that is allocated though
	for (int i = 0; i < lenString; i++)
		cout << myString[i];
	cout << "*DONE*" << std::endl;

	////////////////////////////////////////////
	//lets look for something, how about string?
	char sTag[] = "a beautiful thing";

	//how long is it?
	int lenTagArray = sizeof(sTag) / sizeof(char);
	int lenTagString = strlen(sTag);
	cout << "sTag string is " << lenTagString << " chars long, array is "<< lenTagArray<< " chars long (char arrays are terminated with a \\0 which is the extra char).\n";

	//a pile of chars to search
	char myNewString[] = "A Litespeed Appalachain titanium cyclocross frame is really a beautiful thing";
	lenString = strlen(myNewString);

	//start at the beginning
	char *pIter 	= &myNewString[0];
	lookForTag(lenString, sTag, lenTagString, pIter);

	//how about we make a copy?
	char *pTemp = 0;
	int len = strlen(pIter) +1;	//add 1 for the terminating \0


	pTemp = new char[len];
	if ( pTemp ){
		//set it all to 0
		memset( pTemp, 0,  (len)* sizeof(char));

		//copy away
		strncpy(pTemp,pIter,len);
		string myNewString(pIter);
	}

	//clean up the wreakage
	if ( pTemp )
		delete [] pTemp;
	pTemp = NULL;
}
