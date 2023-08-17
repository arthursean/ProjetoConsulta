#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{
    char *nomeDoProcedimento;
    int numVezes;
    int tempoMinimoEntreAplicacoes;
    int tempoMaximoEntreAplicacoes;
    int duracaoProcedimento;

} Procedimento;

void selecionaProcedimentosDoMedico(int escolha, char *nome)
{
    switch (escolha)
    {
    case 1:
        FILE *fp = fopen("Espinha.txt", "a");
        fprintf(fp, "%s\n", nome);
        fclose(fp);
        break;
    case 2:
        fp = fopen("Hipertrofia.txt", "a");
        fprintf(fp, "%s\n", nome);
        fclose(fp);
        break;
    case 3:
        fp = fopen("Queloides.txt", "a");
        fprintf(fp, "%s\n", nome);
        fclose(fp);
        break;
    case 4:
        fp = fopen("Micose.txt", "a");
        fprintf(fp, "%s\n", nome);
        fclose(fp);
        break;
    case 5:
        fp = fopen("Varizes.txt", "a");
        fprintf(fp, "%s\n", nome);
        fclose(fp);
        break;
    case 6:
        fp = fopen("Consulta.txt", "a");
        fprintf(fp, "%s\n", nome);
        fclose(fp);
        break;
    default:
        printf("Inválido\n");
        return;
    }

    return;
}
void retornaCpfMedicos(char *problema, char cpfs[][16], int *contador)
{
    FILE *file = fopen(problema, "r");
    while (fscanf(file, "%s", cpfs[*contador]) != EOF)
    {
        strcat(cpfs[*contador], ".txt");
        *contador += 1;
    }
    fclose(file);
    return;
}
int verificaDisponibilidade(int dia, int mes, int ano, int escolha, int hora, int minuto, char nome[])
{
    char name[18];
    char fileName[50];
    char cpfs[50][16];
    int contador = 0;
    FILE *file;
    FILE *fp;
    int diaAux, mesAux, anoAux, horaInicio, minInicio, horaFinal, minFinal;
    switch (escolha)
    {
    case 1:
        Procedimento espinha =
            {
                .nomeDoProcedimento = "Espinha",
                .numVezes = 10,
                .tempoMinimoEntreAplicacoes = 15,
                .tempoMaximoEntreAplicacoes = 30,
                .duracaoProcedimento = 10};

        retornaCpfMedicos("Espinha.txt", cpfs, &contador);
        for (int i = 0; i < contador; i++)
        {
            sprintf(fileName, "%s", cpfs[i]);

            fp = fopen(fileName, "r");

            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            while (!feof(fp))
            {
                if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
                {
                    break;
                }
                else
                {
                    fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
                }
            }
            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
            {
                fclose(fp);
            }
            else
            {
                fclose(fp);
                fp = fopen(fileName, "a");
                fprintf(fp, "\n%d/%d/%d-%d:%d-%d:%d %s %s", dia, mes, ano, hora, minuto, hora, minuto + espinha.duracaoProcedimento, nome, espinha.nomeDoProcedimento);
                return 0;
            }
        }
        return 1;
        break;
    case 2:
        Procedimento hipertrofias = {
            .nomeDoProcedimento = "Hipertrofias",
            .numVezes = 15,
            .tempoMinimoEntreAplicacoes = 20,
            .tempoMaximoEntreAplicacoes = 25,
            .duracaoProcedimento = 30};

        retornaCpfMedicos("Hipertrofia.txt", cpfs, &contador);
        for (int i = 0; i < contador; i++)
        {
            sprintf(fileName, "%s", cpfs[i]);

            fp = fopen(fileName, "r");

            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            while (!feof(fp))
            {
                if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
                {
                    break;
                }
                else
                {
                    fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
                }
            }
            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
            {
                fclose(fp);
            }
            else
            {
                fclose(fp);
                fp = fopen(fileName, "a");
                fprintf(fp, "\n%d/%d/%d-%d:%d-%d:%d %s %s", dia, mes, ano, hora, minuto, hora, minuto + hipertrofias.duracaoProcedimento, nome, hipertrofias.nomeDoProcedimento);
                return 0;
            }
        }
        return 1;
        break;
    case 3:
        Procedimento queloides =
            {
                .nomeDoProcedimento = "Queloides",
                .numVezes = 20,
                .tempoMinimoEntreAplicacoes = 10,
                .tempoMaximoEntreAplicacoes = 15,
                .duracaoProcedimento = 20};
        retornaCpfMedicos("Queloides.txt", cpfs, &contador);
        for (int i = 0; i < contador; i++)
        {
            sprintf(fileName, "%s", cpfs[i]);

            fp = fopen(fileName, "r");

            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            while (!feof(fp))
            {
                if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
                {
                    break;
                }
                else
                {
                    fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
                }
            }
            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
            {
                fclose(fp);
            }
            else
            {
                fclose(fp);
                fp = fopen(fileName, "a");
                fprintf(fp, "\n%d/%d/%d-%d:%d-%d:%d %s %s", dia, mes, ano, hora, minuto, hora, minuto + queloides.duracaoProcedimento, nome, queloides.nomeDoProcedimento);
                return 0;
            }
        }
        return 1;
        break;
    case 4:
        Procedimento micose =
            {
                .nomeDoProcedimento = "Micose",
                .numVezes = 10,
                .tempoMinimoEntreAplicacoes = 3,
                .tempoMaximoEntreAplicacoes = 5,
                .duracaoProcedimento = 10};
        retornaCpfMedicos("Micose.txt", cpfs, &contador);
        for (int i = 0; i < contador; i++)
        {
            sprintf(fileName, "%s", cpfs[i]);

            fp = fopen(fileName, "r");

            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            while (!feof(fp))
            {
                if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
                {
                    break;
                }
                else
                {
                    fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
                }
            }
            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
            {
                fclose(fp);
            }
            else
            {
                fclose(fp);
                fp = fopen(fileName, "a");
                fprintf(fp, "\n%d/%d/%d-%d:%d-%d:%d %s %s", dia, mes, ano, hora, minuto, hora, minuto + micose.duracaoProcedimento, nome, micose.nomeDoProcedimento);
                return 0;
            }
        }
        return 1;
        break;
    case 5:
        Procedimento varizes =
            {
                .nomeDoProcedimento = "Varizes",
                .numVezes = 30,
                .tempoMinimoEntreAplicacoes = 7,
                .tempoMaximoEntreAplicacoes = 11,
                .duracaoProcedimento = 40};

        retornaCpfMedicos("Varizes.txt", cpfs, &contador);
        for (int i = 0; i < contador; i++)
        {
            sprintf(fileName, "%s", cpfs[i]);

            fp = fopen(fileName, "r");

            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            while (!feof(fp))
            {
                if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
                {
                    break;
                }
                else
                {
                    fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
                }
            }
            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
            {
                fclose(fp);
            }
            else
            {
                fclose(fp);
                fp = fopen(fileName, "a");
                fprintf(fp, "\n%d/%d/%d-%d:%d-%d:%d %s %s", dia, mes, ano, hora, minuto, hora, minuto + varizes.duracaoProcedimento, nome, varizes.nomeDoProcedimento);
                return 0;
            }
        }
        return 1;
        break;
    case 6:
        Procedimento consulta =
            {
                .nomeDoProcedimento = "Consulta",
                .numVezes = 1,
                .tempoMinimoEntreAplicacoes = 32,
                .tempoMaximoEntreAplicacoes = 186,
                .duracaoProcedimento = 60};

        retornaCpfMedicos("Consulta.txt", cpfs, &contador);
        for (int i = 0; i < contador; i++)
        {
            sprintf(fileName, "%s", cpfs[i]);

            fp = fopen(fileName, "r");

            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            while (!feof(fp))
            {
                if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
                {
                    break;
                }
                else
                {
                    fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
                }
            }
            fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
            {
                fclose(fp);
            }
            else
            {
                fclose(fp);
                fp = fopen(fileName, "a");
                fprintf(fp, "\n%d/%d/%d-%d:%d-%d:%d %s %s", dia, mes, ano, hora, minuto, hora, minuto + consulta.duracaoProcedimento, nome, consulta.nomeDoProcedimento);
                return 0;
            }
        }
        return 1;
        break;
    default:
        printf("Inválido\n");
    }
    return 0;
}