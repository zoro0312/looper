PLATFORM=PC
ROOT ?=.
SRCS = $(shell find . -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)
# OBJS_OUT = $(shell echo $(OBJS) | sed 's/././g')

INCLUDES = -I $(ROOT)/include
LIBS = -lpthread -lgtest -lgtest_main
CXX_FLAGS = -std=c++11 -g
CPP = g++
CC = gcc
AR = ar

lib: $(ROOT)/liblooper.so
	
$(ROOT)/%.o: $(SRCS)
	$(CPP) -fPIC -c $^ $(INCLUDES) $(CXX_FLAGS)

$(ROOT)/liblooper.so: $(ROOT)/%.o
	$(CPP) -shared $^ $(INCLUDES) $(LIBS) $(CXX_FLAGS) -o $@ 



clean:
	rm -rf *.o
	rm -rf *.out
