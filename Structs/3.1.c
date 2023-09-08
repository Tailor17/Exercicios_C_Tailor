#include <stdio.h>

struct Horario {
    int hora,min,seg;

};

int main(){
    struct Horario hr;

    printf("Digite a Hora\n");
    scanf("%d", &hr.hora);

    printf("Digite os Minutos\n");
    scanf("%d", &hr.min);

    printf("Digite os segundos\n");
    scanf("%d", &hr.seg);

    printf("%.2d:%.2d:%.2d",hr.hora,hr.min,hr.seg);
}
