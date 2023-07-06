/**
 * @file main.cpp
 * @author Emmanuel Chavarria Solis (leuname592@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright MIT
 * 
 */
#include "inc.hpp"
#include "functions_headers.hpp"

int main() {
  vector < Empleado > Empleados;
  string input;
  string departamento;
  bool flag = true;
  string salario_minimo;
  string salario_maximo;
  Empleados = leerArchivo("../../employees.csv");
  // Menu para ingresar los datos de busqueda
  while (flag) {
    cout << "1. Busqueda por departamento" << endl;
    cout << "2. Busqueda por salario" << endl;
    cout << "Para salir digite cualquier otro string" << endl;
    cout << "Digite un numero(1,2 o salir): ";
    cin >> input;
    if (input == "1") {
      cout << "Ingrese el nombre del departamento: ";
      cin >> departamento;
      cout << "Empleados por departamento:" << endl << endl;
      buscarPorDepartamento(Empleados, departamento);
    } 
    else if (input == "2") {
      cout << "Ingrese el salario minimo: ";
      try { //Validacion del formato del salario minimo
        cin >> salario_minimo;
        if (!validarEntrada(salario_minimo, "^([0-9]+(.[0-9]+)?)$")) {
          throw std::invalid_argument("Invalid input ****");
        }
      } catch (const std::invalid_argument & ia) {
        cout << endl << "**** Error de formato: " << ia.what() << endl << endl;
        continue;
      }
      cout << endl;
      cout << "Ingrese el salario maximo: ";
      try { //Validacion del formato del salario maximo
        cin >> salario_maximo;
        if (!validarEntrada(salario_maximo, "^([0-9]+(.[0-9]+)?)$")) {
          throw std::invalid_argument("Invalid input ****");
        }
      } catch (const std::invalid_argument & ia) {
        cout << endl << "**** Error de formato: " << ia.what() << endl << endl;
        continue;
      }
      cout << "Empleados por salario:" << endl << endl;
      buscarPorSalario(Empleados, (double) std::stod(salario_minimo), (double) std::stod(salario_maximo));
    } 
    else {
      flag = false;
    }
  }
}
