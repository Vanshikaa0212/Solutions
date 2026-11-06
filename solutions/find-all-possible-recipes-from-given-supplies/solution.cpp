class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;

        for(int i = 0; i < recipes.size(); i++) {
            for(int j = 0; j < ingredients[i].size(); j++) {
                string u = ingredients[i][j];
                adj[u].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

         queue<string> q;

        for(auto s : supplies) {
            q.push(s);
        }

        vector<string> ans;

        while(!q.empty()) {
            string u = q.front();
            q.pop();
            // ans.push_back(u);
            for(auto recipes : adj[u]) {
                indegree[recipes]--;
                if(indegree[recipes] == 0) {
                    ans.push_back(recipes);
                    q.push(recipes);
                }
            }
        }

        return ans;
    }
};