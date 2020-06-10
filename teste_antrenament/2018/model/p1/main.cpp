#include <iostream>
using namespace std;

int main(){
    int n,afisat=0;
    cin >> n;
    for(int i=1;i<=n-2;i++){
        if(n%i==0)
        for(int j=i+1;j<n;j++)
            if(n%j==0)
            for(int k=j+1;k<=n;k++)
                if(n%k==0){
                    if(i+j+k==n && !afisat){
                        cout << i << ' ' << j << ' ' << k;
                        afisat = 1;
                    }
            }
        // cout << i << endl;
    }
    if(!afisat)
        cout << "nu exista";
    cout << endl;
    return 0;
}