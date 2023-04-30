#include <iostream>
#include <vector>

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> size;

public:
    // Initialize the DSU with n elements
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find the leader of the set containing element x
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Merge the sets containing elements x and y
    void union_sets(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y) {
            // Union by size
            if (size[root_x] < size[root_y]) {
                std::swap(root_x, root_y);
            }
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
        }
    }
};#include <iostream>
#include <vector>

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> size;

public:
    // Initialize the DSU with n elements
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find the leader of the set containing element x
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Merge the sets containing elements x and y
    void union_sets(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y) {
            // Union by size
            if (size[root_x] < size[root_y]) {
                std::swap(root_x, root_y);
            }
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
        }
    }
};
