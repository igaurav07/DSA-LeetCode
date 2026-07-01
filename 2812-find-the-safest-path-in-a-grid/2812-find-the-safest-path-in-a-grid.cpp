class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> d(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        int dir[5] = {-1,0,1,0,-1};

        // Multi-source BFS
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]){
                    d[i][j]=0;
                    q.push({i,j});
                }

        while(!q.empty()){
            auto [x,y]=q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dir[k], ny=y+dir[k+1];
                if(nx>=0&&ny>=0&&nx<n&&ny<n&&d[nx][ny]==-1){
                    d[nx][ny]=d[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        auto ok = [&](int val){
            if(d[0][0]<val) return false;
            queue<pair<int,int>> q;
            vector<vector<int>> vis(n, vector<int>(n));
            q.push({0,0});
            vis[0][0]=1;

            while(!q.empty()){
                auto [x,y]=q.front(); q.pop();
                if(x==n-1&&y==n-1) return true;

                for(int k=0;k<4;k++){
                    int nx=x+dir[k], ny=y+dir[k+1];
                    if(nx>=0&&ny>=0&&nx<n&&ny<n&&!vis[nx][ny]&&d[nx][ny]>=val){
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
            return false;
        };

        int l=0,r=2*n;
        while(l<=r){
            int m=(l+r)/2;
            if(ok(m)) l=m+1;
            else r=m-1;
        }
        return r;
    }
};