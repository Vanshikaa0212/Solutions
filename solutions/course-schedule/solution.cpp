class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto edge : prerequisites) {
            int course = edge[0];
            int pre = edge[1];

            adj[pre].push_back(course);
        }

        for (int i = 0; i < numCourses; i++) {
            for (int adjNode : adj[i]) {
                indegree[adjNode]++;
            }
        }
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int adjNode : adj[node]) {
                indegree[adjNode]--;

                if (indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        return count == numCourses;
    }
};