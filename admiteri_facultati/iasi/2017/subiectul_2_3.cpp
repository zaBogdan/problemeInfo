#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int m,n,first_ascii = 97,min=0;
    char a[16][256];
    cin >> m >> n; 
    for(int i=1;i<=n;i++){
        cin >> a[i];
        min = min>strlen(a[i]) ? strlen(a[i]) : min;
    }
    cout << min;
}