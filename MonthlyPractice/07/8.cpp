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
    // ll n,m;cin >> n >> m;
    // vector<ll> pluss;
    // vector<ll> minuss;
    // REP(i,n){
    //     ll tmp;cin >> tmp;
    //     if(tmp>0)pluss.push_back(tmp);
    //     else minuss.push_back(tmp);
    // }
    // sort(ALL(pluss),greater<ll>());
    // sort(ALL(minuss),greater<ll>());
    // ll p_size = pluss.size();
    // ll m_size = minuss.size();
    // ll ans = 1;
    // ll indexp = 0;
    // ll indexm = 0;
    // if(m%2==0){
    //     while(m>0){
    //         bool use_plus = (indexp<p_size-1)?true:false;
    //         bool use_minus = (indexm<m_size-1)?true:false;
    //         if(use_plus && use_minus){
    //             if(pluss[indexp] * pluss[indexp+1] > minuss[indexm] * minuss[indexm+1]){
    //                 ans *= pluss[indexp] % MOD * pluss[indexp+1] % MOD;
    //                 ans %= MOD;
    //                 indexp += 2;
    //             } else {
    //                 ans *=  minuss[indexm]% MOD * minuss[indexm+1] % MOD;
    //                 ans %= MOD;
    //                 indexm += 2;
    //             }
    //         } else if (use_plus){
    //             ans *= pluss[indexp] % MOD * pluss[indexp+1] % MOD;
    //             ans %= MOD;
    //             indexp += 2;
    //         } else if (use_minus) {
    //             ans *=  minuss[indexm]% MOD * minuss[indexm+1] % MOD;
    //             ans %= MOD;
    //             indexm += 2;
    //         } else {
    //             ans *= pluss[indexp] % MOD * minuss[indexm] % MOD;
    //             indexp+=1;indexm+=1;
    //         }
    //         m-=2;
    //     }
    // } else {
    //     while(m>0){
    //         if(m==1){
    //             if(indexp<=p_size-1){
    //                 ans *= pluss[indexp]%MOD;
    //                 indexp+=1;
    //                 m--;
    //             } else {
    //                 ans *= minuss[indexm]%MOD;
    //                 indexm+=1;
    //                 m--;
    //             }
    //         } else {
    //             bool use_plus = (indexp<p_size-1)?true:false;
    //             bool use_minus = (indexm<m_size-1)?true:false;
    //             if(use_plus && use_minus){
    //                 if(pluss[indexp] * pluss[indexp+1] > minuss[indexm] * minuss[indexm+1]){
    //                     ans *= pluss[indexp] % MOD * pluss[indexp+1] % MOD;
    //                     ans %= MOD;
    //                     indexp += 2;
    //                 } else {
    //                     ans *=  minuss[indexm]% MOD * minuss[indexm+1] % MOD;
    //                     ans %= MOD;
    //                     indexm += 2;
    //                 }
    //             } else if (use_plus){
    //                 ans *= pluss[indexp] % MOD * pluss[indexp+1] % MOD;
    //                 ans %= MOD;
    //                 indexp += 2;
    //             } else if (use_minus) {
    //                 ans *=  minuss[indexm]% MOD * minuss[indexm+1] % MOD;
    //                 ans %= MOD;
    //                 indexm += 2;
    //             } else {
    //                 ans *= pluss[indexp] % MOD * minuss[indexm] % MOD;
    //                 indexp+=1;indexm+=1;
    //             }
    //             m-=2;
    //         }
    //     }
    // }
    // if(ans<0){
    //     ans = MOD + ans;
    // }
    // cout << ans << endl;
    ll n,m;cin >> n >> m;
    vector<ll> positive;
    vector<ll> negative;
    REP(i,n){
        ll tmp;cin >> tmp;
        if(tmp<0)negative.push_back(tmp);
        else positive.push_back(tmp);
    }
    ll p_size=positive.size();
    ll n_size=negative.size();
    sort(ALL(positive),greater<ll>());
    sort(ALL(negative));
    ll ans = 1;
    bool is_ans_positive = false;
    if(p_size>0){
        if((n==m && n_size%2==0) || n!=m)is_ans_positive=true;
    }
    if(p_size==0 && m % 2 == 0)is_ans_positive=true;
    if(!is_ans_positive){
        vector<ll> abslist;
        REP(i,p_size){
            abslist.push_back(positive[i]);
        }
        REP(i,n_size){
            abslist.push_back(abs(negative[i]));
        }
        sort(ALL(abslist));
        REP(i,m){
            ans *= abslist[i];
            ans%=MOD;
        }
        ans*=-1;
    } else {
        ll posindex = 0;
        ll negindex = 0;
        if(p_size>0 && m%2==1){
            m--;
            ans*=positive[0];
            ans%=MOD;
            posindex=1;
        }
        while(m>0){
            if(m==1){
                ans *= positive[posindex];
                ans %= MOD;
                m--;
                posindex++;
            } else {
                bool use_pos = (posindex<p_size-1) ? true : false;
                bool use_neg = (negindex<n_size-1) ? true : false;
                if(use_pos && use_neg){
                    ll tmp1 = (positive[posindex] * positive[posindex+1]);
                    ll tmp2 = (negative[negindex] * negative[negindex+1]);
                    if(tmp1>tmp2){
                        tmp1%=MOD;
                        ans*=tmp1;
                        ans%=MOD;
                        posindex+=2;
                    } else {
                        tmp2%=MOD;
                        ans*=tmp2;
                        ans%=MOD;
                        negindex+=2;
                    }
                    m-=2;
                } else if(use_pos) {
                    ll tmp1 = (positive[posindex] * positive[posindex+1]);
                    tmp1%=MOD;
                    ans*=tmp1;
                    ans%=MOD;
                    posindex+=2;
                    m-=2;
                } else if(use_neg){
                    ll tmp2 = (negative[negindex] * negative[negindex+1]);
                    tmp2%=MOD;
                    ans*=tmp2;
                    ans%=MOD;
                    negindex+=2;
                    m-=2;
                }
                // } else {
                //     ll tmp = (positive[posindex] * negative[negindex]) % MOD; 
                //     ans *= tmp;
                //     ans %= MOD;
                //     posindex++;negindex++;
                // }
            }
        }
    }
    if(ans<0)ans=MOD+ans;
    cout << ans << endl;
}//https://atcoder.jp/contests/abc173/tasks/abc173_e