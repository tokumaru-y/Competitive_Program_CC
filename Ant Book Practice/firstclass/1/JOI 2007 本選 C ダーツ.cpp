#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

int N,M;
vector<ll> points;
signed main () {
    cin >> N >> M;
    points.resize(N);
    REP(i,N)cin >> points[i];
    vector<ll> sumlist;points.push_back(0);
    REP(i,N+1)REP(j,N+1){
        sumlist.push_back(points[i]+points[j]);
    }
    ll ans = 0;
    sort(ALL(sumlist));
    REP(i,sumlist.size()){
        ll left = M - sumlist[i];
        if(left<0)continue;
        auto itr = lower_bound(ALL(sumlist),left);
        if(left==*itr){
            ans = M;break;
        } else {
            itr--;
            if(left>*itr)ans = max(ans,sumlist[i]+*itr);
        }
    }
    cout << ans << endl;
}