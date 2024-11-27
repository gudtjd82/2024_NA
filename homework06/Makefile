CC = cc
TARGETS = linear_fitting
SRC = nrutil.c utils.c
HDR = ./my_function.h ./nrutil.h



all: $(TARGETS)

linear_fitting: $(SRC) $(HDR)
	$(CC) -o linear_fitting main.c $(SRC)

clean:
	rm -f $(TARGETS)