#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define ll long long int
#define INF_32 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 5;
void solve();
void solve()
{
    int n;
    cin >> n;
    string name;
    int scr;
    vector<pair<int, string>> history;
    map<string, int> scrs;
    set<string> names;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> scr;
        scrs[name] += scr;
        names.insert(name);
        history.emplace_back(make_pair(scrs[name], name));
    }
    int _max = -INF_32;

    for (auto &n : names)
    {
        _max = max(_max, scrs[n]);
    }
    int cnt = 0;
    for (auto &n : names)
    {
        if (scrs[n] == _max){
            cnt++;
            name = n;
        }
    }
    if (cnt > 1)
    {
        // Finding the people of earliest get _max score
        int _min = INF_32;
        for (auto &n : names)
        {
            if (scrs[n] == _max)
            {
                int _c = INF_32;
                for (int i = 0; i < history.size(); i++)
                {
                    int fst = history[i].first;
                    string snd = history[i].second;
                    if (snd == n && fst >= _max)
                    {
                        _c = min(_c, i);
                        break;
                    }
                }
                _min = min(_min, _c);
            }
        }
        name = history[_min].second;
    }
    cout<<name<<endl;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}