#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//Variables enteras
int i,j; //iteradores id 
int op; //Número de opción
int n,m; //Cantidad de medicamento
int usuario; // Usario que el usuario va a ingresar
int password; // la contraseña que el usuario va a ingresar
int tamUsuario = 4;
int tamInv = 4;
int tamEli = 0;
int tamAgr = 0;
int tamEdi = 0;
int numUsuario, idProducto;
int check;
//Variables de texto
char medicamento[20]; //Nombre del medicamento



// Arreglos para verificar la identidad del usuario.
int idUsuario[4] = {10100,10101,10102,10103};
char nombreUsuario[4][10] = {"Ariel","Vanessa","Erick","Martín"};  
int passUsuario[4] = {12345,54321,32145,54123};

//Arreglos para los medicamentos.
char listaProductos[100][20] = {"Paracetamol","Ibuprofeno","Tukol","Omeprazol"};
int inventarioProductos [100] = {5,10,3,11};
int iniciales = 4;
char productosEliminados[100][20] = {};
char productosAgregados[100][20] = {};
char productosEditados[100][20] = {};

void OrderAsc(char producto[][20],int inventario[],int n){
    char aux[20]; //Variable auxiliar para almacenar el producto 
    int piv; 
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(producto[j]>producto[j+1]){
                //Organizar el producto
                //aux[20] = producto[j];
                strcpy(aux,producto[j]);
                //producto[j] = producto[j+1];
                strcpy(producto[j],producto[j+1]);
                //producto[j+1] = aux[20];
                strcpy(producto[j+1],aux);
                //Organizar la cantidad del producto
                piv = inventario[j];
                inventario[j] = inventario[j+1];
                inventario[j+1] = piv;                

            }
        }
    }

}

int busquedaUsuario(int num){
    n=-1;
    for(i=0;i < tamUsuario;i++){
        if (idUsuario[i] == num){
            n = i;
        }
    }
    return n;
}

int busquedaProducto(char medicamento[20]){
    n=-1;
    for(i=0;i < tamInv;i++){
        if (strcmp(listaProductos[i], medicamento) == 0){
            n = i;
        }   
    }
    if(n==-1){
            printf("El producto no está en el invenatrio.\n");
        }
    return n;
}

//Funciones requeridas
int verificarUsuario(){
    numUsuario=-1;
    check=1;
    do{
        printf("Ingrese su usuario:\n");
        scanf("%d",&usuario);
        printf("Ingrese la contraseña:\n");
        scanf("%d",&password);
        numUsuario = busquedaUsuario(usuario);
        if (numUsuario ==-1){
            printf("Usuario o contraseña inválidos.\n");
            check++;
        } else if (password != passUsuario[numUsuario]){
            printf("Usuario o contraseña inválidos.\n");
            check++;
        } else if(password == passUsuario[numUsuario]){
            printf("Bienvenid@ de nuevo, %s\n", nombreUsuario[numUsuario]);
            check = 5;
        }

    }while(check!=5);
    return numUsuario;
}

void agregarProducto(){
    // n es el tamaño del arreglo
    printf("¿Qué producto quieres agregar?\n");
    scanf("%s", medicamento);
    strcpy(listaProductos[tamInv],medicamento);
    strcpy(productosAgregados[tamAgr],listaProductos[tamInv]);
    tamAgr++;
    printf("¿Cuántas unidades agerga?\n");
    scanf("%d",&m);
    inventarioProductos[tamInv]=m;
    tamInv++;
}
//Ver como asifnar el valor de la variable con un FOR 

void editarProducto(n){
    //n es el tamaño del arreglo
    strcpy(productosEditados[tamEdi],listaProductos[n]);
    tamEdi++;
    printf("¿Qué desea cambiar del producto?\n");
    printf("1) El nombre del producto.\n");
    printf("2) La cantidad del producto\n");
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        printf("¿Cuál es el nuevo nombre del producto?\n");
        scanf("%s", medicamento);
        strcpy(listaProductos[n],medicamento);
        break;
    case 2:
        printf("¿Cuál es la nueva cantidad del producto?\n");
        scanf("%d", &m);
        inventarioProductos[n]=m;
        break;        
    
    default:
        printf("Opción no valida\n");
        break;
    }

}

void eliminarProducto(n){

strcpy(listaProductos[tamInv],listaProductos[n]);
inventarioProductos[tamInv] = inventarioProductos[n];

strcpy(productosEliminados[tamEli],listaProductos[tamInv]);
tamEli++;

for(i=n+1;i<tamInv;i++){
    strcpy(listaProductos[i-1],listaProductos[i]);
    inventarioProductos[i-1] = inventarioProductos[i];
}
tamInv--;
}

void mostarInventario(){
    printf("Producto:  -   Cantidad:\n");
    for(i=0;i<tamInv;i++){
        printf("%s -     %d\n",listaProductos[i],inventarioProductos[i]);
    }
}

void generarRecibo(){
    printf("FarmaosO\nBy Tirando Código.\n");
    printf("Trabajador: %s\n",nombreUsuario[numUsuario]);
    printf("---  Inventario  ---\n");
    mostarInventario();
    if(tamAgr !=0){
        printf("---  Productos agregados  ---\n");
        printf("Se agregaron %d productos.\n",tamAgr);
        printf("Productos:\n");
        for(i=0;i<tamAgr;i++){
            printf("%s\n",productosAgregados[i]);
        }
    }
    if(tamEdi !=0){
        printf("---  Productos eliminados  ---\n");
        printf("Se editaron %d productos.\n",tamEdi);
        printf("Productos:\n");
        for(i=0;i<tamEdi;i++){
            printf("%s\n",productosEditados[i]);
        }
    }

    if(tamEli !=0){
        printf("---  Productos eliminados  ---\n");
        printf("Se eliminaron %d productos.\n",tamEli);
        printf("Productos:\n");
        for(i=0;i<tamEli;i++){
            printf("%s\n",productosEliminados[i]);
        }
    }    

}



int main() {

// usuario = inicio();

numUsuario = verificarUsuario();
if(numUsuario !=-1){
do{
    printf("¿Qué deseas realizar?\n");
    printf("1) Agregar un producto.\n");
    printf("2) Editar un producto.\n");
    printf("3) Eliminar un producto.\n");
    printf("4) Mostrar inventario.\n");
    printf("5) Imprimir recibo.\n");
    printf("0) Salir.\n"); 
    scanf("%d",&op);
    system("clear");
    switch(op){
        case 1:
            agregarProducto();
        break;

        case 2:
            printf("Ingresa el nombre del producto que desea editar:\n");
            scanf("%s",medicamento);
            idProducto = busquedaProducto(medicamento);
            if(idProducto!=-1){
                editarProducto(idProducto);
            }
        break;

        case 3:
            printf("Ingresa el nombre del producto que desea eliminar:\n");
            scanf("%s",medicamento);
            idProducto = busquedaProducto(medicamento);
            if(idProducto!=-1){
                eliminarProducto(idProducto);
            } else{
                printf("Este producto no está en el inventario");
            }    
        break;

        case 4:
            mostarInventario();
        break;

        case 5:
            generarRecibo();
        break;

        case 0:
            printf("Hatsa luego, %s.\n",nombreUsuario[numUsuario]);
        break;    

        default:
            printf("Opción no valida\n");
        break;        




    }

}while(op!=0);
} else{
    printf("Número de intentos excedido.\n");
    printf("Hasta Luego.\n");
}   

return 0;
}