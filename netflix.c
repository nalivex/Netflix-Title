#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"

void separarDados(char* linha, Registro* registro) {
    char* campo;
    int indice = 0;
    char* delimitador = ",";
    char* inicio_aspas = NULL;

    campo = strtok(linha, delimitador);
    while (campo != NULL && indice < 12) {
        if (campo[0] == '\"') {
            inicio_aspas = campo + 1;
            campo = strtok(NULL, "\"");
            strncpy(registro->cast, inicio_aspas, MAX_EMAIL - 1);
        } else {
            switch (indice) {
                case 0:
                    strncpy(registro->show_id, campo, MAX_NOME - 1);
                    break;
                case 1:
                    strncpy(registro->type, campo, MAX_NOME - 1);
                    break;
                case 2:
                    strncpy(registro->title, campo, MAX_NOME - 1);
                    break;
                case 3:
                    strncpy(registro->director, campo, MAX_NOME - 1);
                    break;
                case 4:
                    strncpy(registro->cast, campo, MAX_EMAIL - 1);
                    break;
                case 5:
                    strncpy(registro->country, campo, MAX_NOME - 1);
                    break;
                case 6:
                    strncpy(registro->date_added, campo, MAX_NOME - 1);
                    break;
                case 7:
                    registro->release_year = atoi(campo);
                    break;
                case 8:
                    strncpy(registro->rating, campo, MAX_NOME - 1);
                    break;
                case 9:
                    strncpy(registro->duration, campo, MAX_NOME - 1);
                    break;
                case 10:
                    strncpy(registro->listed_in, campo, MAX_NOME - 1);
                    break;
                case 11:
                    strncpy(registro->description, campo, MAX_EMAIL - 1);
                    break;
            }
        }

        campo = strtok(NULL, delimitador);
        indice++;
    }
}

void salvarDadosEmBinario(FILE* arquivoCSV) {
    FILE* arquivo_netflix = fopen("netflix_titles.bin", "wb+");
    if (arquivo_netflix == NULL) {
        printf("[ERROR] O programa nao conseguiu abrir o arquivo.\n");
        exit(1);
    }

    char linha[500];
    fgets(linha, sizeof(linha), arquivoCSV); // Descarta a primeira linha (cabeçalho)

    Registro registro;
    while (fgets(linha, sizeof(linha), arquivoCSV) != NULL) {
        separarDados(linha, &registro);
        fwrite(&registro, sizeof(Registro), 1, arquivo_netflix);
    }

    fclose(arquivo_netflix);
}

void lerArquivoNetflix() {
    FILE* arquivoCSV = fopen("netflix_titles.csv", "rb+");
    if (arquivoCSV == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    salvarDadosEmBinario(arquivoCSV);

    fclose(arquivoCSV);
}
