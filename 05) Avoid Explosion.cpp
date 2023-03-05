class Solution {
  public:
    vector<string> avoidExplosion(vector<vector<int>> v, int n, vector<vector<int>> a, int m) {
        
        std:: vector<int> p, deg;
        auto Dsu = [&](int n) {
        	p.resize(n + 1);
        	iota(p.begin(), p.end(), 0);
        	deg.assign(n + 1, 0);
        };
        function<int(int)> findpar = [&](int node) {
        	if (p[node] == node) {
        		return node;
        	}
        	return p[node] = findpar(p[node]);
        };
        auto Uni = [&](int u, int v) {
        	u = findpar(u);
        	v = findpar(v);
        	if (deg[u] < deg[v]) p[u] = v;
        	else if (deg[v] < deg[u]) p[v] = u;
        	else {
        		p[v] = u;
        		deg[u]++;
        	}
        };
        Dsu(n + 1);
        
        vector<string> ans(n,"Yes");
        int i = 0;
        for(auto &x : v){
            int p1 = findpar(x[0]), p2 = findpar(x[1]);
            if(p1 > p2) swap(p1, p2);
            bool z = 0;
            for(auto &y : a){
                int pp1 = findpar(y[0]), pp2 = findpar(y[1]);
                if(pp1 > pp2) swap(pp1, pp2);
                if(pp1 == p1 and pp2 == p2) z = 1;
            }
            if(z) ans[i] = "No";
            else Uni(x[0], x[1]);
            i++;
        }
        return ans;
    }
};
