#include <stdio.h>
#include <math.h>



int main()
{
    float x1, y1, x2, y2, distancia;
    printf("Digite as coordenadas de p1 (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Digite as coordenadas de p2 (x2 y2): ");
    scanf("%f %f", &x2, &y2);
    distancia = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    printf("Distancia = %.4f\n", distancia);
    return 0;
}
