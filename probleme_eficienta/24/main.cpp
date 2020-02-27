#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.in");
int fr[10];

int main(){
    int n, x,min=9;
    f >> n;
    for(int i=1;i<=n;i++){
        f >> x;
        int max=0;
        while(x){
            int c=x%10;
            max = c>max ? c : max;
            x/=10;
        }
        //if(max!=0)
        min = max<min && max ? max : min;
        fr[max]++;
    }
    cout << min;
    fr[min]--;
    for(int i=0;i<=n;i++){
        if(fr[i])
            for(int j=1;j<=fr[i];j++)
                cout << i;
    }
    cout << endl; //development purpose.
    return 0;
}