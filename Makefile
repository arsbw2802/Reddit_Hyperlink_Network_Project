EXENAME = finalproject 
OBJS = graph.o vertex.o edge.o main.o user_interface.o read_tsv.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic 
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

graph.o: graph.cpp graph.h edge.h vertex.h
	$(CXX) $(CXXFLAGS) graph.cpp

vertex.o: vertex.cpp vertex.h
	$(CXX) $(CXXFLAGS) vertex.cpp

edge.o: edge.cpp edge.h
	$(CXX) $(CXXFLAGS) edge.cpp

user_interface.o: user_interface.cpp user_interface.h graph.h read_tsv.h vertex.h edge.h
	$(CXX) $(CXXFLAGS) user_interface.cpp

read_tsv.o: read_tsv.cpp read_tsv.h
	$(CXX) $(CXXFLAGS) read_tsv.cpp

test: output_msg tests.o graph.o vertex.o edge.o
	$(LD) tests.o graph.o vertex.o edge.o $(LDFLAGS) -o test

tests.o: tests.cpp catch.hpp graph.h vertex.h edge.h
	$(CXX) $(CXXFLAGS) tests.cpp

clean:
	-rm -f *.o $(EXENAME) test 
  
remake: clean all