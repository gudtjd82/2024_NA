CC = cc
TARGETS = generate_rand_num
SRC = nrutil.c ran1.c gasdev.c
HDR = ./my_function.h ./nrutil.h



all: $(TARGETS)

generate_rand_num: $(SRC) $(HDR)
	$(CC) -o generate_rand_num main.c $(SRC)

clean:
	rm -f $(TARGETS)