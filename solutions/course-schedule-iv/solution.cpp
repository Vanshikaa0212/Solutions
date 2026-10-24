class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> InDeg(n, 0);
        vector<vector<bool>> pre(n, vector<bool>(n, false));

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            InDeg[prerequisites[i][1]]++;
            pre[prerequisites[i][0]][prerequisites[i][1]] = true;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (InDeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int adjNode : adj[node]) {
                for (int j = 0; j < n; j++) {
                    if (pre[j][node]) {
                        pre[j][adjNode] = true;
                    }
                }

                InDeg[adjNode]--;

                if (InDeg[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
    

    vector<bool> ans;

    for (int i = 0; i < queries.size(); i++) {
        int u = queries[i][0];
        int v = queries[i][1];

        ans.push_back(pre[u][v]);
    }

    return ans;
    }
};
