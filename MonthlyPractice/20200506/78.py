ans = 0
def solve(n):
    global ans
    for i in range(1,n+1,2):
        div_list=[]
        for j in range(1,int((i+1)**0.5)+1):
            if i % j == 0:
                if (i//j)!=j:
                    div_list.append(i//j)
                    div_list.append(j)
                else:
                    div_list.append(j)
        if len(div_list) == 8:
            ans+=1

def main():
    n=int(input())
    solve(n)
    print(ans)

if __name__=='__main__':
    main()