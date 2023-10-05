#include <bits/stdc++.h>
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
int v[N];
int n,m;
bool check(int mid){

    int cnt = 0;
    int sum = 0;
    for(int i=1;i<=n;i++){
        if(sum+v[i]>mid){
            sum = v[i];
            cnt++;
        }
        else {
            sum+=v[i];
        }
    }
    cnt++;
    return cnt<=m;
}

void solve(){
    cin>>n>>m;
    int l=1,r=0;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        l = max(v[i],l);
        r+=v[i];
    }


    int ans = 0;
    int mid;
    while(l<r){
        mid = (l+r)>>1;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid+1;
        }

    }
    cout<<r<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}
