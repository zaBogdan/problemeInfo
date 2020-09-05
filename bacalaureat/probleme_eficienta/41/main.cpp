#include <iostream>
#include <fstream>
using namespace std;
ifstream f("permut.txt");
int fr[100];

int main(){
    int x,n,var, line=1;
    bool found = false;
    cin >> var;
    while(f>>x && !found){
        if(x==var){
            cout << "Apare pe linia " << line;
            found=true;
        }
        line++;
    }
    if(!found) cout << "NU apare";
    cout << endl; //development purpose.
    return 0;
} 