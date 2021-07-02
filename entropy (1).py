import math

E = 0
while True:
    x = float(input())
    
    if x == 0:
        break

    ans = - (x * math.log2(x) + (1 - x)*math.log2(1-x))
    
    E = E + ans

    print(ans)
    print("E: {}".format(E))