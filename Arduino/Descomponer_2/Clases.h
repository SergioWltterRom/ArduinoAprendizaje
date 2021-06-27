
class Rectangulo{
 private:
  float Base;
  float Altura;
 public:
  Rectangulo(float tam);
  Rectangulo(float base, float altura);

  float Area();
  float Perimetro();
};

class Triangulo{
 private:
  float Base;
  float Altura;
 public:
  Triangulo(float tam);
  Triangulo(float base, float altura);

  float Area();
  float Perimetro();
};

////  Funciones Clases

unsigned int NumCuadrados();
unsigned int NumRectangulos();
unsigned int NumTrigulosIsosceles();
unsigned int NumTrigulos();
