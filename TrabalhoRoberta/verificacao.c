#include <stdio.h>
#include <time.h>
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
int monthDay(int dia, int mes, int ano)
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
int validar(int dia, int mes, int ano)
{
    time_t tempo;
    struct tm *year;
    time(&tempo);
    year = localtime(&tempo);
    if (year->tm_year + 1900 > ano || (dia <= year->tm_mday && mes <= year->tm_mon + 1) || (mes < year->tm_mon + 1 && ano <= year->tm_year + 1900))
    {
        return 0;
    }
    if (!monthDay(dia, mes, ano))
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
    }
    printf("Consulta marcada para %d/%d/%d", dia, mes, ano);
}