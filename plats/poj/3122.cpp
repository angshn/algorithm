#include <iostream>
#include <cmath>
#include <cstdio>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const double PI = acos(-1.0);
const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
int n,f;
double a[N];
bool check(double m){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=(int)(a[i]/m);
    }

    return sum>=f;
}

void solve(){
    scanf("%d %d",&n,&f);
    f++;
    double maxr = 0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        a[i] = PI*x*x;
        maxr = max(maxr, a[i]);
    }

    double l = 0,r = maxr+0.001;
    double ans = 0;
    // for(int i=0;i<100;i++){

    while((r-l)>eps){
        double mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            l = mid;
        }
        else r = mid;
    }
    printf("%.4f\n",ans);
}
int main()
{
#ifndef ONLINE_JUDEGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    // FASTIO
#ifndef NO_MULTICASE
    int t;scanf("%d",&t);
    while(t--) 
#endif
    solve();
    return 0;
}