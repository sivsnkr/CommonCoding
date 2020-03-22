import math
n = input()
n = int(n)

notShake = set()
for i in range(0, 3):
    st = input()
    st = st.split(" ")
    for j in st:
        notShake.add(int(j))
        # print(j)

n -= len(notShake)
print(len(notShake))

res = int((math.factorial(n))/(2*math.factorial(n-2)))
print(res)
