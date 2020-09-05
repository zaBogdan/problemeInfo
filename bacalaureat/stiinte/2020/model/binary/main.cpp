#include <iostream>
#include <fstream> 
using namespace std;
ifstream f("file.in");

int main(){
    int v[100]={0},x,y,n;
    f >> n;
    for(int i=1;i<=n;i++)
        f >> v[i];
    f >> x >> y;
    int left=1,right=n,mij;
    bool found=false;
    while(left<=right && !found){
        mij = (right+left)/2;
        if(v[mij]>=x && v[mij]<=y) found=true;
        else if(v[mij]<x) right = mij+1;
        else if(v[mij]>y) left = mij+1;
    }
    while(v[mij-1] >=x && v[mij-1]<=y && mij>1)
        mij--;
    cout << v[mij];
    cout << endl;
    return 0;
}