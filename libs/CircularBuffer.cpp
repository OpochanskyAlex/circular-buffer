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


CircularBuffer::SuccessStatus CircularBuffer::pushElement(int  * element){
	SuccessStatus success = UNKNOWNERROR;
	if(isFull()){
		return OVERFLOW;
	}
	mainBufferArray[writePointer] = *element;
	if (++writePointer >= bufferSize){
		writePointer = 0;
	}
	success = OK;
	return success;
}

CircularBuffer::SuccessStatus CircularBuffer::popElement(int  * element){
	SuccessStatus success = UNKNOWNERROR;
	if(isEmpty()){
		return EMPTY;
	}
	*element = mainBufferArray[readPointer];
	if (++readPointer >= bufferSize){
		readPointer = 0;
	}
	success = OK;
	return success;
}

CircularBuffer::SuccessStatus CircularBuffer::readElement(int * element, uint16_t elementOffset){
	SuccessStatus success = UNKNOWNERROR;
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


