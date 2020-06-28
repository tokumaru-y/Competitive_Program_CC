
def solve():
    ans = 0
    n=int(input())
    for i in range(1,n+1,2):
        div_list = []
        for j in range(1,int(i**0.5)+1):
            if i%j!=0:
                continue
            if i//j==j:
                div_list.append(j)
            else:
                div_list.append(i//j)
                div_list.append(j)
        if len(div_list)==8:
            ans+=1
    print(ans)

if __name__ == '__main__':
    solve()