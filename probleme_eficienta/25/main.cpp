#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.in");
int fr[10];

int UltimaCifra(int a, int b){
    /*
    2 -> 2,4,8,6
    3 -> 3,9,7,1
    4 -> 4,6
    5 -> 5
    6 -> 6
    7 -> 7,9,3,1
    8 -> 8, 4, 2 , 6 
    9 -> 9, 1
    */
   if(b==0)
    return 1;
   int uc=a%10;
//    if(uc==0 || uc == 1 || uc == 5 || uc == 6)
//         return uc;
//     else if(uc==4){
//         if(b%2==0)
//             return 6;
//         return 4;
//     }else if(uc==9){
//         if(b%2==0)
//             return 1;
//         return 9;
//     }else if(uc==2 || uc==3 || uc== 7 || uc == 8){
        int modulo = 1;
        cout << b%5 << ' ';
        if(b%5==0)
            return uc;
        for(int i=0;i<b%5;i++)
            modulo *=uc;
        return modulo%10;
    // }
    // return 0;
}

int main(){
    cout << UltimaCifra(1113,43334);
    cout << endl; //development purpose.
    return 0;
}