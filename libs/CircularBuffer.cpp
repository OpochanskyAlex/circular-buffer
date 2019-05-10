/*
 * CircularBuffer.cpp
 *
 *  Created on: 10 апр. 2019 г.
 *      Author: Aleksandr
 */

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(uint16_t size) {
	bufferSize = size;
	mainBufferArray = new int[bufferSize];
	//TODO think over: is read-write pointer better than start-end pointer
	readPointer = 0;
	writePointer = 0;
#ifdef DEBUG_COUT_INFO
	cout << "CircularBuffer object created" << endl; // prints !!!Hello World!!!
#endif

}


bool CircularBuffer::pushElement(int  * element){
	bool success = false;
	if(isFull()){
		return false;
	}
	mainBufferArray[writePointer] = *element;
	if (++writePointer >= bufferSize){
		writePointer = 0;
	}

	//*writePointer = *element; // pointer construction
	success = true;
	return success;
}

bool CircularBuffer::popElement(int  * element){
	bool success = false;
	if(isEmpty()){
		return false;
	}
	*element = mainBufferArray[readPointer];
	if (++readPointer >= bufferSize){
		readPointer = 0;
	}
	success = true;
	return success;
}

bool CircularBuffer::readElement(int * element, uint16_t elementOffset){
	bool success = false;
	//TODO add checks
	*element =   mainBufferArray[readPointer + elementOffset];
	return success;
}
bool CircularBuffer::isFull(){
	return occupancy() == (bufferSize - 1);
}
bool CircularBuffer::isEmpty(){
	return (readPointer == writePointer);
}
uint16_t CircularBuffer::occupancy(){
	//TODO test it is it really safe and optimal?
	uint16_t result;
	if (writePointer >= readPointer) {
		result = (uint16_t) (writePointer - readPointer);
	}
	else
	{
		result = (uint16_t)( bufferSize - readPointer + writePointer );
	}
	return  result;
}

CircularBuffer::~CircularBuffer() {
	// TODO Auto-generated destructor stub
}

