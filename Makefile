PROG = project04
OBJS = base.o scan.o parse.o evaltree.o project04.o

CFLAGS = -g

%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

all : $(PROG)

$(PROG) : project04.h $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

clean :
	rm -rf $(PROG) $(OBJS)
