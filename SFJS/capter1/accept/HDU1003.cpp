#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int buf[N];
int kase = 1;
void solve(){
    int n;cin>>n;
    
    int maxsum = -INF;
    int sum = 0;
    int start=1,end=1;
    int p=1;
    for(int i =0;i<n;i++)
    {
        int x;cin>>x;sum+=x;
        if(sum > maxsum)
        {
            maxsum = sum;
            start = p;
            end = i + 1; 
        }
        if (sum < 0)
        {
            sum = 0;
            p = i + 2;
        }

    }
    cout << "Case " << kase++ <<":\n" << maxsum << " " << start <<" " << end << "\n";

}
int main()
{
    FASTIO
#ifndef NO_MULTICASE
    int t;cin>>t;
    while(t--) 
#endif
    solve();
    return 0;
}
