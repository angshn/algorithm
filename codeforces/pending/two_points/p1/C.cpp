#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N],b[N];
void solve(){
    int n,m;cin>>n>>m;
    GETA(a,n);GETA(b,m);
    int i=0,j=0;
    a[n] = INF;
    b[m] = INF;
    ll cnt = 0;
    int *a1 ,*a2;
    if (a[0] <= b[0])
    {
        a1 = a;a2 = b;
    }
    else {
        a1 = b;a2 = a;
        int __tt = n;
        n = m;
        m = __tt;
    }

    while (j < m)
    {
        int &x = a2[j];
        while(i<n&&a1[i]<x){i++;}
        ll _c = 0;
        while(i<n&&a1[i]==x){i++; _c++;}
        j++;
        ll _c2 = 1;
        while (j < m && a2[j] == x)
        {
            j++;
            _c2++;
        }
        cnt += _c*_c2;
    }
    cout<<cnt<<endl;

}
int main()
{
    #ifndef ONLINE_JUDGE
      freopen("/Users/syang/career/algorithm/codeforces/in.in","r",stdin);
     #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}