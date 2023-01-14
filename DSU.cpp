#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"
#define mod 1'000'000'007
#define cin(vec) for (auto &i : vec) cin >> i
#define cout(vec) for (auto &i : vec) cout << i << " ";cout << '\n';


template<typename T>
struct DSU{
    vector<T> parent, sz;
    int numComponents;
    DSU(int size)
    {
        parent = vector<T>(size+1);
        sz = vector<T>(size+1);
        for(int i=0; i<size; i++)
        {
            parent[i] = i;
            sz[i] = i;
        }
        numComponents = size;
    }

    T find(T p)
    {
        T root = p;
        while(root != parent[root])
            root = parent[root];
        
        // Path Compression
        while(p != root)
        {
            int next = parent[p];
            parent[p] = root;
            p = next;
        }
        return root;
    }

    bool connected(T u, T v)
    {
        return find(u) == find(v);
    }

    void unify(T u, T v)
    {
        T root1 = find(u);
        T root2 = find(v);
        if(root1 == root2) return;

        if(sz[root1] < sz[root2])
        {
            parent[root1] = root2;
            sz[root1] += sz[root2];
        }
        else
        {
            parent[root2] = root1;
            sz[root2] += sz[root1];
        }
        numComponents--;
    }

    int get_size(int u)
    {
        return sz[find(u)];
    }
};

void solve()
{       
    
}

int main()
{
    int t = 1;
    // cin >> t;  
    while(t--)
        solve();
    return 0;
}