#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    vector<int> weight(n + 1), profit(n + 1);

    cout << "Enter weights of items:\n";
    for (int i = 1; i <= n; i++)
        cin >> weight[i];
    cout << "Enter profits of items:\n";
    for (int i = 1; i <= n; i++)
        cin >> profit[i];

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    vector<vector<int>> keep(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weight[i] <= w)
            {
                if (profit[i] + dp[i - 1][w - weight[i]] > dp[i - 1][w])
                {
                    dp[i][w] = profit[i] + dp[i - 1][w - weight[i]];
                    keep[i][w] = 1;
                }
                else
                {
                    dp[i][w] = dp[i - 1][w];
                }
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nProfit DP Table:\n";
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << setw(4) << dp[i][w];
        }
        cout << endl;
    }

    cout << "\nBinary Table:\n";
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << setw(4) << keep[i][w];
        }
        cout << endl;
    }

    cout << "\nMaximum Profit: " << dp[n][W] << endl;

    int w = W;
    vector<int> selected;
    for (int i = n; i > 0; i--)
    {
        if (keep[i][w] == 1)
        {
            selected.push_back(i);
            w -= weight[i];
        }
    }

    cout << "Selected items: ";
    reverse(selected.begin(), selected.end());
    for (int item : selected)
        cout << item << " ";
    cout << endl;

    return 0;
}
