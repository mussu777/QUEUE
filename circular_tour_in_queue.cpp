#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        int requiredFuel = 0;
        int extraFuel = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            extraFuel += p[i].petrol - p[i].distance;
            if (extraFuel < 0)
            {
                start = i + 1;
                requiredFuel += extraFuel;
                extraFuel = 0;
            }
        }

        if (extraFuel + requiredFuel >= 0)
        return start;

        return -1;
        
    }
};

int main()
{

    int n;
    cout<<"Enter the size ";
    cin >> n;

    petrolPump p[n];
    cout<<"Enter the petrolpumps and distance ";

    for (int i = 0; i < n; i++)
    cin >> p[i].petrol >> p[i].distance;

    Solution obj;

    cout<<endl;
    cout <<"The solution is " << obj.tour(p, n) << endl;
    cout<<endl;

}