#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("ms.in");
int n,m,b[100][100],rez[100][100];
int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

void danger_zones(int a[100][100]);
int calcu_bomb(int a[100][100],int i,int j){
        int nr=0;
        for(int k=0;k<8;k++){
            int newx = i+dx[k];
            int newy = j+dy[k];
            if((newx>=0 && newx<n) && (newy>=0 && newy<m))
                if(a[newx][newy]==-1)
                    nr++;
        }
        return nr;
}
void make_safe(int a[100][100],int rez[100][100],int l,int c,int dir){
    
}
void build_result(int a[100][100],int l,int c){
    if(a[l][c]==-1){
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                rez[i][j]=a[i][j];
    }else{
        int nr = calcu_bomb(a,l,c);
        if(nr)
            for(int i=0;i<=n;i++)
                for(int j=0;j<=m;j++){
                    if(i==l && j==c)
                        rez[i][j] = nr;
                    else 
                        rez[i][j] = -2;
                }
        else{
            //caut toate directiile in care e liber si dupa le reparcurg normal.
            //le salvez in vector si updatez mereu de la prima pozitie. 
            
            //cazul general???


            // for(int i=0;i<n;i++)
            //     for(int j=0;j<m;j++)
            //         if(rez[i][j]==-3)
            //             rez[i][j] = 0;
            //         else if(rez[i][j]<=0){
            //             rez[i][j] = -2;
            //         }

        }
    }

}

int main(){
    f >> n >> m;
    int a[100][100];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            f >> a[i][j];
    int l,c;
    f >>l >> c;
    build_result(a,l,c);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << rez[i][j] << ' ';
        cout << endl;

    }
    return 0;
}
void danger_zones(int a[100][100]){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            bool done = false;
            for(int k=0;k<8 && !done;k++){
                int newx = i+dx[k];
                int newy = j+dy[k];
                if((newx>=0 && newx<n) && (newy>=0 && newy<m))
                    if(a[newx][newy]==-1){
                        b[i][j]=1;
                        done=true;
                    }
            }

        }
}