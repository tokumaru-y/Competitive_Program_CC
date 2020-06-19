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
vector<string> split_naive(const string &s, char delim) {
    vector<string> elems;
    string item;
    for (char ch: s) {
        if (ch == delim) {
            if (!item.empty())
                elems.push_back(item);
            item.clear();
        }
        else {
            item += ch;
        }
    }
    if (!item.empty())
        elems.push_back(item);
    return elems;
}
signed main () {
    int n;cin >> n;
    vector<bool> holiday(367,false);
    for(int i=1;i<=366;i++){
        if(i%7==1||i%7==0)holiday[i]=true;
    }
    //int predays[12]={0,31,60,91,121,152,182,213,243,273,304,334};
    int predays[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    REP(i,n){
        string tmp;cin >> tmp;
        int days=0;
        vector<char>mon;vector<char>day;
        bool flag=false;
        for(char aa : tmp){
            if(aa=='/'){
                int dd=0;
                if(mon.size()==2){
                    dd+=(mon[0]-'0')*10 + (mon[1] - '0');
                } else {
                    dd+=(mon[0])-'0';
                }
                REP(i,dd-1){
                    days+=predays[i];
                }
                flag=true;
            } else if(flag){
                day.push_back(aa);
            } else {
                mon.push_back(aa);
            }
        }
        if(day.size()==2){
            days+=(day[0]-'0')*10+(day[1]-'0');
        } else {
            days+=day[0]-'0';
        }
        while(days<=366){
            if(holiday[days])days++;
            else{holiday[days]=true;break;}
        }
    }
    int ans = 0;int cnt=0;
    for(int i=1;i<=366;i++){
        if(holiday[i])cnt++;
        else ans=max(ans,cnt),cnt=0;
    }
    ans=max(ans,cnt);
    cout << ans << endl;
}//https://atcoder.jp/contests/arc010/tasks/arc010_2