class Alumno:
    def __init__(self, nombre="", edad=0, promedio=0.0):        #constructor
        self.nombre = nombre
        self.edad = edad
        self.promedio = promedio

    def __str__(self):
        return f"{self.nombre} {self.edad} {self.promedio:.2f}"

    def __lt__(self, other):
        return self.promedio < other.promedio

class Grupo:
    def __init__(self, cantidad):   #constructor
        self.cantidad = cantidad
        self.alu = [None] * cantidad  # define una lista sin indice

    def __str__(self):
        for alumno in self.alu:
            print(alumno) 
        return ""

    def agregar_alumno(self, nombre, edad, promedio):
        for i, alumno in enumerate(self.alu):   #usamos la funcion enumerate de python como un contador 
            self.alu[i] = Alumno(nombre, edad, promedio)
                

    def ordenar_por_promedio(self):
        for i in range(self.cantidad - 1):
            for j in range(i + 1, self.cantidad):
                if self.alu[j].promedio < self.alu[i].promedio:
                    self.alu[i], self.alu[j] = self.alu[j], self.alu[i]

    def promedio_grupo(self):
        total = sum(alumno.promedio for alumno in self.alu)
        print(f"El promedio de la clase es {total / self.cantidad:.2f}")

    def mejor_promedio(self):
        self.ordenar_por_promedio()
        print(f"El mejor promedio es {self.alu[0].promedio:.2f}")

# main
grupo = Grupo(5)        #definimos el objeto
grupo.agregar_alumno("Alice", 20, 14.3)
grupo.agregar_alumno("Bob", 22, 18.9)
grupo.agregar_alumno("Charlie", 21, 9.99)
grupo.agregar_alumno("David", 23, 10.13)
grupo.agregar_alumno("Eve", 19, 19.4)

print(grupo)
grupo.promedio_grupo()
grupo.mejor_promedio()