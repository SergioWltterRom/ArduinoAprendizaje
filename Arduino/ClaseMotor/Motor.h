class Motor{
 private:
  int Cv;
  int Peso;
  bool Funciona; 
 public:
  Motor(bool funciona);
  void setCV(int cv);
  void setPeso(int peso);  
};

int VentasTotal(); 
