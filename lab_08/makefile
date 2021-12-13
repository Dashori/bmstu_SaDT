OUT = out/
SRC = src/
INC = inc/

CC := gcc
CFLAGS := -std=c99 -Werror -Wextra -Wall -Wpedantic -Wfloat-equal -Wfloat-conversion -Iinc
OBJS := $(OUT)print.o $(OUT)graph_func.o #$(OUT)tree_balance.o $(OUT)hash_func.o $(OUT)compare_structs.o
H :=  $(INC)print.h $(INC)exceptions.h $(INC)graph_func.h #$(INC)tree_balance.h $(INC)hash_func.h $(INC)compare_structs.h  
 
release: app.exe

app.exe: out $(OBJS) $(OUT)main.o
	$(CC) -o $@ $(OBJS) $(OUT)main.o -lm

out:
	mkdir out

$(OUT)print.o: $(SRC)print.c $(INC)print.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)graph_func.o: $(SRC)graph_func.c $(INC)graph_func.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)main.o: $(SRC)main.c $(H)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	$(RM) *.exe -r out