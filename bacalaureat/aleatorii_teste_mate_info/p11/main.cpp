#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("soft_prime.in");
ofstream g("soft_prime.out");
struct primalitate{int numar; bool is_prime;};

bool is_prime(int nr){
    if(nr == 0 || nr == 1)
        return false;
    if(nr == 2 || nr%2==0)
        return false;
    for(int i=3;i*i<=nr;i++)
        if(nr%i==0)
            return false;
    return true;
}

int main(){
    vector<bool> v;
    v.resize(75000);
    // int v[40000]={0};
    // bool v1[40000];
    // const int high = 1000000;
    // int n, x, max = -high;
    // f >> n;
    // int v[40000]={0};
    // for(int i=1;i<=n;i++){
    //     f >> x;
    //     max = max<x ? x : max;
    //     if(is_prime(x))
    //         v[x]=true;
    // }
    // for(int i=2;i<=max;i++)
    //     if(v[i])
    //         g << i << ' ';
    cout << (v.max_size());//1048576.0;
    cout << endl;
    return 0;
}