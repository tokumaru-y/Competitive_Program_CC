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
    ll mod = 998244353;
    map<int,int> cnt;
    REP(i,n){
        int a;cin >> a;
        if((a==0 && i!=0) || (i==0 && a !=0)){
            cout << 0 << endl;return 0;
        }
        cnt[a]++;
    }
    if(cnt.count(1)==0) {
        cout << 0 << endl;return 0;
    }
    ll ans=1;
    FOR(i,1,n){
        if(cnt.count(i)==0)continue;
        if(cnt.count(i-1)==0){
            cout << 0 << endl;return 0;
        }
        ll nowcnt = cnt[i];
        REP(j,nowcnt){
            ans*=cnt[i-1];
            ans %=mod;
        }
    }
    cout << ans << endl;
}
//https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_b