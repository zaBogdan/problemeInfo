#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    //DE UNDE SI PANA UNDE N=8??????
    int n,v[51];
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    int count=0;
    for(int i=1;i<=n;i++){
        if(v[i]%2==0)
            count++;
        else{
            if(count==2){
                // cout << i << ' ';
                i--;
                for(int j=i;j<n;j++)
                    v[j]=v[j+1];
                v[i-1]=2017;
                n--;
            }
            count = 0;
        }
    }
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}