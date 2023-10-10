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
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int tree[N];
int a[N];
int n,m;
int lowbit(int x){return x&(-x);}
void update(int x,int value){
    while(x<=n){
        tree[x] = max(tree[x],value);
        x += lowbit(x); // 算父节点
    }
}

int query(int L,int R){
    int ans = 0;
    while (L <= R){
        ans = max(ans,a[R]);
        R--;
        while (R - L >= lowbit(R)){
            ans = max(ans, tree[R]);
            R -= lowbit(R);
        }
    }
    return ans;
}

void solve(){
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    while(m--){
        char s[5];int A,B;cin>>s>>A>>B;

        if(s[0]=='U'){
            a[A] = max(a[A],B);
            update(A, B);
        }
        else {
            cout<<query(A,B)<<endl;
        }
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