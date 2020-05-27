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
    string ss;cin >> ss;
    char s[ss.length()];
    for(int i=0;i<ss.length();i++){
        s[i]=ss[i];
    }
    ll ans=0;ll prea=0;bool skip=false;
    REP(i,ss.length()){
        if(skip){skip=false;continue;}
        if(s[i]=='A')prea++;
        else prea=0;
        if(i+2<=ss.length()-1 && s[i]=='A' && s[i+1]=='B' && s[i+2]=='C'){
            ans+=prea;
            s[i]='B';s[i+1]='C';s[i+2]='A';
            prea--;
            skip=true;
        }
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/agc034/tasks/agc034_b