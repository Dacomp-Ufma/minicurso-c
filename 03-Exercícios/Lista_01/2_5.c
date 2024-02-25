#include <stdio.h>

void trianguloPascal(int x);
int calculoBinomial(int n, int k, int fatorial[]);

int main (void) {  
  int x;
  scanf("%d", &x);
  trianguloPascal(x);
  
}



void trianguloPascal(int x){
    int fatorial[x];
    fatorial[0] = 1;
    for(int i = 1; i <= x; i ++){
        fatorial[i] = fatorial[i-1] * i;
    }


    for(int i = 0; i <= x; i ++){
        for(int j = 0; j <= (x - i - 1); j ++){
            printf(" ");
        }
        for(int j = 0; j < i; j++){
            printf("%d ", calculoBinomial(i, j, fatorial));
        }

        printf("\n");
    }
}



int calculoBinomial(int n, int k, int fatorial[]){
    return fatorial[n]/(fatorial[n - k] * fatorial[k]);
}
