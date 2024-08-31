import unittest
from triangulo import Triangulo

class TrianguloTestCase(unittest.TestCase):

    def setUp(self):
      self.trianguloObj = Triangulo()

    def testTrianguloEscalenoValido(self):
      self.trianguloObj.setLado1(3)
      self.trianguloObj.setLado2(4)
      self.trianguloObj.setLado3(5)

      tipo_triangulo = self.trianguloObj.getTipoTriangulo()
    
      assert tipo_triangulo == "Escaleno"

    def testTrianguloIsoscelesValido(self):
      self.trianguloObj.setLado1(8)
      self.trianguloObj.setLado2(12)
      self.trianguloObj.setLado3(12)

      tipo_triangulo = self.trianguloObj.getTipoTriangulo()
    
      assert tipo_triangulo == "Isósceles"

    def testTrianguloEquilateroValido(self):
      self.trianguloObj.setLado1(15)
      self.trianguloObj.setLado2(15)
      self.trianguloObj.setLado3(15)

      tipo_triangulo = self.trianguloObj.getTipoTriangulo()
    
      assert tipo_triangulo == "Equilatero"

    def testValorNulo(self):
      self.trianguloObj.setLado2(5)
      self.trianguloObj.setLado2(7)

      triangulo = self.trianguloObj.getTriangulo()
    
      assert triangulo == False

    def testValorNegativo(self):
      self.trianguloObj.setLado1(-5)
      self.trianguloObj.setLado2(5)
      self.trianguloObj.setLado3(7)

      triangulo = self.trianguloObj.getTriangulo()
    
      assert triangulo == False

    def testTodosZerados(self):
      self.trianguloObj.setLado1(0)
      self.trianguloObj.setLado2(0)
      self.trianguloObj.setLado3(0)

      triangulo = self.trianguloObj.getTriangulo()
    
      assert triangulo == False


    def testIsoscelesValidoPrimeiroPermuta(self):
      self.trianguloObj.setLado1(5)
      self.trianguloObj.setLado2(5)
      self.trianguloObj.setLado3(7)

      triangulo = self.trianguloObj.getTipoTriangulo()
    
      assert triangulo == "Isósceles"

    def testIsoscelesValidoSegundoPermuta(self):
      self.trianguloObj.setLado1(5)
      self.trianguloObj.setLado2(7)
      self.trianguloObj.setLado3(5)

      tipo_triangulo = self.trianguloObj.getTipoTriangulo()
    
      assert tipo_triangulo == "Isósceles"
    
    def testIsoscelesValidoTerceiroPermuta(self):
      self.trianguloObj.setLado1(7)
      self.trianguloObj.setLado2(5)
      self.trianguloObj.setLado3(5)

      tipo_triangulo = self.trianguloObj.getTipoTriangulo()
    
      assert tipo_triangulo == "Isósceles"

    def testLimiteTrianguloPrimeiraPermuta(self):
      self.trianguloObj.setLado1(3)
      self.trianguloObj.setLado2(4)
      self.trianguloObj.setLado3(7)

      triangulo = self.trianguloObj.getTriangulo()
    
      assert triangulo == False

    def testLimiteTrianguloSegundaPermuta(self):
      self.trianguloObj.setLado1(7)
      self.trianguloObj.setLado2(3)
      self.trianguloObj.setLado3(4)

      triangulo = self.trianguloObj.getTriangulo()
    
      assert triangulo == False

    def testLimiteTrianguloTerceiraPermuta(self):
      self.trianguloObj.setLado1(4)
      self.trianguloObj.setLado2(7)
      self.trianguloObj.setLado3(3)

      triangulo = self.trianguloObj.getTriangulo()
    
      assert triangulo == False


    def testNaoTrianguloPrimeiraPermuta(self):
      self.trianguloObj.setLado1(10)
      self.trianguloObj.setLado2(2)
      self.trianguloObj.setLado3(1)

      triangulo = self.trianguloObj.getTriangulo()
    
      assert triangulo == False

    
    def testNaoTrianguloSegundaPermuta(self):
      self.trianguloObj.setLado1(1)
      self.trianguloObj.setLado2(10)
      self.trianguloObj.setLado3(2)

      triangulo = self.trianguloObj.getTriangulo()
    
      assert triangulo == False


    def testNaoTrianguloTerceiraPermuta(self):
      self.trianguloObj.setLado1(2)
      self.trianguloObj.setLado2(1)
      self.trianguloObj.setLado3(10)

      triangulo = self.trianguloObj.getTriangulo()
    
      assert triangulo == False

if __name__ == "__main__":
  unittest.main()