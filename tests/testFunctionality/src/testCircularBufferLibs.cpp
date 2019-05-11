#include "gtest/gtest.h"
#include "CircularBuffer.h"

#define BUFFERSIZE 101U
TEST(BufferTests,pushAndPop1Element){
	CircularBuffer MyBuffer(BUFFERSIZE);
	int elementPush, elementPop;
	elementPush = 5;
	ASSERT_EQ(MyBuffer.OK, MyBuffer.pushElement(&elementPush));
	ASSERT_EQ(MyBuffer.OK, MyBuffer.popElement(&elementPop));
	ASSERT_EQ(elementPush,elementPop);

}

TEST(BufferTests, pushAndPopFull){
	CircularBuffer MyBuffer(BUFFERSIZE);
	int elementPush, elementPop;
	//fill full buffer
	for (int i=0;i < BUFFERSIZE - 1; i++){
		elementPush = i;
		ASSERT_EQ(MyBuffer.OK, MyBuffer.pushElement(&elementPush));
	}
	//buffer must reject write
	elementPush = 0;
	ASSERT_EQ(MyBuffer.OVERFLOW, MyBuffer.pushElement(&elementPush));

	//read all elements
	for (int i=0;i < BUFFERSIZE - 1; i++){
		ASSERT_EQ(MyBuffer.OK, MyBuffer.popElement(&elementPop));
		ASSERT_EQ(elementPop,i);
	}
	//buffer must be free
	ASSERT_EQ(0, MyBuffer.occupancy());
}

TEST(BufferTests, pushAndPopOverstep){
	CircularBuffer MyBuffer(BUFFERSIZE);
	int elementPush, elementPop;
	//fill full buffer
	for (int i=0;i < BUFFERSIZE - 1; i++){
		elementPush = i;
		ASSERT_EQ(MyBuffer.OK, MyBuffer.pushElement(&elementPush));
	}
	//buffer must reject write
	elementPush = 0;
	ASSERT_EQ(MyBuffer.OVERFLOW, MyBuffer.pushElement(&elementPush));

	//read half elements
	for (int i=0;i < BUFFERSIZE/2 - 1; i++){
		ASSERT_EQ(MyBuffer.OK, MyBuffer.popElement(&elementPop));
		ASSERT_EQ(elementPop,i);
	}
	//fill buffer
	elementPush = BUFFERSIZE - 1;
	while(MyBuffer.pushElement(&elementPush) == MyBuffer.OK){
		elementPush++;
	}
	//empty buffer. numbers have to follow one by one
	int readResult = MyBuffer.popElement(&elementPop);
	ASSERT_EQ(MyBuffer.OK, readResult);
	int elementExpected = elementPop;

	while(readResult == MyBuffer.OK){
		readResult = MyBuffer.popElement(&elementPop);
		if( readResult != MyBuffer.OK){continue;}
		ASSERT_EQ(++elementExpected, elementPop);
	}
	//buffer must be empty
	ASSERT_EQ(MyBuffer.EMPTY, MyBuffer.popElement(&elementPop));
	ASSERT_EQ(0, MyBuffer.occupancy());
}

TEST(BufferTests, DISABLED_readtestBasic){
	//TODO: implement TEST(BufferTests,readtestBasic)
}

TEST(BufferTests, DISABLED_readtestOverstep){
	//TODO: implement TEST(BufferTests,readtestOverstep)
}

int main(int argc,char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


