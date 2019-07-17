#include <iostream>
#include <fstream>
using namespace std;
bool ok=false;
int n,s,val[10],card[10],suma,x[10];

void read();
bool valid(){
    suma = 0;
    for(int k=1;k<=n;k++)
        suma += val[k]*x[k];
    if(suma==s)
        return 1;
    return 0;
}
void afisare(){
    if(valid()){
        for(int i=1;i<=n;i++)
            cout << x[i] << ' ';
        cout << '\n';
        ok = true;
    }
}
void bkt(int k){
    if(k==n+1 && !ok) afisare();
    else
        for(int i=1;i<=card[k];i++){
            x[k] = i;
            bkt(k+1);
        }
}

int main(){
    read();
    bkt(1);
    return 0;
}

void read(){
    // ifstream f("plata1.in"); //to be removed!
    cin >> n >> s;
    for(int i=1;i<=n;i++)
        cin >> val[i];
    for(int i=1;i<=n;i++)
        cin >> card[i];
    // f.close();
}