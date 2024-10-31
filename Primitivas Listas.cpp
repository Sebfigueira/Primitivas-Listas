#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
};

void menu();
void insertar_lista(Node *&, int);
void imprimir_lista(Node *);
void buscar_lista(Node *, int);
void eliminar_elemento_lista(Node *&, int);
void eliminar_lista_entera(Node *&);

Node *lista = NULL;

int main(){
    
    menu();
}

void menu(){
    int option, value;
    do{
        cout<<"\tMENU\n";
        cout<<"1. Agregar elemento a la lista\n";
        cout<<"2. Imprimir los elementos de la lista\n";
        cout<<"3. Buscar un elemento de la lista\n";
        cout<<"4. Eliminar un elemento de la lista\n";
        cout<<"5. Eliminar la lista entera\n";
        cout<<"6. Salir\n";
        cout<<"\n";
        cin>>option;

        switch(option){
            case 1: cout<<"Escriba el elemento que quiere ingresar\n";
                    cin>>value;
                    insertar_lista(lista,value);
                    break;
            
            case 2: imprimir_lista(lista);
                    break;

            case 3: cout<<"Escriba el elemento que quiere buscar\n";
                    cin>>value;
                    buscar_lista(lista,value);    
                    break; 

            case 4: cout<<"Escriba el elemento que quiere eliminar\n";
                    cin>>value;
                    eliminar_elemento_lista(lista,value);
                    break;

            case 5: eliminar_lista_entera(lista);
                    break;
        }
    }while(option!=6);
    
}

void insertar_lista(Node *&lista,int n){
    Node *new_node = new Node;
    new_node->value = n;
    Node *aux1 = lista;
    Node *aux2;

    while (aux1!=NULL){
        aux2 = aux1;
        aux1=aux1->next;
    }

    if(lista==aux1){
        lista=new_node;
    }
    else{
        aux2->next=new_node;
    }
    new_node->next=aux1;
}

void imprimir_lista(Node *lista){
    Node *p = lista;
    while(p!=NULL){
        cout<<p->value<<" -> ";
        p=p->next;
    }
}

void buscar_lista(Node *lista,int n){
    bool bandera = false;
    Node *p = lista;

    while(p!=NULL){
        if(p->value==n){
            bandera = true;
        }
        p=p->next;
    }

    if(bandera){
        cout<<"El elemento que estas buscando SI esta\n";
        cout<<"\n";
    }
    else{
        cout<<"El elemento que estas buscando NO esta\n";
        cout<<"\n";
    }
}

void eliminar_elemento_lista(Node *&lista, int n){
    if (lista!=NULL){
        Node *aux1 = lista;
        Node *aux2 = NULL;

        while((aux1!=NULL)&&(aux1->value!=n)){
            aux2=aux1;
            aux1=aux1->next;
        }

        if(aux1==NULL){
            cout<<"El elemento no se ha encontrado\n";
            cout<<"\n";
        }
        else if(lista==aux1){
            lista=lista->next;
            delete aux1;
        }
        else{
            aux2->next=aux1->next;
            delete aux1;
            cout<<"Eliminado exitosamente\n";
            cout<<"\n";
        }
    }
}

void eliminar_lista_entera(Node *&lista){
    if(lista!=NULL){
        Node *aux1 = lista;
        while(aux1!=NULL){
            lista=lista->next;
            delete aux1;
            aux1=lista;
        }
        cout<<"Eliminado exitosamente\n";
        cout<<"\n";
    }
}