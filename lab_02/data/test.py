from random import *


country = ("Russia", "Belarus", "Ukraine", "China", "Bulgary", "Germany", "Japan", "Britain", "USA", "Australia", "Georgia")
city = ("Chelyabinsk", "Moscow", "Belgorod", "Humburg", "Minsk", "Honkong", "London", "Seul", "Colorado", "Zavolzhye", "Sochi", "Odessa")
street = ("Pushkina", "Lenina", "Pervaya", "Colorars","Revolution", "Baumana", "Minskay", "Prospect", "Heroes", "Lity", "Kirta")
sign = ("0", "1")

file = open("flats2.txt", "w")
for i in range(200):
    file.write(country[randint(0,10)])
    file.write(' ')
    file.write(city[randint(0,11)])
    file.write(' ')
    file.write(street[randint(0,10)])
    file.write(' ')
    file.write(str(randint(1,100))) ##house
    file.write(' ')
    file.write(str(randint(1,100))) #flat
    file.write(' ')
    file.write(str(randint(30,300))) #square
    file.write(' ')
    file.write(str(randint(1,10))) #room
    file.write(' ')
    file.write(str(randint(1000,100000))) #cost
    file.write(' ')
    new = sign[randint(0,1)]
##    file.write(' ')
    file.write(str(new)) #new
    file.write(' ')
    if new == '0':
        file.write(str(sign[randint(0,1)]))
        file.write(' ')
    else:
        file.write(str(randint(1900, 2021))) #year
        file.write(' ')
        file.write(str(randint(1, 100))) #all
        file.write(' ')
        file.write(str(randint(1, 10))) #last
        file.write(' ')
        file.write(str(sign[randint(0,1)]))
    file.write ("\n")
                   
        
    
file.close()
