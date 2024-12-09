#include <bits/stdc++.h>

/* This one is a collaboration with Bryan Hernandez. */

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

    vector<int> grid(n, 0);
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
        {
            if (s[j] - '0') {
            	grid[i] |= (1 << j);
            }
        }
    }


    vector<int> Match(1 << m, 0);
    for (int mask = 0; mask < (1 << m); ++mask)
    {
    	for (int i = 0; i < m; i++) {
    	  if ((mask & (1 << i))) {
         Match[mask]++;
      	}	
    	}
    }

    int max_strength = 0;


    for (int mask = 0; mask < (1 << m); ++mask)
    {
        int strength = 0;


        for (int i = 0; i < n; ++i)
        {
            if (Match[(mask & grid[i])] > x)
            {
                strength += Match[(mask & grid[i])] - x;
            }
        }


        strength -= y * __builtin_popcount(mask);

        max_strength = max(max_strength, strength);
    }

    cout << max_strength << "\n";
    return 0;
}
