import pytest
from triangulo import Triangulo

class TestTriangulo:

  @pytest.fixture
  def setup(self):
    self.trianguloObj = Triangulo()
      
  @pytest.mark.validadeTipoTriangulos
  def testTrianguloEscalenoValido(self, setup):
    self.trianguloObj.setLado1(3)
    self.trianguloObj.setLado2(4)
    self.trianguloObj.setLado3(5)

    tipo_triangulo = self.trianguloObj.getTipoTriangulo()

    assert tipo_triangulo == "Escaleno"

  @pytest.mark.validadeTipoTriangulos
  def testTrianguloIsoscelesValido(self, setup):
    self.trianguloObj.setLado1(8)
    self.trianguloObj.setLado2(12)
    self.trianguloObj.setLado3(12)

    tipo_triangulo = self.trianguloObj.getTipoTriangulo()

    assert tipo_triangulo == "Isósceles"

  @pytest.mark.validadeTipoTriangulos
  def testTrianguloEquilateroValido(self, setup):
    self.trianguloObj.setLado1(15)
    self.trianguloObj.setLado2(15)
    self.trianguloObj.setLado3(15)

    tipo_triangulo = self.trianguloObj.getTipoTriangulo()

    assert tipo_triangulo == "Equilatero"

  @pytest.mark.casosIndesejaveis
  def testValorNulo(self, setup):
    self.trianguloObj.setLado2(5)
    self.trianguloObj.setLado2(7)

    triangulo = self.trianguloObj.getTriangulo()

    assert triangulo == False

  @pytest.mark.casosIndesejaveis
  def testValorNegativo(self, setup):
    self.trianguloObj.setLado1(-5)
    self.trianguloObj.setLado2(5)
    self.trianguloObj.setLado3(7)

    triangulo = self.trianguloObj.getTriangulo()

    assert triangulo == False

  @pytest.mark.casosIndesejaveis
  def testTodosZerados(self, setup):
    self.trianguloObj.setLado1(0)
    self.trianguloObj.setLado2(0)
    self.trianguloObj.setLado3(0)

    triangulo = self.trianguloObj.getTriangulo()

    assert triangulo == False


  @pytest.mark.isoceleValidoPermuta
  def testIsoscelesValidoPrimeiroPermuta(self, setup):
    self.trianguloObj.setLado1(5)
    self.trianguloObj.setLado2(5)
    self.trianguloObj.setLado3(7)

    triangulo = self.trianguloObj.getTipoTriangulo()

    assert triangulo == "Isósceles"

  @pytest.mark.isoceleValidoPermuta
  def testIsoscelesValidoSegundoPermuta(self, setup):
    self.trianguloObj.setLado1(5)
    self.trianguloObj.setLado2(7)
    self.trianguloObj.setLado3(5)

    tipo_triangulo = self.trianguloObj.getTipoTriangulo()

    assert tipo_triangulo == "Isósceles"

  @pytest.mark.isoceleValidoPermuta
  def testIsoscelesValidoTerceiroPermuta(self, setup):
    self.trianguloObj.setLado1(7)
    self.trianguloObj.setLado2(5)
    self.trianguloObj.setLado3(5)

    tipo_triangulo = self.trianguloObj.getTipoTriangulo()

    assert tipo_triangulo == "Isósceles"

  @pytest.mark.trianguloLimiteInferiorPermuta
  def testLimiteTrianguloPrimeiraPermuta(self, setup):
    self.trianguloObj.setLado1(3)
    self.trianguloObj.setLado2(4)
    self.trianguloObj.setLado3(7)

    triangulo = self.trianguloObj.getTriangulo()

    assert triangulo == False

  @pytest.mark.trianguloLimiteInferiorPermuta
  def testLimiteTrianguloSegundaPermuta(self, setup):
    self.trianguloObj.setLado1(7)
    self.trianguloObj.setLado2(3)
    self.trianguloObj.setLado3(4)

    triangulo = self.trianguloObj.getTriangulo()

    assert triangulo == False

  @pytest.mark.trianguloLimiteInferiorPermuta
  def testLimiteTrianguloTerceiraPermuta(self, setup):
    self.trianguloObj.setLado1(4)
    self.trianguloObj.setLado2(7)
    self.trianguloObj.setLado3(3)

    triangulo = self.trianguloObj.getTriangulo()

    assert triangulo == False

  @pytest.mark.naoTrianguloPermuta
  def testNaoTrianguloPrimeiraPermuta(self, setup):
    self.trianguloObj.setLado1(10)
    self.trianguloObj.setLado2(2)
    self.trianguloObj.setLado3(1)

    triangulo = self.trianguloObj.getTriangulo()

    assert triangulo == False

  @pytest.mark.naoTrianguloPermuta
  def testNaoTrianguloSegundaPermuta(self, setup):
    self.trianguloObj.setLado1(1)
    self.trianguloObj.setLado2(10)
    self.trianguloObj.setLado3(2)

    triangulo = self.trianguloObj.getTriangulo()

    assert triangulo == False

  @pytest.mark.naoTrianguloPermuta
  def testNaoTrianguloTerceiraPermuta(self, setup):
    self.trianguloObj.setLado1(2)
    self.trianguloObj.setLado2(1)
    self.trianguloObj.setLado3(10)

    triangulo = self.trianguloObj.getTriangulo()

    assert triangulo == False
