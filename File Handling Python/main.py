import libEmpleado.functions as functions


def main():
    lista_empleados = functions.leer_archivo('../../employees.csv')
    while (True):
        # Se inicia el menu
        print("0. Salir")
        print("1. Buscar por departamento")
        print("2. Buscar por rango salarial")
        # Manejo de excepciones
        try:
            entrada_usuario = int(input("Ingrese una opción: "))
        except ValueError:
            print(">>>>>>>>>>> Opción inválida\n")
            continue
        # Si la entrada es cero salir del programa
        if entrada_usuario == 0:
            break
        # Si la entrada es 1 buscar por departamento
        elif entrada_usuario == 1:
            try:
                departamento = input("Ingrese el departamento: ")
            except ValueError:
                print(">>>>>>>>>>> Ingrese una opción válida\n")
            lista_empleados_departamento = functions.buscarPorDepartamento(lista_empleados, departamento) # noqa
            print("\nLa lista de empleados en el departamento",
                  departamento, "es:\n")
            if lista_empleados_departamento == []:
                print("No se encontraron empleados en el departamento: ", departamento) # noqa
            else:
                functions.imprimir_info_empleados(lista_empleados_departamento)
        # Si la entrada es 2 buscar por salario
        elif entrada_usuario == 2:
            try:
                salario_minimo = int(input("Ingrese el salario mínimo: "))
            except ValueError:
                print(">>>>>>>>>>> Ingrese una opción válida\n")
                continue
            try:
                salario_maximo = int(input("Ingrese el salario máximo: "))
            except ValueError:
                print(">>>>>>>>>>> Ingrese una opción válida\n")
                continue
            print("\nLa lista de empleados en el rango salarial",
                  salario_minimo, "-", salario_maximo, "es:\n")
            lista_empleados_salario = functions.buscarPorSalario(lista_empleados, salario_minimo, salario_maximo) # noqa
            if (lista_empleados_salario == []):
                print("No se encontraron empleados en el rango salarial: ",
                      salario_minimo, "-", salario_maximo)
            else:
                functions.imprimir_info_empleados(lista_empleados_salario)
        else:
            print(">>>>>>>>>>> Opción inválida\n")


if __name__ == '__main__':
    main()
