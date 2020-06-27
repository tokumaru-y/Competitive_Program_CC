

def solve():
    n,m = map(int,input().split())
    inlist = [list(map(int,input().split())) for _ in range(n)]
    ans = 0
    for i in range(m):
        for j in range(i+1,m):
            tmpsum = 0
            for k in range(n):
                tmpsum+=max(inlist[k][i],inlist[k][j])
            ans = max(ans,tmpsum)
    print(ans)


if __name__ == '__main__':
    solve()