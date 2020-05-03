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

int N,K;
vector<ll> sx;vector<ll> sy;vector<ll> sz;
vector<ll> ex;vector<ll> ey;vector<ll> ez;
vector<ll> rex;vector<ll> rey;vector<ll> rez;


ll solve(vector<ll> &sortx,vector<ll> &sorty,vector<ll> &sortz){
    sort(ALL(sortx));sort(ALL(sorty));sort(ALL(sortz));
    for(int i=0;i<sortx.size();i++){
        if(i==0 || sortx[i] != sortx[i-1])rex.push_back(sortx[i]);
        if(i==0 || sorty[i] != sorty[i-1])rey.push_back(sorty[i]);
        if(i==0 || sortz[i] != sortz[i-1])rez.push_back(sortz[i]);
    }
    ll ans = 0 ;
    for(int i=0;i<sortx.size()-1;i++){
        for(int j=0;j<sorty.size()-1;j++){
            for(int k=0;k<sortz.size()-1;k++){
                int cnt = 0;
                for(int c=0;c<N;c++){
                    if(sx[c] <= sortx[i] && sortx[i+1] <= ex[c] &&
                       sy[c] <= sorty[j] && sorty[j+1] <= ey[c] &&
                       sz[c] <= sortz[k] && sortz[k+1] <= ez[c]) cnt++;
                }

                if(cnt>=K)ans += (sortx[i+1] - sortx[i]) * (sorty[j+1] - sorty[j]) * (sortz[k+1] - sortz[k]);
            }
        }
    }
    return ans ;
}

signed main () {
    cin >> N >> K;
    sx.resize(N);sy.resize(N);sz.resize(N);
    ex.resize(N);ey.resize(N);ez.resize(N);
    vector<ll> sortx;vector<ll> sorty;vector<ll> sortz;
    REP(i,N){
        cin >> sx[i] >> sy[i] >> sz[i] >> ex[i] >> ey[i] >> ez[i]; 
        sortx.push_back(sx[i]);sortx.push_back(ex[i]);
        sorty.push_back(sy[i]);sorty.push_back(ey[i]);
        sortz.push_back(sz[i]);sortz.push_back(ez[i]);
    }
    cout << solve(sortx,sorty,sortz) << endl;
}