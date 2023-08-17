#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_PROC_LENGTH 30
#define MAX_NAME_LENGTH 50
#define MAX_PROCEDIMENTOS 6
#define MAX_DIAS_ATENDIMENTO 5

int validarCpf();
int selecionaProcedimentosDoMedico();
struct Medico
{
    char nome[MAX_NAME_LENGTH];
    char cpf[12];
    char *procedimentos[MAX_PROCEDIMENTOS];
    int diasAtendimento[MAX_DIAS_ATENDIMENTO];
    int horaEntrada;
    int horaSaida;
};

void liberarProcedimentos(struct Medico medico)
{
    for (int i = 0; i < MAX_PROCEDIMENTOS; i++)
    {
        free(medico.procedimentos[i]);
    }
}

void salvarMedicoNoArquivo(struct Medico medico)
{
    FILE *fp;
    fp = fopen(strcat(medico.cpf, ".txt"), "a");
}

void cadastrarMedico()
{
    struct Medico medico;

    printf("Digite o nome do medico: ");
    scanf("%s", medico.nome);
    printf("Digite o CPF do medico: ");
    while (true)
    {
        scanf("%s", medico.cpf);
        if (validarCpf(medico.cpf))
        {
            break;
        }
        printf("CPF inválido. Digite novamente\n");
    }

    printf("Quantos procedimentos você realizará? ");
    int numProcedimentos = 0;
    scanf("%d", &numProcedimentos);
    printf("Procedimentos disponíveis:\n");
    printf("1 - Espinhas\n");
    printf("2 - Hipertrofia\n");
    printf("3 - Queloides\n");
    printf("4 - Micose\n");
    printf("5 - Varizes\n");
    printf("6 - Consulta\n");

    if (numProcedimentos > 0 && numProcedimentos < 7)
    {
        for (int i = 0; i < numProcedimentos; i++)
        {
            int procedimentosEscolha;
            printf("Escolha um procedimento (1-6) ou 0 para sair: ");
            scanf("%d", &procedimentosEscolha);
            if (procedimentosEscolha >= 1 && procedimentosEscolha <= 6)
            {
                selecionaProcedimentosDoMedico(procedimentosEscolha, medico.cpf);
            }
        }
    }
    salvarMedicoNoArquivo(medico);
    printf("Médico cadastrado com sucesso!\n");
}

void programaMedico()
{
    int escolha;
    do
    {
        printf("Você gostaria de:\n1 - Cadastrar medico\n2 - Voltar ao menu principal\n");
        scanf("%d", &escolha);
        getchar();

        switch (escolha)
        {
        case 1:
            cadastrarMedico();
            break;
        case 2:
            return;
        default:
            printf("Escolha inválida, tente novamente!\n");
        }
    } while (true);
}
