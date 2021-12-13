import sys
import faker
fake = faker.Faker()

size = sys.argv[1]
tablename = 'data_' + str(size) + '.txt'

f = open(tablename, "w")

for i in range(int(size)):
    f.write(fake.unique.first_name() + '\n')

f.close()
