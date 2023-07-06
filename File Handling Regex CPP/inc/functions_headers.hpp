/**
 * @file functions_headers.hpp
 * @author Emmanuel Chavarria Solis (leuname592@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright MIT
 * 
 */
#pragma once
#include "inc.hpp"
#include "class_structure.hpp"

/**
 * @brief Lectura del archivo (simulacion de una base de datos)
 * 
 * @param nombreArchivo Ruta del archivo a leer
 * @return vector<Empleado> Se retorna un vector de empleados con las lineas correctas 
 */
vector < Empleado > leerArchivo(string nombreArchivo);

/**
 * @brief Buscar empleados por departamento
 * 
 * @param empleados Vector de empleados leidos del archivo
 * @param departamento Departamento a buscar
 * @return vector<Empleado> Se retorna un vector de empleados con las coincidencias
 */
vector < Empleado > buscarPorDepartamento(vector < Empleado > empleados, string departamento);

/**
 * @brief Buscar empleado por salario
 * 
 * @param empleados Vector de empleados leidos del archivo
 * @param salarioMinimo Salario maximo en la busqueda
 * @param salarioMaximo Salario minimo en la busqueda
 * @return vector<Empleado> Se retorna un vector de empleados con las coincidencias
 */
vector < Empleado > buscarPorSalario(vector < Empleado > empleados, double salarioMinimo, double salarioMaximo);

/**
 * @brief Validar entradas con regex
 * 
 * @param entrada String a validar
 * @param patron Patron para realizar la validacion
 * @return true 
 * @return false 
 */
bool validarEntrada(string entrada, string patron);