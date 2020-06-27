import bisect

def main():
    n,m=map(int,input().split())
    points = [int(input()) for _ in range(n)]
    points.insert(0,0)
    points_table = []
    for i in range(n+1):
        points_table.append(points[i])
        for j in range(i,n+1):
            points_table.append(points[i]+points[j])
    ans = 0
    points_table.sort()
    for i in range(len(points_table)):
        target = points_table[i]+points_table[(bisect.bisect_left(points_table,m-points_table[i]))-1]
        if target<= m:
            ans = max(ans,target)
    print(ans)

if __name__=="__main__":
    main()