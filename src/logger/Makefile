include ../head.mk

all: logger.cc
	$(CXX) $(CXXFLAGS) -c -o $(patsubst %.cc,%.o,$<) $<
	
test: unit_test_* logger.o
	$(MAKE)
	$(CXX) $(CXXFLAGS) -o $(patsubst %.cc,%,$<) $^

clean:
	rm *.o
