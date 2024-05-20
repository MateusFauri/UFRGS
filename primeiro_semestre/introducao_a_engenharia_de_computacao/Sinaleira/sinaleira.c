// POG, desculpa pelo codigo feito. Não me responsabiliso por sua leitura e entedimento. 
// Ele funciona!

typedef struct 
{
    int pinVerde;
    int pinVermelho;
}sinaleira;

sinaleira P1_8 = {2,3};
sinaleira P4_5 = {4,5};

sinaleira P2_3 = {6,7};
sinaleira P6_7 = {8,9};


int numeroSinaleira = 2;
int resetar = 0;
int estadoSinaleira;
int flag[4] = {0,0,0,0};
int contador;
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
  contador = 0;

  if(numeroSinaleira != -1)
  	abrirSinaleira(numeroSinaleira);
  
  delay(1000);
  numeroSinaleira = Serial.read();
  
  switch(contador)
  {
    case 0:  // norte
      if(flag[contador])
        //chamar função bloqueadora
      else 
        contador = 1;
      break;

    case 1:   // leste
      if(flag[contador])
        //chamar função bloqueadora 4s
      else 
        contador = 2;
      break;

    case 2: //sul
      if(flag[contador])
        //chamar função bloqueadora 4s
      else 
        contador = 3;
      break;

    case 3:  //oeste
      if(!flag[contador])
        //chamar função bloqueadora 4s

    default:  // norte
      //chamar função norte bloqueadora 4s

      break;
  }
}




void abrirSinaleira(int numero)
{
  resetaSinaleiras();
  estadoSinaleira = numero;

  switch(numero)
  {
    case '8':
    case '4':
    case '5':
    case '1':
        digitalWrite(P6_7.pinVerde, HIGH); 
        digitalWrite(P2_3.pinVerde, HIGH); 
        digitalWrite(P6_7.pinVermelho, LOW); 
        digitalWrite(P2_3.pinVermelho, LOW); 
        break;

    case '2':
    case '3':
    case '6':
    case '7':
    default:
    	digitalWrite(P1_8.pinVerde, HIGH); 
        digitalWrite(P4_5.pinVerde, HIGH); 
        digitalWrite(P1_8.pinVermelho, LOW); 
        digitalWrite(P4_5.pinVermelho, LOW); 
        break;
  }
 resetar = 0;

 delay(4000);
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