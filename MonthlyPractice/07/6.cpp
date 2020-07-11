#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
typedef long long ll;
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int h,w,k;cin >> h >> w >> k;
    int ans=0;
    vector<string> inlist(h);
    REP(i,h)cin >> inlist[i];
    FOR(i,0,(1<<h))FOR(j,0,(1<<w)){
        vector<string> tmp = inlist;
        REP(s,h){
            if(i & (1<<s)){
                REP(t,w){
                    tmp[s][t]='X';
                }
            }
        }
        REP(s,w){
            if(j & (1<<s)){
                REP(t,h){
                    tmp[t][s]='X';
                }
            }
        }
        int tmpcnt=0;
        REP(a,h)REP(b,w){
            if(tmp[a][b]=='#')tmpcnt++;
        }
        if(tmpcnt==k)ans++;
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/abc173/tasks/abc173_c