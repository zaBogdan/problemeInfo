#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int NMax = 55;
const long long NMMAx = 10000000000000000;
long long task,n,a[NMax][NMax],total,maxim,pmax;

void read();
bool valid(long long nr){
    int fr[NMax][NMax];
    memset(fr,0,sizeof(fr));

    //contruiesc o matrice secundara ca sa o umplu
    fr[1][1] = nr;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++){
            fr[i+1][j] += (fr[i][j]-a[i][j]+1)/2; //cantitatea actuala - capacitatea maxima
            fr[i+1][j+1] += (fr[i][j]-a[i][j])/2;
        }

    for(int i=1;i<=n;i++)
        if(fr[n][i]<a[n][i]) //daca ultima linie nu e umpluta mai trebuie sa caut.
            return 0;
    return 1;
}

long long fill_pic(){
    //intervalul este [suma capacitatilor, ULLONG_MAX]
    long long sol = -1,left = total, right = NMMAx;
    while(left<=right){ //cautare binara
        long long mijloc = (left+right)/2;
        if(valid(mijloc)){
            sol = mijloc;
            right = mijloc - 1; //daca am gasit shiftez intervalu spre stanga
        }else left = mijloc + 1; //daca nu spre dreapta. 
    }

    return sol;
}


int main(){
    ofstream g("pic.out");
    read();
    if(task == 1) g << pmax;
    else g << fill_pic() << ' ' << fill_pic()-total;
    g.close();
    return 0;
}

void read(){
    ifstream f("pic.in");
    f >> task;
    f >> n;
    for(int i=1;i<=n;i++){
        int s = 0;
        for(int j=1;j<=i;j++){
            int x;
            f >> x;
            s+=x;
            a[i][j] = x;
        }
        total+=s;
        if(maxim<s){
            maxim = s;
            pmax = i;
        }
    }
    f.close();
}