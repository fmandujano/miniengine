#include "MiMotor.h"

float factorial(int x)
{
	int r = 1;
	for (int i = 1; i <= x; i++)
	{
		r *= i;
	}
	return r;
}

float coseno(float x)
{
	//serie de potencias del coseno
	int n = 14;
	float res = 0;
	for (int k = 0; k <= n; k++)
	{
		float actual = pow(-1, k) *pow(x, 2 * k);// / factorial(2 * k);
		int fact = factorial(2 * k);
		res += (actual/fact);
		//printf("seno iteracion %i: %.6f/%i = %.6f \n",k,actual,fact, actual/fact);
		printf("seno iteracion %i: %.6f\n", k, res);
	}
	return res;
}

//========================================================================
int main(int argc, char** argv )
{
	int resx=1024, resy=768;
	bool enVentana=true;
	bool enVentanadfd = false;

	for (int i = 1; i < argc; i++)
	{ 
		if (!enVentanadfd && strcmp(argv[i], "-w") == 0)
		{
			enVentana = true;
			enVentanadfd = true;
		}

		if (strcmp(argv[i], "-resx") == 0)
		{
			resx = atoi(argv[i+1]);
			i++;
		}
		else if (strcmp(argv[i], "-resy") == 0)
		{
			resy = atoi(argv[i + 1]);
			i++;
		}
	}

	//leer desde archivo
	ofstream myfile;
	myfile.open("../data/datos.txt", std::ofstream::in);
	if (myfile == NULL)
	{
		printf("no se encuentra el archivo\n");
	}
	else
	{
		printf("archivo encontrado\n");
	}
	
	myfile.close();


	ofSetupOpenGL(resx,resy,  enVentana ?OF_WINDOW:OF_FULLSCREEN);			// <-------- setup the GL context

	ofRunApp(new MiApp());
	
	return(0);
}
