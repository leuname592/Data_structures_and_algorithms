/**
 * @file function_implementation.cpp
 * @author Emmanuel Chavarria Solis (leuname592@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright MIT
 * 
 */
#include "functions_headers.hpp"

bool validarEntrada(string entrada, string patron) {
  std::regex regex_patron(patron);
  //En caso de haber coincidencia retorna true, caso opuesto retorna false
  return std::regex_search(entrada, regex_patron);
}

vector < Empleado > leerArchivo(string nombreArchivo) {
  Empleado EmpleadoInfo;
  vector < Empleado > Empleados;
  std::ifstream ReadFile(nombreArchivo);
  try{
    if(ReadFile.fail()){
      throw std::invalid_argument("Error opening file");
    }
  } catch(const std::invalid_argument & ia){
    cout << "Error al abrir archivo, es probable que este ubicado en otro lugar al esperado: " << ia.what() << endl;
  }
  string delimiter = ",";
  int line_no = 1;
  string line;
  vector < string > line_v;
  size_t block = 0;
  //Lectura del archivo por medio de stream
  while (getline(ReadFile, line)) {
    try {
      //Validacion de las lineas del documento segun el formato de la tarea
      if (!validarEntrada(line, "^([^,]+),([a-zA-Z0-9_.]+@[a-zA-Z0-9]+.[a-zA-Z0-9]+),([0-9]+),([^,]+),([0-9]+(.[0-9]+)?)$")) {
        throw std::invalid_argument("Invalid input");
      }
    } catch (const std::invalid_argument & ia) {
      cout << "Ignorando linea " << line_no << ": " << ia.what() << endl;
      line_no++;
      continue;
    }

    // En caso de linea correcta cada valor se divide en el delimiter "," y se agrega a un vector con pushback
    while ((block = line.find(delimiter)) != string::npos) {
      string value = line.substr(0, block);
      line_v.push_back(value);
      line.erase(0, block + delimiter.length());
    }
    line_v.push_back(line);
    
    //Se inicializa el objeto
    EmpleadoInfo.set_nombre(line_v[0]);
    EmpleadoInfo.set_correo(line_v[1]);
    EmpleadoInfo.set_edad((short unsigned int) std::stoi(line_v[2]));
    EmpleadoInfo.set_departamento(line_v[3]);
    EmpleadoInfo.set_salario((double) std::stod(line_v[4]));
    Empleados.push_back(EmpleadoInfo);
    line_no++;
    line_v.clear();
  }
  //Cerrar archivo
  ReadFile.close();
  return Empleados;
}

vector < Empleado > buscarPorDepartamento(vector < Empleado > empleados, string departamento) {
  vector < Empleado > empleadosPorDepartamento;
  //Buscar departamento en caso de coincidencia se agrega al final del vector
  for (int i = 0; i < (int) empleados.size(); i++) {
    if (empleados[i].get_departamento() == departamento) {
      empleados[i].imprimir();
      empleadosPorDepartamento.push_back(empleados[i]);
    }
  }
  // Si no hay coincidencias se indica en la consola
  if (empleadosPorDepartamento.empty()) {
    cout << "No hay resultados en la busqueda" << endl << endl;
  }
  return empleadosPorDepartamento;
}

vector < Empleado > buscarPorSalario(vector < Empleado > empleados, double salarioMinimo, double salarioMaximo) {
  vector < Empleado > empleadosPorSalarios;
  //Buscar salario en caso de coincidencia se agrega al final del vector
  for (int i = 0; i < (int) empleados.size(); i++) {
    if ((empleados[i].get_salario() >= salarioMinimo) && (empleados[i].get_salario() <= salarioMaximo)) {
      empleados[i].imprimir();
      empleadosPorSalarios.push_back(empleados[i]);
    }
  }
  // Si no hay coincidencias se indica en la consola
  if (empleadosPorSalarios.empty()) {
    cout << "No hay resultados en la busqueda" << endl << endl;
  }
  return empleadosPorSalarios;
}
