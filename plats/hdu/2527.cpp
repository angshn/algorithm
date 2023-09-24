#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    priority_queue<int,vector<int>, greater<int> > q;
    sort(s.begin(), s.end());
    int num = 1;
    for(int i=1;i<=s.length();i++){
        if(s[i]!=s[i-1]) {
            q.push(num);num=1;
        }
        else num++;
    }
    int ans = 0;
    if(q.size()==1)
        ans = s.length();
    while(q.size()>1){
        int op1 = q.top();q.pop();
        int op2 = q.top();q.pop();
        q.push(op1+op2);
        ans+=op1+op2;
    }
    cout<<((ans<n)?"yes\n":"no\n");
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    // FASTIO
    int t;cin>>t;
    while(t--) solve();
    return 0;
}