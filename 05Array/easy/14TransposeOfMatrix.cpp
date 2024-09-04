#include<bits/stdc++.h>
using namespace std;

  vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>> tP(c,vector<int>(r));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                tP[j][i]=matrix[i][j];
            }
        }
    return tP;
    }

int main()
{
 vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
 vector<vector<int>> tP=transpose(matrix);
  for(int i=0;i<tP.size();i++){
            for(int j=0;j<tP[i].size();j++){
                cout<<tP[i][j]<<" ";
            }
            cout<<endl;
        }
 return 0;
}