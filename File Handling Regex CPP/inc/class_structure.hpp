/**
 * @file class_structure.hpp
 * @author Emmanuel Chavarria Solis (leuname592@hotmail.com)
 * @brief Estructura de la clase empleado
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright MIT
 * 
 */
#pragma once
#include "inc.hpp"

/**
 * @brief Clase recibe varios atributos y se definen los setters y getters asi como la impresion de estos elementos
 * 
 * @param nombre Nombre del empleado
 * @param correo Correo del empleado
 * @param departamento Departamento al que pertenece
 * @param edad Edad actual
 * @param salario Salario del empleado
 */
class Empleado {
  private: string nombre;
  string correo;
  string departamento;
  short unsigned int edad;
  double salario;

  public: void set_nombre(string nombre);
  void set_correo(string correo);
  void set_departamento(string departamento);
  void set_edad(short unsigned int edad);
  void set_salario(double salario);
  void imprimir();
  string get_nombre();
  string get_correo();
  string get_departamento();
  short unsigned int get_edad();
  double get_salario();
  bool validar_entrada(string entrada, string patron);

};