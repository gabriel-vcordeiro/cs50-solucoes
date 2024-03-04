from cs50 import get_int


height = get_int("Height: ")
wall = "#"
space = " "
while height <1 or height>8:
    height = int(input("Insert the height: "))
for i in range (1, height + 1, 1):
    spaces = height - i

    print((space * spaces) + (wall * i) + "  " + (wall * i))

