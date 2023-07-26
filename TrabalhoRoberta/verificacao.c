#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int ehFeriado(int dia, int mes, int ano)
{
    if (ano == 2023 || ano == 2024)
    {
        char texto[10];
        int x = 0;
        sprintf(texto, "%d", ano);
        FILE *fp;
        fp = fopen(strcat(texto, ".txt"), "r");
        int diaF, mesF;
        while (fscanf(fp, "%d/%d", &diaF, &mesF) != EOF)
        {
            if (dia == diaF && mes == mesF)
            {
                return 1;
            }
        }
        fclose(fp);
    }
    return 0;
}
int retornaDiaDaSemana(int d, int m, int y)
{
    return (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
}
int ehBissexto(int ano)
{
    return ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0) ? 29 : 28;
}
int retornaDiaDoMes(int dia, int mes, int ano)
{
    return (dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) || mes == 2 && dia > ehBissexto(ano) || dia > 31;
}
int mesInt(char mes[])
{
    if (!strcmp("Jan", mes))
        return 1;
    if (!strcmp("Feb", mes))
        return 2;
    if (!strcmp("Mar", mes))
        return 3;
    if (!strcmp("Apr", mes))
        return 4;
    if (!strcmp("May", mes))
        return 5;
    if (!strcmp("Jun", mes))
        return 6;
    if (!strcmp("Jul", mes))
        return 7;
    if (!strcmp("Aug", mes))
        return 8;
    if (!strcmp("Sep", mes))
        return 9;
    if (!strcmp("Oct", mes))
        return 10;
    if (!strcmp("Nov", mes))
        return 11;
    if (!strcmp("Dec", mes))
        return 12;
}
void retornaDiaAtual(int *diaAtual, int *mesAtual, int *anoAtual)
{
    const char aa[] = __DATE__;
    char mes[4];
    char dia[3];
    char ano[5];
    int x = 0;
    for (int i = 0; i < 3; i++)
    {
        mes[i] = aa[i];
    }
    for (int i = 4; i < 7; i++)
    {
        dia[x] = aa[i];
        x += 1;
    }
    x = 0;
    for (int i = 7; i < 11; i++)
    {
        ano[x] = aa[i];
        x += 1;
    }
    *diaAtual = atoi(dia);
    *mesAtual = mesInt(mes);
    *anoAtual = atoi(ano);
}
int validarData(int dia, int mes, int ano)
{
    int anoAtual;
    int diaAtual;
    int mesAtual;
    retornaDiaAtual(&diaAtual, &mesAtual, &anoAtual);
    if (anoAtual > ano || (dia <= diaAtual && mes <= mesAtual && anoAtual >= ano) || (mes < mesAtual && ano <= anoAtual))
    {
        return 1;
    }
    return (retornaDiaDoMes(dia, mes, ano)) || (dia < 1) || (mes < 1 || mes > 12) || (retornaDiaDaSemana(dia, mes, ano) == 6 || retornaDiaDaSemana(dia, mes, ano) == 0) || ehFeriado(dia, mes, ano);
}
int main()
{
    int dia, mes, ano;
    int flag = 0;
    while (flag == 0)
    {
        printf("Dia: ");
        scanf("%d", &dia);
        printf("Mes: ");
        scanf("%d", &mes);
        printf("Ano: ");
        scanf("%d", &ano);
        if (!validarData(dia, mes, ano))
        {
            printf("\n");
            flag = 1;
            break;
        }
        printf("Data inválida!\n");
        sleep(2);
        system("clear");
    }
    system("clear");
    printf("Consulta marcada para %02d/%02d/%d\n", dia, mes, ano);
    sleep(2);
    system("clear");
}
