#include <iostream>
#include <fstream>
using namespace std;
int a[100],b[100];

int main(){
    int n,p,poz=1;
    cin >> n >> p;
    if(n<4 || n%4!=0 || (p<1 || p>n/2))
        cout << "date invalide";
    else {
        for(int i=1;i<=n/2;i++)
            if(i%2==1){
                a[poz] = i;
                a[n/2-poz+1] = (n-i)+1; 
            }else
            {
                b[poz] = i;
                b[n/2-poz+1] = (n-i)+1;
                poz++; 
            }
        if(p%2==1){
            cout << "partitie inexistenta";
        }else{
            
        }

    }
    return 0;
}