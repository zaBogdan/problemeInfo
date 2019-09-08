#include <iostream>
#include <fstream>
using namespace std;
ofstream g("grupe.out");
const int NMax = 100,NMax2=100003; 
struct coord{int divs,elements, maxim;} v[NMax];
int poz=1,maximA,maximB,pozMaxA,pozMaxB,divis[NMax2];

void read();
int divs(int nr);
void set_array(int nr_div,int nr){
    if(!v[nr_div].elements){
        v[nr_div].elements = 1;
        v[nr_div].maxim = nr;
        v[nr_div].divs = nr_div;
    }else{
        v[nr_div].elements++;
        if(v[nr_div].maxim < nr)
            v[nr_div].maxim = nr;
    }

    if(maximA < v[nr_div].elements){
        // maximB = maximA;
        // pozMaxB = pozMaxA;
        maximA = v[nr_div].elements;
        pozMaxA = nr_div;
    }else if(maximB < v[nr_div].elements){
        maximB = v[nr_div].elements;
        pozMaxB = nr_div;
    }

}


int main(){
    read();
    if(maximA==maximB){
        if(pozMaxA<pozMaxB){
            int aux;
            aux = pozMaxA;
            pozMaxA = pozMaxB;
            pozMaxB = aux;
        }
    }
    g << v[pozMaxA].divs << ' ' << v[pozMaxA].elements << ' ' << v[pozMaxA].maxim << endl;
    g << v[pozMaxB].divs << ' ' << v[pozMaxB].elements << ' ' << v[pozMaxB].maxim;
    g.close();
    return 0;
}

void read(){
    ifstream f("grupe.in");
    int n,m;
    f >> n >> m;
    for(int i=1;i<=n*m;i++){
        int x;
        f >> x;
        int nr_div = divs(x); 
        set_array(nr_div,x);
    }
    f.close();
}
int divs(int nr){
    if(!divis[nr]){
        int divs = 0;
        for(int i=1;i<=nr/2;i++)
            if(nr%i==0)
                divs++;
        divis[nr]=divs+1;
    }
    return divis[nr];
    
}