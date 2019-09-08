#include <iostream>
using namespace std;

int elem_pare(int n,int v[]){
    int k=0;
    for(int i=1;i<=n;i++)
        if(v[i]%2==0) // sub b
            k++;
}
void change(int &a,int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

int main(){
    int v[101],n;
    //subpunctul d si e
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> v[i];

    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(v[i]%2==0 && v[j]%2==0)
                if(v[i]>v[j])
                    change(v[i],v[j]);
    for(int i=1;i<=n;i++)
        cout << v[i] << ' ';
    
    return 0;
}