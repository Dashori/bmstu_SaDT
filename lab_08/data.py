import sys
import random

size = sys.argv[1]
tablename = 'data_' + str(size) + '.txt'

f = open(tablename, "w")

# f.write(str(size) + '\n')

for i in range(int(size)):
    for j in range(int(size)):
        f.write(str(random.randint(0, 20)) + " ")
    f.write("\n")

f.close()