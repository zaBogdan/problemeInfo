#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct coord{char name[100]; int values[1005],max;} v[105];
int n,task,poz;

void read();
void decode_value(char line[255],char c[100],int &val);
void place_values(char c[100],int val){
    bool gasit = false;
    for(int i=1;i<=poz && !gasit;i++)
        if(strcmp(v[i].name,c)==0){
            v[i].values[val]++;
            gasit = true;
            v[i].max = v[i].max<val ? val : v[i].max;
        }
    
    if(!gasit){
        poz++;
        strcpy(v[poz].name,c);
        v[poz].values[val]++;
        v[poz].max = v[poz].max<val ? val : v[poz].max;
    }
}

int main(){
    read();
    ofstream g("timbre.out");
    if(task == 1) g << poz; 
    else if(task == 2){
        int nr = 0;
        for(int i=1;i<=poz;i++)
            for(int j=1;j<=v[i].max;j++)
                if(v[i].values[j]==1){
                    nr++;
                }
        g << nr;
    }else{
        int sume[poz],maxim=0;
        memset(sume,0,sizeof(sume)+5);
        for(int i=1;i<=poz;i++){
            for(int j=1;j<=v[i].max;j++)
                if(v[i].values[j])
                    sume[i]+=j;
            maxim = maxim<sume[i] ? sume[i] : maxim;
        }
        char values[105][255];
        int place = 0;
        for(int i=1;i<=poz;i++)
            if(sume[i]==maxim){
                strcpy(values[++place],v[i].name);
            }
        bool sortat = true;
        do{
            sortat = true;
            for(int i=1;i<place;i++)
                if(strcmp(values[i],values[i+1])>0){
                    sortat= false;
                    swap(values[i],values[i+1]);
                }
        }while(!sortat);
        for(int i=1;i<=place;i++)
            g << values[i] << endl;
    }
    g.close();
    
    return 0;
}

void read(){
    ifstream f("timbre.in");
    f >> task >> n;
    char line[255];
    f.getline(line,255);
    for(int i=1;i<=n;i++){
        int val;
        char c[100];
        f.getline(line,255);
        decode_value(line,c,val);
        place_values(c,val);
    }
    f.close();
}
void decode_value(char line[255],char c[100],int &val){
    int i = strlen(line)-1;
    int nd = 0,p=1;
    while(line[i]!=' '){
        nd = nd + p*(line[i]-'0');
        p*=10;
        i--;
    }
    strncpy(c, line, i);
    c[i] = '\0';
    val = nd;
}
