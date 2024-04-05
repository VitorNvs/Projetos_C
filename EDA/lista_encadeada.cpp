#include <iostream>

using namespace std;

typedef struct no{
    int valor;
    no* prox;
}No;

typedef struct Lista{
    No* p;
    int qtd;
}Lista;

void printarLista(Lista list){
    cout << "\n";
    for(int i = 0; i < list.qtd; i++){
        No *aux = list.p;
        cout << aux->valor << " ";
        aux = aux->prox;
    }
    cout << "\n";
}

void inserirFim(Lista *list, int valor){
    No *node = new No;
    if(list->qtd == 0){
        list->p = node;
    }else{
        No *aux = list->p;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = node; 
    }
    list->qtd++;
    node->valor = valor;
}

void apagarComeco(Lista *list){
    No *aux = list->p;
    list->p = aux->prox;
    delete aux; 
    list->qtd--;
}

int main(){
    Lista list;
    list.qtd = 0;

    int res;

    do{
        cout << "LISTA ENCADEADA\n\n[ 1 ] Ver lista\n[ 2 ] Adicionar no fim\n[ 3 ] Apagar do inicio\n[ 4 ] SAIR\n";
        cout << "Opção escolhida: ";
        cin >> res;
        int valor;

        switch(res){
            case 1:
                printarLista(list);
                break;
            case 2:
                cout << "Valor a ser inserido: ";
                cin >> valor;
                inserirFim(&list, valor);
                break;
            case 3:
                apagarComeco(&list);
                cout << "Elemento apagado.\n";
            case 4:
                break;
            default:
                cout << "Escolha uma opção válida!\n";
        }
    }while(res != 4);
    
    while(list.p != NULL){
        apagarComeco(&list);
    }
}
