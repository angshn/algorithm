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
    priority_queue<int, vector<int>, greater<int> > q1;
    priority_queue<int, vector<int>, less<int> > q2;
    int mid ;cin>>mid;
    cout<<mid<<"\n";
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        if(mid ==-1){
            mid = x;
        }
        if(x<=mid) q2.push(x);
        else q1.push(x);
        if(i&1){
            while(q1.size()!=q2.size()){
                if(q1.size()>q2.size()){
                    q2.push(mid);
                    mid = q1.top();
                    q1.pop();
                }
                else {
                    q1.push(mid);
                    mid = q2.top();
                    q2.pop();
                }
            }
            cout<<mid<<"\n";
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}