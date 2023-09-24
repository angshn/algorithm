#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define pii pair<ll,ll> 
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int inf = 2000000000+5;
int ans;
pii a[N];

pair<int,int> two_point(int target,int n){

    int i=0,j=1;
    int l,r;
    //接近可以是小于也可以是大于
    ll dmin = inf;
    int sum = 0;
    while(j<=n){
        sum = a[j].first - a[i].first;
        if(abs(sum-target)<dmin){
            dmin = abs(sum-target);
            l = a[i].second;
            r = a[j].second;    
            ans = sum;
        }

        if(sum>target){ 
            i++;

        }
        else if(sum<target){
            j++;
        }
        else {
            break;
        }
        if (i == j)
        {
            j++;
        }
    }

    return {min(l,r),max(l,r)};

}
void solve(){
    int n,k;cin>>n>>k;
    while(n!=0&&k!=0){
        a[0].first = a[0].second = 0;
        for(int i=1;i<=n;i++) {
            cin>>a[i].first;
            a[i].first = a[i].first + a[i-1].first;
            a[i].second = i;
        }

        sort(a,a+n+1);
        for(int i=0;i<k;i++){
            ll t;cin>>t;
            ans = 0;
            pair<int,int> lr = two_point(t, n);
            cout<< ans <<" "<<lr.first+1<<" "<<lr.second<<endl;
        }
        cin>>n>>k;
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