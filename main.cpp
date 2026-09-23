#include <iostream>
#include <functional>
#include <vector>
#include <iomanip>
#include <cmath>

#define ANO_SEGUNDOS 3.156e+7;
#define GRAMA_AGUA_MOLECULAS 3.0e-23;

int iniciar();

float imc(float, float);
double imc(double, double);

float notacaoFixada(float);
	float notacaoCientifica(float receber);
float anos_emSegudos(float);
float massa_daAgua(float);

void testarFuncao();

void baskara(float, float, float);
void descobrirPontoFlutuante_doBinario();

int main() {
	iniciar();

}
// Os enunciados estão disponiveis em: https://github.com/JudsonSS/ProgComp/blob/master/Labs/Lab08/Lab08.pdf;
int iniciar() {
	/*
	
	// Exercicio 01:
	// a:
	float massaFloat = 1.75f, alturaFloat = 80.0f;
	std::cout<< "Resultado Float: " << imc(massaFloat, alturaFloat) << std::endl;

	double massaDouble = 1.75, alturaDouble = 80.0;
	std::cout << "Resultado Double: " << imc(massaFloat, alturaFloat) << std::endl;

	//b:
	std::cout.fixed;
	std::cout.precision(12);
	std::cout << "Resultado Float resultado em precisao de 10 casas decimais: " << imc(massaFloat, alturaFloat) << std::endl;
	std::cout << "Resultado Double resultado em precisao de 10 casas decimais: " << imc(massaDouble, alturaDouble) << std::endl;
	
	//c:
	// Sim, tanto o float quanto o double fazem arredondamento, é um fenomeno interessante, até esse ponto de precisão
	// o que dá 7 na calculadora, no return da função double é igual a 7. Se aumentar a precisão o resultado bate até a 13º casa
	// decimal em double, após isso é ruido.
	// Em float isso acontece mais cedo, tendo apenas 6 digitos significativos precisos.

	//d:
	// Para esse programa nesse cenário em específico o ideal é usar float mesmo com menor precisão, pois a necessidade é de apenas
	// medir a massa corporal simples, contas simples como essas necessitam de apenas 2 casas decimais para uma boa precisão matemática
	// Caso fosse um calculo com valores mais elevados e que dependam de máxima precisão possível, seria ideal usar o double, o que não
	// é o nosso caso aqui.

	//Exercicio 02:
	float valor = 0.0f;

	std::cout << "Digite um ponto flutuante: "; std::cin >> valor;
	notacaoFixada(valor);

	//Exercicio 03:
	std::cout << "\n" << "Digite sua idade em anos: "; std::cin >> valor;
	std::cout.fixed;
	std::cout.precision(0);
	std::cout << valor << " anos correspondem a "
		<< std::setprecision(2)
		<< std::scientific 
		<< anos_emSegudos(valor) << " segundos \n";

	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	std::cout << valor << " anos correspondem a "
		<< anos_emSegudos(valor) << " segundos \n";

	// Exercicio 04:
	std::cout << "\n" << "Digite a quantidade de galoes de agua: "; std::cin >> valor;

	std::cout.precision(2);
	std::cout << "Em " << valor << " galoes existem "
		<< std::fixed
		<< std::setprecision(5)
		<< std::scientific
		<< massa_daAgua(valor) << " moleculas de agua \n";
	*/
	/*
	
	// Atividade de fixação: 
	// Atividade 01:

	float a, b, c;
	std::cout << "\nDigite o valor de a, b e c para usarmos baskara: "
		<< "\n a:";
		std::cin >> a;
	std::cout << "\n b:";
		std::cin >> b;
	std::cout << "\n c:";
		std::cin >> c;
	baskara(a, b, c);
	*/

	// Atividade 02:
	descobrirPontoFlutuante_doBinario();
	return 0;
}

float imc(float altura, float massa) {
	return massa / (altura * altura);
}
double imc(double altura, double massa) {
	return massa / (altura * altura);
}

float notacaoFixada(float receber) {
	std::cout << "Notacao padrão: " << receber << "\n";
	// scientific pertence a iosmanip, mas precisa do namespace std::
	// Tive que usar std::fixed e std::setprecision de iosmanip porque std::scienfic acaba empregando sobre o cout
	// para que mostre a quantidade de casas decimais totais. 
	// isso é diferente de std::cout.fixed, e std::cout.precision(x) como também é diferente do método logo abaixo.
	std::cout << "Notacao cientifica: " << std::fixed << std::setprecision(6) << std::scientific << receber << "\n"; 
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout << "Notacao decimal: " << receber;
	return 0.0;
}

float anos_emSegudos(float anos) {
	float segundos = ANO_SEGUNDOS;
	return segundos * anos;
}
// 1/4 de galão é 950 gramas
// 4*950 é 3800 (não confundir com 3.800 que em inglês é o mesmo que o nosso 3,8 e C++ segue a norma inglesa)
// multiplicamos o valor do galao que possui aproximadamente 4 litros (um litro - 200) pelo valor da molecula por grama da agua
// como o valor é exponecialmente negativo (ou seja, menor que 0), é necessario dividir para multiplicar.

float massa_daAgua(float receber) {
	float gramasTotais = (3800 * receber)/GRAMA_AGUA_MOLECULAS; 
	return gramasTotais;
}

void testarFuncao() {
	// Extrapola o número de dígitos significativos da mantissa.
	float f1 = 24980154.845f;

	// Extrapola o maior expoente possível.
	//float f2 = 2e40f;

	// Extrapola o número de dígitos significativos da mantissa.
	double d1 = 293849384958473847.394;

	// Extrapola o maior expoente possível.
	//double d2 = 2e315;

	/*
	std::cout << "Float f1: " << f1 << "\nFloat f2: " << f2
		<< "\nDouble d1: " << d1 << "\nDouble d2" << d2 << "\n\n";
	*/

	// Exercício 05:
	// Simplesmente não roda pois f2 e d2 está fora de interfalo do que conseguem reprensentar
	// o compilador simplesmente não consegue calcular esses valoress.
}

void baskara(float a, float b, float c) {
	float delta = sqrt((b * b) - 4 * a * c);
	float x1 = (-b + delta) / 2 * a;
	float x2 = (-b - delta) / 2 * a;

	// a:
	// quando delta:
	if (delta > 0) {
		std::cout << "\nHa duas raizes reais e distintas, delta: " << delta << "\n";
		// Não se coloca "maior ou igual" ( >= ) quando existe apenas uma unica possível solução
		// que nesse caso é ser maior que zero, tendo o 0 como referencia. Da mesma forma o contrario. 
	}
	// b:
	// quando delta:
	else if (delta == 0) {
		std::cout << "\nHa apenas uma raiz real (ha duas raizes iguais), delta: " << delta << "\n";
	}

	// c:
	// quando delta:
	else{
		std::cout << "\nNao ha rais real, delta: " << delta << "\n";
	}
}


void descobrirPontoFlutuante_doBinario() {
	/* float binario[32] = {1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
					1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 
					0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
	*/

	int binario[32] = { 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	//0, 1, 1, 0, 0, 0, 1, 0, 1

	double mantissa = 1;

	mantissa = (mantissa / 4) + (mantissa / 8) + (mantissa / 128) + (mantissa / 512);
	int estado = 255 ^ (3 << 4);
	estado = estado ^ 7;

	int expoente = (estado - 127);

	std::cout << "\nParte inteira: (expoente da operacao) " << estado
		<< "\nExpoente: " << expoente
		<< "\nMantissa: " << mantissa ;


	
	double v = 1 * (pow(2.0, expoente)) * (1 + mantissa);

	std::cout << "\nO valor ponto flutuante refente ao binario[32]: " << v;

}