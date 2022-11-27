#include <stdio.h>

struct No{
    int dado;
    struct No *prox;
}*inicio = NULL;

int inserir(int valor){
    struct No *novo;

    novo = new struct No();
    novo -> dado = valor;
    novo -> prox = inicio;
    inicio = novo;

    return 0;
}

int inserir_final(int valor){
    struct No *novo, *aux = inicio;

    novo = new struct No();
    novo -> dado = valor;
    novo -> prox = NULL;

    if (aux == NULL){
        inicio = novo;
    }
    else{
        while (aux -> prox != NULL){
            aux = aux -> prox;
        }

        aux -> prox = novo;
    }

    return 0;
}

int imprimir(){
    struct No *aux = inicio;

    if (aux == NULL){
        printf("\nLista vazia!");
        return 0;
    }

    while (aux != NULL){
        printf(" %d ", aux -> dado);

        aux = aux -> prox;
    }

    return 0;
}

struct No* buscar(int valor){
    struct No *aux = inicio;

    if (aux == NULL){
        printf("\nLista vazia!");
    }
    else{
        while (aux != NULL){
            if (aux -> dado == valor){
                return aux;
            }

            aux = aux -> prox;
        }
    }
}

int alterar(int valor_substituido){
    struct No *temp = buscar(valor_substituido);
    int novo_valor;

    if (temp == NULL){
        printf("\nElemento nao encontrado!");
        return 0;
    }

    printf("Insira um valor para substituir o numero %d: ", valor_substituido);
    scanf("%d", &novo_valor);

    temp -> dado = novo_valor;
    return 0;
}

int deletar(){
    struct No *aux = inicio;

    if (aux == NULL){
        printf("\nLista vazia!");
        return 0;
    }

    while (aux != NULL){
        inicio = aux -> prox;
        delete aux;
        aux = inicio;
    }

    return 0;
}

int excluir_um_elemento(int valor){
    struct No *temp = buscar(valor), *aux = inicio;

    if (temp == NULL){
        printf("\nElemento nao encontrado!");
        return 0;
    }

    if (inicio == temp){
        inicio = temp -> prox;
    }
    else{
        while (aux -> prox != temp){
            aux = aux -> prox;
        }

        aux -> prox = temp -> prox;
    }

    return 0;
}

int inserir_ordenado(int valor){
    struct No *novo, *aux = inicio, *aux2 = inicio;

    novo = new struct No();
    novo -> dado = valor;

    if (aux == NULL){
        inicio = novo;
        novo -> prox = NULL;
        return 0;
    }

    while (aux != NULL){

        if (valor < aux -> dado && inicio == aux){
            inicio = novo;
            novo -> prox = aux;
            return 0;
        }
        else if (valor < aux -> dado){
            while (aux2 -> prox != aux){
                aux2 = aux2 -> prox;
            }

            aux2 -> prox = novo;
            novo -> prox = aux;
            return 0;
        }

        aux = aux -> prox;
    }

    while (aux2 -> prox != aux){
        aux2 = aux2 -> prox;
    }

    aux2 -> prox = novo;
    novo -> prox = NULL;
    return 0;
}

int main(){

     int opcao, numero;
    struct No *temp;

    do{

        printf("\n====================================\nEscolha a opcao desejada\n====================================\n");
        printf("\n1 - Inserir\n2 - Inserir no final\n3 - Imprimir\n4 - Buscar\n5 - Alterar\n6 - Deletar tudo\n7 - Deletar um elemento\n8 - Inserir ordenado\n9 - Finalizar\n");
        printf("Sua opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\nInsira o elemento que deseja inserir: ");
            scanf("%d", &numero);
            inserir(numero);
            break;
        case 2:
            printf("\nInsira o elemento que deseja inserir: ");
            scanf("%d", &numero);
            inserir_final(numero);
            break;
        case 3:
            imprimir();
            break;
        case 4:
            printf("\nQual elemento deseja buscar? ");
            scanf("%d", &numero);

            temp = buscar(numero);

            if (temp == NULL){
                printf("\nElemento nao encontrado.");
            }
            else{
                printf("\nO valor %d foi encontrado na posicao %p.", numero, temp);
            }
            break;
        case 5:
            printf("\nInsira o valor a ser subtituido: ");
            scanf("%d", &numero);
            alterar(numero);
            break;
        case 6:
            deletar();
            break;
        case 7:
            printf("\nInsira o elemento a ser deletado: ");
            scanf("%d", &numero);

            excluir_um_elemento(numero);
            break;
        case 8:
            printf("\nInsira o elemento que deseja inserir: ");
            scanf("%d", &numero);

            inserir_ordenado(numero);
            break;
        case 9:
            printf("\nFinalizando!");
            break;
        default:
            printf("Opcao invalida! Por favor, tente novamente.");
        }

    }while(opcao != 9);

    return 0;
}
