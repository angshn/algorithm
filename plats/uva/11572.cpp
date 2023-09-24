#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    //最长的没有重复数字的长度
    int l=0,r=0;
    int len = 0;
    map<int ,int> hashm;
    while(r<n){
        while(!hashm.empty()&&hashm[a[r]]){
            hashm[a[l]]--;
            l++;
        }
        hashm[a[r]]++;
        len = max(r - l + 1, len);
        r++;
    }
    cout<<len<<endl;

}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif 
    FASTIO
    int t;cin>>t;
    while(t--) solve();
    return 0;
}