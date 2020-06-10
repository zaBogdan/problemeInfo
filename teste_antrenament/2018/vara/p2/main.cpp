#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int ns,nc, s[100]={0},c[100]={0};
    f >> ns >> nc;
    if(ns==nc){
        for(int i=1;i<=ns;i++)
            f >> s[i];
        for(int i=1;i<=nc;i++){
            int x;
            f >> x;
            c[i]=x%2;
        }
        for(int i=1;i<=ns;i++){
            if(c[i]==0){
                int aux = s[i];
                for(int j=i;j>=1;j--)
                    s[j]=s[j-1];
                s[1]=aux;
            }
        }
        for(int i=1;i<=ns;i++)
            cout << s[i] << ' ';
    }else 
        cout << "cod incorect";
    cout << endl;
    return 0;
}