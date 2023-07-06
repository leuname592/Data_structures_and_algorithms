class Empleado:

    # Se inicia el constructor de la clase
    def __init__(self, nombre, correo, edad, departamento, salario):
        self.nombre = nombre
        self.correo = correo
        self.edad = edad
        self.departamento = departamento
        self.salario = salario

    # Se definen setters y getters
    def set_nombre(self, nombre):
        self.nombre = nombre

    def set_correo(self, correo):
        self.correo = correo

    def set_edad(self, edad):
        self.edad = edad

    def set_departamento(self, departamento):
        self.departamento = departamento

    def set_salario(self, salario):
        self.salario = salario

    def get_nombre(self):
        return self.nombre

    def get_correo(self):
        return self.correo

    def get_edad(self):
        return self.edad

    def get_departamento(self):
        return self.departamento

    def get_salario(self):
        return self.salario

    # Se imprime la informacion del objeto que quiere ser imprimido
    def imprimir_info(self):
        print(self.nombre
              + ",", self.correo
              + ",", self.edad
              + ",", self.departamento
              + ",", self.salario)
