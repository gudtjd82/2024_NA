CC = cc
TARGETS = example
SRC = nrutil.c utils.c covsrt.c gaussj.c
HDR = ./my_function.h ./nrutil.h



all: $(TARGETS)

example: $(SRC) $(HDR)
	$(CC) -o example xlfit.c ran1.c org_lfit.c $(SRC) -lm

clean:
	rm -f $(TARGETS)