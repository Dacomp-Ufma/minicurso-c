#include <stdio.h>

int func(int x);

int main(){
    int n;
    scanf("%d", &n);

    printf("%d", func(n));

}



int func(int x){

    // Caso base: se o número for zero, a soma dos dígitos é zero
    if(x == 0){
        return 0;
    }

    // Chamada recursiva: soma o último dígito (x % 10) com a soma dos dígitos do restante do número (x / 10)
    return((x % 10) + func(x/10));
}