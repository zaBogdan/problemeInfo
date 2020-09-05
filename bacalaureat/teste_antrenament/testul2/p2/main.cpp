#include <iostream>
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    short n, v[201]={0};
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    for(int i=1;i<=n;i++)
        if(v[i]<0){
            for(int j=i;j<=n;j++)
                v[j]=v[j+1];
            n--;
            i--;
        }
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    cout << endl;   
    return 0;
}