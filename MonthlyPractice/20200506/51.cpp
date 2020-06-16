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
    vector<ll> h(n);
    REP(i,n)cin >> h[i];
    ll ans = 0;
    REP(middle,n){
        if(middle==0 || middle==n-1){
            if(middle==0){
                ll l = 0 ;
                while(h[l] > h[l+1] && l < n-1)l++;
                ans = max(ans,l - middle+1);
            } else{
                ll r = middle;
                while(h[r]>h[r-1] && r > 0)r--;
                ans = max(ans, middle-r+1);
            }
        } else if(h[middle-1]<h[middle] && h[middle]>h[middle+1]){
            ll r=middle;ll l=middle;
            while(h[r]>h[r-1] && r > 0 )r--;
            while(h[l]>h[l+1] && l < n-1)l++;
            ans = max(ans, l - r + 1);
        }
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/arc036/tasks/arc036_b