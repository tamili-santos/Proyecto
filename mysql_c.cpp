#include<mysql.h>
#include <iostream>
#include "Cliente.h"
using namespace std;

void crear_cliente();
void leer_cliente();
void borrar_cliente();
void actualizar_cliente();
int q_estado;
int main()
{
    string nombres, apellidos, nit, genero, correo_electronico, fecha_ingreso;
    int telefono = 0, id = 0, op = 0;
    Cliente c = Cliente(nombres, apellidos, telefono, nit, genero, correo_electronico, fecha_ingreso,id);
 
    cout << "Que desea realizar: " << endl;
    cout << "1. Crear cliente" << endl;
    cout << "2. Ver cliente" << endl;
    cout << "3. Borrar cliente" << endl;
    cout << "4. Actualizar cliente" << endl;
    cin >> op;
    cin.ignore();

    switch (op) {
    case 1:
        crear_cliente();
        break;
    case 2:
        leer_cliente();
        break;
    case 3:
        borrar_cliente();
        break;
    case 4:
        actualizar_cliente();
        break;
}
    return 0;
}

        void crear_cliente() {
        string nombres, apellidos, nit, genero, correo_electronico, fecha_ingreso;
        int telefono = 0, id = 0;
        cout << "Ingrese nombres: ";
        getline(cin, nombres);
        cout << "Ingrese apellidos: ";
        getline(cin, apellidos);
        cout << "Ingrese NIT: ";
        getline(cin, nit);
        cout << "Ingrese genero: ";
        getline(cin, genero);
        cout << "Ingrese telefono: ";
        cin >> telefono;
        cin.ignore();
        cout << "Ingrese correo electronico: ";
        getline(cin, correo_electronico);
        cout << "Ingrese fecha de ingreso: ";
        cin >> fecha_ingreso;

        
        Cliente nuevoCliente(nombres, apellidos, telefono, nit, genero, correo_electronico, fecha_ingreso, id);
        nuevoCliente.crear();
        system("pause");
    }

        void leer_cliente() {
            string nombres, apellidos, nit, genero, correo_electronico, fecha_ingreso;
            int telefono = 0, id=0;
            Cliente c = Cliente(nombres, apellidos, telefono, nit, genero, correo_electronico, fecha_ingreso, id);
            c.leer();
        }

        void borrar_cliente() {
            string nombres, apellidos, nit, genero, correo_electronico, fecha_ingreso;
            int telefono = 0, id = 0;
            cout << "Ingrese el ID que desea eliminar: ";
            cin >> id;
            Cliente c = Cliente(nombres, apellidos, telefono, nit, genero, correo_electronico, fecha_ingreso, id);
            c.borrar();
        }

        void actualizar_cliente() {
            string nombres, apellidos, nit, genero, correo_electronico, fecha_ingreso;
            int telefono = 0, id = 0;
            cout << "Ingrese el ID que desea actualizar: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese nombres: ";
            getline(cin, nombres);
            cout << "Ingrese apellidos: ";
            getline(cin, apellidos);
            cout << "Ingrese NIT: ";
            getline(cin, nit);
            cout << "Ingrese genero: ";
            getline(cin, genero);
            cout << "Ingrese telefono: ";
            cin >> telefono;
            cin.ignore();
            cout << "Ingrese correo electronico: ";
            getline(cin, correo_electronico);
            cout << "Ingrese fecha de ingreso: ";
            cin >> fecha_ingreso;
            Cliente c = Cliente(nombres, apellidos, telefono, nit, genero, correo_electronico, fecha_ingreso, id);
            c.actualizar();
        }

   /*
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_proyectof", "pr0yect0fin@l123", "db_proyectofinal", 3306, NULL, 0);
    if(conectar) {
        string puesto;
        cout << "Ingrese puesto: ";
        cin >> puesto;
        string insertar = "insert into puestos(puesto) values('" + puesto + "')";
        const char* i = insertar.c_str();   
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Ingreso Exitoso" << endl;
        }
        else {
            cout << "Error al ingresar" << endl;
        } 

        string consulta = "select * from puestos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << "," << fila[1] << endl;
            }
        }
        else {
            cout << "Error al ingresar" << endl;
        }

    }
   */

    
    


    

