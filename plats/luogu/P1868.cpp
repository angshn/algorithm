#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 150010;
const int INF = 0x3f3f3f3f;
#define pii pair<int,int>
pii a[N];
int dp[N];
int n;
int grass(int i){
    return a[i].second - a[i].first + 1;
}
bool cmp(pii &x,pii &y){//y相同区间尽量短

    if(x.second == y.second){
        return x.first < y.first;
    }

    return x.second < y.second;
}



int find(int x){
    int l=1,r=n;
    int ans = -1;
    while(l<=r){
        int mid = (l+r)>>1;
        if(a[mid].second < a[x].first){
            ans = mid;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    return ans;
}

void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+1+n,cmp);
    dp[1] = grass(1);
    for(int i=2;i<=n;i++){
        int last = find(i);
        if (last != -1){
            dp[i] = max(dp[i-1], dp[last]+grass(i));
        }
        else {
            dp[i] = max(dp[i-1], grass(i));
        }
    }
    cout<<dp[n]<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}