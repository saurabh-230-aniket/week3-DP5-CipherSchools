string findOrder(string dict[], int n, int K) {
        //code here
        //topological sort
        vector<int> adj[K];
        vector<int> indegree(26 , 0);
        for(int i = 0 ; i < n - 1 ; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int j = 0 , k = 0;
            while(j<s1.size() && k < s2.size()){
                if(s1[j] != s2[k]){
                    adj[s1[j] - 'a'].push_back(s2[k] - 'a');
                    indegree[s2[k] - 'a']++;
                    break;
                }
                j++;
                k++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i < K ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto u : adj[x]){
                indegree[u]--;
                if(indegree[u] == 0){
                    q.push(u);
                }
            }
            char ch = x + 'a';
            ans += ch;
        }
        return ans;
    }