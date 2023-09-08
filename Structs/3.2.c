#include <stdio.h>

struct Data{
    int dia,mes,ano;
};

struct Aluno{
    int nMatri;
    struct Data dtNasc;
};

int main(){
    struct Data dataHj;
    struct Aluno al;
    int data;

    printf("Digite o dia de hoje: ");
    scanf("%d", &dataHj.dia);

    printf("\nDigite o mes atual: ");
    scanf("%d", &dataHj.mes);

    printf("\nDigite o ano atual: ");
    scanf("%d", &dataHj.ano);

    printf("\nData atual: %.2d/%.2d/%d",dataHj.dia,dataHj.mes,dataHj.ano);

    printf("\nDigite a Matricula do aluno: ");
    scanf("%d", &al.nMatri);

    while(al.nMatri>=0){


        printf("\nDigite o dia de nascimento: ");
        scanf("%d", &al.dtNasc.dia);

        printf("\nDigite o mes de nascimento: ");
        scanf("%d", &al.dtNasc.mes);

        printf("\nDigite o ano de nascimento: ");
        scanf("%d", &al.dtNasc.ano);

        data = dataHj.ano - al.dtNasc.ano;

        if(data >= 18){
            printf("\nO aluno e maior de idade\n");
        }
        if(data == 17){
            if(dataHj.mes <= al.dtNasc.mes && dataHj.dia <= al.dtNasc.dia ){
                printf("O aluno e menor de idade\n");
            }
            else{
                printf("O aluno e menor de idade\n");
            }
          }
        if(data < 17){
            printf("O aluno e menor de idade\n");
        }
        printf("\nDigite a Matricula do aluno: ");
        scanf("%d", &al.nMatri);

    }

}
