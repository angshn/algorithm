#include <iostream>
#include<cstdio>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read();
using namespace std;
const int N = 5e4+ 5;
const int INF = 0x3f3f3f3f;
int s[N];
int d[N];
int ans;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
void init_set(){
    for(int i=0;i<=N;i++){
         s[i] = i;d[i]=0;
    }
}
int find_set(int x){
    if(x!=s[x]){
        int t = s[x];
        s[x] = find_set(s[x]);
        d[x] = (d[x] + d[t]) % 3;
    }
    return s[x];
}

void merge_set(int x,int y, int rel){
    int rx = find_set(x);
    int ry = find_set(y);
    if(rx == ry){
        if ((rel - 1) != ((d[x] - d[y] + 3) % 3))
            ans++;
    }
    else {
        s[rx] = ry;
        d[rx] = (d[y] - d[x] + rel - 1) % 3;
    }
}


void solve(){
    int n,k;n=read();k=read();
    init_set();
    ans = 0;
    while(k--){
        int r,x,y;scanf("%d %d %d",&r,&x,&y);
        if (x > n || y > n || (r == 2 && x == y))
            ans++;
        else merge_set(x,y,r);
    }
    printf("%d\n",ans);
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