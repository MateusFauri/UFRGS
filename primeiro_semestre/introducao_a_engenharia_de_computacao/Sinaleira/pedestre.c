
typedef struct 
{
    int pinVerde;
    int pinVermelho;
}sinaleira;

sinaleira P1_8 = {2,3};
sinaleira P4_5 = {4,5};

sinaleira P2_3 = {6,7};
sinaleira P6_7 = {8,9};

int numeroSinaleira = 1;
sinaleira sinaleirasPedestres[4] = {P1_8, P2_3, P4_5, P6_7};

void setup()
{
    Serial.begin(9600);

    for(int i=0; i<4; i++)
    {
        pinMode(sinaleirasPedestres[i].pinVerde, OUTPUT);
        pinMode(sinaleirasPedestres[i].pinVermelho, OUTPUT);
    }
    
}

void loop()
{
    // aqui ele vai ler do teclado e jogar para abrirSinaleira com um switch de S-L-O -> default N
  if(numeroSinaleira != -1)
  	abrirSinaleira(numeroSinaleira);
  delay(1000);
  numeroSinaleira = Serial.read();

}




void abrirSinaleira(int numero)
{
   // P1_8 e P4_5 juntos
   // P2_3 e P6_7 juntos
    resetaSinaleiras();

  switch(numero)
  {
    case '8':
    case '4':
    case '5':
    case '1':
        digitalWrite(P1_8.pinVerde, HIGH); 
        digitalWrite(P4_5.pinVerde, HIGH); 
        digitalWrite(P1_8.pinVermelho, LOW); 
        digitalWrite(P4_5.pinVermelho, LOW); 
        break;

    case '2':
    case '3':
    case '6':
    case '7':
    default:
        digitalWrite(P6_7.pinVerde, HIGH); 
        digitalWrite(P2_3.pinVerde, HIGH); 
        digitalWrite(P6_7.pinVermelho, LOW); 
        digitalWrite(P2_3.pinVermelho, LOW); 
        break;
  }

}

void resetaSinaleiras()
{
    digitalWrite(P6_7.pinVermelho, HIGH); 
    digitalWrite(P2_3.pinVermelho, HIGH); 
    digitalWrite(P1_8.pinVermelho, HIGH); 
    digitalWrite(P4_5.pinVermelho, HIGH); 
    digitalWrite(P6_7.pinVerde, LOW); 
    digitalWrite(P2_3.pinVerde, LOW); 
    digitalWrite(P1_8.pinVerde, LOW); 
    digitalWrite(P4_5.pinVerde, LOW); 
}