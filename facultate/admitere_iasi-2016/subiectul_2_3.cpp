#include <iostream>
#include <cstring>
using namespace std;

bool onlya(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] != 'a')
            return 0;
    return 1;
}
bool validator(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] != 'a' && s[i] != 'b')
            return 0;
    return 1;
}
void transform(char str[])
{
    int fr[8];
    char r[][7] = {"aab", "aba", "abb", "baa", "bab", "bba", "bbb"};
    char t[][7] = {"aaa", "aab", "aba", "abb", "aba", "baa", "bab"};
    for (int i = 1; i <= 7; i++)
        fr[i] = 0;
    int i;
    bool changed;
    while(!onlya(str)){
        i=0,changed=false;
        while(i<7 && !changed){
            char *p = strstr(str, r[i]);
            if(p){
                int pos;
                pos=p-str;
                strncpy(str+pos,t[i],3);
                fr[i+1]++;
                changed = true;
                // cout << str << ' ' << i+1 << endl;
            }
            else i++;
        }
    }

    for(int i=1;i<=7;i++)
        cout << i << ' ' << fr[i] << endl;

}

int main()
{
    char s[256];
    cin >> s;
    if (!validator(s))
        cout << "Date invalide" << endl;
    else
        transform(s);
    return 0;
}