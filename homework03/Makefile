CC = cc
TARGETS = sol_gje sol_lud sol_svd sol_mprove find_det_inv
SRC = nrutil.c pythag.c ludcmp.c gaussj.c lubksb.c svdcmp.c svbksb.c utils.c mprove.c
HDR = ./my_function.h ./nrutil.h



all: $(TARGETS)

sol_gje: $(SRC) $(HDR)
	$(CC) -o sol_gje sol_gje.c $(SRC)

sol_lud: $(SRC) $(HDR)
	$(CC) -o sol_lud sol_lud.c $(SRC)

sol_svd: $(SRC) $(HDR)
	$(CC) -o sol_svd sol_svd.c $(SRC)

sol_mprove: $(SRC) $(HDR)
	$(CC) -o sol_mprove sol_mprove.c $(SRC)

find_det_inv: $(SRC) $(HDR)
	$(CC) -o find_det_inv find_det_inv.c $(SRC)

clean:
	rm -f $(TARGETS)