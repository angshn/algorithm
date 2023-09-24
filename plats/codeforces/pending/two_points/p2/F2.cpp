#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
ll a[N];
void solve(){
    int n;ll k;cin>>n>>k;
    GETA(a,n);
    int l=0;
    multiset<ll> s;
    ll ans = 0;
    for(int r = 0;r<n;r++){
        s.insert(a[r]);
        while (*s.rbegin() - *s.begin() > k){
            s.erase(s.find(a[l++]));
        }
        ans += r - l + 1;
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}