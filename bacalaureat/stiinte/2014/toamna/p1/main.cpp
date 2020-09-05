#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int x=0;x<n-1;x++)
        for(int y=x+1;y<n;y++)
            for(int z=y+1;z<=n;z++)
                if(x*y+y*z==n){
                    cout << "(";
                    cout << x << "," << y << "," << z;
                    cout << ") ";
                }
    cout << endl;
    return 0;
}