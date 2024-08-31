class Triangulo:
    def __init__(self, lado1=None, lado2=None, lado3=None):
        self._lado1 = lado1
        self._lado2 = lado2
        self._lado3 = lado3
        self._triangulo = None
        self._tipo_do_triangulo = None

    def getTriangulo(self):
        self._forma_um_triangulo()
        return self._triangulo
    
    def getTipoTriangulo(self):
        if not self._triangulo:
            self._forma_um_triangulo()
        if self._triangulo:
            self._tipo_triangulo()
        return self._tipo_do_triangulo

    def getLado1(self):
        return self._lado1

    def setLado1(self, lado1):
        self._lado1 = lado1

    def getLado2(self):
        return self._lado2

    def setLado2(self, lado2):
        self._lado2 = lado2

    def getLado3(self):
        return self._lado3

    def setLado3(self, lado3):
        self._lado3 = lado3

    def _possuiTodosDadosNecessarios(self):
        if self._lado1 and self._lado2 and self._lado3:
            return True
        return False

    def _possuiValorNegativo(self):
        if (self._lado1 > 0) and (self._lado2 > 0) and (self._lado3 > 0):
            return False
        return True


    def _forma_um_triangulo(self):
        dados_validos = self._possuiTodosDadosNecessarios() and not self._possuiValorNegativo()

        if dados_validos:
            primeiro_lado = (self._lado2 + self._lado3) > self._lado1
            segundo_lado = (self._lado1 + self._lado3) > self._lado2
            terceiro_lado = (self._lado1 + self._lado2) > self._lado3

            if primeiro_lado and segundo_lado and terceiro_lado:
                self._triangulo = True
            else:
                self._triangulo = False
        else:
            self._triangulo = False

    def _tipo_triangulo(self):
        isoceles = (self._lado1 == self._lado2) or (self._lado2 == self._lado3) or (self._lado1 == self._lado3)
        equilatero = (self._lado1 == self._lado2) and (self._lado2 == self._lado3)

        if equilatero:
            self._tipo_do_triangulo = "Equilatero"
        elif isoceles:
            self._tipo_do_triangulo = "Isósceles"
        else:
            self._tipo_do_triangulo = "Escaleno"
