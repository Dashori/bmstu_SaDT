import sys

name_pos = str(sys.argv[1])
name_out = "out.txt"

f = open(name_pos)
g = open(name_out)

flag = -1
count = 0
for line_g in g:
    arr = line_g.split()
    count += 1
    if count == 21:
        line = line_g
        flag = 0
##        print(line)
##        print("AAAA")
if flag == -1:
    print("BBB", count)
    raise SystemExit(1)

else:
    for line_f in f:
        if line_f.split() == line.split():
            raise SystemExit(0)



raise SystemExit(1)
f.close()
g.close()
    
