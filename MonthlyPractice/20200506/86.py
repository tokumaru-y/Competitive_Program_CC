import itertools
import math

def combinations_count(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

def solve():
    n=int(input())
    s=input()
    setcnt = n - len(set(s))
    ans = combinations_count(n,3) - setcnt
    print(ans)



if __name__=='__main__':
    solve()
#https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d