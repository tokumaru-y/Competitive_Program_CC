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
    int n;scanf("%d",&n);
    vector<vector<bool>> list(3001,vector<bool>(3001,false));
    REP(i,n){
        int x,y;scanf("%d %d",&x,&y);
        list[x-1][y-1] = true;
    }
    int ans=0;
    REP(i,3001){
        REP(j,3001){
            if(i==j)continue;
            int distance = 
        }
    }
}