#include <iostream>
#include <string.h>
#include <exception>
#include <assert.h>

using namespace std;


void lookForTag(int lenString, char sTag[], int lenTagString, char* &pIter) {\

	for (int i = 0; i < lenString; i++) {
		//zoom along till we find the first char

		if (*(pIter + i) == sTag[0]) {
			//found an a, lets see if it could be the start of a beautiful thing
			if (strncmp((pIter + i), sTag, lenTagString) == 0) {
				//got it whohoo, now what?
				cout<<"Found \'"<<sTag<<"\' in \'" <<pIter<<"\'"<<endl;
				return;
			}
		}
	}
}

int main() {
	//a pile of chars to search
	char myNewString[] = "A Litespeed Appalachain titanium cyclocross frame is really a beautiful thing";
	//a string inside above string
	char sTag[] = "a beautiful thing";

	//how long is it?
	int lenmyNewString = strlen(myNewString);
	int lenTagString = strlen(sTag);

	//start at the beginning
	char *pIter 	= &myNewString[0];
	lookForTag(lenmyNewString, sTag, lenTagString, pIter);
}
