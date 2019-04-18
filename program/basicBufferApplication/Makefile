PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

PROJECT_NAME = basicBufferApplication

BUILD_DIR = build
EXECUTABLE = $(BUILD_DIR)/$(PROJECT_NAME)

#INCDIR += $(PROJECT_ROOT)/src
#INCDIR += $(PROJECT_ROOT)/../../libs

SOURCES += src/main.cpp
SOURCES += $(PROJECT_ROOT)/../../libs/CircularBuffer.cpp


ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else
	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))
#OBJECTS=$(SOURCES:.cpp=.o)
#$(error $(OBJECTS) OBJECTS)

all: directories $(EXECUTABLE).exe
	
directories: ${BUILD_DIR}

${BUILD_DIR}:
	mkdir -p $@
	
$(EXECUTABLE).exe: $(OBJECTS) 
	$(CXX) $(CFLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(SOURCES)
	$(CXX) -c $< -o $@ $(CFLAGS) 
#-I $(INCDIR)
clean:
	rm -fr $(BUILD_DIR)
