
def main():
    s = input()
    ans = 0
    seq = 0
    for c in s:
        if c == 'A' or c == 'C' or c == 'T' or c == 'G':
            seq+=1
        else:
            ans = max(ans,seq)
            seq=0
    else:
        ans = max(ans,seq)
    print(ans)

if __name__ == '__main__':
    main()