PROG = carafe
SRCS = carafe.cc main.cc
OBJS = $(SRCS:%.cc=%.o)

%.o: %.cc
	g++ -g -O0 -c $^ -o $@

all: $(PROG)

.PHONY: all clean

$(PROG): $(OBJS)
	g++ -g -o0 $(OBJS) -o $@

clean:
	rm -f carafe *.o *~
