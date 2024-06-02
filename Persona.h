#pragma once
#include<iostream>
using namespace std;
class Persona
{
protected: string nombres, apellidos;
		 int telefono=0;


		 //constructor
protected:
	Persona() {

	}
	Persona(string nom, string ape, int tel) {
		nombres = nom;
		apellidos = ape;
		telefono = tel;


	}

};

