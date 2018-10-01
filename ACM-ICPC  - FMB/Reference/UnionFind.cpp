#include <bits\stdc++.h>

    using namespace std;

//Indexado en 1.
class UnionFind{

public:
    int Size;
    int* id;
    int* wh;

    UnionFind(void)
    {
        Size = 0;
        id = (int*)malloc((1)*sizeof(int));
        wh = (int*)malloc((1)*sizeof(int));
        id[0] = 0;
        wh[0] = 1;
    }

    UnionFind(int n)
    {
        Size = n;
        id = (int*)malloc((n+1)*sizeof(int));
        wh = (int*)malloc((n+1)*sizeof(int));
        for(int i=0; i<=n; i++)
        {
            id[i] = i;
            wh[i] = 1;
        }
    }

    int Root(int x)
    {
        if(x == 0 || x > Size+1)
            return -1;
        if(x == id[x])
            return x;
        return id[x] = Root(id[x]);
    }

    bool Find(int x, int y)
    {
        return Root(x) == Root(y);
    }

    bool Union(int x, int y)
    {
        if(!Find(x, y))
        {
            x = Root(x);
            y = Root(y);
            if(wh[x] > wh[y])
            {
                id[y] = x;
                wh[x] += wh[y];
            }
            else
            {
                id[x] = id[y];
                wh[y] += wh[x];
            }
        }
    }

};

int main()
{

    return 0;
}

