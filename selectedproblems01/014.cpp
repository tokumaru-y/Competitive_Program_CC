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
    int buildings,colors;scanf("%d %d",&buildings,&colors);
    vector<ll> heights(buildings,0);
    REP(i,buildings){
        ll tmp;scanf("%lld",&tmp);
        heights[i]=tmp;
    }
    ll ans=INF;
    for(int bit=0;bit<(1<<buildings);bit++){
        ll tmpans=0;
        vector<ll> tmplist(buildings);
        copy(heights.begin(), heights.end(),tmplist.begin());
        ll tmpmax = tmplist[0];
        for(int j=1;j<buildings;j++){
            if(bit&(1<<j)){
                if(tmpmax >= tmplist[j]){
                    tmpans += tmpmax - tmplist[j] + 1;
                    tmplist[j] = tmpmax+1;
                }
            }
            tmpmax = max(tmpmax,tmplist[j]);
        }
        int cnt = 1;
        ll minn = tmplist[0];
        for(int ind=1;ind<buildings;ind++){
            if(tmplist[ind] > minn){
                cnt++;
                minn = tmplist[ind];
            }
            if(cnt>=colors){
                ans = min(ans,tmpans);
                break;
            }
        }
    }
    printf("%lld\n",ans);
}