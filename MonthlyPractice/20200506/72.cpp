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
    string instr;cin >> instr;
    string strlist = "ABXY";
    ll ans = INF;
    REP(i,4)REP(j,4)REP(a,4)REP(b,4){
        string target1="";string target2="";
        target1+=strlist[i];
        target1+=strlist[j];
        target2+=strlist[a];
        target2+=strlist[b];
        if(target1==target2)continue;
        ll index=0;ll tmpcnt=0;
        while(index<=n-1){
            if(index+1<=n-1 && instr[index]==target1[0] && instr[index+1]==target1[1]){
                index++;
            } else if(index+1<=n-1 && instr[index]==target2[0] && instr[index+1]==target2[1]){
                index++;
            }
            tmpcnt++;
            index++;
        }
        ans=min(ans,tmpcnt);
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/arc002/tasks/arc002_3