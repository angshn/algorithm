#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

#define ll long long int
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e5 + 5;
int buff[N];
void solve(void ){
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>buff[i];

    int l=0,r = n-1;
    int mx = n,mn = 1;
    while(l<=r){
        if(buff[l]==mn){
            l++;
            mn++;
        }
        else if(buff[l]==mx){
            l++;
            mx--;
        }
        else if(buff[r]==mn){
            r--;
            mn++;
        }
        else if(buff[r]==mx){
            r--;
            mx--;
        }else{
            break;
        }
    }
    if(l>=r){
        cout<<-1<<endl;

    }
    else{
        cout<<l+1<<" "<<r+1<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--) solve();
}