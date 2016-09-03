include ../head.mk

OBJ= singleton

%.o: %.cc
	$(CXX) -c $(CXXFLAGS) $<

all: $(addsuffix .o, ${OBJ})
	${AR} ${ARFLAGS} libcore.a $(addsuffix .o, ${OBJ})
