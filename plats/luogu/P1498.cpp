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
const int N = 3e3 + 5;
const int INF = 0x3f3f3f3f;
char a[N][N];
void solve(){
    int n;cin>>n;
    memset(a,' ',sizeof(a));
    a[1][2]=a[2][1]='/';a[1][3]=a[2][4]='\\';a[2][2]=a[2][3]='_';
    

    int w = 4,h=2;
    for(int l=1;l<n;l++){


        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                //下左
                a[i+h][j]=a[i+h][j+w]=a[i][j];
                a[i][j]=' ';
            }
        }


        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                a[i][j+w/2] = a[i+h][j];
            }
        }
        w<<=1,h<<=1;
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout<<a[i][j];
        }
        cout<<"\n";
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