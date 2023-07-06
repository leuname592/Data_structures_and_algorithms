/**
 * @file class_implementation.cpp
 * @author Emmanuel Chavarria Solis (leuname592@hotmail.com)
 * @brief Implementacion de clase empleado
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright MIT
 * 
 */

#include "class_structure.hpp"

void Empleado::set_nombre(string nombre) {
  this -> nombre = nombre;
}
void Empleado::set_correo(string correo) {
  this -> correo = correo;
}
void Empleado::set_departamento(string departamento) {
  this -> departamento = departamento;
}
void Empleado::set_edad(short unsigned int edad) {
  this -> edad = edad;
}
void Empleado::set_salario(double salario) {
  this -> salario = salario;
}
void Empleado::imprimir() {
  cout.precision(15); // Se agrega una mayor precision para poder imprimir todos los digitos en la terminal
  //Impresion de la informacion de la clase
  cout << "Nombre: " << this -> nombre << ", correo: " << this -> correo << ", edad: " << this -> edad << ", departamento: " << this -> departamento << ", salario: " << this -> salario << endl;
}
string Empleado::get_nombre() {
  return this -> nombre;
}
string Empleado::get_correo() {
  return this -> correo;
}
string Empleado::get_departamento() {
  return this -> departamento;
}
short unsigned int Empleado::get_edad() {
  return this -> edad;
}
double Empleado::get_salario() {
  return this -> salario;
}
bool Empleado::validar_entrada(string entrada, string patron) {
  return false;
}