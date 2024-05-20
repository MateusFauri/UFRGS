// POG, desculpa pelo codigo feito. Não me responsabiliso por sua leitura e entedimento.
// Ele funciona!

typedef struct
{
    int pinVerde;
    int pinAmarelo;
    int pinVermelho;
}sinaleiraTripla;

typedef struct
{
    int pinVerde;
    int pinVermelho;
    int botao;
}sinaleira;

sinaleira P1_8 = {38,39,2};
sinaleira P2_3 = {42,43,3};
sinaleira P4_5 = {46,47,20};
sinaleira P6_7 = {50,51,21};

sinaleiraTripla SN = {22,23,24};
sinaleiraTripla SL = {26,27,28};
sinaleiraTripla SSUL = {30,31,32};
sinaleiraTripla SO = {34,35,36};

sinaleira sinaleirasPedestres[4] = {P1_8, P2_3, P4_5, P6_7};
sinaleiraTripla sinaleirasCarros[4] = {SN, SL, SSUL, SO};

//sensor de carro V1, V2, V3, V4
int sensorCarros[4] = {0,0,0,0};
char estadoDirecao;
char sentidoCarro = 'n';
int numeroSinaleira = 2;
int resetar = 0;
int estadoSinaleira;
unsigned long time;

//criadas recentemente
int outraFlag = 0;
char controlador;
char sentido;
char ultimaDirecao =' ';

void setup()
{
    Serial.begin(9600);

    for(int i=0; i<4; i++)
    {
        pinMode(sinaleirasPedestres[i].pinVerde, OUTPUT);
        pinMode(sinaleirasPedestres[i].pinVermelho, OUTPUT);
        pinMode(sinaleirasCarros[i].pinVerde, OUTPUT);
        pinMode(sinaleirasCarros[i].pinAmarelo, OUTPUT);
        pinMode(sinaleirasCarros[i].pinVermelho, OUTPUT);
        pinMode(sinaleirasPedestres[i].botao, INPUT);
    }

    attachInterrupt(digitalPinToInterrupt(sinaleirasPedestres[0].botao),ligarFlagNorteSul, HIGH); //mudar a função controladorBinario para algo
    attachInterrupt(digitalPinToInterrupt(sinaleirasPedestres[1].botao),ligarFlagLesteOeste, HIGH); //mudar a função controladorBinario para algo
    attachInterrupt(digitalPinToInterrupt(sinaleirasPedestres[2].botao),ligarFlagNorteSul, HIGH); //mudar a função controladorBinario para algo
    attachInterrupt(digitalPinToInterrupt(sinaleirasPedestres[3].botao),ligarFlagLesteOeste, HIGH); //mudar a função controladorBinario para algo

}

void loop()
{
  sentido = 'n';
  sentidoCarro = Serial.read();

  if(sentidoCarro != -1)
  {
    controlador = sentidoCarro;
    switch(controlador)
    {
      case 'n':
        sensorCarros[0] = 1;
        break;
      case 'l':   // leste
        sensorCarros[1] = 1;
        break;

      case 's': //sul
       sensorCarros[2] = 1;
        break;

      case 'o':  //oeste
        sensorCarros[3] = 1;
        break;

      default:
        break;
    }
  }

  if(outraFlag)
  {
    if((millis() - time) >= 4000)
      outraFlag = 0;
  }

  if(!outraFlag){
    if(ultimaDirecao != ' '){
      sentido = ultimaDirecao;
      ultimaDirecao = ' ';
    }
    switch(sentido)
    {
      case 'n':  // norte
        if(sensorCarros[0])
        {
          outraFlag = 1;
          time = millis();
          ultimaDirecao = 'n';
          abrirSinaleiraCarros(0);
           break;
        }

      case 'l':   // leste
        if(sensorCarros[1])
        {
          outraFlag = 1;
          time = millis();
          ultimaDirecao = 'l';
          abrirSinaleiraCarros(1);
          break;
        }


      case 's': //sul
        if(sensorCarros[2])
        {
          outraFlag = 1;
          time = millis();
          ultimaDirecao = 's';
          abrirSinaleiraCarros(2);
          break;
        }

      case 'o':  //oeste
        if(sensorCarros[3])
        {
          outraFlag = 1;
          time = millis();
          ultimaDirecao = 'o';
          abrirSinaleiraCarros(3);
          break;
        }

      default:  // norte
        abrirSinaleiraCarros(0);
        break;
    }
  }
}


void abrirSinaleiraCarros(int controlador)
{
  int amarelo = controlador - 1;
  if(amarelo < 0) amarelo = 3;
  resetaSinaleiras();
  mudarComposicao(controlador);

  switch(controlador)
  {
    case 1:
      ligarPedestresNorteSul();
      sensorCarros[1] = 0;
      break;

    case 2:
      ligarPedestresLesteOeste();
      sensorCarros[2] = 0;
      break;

    case 3:
      ligarPedestresNorteSul();
      sensorCarros[3] = 0;
      break;

    default:
      ligarPedestresLesteOeste();
      sensorCarros[0] = 0;
      break;
  }

  resetar = 0;
}

void mudarComposicao(int controlador)
{
   for(int i=0; i < 4; i++)
  {
    if(i == controlador)
    {
      digitalWrite(sinaleirasCarros[i].pinVerde, HIGH);
      digitalWrite(sinaleirasCarros[i].pinAmarelo, LOW);
      digitalWrite(sinaleirasCarros[i].pinVermelho, LOW);
    }
    else
    {
      digitalWrite(sinaleirasCarros[i].pinVerde, LOW);
      digitalWrite(sinaleirasCarros[i].pinAmarelo, LOW);
      digitalWrite(sinaleirasCarros[i].pinVermelho, HIGH);
    }
  }
}

void ligarFlagLesteOeste()
{
  sensorCarros[0] = 1;
}

void ligarFlagNorteSul()
{
  sensorCarros[1] = 1;
}



void resetaSinaleiras(int amarelo)
{
    digitalWrite(sinaleirasCarros[amarelo].pinVerde, LOW);
    digitalWrite(sinaleirasCarros[amarelo].pinAmarelo, HIGH);
    digitalWrite(sinaleirasCarros[amarelo].pinVermelho, LOW);

    delay(1000);
    for(int i=0; i < 4; i++)
    {
        //reseta Sinaleiras pedestres
        digitalWrite(sinaleirasPedestres[i].pinVerde, LOW);
        digitalWrite(sinaleirasPedestres[i].pinVermelho, HIGH);
    }

}

void ligarPedestresLesteOeste()
{
    digitalWrite(P6_7.pinVerde, HIGH);
    digitalWrite(P2_3.pinVerde, HIGH);
    digitalWrite(P6_7.pinVermelho, LOW);
    digitalWrite(P2_3.pinVermelho, LOW);
    digitalWrite(P1_8.pinVerde, LOW);
    digitalWrite(P4_5.pinVerde, LOW);
    digitalWrite(P1_8.pinVermelho, HIGH);
    digitalWrite(P4_5.pinVermelho, HIGH);
}

void ligarPedestresNorteSul()
{
    digitalWrite(P1_8.pinVerde, HIGH);
    digitalWrite(P4_5.pinVerde, HIGH);
    digitalWrite(P1_8.pinVermelho, LOW);
    digitalWrite(P4_5.pinVermelho, LOW);
    digitalWrite(P6_7.pinVerde, LOW);
    digitalWrite(P2_3.pinVerde, LOW);
    digitalWrite(P6_7.pinVermelho, HIGH);
    digitalWrite(P2_3.pinVermelho, HIGH);
}