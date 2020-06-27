import sys

def main():
    while True:
        inlist = list(map(int, input().split()))
        if inlist[0]==0 and inlist[1]==0:
            break
        ans = 0
        numlist = [i for i in range(1,inlist[0]+1)]
        for i in numlist:
            tmpsum = 0
            for j in range(i+1,inlist[0]+1):
                for k in range(j+1,inlist[0]+1):
                    if(i==j or j==k or k==i):
                        continue
                    tmpsum=i+j+k
                    if tmpsum==inlist[1]:
                        ans+=1
        print(ans)

if __name__ == '__main__':
    main()