#include <iostream>
#include <fstream>
using namespace std;
ofstream g("arc.out");
const int NMax = 20007;
struct coord{int lenght, start_x, value;} x[NMax];
int c,n,v[NMax],poz,maxim, p_maxim,f[NMax];

void read();
void afisare();
void remove_row(int &poz,int s);
void sum_rows(int &poz);
void culori(){
    int max_lenght = maxim;
    int s=0;
    // afisare();
    while(max_lenght>=3){
        // cout << "REMOVE ROW: " << p_maxim << endl;
        n-=x[p_maxim].lenght;
        remove_row(poz,p_maxim);
        if(x[p_maxim-1].lenght>=3)n-=x[p_maxim-1].lenght, remove_row(poz,p_maxim-1); 
        if(x[p_maxim+1].lenght>=3)n-=x[p_maxim+1].lenght, remove_row(poz,p_maxim+1); 
        p_maxim = 0;
        maxim = 0;
        for(int i=1;i<=poz;i++)
            if(x[i].lenght>maxim){
                maxim = x[i].lenght;
                p_maxim  = i;
            }
        max_lenght = maxim;
        // afisare();
    }
    afisare();
    g << n << endl;
    for(int i=1;i<=poz;i++)
        for(int j=1;j<=x[i].lenght;j++)
            g << x[i].value << endl;
    g.close();
    
}

int main(){
    read();
    if(c==1)
        g << poz;
    else culori();
    return 0;
}

void read(){
    ifstream f("arc.in");
    f >> c >> n;
    for(int i=1;i<=n;i++){
        f >> v[i];
        if(v[i]==v[i-1])
            x[poz].lenght++;
        else{
            if(x[poz].lenght>maxim){
                maxim = x[poz].lenght;
                p_maxim = poz;
            }
            poz++;
            x[poz].lenght = 1;
            x[poz].start_x = i;
            x[poz].value = v[i];
        }
    }

    f.close();
}
void remove_row(int &poz,int s){
    for(int i=s;i<poz;i++)
        x[i] = x[i+1];
    poz--;
    sum_rows(poz);
}
void afisare(){
    for(int i=1;i<=poz;i++)
        cout << "Lenght: " <<x[i].lenght,
        cout << " Start: " << x[i].start_x,
        cout << " Value: "<< x[i].value << endl;
        cout << endl << endl << endl; 
}
void sum_rows(int &poz){
    for(int i=1;i<poz;i++)
        if(x[i].value == x[i+1].value){
            x[i].lenght += x[i+1].lenght;
            remove_row(poz,i+1);
        }
}