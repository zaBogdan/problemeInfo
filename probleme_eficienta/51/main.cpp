#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
int fr[10];

int main(){
    int n;
    f >> n;
    for(int i=1;i<=n;i++){
        int x;
        f >> x;
        fr[x]++;
    }
    for(int i=0;i<=9;i++)
        if(fr[i])
            for(int j=1;j<=fr[i];j++)
                cout << i << ' ';
    cout << endl; //development purpose.
    return 0;
} 