OUT = out/
SRC = src/
INC = inc/

CC := gcc
CFLAGS := -std=c99 -Werror -Wextra -Wall -Wpedantic -Wfloat-equal -Wfloat-conversion -Iinc
OBJS := $(OUT)print.o $(OUT)structs.o $(OUT)array.o $(OUT)list.o
H :=  $(INC)print.h $(INC)exceptions.h  $(INC)structs.h $(INC)array.h $(INC)list.h 
 
release: app.exe

app.exe: out $(OBJS) $(OUT)main.o
	$(CC) -o $@ $(OBJS) $(OUT)main.o -lm

out:
	mkdir out

$(OUT)array.o: $(SRC)array.c $(INC)array.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)list.o: $(SRC)list.c $(INC)list.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)structs.o: $(SRC)structs.c $(INC)structs.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)print.o: $(SRC)print.c $(INC)print.h
	$(CC) $(CFLAGS) -c $< -o $@


$(OUT)main.o: $(SRC)main.c $(H)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	$(RM) *.exe -r out