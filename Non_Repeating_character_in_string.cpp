#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        unordered_map<char, int> count;
        string ans = "";
        queue<char> q;

        for (int i = 0; i < A.length(); i++)
        {
            char ch = A[i];

            // increase coutn
            count[ch]++;

            // queue me push karo
            q.push(ch);

            while (!q.empty())
            {
                if (count[q.front()] > 1)
                {
                    // for repeating character
                    q.pop();
                }
                else
                {
                    // for non- repeating character
                    ans.push_back(q.front());
                    break;
                }
            }
             
            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};

int main()
{
    // int tc;
    // cin >> tc;
    // while (tc--)
    // {
        string A = "aabbc";
        // cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    // }
    return 0;
}