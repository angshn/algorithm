#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
struct Line{
    ll y;ll lx,rx;
    int inout;
    Line(){}
    Line(ll y,ll x2,ll x1,int io):y(y),rx(x2),lx(x1),inout(io){}
}line[N],line2[N];

ll sum[N<<2];
ll tag[N<<2];
int xx[N];
int yy[N];
void pushup(int p,int pl,int pr,int c){
    if(tag[p]){
        if(c==0){
            sum[p]=xx[pr]-xx[pl];
        }
        else {
            sum[p] = yy[pr] - yy[pl];
        }
    }
    else if(pl+1==pr) sum[p]=0;
    else sum[p]=sum[ls(p)]+sum[rs(p)];
}

void update(int L,int R,int p,int pl,int pr,int d,int c){
    if(L<=pl and pr <=R){
        tag[p]+=d;pushup(p,pl,pr,c);return;
    }
    if(pl+1==pr) return;
    int mid = (pr+pl)>>1;
    if(L<=mid) update(L,R,ls(p),pl,mid,d,c);
    if(R>mid)  update(L,R,rs(p),mid,pr,d,c);
    pushup(p,pl,pr,c);
}
bool cmp(Line &A, Line &B){
    if(A.y==B.y){
        return A.inout>B.inout;
    }
    return A.y<B.y;
}
void solve(){

    int n;
    while(cin>>n){
        memset(sum, 0, sizeof(sum));
        memset(tag, 0, sizeof(tag));
        int cnt = 0;
        int cnt2 = 0;
        for (int i = 1; i <= n; i++)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            line[++cnt] = Line(y1, x2, x1, 1);
            xx[cnt] = x1;
            line[++cnt] = Line(y2, x2, x1, -1);
            xx[cnt] = x2;

            line2[++cnt2] = Line(x1, y2, y1, 1);
            yy[cnt2] = y2;
            line2[++cnt2] = Line(x2, y2, y1, -1);
            yy[cnt2] = y1;
        }
        ll ans = 0;
        sort(xx + 1, xx + 1 + cnt);
        sort(line + 1, line + 1 + cnt, cmp);

        int num = unique(xx + 1, xx + 1 + cnt) - xx - 1;

        ll pre = 0;
        for (int i = 1; i <= cnt; i++)
        {
            int L = lower_bound(xx + 1, xx + 1 + num, line[i].lx) - xx;
            int R = lower_bound(xx + 1, xx + 1 + num, line[i].rx) - xx;
            pre = sum[1];
            update(L, R, 1, 1, num, line[i].inout, 0);
            if (sum[1] != pre)
            {
                ans += abs(pre - sum[1]);
            }
        }
        memset(sum, 0, sizeof(sum));
        memset(tag, 0, sizeof(tag));
        sort(yy + 1, yy + 1 + cnt2);
        sort(line2 + 1, line2 + 1 + cnt2, cmp);
        int num2 = unique(yy + 1, yy + 1 + cnt2) - yy - 1;
        pre = 0;
        ll ans2 = 0;
        for (int i = 1; i <= cnt2; i++)
        {
            int L = lower_bound(yy + 1, yy + 1 + num2, line2[i].lx) - yy;
            int R = lower_bound(yy + 1, yy + 1 + num2, line2[i].rx) - yy;
            pre = sum[1];
            update(L, R, 1, 1, num2, line2[i].inout, 1);
            if (sum[1] != pre)
            {
                ans2 += abs(pre - sum[1]);
            }
        }
        cout << ans2 + ans << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;solve();return 0;
}