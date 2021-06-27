
class Coche {
 private:
  char Nombre;
  char Modelo;
  char Marca;
 public:     
  Coche();
  Coche(char modelo, char marca);
  void cambioNombre(char nombre);
  char getModelo();
  char getMarca();  
};

unsigned int cochesCont();
