#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
double a[N];
int n;double l,r; 
double f(double x){
    double s = 0;
    for(int i=n;i>=0;i--) s = s*x+a[i];
    return s;
}


void solve(){
    scanf("%d %lf %lf",&n,&l,&r);
    for(int i=n;i>=0;i--) scanf("%lf", a+i);
    for(int i=0;i<100;i++){
        double k = (r-l)/3.0;
        double mid1 = l+k,mid2=r-k;
        if(f(mid1)>f(mid2)) r = mid2;
        else l = mid1;
    }

    printf("%.5f\n",l);
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