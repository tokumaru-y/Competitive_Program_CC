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
    string s;cin >> s;
    string candi; cin >> candi;
    int lens = s.length();int lenc = candi.length();lenc--;
    int startind=1000;bool flag = false;
    for(int i=lens-1;i>=0;i--){
        if(s[i]==candi[lenc] || s[i]=='?'){
            int cnt=1;
            while(cnt!=lenc+1){
                if(i-cnt<0 || lenc-cnt < 0)break;
                if(s[i-cnt]!=candi[lenc-cnt] && s[i-cnt]!='?')break;
                cnt++;
            }

            if(cnt==lenc+1){
                flag = true;
                startind = i -cnt+1;
                break;
            }
        }
    }
    if(!flag)cout << "UNRESTORABLE" << endl,exit(0);
    for(int i = 0;i<lens;i++){
        if(i==startind){
            cout << candi;
            i+=lenc;
            if(i>=lens)break;
            continue;
        }
        if(s[i]=='?'){
            cout << 'a';
        } else {
            cout << s[i];
        }
    }
    cout << endl;
}