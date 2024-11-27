CC = cc
TARGETS = linear_fitting example
SRC = nrutil.c utils.c covsrt.c gaussj.c lfit.c
HDR = ./my_function.h ./nrutil.h



all: $(TARGETS)

linear_fitting: $(SRC) $(HDR)
	$(CC) -o linear_fitting main.c $(SRC) -lm

example: $(SRC) $(HDR)
	$(CC) -o example xlfit.c ran1.c org_lfit.c $(SRC) -lm

clean:
	rm -f $(TARGETS)