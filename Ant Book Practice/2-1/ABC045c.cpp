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
    int len = s.size();
    ll ans=0;
    vector<int> list(len);
    REP(i,len){
        list[i] = s.at(i)-'0';
    }
    for(int bit=0;bit<(1<<(len-1));bit++){
        ll sumnum = 0;ll now = list[0];
        for(int i=0;i<(len-1);i++){
            if(bit&(1<<i)){
                sumnum+=now;
                now=list[i+1];
            } else {
                now=now*10+list[i+1];
            }
        }
        sumnum += now;ans += sumnum;
    }
    printf("%lld",ans);
}