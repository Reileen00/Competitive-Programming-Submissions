#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve(){
    string s,d;
    cin>>s>>d;
    int sx=int(s[0]-'a');
    int sy=int(s[1]-'1');
    int dx=int(d[0]-'a');
    int dy=int(d[1]-'1');
    vector<pair<int,int>> move={{-2,1},{-2,-1},{-1,2},{-1,-2}
    ,{1,2},{1,-2},{2,1},{2,-1}};
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(8,vector<bool> (8,false));
    q.push({sx,sy});
    vis[sx][sy]=true;
    ll count=0;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            auto [x,y]=q.front();
            q.pop();
            if(x==dx && y==dy){cout<<count<<endl;return;}
            else {
                for(auto [ddx,ddy]:move){
                    int nx=x+ddx;
                    int ny=y+ddy;
                    if(nx>=0&& nx<8 && ny>=0 && ny<8 && !vis[nx][ny]){
                        q.push({nx,ny});
                        vis[nx][ny]=true;
                    }
                }
            }
        }
        count++;
    }
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
} 
