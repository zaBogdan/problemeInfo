#include <iostream>
#include <fstream>
using namespace std;
ofstream g("castig.out");
const int NMax = 100001;
unsigned long long n,k,v[NMax],s[NMax],smax[NMax], dmax[NMax];

void read();
void next_vectors(){
    for(int i=1;i<=n-k+1;i++){
        int maxim = 0;
        for(int j=1;j<=i;j++)
            if(maxim<s[j])
                maxim = s[j];
        smax[i] = maxim;

        maxim = 0;
        for(int j=i;j<=n-k+1;j++)
            if(maxim<s[j])
                maxim = s[j];
        dmax[i] = maxim;
    }
    // for(int i=1;i<=n-k+1;i++)
    //     cout << s[i] << endl;
    int maxim = 1000000000;
    for(int i=k+1;i<=n-k+1;i++){
        int maxy = max(smax[i-k],dmax[i+k]);
        if(maxim > maxy){
            maxim = maxy;
        }
    }
    cout << maxim << endl;

}

int main(){
    read();
    next_vectors();
    return 0;
}

void read(){
    ifstream f("castig.in");
    f >> n >> k;
    int poz = 1;
    for(int i=1;i<=k;i++){
        f >> v[i];
        s[poz]+=v[i];
    }
    for(int i=k+1;i<=n;i++){
        f >> v[i];
        int sum = s[poz]-v[i-k]+v[i];
        s[++poz] = sum;
    }
    f.close();
}
