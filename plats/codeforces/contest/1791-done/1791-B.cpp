#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <utility>
#define INPUT_PATH "in.in"
#define TCASE int t;cin >> t;
#define forf(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define pfi(p) p.first
#define psd(p) p.second 
#define DEBUG(x) clog<<x;
using namespace std;
const int N = 1e2 + 5;
char buffer[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen(INPUT_PATH, "r", stdin);
#endif
    TCASE
    
    while(t--){
        int n; cin>>n;
        cin >> buffer;
        pair<int,int> st(0,0);
        bool ok = false;
        forf(i,n){
            switch(buffer[i]){
                case 'U':
                    psd(st)+=1;
                    break;
                case 'L':
                    pfi(st)-=1;

                    break;
                case 'D':
                    psd(st)-=1;
                    break;
                case 'R':
                    pfi(st)+=1;
                    break;
            }
            DEBUG(pfi(st))
            DEBUG(", ")
            DEBUG(psd(st))
            DEBUG("\n")
            if(pfi(st)==1 && psd(st)==1){
                ok  = true;
                break;
            }
        }
        ok?cout<<"YES\n":cout<<"NO\n";
    }
}