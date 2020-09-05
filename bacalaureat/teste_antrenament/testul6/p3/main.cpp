#include <iostream> 
#include <fstream>
using namespace std;
ofstream g("bac.out");

int main(){
    int p1,p2;
    cin >> p1 >> p2;
    for(int i=9;i>=1;i--)
        if(p1%i==0 && p1/i<10)
            for(int j=9;j>=1;j--)
                if(p2%j==0 && p2/j<10){
                    g << i << p1/i;
                    g << 0 << 0 << 0;
                    g << j << p2/j << '\n';
                }
    return 0;
}