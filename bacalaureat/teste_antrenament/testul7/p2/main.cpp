#include <iostream> 
#include <fstream>
using namespace std;
ifstream f("bac.in");


void frecventa(){
    int n, v[50]={0},x;
    f >> n;
    for(int i=1;i<=n;i++){
        f >> x;
        v[x]=1;
    }
    for(int i=1;i<=n;i++){
        f >> x;
        if(v[x]==1)
            cout << x << ' ';
    }

}

int main(){
    // frecventa();
    int n,v[50];
    f >> n;
    for(int i=1;i<=2*n;i++)
        f >> v[i];
    for(int i=1;i<=n;i++)
        for(int j=n+1;j<=2*n;j++)
            if(v[i]==v[j])
                cout << v[i] << ' ';

    cout << endl;
    return 0;
}