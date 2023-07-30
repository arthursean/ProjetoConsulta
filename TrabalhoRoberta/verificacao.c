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

int validarCpf(char cpf[])
{
    int sum = 0;
    int verificador1 = cpf[9] - '0';
    int verificador2 = cpf[10] - '0';
    int condicao;
    for (int i = 0; i < 9; i++)
    {
        int temp = cpf[i] - '0';
        sum += temp * (10 - i);
    }
    condicao = 11 - (sum % 11);
    if (((verificador1 != condicao) && verificador1 != 0) || verificador1 == 0 && condicao < 10)
    {
        return 0;
    }
    sum = 0;
    for (int i = 0; i < 10; i++)
    {
        int temp = cpf[i] - '0';
        sum += temp * (11 - i);
    }
    condicao = 11 - (sum % 11);
    if (((verificador2 != condicao) && verificador2 != 0) || verificador2 == 0 && condicao < 10)
    {
        return 0;
    }
    return 1;
}
int escolhaData(int *dia, int *mes, int *ano)
{
    while (1)
    {
        printf("Dia: ");
        scanf("%d", &*dia);
        printf("Mes: ");
        scanf("%d", &*mes);
        printf("Ano: ");
        scanf("%d", &*ano);
        if (ehFeriado(*dia, *mes, *ano))
        {
            if ((*dia > 30 && (*mes == 4 || *mes == 6 || *mes == 9 || *mes == 11)) || *mes == 2 && *dia > ehBissexto(*ano) || *dia > 31)
            {
                *dia = 1;
                if (*mes == 12)
                {
                    *mes = 1;
                    *ano += 1;
                }
                else
                {
                    *mes += 1;
                }
            }
            else
            {
                *dia += 1;
            }
            while (validarData(*dia, *mes, *ano))
            {

                if ((*dia > 30 && (*mes == 4 || *mes == 6 || *mes == 9 || *mes == 11)) || *mes == 2 && *dia > ehBissexto(*ano) || *dia > 31)
                {
                    *dia = 1;
                    if (*mes == 12)
                    {
                        *mes = 1;
                        *ano += 1;
                    }
                    else
                    {
                        *mes += 1;
                    }
                }
                else
                {
                    *dia += 1;
                }
            }
            return 0;
        }
        if (!validarData(*dia, *mes, *ano))
        {
            printf("\n");
            return 0;
        }
        printf("Data inválida!\n");
        sleep(2);
        system("clear");
    }
    return 1;
}
void programaPaciente()
{
    int dia, mes, ano;
    char nome[50];
    char cpf[12];
    printf("Digite o seu primeiro nome: ");
    scanf("%s", nome);
    getchar();
    printf("Digite seu CPF: ");
    while (1)
    {
        scanf("%s", cpf);
        if (validarCpf(cpf))
        {
            printf("CPF cadastrado com sucesso!\n");
            break;
        }
        printf("Seu CPF é inválido, digite novamente!\n");
    }
    sleep(1);
    system("clear");
    printf("Agora escolha a data de sua consulta\n");
    escolhaData(&dia, &mes, &ano);
    system("clear");
    printf("Sr. %s sua consulta está marcada para %02d/%02d/%d\n", nome, dia, mes, ano);
    sleep(2);
    system("clear");
}
int main()
{
    int escolha;
    printf("Bem vindo à clínica Boa Estética!\n");
    printf("Você gostaria de:\n1 - Marcar consulta\n2 - Cadastrar como médico\n3 - Sair\n");
    scanf("%d", &escolha);
    system("clear");
    getchar();
    if (escolha == 1)
    {
        programaPaciente();
    }
    else if (escolha == 2)
    {
        // programaMedico();
    }
    else if (escolha == 3)
    {
        printf("Obrigado por utilizar nosso programa!\n");
        return 0;
    }
    else
    {
        main();
    }
}
