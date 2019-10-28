#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("circularlistinsert.in");
ofstream fout("circularlistinsert.out");
int n, m;
struct nod
{
    int info;
    nod * urm;
}*refe,*pc;

void creare(nod *& refe, int n)
{
    nod*p,*q;
    refe=NULL;
    int x;
    for(int i=1; i<=n; i++)
    {
        fin>>x;
        p=new nod;
        p->info=x;
        p->urm=NULL;
        if(refe==NULL)
        {
            refe=p;
            q=p;
            q->urm=refe;
        }
        else
        {
            q->urm=p;
            p->urm=refe;
            q=p;
        }
    }
}

void dublare(nod*&refe,int m)
{
    int x, i, j;
    nod * p;
    for(i=1; i<=m ;i++)
    {
        fin>>x;
        for(j=1;j<=x;j++)
            refe=refe->urm;
        p=new nod;
        p->info=2*refe->info;
        p->urm=refe->urm;
        refe->urm=p;
        refe=p;
    }
}

void afisare(nod*refe)
{
    nod * p=pc->urm;
    fout<<pc->info<<' ';
    while(p != pc)
    {
        fout<<p->info<<' ';
        p=p->urm;
    }
}

int main()
{
    fin>>n;
    creare(refe, n);
    pc=refe;
    fin>>m;
    dublare(refe, m);
    afisare(refe);
    return 0;
}