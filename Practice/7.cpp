// https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_c
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int H,W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    priority_queue<int>que;
    unordered_map<char, int>mp;
    REP(i,H)REP(j,W){
        cin >> A[i][j];
        mp[A[i][j]]++;
    }
    if (H==1 && W==1){
        cout << "Yes" << endl;
        return 0;
    }
    for (auto itr=mp.begin();itr!=mp.end();itr++){
        que.push(itr->second);
    }
    for(int w=0;w<(W/2);w++){
        if (que.size()==0){
            cout << "No" << endl;
            return 0;
        }
        while (que.top() < 4){
            que.pop();
            if (que.size()==0){
                cout << "No" << endl;
                return 0;
            }
        }
        int top = que.top();
        que.pop();
        que.push(top-4);
    }
    if(W%2==1){}

}