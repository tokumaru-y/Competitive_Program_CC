if __name__=='__main__':
    a,b,c,x,y = map(int,input().split())
    ans = float('inf')

    ans = min(ans,x*a+b*y)
    ans = min(ans,c*2*y+(x-y)*a) if x>y else min(ans,c*2*x+(y-x)*b)
    ans = min(ans,c*2*max(x,y))
    print(ans) 