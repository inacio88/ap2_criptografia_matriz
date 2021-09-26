#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cabecalho.h"


int tamanhoString(char *frase){
    int tamanho = 0;
    while (frase[tamanho] != '\0'){
        tamanho++;
    }

    return tamanho;
}

char sugestaoSenha(char *frase2){
    int tamanho = tamanhoString(frase2);
    int i = 0;
    for (int i = 0; i < tamanho; i++){
            frase2[i] = numero_aleatorio(33, 122);
            system("sleep 01"); 
    }

    return ' ';
}




int numero_aleatorio(int min_num, int max_num){
        int result = 0, low_num = 0, hi_num = 0;

        if (min_num < max_num)
        {
            low_num = min_num;
            hi_num = max_num + 1; // include max_num in output
        } else {
            low_num = max_num + 1; // include max_num in output
            hi_num = min_num;
        }


    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;

}
