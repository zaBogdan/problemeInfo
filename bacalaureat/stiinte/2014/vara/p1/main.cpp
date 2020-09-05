#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ffact=1,sfact=1;
    for(int i=1;i<n;i++)
        ffact*=i;
    for(int j=1;j<=n+1;j++)
        sfact*=j;
    cout << ffact+1 << ' ' << sfact-1;
    cout << endl;
    return 0;
}