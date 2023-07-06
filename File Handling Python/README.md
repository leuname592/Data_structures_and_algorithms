# Sistemas Python-C++ S.A

 Para ello la primer diferencia es que en esta tarea se utilizó un archivo de pre-commit como hook para git, el cual se encarga de correr el programa de python y verificar que la sintaxis sea correcta siguiendo un formato PEP8. En caso de que el programa no cumpla con el formato, el commit no se realiza y se muestra un mensaje de error.
<br>
Para realizar el Pre-commit hay librerias ya realizadas con el proposito de verificar el formato de python, en este caso se utilizó la libreria flake8, se siguieron los pasos de este [material](https://www.youtube.com/watch?v=psjz6rwzMdk):
1. Se instala pre-commit con el comando:
```bash
    pip install pre-commit
```
2. Se crea el archivo .pre-commit-config.yaml con el siguiente contenido:
```yaml
repos:
-   repo: https://github.com/PyCQA/flake8
    rev: 6.0.0
    hooks:
    -   id: flake8
```
3. Se ejecuta el comando:
```bash
    pre-commit install
```

Se observa como usando la [libreria](https://github.com/PyCQA/flake8), se simplifica el proceso de verificacion de sintaxis de python.

Otro cambio con respecto a la tarea realizada en lenguaje C++ es que en python no existen los includes, entonces se realizó una modularización más simple creando un folder de librerias con las funciones y la clase e importando esto en forma de libreria en el archivo main.py.
En esta tarea realizé una corrección del regex para que acepte los dos formatos de final de linea (LF y CRLF). Para que de esta manera no se quiebre con archivos generados en windows o linux. Este cambio se muestra a continuación:
<br>
Antes:
<br>
...\$
<br>
Después:
<br>
...*$
<br>
En el archivo main.py se puede encontrar el menu de opciones para el usuario, el cual se muestra a continuación:
```python
    print("0. Salir")
    print("1. Buscar por departamento")
    print("2. Buscar por rango salarial")
```
El menú hace uso de la libreria donde se implementan las funciones para validar entradas, leer archivos, buscar por departamento, buscar por salario e imprimir información de la clase empleados.
```python
    def validar_entrada(patron, entrada):
        ...
    def leer_archivo(nombre):
        ...
    def buscarPorDepartamento(lista_empleados, departamento):
        ...
    def buscarPorSalario(lista_empleados, salario_minimo, salario_maximo):
        ...
    def imprimir_info_empleados(lista_empleados):
        ...
```
Este archivo finalmente hace uso de la clase empleado que recibe como atributo nombre, correo, edad, departamento y salario. La clase tiene un metodo para imprimir la información de un empleado y setters, getters para obtener e insertar información.
```python
    class Empleado:
        def __init__(self, nombre, correo, edad, departamento, salario):
            self.nombre = nombre
            self.correo = correo
            self.edad = edad
            self.departamento = departamento
            self.salario = salario
        def imprimir_info(self):
            ...
```

Para correr el programa se ejecuta el siguiente comando:
```bash
    make
```
Y para eliminar el folder __pycache__ se ejecuta:
```bash
    make clean
```

## Licencia

[MIT](https://choosealicense.com/licenses/mit/)