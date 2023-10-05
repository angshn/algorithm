#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;
int l2[N];
int a[N],dp_min[N][22],dp_max[N][22];
int n,m;

void init(){
    l2[0]=-1;
    for(int i=1;i<=N;i++) l2[i]=l2[i>>1]+1;
    for(int i=1;i<=n;i++){
        dp_min[i][0] = a[i];
        dp_max[i][0] = a[i];
    }
    int p = (int)(log(double(n))/log(2.0));
    for(int k=1;k<=p;k++){
        for(int s=1;s+(1<<k)<=n+1;s++){
            dp_min[s][k] = min(dp_min[s][k-1],dp_min[s+(1<<(k-1))][k-1]);
            dp_max[s][k] = max(dp_max[s][k-1],dp_max[s+(1<<(k-1))][k-1]);
        }
    }
}

int st_query(int l,int r){
    int k = l2[r-l+1];
    int x = min(dp_min[l][k],dp_min[r-(1<<k)+1][k]);
    int y = max(dp_max[l][k],dp_max[r-(1<<k)+1][k]);
    return y-x;
    
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    init();

    for(int i=1;i<=m;i++){
        int l,r;cin>>l>>r;
        cout<<st_query(l,r)<<"\n";
    }
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
