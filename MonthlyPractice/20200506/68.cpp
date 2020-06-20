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
    int n,m;cin >> n >> m;
    string s,t;cin >> s >> t;
    map<char,int>scnt;map<char,int>tcnt;
    for(char a='A';a<='Z';a++){
        REP(i,n){
            if(s[i]==a)scnt[a]++;
        }
        REP(j,m){
            if(t[j]==a)tcnt[a]++;
        }
    }
    int ans=0;
    for(auto p : scnt){
        char target=p.first;int cn = p.second;
        if(tcnt.count(target)==0){
            cout << -1 << endl;return 0;
        }
        int ttt = tcnt[target];
        if(ttt>=cn){
            ans = max(ans,1);
        } else if(cn%ttt==0){
            ans = max(ans,cn/ttt);
        } else {
            ans = max(ans,(cn/ttt)+1);
        }
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/arc008/tasks/arc008_2