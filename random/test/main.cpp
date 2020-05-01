#include <cctype>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    char s[256],voc[]="aeiou";
    cin.getline(s,256);
    int i=strlen(s)-1;
    while(i>=0)
    {
        if(isalpha(s[i]))
            if(strchr(voc,s[i]))
            {
                strcpy(s+i,s+i+1);
                cout<<s;
                i=0;
            }
        i--;
    }
        return 0;
    }