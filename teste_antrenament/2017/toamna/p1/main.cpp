#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("bac.in");
ofstream g("bac.out");

int main(){
    int a,b,c;
    bool afisat=false;
    cin >> a >> b >> c;
    for(int x=a;x<=b;x++)
        for(int y=a;y<=b;y++)
            for(int z=a;z<=b;z++)
                if(x<=y && y<=z)
                    if(x+y+z==c){
                        cout << '{' << x << ',' << y << ','<< z << '}';
                        afisat=true;
                    }
    if(!afisat)
        cout << "nu exista";
    cout << endl;
    return 0;
}