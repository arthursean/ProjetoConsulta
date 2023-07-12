#include <stdio.h>
#include <stdlib.h>
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
int validar(int dia, int mes, int ano)
{
    time_t tempo;
    struct tm *year;
    time(&tempo);
    year = localtime(&tempo);
    if (year->tm_year + 1900 > ano || (dia <= year->tm_mday && mes <= year->tm_mon + 1 && year->tm_year + 1900 >= ano) || (mes < year->tm_mon + 1 && ano <= year->tm_year + 1900))
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
        sleep(2);
        system("clear");
    }
    system("clear");
    printf("Consulta marcada para %d/%d/%d\n", dia, mes, ano);
    sleep(2);
    system("clear");
}
