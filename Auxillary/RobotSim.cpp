//https://leetcode.com/problems/walking-robot-simulation/description/
#include<bits/stdc++.h>
using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;
        for(int i=0;i<obstacles.size();i++){
            st.insert({obstacles[i][0],obstacles[i][1]});
        }
        vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};//NESW
        int d=0;//iterator of dir
        int x=0,y=0;
        int result;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1) d=(d+1)%4;
            else if(commands[i]==-2) d=(d+3)%4;
            else{
                for(int j=0; j<commands[i];j++){
                    int dx=dir[d].first, dy=dir[d].second;
                    if(st.find({x+dx,y+dy})!=st.end()) break;
                    x+=dx;
                    y+=dy;
                }
            }
            result=max(result,x*x+y*y);

        }

        return result;
    }

int main()
{
 vector<int> commands={4,-1,4,-2,4};
 vector<vector<int>> obstacles={{2,4}};
 cout<<robotSim(commands,obstacles);
 return 0;
}