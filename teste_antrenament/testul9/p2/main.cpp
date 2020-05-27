#include <iostream> 
#include <fstream>
using namespace std;
ifstream f("file.in");

int main(){
    int n, v[25],last;
    f >> n;
    for(int i=1;i<=n;i++){
        f >> v[i];
        last=v[i];
    }
    for(int i=1;i<=n;i++)
        if(v[i]>last)
            cout << v[i] << ' ';
    cout << endl;
    return 0;
}