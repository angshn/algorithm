#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
#define lowbit(x) (x&(-x))
const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;
int n,q;
int a[N];
int tree1[N],tree2[N];
void update1(int x,int d){
    while(x<=n){
        tree1[x] = max(tree1[x],d);
        x+=lowbit(x);
    }
}
void update2(int x,int d){
    while(x<=n){
        tree2[x] = min(tree2[x],d);

        x+=lowbit(x);
    }
}

int query1(int L,int R){
    int ans = 0;
    while(L<=R){
        ans = max(ans,a[R]);
        R--;
        while(R-L>=lowbit(R)){
            ans = max(ans,tree1[R]);
            R-=lowbit(R);
        }
    }
    return ans;
}
int query2(int L,int R){
    int ans = INF;
    while(L<=R){
        ans = min(ans,a[R]);
        R--;
        while(R-L>=lowbit(R)){
            ans = min(ans,tree2[R]);
            R-=lowbit(R);
        }
    }
    return ans;
}

void solve(){
    cin>>n>>q;
    memset(tree2,0x3f,sizeof(tree2));
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        update1(i,a[i]);
        update2(i,a[i]);
    }
    for(int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        cout<<query1(l,r)-query2(l,r)<<endl;
    }

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