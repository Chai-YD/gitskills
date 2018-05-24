#include<stdio.h>


char* rotateString(char* A,int n,int p){
    if(A== NULL||n == 0||p ==n-1){
        return A;
    }
    int num = n - p-1;
    while(num-- != 0){
        int i= 0;
        int tmp = A[n-1];
        for(i = n-1;i>0;--i){
            // A+i+1 =A+i;
             A[i] =A[i-1];
            //*(A+i+1) = *(A+i);
        }
        A[0] = tmp;
    }
    return A;
}
int main(){
    char buf[8] = "ABCDEFGH";
        char* A =rotateString(buf,8,5);
        printf("%s\n",A);
    return 0;
}
