#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 3e2 + 5;
const int C = 101;
const int INF = 0x3f3f3f3f;
//每种c的取值在tree上的和
#define SZ [C][N][N]
int t1 SZ,t2 SZ, t3 SZ, t4 SZ;
int cc[N][N];
inline int lowbit(int x){return x&(-x);}
int n,m;
void update(int x,int y,int d,int c){



    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            t1[c][i][j]+=d;
        }
    }
}

int query(int x,int y,int c){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i)){
        for(int j=y;j;j-=lowbit(j)){
            ans += t1[c][i][j];
        }
    }
    return ans;
}



void solve(){
    n = read(),m = read();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x = read();
            cc[i][j]=x;
            update(i,j,1,x);
        }
    }
    int q = read();
    while(q--){
        int op = read();
        if(op==1){
            int x=read(),y=read(),c=read();
            //原来的颜色要改成0了，获取原来位置的x,y对应的位置颜色
            int o = cc[x][y];
            cc[x][y] = c;
            update(x,y,-1,o);
            update(x,y,1,c);
        }
        else {
            int x1=read(),x2=read(),y1=read(),y2=read(),c=read();
            int ans = query(x2,y2,c)+query(x1-1,y1-1,c)-query(x1-1,y2,c)-query(x2,y1-1,c);
            printf("%d\n",ans);
        }
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