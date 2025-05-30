#include <stdio.h>
#include <string.h>

float calcularMedia(float n1, float n2, float n3);
float notaAlta(float n1, float n2, float n3);
float notaBaixa(float n1, float n2, float n3);
float mediaTurma(float medias[], int quantidade);

int main() {
    int qtdalunos;
    char nome[100], turma[30];
    float media, n1, n2, n3;
    int repetir;

    do {
        #ifdef _WIN32
            system("cls");  // Windows
        #else
            system("clear");  // Linux/macOS
        #endif

        printf("Escreva a matéria:\n");
        fgets(turma, sizeof(turma), stdin);
        turma[strcspn(turma, "\n")] = '\0'; 

        // Validação para garantir que a quantidade de alunos seja maior que 0
        do {
            printf("Escreva a quantidade de alunos (maior que 0):\n");
            scanf("%d", &qtdalunos);
            if (qtdalunos <= 0) {
                printf("Quantidade inválida! Digite um número maior que 0.\n");
            }
        } while (qtdalunos <= 0);
        getchar();  // Limpa o '\n' do scanf anterior

        float medias[qtdalunos];

        printf("---------------------------\n");

        // Loop para inserir os dados dos alunos
        for (int i = 0; i < qtdalunos; i++) {
            printf("Escreva o nome do aluno:\n");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            // Validação das notas (entre 0 e 10)
            do {
                printf("Escreva o valor da nota 1:\n");
                scanf("%f", &n1);
                if (n1 > 10 || n1 < 0) {
                    printf("Número inválido (apenas de 0 a 10)\n");
                }
            } while (n1 > 10 || n1 < 0);

            do {
                printf("Escreva o valor da nota 2:\n");
                scanf("%f", &n2);
                if (n2 > 10 || n2 < 0) {
                    printf("Número inválido (apenas de 0 a 10)\n");
                }
            } while (n2 > 10 || n2 < 0);

            do {
                printf("Escreva o valor da nota 3:\n");
                scanf("%f", &n3);
                if (n3 > 10 || n3 < 0) {
                    printf("Número inválido (apenas de 0 a 10)\n");
                }
            } while (n3 > 10 || n3 < 0);

            getchar();  // Limpa o '\n' após scanf das notas

            // Cálculo da média, maior e menor nota
            media = calcularMedia(n1, n2, n3);
            medias[i] = media;
            float maiorNota = notaAlta(n1, n2, n3);
            float menorNota = notaBaixa(n1, n2, n3);
            
            // Definindo status do aluno (Aprovado/Reprovado)
            char status[15];
            if (media >= 6.0) {
                strcpy(status, "Aprovado");
            } else {
                strcpy(status, "Reprovado");
            }

            // Exibindo as informações do aluno
            printf("Matéria: %s | Aluno: %s | Média: %.2f | Maior nota: %.2f | Menor nota: %.2f | Status: %s\n",
                   turma, nome, media, maiorNota, menorNota, status);
            printf("---------------------------\n");
        }

        // Cálculo da média geral da turma
        float mediaGeral = mediaTurma(medias, qtdalunos);
        printf("\nMédia geral da turma de %s: %.2f\n", turma, mediaGeral);

        // Contagem de alunos aprovados e reprovados
        int aprovados = 0, reprovados = 0;
        for (int i = 0; i < qtdalunos; i++) {
            if (medias[i] >= 6.0) {
                aprovados++;
            } else {
                reprovados++;
            }
        }

        printf("Quantidade de alunos aprovados: %d\n", aprovados);
        printf("Quantidade de alunos reprovados: %d\n", reprovados);

        // Cálculo da maior e menor média da turma
        float maiorMedia = medias[0];
        float menorMedia = medias[0];
        for (int i = 1; i < qtdalunos; i++) {
            if (medias[i] > maiorMedia) {
                maiorMedia = medias[i];
            }
            if (medias[i] < menorMedia) {
                menorMedia = medias[i];
            }
        }

        printf("Maior média da turma: %.2f\n", maiorMedia);
        printf("Menor média da turma: %.2f\n", menorMedia);

        // Perguntar se o usuário quer refazer a consulta ou encerrar
        printf("\nDeseja fazer uma nova consulta?\n(0)Encerrar o programa\n(1)Refazer nova consulta\n");
        scanf("%d", &repetir);
        getchar();  

    } while(repetir == 1);

    return 0;
}

// Função para calcular a média
float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

// Função para encontrar a maior nota
float notaAlta(float n1, float n2, float n3) {
    float maior = n1;
    if (n2 > maior) maior = n2;
    if (n3 > maior) maior = n3;
    return maior;
}

// Função para encontrar a menor nota
float notaBaixa(float n1, float n2, float n3) {
    float menor = n1;
    if (n2 < menor) menor = n2;
    if (n3 < menor) menor = n3;
    return menor;
}

// Função para calcular a média geral da turma
float mediaTurma(float medias[], int quantidade) {
    float soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += medias[i];
    }
    return soma / quantidade;
}
