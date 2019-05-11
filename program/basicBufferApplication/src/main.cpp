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

#define BUFFERSIZE 101U

//hehe I have tried to amend commit, which was already pushed

int main() {
	uint32_t myVar;
	int element;

	CircularBuffer MyBuffer(BUFFERSIZE);

	//write 100 elements
	for (int i=0; i < BUFFERSIZE-1; ++i){
		element = i;
		cout << " write error " << MyBuffer.pushElement(&element) <<  endl;
		cout << " buffer occupancy " << MyBuffer.occupancy() <<  endl;
	}
	cout << " buffer full______________" << endl;

	//read 50 elements
	for (int i=0; i<BUFFERSIZE/2; ++i){
		cout << " read error " << MyBuffer.popElement(&element) ;
		cout << " extr " << element << " " <<  endl;
		cout << " buffer occupancy " << MyBuffer.occupancy() <<  endl;
	}
	cout << " pop 50 elements______________" << endl;
/*
	MyBuffer.readElement(&element,10);
	cout << " read +10 " << element << " " <<  endl;
	//write 50 elements and try to write another 50
	for (int i=0; i < BUFFERSIZE-1; ++i){
		element = i+100;
		cout << " write error " << MyBuffer.pushElement(&element) <<  endl;
		cout << " buffer occupancy " << MyBuffer.occupancy() <<  endl;
	}
	cout << "______________" << endl;
*/
	//fill buffer
	element = BUFFERSIZE - 1;
	while(MyBuffer.pushElement(&element) == MyBuffer.OK){
		element++;
	}

	int readResult = MyBuffer.popElement(&element);
	while(readResult == MyBuffer.OK){
		cout << " read error " << readResult ;
		cout << " extr " << element << " " <<  endl;
		cout << " buffer occupancy " << MyBuffer.occupancy() <<  endl;
		readResult = MyBuffer.popElement(&element);
	}
	return 0;
}
