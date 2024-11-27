CC = cc
CFLAGS = -I ../NRs/ansi/other
TARGET = rootFinding
SRC_DIR = ../NRs/ansi/recipes
SRC = main.c $(SRC_DIR)/zbrak.c $(SRC_DIR)/bessj0.c $(SRC_DIR)/bessj1.c $(SRC_DIR)/rtsafe.c ../NRs/ansi/other/nrutil.c rtbis.c rtflsp.c rtsec.c rtnewt.c rtsafe.c muller.c kepler.c
HDR = ../NRs/ansi/other/nr.h

$(TARGET): $(SRC) $(HDR)
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS)

clean:
	rm -f$(TARGET)