#include <iostream>
#include <fstream>
using namespace std;
ofstream g("harta.out");
const int NMax = 1503;
struct coord {int x, y;} init[NMax], finish[NMax],banned[NMax];
int n, m, p, k,a[NMax][NMax];

void first_task();
void read();
int calculate_areas(coord init, coord finish);
int calculate_fit(coord ini, coord fini);
void draw_matrix();

int main(){
    read();
    if(p==1)
        first_task();
    else draw_matrix();
    return 0;
}

void read(){
    ifstream f("harta.in");
    f >> p;
    f >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        f >> init[i].x >> init[i].y;
        f >> finish[i].x >> finish[i].y;
    }
    f.close();
}
int calculate_areas(coord init, coord finish){
    int lenght_x = finish.x - init.x + 1; //the height of the form
    int lenght_y = finish.y - init.y + 1; //the width of the form;
    if(lenght_x==lenght_y)
        return lenght_x * lenght_y;
    return 0;
}
int calculate_fit(coord ini, coord fini){
    int maxim_x = fini.x - ini.x + 1;
    int maxim_y = fini.y - ini.y + 1;
    int nr = 0;
    for (int i = 1; i <= k; i++){
        int lenght_x = finish[i].x - init[i].x + 1;
        int lenght_y = finish[i].y - init[i].y + 1;
        if(lenght_x < maxim_x-1 && lenght_y < maxim_y-1)
            nr++;
    }
    return nr;
}
void first_task(){
    //calculate the maximum area.
    int maxim = 0, number;
    for (int i = 1; i <= k; i++)
    {
        int area = calculate_areas(init[i], finish[i]);
        if (maxim < area)
        {
            maxim = area;
            number = calculate_fit(init[i],finish[i]);
        }
    }

    // cout << maxim << ' ' << number << endl;
    g << maxim << ' ' << number << endl;
}
void draw_matrix(){
    for(int cont=1;cont<=k;cont++)
        for(int i=init[cont].x;i<=finish[cont].x;i++)
            for(int j=init[cont].y;j<=finish[cont].y;j++){
                a[init[cont].x][j] = a[finish[cont].x][j] = 1,
                a[i][init[cont].y] = a[i][finish[cont].y] = 1;
                a[i][0]=1;
                a[0][j]=1;
            }
    for(int i=1;i<n;i++)
        if(!a[i][0] && !a[i+1][0])
            a[i][0] = 2;
    for(int j=1;j<m;j++)
        if(!a[0][j] && !a[0][j+1])
            a[0][j] = 2;


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            if(a[0][j]!=2 && a[i][0]!=2)
                g << a[i][j] << ' ';
        if(a[i][0]!=2)
            g << endl;
    }

}