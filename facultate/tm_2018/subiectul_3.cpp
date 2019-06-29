#include <iostream>
using namespace std;
const int NMax=50;
int a[NMax][NMax],b[NMax][NMax];;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void matrixB(int a[NMax][NMax], int nivel_mediu_gri);
int nivel_mediu_gri(int h[256]);
void histograma(int h[256]);
void transformB(int i,int j){
    b[i][j]=-1;
    for(int k=0;k<4;k++){
        int newX = i+dx[k];
        int newY = j+dy[k];
        if((newX>=0 && newX<NMax) && (newY>=0 && newY<NMax))
            if(b[newX][newY]==1) transformB(newX,newY);
    }
        
}

int main(){
    int n,c[NMax][NMax];
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>c[i][j];
    transformB(2,4);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout <<c[i][j]<<' ';
        cout << endl;
    }
    return 0;
}

void matrixB(int a[NMax][NMax], int nivel_mediu_gri){
    for(int i=0;i<NMax;i++)
        for(int j=0;j<NMax;j++)
            if(a[i][j]>=nivel_mediu_gri)
                b[i][j]=1;
            else b[i][j]=0;
}


int nivel_mediu_gri(int h[256]){
    int suma=0,ponderi=0;
    for(int i=0;i<=255;i++){
        suma+=i*h[i];
        ponderi+=h[i];
    }
    return suma/ponderi;
}

void histograma(int h[256]){
    for(int i=0;i<=255;i++)
        h[i]=0;

    for(int i=0;i<NMax;i++)
        for(int j=0;j<NMax;j++)
            h[a[i][j]]++;
}

