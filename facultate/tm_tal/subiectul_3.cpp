#include <iostream>
using namespace std;

int is_prezent(int x,int f[]){
    
}

void citeste(int &n,int &k,int f[]){
    cin >> n >> k;
    for(int i=0;i<=k;i++)
        f[i]=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        f[x]++;
    }
}

int main(){
    int f[100], n,k,x;
    //Punctul a.
    citeste(n,k,f);
    
    //Punctul b.
    cin >> x;
    if(f[x]) cout << "prezent";
    else cout << "absent";

    // Punctul c.
    bool ok=false;
    for(int i=0;i<=k && !ok;i++)
        if(f[i]>1){
            cout << "fals";
            ok=true; 
        }
    if(!ok) cout << "adevarat";

    //Punctul d.
    cin >> x;
    for(int i=x+1;i<=k;i++)
        if(f[i])
        cout << i << ' ';

    return 0;
}