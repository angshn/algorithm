#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

using namespace std;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int n;
int s[N];
void Init(){for(int i=0;i<N;i++) s[i]=i;}
int Find(int x){
    return x==s[x]?x:s[x]=Find(s[x]);
}
void Merge(int x,int y){
    int fx = Find(x),fy=Find(y);
    if(fx!=fy) 
        s[fx] = fy;
}

struct Ins{
    int x,y,e;
    bool operator < (const Ins&rhs)const {
        return e>rhs.e;
    }
}a[N];
int b[N];
void solve(){
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].e;
        b[cnt++]=a[i].x;
        b[cnt++]=a[i].y;
    }
    Init();
    sort(b,b+cnt);
    cnt = unique(b,b+cnt) - (b);
    map<int,int> hsh;
    for(int i=0;i<cnt;i++){
        hsh[b[i]]=i+1;
    }
    for(int i=1;i<=n;i++){
        a[i].x = hsh[a[i].x];
        a[i].y = hsh[a[i].y];
    }

    sort(a+1,a+1+n);

    string ans = "YES\n";
    for(int i=1;i<=n;i++){
        int u = a[i].x;
        int v = a[i].y;
        int op = a[i].e;
        if(op){
            Merge(u,v);
        }
        else {
            if(Find(u)==Find(v)){
                ans = "NO\n";
                break;
            }
        }
    }
    cout<<ans;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    int t;cin>>t;
    while(t--) solve();
    return 0;
}