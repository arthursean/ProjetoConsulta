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
int verificaDisponibilidade(int dia, int mes, int ano, int escolha, int hora, int minuto, char nome[])
{
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
        char name[18];
        FILE *file = fopen("Espinha.txt", "r");
        fscanf(file, "%s", name);
        FILE *fp = fopen(strcat(name, ".txt"), "r");
        int diaAux, mesAux, anoAux, horaInicio, minInicio, horaFinal, minFinal;
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        while (!feof(fp))
        {
            if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
            {
                return 1;
            }
            else
            {
                fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            }
        }
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d %*s %*s\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        if (diaAux == dia && mesAux == mes && anoAux == ano && (horaInicio == hora && minInicio <= minuto && minFinal > minuto))
        {
            return 1;
        }
        else
        {
            fclose(fp);
            fp = fopen(name, "a");
            fprintf(fp, "\n%d/%d/%d-%d:%d-%d:%d %s %s", dia, mes, ano, hora, minuto, hora, minuto + espinha.duracaoProcedimento, nome, espinha.nomeDoProcedimento);
            return 0;
        }
        break;
    case 2:
        Procedimento hipertrofias = {
            .nomeDoProcedimento = "Hipertrofias",
            .numVezes = 15,
            .tempoMinimoEntreAplicacoes = 20,
            .tempoMaximoEntreAplicacoes = 25,
            .duracaoProcedimento = 30};
        fp = fopen("09428867470.txt", "r");
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        while (!feof(fp))
        {
            if (diaAux == dia && mesAux == mes && anoAux == ano)
            {
                return 1;
            }
            else
            {
                fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            }
        }
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        if (diaAux == dia && mesAux == mes && anoAux == ano)
        {
            return 1;
        }
        else
        {
            fclose(fp);
            fp = fopen("09428867470.txt", "a");
            fprintf(fp, "\n%d/%d/%d", dia, mes, ano);
            return 0;
        }
        break;
    case 3:
        Procedimento queloides =
            {
                .nomeDoProcedimento = "Queloides",
                .numVezes = 20,
                .tempoMinimoEntreAplicacoes = 10,
                .tempoMaximoEntreAplicacoes = 15,
                .duracaoProcedimento = 20};
        fp = fopen("09428867470.txt", "r");
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        while (!feof(fp))
        {
            if (diaAux == dia && mesAux == mes && anoAux == ano)
            {
                return 1;
            }
            else
            {
                fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            }
        }
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        if (diaAux == dia && mesAux == mes && anoAux == ano)
        {
            return 1;
        }
        else
        {
            fclose(fp);
            fp = fopen("09428867470.txt", "a");
            fprintf(fp, "\n%d/%d/%d", dia, mes, ano);
            return 0;
        }
        break;
    case 4:
        Procedimento micose =
            {
                .nomeDoProcedimento = "Micose",
                .numVezes = 10,
                .tempoMinimoEntreAplicacoes = 3,
                .tempoMaximoEntreAplicacoes = 5,
                .duracaoProcedimento = 10};
        fp = fopen("09428867470.txt", "r");
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        while (!feof(fp))
        {
            if (diaAux == dia && mesAux == mes && anoAux == ano)
            {
                return 1;
            }
            else
            {
                fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            }
        }
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        if (diaAux == dia && mesAux == mes && anoAux == ano)
        {
            return 1;
        }
        else
        {
            fclose(fp);
            fp = fopen("09428867470.txt", "a");
            fprintf(fp, "\n%d/%d/%d", dia, mes, ano);
            return 0;
        }
        break;
    case 5:
        Procedimento varizes =
            {
                .nomeDoProcedimento = "Varizes",
                .numVezes = 30,
                .tempoMinimoEntreAplicacoes = 7,
                .tempoMaximoEntreAplicacoes = 11,
                .duracaoProcedimento = 40};
        fp = fopen("09428867470.txt", "r");
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        while (!feof(fp))
        {
            if (diaAux == dia && mesAux == mes && anoAux == ano)
            {
                return 1;
            }
            else
            {
                fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            }
        }
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        if (diaAux == dia && mesAux == mes && anoAux == ano)
        {
            return 1;
        }
        else
        {
            fclose(fp);
            fp = fopen("09428867470.txt", "a");
            fprintf(fp, "\n%d/%d/%d", dia, mes, ano);
            return 0;
        }
        break;
    case 6:
        Procedimento consulta =
            {
                .nomeDoProcedimento = "Consulta",
                .numVezes = 1,
                .tempoMinimoEntreAplicacoes = 32,
                .tempoMaximoEntreAplicacoes = 186,
                .duracaoProcedimento = 60};
        fp = fopen("09428867470.txt", "r");
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        while (!feof(fp))
        {
            if (diaAux == dia && mesAux == mes && anoAux == ano)
            {
                return 1;
            }
            else
            {
                fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
            }
        }
        fscanf(fp, "%d/%d/%d-%d:%d-%d:%d\n", &diaAux, &mesAux, &anoAux, &horaInicio, &minInicio, &horaFinal, &minFinal);
        if (diaAux == dia && mesAux == mes && anoAux == ano)
        {
            return 1;
        }
        else
        {
            fclose(fp);
            fp = fopen("09428867470.txt", "a");
            fprintf(fp, "\n%d/%d/%d", dia, mes, ano);
            return 0;
        }
        break;
    default:
        printf("Inválido\n");
    }
    return 0;
}