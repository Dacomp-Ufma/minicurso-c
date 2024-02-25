#include <stdio.h>
#include <math.h>

/*
Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no plano,
p1(x1, y1) e p2(x2, y2) e calcule a distância entre eles, mostrando 4 casas decimais após
a vírgula, segundo a fórmula:

Distancia = raiz( (x2 - x1)² + (y2 - y1)² )
*/

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
