#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class TInversions {
    std::vector<long int> comp;
    std::vector<long long> fenw;
    std::vector<long int> v;
    long int n, t;

    long int getId(long int x) {
        long int l=0, r=comp.size()-1;
        while(l<r) {
            long int m=(l+r)>>1;
            if(comp[m]<x) l=m+1; else r=m;
        }
        return l+1;
    }

    void update(long int i, long int n) {
        for(; i<=n; i+=i&-i) fenw[i]++;
    }

    long long query(long int i) {
        long long s=0;
        for(; i>0; i-=i&-i) s+=fenw[i];
        return s;
    }

public:
    TInversions(long int n, long int t, const std::vector<long int> &arr) {
        this->n=n;
        this->t=t;
        this->v=arr;
    }

    long long solve() {
        for(long int i=0; i<n; i++){
            comp.push_back(v[i]);
            comp.push_back(v[i]+t+1);
        }
        std::sort(comp.begin(), comp.end());
        comp.erase(std::unique(comp.begin(), comp.end()), comp.end());
        fenw.resize(comp.size()+1, 0);
        long long ans=0;
        for(long int i=0; i<n; i++){
            long int idx=getId(v[i]+t+1);
            ans+=query(comp.size())-query(idx-1);
            update(getId(v[i]), comp.size());
        }
        return ans;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long int n,t;
    std::cin >> n >> t;
    std::vector<long int> arr(n);
    for(long int i=0; i<n; i++) std::cin >> arr[i];
    TInversions solver(n,t,arr);
    std::cout << solver.solve();
}