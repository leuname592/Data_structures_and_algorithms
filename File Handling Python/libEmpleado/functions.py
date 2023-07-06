import libEmpleado.classes as classes
import re


# Validar regex
def validar_entrada(patron, entrada):
    return re.search(patron, entrada)


''' En esta funcion se lee el archivo
se hace exception handling y se inicializa
la clase empleado a partir del constructor
'''


def leer_archivo(nombre):
    lista_empleados = []
    try:
        with open(nombre, mode='r', encoding='UTF-8') as archivo:
            for num, linea in enumerate(archivo, 1):
                if (not validar_entrada("^([^,]+),([a-zA-Z0-9_.]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+),([0-9]+),([^,]+),([0-9]+(\.[0-9]+)?)*$", linea)): # noqa
                    print(">>>>>>>>>>> Ignorando linea "
                          + str(num)
                          + " por formato inválido\n")
                    continue
                linea = linea.strip().split(',')
                lista_empleados.append(classes.Empleado(linea[0],
                                                        linea[1],
                                                        linea[2],
                                                        linea[3],
                                                        int(linea[4])))
    except FileNotFoundError:
        print(">>>>>>>>>>> No se encontró el archivo\n")
    return lista_empleados


def buscarPorDepartamento(lista_empleados, departamento):
    lista_empleados_departamento = []
    for empleado in lista_empleados:
        # Si hay match se agrega a la lista
        if empleado.get_departamento() == departamento:
            lista_empleados_departamento.append(empleado)
    if lista_empleados_departamento == []:
        print("No se encontraron empleados en el departamento: ", departamento)
    print("\n")
    return lista_empleados_departamento


def buscarPorSalario(lista_empleados, salario_minimo, salario_maximo):
    lista_empleados_salario = []  # Si hay match se agrega a la lista
    for empleado in lista_empleados:
        if (empleado.get_salario() >= salario_minimo and empleado.get_salario() <= salario_maximo): # noqa
            lista_empleados_salario.append(empleado)
    print("\n")
    return lista_empleados_salario


def imprimir_info_empleados(lista_empleados):
    for empleado in lista_empleados:
        empleado.imprimir_info()  # Impresion de objeto tipo empleado
    print("\n")
