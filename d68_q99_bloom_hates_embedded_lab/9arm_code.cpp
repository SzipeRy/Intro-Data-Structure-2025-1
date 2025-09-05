#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n; int m,q;
    cin >> n >> m >> q;
    vector<pair<ll,ll>> v;
    
    while(m--){
        ll p,f;
        cin >> p >> f;
        v.push_back(make_pair(max((ll)1,p - f),min(n,p + f)));
    }
    
    sort(v.begin(), v.end());
    
    map<ll,ll> broken;
    
    int i;
    for(i = 0; i < v.size(); ++i){
        if(broken.empty()){
            broken[v[i].first] = v[i].second;
            continue;
        }
        
        auto it = broken.rbegin();
        if(it->second >= v[i].first){
            it->second = max(v[i].second,it->second);
        } else {
            broken[v[i].first] = v[i].second;
        }
    }

    //for(auto &p :broken) cout << p.first << "-" << p.second << endl;
     
    
    while(q--){
        ll l,r;
        cin >> l >> r;
        
        auto it = broken.upper_bound(l);
        
        auto before = broken.begin();
        
        ll range = r - l + 1;
        
        //cout << it->first << "," << it->second << endl;
        
        //cout << before->first << "," << before->second << endl;
        
        //cout << (it != before) << (it->second >= r) << endl;
        
        if(it != before){
            it--;
            if(it->second >= r){
                cout << 0 << endl;
                continue;
            }
            
            if(it->second >= l){
                range -= it->second - l + 1;
            }
            
            it++;
        }
        
        
        //if(it != before && it->second >= l){
            //range -= it->second - l - 1;
        //}
        
        
        while(it != broken.end() && it->first <= r){
            range -= min(it->second - it->first + 1,r - it->first + 1);
            it++;
        }
        
        cout << range << endl;
    }
    
    return 0;
}