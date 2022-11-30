#include <iostream>
using namespace std;

int main()
{
    char vowels[] = {'a', 'i', 'o', 'e', 'u'};

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        string s;
        cin >> s;
        int cons = 0;
        for (int i = 0; i < N; i++)
        {
            if (cons < 4)
            {
                bool isvowel = false;
                for (int j = 0; j < 5; j++)
                {
                    if (s[i] == vowels[j])
                    {
                        isvowel = true;

                        break;
                    }
                    else
                    {
                        isvowel = false;
                    }
                }

                if (isvowel)
                {
                    cons = 0;
                }
                else
                {
                    cons += 1;
                }
            }
            else
            {
                break;
            }
        }

        if(cons< 4){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    // your code goes here
    return 0;
}
