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
    vector<vector<char>> inlist(2,vector<char>(n));
    REP(i,2)REP(j,n){
        cin >> inlist[i][j];
    }
    ll ans = 1;
    //true = tate , false = yoko
    bool pre = false;
    ll index = 0;
    while(index<n){
        if(inlist[0][index]==inlist[1][index]){
            if(index==0){
                ans*=3;
            } else if (pre){
                ans*=2;
            }
            pre=true;
            index++;
        } else {
            if(index==0){
                ans*=6;
            } else if(pre) {
                ans*=2;
            } else {
                ans*=3;
            }
            pre = false;
            index+=2;
        }
        ans%=MOD;
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/arc081/tasks/arc081_b