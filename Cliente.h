#pragma once
#include<mysql.h>
#include<iostream>
#include<string>
#include "ConexionBD.h"
#include "Persona.h"


using namespace std;
class Cliente : Persona{
	//atributos
private: string nit, genero, correo_electronico, fecha_ingreso;
	   int id = 0;
	   

	   //constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, int tel, string n, string gn, string c_e, string f_i, int i) : Persona(nom, ape, tel) {
		nit = n;
		genero = gn;
		correo_electronico = c_e;
		fecha_ingreso = f_i; 
		id = i;

	}

	
	//metodos
	//set (modificar)
	void setId(int i) { id = i; }
	void setNit(string n) { nit = n; }
	void setNombre(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setGenero(string gn) { genero = gn; }
	void setCorreo(string c_e) { correo_electronico = c_e; }
	void setFecha_Ingreso(string f_i) { fecha_ingreso = f_i; }
	void setTelefono(int tel) { telefono = tel; }
	//get (motrar)
	int getId() { return id; }
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getGenero() { return genero; }
	string getCorreo() { return correo_electronico; }
	string getFecha_Ingreso() { return fecha_ingreso; }
	int getTelefono() { return telefono; }
	

	void borrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string ii = to_string(id);
		if (cn.getConectar()) {
			string borrar = "delete from clientes where id_cliente = " + ii + "";
			const char* i = borrar.c_str();			
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion exitosa" << endl;
			}
			else {
				cout << "Error al ingresar" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();

	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		string ii = to_string(id);
		if (cn.getConectar()) {
			string actualizar = "update clientes set nombres = '" + nombres + "', apellidos = '" + apellidos + "', NIT = '" + nit + "', genero = '" + genero + "', telefono = '" + t + "', correo_electronico = '" + correo_electronico + "', fecha_ingreso = '" + fecha_ingreso + "' where id_cliente = " + ii + "";
			const char* i = actualizar.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion exitosa" << endl;
			}
			else {
				cout << "Error al ingresar" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string insertar = "INSERT INTO clientes(nombres,apellidos,NIT,genero,telefono,correo_electronico,fecha_ingreso)VALUES('" + nombres + "','" + apellidos + "','" + nit + "','" + genero + "','" + t + "','" + correo_electronico + "','" + fecha_ingreso + "'); ";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso" << endl;
			}
			else {
				cout << "Error al ingresar" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "------------- CLIENTES -------------"<<endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				}
			}
			else {
				cout << "Error al ingresar la informacion" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

};

