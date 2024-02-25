#include <stdio.h>

int somatorioFatorial(int n);
int fatorial(int n);

int main(){
     
    int n;
    scanf("%d", &n);
    
    printf("%d", somatorioFatorial(n));
}

int somatorioFatorial(int n){
    if (n == 0){
        return 0;
    }
    return fatorial(n) + somatorioFatorial(n - 1);
        
}

int fatorial(int n){
    if (n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    return n * fatorial(n - 1);
}