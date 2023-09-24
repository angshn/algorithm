#include<bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(x) x.begin(),x.end()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;


void solve(){
    int n ;
    vector<pair<int,int>> clt;
    int size = 0;
    rep(i,0,4){
        cin>>n;
        rep(j,0,n){
            int x;
            cin>>x;
            clt.emplace_back(make_pair(x,i));
        }
    }
    sort(all(clt));
    int l = 0;
    size = clt.size();
    int tcnt = 0;
    ll sum = 0;
    ll mn = INF;
    queue<int> st[4];
    int aa[4];
    int tt[4];
    rep(r,0,size){
        st[clt[r].second].push(clt[r].first);
        if(st[clt[r].second].size()==1){
            tcnt ++;
        }
        while(tcnt == 4){
            if(clt[r].first - clt[l].first < mn){
                mn = clt[r].first - clt[l].first;
                rep(i,0,4){
                    tt[i] = st[i].front();
                }
                tt[clt[r].second] = clt[r].first;
            }
            st[clt[l].second].pop();
            if(st[clt[l].second].size()==0){
                tcnt--;
            }
            l++;
        }
    }
    rep(i,0,4){
        cout<<tt[i] << " \n"[i+1==4];
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}