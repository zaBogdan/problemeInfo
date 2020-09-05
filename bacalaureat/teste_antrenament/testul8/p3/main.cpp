#include <iostream> 
#include <fstream>
using namespace std;
ifstream f("bac.in");

int main(){
    int fr[10]={0},x,apmax=0;
    while(f >> x){
        fr[x%10]++;
        apmax = apmax<fr[x%10] ? fr[x%10] : apmax;
    }
    for(int i=0;i<10;i++)
        if(fr[i]==apmax)
            cout << i << ' ';
    cout << endl;
    return 0;
}