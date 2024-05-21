#include<bits/stdc++.h>
using namespace std;

void usePairs(){
 pair p={2,4};
 cout<<p.second<<"\n";
 pair<int, string> abc={1,"a"};
 cout<<abc.second;
}

void useVectors(){
vector abc={1,2,3};
cout<<abc[2]<<"\n";
vector v(5,100);
v.push_back(1);
cout<<v[5]<<"\n";
v.emplace_back(2);//faster
cout<<v[6]<<"\n";

}

void vectorIterator(){
    vector<int> v={1,2,3,4,5};

    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
    cout<<*(it)<<" ";
    }
    for(auto it=v.begin();it!=v.end();it++){
    cout<<*(it)<<" ";
    }
    for(auto i:v){
    cout<<i<<" ";
    }
}

void moreVectorFunc(){
    vector<int> v={1,2,3,4,5};
            for(auto i:v){
            cout<<i<<" ";
            }

            cout<<"\n";
    v.erase(v.begin()+1,v.begin()+3);

            for(auto i:v){
            cout<<i<<" ";
            }
            cout<<"\n";
    v.insert(v.begin()+1,2,7);
            for(auto i:v){
            cout<<i<<" ";
            }

            cout<<"\n";
    cout<<v.size();
            cout<<"\n";

    v.pop_back();
            for(auto i:v){
            cout<<i<<" ";
            }
            cout<<"\n";
    //v1.swap(v2)

    v.clear();
            for(auto i:v){
            cout<<i<<" ";
            }



        //map

int arr[5]={1,2,2,3,1};
map<int,int> mpp;
for (int i = 0; i < sizeof(arr); i++)
{
    mpp[arr[i]]++;
}
        //iteration
for(auto it: mpp){
    cout<<it.first<<"->"<<it.second<<endl;
}



}


int main()
{

 //usePairs();
 //useVectors();
 //vectorIterator();
 moreVectorFunc();
}