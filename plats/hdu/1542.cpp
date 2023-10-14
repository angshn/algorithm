#include <bits/stdc++.h>
#define ll long long int
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e4 + 5;
const int INF = 0x3f3f3f3f;
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
int tag[N];
double length[N];
double xx[N];
struct ScanLine{
	double y;
    double right_x, left_x;
    int inout;
    ScanLine(){};
    ScanLine(double y, double x2, double x1, int io) :
         y(y), right_x(x2), left_x(x1), inout(io) {}

}line[N];

void pushup(int p,int pl, int pr){
    if (tag[p]) length[p] = xx[pr] - xx[pl];//这个线段对计算宽度有效，计入宽度
    else if (pl + 1 == pr) length[p] = 0;   //叶节点不行，左闭右开
    else length[p] = length[ls(p)] + length[rs(p)]; //tag不为0的总宽度
}

void update(int L,int R,int io,int p,int pl,int pr){
    if(L<=pl&&pr<=R){
        tag[p]+=io;
        pushup(p, pl, pr);
        return;
    }
    if (pl + 1 == pr) return;
    int mid = (pl+pr)>>1;
    if(L<=mid) update(L,R,io,ls(p),pl,mid);
    if(R>mid)  update(L,R,io,rs(p),mid,pr);
    pushup(p,pl,pr);
}

bool cmp(ScanLine &a,ScanLine &b){
    return a.y<b.y;
}

void solve(){
    int n,t=0;
    while(scanf("%d",&n),n){
        int cnt = 0;
        while(n--){
            double x1,x2,y1,y2;scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            line[++cnt]=ScanLine(y1,x2,x1,1);
            xx[cnt]=x1;
            line[++cnt]=ScanLine(y2,x2,x1,-1);
            xx[cnt]=x2;
        }
        sort(xx + 1, xx + 1 + cnt);
        sort(line + 1, line + 1 + cnt, cmp);
        int num = unique(xx + 1, xx + cnt + 1) - (xx + 1);

        memset(tag, 0, sizeof(tag));
        memset(length, 0, sizeof(length));
        double ans = 0;
        for (int i = 1; i <= cnt; ++i)
        {
            int L, R;
            ans += length[1] * (line[i].y - line[i - 1].y); //W*H 
            L = lower_bound(xx + 1, xx + num + 1, line[i].left_x) - xx;
            R = lower_bound(xx + 1, xx + num + 1, line[i].right_x) - xx;
            update(L, R, line[i].inout, 1, 1, num);
        }

        printf("Test case # %d\nTotal explored area: %.2f\n\n", ++t, ans);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}
