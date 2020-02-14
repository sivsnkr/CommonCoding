import math
n = input()

n = n.split(" ")

k = int(n[1])
n = int(n[0])

modulo = 10**9+7


def fact(value):
    prod = 1
    while(value > 0):
        prod *= value
        prod %= modulo
    return prod % modulo


def make(value, k2):
    setList = []
    sum1 = 0
    for i in range(0, k2+1):
        for j in range(0, k2+1):
            for k1 in range(0, k2+1):
                for l in range(0, k2+1):
                    if(i+j+k1+l == value):
                        p = (math.factorial(value)/(math.factorial(i)*math.factorial(j)
                                                    * math.factorial(k1)*math.factorial(l)))
                        sum1 += p
    return sum1


if(k < 3):
    print(0)
else:
    sum2 = make(10, k)
    sum2 %= modulo

    prod = 1
    for j in range(0, int(n/2)):
        prod *= sum2
        prod %= modulo
    if(n % 2 != 0):
        sum1 = make(5, k)
        sum1 %= modulo
        prod *= sum1
        prod %= modulo
        prod *= fact(int(n/2))

    print(int(prod % modulo))
