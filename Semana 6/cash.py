from cs50 import get_float
money = get_float("Insert the amount of money: ")
while money<=0:
    money = get_float("Insert the amount of money: ")
money *= 100
coins = 0
def reduce_money(cash, amount):
    global coins
    global money
    while cash>=amount:
        cash = cash-amount
        money = cash
        coins = coins+1
reduce_money(money, 25)
reduce_money (money, 10)
reduce_money (money,5)
reduce_money (money,1)
print(coins)




