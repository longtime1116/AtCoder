#include <stdio.h>                                                                                                         
#include <string>
#include <iostream>
using namespace std;

int main (void)
{
    string          s, t, atcoder="atcoder@";
    unsigned int    i;
    int             result = 0;

    cin >> s;
    cin >> t;

    
    for ( i = 0; i < s.size(); i++ )
    {
        if ( s[i] == '@' )
        {
            if ( atcoder.find(t[i]) == string::npos )
            {
               result = -1;
               break;
            }
        }
        else if ( atcoder.find(s[i]) != string::npos )
        {
            if ( s[i] != t[i] && t[i] != '@' )
            {
                result = -1;
                break;
            }
        }
        else
        {
            if ( s[i] != t[i] )
            {
                result = -1;
                break;
            }
        }
    }
    if ( result == -1 )
        cout << "You will lose" << endl;
    else
        cout << "You can win" << endl;
    return 0;
}
