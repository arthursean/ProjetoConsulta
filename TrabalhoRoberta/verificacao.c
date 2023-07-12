#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
int diaDaSemana(int d, int m, int y)
{
    return (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
}
int bissexto(int ano)
{
    if (ano % 400 == 0)
    {
        return 29;
    }
    else if (ano % 100 != 0 && ano % 4 == 0)
    {
        return 29;
    }
    return 28;
}
int diaDoMes(int dia, int mes, int ano)
{
    if (dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
    {
        return 0;
    }
    else if (mes == 2 && dia > bissexto(ano))
    {
        return 0;
    }
    else if (dia > 31)
    {
        return 0;
    }
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
void atual(int *diaAtual, int *mesAtual, int *anoAtual)
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

int validar(int dia, int mes, int ano)
{
    int anoAtual;
    int diaAtual;
    int mesAtual;
    atual(&diaAtual, &mesAtual, &anoAtual);
    if (anoAtual > ano || (dia <= diaAtual && mes <= mesAtual && anoAtual >= ano) || (mes < mesAtual && ano <= anoAtual))
    {
        return 0;
    }
    if (!diaDoMes(dia, mes, ano))
    {
        return 0;
    }
    if (dia < 1)
    {
        return 0;
    }
    if (mes < 1 || mes > 12)
    {
        return 0;
    }
    if (diaDaSemana(dia, mes, ano) == 6 || diaDaSemana(dia, mes, ano) == 0)
    {
        return 0;
    }
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
        if (validar(dia, mes, ano))
        {
            printf("\n");
            flag = 1;
            break;
        }
        printf("Data inválida!\n");
        // sleep(2);
        // system("clear");
    }
    // system("clear");
    printf("Consulta marcada para %d/%d/%d\n", dia, mes, ano);
    // sleep(2);
    // system("clear");
}
