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
    int k,t;cin >> k >> t;
    priority_queue<ll> que;
    REP(i,t){
        ll tmp;cin >> tmp;que.push(tmp);
    }
    ll pre=que.top();que.pop();
    pre--;
    while(!que.empty()){
        ll pn = que.top();que.pop();
        pn--;
        if(pre>0)que.push(pre);
        pre=pn;
    }
    cout << pre << endl;
}//https://atcoder.jp/contests/code-festival-2016-qualc/tasks/codefestival_2016_qualC_b