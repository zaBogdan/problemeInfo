#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct coord{int x,y;} v[100];
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
            rez[l][c]=-3;
            int prim,ultim;
            prim=ultim=1;
            v[prim].x = l;
            v[prim].y = c;
            while(prim<=ultim){
                for(int k=0;k<8;k++){
                    int newx,newy;
                    newx = v[prim].x + dx[k];
                    newy = v[prim].y + dy[k];
                    if(newx>=0 && newy>=0 && newx<n && newy<m)
                        if(!b[newx][newy] && !a[newx][newy]){
                            ultim++;
                            v[ultim].x = newx;
                            v[ultim].y = newy;
                            rez[newx][newy] = -3;
                            b[newx][newy] = 1;
                        }
                    
                }
                prim++;
            }
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(!a[i][j] && b[i][j] && !rez[i][j])
                        rez[i][j] = calcu_bomb(a,i,j);

            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(rez[i][j]==-3)
                        rez[i][j] = 0;
                    else if(rez[i][j]<=0){
                        rez[i][j] = -2;
                    }

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
    danger_zones(a);
    build_result(a,l,c);
    cout << n << ' ' << m << endl;   
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
            for(int k=0;k<8;k++){
                int newx = i+dx[k];
                int newy = j+dy[k];
                if((newx>=0 && newx<n) && (newy>=0 && newy<m))
                    if(a[newx][newy]==-1){
                        b[i][j]=1;
                    }
            }

        }
}