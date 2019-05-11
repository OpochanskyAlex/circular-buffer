PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

PROJECT_NAME = testCircularBufferLibs

BUILD_DIR = build
EXECUTABLE = $(BUILD_DIR)/$(PROJECT_NAME)

INCDIR += src/
INCDIR += ../../libs/
INCDIR += ./

SOURCES += src/testCircularBufferLibs.cpp
SOURCES += ../../libs/CircularBuffer.cpp
SOURCES += gtest/gtest-all.cc

DEFINES += -DDEBUG_COUT_INFO
ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g 
	CFLAGS += $(DEFINES)
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else
	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif


OBJECTS := $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES)))
OBJECTS := $(OBJECTS:.cpp=.o)
OBJECTS := $(OBJECTS:.cc=.o)
#$(error $(OBJECTS))
VPATH = build:src:../../libs:gtest

all: directories $(EXECUTABLE).exe
	
directories: ${BUILD_DIR}

${BUILD_DIR}:
	mkdir -p $@
	
$(EXECUTABLE).exe: $(OBJECTS)
	$(CXX) -o $@ $(CFLAGS) $(OBJECTS) $(addprefix -I ,$(INCDIR))

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS) $(addprefix -I ,$(INCDIR)) 
	
$(BUILD_DIR)/%.o: %.cc
	$(CXX) -o $@ -c $< $(CFLAGS) $(addprefix -I ,$(INCDIR)) 
	
clean:
	rm -fr $(BUILD_DIR)
