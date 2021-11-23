// https://atcoder.jp/contests/abc029/tasks/abc029_c
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < int(n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
typedef long long ll;
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

void dfs(vector<string> &ans) {
    signed int s = ans.size();
    vector<string> tmp;
    for (char x = 'a'; x<='c';x++){
        for(string y: ans) {
            tmp.push_back(y+x);
        }
    }
    ans = tmp;
}

signed main () {
    int N;
    cin >> N;
    vector<string> ans = {"a", "b", "c"};
    REP(i,N-1){
        dfs(ans);
    }
    sort(ans.begin(), ans.end());
    for (string a:ans){
        cout << a << endl;
    }
    return 0;
}