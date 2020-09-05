#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("file.in");

int main(){
    int n,k;
    char cuvinte[30][30]={NULL},magic[20]="";
    f >> n >> k;
    for(int i=0;i<n;i++){
        f.getline(cuvinte[i], 30);
        if(k==i)
            strcpy(magic,cuvinte[i]);
    }
    for(int i=1;i<n;i++)
        if(i!=k){
            int len=strlen(magic);
            int cuv_len=strlen(cuvinte[i]);
            int vector =0;
            bool right = true;  
            while(vector<len && right){
                if(magic[vector]!=cuvinte[i][cuv_len-vector-1])
                    right=false;
                vector++;
            }
            if(right)
                cout << cuvinte[i] << ' ';
        }
    cout << endl;
}