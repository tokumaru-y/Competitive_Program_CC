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
    ll n,k;cin >> n >> k;
    vector<ll> pl;vector<ll> min;
    REP(i,n){
        ll tmp;cin >> tmp;
        if(tmp<0)min.push_back(tmp);
        else pl.push_back(tmp);
    }
    ll pllen=pl.size();ll minlen=min.size();
    sort(ALL(pl),greater<ll>());
    sort(ALL(min));
    ll ans=1;
    bool is_ans_plus=false;
    if(pllen==0){
        if(k%2==0)is_ans_plus=true;
    } else {
        if(n>k || (n==k && minlen%2==0))is_ans_plus=true;
    }
    if(is_ans_plus){
        ll pindex=0;
        ll mindex=0;
        if(pllen>0 && k%2==1){
            pindex=1;
            ans*=pl[0];
            ans%=MOD;
            k--;
        }
        while(k>0){
            bool canp=(pindex<pllen-1)?true:false;
            bool canm=(mindex<minlen-1)?true:false;
            if(k==1){
                ans*=pl[pindex];
                ans%=MOD;
                pindex++;
                k--;
            } else if(canp && canm){
                ll t1=pl[pindex]*pl[pindex+1];
                ll t2=min[mindex]*min[mindex+1];
                if(t1>t2){
                    t1%=MOD;
                    ans*=t1;
                    ans%=MOD;
                    pindex+=2;
                    k-=2;
                } else {
                    t2%=MOD;
                    ans*=t2;
                    ans%=MOD;
                    mindex+=2;
                    k-=2;
                }
            } else if(canp){
                ll t1=pl[pindex]*pl[pindex+1];
                t1%=MOD;
                ans*=t1;
                ans%=MOD;
                pindex+=2;
                k-=2;
            } else {
                ll t2=min[mindex]*min[mindex+1];
                t2%=MOD;
                ans*=t2;
                ans%=MOD;
                mindex+=2;
                k-=2;
            }
        }
    } else {
        vector<ll> abslist;
        REP(i,pllen)abslist.push_back(pl[i]);
        REP(i,minlen)abslist.push_back(abs(min[i]));
        sort(ALL(abslist));
        REP(i,k)ans*=abslist[i],ans%=MOD;
        ans*=-1;
        ans+=MOD;
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/abc173/tasks/abc173_e