#include <stdio.h>
int recursion(int n){
    if(n==1)
    return 1;
    int r= n+recursion(n-1);
    return r;
    

}
void main() {
    int res=recursion(3);
    printf("%d",res);
}