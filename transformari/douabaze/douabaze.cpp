#include <iostream>
#include <cstring>
using namespace std;
char c[105];

int main()
{
    cin >> c;
    int nd=0;
    int len = strlen(c);
    int i;
    if(len%2==0) nd=0,i=0;
    else cout << 1,i=1;

    while(i<len-1){
        if(c[i]=='0'){
            if(c[i+1]=='0')
                cout << 0;
            if(c[i+1]=='1')
                cout << 1;
        }else if(c[i]=='1'){
            if(c[i+1]=='0')
                cout << 2;
            if(c[i+1]=='1')
                cout << 3;
        }
        i+=2;
    }
    return 0;
}
