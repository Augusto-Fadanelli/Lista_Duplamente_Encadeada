#include <iostream>
#include <locale> // para o setlocale
#include <stdlib.h> // para o system("cls"); (So funciona no windows) // para o malloc

//Verifica se o SO é GNU/Linux ou Windows
#ifdef _unix_

	#define OS_UNIX

#elif defined(_WIN32) || defined(WIN32)

	#define OS_WINDOWS

#endif

using std::cout;
using std::cin;
using std::endl;

typedef struct no{
    int value;
    struct no *prev;
    struct no *next;
}no;

int menu();

void insert_inHead(no **);
void insert_inTail(no *, no **);

void toList_atHead(no *, no **);

void clear();
void pause();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    no *head = NULL;
    //no *tail = NULL;

    int flag = 0;

    do{
        switch(menu()){
        case 1:
        //Inserir no início
            insert_inHead(&head);

        break;
        case 2:
        //Inserir no final
            insert_inTail(head, &head);

        break;
        case 3:
        //Inserir por posição
        break;
        case 4:
        //Excluir
        break;
        case 5:
        //Listar como lista
            toList_atHead(head, &head);
            pause();
        break;
        case 6:
        //Listar como pilha
        break;
        case 7:
        //Sair
            flag = 1;
        break;
        default:
            cout << "Opção Inválida!" << endl;
            pause();
        }

        clear();

    }while(flag !=1);

    return 0;
}

void insert_inHead(no **head)
{
    int value;
    cout << "Digite o inteiro a ser inserido: ";
    cin >> value;

    no *aux = (no *)malloc(sizeof(no));

    aux->value = value;
    aux->next = *head;
    aux->prev = NULL;

    /*if(*head == NULL){
        *tail = aux;
    }*/

    *head = aux;
}

void insert_inTail(no *aux, no **head)
{
    int value;
    cout << "Digite o inteiro a ser inserido: ";
    cin >> value;

    no *novo = (no *)malloc(sizeof(no));

    if(*head != NULL)
    while(aux->next != NULL){
        //aux percorre até o final
    }


    novo->value = value;
    novo->next = NULL;
    novo->prev = aux;
}

void toList_atHead(no *aux, no **head)
{
    if(*head = NULL){
        cout << "Lista Vazia!" << endl;
        pause();
    }else{
        int cont = 0;
        do{
            cont++;
            cout << "[" << cont << "º] " << aux->value << " | ";
            aux = aux->next;
        }while(aux != NULL);
    }


}

int menu(){
    int op;

    cout << "***LISTA DUPLAMENTE ENCADEADA***" << endl;
    cout << "[1] - Inserir no Início" << endl;
    cout << "[2] - Inserir no Final" << endl;
    cout << "[3] - Inserir por Posição" << endl;
    cout << "[4] - Excluir" << endl;
    cout << "[5] - Listar do Início" << endl;
    cout << "[6] - Listar do Final" << endl;
    cout << "[7] - Sair" << endl;
    cin >> op;

    return op;
}

void clear(){

	#ifdef OS_WINDOWS
	// Codigo Windows
		system("cls");
	#else
    //Codigo GNU/Linux
		system("clear");
	#endif
}

void pause(){

    #ifdef OS_WINDOWS
    // Codigo Windows
        system("pause");
    #else
    // Codigo GNU/Linux
        cout << "Pressione qualquer tecla para continuar...";
        getchar();
    #endif

}
