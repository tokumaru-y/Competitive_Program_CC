#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
typedef long long ll;
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
    vector<vector<int>> memberlist(n,vector<int>());
    REP(i,m){
        int a,b;cin >> a >> b;
        a--;b--;
        memberlist[a].push_back(b);
        memberlist[b].push_back(a);
    }
    int ans = 0;
    for(int i=1;i<(1<<n);i++){
        int cnt=0;
        vector<int> candidate;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                cnt++;
                candidate.push_back(j);
            }
        }
        for(int s=0;s<candidate.size();s++){
            vector<int> candlist = memberlist[candidate[s]];
            for(int k=0;k<candidate.size();k++){
                if(s==k)continue;
                if(find(ALL(candlist),candidate[k])==candlist.end()){
                    cnt=-1;break;
                }
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}