#include <stdio.h>
#include <stdlib.h>
#include "TAD_Pokelista.h"

void inicializa_lista(Lista *pLista)// A função recebe um ponteiro para uma lista.
{
    pLista->primeiro = (Apontador)malloc(sizeof(Poke_celula)); // Aloca dinamicamente um espaço na memória para armazenar a célula cabeça. Atribuindo o endereço dessa célula ao ponteiro "primeiro".
    pLista->ultimo = pLista->primeiro;                         // Como a lista não possui elementos, então os ponteiros "primeiro" e "ultimo" apontam para o mesmo lugar, a célula cabeça.
    pLista->primeiro->proximo = NULL;                          // O endereço de memória do elemento que vem após a célula cabeça é NULL.
}

int LEhVazia(Lista *pLista)// A função recebe um ponteiro para uma lista.
{
    if (pLista->primeiro == pLista->ultimo) // Se a lista é vazia, os ponteiros "primeiro" e "ultimo" apontam para o mesmo lugar, para a célula cabeça. E a função retorna 1 como confirmação.
    {
        return 1;
    }

    else // Caso a lista tenha elementos, então os ponteiros "primeiro" e "ultimo" apontam para lugares diferentes. O "primeiro" aponta para a célula cabeça e o "ultimo" aponta para a ultima célula na lista. Assim, a função retorna 0 como negação.
    {
        return 0;
    }
}

void LInsere(Lista *pLista, Pokemon *p) // A função recebe um ponteiro para uma lista e um ponteiro para um Pokemon.
{
    pLista->ultimo->proximo = (Apontador)malloc(sizeof(Poke_celula)); // Aloca dinamicamente um espaço na memória para armazenar a nova célula da lista e, coloca essa nova célula após o último elemento da lista.
    pLista->ultimo = pLista->ultimo->proximo;                         // Atualiza o ponteiro "ultimo", uma vez que a nova última célula vem após a antiga última célula.
    pLista->ultimo->info = *p;                                        // O campo info da nova célula, que armazena as informações do Pokemon, recebe o conteúdo do Pokemon recebido como parâmetro.
    pLista->ultimo->proximo = NULL;                                   // A nova última célula aponta para NULL.
}

int LRetira(Lista *pLista, Pokemon *p)// A função recebe um ponteiro para uma lista e um ponteiro para um Pokemon.
{
    Apontador aux; // Cria um ponteiro para uma célula Pokémon.
    if (LEhVazia(pLista))
    {
        return 0;
    }

    *p = pLista->primeiro->proximo->info;         // Salva as informações do Pokemon em uma variável externa do tipo Pokemon.
    aux = pLista->primeiro;                       // aux aponta para a célula cabeça.
    pLista->primeiro = pLista->primeiro->proximo; // A nova célula cabeça é a célula que vem depois da antiga célula cabeça.
    free(aux);                                    // Libera a antiga célula cabeça.
    return 1;
}

void LImprime(Lista *pLista)// A função recebe um ponteiro para uma lista.
{
    Apontador aux; // Cria um ponteiro para uma célula Pokémon.

    aux = pLista->primeiro->proximo; // aux aponta para o primeiro elemento da lista, que vem após a célula cabeça.

    while (aux != NULL) // Enquanto não chegou ao final da lista.
    {
        printf("\nID: %d\n", aux->info.ID);
        printf("Número na Pokédex: %d\n", aux->info.num_pokedex);
        printf("Nome: %s\n", aux->info.nome);
        printf("Tipo: %s\n", aux->info.tipo);
        printf("Localização: %d %d\n\n", aux->info.lugar.x, aux->info.lugar.y);
        aux = aux->proximo; //"Anda" na lista.
    }
}

int busca(Lista *pLista, int id)// A função recebe um ponteiro para uma lista e um valor de ID a ser buscado.
{
    if (LEhVazia(pLista)) // Se a lista é vazia, não há elementos para buscar.
    {
        return 0; // Retorna zero pois o Pokemon com o ID recebido não está na lista.
    }

    Apontador aux;                   // Cria um ponteiro para uma célula Pokémon.
    aux = pLista->primeiro->proximo; // aux aponta para o primeiro elemento da lista, que vem após a célula cabeça.
    while (aux != NULL)              // Enquanto não chegou ao final da lista.
    {
        if (aux->info.ID == id) // Se encontra o ID.
        {
            printf("O elemento está na lista.\n");
            return 1; // ID encontrado,
        }
        aux = aux->proximo; //"Anda" na lista caso o ID não seja encontrado.
    }
    printf("O elemento não está na lista.\n");
    return 0; // Retorna zero pois o Pokemon com o ID recebido não está na lista.
}

int tamanho_lista(Lista *pLista)// A função recebe um ponteiro para uma lista.
{
    if (LEhVazia(pLista)) // Se a lista está vazia, ela tem zero elementos.
    {
        return 0; // Retorna a quantidae de elementos na lista, que é zero.
    }

    int tam = 0;
    Apontador aux;
    aux = pLista->primeiro->proximo; // aux aponta para o primeiro elemento da lista, que vem após a célula cabeça.

    while (aux != NULL) // Enquanto não chegou no fim da lista.
    {
        tam += 1;           // Incrementa o valor do tamanho.
        aux = aux->proximo; //"Anda" na lista.
    }

    return tam;
}
