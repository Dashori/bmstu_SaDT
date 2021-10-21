OUT = out/
SRC = src/
INC = inc/

CC := gcc
CFLAGS := -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Iinc
OBJS := $(OUT)menu.o  $(OUT)input.o
H :=  $(INC)menu.h $(INC)input.h
 
release: app.exe

debug : CFLAGS += -g3
debug : app.exe

app.exe: out $(OBJS) $(OUT)main.o
	$(CC) -o $@ $(OBJS) $(OUT)main.o

out:
	mkdir out

$(OUT)menu.o: $(SRC)menu.c $(INC)menu.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)input.o: $(SRC)input.c $(INC)input.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)main.o: $(SRC)main.c $(H)
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY : clean func
func:
	sh make_func.sh
clean:
	$(RM) *.o *.exe -r out