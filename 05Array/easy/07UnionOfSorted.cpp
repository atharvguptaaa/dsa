#include <bits/stdc++.h>
using namespace std;
// bruteforce
//  vector<int> findUnion(int arr1[], int arr2[], int n, int m){
//      set<int> st;
//      for(int i=0;i<n;i++){
//          st.insert(arr1[i]);
//      }
//      for(int i=0;i<m;i++){
//          st.insert(arr2[i]);
//      }
//      vector<int> final;
//      for(auto o:st){
//          final.push_back(o);
//      }
//      return final;
//  }

// optimized 2-pointer approach
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    vector<int> unionArr;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != arr1[i])
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != arr2[j])
            {
                unionArr.push_back(arr2[j]);
              }
            j++;
        }
    }
    while (i < n)
    {
        if (unionArr.size() == 0 || unionArr.back() != arr1[i])
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m)
    {
        if (unionArr.size() == 0 || unionArr.back() != arr2[j])
        {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }
    return unionArr;
}


int main()
{
    int arr1[] = {-8, -3, -3, -2, 0, 1, 2, 2, 6};
    int arr2[] = {-9, -9, 0};
    vector<int> ans = findUnion(arr1, arr2, 9, 3);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}






// // first try lol exceeded time lims
//  vector<int> findUnion(int arr1[], int arr2[], int n, int m)
//     {
//         vector<int> temp;
//         for(int i=0;i<n;i++){
//             temp.push_back(arr1[i]);
//         }
//          for(int i=0;i<m;i++){
//             int c=0;
//             for(int j=0;j<n;j++){
//                 if(temp[j]==arr2[i]){
//                     c++;
//                 }
//             }
//             if(c==0){
//                 temp.push_back(arr2[i]);
//             }
//         }

//         sort(temp.begin(),temp.end());
//         auto newEnd = unique(temp.begin(), temp.end()); //unique shifts duplicates to the end returning iterator to new logical end
//         temp.erase(newEnd, temp.end());
//         return temp;
//     }

