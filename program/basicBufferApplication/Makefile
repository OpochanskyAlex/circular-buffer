PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

EXECUTABLE = basicBufferApplication
BUILD_DIR = build
INCDIR += $(PROJECT_ROOT)/src

SOURCES += src/main.cpp

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else
	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

#OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))
OBJECTS=$(SOURCES:.cpp=.o)
#$(error $(SOURCES) SOURCES)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@
	
.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@
	
	
clean:
	rm -fr $(BUILD_DIR)
