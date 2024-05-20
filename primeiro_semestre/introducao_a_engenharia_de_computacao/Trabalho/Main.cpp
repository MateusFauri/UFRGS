#include <iostream>
#include "libs/EdubotLib.hpp"

#define QUADRADOS	3
#define LADOS	4

using namespace std;

int main(){

	EdubotLib *edubot = new EdubotLib();
	double sonarFrontal;
	int contagem, ladosQuadrado, quantidadeQuadrados;
	int larguraQuadrado;
	int zorro;
	
	if (edubot->connect())
	{
		cout << "Conexão bem sucedida" << endl;
		
		edubot->sleepMilliseconds(100);

		sonarFrontal = edubot->getSonar(3);
		
		cout << sonarFrontal << endl;
		
		quantidadeQuadrados = 0;
		larguraQuadrado = 10;
		zorro = 0;

		while (edubot->isConnected() && zorro < 2)
		{
			while(quantidadeQuadrados < QUADRADOS)
			{
				for(ladosQuadrado = 0; ladosQuadrado < LADOS; ladosQuadrado++)
				{
					for(contagem = 0; contagem < larguraQuadrado; contagem++)
					{
						edubot->move(0.3); 	
		
						edubot->sleepMilliseconds(100);
					}
					edubot->neutral();
					edubot->rotate(90);
					edubot->sleepMilliseconds(1000);
				}
	
				quantidadeQuadrados++;
				larguraQuadrado = larguraQuadrado * 2;
			}
			
			// 		ZORRO
			// “Você sabe como usar uma espada? Sei... a parte pontuda vai no outro homem.�? (A Máscara de Zorro, 1998).
			
	
			for(zorro = 0; zorro < 3; zorro++)
			{
				
				for(contagem=0; contagem <= 20; contagem++)
				{
					edubot->move(0.4);
					edubot->sleepMilliseconds(100);
				}
				
				edubot->neutral();

				switch(zorro)
				{
					case 0:
							edubot->rotate(150);
							break;
					case 1:
							edubot->rotate(-150);
							break;
					default:
							break;
					
				}

				edubot->sleepMilliseconds(1000);
			}
		}

		edubot->stop();
	} 
	else
	{
		cout << "Conexão falhou" << endl; 	
	
	}

	return 0;
}

