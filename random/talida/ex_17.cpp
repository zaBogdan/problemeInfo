#include <iostream>
using namespace std;

//punctul a)
int nx(int n){
    int d2=0,d5=0;
    //caut cati de 2 si 5 am 
    for(int i=1;i<=n;i++){
        if(i%2==0) d2++;
        if(i%5==0) d5++;
    }
    //calculez minimul dintre 2 si 5
    //cazul in care sunt mai putini multipli de 2
    if(d2<d5)
        return d2;
    //cazul cand sunt mai putini multipli de 5 sau e egal
    else return d5;
}

int main(){
    //punctul b
    int n,k;
    cin >> k;
    if(k==0)
        cout << 0;
    else{
        int found=0;
        int n=5;
        while(!found){
            if(nx(n)==k){
                cout << n;
                found = 1;
            }
            n++;
        }
    }
    cout << endl;
    return 0;
}