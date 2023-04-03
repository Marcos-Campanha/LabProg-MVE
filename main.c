// Aluno Marcos Paulo de Souza Campanha
// Aluno João Vitor Rodrigues Cortines Laxe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    int codigo;
    char *nome;
    char *cpf;

    struct Aluno *next;
} aluno;

typedef struct Disciplina
{
    int codigo, creditos;
    char *nome, *professor;

    struct Disciplina *next;
} disciplina;

typedef struct CadastroAD
{
    char num_periodo[7];

    struct Aluno *aluno;
    struct Disciplina *disciplina;
    struct Periodo *next;
} cadastroAD;

typedef struct lista_alunos
{
    aluno *head, *tail;

    int tamanho;
} lista_alunos;

typedef struct lista_disciplinas
{
    disciplina *head, *tail;

    int tamanho;
} lista_disciplinas;

typedef struct lista_cadastroad
{
    cadastroAD *head, *tail;

    int tamanho;
} lista_cadastroad;

aluno *novo_aluno(int codigo, char *nome, char *cpf)
{
    aluno *novo_aluno = malloc(sizeof *novo_aluno);

    novo_aluno->codigo = codigo;
    strcpy(novo_aluno->nome, nome);
    strcpy(novo_aluno->cpf, cpf);
    novo_aluno->next = NULL;

    return novo_aluno;
}

disciplina *nova_disciplina(int codigo, int creditos, char *nome, char *professor)
{
    disciplina *nova_disciplina = malloc(sizeof *nova_disciplina);

    nova_disciplina->codigo = codigo;
    nova_disciplina->creditos = codigo;
    nova_disciplina->nome = malloc(sizeof(nome) + 1);
    strcpy(nova_disciplina->nome, nome);
    nova_disciplina->professor = malloc(sizeof(professor) + 1);
    strcpy(nova_disciplina->professor, professor);
    nova_disciplina->next = NULL;

    return nova_disciplina;
}

cadastroAD *novo_cadastroAD(char num_periodo[7], aluno *og_aluno, disciplina *og_disciplina)
{
    cadastroAD *novo_cadastroAD = malloc(sizeof *novo_cadastroAD);

    strcpy(novo_cadastroAD->num_periodo, num_periodo);
    novo_cadastroAD->aluno = og_aluno;
    novo_cadastroAD->disciplina = og_disciplina;
    novo_cadastroAD->next = NULL;

    return novo_cadastroAD;
}

void inserir_aluno(lista_alunos *listaalunos, int codigo, char *nome, char *cpf)
{
    aluno *novo_aluno = malloc(sizeof(aluno));

    novo_aluno->codigo = codigo;
    novo_aluno->nome = malloc(sizeof(nome) + 1);
    strcpy(novo_aluno->nome, nome);
    novo_aluno->cpf = malloc(sizeof(cpf) + 1);
    strcpy(novo_aluno->cpf, cpf);
    novo_aluno->next = NULL;

    if(listaalunos->head == NULL)
    {
        listaalunos->head = novo_aluno;
        listaalunos->tail = novo_aluno;
    }
    else
    {
        listaalunos->tail->next = novo_aluno;
        listaalunos->tail = novo_aluno;
    }

    listaalunos->tamanho++;

    return;
}

void inserir_disciplina(lista_disciplinas *listadisciplinas, int codigo, int creditos, char *nome, char *professor)
{
    disciplina *nova_disciplina = malloc(sizeof *nova_disciplina);

    nova_disciplina->codigo = codigo;
    nova_disciplina->creditos = creditos;
    nova_disciplina->nome = malloc(sizeof(nome) + 1);
    strcpy(nova_disciplina->nome, nome);
    nova_disciplina->professor = malloc(sizeof(professor) + 1);
    strcpy(nova_disciplina->professor, professor);
    nova_disciplina->next = NULL;

    if(listadisciplinas->head == NULL)
    {
        listadisciplinas->head = nova_disciplina;
        listadisciplinas->tail = nova_disciplina;
    }
    else
    {
        listadisciplinas->tail->next = nova_disciplina;
        listadisciplinas->tail = nova_disciplina;
    }

    listadisciplinas->tamanho++;

    return;
}

void inserir_cadastroad(lista_cadastroad *listacadastroad, char *periodo, aluno *og_aluno, disciplina *og_disciplina)
{

    cadastroAD *novo_cadastroAD = malloc(sizeof *novo_cadastroAD);

    strcpy(novo_cadastroAD->num_periodo, periodo);
    novo_cadastroAD->aluno = og_aluno;
    novo_cadastroAD->disciplina = og_disciplina;
    novo_cadastroAD->next = NULL;

    if(listacadastroad->head == NULL)
    {
        listacadastroad->head = novo_cadastroAD;
        listacadastroad->tail = novo_cadastroAD;
    }
    else
    {
        listacadastroad->tail->next = novo_cadastroAD;
        listacadastroad->tail = novo_cadastroAD;
    }

    listacadastroad->tamanho++;

    return;
}

void remover_aluno(lista_alunos *listaalunos, int codigo)
{
    aluno *tmp = listaalunos->head;
    aluno *rem = NULL;

    if (tmp != NULL && listaalunos->head->codigo == codigo)
    {
        rem = listaalunos->head;
        listaalunos->head = rem->next;
    }
    else
    {
        while (tmp != NULL && tmp->next != NULL && tmp->next->codigo != codigo)
        {
            tmp = tmp->next;
        }

        if (tmp != NULL && tmp->next != NULL)
        {
            rem = tmp->next;
            tmp->next = rem->next;
        }

        if (rem)
        {
            free(rem);
            listaalunos->tamanho--;
        }
    }
}

void remover_disciplina(lista_disciplinas *listadisciplinas, int codigo)
{
    disciplina *tmp = listadisciplinas->head;
    disciplina *rem = NULL;

    if (tmp != NULL && listadisciplinas->head->codigo == codigo)
    {
        rem = listadisciplinas->head;
        listadisciplinas->head = rem->next;
    }
    else
    {
        while (tmp != NULL && tmp->next != NULL && tmp->next->codigo != codigo)
        {
            tmp = tmp->next;
        }

        if (tmp != NULL && tmp->next != NULL)
        {
            rem = tmp->next;
            tmp->next = rem->next;
        }

        if (rem)
        {
            free(rem);
            listadisciplinas->tamanho--;
        }
    }
}

void imprimir_alunos(lista_alunos *listaalunos)
{
    aluno *tmp = listaalunos->head;

    while(tmp != NULL)
    {
        printf("\t\t\t\t- Nome do aluno: %s | Codigo do aluno: %d | CPF do aluno: %s\n", tmp->nome, tmp->codigo, tmp->cpf);
        tmp = tmp->next;
    }
}

aluno *buscar_aluno(lista_alunos *listaalunos, int codigo)
{
    aluno *tmp = listaalunos->head;

    while (tmp != NULL)
    {
        if (tmp->codigo == codigo) return tmp;

        tmp = tmp->next;
    }

    return NULL;
}

disciplina *buscar_disciplina(lista_disciplinas *listadisciplinas, int codigo)
{
    disciplina *tmp = listadisciplinas->head;

    while (tmp != NULL)
    {
        if (tmp->codigo == codigo) return tmp;

        tmp = tmp->next;
    }

    return NULL;
}

void print_alunosdisc(cadastroAD *cadastro, disciplina *og_disciplina, char *num_periodo)
{
    cadastroAD *tmp = cadastro;

    printf("\n\t\t\t\t--- Alunos matriculados na disciplina %s, em %s ---\n", og_disciplina->nome, num_periodo);

    while (tmp != NULL)
    {
        if (tmp->disciplina->codigo == og_disciplina->codigo && strcmp(tmp->num_periodo, num_periodo) == 0) printf("\n\t\t\t\t=> Aluno: %s | Codigo: %d | CPF: %s", tmp->aluno->nome, tmp->aluno->codigo, tmp->aluno->cpf);

        tmp = tmp->next;
    }

    printf("\n\n\n");
}

void print_discsaluno(cadastroAD *cadastro, aluno *og_aluno, char *num_periodo)
{
    cadastroAD *tmp = cadastro;

    printf("\n\t\t\t\t--- Disciplinas cursadas pelo aluno %s, em %s ---\n", og_aluno->nome, num_periodo);

    while (tmp != NULL)
    {
        if (tmp->aluno->codigo == og_aluno->codigo && strcmp(tmp->num_periodo, num_periodo) == 0) printf("\n\t\t\t\t=> Disciplina: %s | Codigo: %d | Total de creditos: %d | Professor: %s", tmp->disciplina->nome, tmp->disciplina->codigo, tmp->disciplina->creditos, tmp->disciplina->professor);

        tmp = tmp->next;
    }

    printf("\n\n\n");
}

void print_alunos(lista_alunos *listaalunos)
{
    aluno *tmp = listaalunos->head;

    printf("\n\t\t\t\t--- Todos os alunos matriculados ---\n");

    while (tmp != NULL)
    {
        printf("\n\t\t\t\t=> Aluno %s | Codigo %d | CPF %s", tmp->nome, tmp->codigo, tmp->cpf);

        tmp = tmp->next;
    }

    printf("\n\n\n");
}

void print_disciplinas(lista_disciplinas *listadisciplinas)
{
    disciplina *tmp = listadisciplinas->head;

    printf("\n\t\t\t\t--- Todas as disciplinas ministradas ---\n");

    while (tmp != NULL)
    {
        printf("\n\t\t\t\t=> Disciplina: %s | Codigo: %d | Total de creditos: %d | Professor: %s", tmp->nome, tmp->codigo, tmp->creditos, tmp->professor);

        tmp = tmp->next;
    }

    printf("\n\n\n");
}

/*void remover_alunodisc(lista_cadastroad *listacadastro, char *num_periodo, aluno *og_aluno, disciplina *og_disciplina)
{
    cadastroAD *tmp = listacadastro->head;
    cadastroAD *rem = NULL;

    if (tmp != NULL && tmp->next!=NULL && (listacadastro->head->aluno == og_aluno || listacadastro->head->disciplina == og_disciplina || listacadastro->head->num_periodo == num_periodo))
    {
        rem = listacadastro->head;
        listacadastro->head = rem->next;
    }
    else
    {
        while (tmp != NULL && tmp->next != NULL && tmp->next->aluno != og_aluno && tmp->next->disciplina != og_disciplina && tmp->next->num_periodo != num_periodo)
        {
            tmp = tmp->next;
        }

        if (tmp != NULL && tmp->next != NULL)
        {
            rem = tmp->next;
            tmp->next = rem->next;
        }

        if (rem)
        {
            free(rem);
            listacadastro->tamanho--;
        }
    }
}*/

void salvar_dados(lista_alunos listaalunos, lista_disciplinas listadisciplinas, lista_cadastroad listacadastroad)
{
    FILE *arquivo = fopen("arquivo.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    aluno *al_tmp = listaalunos.head;
    fprintf(arquivo, "Alunos\n");
    while (al_tmp != NULL)
    {
        fprintf(arquivo, "%s;%d;%s\n", al_tmp->nome, al_tmp->codigo, al_tmp->cpf);
        al_tmp = al_tmp->next;
    }

    disciplina *disciplina_tmp = listadisciplinas.head;
    fprintf(arquivo, "Disciplinas\n");
    while (disciplina_tmp != NULL)
    {
        fprintf(arquivo, "%s;%d;%d;%s\n", disciplina_tmp->nome, disciplina_tmp->codigo, disciplina_tmp->creditos, disciplina_tmp->professor);
        disciplina_tmp = disciplina_tmp->next;
    }

    cadastroAD *cadastro_tmp = listacadastroad.head;
    fprintf(arquivo, "Cadastros\n");
    while (cadastro_tmp != NULL)
    {
        fprintf(arquivo, "%s;%d;%d\n", cadastro_tmp->num_periodo, cadastro_tmp->aluno->codigo, cadastro_tmp->disciplina->codigo);
        cadastro_tmp = cadastro_tmp->next;
    }
    fclose(arquivo);
    printf("\n\t\t\t\t***Dados salvos com sucesso***\n\n\n");
}

void recuperar_dados(lista_alunos *listaalunos, lista_disciplinas *listadisciplinas, lista_cadastroad *listacadastroad)
{
    FILE *arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo de dados\n");
        return;
    }

    int codigo_al, codigo_disc = 0, creditos = 0, alunos_tamanho = 0, disciplinas_tamanho = 0, cadastroad_tamanho = 0;
    char nome_al[50], nome_disc[50], cpf[15], professor[50], num_periodo[7], buffer[200];

    while(1)
    {
        fscanf(arquivo, "%[^\n]\n", buffer);

        if(strcmp(buffer, "Disciplinas") == 0)
        {
            break;
        }

        alunos_tamanho++;
    }

    while(1)
    {
        fscanf(arquivo, "%[^\n]\n", buffer);

        if(strcmp(buffer, "Cadastros") == 0)
        {
            break;
        }

        disciplinas_tamanho++;
    }

    while(fscanf(arquivo, "%[^\n]\n", buffer) != EOF)
    {
        cadastroad_tamanho++;
    }

    fclose(arquivo);
    FILE *narquivo = fopen("arquivo.txt", "r");

    fgets(buffer, 200, narquivo);

    for(int i = 0; i < alunos_tamanho - 1; i++)
    {
        fscanf(narquivo, "%[^;];%d;%s", nome_al, &codigo_al, cpf);
        inserir_aluno(listaalunos, codigo_al, nome_al, cpf);
    }

    fgets(buffer, 200, narquivo);
    fgets(buffer, 200, narquivo);

    for(int i = 0; i < disciplinas_tamanho; i++)
    {
        fscanf(narquivo, "%[^;];%d;%d;%s\n", nome_disc, &codigo_disc , &creditos, professor);
        inserir_disciplina(listadisciplinas, codigo_disc, creditos, nome_disc, professor);
    }

    fgets(buffer, 200, narquivo);

    for(int i = 0; i < cadastroad_tamanho; i++)
    {
        fscanf(narquivo, "%[^;];%d;%d\n", num_periodo, &codigo_al , &codigo_disc);
        aluno *aluno_busca = buscar_aluno(listaalunos, codigo_al);
        disciplina *disciplina_busca = buscar_disciplina(listadisciplinas, codigo_disc);

        inserir_cadastroad(listacadastroad, num_periodo, aluno_busca, disciplina_busca);
    }

    fclose(narquivo);

    printf("\n\t\t\t\t***Dados recuperados com sucesso***\n");
}

void menu()
{
    printf("\n\t\t\t========================= MENU DE REGISTRO =========================\n\n");
    printf("\t\t\t\t0. Sair do programa\n");
    printf("\t\t\t\t1. Cadastrar novo aluno\n");
    printf("\t\t\t\t2. Cadastrar nova disciplina\n");
    printf("\t\t\t\t3. Cadastrar aluno em uma disciplina\n");
    printf("\t\t\t\t4. Consultar alunos matriculados em uma disciplina\n");
    printf("\t\t\t\t5. Consultar todos os alunos matriculados\n");
    printf("\t\t\t\t6. Consultar disciplinas cursadas por um aluno\n");
    printf("\t\t\t\t7. Consultar todas as disciplinas ministradas\n");
    printf("\t\t\t\t8. Remover aluno de uma disciplina\n");
    printf("\t\t\t\t9. Remover o cadastro de um aluno\n");
    printf("\t\t\t\t10. Remover o cadastro de uma disciplina\n");
    printf("\t\t\t\t11. Salvar dados\n");
    printf("\t\t\t\t12. Recuperar dados\n");
    printf("\t\t\t\t__________________________________________________\n");
    printf("\t\t\t\tDigite a opcao desejada: ");
}

int main()
{
    lista_alunos listaalunos = {NULL, NULL, 0};
    lista_disciplinas listadisciplinas = {NULL, NULL, 0};
    lista_cadastroad listacadastroad = {NULL, NULL, 0};

    int choice = 13;

    do
    {
        switch(choice)
        {
        case 1:
        {
            int codigo = 0;
            char *nome, *buffer_nome, *cpf, *buffer_cpf;
            nome = (char *)malloc(50 * sizeof(char));
            cpf = (char *)malloc(15 * sizeof(char));

            printf("\n\t\t\t\tDigite o codigo do aluno: ");
            scanf("%5d", &codigo);
            fflush(stdin);

            printf("\t\t\t\tDigite o nome do aluno: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            buffer_nome = (char *)malloc(strlen(nome) + 1);
            strcpy(buffer_nome, nome);

            printf("\t\t\t\tDigite o CPF do aluno: ");
            fgets(cpf, 15, stdin);
            cpf[strcspn(cpf, "\n")] = '\0';
            buffer_cpf = (char *)malloc(strlen(cpf) + 1);
            strcpy(buffer_cpf, cpf);

            inserir_aluno(&listaalunos, codigo, buffer_nome, buffer_cpf);

            system("cls");

            printf("\n\t\t\t\t*** O aluno foi cadastrado com sucesso ***\n");

            free(nome);
            free(buffer_nome);
            free(cpf);
            free(buffer_cpf);
        } break;

        case 2:
        {
            int codigo = 0, creditos = 0;
            char *nome, *buffer_nome, *professor, *buffer_professor;
            nome = (char *)malloc(50 * sizeof(char));
            professor = (char *)malloc(50 *sizeof(char));

            printf("\n\t\t\t\tDigite o nome da disciplina: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            buffer_nome = (char *)malloc(strlen(nome) + 1);
            strcpy(buffer_nome, nome);

            printf("\t\t\t\tDigite o codigo da disciplina: ");
            scanf("%5d", &codigo);
            fflush(stdin);

            printf("\t\t\t\tDigite o numero de creditos da disciplina: ");
            scanf("%d", &creditos);
            fflush(stdin);

            printf("\t\t\t\tDigite o nome do professor da disciplina: ");
            fgets(professor, 50, stdin);
            professor[strcspn(professor, "\n")] = '\0';
            buffer_professor = (char *)malloc(strlen(professor) + 1);
            strcpy(buffer_professor, professor);

            inserir_disciplina(&listadisciplinas, codigo, creditos, buffer_nome, buffer_professor);

            free(nome);
            free(buffer_nome);
            free(professor);
            free(buffer_professor);

            system("cls");

            printf("\n\t\t\t\t*** A disciplina foi cadastrada com sucesso ***\n");
        } break;

        case 3:
        {
            int cod_al = 0, cod_disc = 0;
            char num_periodo[7];

            printf("\n\t\t\t\tDigite o codigo do aluno: ");
            scanf("%5d", &cod_al);

            printf("\t\t\t\tDigite o codigo da disciplina: ");
            scanf("%5d", &cod_disc);

            fflush(stdin);
            printf("\t\t\t\tDigite o periodo em que a disciplina eh cursada pelo aluno: ");
            fgets(num_periodo, 7, stdin);
            num_periodo[strcspn(num_periodo, "\n")] = '\0';

            aluno *aluno_busca = buscar_aluno(&listaalunos, cod_al);
            disciplina *disciplina_busca = buscar_disciplina(&listadisciplinas, cod_disc);

            system("cls");

            if (aluno_busca != NULL && disciplina_busca != NULL)
            {
                inserir_cadastroad(&listacadastroad, num_periodo, aluno_busca, disciplina_busca);
                printf("\n\t\t\t\t***Cadastro realizado com sucesso!***\n");
            }
            else if (aluno_busca == NULL && disciplina_busca != NULL) printf("\n\t\t\t\t***Nao existe aluno com esse codigo!***\n");
            else if (aluno_busca != NULL && disciplina_busca == NULL) printf("\n\t\t\t\t***Nao existe disciplina com esse codigo!***\n");
            else printf("\n\t\t\t\t***Nao existem nem aluno nem disciplina com esses codigos!***\n");
        } break;

        case 4:
        {
            int codigo = 0;
            char num_periodo[7];

            printf("\n\t\t\t\tDigite o codigo da disciplina: ");
            scanf("%5d", &codigo);
            fflush(stdin);

            printf("\t\t\t\tDigite o periodo que deseja consultar os alunos: ");
            fgets(num_periodo, 7, stdin);
            num_periodo[strcspn(num_periodo, "\n")] = '\0';

            disciplina *disciplina_busca = buscar_disciplina(&listadisciplinas, codigo);

            system("cls");

            if (disciplina_busca != NULL)
            {
                print_alunosdisc(listacadastroad.head, disciplina_busca, num_periodo);
            }
            else
            {
                printf("\n\t\t\t\t***Nao existe disciplina com esse codigo***\n");
            }
        } break;

        case 5:
        {
            print_alunos(&listaalunos);
        } break;

        case 6:
        {
            int codigo;
            char num_periodo[7];

            printf("\n\t\t\t\tDigite o codigo do aluno: ");
            scanf("%5d", &codigo);
            fflush(stdin);

            printf("\t\t\t\tDigite o periodo que deseja consultar as disciplinas do aluno: ");
            fgets(num_periodo, 7, stdin);
            num_periodo[strcspn(num_periodo, "\n")] = '\0';

            aluno *aluno_busca = buscar_aluno(&listaalunos, codigo);

            system("cls");

            if (aluno_busca != NULL)
            {
                print_discsaluno(listacadastroad.head, aluno_busca, num_periodo);
            }
            else
            {
                printf("\n\t\t\t\t***Código inválido de aluno***\n");
            }
        } break;

        case 7:
        {
            print_disciplinas(&listadisciplinas);
        } break;

        case 8:
        {

        } break;

        case 9:
        {
            int codigo = 0;

            printf("\n\t\t\t\tDigite o codigo do aluno: ");
            scanf("%5d", &codigo);

            aluno *aluno_busca = buscar_aluno(&listaalunos, codigo);

            system("cls");

            if (aluno_busca != NULL)
            {
                remover_aluno(&listaalunos, aluno_busca->nome);

                printf("\n\t\t\t\t***O aluno %s foi removido com sucesso***\n", aluno_busca->nome);
            }
            else printf("\n\t\t\t\t***Nao ha aluno com esse codigo!***\n");
        } break;

        case 10:
        {
            int codigo = 0;

            printf("\n\t\t\t\tDigite o codigo da disciplina: ");
            scanf("%5d", &codigo);

            disciplina *disciplina_busca = buscar_disciplina(&listadisciplinas, codigo);

            if (disciplina_busca != NULL)
            {
                remover_disciplina(&listadisciplinas, disciplina_busca->nome);

                printf("\n\t\t\t\t***A disciplina %s foi removida com sucesso***\n\n\n", disciplina_busca->nome);
            }
            else printf("\n\t\t\t\t***Nao ha disciplina com esse codigo!***\n\n\n");
        } break;

        case 11:
        {
            salvar_dados(listaalunos, listadisciplinas, listacadastroad);
        } break;

        case 12:
        {
            recuperar_dados(&listaalunos, &listadisciplinas, &listacadastroad);
        } break;

        default:
            break;
        }

        menu();
        scanf("%d", &choice);
        fflush(stdin);
    } while(choice != 0);

    return 0;
}
