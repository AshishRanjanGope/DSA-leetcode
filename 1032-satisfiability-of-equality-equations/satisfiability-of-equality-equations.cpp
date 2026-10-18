class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i], parent);
    }
    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equ) {
        vector<int> parent(26);
        vector<int> rank(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (string& s : equ) {
            if (s[1] == '=') {
                Union(s[0] - 'a', s[3] - 'a', parent, rank);
            }
        }

        for (string& s : equ) {
            if (s[1] == '!') {
                int first_parent= find(s[0]-'a',parent);
                int second_parent= find(s[3]-'a',parent);
                if(first_parent==second_parent) return false;
            }
        }
        return true;

    }
};