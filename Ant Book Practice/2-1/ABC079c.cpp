#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    string s;cin >> s;
    int len=s.size();
    vector<int> list(len);
    REP(i,len){
        list[i]=s.at(i) - '0';
    }
    for(int bit=0;bit<(1<<(len-1));bit++){
        int tmp = list[0];
        for(int i=0;i<(len-1);i++){
            if(bit&(1<<i)){
                tmp += list[i+1];
            } else {
                tmp -= list[i+1];
            }
        }
        if(tmp==7){
            vector<char> ans(len+len-1);
            ans[0] = s[0];
            for(int j = 0;j<len-1;j++){
                if(bit&(1<<j)){
                    ans[j*2+1] = '+';
                } else {
                    ans[j*2+1] = '-';
                }
                ans[j*2] = s[j];
            }
            for(int k=0;k<ans.size();k++){
                printf("%c",ans[k]);
            }
            printf("=7");
            return 0;
        }
    }
}