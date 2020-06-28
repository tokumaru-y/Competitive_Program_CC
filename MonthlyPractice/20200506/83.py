if __name__ =='__main__':
    s = input()
    ans = 0
    seq = 0
    for c in s:
        if c=='A' or c=='T' or c=='G' or c=='C':
            seq+=1
        else:
            ans = max(ans,seq)
            seq=0
    ans = max(ans,seq)
    print(ans)