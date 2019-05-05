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
	uint16_t bufferSize = 0;
	int * mainBufferArray;
	uint16_t readPointer;
	uint16_t writePointer;
	CircularBuffer(uint16_t size);
	bool writeElement(int * element);
	bool readElement(int * element);
	bool isFull();
	bool isEmpty();
	uint16_t occupancy();
	virtual ~CircularBuffer();
};

#endif /* LIBS_CIRCULARBUFFER_H_ */
