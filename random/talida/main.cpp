#include <fstream>
using namespace std;
ifstream f("BAC.IN");
ofstream g("BAC.OUT");

//punctul a)
int p(int n,int c){
    int p=1,m=0;
    while(n>1){
        if(n%10!=c){
            m = (n%10)*p+m;
            p*=10;
        }
        n/=10;
    }
    if(p==1)
        return 0;
    else return m;
}

int main(){
    int x;
    while(f >> x){
        //caut toate cifrele impare
        for(int i=1;i<=9;i+=2)
            x = p(x,i);
        if(x)
            g << x << ' ';
    }

    return 0;
}