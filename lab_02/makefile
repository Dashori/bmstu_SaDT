OUT = out/
SRC = src/
INC = inc/

CC := gcc
CFLAGS := -std=c99 -Werror -Wall -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Iinc
OBJS := $(OUT)add_del_flat.o $(OUT)find_flats.o $(OUT)menu.o $(OUT)print.o $(OUT)read_file.o $(OUT)sort_flats.o $(OUT)compare.o
C := $(INC)add_del_flat.h $(INC)find_flats.h $(INC)menu.h $(INC)print.h $(INC)read_file.h $(INC)sort_flats.h $(INC)struct_flats.h $(INC)compare.h
 
release: app.exe

debug : CFLAGS += -g3
debug : app.exe

app.exe: out $(OBJS) $(OUT)main.o
	$(CC) -o $@ $(OBJS) $(OUT)main.o

out:
	mkdir out

$(OUT)add_del_flat.o : $(SRC)add_del_flat.c $(INC)add_del_flat.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)find_flats.o: $(SRC)find_flats.c $(INC)find_flats.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)menu.o: $(SRC)menu.c $(INC)menu.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)print.o: $(SRC)print.c $(INC)print.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)read_file.o: $(SRC)read_file.c $(INC)read_file.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)sort_flats.o: $(SRC)sort_flats.c $(INC)sort_flats.h	
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)compare.o: $(SRC)compare.c $(INC)compare.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)main.o : $(SRC)main.c  $(C)
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY : clean func
func:
	sh make_func.sh
clean:
	$(RM) *.o *.exe -r out
