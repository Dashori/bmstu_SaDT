OUT = out/
SRC = src/
INC = inc/

CC := gcc
CFLAGS := -std=c99 -Werror -Wextra -Wall -Wpedantic -Wfloat-equal -Wfloat-conversion -Iinc
OBJS := $(OUT)print.o $(OUT)tree_func.o $(OUT)tree_balance.o 
H :=  $(INC)print.h $(INC)exceptions.h $(INC)tree_func.h $(INC)tree_balance.h 
 
release: app.exe

app.exe: out $(OBJS) $(OUT)main.o
	$(CC) -o $@ $(OBJS) $(OUT)main.o -lm

out:
	mkdir out

$(OUT)print.o: $(SRC)print.c $(INC)print.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)tree_func.o: $(SRC)tree_func.c $(INC)tree_func.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)tree_balance.o: $(SRC)tree_balance.c $(INC)tree_balance.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)main.o: $(SRC)main.c $(H)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	$(RM) *.exe -r out