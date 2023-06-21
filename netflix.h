#ifndef NETFLIX_H_INCLUDED
#define NETFLIX_H_INCLUDED
#define MAX_NOME 50
#define MAX_EMAIL 100

typedef struct
{
    char show_id[MAX_NOME];
    char type[MAX_NOME];
    char title[MAX_NOME];
    char director[MAX_NOME];
    char cast[MAX_EMAIL];
    char country[MAX_NOME];
    char date_added[MAX_NOME];
    int release_year;
    char rating[MAX_NOME];
    char duration[MAX_NOME];
    char listed_in[MAX_NOME];
    char description[MAX_EMAIL];
} Registro;

void separarDados(char* linha, Registro* registro);
void salvarDadosEmBinario();
void lerArquivoNetflix();


#endif // NETFLIX_H_INCLUDED
