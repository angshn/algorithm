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
int a[N];
int n,c;
bool check(int d){
    int cnt = 1;
    int place = 0;
    for(int i=1;i<n;i++){
        if(a[i]-a[place] >= d){
            cnt++;
            place = i;
        }
    }
    return cnt>=c;
}


void solve(){
cin>>n>>c;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int l=0,r=a[n-1]-a[0];
    int ans = 0;
    while(l<r){
        int mid = (l+r)>>1;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }
        else {
            r = mid;
        }
    }
    cout<<ans<<endl;
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