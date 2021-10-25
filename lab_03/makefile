OUT = out/
SRC = src/
INC = inc/

CC := gcc
CFLAGS := -std=c99 -Werror -Wextra -Wall -Wpedantic -Wfloat-equal -Wfloat-conversion -Iinc
OBJS := $(OUT)menu.o  $(OUT)input_mtr.o $(OUT)input_str.o $(OUT)actions.o $(OUT)structs.o
H :=  $(INC)menu.h $(INC)input_mtr.h $(INC)input_str.h $(INC)actions.h  $(INC)structs.h
 
release: app.exe

debug : CFLAGS += -g3
debug : app.exe

app.exe: out $(OBJS) $(OUT)main.o
	$(CC) -o $@ $(OBJS) $(OUT)

out:
	mkdir out

$(OUT)menu.o: $(SRC)menu.c $(INC)menu.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)input_mtr.o: $(SRC)input_mtr.c $(INC)input_mtr.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)input_str.o: $(SRC)input_str.c $(INC)input_str.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)actions.o: $(SRC)actions.c $(INC)actions.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)structs.o: $(SRC)structs.c $(INC)structs.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)main.o: $(SRC)main.c $(H)
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY : clean func
func:
	sh make_func.sh
clean:
	$(RM) *.exe -r out
