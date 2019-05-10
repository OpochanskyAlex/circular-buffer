//============================================================================
// Name        : basicBufferApplication.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CircularBuffer.h"
using namespace std;



int main() {
	uint32_t myVar;
	int element;

	CircularBuffer MyBuffer(101U);

	//write 100 elements
	for (int i=0; i<100; ++i){
		element = i;
		cout << " write success " << MyBuffer.pushElement(&element) <<  endl;
		cout << " buffer occupancy " << MyBuffer.occupancy() <<  endl;
	}
	cout << " buffer full______________" << endl;

	//read 50 elements
	for (int i=0; i<50; ++i){
		cout << " read success " << MyBuffer.popElement(&element) ;
		cout << " extr " << element << " " <<  endl;
		cout << " buffer occupancy " << MyBuffer.occupancy() <<  endl;
	}
	cout << " red 50 elements______________" << endl;

	//write 50 elements and try to write another 50
	for (int i=0; i<100; ++i){
		element = i+100;
		cout << " write success " << MyBuffer.pushElement(&element) <<  endl;
		cout << " buffer occupancy " << MyBuffer.occupancy() <<  endl;
	}
	cout << "______________" << endl;

	bool readResult = MyBuffer.popElement(&element);
	while(readResult){
		cout << " read success " << readResult ;
		cout << " extr " << element << " " <<  endl;
		cout << " buffer occupancy " << MyBuffer.occupancy() <<  endl;
		readResult = MyBuffer.popElement(&element);
	}
	return 0;
}
