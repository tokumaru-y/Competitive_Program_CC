#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    ll h,n;scanf("%lld %lld",&h,&n);
    ll sumh = 0;
    REP(i,n){
        ll a;
        scanf("%lld", &a);
        sumh += a;
    }
    if(sumh >=h){
        printf("Yes");
    } else {
        printf("No");
    }
}