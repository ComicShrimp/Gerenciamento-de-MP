#include <stdio.h>
#include <stdlib.h>

#define MEM 50

void print_mem(int *mem);

int main(void){

    int memoria[MEM];

    int i;
    for(i = 0;i < MEM;i++){

        if(i < 5){
            memoria[i] = 1;
        }else if(i < 8){
            memoria[i] = 2;
        }else if((17 < i) && (i < 24)){
            memoria[i] = 3;
        }else{
            memoria[i] = 0;
        }

    }

    print_mem(memoria);

    int saida = 0;
    int tipo = 0;
    int id = 0;
    int tam = 0;

    do{
        printf("Qual a operacao (1 - Alocar; 2 - tirar; 3 - exibir; 4 - sair): ");
        scanf("%d", &saida);

        if(saida == 1){
            printf("Qual o tipo de alocacao (1 - Best; 2 - Worst; 3 - First): ");
            scanf("%d", &tipo);
        }

        if(saida != 4){
            printf("Qual o id: ");
            scanf("%d", &id);

            printf("Qual o tamanho: ");
            scanf("%d", &tam);
        }

        switch (saida) {
            case 1:{
                if(tipo == 1){

                    int tot_menor = MEM;
                    int id_menor = MEM;

                    int i,aux,total;
                    aux = total = 0;
                    for(i = 0;i < MEM;i++){

                        if(i == 0){
                            aux = memoria[i];
                        }

                        if((aux != memoria[i]) || (i == MEM - 1)){
                            total = (i == MEM - 1) ? (total + 1) : (total);
                            if((total < tot_menor) && (total >= tam) && (aux == 0)){
                                tot_menor = total;
                                id_menor = i - tot_menor;
                            }
                            if((i == MEM - 1) && (id_menor < MEM)){
                                int j;
                                int per = id_menor;
                                for(j = per;j < per + tam;j++){
                                    memoria[j] = id;
                                }
                                break;
                            }
                            total = 0;
                            aux = memoria[i];
                        }

                        total++;

                    }

                }else if(tipo == 2){

                    int tot_maior = 0   ;
                    int id_maior = MEM;

                    int i,aux,total;
                    aux = total = 0;
                    for(i = 0;i < MEM;i++){

                        if(i == 0){
                            aux = memoria[i];
                        }

                        if((aux != memoria[i]) || (i == MEM - 1)){
                            total = (i == MEM - 1) ? (total) : (total);
                            if((total > tot_maior) && (total >= tam) && (aux == 0)){
                                tot_maior = total;
                                id_maior = i - tot_maior;
                            }
                            if((i == MEM - 1) && (tot_maior > 0)){
                                int j;
                                int per = id_maior;
                                for(j = per;j < per + tam;j++){
                                    memoria[j] = id;
                                }
                                break;
                            }
                            total = 0;
                            aux = memoria[i];
                        }

                        total++;

                    }

                }else if(tipo == 3){

                    int i,aux,total;
                    aux = total = 0;
                    for(i = 0;i < MEM;i++){

                        if(i == 0){
                            aux = memoria[i];
                        }

                        if((aux != memoria[i]) || (i == MEM - 1)){
                            total = (i == MEM -1) ? (total + 1) : (total);
                            if((total >= tam) && (aux == 0)){
                                int j;
                                int per = i - total;
                                for(j = per;j < per + tam;j++){
                                    memoria[j] = id;
                                }
                                break;
                            }
                            total = 0;
                            aux = memoria[i];
                        }

                        total++;

                    }

                }else{
                    printf("Comando nao encontrado\n");
                }

                print_mem(memoria);

                break;
            }

            case 2:{

                int i,aux,total;
                aux = total = 0;
                for(i = 0;i < MEM;i++){

                    if(i == 0){
                        aux = memoria[i];
                    }

                    if((aux != memoria[i]) || (i == MEM - 1)){
                        total = (i == MEM -1) ? (total + 1) : (total);
                        if(aux == id){
                            int j;
                            int per = i - total;
                            for(j = per;j < i;j++){
                                memoria[j] = 0;
                            }
                            break;
                        }
                        total = 0;
                        aux = memoria[i];
                    }

                    total++;

                }

            }

            case 3:{
                print_mem(memoria);
            }

            case 4:{
                break;
            }

            default:{
                printf("Comando nao encontrado\n");
            }
        }

    }while(saida != 4);

    return 0;
}

void print_mem(int *mem){

    printf("\n");

    int i,aux,total;
    aux = total = 0;
    for(i = 0;i < MEM;i++){

        if(i == 0){
            aux = mem[i];
        }

        if((aux != mem[i]) || (i == MEM - 1)){
            total = (i == MEM -1) ? (total + 1) : (total);
            printf("%d - %d\n",aux, total);
            total = 0;
            aux = mem[i];
        }

        total++;

    }

    printf("\n");

}
