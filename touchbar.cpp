
//QUESTION
/*Glide Typing task in Crowdsource app uses a new Google keyboard to type a word by sliding a finger across keys without lifting the finger, as shown in the animation below.

Demostration of Glide Typing on a mobile device.
To make the Glide Typing task more challenging, instead of a normal keyboard, we have a special linear keyboard K that has all the keys in one row.

Imagine that you want to type a word S that is N characters long. The linear keyboard K has M keys. It is guaranteed that the keys cover all characters in S. However, some of the keys may be duplicates. In other words, for each character in S, there is one or more keys in K mapped to the character. Note that, all characters and keys are represented as integers.

You may start with your finger on any key. It takes 1 second to move your finger from a key to an adjacent key. Due to Glide Typing, there is no pressing a key. If the finger is currently at the key i which has character Ki, and we want to type the character Kj at index j, we will glide the finger from the key i to the key j, which takes |j−i| seconds. If your finger is at key x, you can type character Kx any number of times instantly. You need to type string S character by character. Formally, you need to type Si before Si+1 for each 1≤i≤N−1.

For example, suppose the word S has characters: 1, 2, 2, 3, 4. You can start by keeping your finger on key with character 1 on the keyboard which is at index i. Then you glide your finger to key which has character 2 which is at index j. It would take |j−i| seconds. In order to type character 2 two times in string S, you can do that in no additional time as |j−j|=0 seconds. Then you can continue to glide your finger to type the other characters in the word S sequentially.

Can you calculate the minimal time needed to type the word?

Input
The first line of the input gives the number of test cases, T. T test cases follow.

The first line of each test case contains one integer N: the length of the word S.
The second line of each test case contains N integers: each Si is the character at the i-th index.
The third line of each test case contains one integer M: the length of the keyboard K.
The fourth line of each test case contains M integers: each Ki is the character at the i-th key.

Output
For each test case, output one line containing the minimal time needed to type the word. Case #x: y, where x is the test case number (starting from 1) and y is the minimal time needed to type S on the keyboard K.

Limits
Memory limit: 1 GB.
1≤T≤100.
All characters in S appears at least once in K.
1≤Ki≤2500.
1≤Si≤2500.

Test Set 1
Time limit: 20 seconds.
1≤N≤100.
1≤M≤100.
It is guaranteed that there are no duplicated keys in keyboard K.

Test Set 2
Time limit: 20 seconds.
1≤N≤100.
1≤M≤100.
Test Set 3
Time limit: 40 seconds.
1≤N≤2500.
1≤M≤2500.
Sample
Note: there are additional samples that are not run on submissions down below.*/


#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int caseno = 1; caseno <= t; caseno++)
    {

        /*----------------- INPUT ------------------*/
        // Length of the word
        int word_len;
        cin >> word_len;

        // array of characters in the word
        int word_ints[word_len];
        for (int i = 0; i < word_len; i++)
        {
            cin >> word_ints[i];
        }

        // length of keyboard
        int board_len;
        cin >> board_len;

        // array of characters in the keyboard
        int board_ints[board_len];
        for (int i = 0; i < board_len; i++)
        {
            cin >> board_ints[i];
        }
        /*----------------- INPUT ------------------*/

        /*----------------- LOGIC ------------------*/
        int index = -1;
        int time = 0;
        for (int i = 0; i < word_len; i++)
        {
            // character to type
            int c = word_ints[i];

            // if keyboard is not selected
            if (index == -1)
            {
                for (int newkey = 0; newkey < board_len; newkey++)
                {
                    int k = board_ints[newkey];
                    if (c == k)
                    {
                        index = newkey;

                        break;
                    }
                }
            }
            else
            {
                // user goes to right side from current index to find the key

                int rightkeyindex = -1;
                for (int rindex = index; rindex < board_len; rindex++)
                {
                    // assigns key to right side if index is available on right side
                    if (c == board_ints[rindex])
                    {
                        rightkeyindex = rindex;
                        break;
                    }
                }

                // user goes to left side from current index to find the key
                int leftkeyindex = -1;
                for (int lindex = index; lindex >= 0; lindex--)
                {
                    // assigns index to left key if key is available on left side
                    if (c == board_ints[lindex])
                    {
                        leftkeyindex = lindex;
                        break;
                    }
                }

                int oldindex = index;

                // checks which index is closer to current index
                if (abs(leftkeyindex - index) < abs(rightkeyindex - index))
                {
                    // checks if left index is available or not
                    if (leftkeyindex != -1)
                    {
                        index = leftkeyindex;
                    }
                    else
                    {
                        index = rightkeyindex;
                    }
                }
                else
                {
                    // checks if right index is available or not
                    if (rightkeyindex != -1)
                    {
                        index = rightkeyindex;
                    }
                    else
                    {
                        index = leftkeyindex;
                    }
                }

                time += abs(index - oldindex);
            }
        }
        /*----------------- LOGIC ------------------*/

        /*----------------- OUTPUT ------------------*/

        cout << "Case #" << caseno << ": " << time << "\n";

        /*----------------- OUTPUT ------------------*/
    }

    return 0;
}
