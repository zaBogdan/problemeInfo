#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int max=a;
    for(int i=a;i<=b;i++){
        int p=1;
        for(int j=3;j<i;j+=2)
            if(i%j==0)
                p*=j;
        if(p>i)
            max=i;

    }
    cout << max;

    cout << endl;
    return 0;
}