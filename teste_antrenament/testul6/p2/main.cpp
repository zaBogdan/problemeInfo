#include <iostream> 
#include <fstream>
using namespace std;
ifstream f("bac.in");

int main(){
    int n, v[30];
    bool ok=false;
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    for(int i=1;i<=n;i++)
        if(v[i] < i){
            cout << v[i] << ' ';
            ok=true;
        }
    if(!ok)
        cout << "nu exista";
    cout << endl;
    return 0;
}