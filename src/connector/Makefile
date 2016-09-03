include ../head.mk

OBJ=blocking_queue

%.o: %.cc
	$(CXX) -c $(CXXFLAGS) $<

all: $(addsuffix .o, ${OBJ})
	${AR} ${ARFLAGS} libconnector.a $(addsuffix .o, ${OBJ})
