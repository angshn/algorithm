#include <iostream>
#include <cstdio>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read();
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
int s[N];
void Init(){
    for(int i=0;i<=N;i++) s[i]=i;
}

int Find(int x){
    if(x!=s[x]){
        s[x] = Find(s[x]);
    }
    return s[x];
}
void Merge(int x,int y){
    int rx = Find(x);
    int ry = Find(y);

    if(rx !=ry ){
        if(rx<ry) s[ry]=rx;
        else s[rx] = ry;
    }
}

void solve(){
    while (cin >> n >> m ){
        if(!n&&!m) break;
        Init();
        while(m--){
            int k;cin>>k;
            int x;
            int pre = -1;
            while(k--){
                cin>>x;
                if(pre == -1) pre = x;
                else Merge(pre,x);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(Find(i)==0){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
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