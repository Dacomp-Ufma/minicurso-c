#include <stdio.h>

int ehPalindromo(char a[], int n, int inicio);

int main (void) {  
    char a[] = "banana";
    char b[] = "civic";
    
    printf("%d", ehPalindromo(a, sizeof(a)-1, 0));
    printf("%d", ehPalindromo(b, sizeof(b)-1, 0));

}


int ehPalindromo(char a[], int n, int inicio){

    if (a[inicio] != a[n-1]){
        return 0;
    }
    else{
        if(inicio == n){
            return 1;
        }
        else if(inicio == n - 1){
            return 1;
        }
        return ehPalindromo(a, n - 1, inicio + 1);
    }
    
}


