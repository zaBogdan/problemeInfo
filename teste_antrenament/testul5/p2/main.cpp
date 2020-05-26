#include <iostream>
using namespace std;

void fara_vector(){
    int n, x,nr=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        if(!x%20)
            nr++;
    }
    cout << nr;
}

int main(){
    //10
    //10 200 25 40 50 80 400 120 100 5
    int n, v[25]={0};
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> v[i];
    int div20=0;
    for(int i=0;i<n;i++)
        if(v[i]%20==0)
            div20++;
    cout << div20;
    cout << endl;   
    return 0;
}