#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    bool afisat=false;
    cin >> a >> b >> c;
    for(int x=a;x<b-1;x++)
        for(int y=x;y<b;y++)
            for(int z=y;z<=b;z++)
                // if(x<=y && y<=z)
                    if(x+y+z==c){
                        c   out << '{' << x << ',' << y << ','<< z << '}';
                        afisat=true;
                    }
    if(!afisat)
        cout << "nu exista";
    cout << endl;
    return 0;
}