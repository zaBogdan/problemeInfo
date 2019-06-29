#include <iostream>
#include <fstream>
using namespace std;
const int NMax = 103;
ofstream g("munte.out");
int n, v[NMax];

void read(); 
bool is_peak(int x);
void shift_array(int poz){
    for(int i=poz;i<n;i++)
        v[i]=v[i+1];
}
void peaks(int &poz){
    int nr=0,init_peaks;
    bool entered = true,first = true;
    do{
        int cn=n;
        for(int i=2;i<n;i++)
            if(is_peak(i)){
                nr++;
                shift_array(i);
                n--;
        }
        if(first){first=false, init_peaks = nr;}
        if(cn==n) entered = false;
    }while(entered);
    g << init_peaks << endl;
    g << nr << endl;
    g << n;
}

int main(){
    read();
    int poz=0;
    peaks(poz);
    return 0;
}

void read(){
    ifstream f("munte.in");
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i]; 
    f.close();
}
bool is_peak(int x){
    if(v[x-1]<v[x] && v[x]>v[x+1])
        return true;
    return false;
}
