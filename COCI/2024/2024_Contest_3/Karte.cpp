#include <bits/stdc++.h>

/* This one is a collaboration between Bryan Hernandez and me. 
** I wrote the solution and he wrote the computer program. */

using namespace std;

void optimize()
{
    cin.tie(0)->sync_with_stdio(0);
}

int main()
{
    optimize();

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
        {
            grid[i][j] = s[j] - '0';
        }
    }


    vector<vector<int>> Match(n, vector<int>(1 << m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int mask = 0; mask < (1 << m); ++mask)
    {
            for (int j = 0; j < m; ++j)
            {
                if (mask & (1 << j))
                {
                    Match[i][mask] += grid[i][j];
                }
            }
        }
    }

    int max_strength = 0;


    for (int mask = 0; mask < (1 << m); ++mask)
    {
        int strength = 0;


        for (int i = 0; i < n; ++i)
        {
            if (Match[i][mask] > x)
            {
                strength += Match[i][mask] - x;
            }
        }


        strength -= y * __builtin_popcount(mask);

        max_strength = max(max_strength, strength);
    }

    cout << max_strength << "\n";
    return 0;
}
