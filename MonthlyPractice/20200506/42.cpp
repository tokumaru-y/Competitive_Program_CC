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
    string str;cin >> str;ll k;cin >> k;
    ll strlen = str.length();
    char ans[strlen];
    REP(i,strlen){
        int alphsnum = 'z' - str[i] + 1;
        if(str[i]!='a' && alphsnum<=k && k>0){
            ans[i]='a';
            k-=alphsnum;
        } else {
            ans[i]=str[i];
        }
    }
    if(k>0){
        k%=26;
        ans[strlen-1]+=k;
    }
    for(char a : ans){
        cout << a;
    }
    cout << endl;
}//https://atcoder.jp/contests/code-festival-2016-quala/tasks/codefestival_2016_qualA_c