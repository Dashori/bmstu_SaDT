OUT = out/
SRC = src/
INC = inc/

CC := gcc
CFLAGS := -std=c99 -Werror -Wextra -Wall -Wpedantic -Wfloat-equal -Wfloat-conversion -Iinc
OBJS := $(OUT)print.o $(OUT)structs.o $(OUT)add_del_arr.o $(OUT)add_del_list.o #$(OUT)menu.o  #$(OUT)input_mtr.o $(OUT)input_str.o $(OUT)actions.o 
H :=  $(INC)print.h  $(INC)structs.h $(INC)add_del_arr.h $(INC)add_del_list.h #$(INC)menu.h $(INC)input_mtr.h $(INC)input_str.h $(INC)actions.h  
 
release: app.exe

app.exe: out $(OBJS) $(OUT)main.o
	$(CC) -o $@ $(OBJS) $(OUT)main.o

out:
	mkdir out

# $(OUT)menu.o: $(SRC)menu.c $(INC)menu.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OUT)input_mtr.o: $(SRC)input_mtr.c $(INC)input_mtr.h
# 	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)add_del_arr.o: $(SRC)add_del_arr.c $(INC)add_del_arr.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)add_del_list.o: $(SRC)add_del_list.c $(INC)add_del_list.h
	$(CC) $(CFLAGS) -c $< -o $@
# $(OUT)actions.o: $(SRC)actions.c $(INC)actions.h
# 	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)structs.o: $(SRC)structs.c $(INC)structs.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT)print.o: $(SRC)print.c $(INC)print.h
	$(CC) $(CFLAGS) -c $< -o $@


$(OUT)main.o: $(SRC)main.c $(H)
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY : clean
clean:
	$(RM) *.exe -r out