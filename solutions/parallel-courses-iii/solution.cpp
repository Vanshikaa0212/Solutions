class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> InDeg(n, 0);

        for (int i = 0; i < relations.size(); i++) {
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1); // converted into 0 based indexing
            InDeg[relations[i][1]-1]++;

        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (InDeg[i] == 0) {
                q.push(i);
            }
        }

        // Maximum time to complete previous courses
        vector<int> PreviousTime(n, 0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++) {
                int adjNode = adj[node][j];

                PreviousTime[adjNode] = max(PreviousTime[adjNode],PreviousTime[node] + time[node]);

                InDeg[adjNode]--;

                if (InDeg[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        // Maximum time to complete all courses
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, PreviousTime[i] + time[i]);
        }

        return ans;
    }
};