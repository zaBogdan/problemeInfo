#include <iostream>
#include <fstream>
using namespace std;
int n,v[100];

bool valid(int k){
    if(v[k-1]>v[k])
        return 0;
    if(k>n)
        return 0;
    int suma_nr = 0;
    double suma_under =0;
    for(int i=1;i<=k;i++){
        suma_nr+=v[i];
        suma_under += (double) 1/v[i];
    }
        cout << k << ' ' << suma_nr << ' ' << suma_under << endl;
    if(suma_nr==n && suma_under ==1)
        return 1;
    return 0;
    // int s=0;
    // double suma=0;
    // for(int i=1;i<=k;i++){
    //     s+=v[i];
    //     if(v[i])
    //         suma = suma+ (double) 1/v[i];
    // }
    // // cout << suma << endl;
    // if(s==n && suma==1)
    //     return 1;
    // return 0;
}
void afisare(int k){
    for(int i=1;i<=k;i++)
        cout << v[i] << ' ';
    cout << endl;
}
void bkt(int k){
    if(valid(k-1)) afisare(k-1);
    else{
        for(int i=1;i<=n;i++){
            v[k]=i;
            bkt(k+1);
        }
    }
}

int main(){
    ifstream f("nsir.in");
    f >> n;
    f.close();
    bkt(1);
    return 0;
}
