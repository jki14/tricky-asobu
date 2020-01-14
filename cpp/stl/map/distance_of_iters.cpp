#include "bits/stdc++.h"
using namespace std;

int main(){
    set<int> rbt;
    for(int i=0; i<100000; i++){
        rbt.insert(i);
    }
    long long lef=0LL;
    long long rig=0LL;
    for(int i=0; i<100000; i++){
        lef+=distance(rbt.begin(), rbt.lower_bound(i));
        rig+=distance(rbt.lower_bound(i), rbt.end());
    }
    cout<<lef<<" "<<rig<<endl;
    return 0;
}
