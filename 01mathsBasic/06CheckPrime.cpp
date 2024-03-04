#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
	int count=0;
        for (int i = 1; i * i <=n; i++) {
          if (n % i == 0) {
            count+=1;
            if ((n / i)!=i)
			count+=1;
          }
                }
				if(count==2)
				cout<< "true";
				else
				cout<< "false";

}
