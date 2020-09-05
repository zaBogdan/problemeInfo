#include <iostream>
#include <fstream>
using namespace std;
ifstream f("permutare.in");
const int NMax = 20;
int n, v[NMax],x[NMax],viz[NMax];

void afisare(){
    for(int i=1;i<=n;i++)
        cout << x[i] << ' ';
    cout << endl;
    return;
}
bool valid(int k){
    return x[k-1]==x[k] ? 0 : 1;
}
void bkt(int k){
    if(n+1==k) afisare();
    else{
        for(int i=1;i<=n;i++){
            if(!viz[i]){
                x[k]=v[i];
                viz[i]=true;
                if(valid(k)) bkt(k+1);
            }
        }
        viz[k]=false;
    }
}
int main(){
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    x[1]=v[1];
    viz[1]=true;
    bkt(2);
    return 0;
}