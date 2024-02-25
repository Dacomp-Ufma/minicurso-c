#include <stdio.h>

int fatorial(int n);

int main(){

    int n;
    scanf("%d", &n);
    printf("%d", fatorial(n));

}


int fatorial(int n){
    if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    return n * fatorial(n - 1);
}
