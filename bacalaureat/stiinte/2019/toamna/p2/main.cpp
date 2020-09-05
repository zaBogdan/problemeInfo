#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int n,v[22];
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    int nr=v[1], maxlen=0,len=1;
    for(int i=2;i<=n;i++){
        if(v[i]==nr){
            len++;
            if(len>maxlen)
                maxlen=len;
        }
        else{
            len=1;
            nr=v[i];
        }
    }
    cout << maxlen;
    cout << endl;
    return 0;
}