#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>

class TBigMultiplication {
    std::string A,B;

    void fft(std::vector<std::complex<long double>> &a, bool inv) {
        long int n=a.size();
        for(long int i=1,j=0; i<n; i++){
            long int bit=n>>1;
            for(; j&bit; bit>>=1) j^=bit;
            j^=bit;
            if(i<j) std::swap(a[i], a[j]);
        }
        for(long int len=2; len<=n; len<<=1){
            long double ang=2.0L*acosl(-1.0L)/len*(inv?-1.0L:1.0L);
            std::complex<long double> wlen(cosl(ang), sinl(ang));
            for(long int i=0; i<n; i+=len){
                std::complex<long double> w(1.0L, 0.0L);
                for(long int j=0; j<len/2; j++){
                    std::complex<long double> u=a[i+j];
                    std::complex<long double> v=a[i+j+len/2]*w;
                    a[i+j]=u+v;
                    a[i+j+len/2]=u-v;
                    w*=wlen;
                }
            }
        }
        if(inv) {
            for(long int i=0; i<n; i++) a[i]/=n;
        }
    }

public:
    TBigMultiplication(const std::string &A, const std::string &B) {
        this->A=A;
        this->B=B;
    }

    std::string solve() {
        if(A=="0" || B=="0") return "0";
        long int n=A.size();
        long int m=B.size();
        long int size=1;
        while(size < n+m) size<<=1;
        std::vector<std::complex<long double>> fa(size), fb(size);
        for(long int i=0; i<n; i++) fa[i]=A[n-1-i]-'0';
        for(long int i=0; i<m; i++) fb[i]=B[m-1-i]-'0';
        fft(fa, false);
        fft(fb, false);
        for(long int i=0; i<size; i++) fa[i]*=fb[i];
        fft(fa, true);
        std::vector<long long> res(size);
        for(long int i=0; i<size; i++){
            res[i]=(long long)llroundl(fa[i].real());
        }
        for(long int i=0; i+1<size; i++){
            res[i+1]+=res[i]/10;
            res[i]%=10;
        }
        while(res.size()>1 && res.back()==0) res.pop_back();
        std::string ans;
        for(long int i=res.size()-1; i>=0; i--) ans.push_back((char)('0'+res[i]));
        return ans;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string A,B;
    std::cin >> A >> B;
    TBigMultiplication solver(A,B);
    std::cout << solver.solve();
}