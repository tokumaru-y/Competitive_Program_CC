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
    vector<P> alist;
    REP(i,n){
        ll x,y;cin >> x >> y;
        alist.push_back(P(x,y));
    }
    vector<P> blist;
    REP(j,n){
        ll x,y;cin >> x >> y;
        blist.push_back(P(x,-y));
    }
    sort(ALL(alist),greater<P>());
    sort(ALL(blist));
    ll ans =0;
    vector<bool> used(n,false);
    REP(i,n){
        P tmpa=alist[i];
        ll ax=tmpa.first;ll ay=tmpa.second;
        REP(j,n){
            if(used[j])continue;
            P tmpb=blist[j];
            ll bx=tmpb.first;ll by=tmpb.second;by*=-1;
            if(ax<bx && ay<by){
                cout << ax << " " << ay << " " << bx << " " << by << endl;
                ans++,used[j]=true;
                break;
            }
        }
    }
    cout << ans << endl;
}