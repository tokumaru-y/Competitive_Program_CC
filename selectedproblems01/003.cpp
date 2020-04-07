//https://atcoder.jp/contests/abc122/tasks/abc122_b
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;
//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    //sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
signed main () {
    string n;cin >> n;
    int ans =0;int tmp=0;
    for(int i=0;i<n.length();i++){
        if(n[i]=='A'||n[i]=='C'||n[i]=='G'||n[i]=='T'){
            tmp++;
        } else {
            ans = max(ans,tmp);
            tmp = 0;
        }
    }
    ans = max(ans,tmp);
    printf("%d",ans);
}