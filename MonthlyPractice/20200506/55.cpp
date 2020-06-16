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
    int n;cin >> n;
    map<ll,int> cnt;
    vector<ll> inlist(n);
    REP(i,n){
        ll tmp;cin >> tmp;
        inlist[i]=tmp;
        cnt[tmp]++;
    }
    ll mintime = 0;ll passedtime = 0;
    ll pattern = 1;
    ll cn = 0;ll siz = cnt.size();
    sort(ALL(inlist));
    for(ll a : inlist){
        cn++;
        passedtime+=a;
        mintime+=passedtime;
    }
    for(auto b : cnt){
        ll s=b.first;ll t=b.second;
        while(t>1){
            pattern*=t;
            pattern%=MOD;
            t--;
        }
    }
    cout << mintime << endl;
    cout << pattern << endl;
}//https://atcoder.jp/contests/arc035/tasks/arc035_b