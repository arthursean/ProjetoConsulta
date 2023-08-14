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
    char *diasAtendimento[MAX_DIAS_ATENDIMENTO];
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

void salvarMedicoNoArquivo(struct Medico medico, int numDiasProcedimento)
{
    FILE *fp;
    fp = fopen(strcat(medico.cpf, ".txt"), "a");

    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(fp, "%s ", medico.nome);

    for (int i = 0; i < numDiasProcedimento; i++)
    {
        fprintf(fp, "%s ", medico.diasAtendimento[i]);
    }
    fprintf(fp, "%d-%d\n", medico.horaEntrada, medico.horaSaida);
    fclose(fp);
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
    printf("2 - Hipertrofias\n");
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

    printf("Você trabalhará quantos dias? ");
    int numDiasAtendimento = 0;
    scanf("%d", &numDiasAtendimento);
    printf("Dias de atendimento disponíveis:\n");
    printf("1 - Segunda-feira\n");
    printf("2 - Terca-feira\n");
    printf("3 - Quarta-feira\n");
    printf("4 - Quinta-feira\n");
    printf("5 - Sexta-feira\n");
    if (numDiasAtendimento > 0)
    {
        for (int x = 0; x < numDiasAtendimento; x++)
        {
            int dayChoice;
            printf("Escolha um dia de atendimento (1-5) ou 0 para sair: ");
            scanf("%d", &dayChoice);

            if (dayChoice == 0)
            {
                if (numDiasAtendimento == 0)
                {
                    printf("Você não adicionou nenhum dia de atendimento. Cancelando cadastro.\n");
                    return;
                }
                break;
            }
            else if (dayChoice >= 1 && dayChoice <= 5)
            {
                switch (dayChoice)
                {
                case 1:
                    medico.diasAtendimento[x] = strdup("segunda\0");
                    break;
                case 2:
                    medico.diasAtendimento[x] = strdup("terca\0");
                    break;
                case 3:
                    medico.diasAtendimento[x] = strdup("quarta\0");
                    break;
                case 4:
                    medico.diasAtendimento[x] = strdup("quinta\0");
                    break;
                case 5:
                    medico.diasAtendimento[x] = strdup("sexta\0");
                    break;
                }
            }
            else
            {
                printf("Opção inválida de dia de atendimento!\n");
            }
        }
    }
    printf("Quando você começará a atender? ");
    while (true)
    {
        scanf("%d", &medico.horaEntrada);
        if (medico.horaEntrada >= 7 && medico.horaEntrada <= 14)
        {
            medico.horaSaida = medico.horaEntrada + 6;
            break;
        }
        printf("Horário inválido\n");
    }

    salvarMedicoNoArquivo(medico, numDiasAtendimento);
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
