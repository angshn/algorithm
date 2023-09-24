#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
void solve(){
    int n;ll s;cin>>n>>s;
    GETA(a,n)
    int l = 0;
    ll sum = 0;
    ll ans = 0;
    for (int r = 0; r < n; r++){
        sum += a[r];
        while(sum - a[l] >= s){
            sum -= a[l];
            l++;
        }
        if(sum >=s){
            ans += l+1;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
      freopen("/Users/syang/career/algorithm/codeforces/in.in","r",stdin);
     #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}