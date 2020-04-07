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
    int a,b,c,x,y;scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
    int ans = 0;
    if(a+b>2*c){
        if(x<y){
            int tmp = 0;
            int left = y - x;
            ans += 2*c*x;
            ans += min(left*b,2*c*left);
        } else {
            int tmp = 0;
            int left = x - y;
            ans += 2*c*y;
            ans += min(left*a,2*c*left);
        }
    } else {
        ans = a*x + b*y;
    }
    printf("%d",ans);
}