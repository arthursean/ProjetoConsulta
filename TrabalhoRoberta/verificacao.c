#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void programaMedico();
int verificaDisponibilidade();
int encontrarProximoDiaUtil();
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
    // printf("%d %d %d", *diaAtual, *mesAtual, *anoAtual);
}
int validarData(int dia, int mes, int ano, int escolha, int hora, int min, char nome[])
{
    int anoAtual;
    int diaAtual;
    int mesAtual;
    retornaDiaAtual(&diaAtual, &mesAtual, &anoAtual);
    if (anoAtual > ano || (dia <= diaAtual && mes <= mesAtual && anoAtual >= ano) || (mes < mesAtual && ano <= anoAtual))
    {
        return 1;
    }
    int valida = (retornaDiaDoMes(dia, mes, ano)) || (dia < 1) || (mes < 1 || mes > 12) || (retornaDiaDaSemana(dia, mes, ano) == 6 || retornaDiaDaSemana(dia, mes, ano) == 0) || ehFeriado(dia, mes, ano);
    if (valida == 0)
    {
        return verificaDisponibilidade(dia, mes, ano, escolha, hora, min, nome);
    }
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

int ehDiaUtil(int diaSemana)
{
    if (diaSemana >= 1 && diaSemana <= 5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int encontrarProximoDiaUtil(int dia, int mes, int ano)
{
    int diaSemana = retornaDiaDaSemana(dia, mes, ano);

    while (!ehDiaUtil(diaSemana) || ehFeriado(dia, mes, ano))
    {
        if (retornaDiaDoMes(dia, mes, ano))
        {
            dia = 1;
            if (mes < 12)
            {
                mes++;
            }
            else
            {
                mes = 1;
                ano++;
            }
        }
        else
        {
            dia++;
        }
        diaSemana = (diaSemana + 1) % 7;
    }

    return dia;
}

typedef struct
{
    char nomeDoProcedimento[50];
    int numVezes;
    int tempoMinimoEntreAplicacoes;
    int tempoMaximoEntreAplicacoes;
    int duracaoProcedimento;
} Procedimento;

int escolhaData(int *dia, int *mes, int *ano, int escolha, char nome[])
{
    Procedimento procedimentos[] = {
        {"Espinhas", 10, 15, 22},
        {"Hipertrofias", 15, 20, 25},
        {"Queloides", 20, 10, 15},
        {"Micose", 10, 3, 5},
        {"Varizes", 30, 7, 11},
        {"Consulta", 1, 32, 186}};

    int intervaloMin = procedimentos[escolha - 1].tempoMinimoEntreAplicacoes;
    int intervaloMax = procedimentos[escolha - 1].tempoMaximoEntreAplicacoes;

    printf("Digite o intervalo desejado entre as consultas (em dias) entre %d e %d: ", intervaloMin, intervaloMax);
    int intervaloEscolhido;
    while (1)
    {
        scanf("%d", &intervaloEscolhido);
        if (intervaloEscolhido >= intervaloMin && intervaloEscolhido <= intervaloMax)
        {
            break;
        }
        printf("Intervalo inválido! Digite novamente: ");
    }

    int hora, min;

    while (1)
    {
        printf("Dia: ");
        scanf("%d", &*dia);
        printf("Mes: ");
        scanf("%d", &*mes);
        printf("Ano: ");
        scanf("%d", &*ano);
        printf("Nós trabalhamos das 8h às 16h\n");
        printf("Escolha a hora que você ser atendido: ");
        int choice;
        hora = 0;
        while (hora == 0)
        {
            printf("\n1 - 8h\n2 - 9h\n3 - 10h\n4 - 11h\n5 - 12h\n6 - 13h\n7 - 14h\n8 - 15h\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                hora = 8;
                break;
            case 2:
                hora = 9;
                break;
            case 3:
                hora = 10;
                break;
            case 4:
                hora = 11;
                break;
            case 5:
                hora = 12;
                break;
            case 6:
                hora = 13;
                break;
            case 7:
                hora = 14;
                break;
            case 8:
                hora = 15;
                break;
            default:
                hora = 0;
                printf("Valor inválido!\n");
                break;
            }
        }
        min = 5;
        while (min == 5)
        {
            printf("1 - %d:00\n2 - %d:30\n", hora, hora);
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                min = 0;
                break;
            case 2:
                min = 30;
                break;
            default:
                min = 5;
                break;
            }
        }
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
            while (validarData(*dia, *mes, *ano, escolha, hora, min, nome))
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
            break;
        }
        int proximoDia = *dia;
        int proximoMes = *mes;
        int proximoAno = *ano;
        if (!validarData(*dia, *mes, *ano, escolha, hora, min, nome))
        {
            printf("\n");
            for (int i = 1; i < procedimentos[escolha - 1].numVezes; i++)
            {
                proximoDia += intervaloEscolhido;

                if (proximoDia > 30 && (proximoMes == 4 || proximoMes == 6 || proximoMes == 9 || proximoMes == 11))
                {
                    proximoDia = proximoDia - 30;
                    proximoMes++;
                }
                else if ((proximoMes == 2 && proximoDia > 28 && !ehBissexto(proximoAno)) || (proximoMes == 2 && proximoDia > 29 && ehBissexto(proximoAno)))
                {
                    proximoDia = proximoDia - 28;
                    proximoMes++;
                }
                else if (proximoDia > 31)
                {
                    proximoDia = proximoDia - 31;
                    proximoMes++;
                }

                if (proximoMes > 12)
                {
                    proximoMes = proximoMes - 12;
                    proximoAno++;
                }

                proximoDia = encontrarProximoDiaUtil(proximoDia, proximoMes, proximoAno);

                if (!validarData(proximoDia, proximoMes, proximoAno, escolha, hora, min, nome))
                {
                    printf("Proxima Consulta para %02d/%02d/%d às %02d:%02d\n", proximoDia, proximoMes, proximoAno, hora, min);
                }
            }
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

    printf("Olá, Sr(a). %s. Você gostaria de realizar qual procedimento?\n", nome);
    int escolha;
    int flag = 0;
    while (flag == 0)
    {
        printf("1 - Tratamento de Acne\n2 - Tratamento para Hipertrofia\n3 - Tratamento de Queloides\n4 - Tratamento de Micoses\n");
        printf("5 - Tratamento de Varizes\n6 - Consulta\n");
        scanf("%d", &escolha);
        flag = 1;
        if (escolha < 1 || escolha > 6)
        {
            flag = 0;
            printf("Opção inválida!\n");
        }
    }
    printf("Agora escolha a data de sua consulta\n");
    escolhaData(&dia, &mes, &ano, escolha, nome); // TODO: COLOCAR A DOENÇA NA ESCOLHA DA DATA E LINKAR COM OS MÉDICOS

    printf("Sr. %s sua consulta está marcada para %02d/%02d/%d\n", nome, dia, mes, ano);
}
int main()
{
    int escolha;
    printf("Bem vindo à clínica Boa Estética!\n");
    printf("Você gostaria de:\n1 - Marcar consulta\n2 - Cadastrar como médico\n3 - Sair\n");
    scanf("%d", &escolha);
    getchar();
    if (escolha == 1)
    {
        programaPaciente();
    }
    else if (escolha == 2)
    {
        programaMedico();
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
