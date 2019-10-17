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

void clear();
void pause();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    no *head = NULL;
    no *tail = NULL;

    int flag = 0;

    do{
        switch(menu()){
        case 1:
        //Inserir

        break;
        case 2:
        //Inserir por posição
        break;
        case 3:
        //Excluir
        break;
        case 4:
        //Listar como lista
        break;
        case 5:
        //Listar como pilha
        break;
        case 6:
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

int menu(){
    int op;

    cout << "***LISTA DUPLAMENTE ENCADEADA***" << endl;
    cout << "[1] - Inserir" << endl;
    cout << "[2] - Inserir por Posição" << endl;
    cout << "[3] - Excluir" << endl;
    cout << "[4] - Listar como Lista" << endl;
    cout << "[5] - Listar como Pilha" << endl;
    cout << "[6] - Sair" << endl;
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
