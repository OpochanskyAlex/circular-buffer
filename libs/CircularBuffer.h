/*
 * CircularBuffer.h
 *
 *  Created on: 10 апр. 2019 г.
 *      Author: Aleksandr
 */

#ifndef LIBS_CIRCULARBUFFER_H_
#define LIBS_CIRCULARBUFFER_H_

using namespace std;
#include <iostream>

class CircularBuffer {
public:
	enum SuccessStatus{
		OK = 0,
		UNKNOWNERROR = 1,
		OVERFLOW = 2,
		EMPTY = 3,
		OUTOFRANGE = 4,
		OUTOFTYPE = 5
	};
	uint16_t bufferSize = 0;
	int * mainBufferArray;
	uint16_t readPointer;
	uint16_t writePointer;
	CircularBuffer(uint16_t size);
	SuccessStatus pushElement(int * element);
	SuccessStatus popElement(int * element);
	SuccessStatus readElement(int * element, uint16_t elementOffset);
	bool isFull();
	bool isEmpty();
	uint16_t occupancy();
	virtual ~CircularBuffer();
};

#endif /* LIBS_CIRCULARBUFFER_H_ */
