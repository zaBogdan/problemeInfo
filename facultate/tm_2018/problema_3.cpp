#include <iostream>
using namespace std;

void ordonare(int v[],int n){
    bool sortat;
    do{
        sortat=1;
        for(int i=1;i<n-1;i++){
            if(i%2==0 && v[i]>v[i+2]){
                    swap(v[i],v[i+2]);
                    sortat=0;
            }
            if(i%2==1 && v[i]<v[i+2]){
                    swap(v[i],v[i+2]);
                    sortat=0;
            }
            

        }
    }while(!sortat);
}

int main(){
    int v[]={0,5,1,7,6,2,1,8,3};
    ordonare(v,8);
    for(int i=1;i<=8;i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}