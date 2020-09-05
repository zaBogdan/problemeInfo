#include <iostream>
#include <fstream>
using namespace std;
ofstream g("bac.out");

int main(){
    int p1,p2;
    cin >> p1 >> p2;
    for(int i=1;i<=9;i++){
        if(p1%i==0 && p1/i<10 && p1/(p1/i)<10){
            int first = p1/i;
            int second = p1/first;
            for(int j=9;j>=0;j--)
                for(int k=1;k<=9;k++){
                    if(p2%k==0 && p2/k<10 && p2/(p2/k)<10){
                        int third = p2/k;
                        int fourth = p2/third;
                        g << first << second << j << j << j << third << fourth << '\n';
                    }
                }
        }
    }
    return 0;
}