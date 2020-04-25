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

signed main () {
    SCANF(n);vector<ll> cnt(n,0);
    SCANF(color);int first = color;
    cnt[0]=1;
    int index=0;
    REP(i,n-1){
        SCANF(tmpc);
        if(color==tmpc){
            cnt[index]++;
        } else if(i%2==0){
            if(index==0){
                first=tmpc;
                cnt[index]++;
            } else {
                cnt[index-1]+=cnt[index]+1;
                cnt[index]=0;
                index--;
            }
        } else {
            index++;
            cnt[index]=1;
        }
        color=tmpc;
    }
    ll ans=0;
    if(first){
        for(int i=1;i<n;i+=2){
            ans+=cnt[i];
        }
    } else {
        for(int i=0;i<n;i+=2){
            ans+=cnt[i];
        }
    }
    //REP(i,n)printf("%lld ",cnt[i]);
    printf("%lld\n",ans);
}