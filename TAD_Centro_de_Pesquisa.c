#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TAD_Centro_de_Pesquisa.h"

Centro_de_Pesquisa *inicializa_centro(Treinador *t1, Treinador *t2) // A função recebe dois ponteiros para treinadores e, retorna um ponteiro para um Centro de Pesquisa.
{
    Centro_de_Pesquisa *centro = (Centro_de_Pesquisa *)malloc(sizeof(Centro_de_Pesquisa)); // Aloca dinamicamente um espaço na memória para armazenar um Centro de Pesquisa.

    if (centro != NULL) // Verifica se a alocação funcionou.
    {

        inicializa_lista(&(centro->fugitivos));   // Inicializa a lista dos Pokemons fugitivos.
        inicializa_lista(&(centro->recuperados)); // Inicializa a lista dos Pokemons recuperados.
        inicializa_coordenadas(&(centro->lugar)); // Inicializa as coordenadas do Centro de pesquisa, que são: (0,0)
        inicializa_treinador(t1);                 // Inicializa as variáveis dos treinadores.
        inicializa_treinador(t2);

        FILE *arquivo;
        arquivo = fopen("teste1.txt", "r");

        if (arquivo != NULL) // Se o arquivo foi aberto corretamente.
        {

            char palavra[50]; // Variáveis auxiliares usadas para ajudar na leitura das informações dos treinadores.
            int quantidade = 0;

            fscanf(arquivo, "%49s %d", palavra, &quantidade); // Lê as informações presentes no arquivo acerca do primeiro treinador.
            insere_Tdados(t1, quantidade, palavra, 1);        // Repassa os dados para o treinador.

            printf("%s %d\n", palavra, quantidade);

            fscanf(arquivo, "%49s %d", palavra, &quantidade); // Lê as informações presentes no arquivo acerca do segundo treinador.
            insere_Tdados(t2, quantidade, palavra, 2);        // Repassa os dados para o treinador.

            printf("%s %d\n", palavra, quantidade);

            fclose(arquivo);

            return centro; // Retorna o endereço de memória onde as informações do centro estão armazenadas.
        }

        else // Caso a leitura do arquivo falhe.
        {
            printf("Erro na leitura das informações dos treinadores.\n");
            return NULL; // O endereço de memória, que deveria armazenar as informações do centro, é retornado como NULL.
        }
    }

    else // Caso a alocação falhe.
    {
        printf("Erro na alocação de memória para o Centro.\n");
        return NULL; // O endereço de memória, que deveria armazenar as informações do centro, é retornado como NULL.
    }
}

void insere_fugitivos(Centro_de_Pesquisa *Centro) // A função recebe um ponteiro para um Centro de Pesquisa.
{

    FILE *arquivo;
    arquivo = fopen("teste1.txt", "r");

    if (arquivo != NULL) // Se o arquivo foi aberto corretamente.
    {

        char palavra[50]; // Variáveis auxiliares usadas para ajudar a pular a leitura das informações dos treinadores.
        int quantidade = 0;

        int cont = 0; // Variáveis auxiliares usadas para ajudar na leitura das informações dos Pokemons.
        int ident = 1;
        int numero_pokedex = 0;
        char nome_p[50];
        char tipo_p[50];
        int x, y = 0;

        fscanf(arquivo, "%49s %d", palavra, &quantidade); // Lê as informações dos treinadores.
        fscanf(arquivo, "%49s %d", palavra, &quantidade); // Lê as informações dos treinadores.
        fscanf(arquivo, "%d", &cont);                     // Lê a quantidade de Pokemons fugitivos.

        while (cont > 0) // Enquanto ainda tem Pokemons a serem lidos.
        {
            if ((fscanf(arquivo, " %d %49s %49s %d %d", &numero_pokedex, nome_p, tipo_p, &x, &y)) == 5) // Lê e repassa as informações para as variáveis auxiliares de leitura dos Pokemons.
            {

                Pokemon novo_pokemon;                                                      // Cria uma struct Pokemon.
                inicializa_pokemon(&novo_pokemon);                                         // Inializa as variáveis da struct Pokemon.
                insere_Pdados(&novo_pokemon, numero_pokedex, nome_p, tipo_p, ident, x, y); // Repassa os dados lidos para a struct Pokemon.
                LInsere(&Centro->fugitivos, &novo_pokemon);                                // Insere o Pokemon na lista de fugitivos.
                cont -= 1;                                                                 // Decrementa a quantidade de Pokemons a serem lidos.
                ident += 1;
                printf("Fugitivo cadastrado.\n"); // Incrementa o ID a ser atribuído ao pŕoximo Pokemon que pode lido.
            }
        }

        fclose(arquivo);
    }
}

void remove_fugitivos(Centro_de_Pesquisa *Centro) // A função recebe um ponteiro para um Centro de Pesquisa e remove um Pokemon da lista dos fugitivos.
{
    Pokemon aux; // Como a função LRetira também espera um ponteiro para Pokemon, cria-se essa variável auxilar para satisfazer as exigências da função. Nesse caso de retirada de um pokemon da lista de fugitivos, a permanência das informações do pokemon retirado não é necessária.
    LRetira(&(Centro->fugitivos), &aux);
}

void recebe_recuperados(Centro_de_Pesquisa *Centro, Treinador *pnt) // A função recebe um ponteiro para um Centro de Pesquisa e, um ponteiro para um treinador. A fim de fazer a lista dos recuperados do Centro de Pesquisa receber os Pokemons capturados pelo treinador.
{
    if (!(LEhVazia(&pnt->Tlista))) // Verifica se a Pokelista do treinador tem elementos.
    {

        int x = tamanho_lista(&(pnt->Tlista)); // Descobre a quantidade de pokemons armazenados na Pokelista do treinador.
        while (x > 0)                          // Enquanto há pokemons na Pokelista do treinador.
        {

            Pokemon aux;                           // Variável usada para a transição do pokemon da Pokelista do treinador para a lista dos pokemons recuperados do Centro de Pesquisa.
            LRetira(&(pnt->Tlista), &aux);         // Retira o pokemon da Pokelista do treinador.
            LInsere(&(Centro->recuperados), &aux); // Insere o pokemon na lista de pokemons recuperados do Centro de Pesquisa.
            x -= 1;
        }
    }
}

void imprime_fugitivos(Centro_de_Pesquisa *Centro) // A função recebe um ponteiro para um Centro de Pesquisa e imprime os pokemons presentes na lista dos fugitivos.
{
    LImprime(&(Centro->fugitivos));
}

void recarrega_pokebolas(Treinador *pnt) // A função recebe um ponteiro para um treinador e atualiza a quantidade de suas pokebolas somando um número pseudoaleatório entre 1 e 20.
{
    int x = (rand() % 20) + 1; // Gera um número pseudoaleatório entre 1 e 20.
    pnt->quant_pokebolas += x; // Atualiza a quantidade de pokebolas.
}

void imprime_relatorio(Centro_de_Pesquisa *Centro)
{
    FILE *file;
    file = fopen("relatorio.txt", "w");

    if (file != NULL) // Verifica se o arquivo foi criado(caso não exista) e acessado corretamente.
    {

        Apontador aux;
        aux = Centro->recuperados.primeiro->proximo;
        fprintf(file, "Pokemons recuperados:\n"); // Escreve o relatório no arquivo.

        while (aux != NULL)
        {
            fprintf(file, "%d %s\n", aux->info.num_pokedex, aux->info.nome);
            aux = aux->proximo;
        }
    }
    else
    {

        printf("ERRO na escrita do relatório.\n");
    }
}