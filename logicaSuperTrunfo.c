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
        while (getchar() != '\n'); // Limpa o buffer de entrada        
        fgets((*cidades)[i].nome, sizeof((*cidades)[i].nome), stdin); // Lê a string com espaços
        (*cidades)[i].nome[strcspn((*cidades)[i].nome, "\n")] = 0; // Remove o caractere de nova linha     

        printf("Digite a população da cidade: ");
        scanf("%d", &(*cidades)[i].populacao);
        while (getchar() != '\n'); // Limpa o buffer de entrada

        printf("Digite a área da cidade (em km²): ");
        scanf("%f", &(*cidades)[i].area);

        printf("Digite o PIB da cidade: ");
        scanf("%f", &(*cidades)[i].pib);
                
        // // Calculando a densidade populacional programaticamente
        // (*cidades)[i].densidadePopulacional = (*cidades)[i].populacao / (*cidades)[i].area;
        // printf("Densidade populacional calculada: %.2f\n", (*cidades)[i].densidadePopulacional);
        
        while (getchar() != '\n'); // Limpa o buffer de entrada
        printf("Digite a densidade populacional da cidade: ");
        scanf("%f", &(*cidades)[i].densidadePopulacional);
        while (getchar() != '\n'); // Limpa o buffer de entrada
        printf("Digite o PIB per capita da cidade: ");
        scanf("%f", &(*cidades)[i].pibPerCapita);
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }
    return numCidades; // Retorna o número de cidades cadastradas
}

int main()
{

    Cidade *cidades = NULL;                     // Ponteiro para o vetor de cidades
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

    // Exibição de comparações entre cidades
    printf("\n-------------Comparação de Cidades--------------\n");
    printf("\n");

    // Comparando a densidade populacional
    int i = 0, j = 1; // Definindo índices para as cidades a serem comparadas

    if (cidades[i].densidadePopulacional > cidades[j].densidadePopulacional)
    {
        printf("A cidade %s, tem maior densidade populacional que a cidade %s\n", cidades[i].nome, cidades[j].nome);
    }
    else
    {
        printf("A cidade %s, tem menor densidade populacional que a cidade %s\n", cidades[i].nome, cidades[j].nome);
    }
    
    // Comparando o PIB per capita
    if (cidades[i].pibPerCapita > cidades[j].pibPerCapita)
    {
        printf("A cidade %s, tem maior PIB per capita que a cidade %s\n", cidades[i].nome, cidades[j].nome);
    }
    else
    {
        printf("A cidade %s, tem menor PIB per capita que a cidade %s\n", cidades[i].nome, cidades[j].nome);
    }

    // Determinando a cidade vencedora com base no PIB per capita
    char *cidadeVencedora = (cidades[i].pibPerCapita > cidades[j].pibPerCapita) ? cidades[i].nome : cidades[j].nome;

    // Exibição dos resultados
    printf("\nA cidade vencedora é: %s, parabéns!\n", cidadeVencedora); // Exibe a cidade vencedora
    printf("\n");

    // Liberando a memória alocada
    free(cidades);

    return 0;
}
