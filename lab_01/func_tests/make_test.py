current = "10"
p = "TRUE"
p = input("Input in: \n")
g = input("Input out: \n")
while(p!="FALSE"):
##    name_in = "pos_" + "0" + current + "_in.txt"
##    name_out = "pos_" + "0" + current + "_out.txt"
    name_in = "pos_" + current + "_in.txt"
    name_out = "pos_" + current + "_out.txt"
    file_in= open(name_in, "w")
    file_out= open(name_out, "w")
    
    file_in.write(p + '\n')
    file_out.write(g + '\n')
    
    current=str(int(current) + 1)
    
    p = input("Input in: \n")
    g = input("Input out: \n")
    
    file_in.close()
    file_out.close()
