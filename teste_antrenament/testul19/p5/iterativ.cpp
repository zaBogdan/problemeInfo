#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bac.in");
ofstream g("bac.out");
// const int nefericite[] = {0,4,16,20,37,42,58,89,145};

int main(){
    int x;
    while(f >> x){
        int frecv = 0,cx=x;
        while(x!=0 && x!=4 && x!=16 && x!=20 && x!=37 && x!=42 && x!=1 && x!=58 && x!=89 && x!=149){
            int s=0;
            while(x){
                s+=(x%10)*(x%10);
                x/=10;
            }
            frecv++;
            x=s;
        }
        if(x==1)
            g << cx << ' ' << frecv << '\n';


        //g << x << ' ' << ap << '\n';
    }
    return 0;
}   