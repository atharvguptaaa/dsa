#include <stdio.h>
int recursion(int n){
    if(n==1)
    return 1;
    int r= n+recursion(n-1);
    printf("%d",r);

}
void main() {
    recursion(3);
}