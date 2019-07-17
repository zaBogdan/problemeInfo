#include <iostream>
#include <cstring>
using namespace std;
char c[10][10],cuv[20]="";
int n;
bool ok = false;

void afisare(){
    cuv[n+1]='\0';
    cout << cuv << endl;
    ok = true;
}
void ordoneaza(char s[]);
bool valid(int k,int j){
    char litera = c[k][j];
    for(int i=0;i<=k;i++)
        if(cuv[i]==litera)
            return 0;
    return 1;
}

void bkt(int k){
    if(k==n && !ok) afisare();
    else
        for(int i=0;i<strlen(c[k]) && !ok;i++){
            if(valid(k,i)){
                cuv[k]=c[k][i];
                // cout << "I: " << i << " Litera: " << c[k][i] << " Cuvant intreg: " << c[k] << endl; 
                bkt(k+1);
            }
        }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c[i];
        ordoneaza(c[i]);
    }
    bkt(0);
}
void ordoneaza(char s[]){
    int len = strlen(s);
    for(int i=0;i<len;i++)
        for(int j=0;j<=len;j++)
            if(s[i]<s[j])
                swap(s[i],s[j]);
}