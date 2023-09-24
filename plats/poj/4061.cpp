#include <iostream>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
void solve(){
    int n,s;cin>>n>>s;
    int i=0,j=0;
    for(int k=0;k<n;k++) cin>>a[k];

    int sum = 0;
    int ans = INF;
    while(j<=n){
        if(sum>=s){
            ans = min(ans, j - i);
            sum-=a[i++];
            if(i>j){
                sum = a[i],j++;
            }
        }
        if(sum<s) {
            sum+=a[j++];
        }
    }
    if(ans == INF)ans=0;
    cout<<ans<<endl;
    

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