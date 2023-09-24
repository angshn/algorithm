#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N],b[N];

inline int bsearch(int buff[],int l,int r,int x){

    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] < x)
        {
            l = mid + 1;
        }
        else {
            r = mid ;
        }
    }
    return l;
}


void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    a[n] = INF;
    b[m] = INF;
    int i=0,j=0;
    a[n] = b[m] = INF;
    while(i<n || j<m){
        if(a[i]<b[j]){
            i++;
        }
        else {
            cout<<i<<" ";
            j++;
        }
    }   
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}