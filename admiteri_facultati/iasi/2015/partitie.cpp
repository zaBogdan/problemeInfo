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
            int s=0;
            for(int i=1;i<=n/2;i++)
                s+=a[i];
            if((p/2)%2==1){
                for(int i=1;i<=n/2;i++)
                    if(a[i]==p/2)
                        a[i]=0;
                b[n/2+1]=p/2;
            }else{
                for(int i=1;i<=n/2;i++){
                    if(a[i]==p/2+1)
                        a[i]=0;
                    if(a[i]==1)
                        a[i]=2;
                    if(b[i]==2)
                        b[i]=1;
                }
                b[n/2+1] = 1+p/2;
            }
            
        }

    }
    return 0;
}