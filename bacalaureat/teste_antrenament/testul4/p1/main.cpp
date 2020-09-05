#include <iostream>
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    int n;
    bool ok=false;
    cin >> n;
    for(int a=2;a<=n/2;a+=2){
        for(int b=1;b<=n/2;b++)
            if(a*b+a/b==n){
                cout << a << '-' << b << ' ';
                ok=true;
            }
    }
    if(!ok)
        cout << "nu exista";
    cout << endl;   
    return 0;
}