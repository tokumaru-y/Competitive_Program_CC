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
    ll n;cin >> n;
    ll cnt = n;
    ll tmpaaa = n;
    ll k = 26;
    ll lens = 1;
    while(cnt>k){
        tmpaaa-=k;
        k*=26;
        lens++;
    }
    vector<ll> maxnum(lens);
    ll tmpsum = 26;
    REP(i,lens){
        maxnum[i]=tmpsum;
        tmpsum*=26;
    }
    string ans = "";
    for(int a = lens-1;a>=0;a--){
        ll tmpcnt = cnt/maxnum[a];
        ll div = cnt%maxnum[a];
        if(tmpcnt>0){
            cnt-= tmpcnt*maxnum[a];
            // char tmpcn = 'a';
            // tmpcnt--;
            // while(tmpcnt>0){
            //     tmpcn++;
            //     tmpcnt--;
            // }
            // if(div==0)tmpcn='z';
            // ans+=tmpcn;
            ans+='z';
        } else {
            ll roop;
            if(a==0){
                roop=cnt,cnt-=roop;
            }else {
                roop = cnt/maxnum[a-1];
                div= cnt%maxnum[a-1];
                ll tttt = roop*maxnum[a-1];
                cnt-=tttt;
            }
            char c = 'a';
            roop--;
            while(roop>0){
                c++;
                roop--;
            }
            if(div==0)c='z';
            ans+=c;
        }
    }
    // char an = 'a';
    // while(cnt>1){
    //     an++;cnt--;
    // }
    // ans+=an;
    cout << ans << endl;
    // ll tmpccc=1;
    // if(lens==1){
    //     for(char aa='a';aa<='z';aa++){
    //         if(tmpccc==n){
    //             cout << aa << endl;
    //             return 0;
    //         }
    //         tmpccc++;
    //     }
    // }

    // string ans = "";
    // int addz=0;
    // ll mod = cnt%26;
    // while((cnt/26)>=26){
    //     addz++;
    //     cnt/=26;
    //     mod=cnt%26;
    // }
    // if(addz>0){
    //     REP(i,lens-addz){
    //         ans +='a';
    //     }
    //     REP(i,addz)ans+='z';
    // }
    // char tmp ='a';
    // while(cnt>1){
    //     tmp++;
    //     cnt--;
    // }
    // ans+=tmp;
    // char tmp1='a';
    // while(mod>0){
    //     tmp1++;
    //     mod--;
    // }
    // ans+=tmp1;
    // cout << ans << endl;
}