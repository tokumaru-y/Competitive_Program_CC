#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    int a;scanf("%d",&a);
    string s,t; cin >> s >> t;
    for(int i=0;i<a;i++){
        printf("%c%c",s[i],t[i]);
    }
}