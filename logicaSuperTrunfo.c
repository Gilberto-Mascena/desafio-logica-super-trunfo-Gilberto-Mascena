#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Desafio Super Trunfo - Países
 Tema 2 - Comparação das Cartas
 Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades.
 Siga os comentários para implementar cada parte do desafio.
 */

// Definição da estrutura Cidade
// A estrutura Cidade contém os atributos necessários para armazenar as informações de cada cidade.
typedef struct
{
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    float densidadePopulacional;
    float pibPerCapita;
} Cidade;

/*
 Função para cadastrar cidades
 Esta função solicita ao usuário as informações de cada cidade e as armazena em um vetor dinâmico.
 O vetor é alocado dinamicamente com base na quantidade de cidades que o usuário deseja cadastrar.
 A função retorna o número de cidades cadastradas.
 */
int cadastrarCidade(Cidade **cidades)
{

    printf("\n-------------Cadastro de Cidade--------------\n");
    printf("\nQuantas cidades deseja cadastrar? ");

    int numCidades;
    scanf("%d", &numCidades);
    *cidades = (Cidade *)malloc(numCidades * sizeof(Cidade));
    if (*cidades == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    // For para percorrer o vetor de cidades
    // e solicitar os dados de cada cidade
    for (int i = 0; i < numCidades; i++)
    {
        printf("\nCadastro da cidade #%d:\n", i + 1);
        printf("Digite o código da cidade: ");
        scanf("%9s", (*cidades)[i].codigo); // Limita a entrada a 9 caracteres
        printf("Digite o nome da cidade: ");
        scanf("%49s", (*cidades)[i].nome); // Limita a entrada a 49 caracteres
        printf("Digite a população da cidade: ");
        scanf("%d", &(*cidades)[i].populacao);
        printf("Digite a área da cidade (em km²): ");
        scanf("%f", &(*cidades)[i].area);
        printf("Digite o PIB da cidade: ");
        scanf("%f", &(*cidades)[i].pib);
        printf("Digite a densidade populacional da cidade: ");
        scanf("%f", &(*cidades)[i].densidadePopulacional);
        printf("Digite o PIB per capita da cidade: ");
        scanf("%f", &(*cidades)[i].pibPerCapita);
    }
    return numCidades; // Retorna o número de cidades cadastradas
}

int main()
{
    
    Cidade *cidades = NULL; // Ponteiro para o vetor de cidades
    int numCidades = cadastrarCidade(&cidades); // Chama a função para cadastrar cidades e armazena o número de cidades cadastradas

    // Exibição dos dados cadastrados
    printf("\n-------------Dados Cadastrados--------------\n");
    for (int i = 0; i < numCidades; i++)
    {
        printf("\nCidade #%d:\n", i + 1);
        printf("Código: %s\n", cidades[i].codigo);
        printf("Nome: %s\n", cidades[i].nome);
        printf("População: %d\n", cidades[i].populacao);
        printf("Área: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2f\n", cidades[i].pib);
        printf("Densidade Populacional: %.2f\n", cidades[i].densidadePopulacional);
        printf("PIB per Capita: %.2f\n", cidades[i].pibPerCapita);
    }

    /*
     Liberação da memória alocada pela lista de cidades
     Após o uso, é importante liberar a memória alocada para evitar vazamentos de memória.
     Utilize a função free() para liberar a memória alocada para o vetor de cidades.
     */
    free(cidades);

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
