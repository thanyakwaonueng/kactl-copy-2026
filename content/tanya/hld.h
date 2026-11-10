/**
 * Author: Tanya
 * Description: simple hld that I copy from cp algorithm
 */
 vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

//this assume 0 base index and root is at 0
void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

//TODO: implement segment tree
//this implementation already handle LCA implicitly
//Query the sum, maximum, minimum, or any other operation that satisfies
//the associative property along the path from node a to node b
//this query function is an example for maximum query

//so make sure to make the correct exclusion in query function below
//if it's query path something on node value then it's fine
//but if it qeury path something value on edge then I normally exclude the right bound
//since I define paths as vertext disjoint paths which excluding first vertext
ll query(int a, int b) { //query sum of edges weight on path version
    ll res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        ll cur_heavy_path = segment_tree_query(pos[head[b]], pos[b]);
        res += cur_heavy_path;
    }

    if (depth[a] > depth[b])
        swap(a, b);
    ll last_heavy_path = segment_tree_query(pos[a]+1, pos[b]);
    res += last_heavy_path;
    return res;
}
