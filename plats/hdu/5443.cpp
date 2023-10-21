#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
int st[N][11];
int a[N];
int n;

void init(){

    for(int i=1;i<=n;i++){
        st[i][0]=a[i];
    }
    int p = log(double(n))/log(2.0);

    for(int k=1;k<=p;k++){
        for(int s=1;s+(1<<k)<=n+1;s++){
            st[s][k] = max(st[s][k-1], st[s+(1<<(k-1))][k-1]);

        }
    }
}

int query(int l,int r){
    int k = log(r-l+1)/log(2.0);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<query(l,r)<<"\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}