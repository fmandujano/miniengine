#include "MiApp.h"
#include "MiMotor.h"
#include "ConsoleLogger.h"
#include <Windows.h>

//@TODO mover esto a su propio modulo
//CConsoleLogger another_console;
//--------------------------------------------------------------
void MiApp::setup()
{
	ofSetFrameRate(60);
	//inicializacion de los modulos
	AssetManager::Instance()->initialize();

	int sprite_id;
	char * filename = new char;
	//AssetManager::Instance()->getIntValueFor("hero","x", &x);
	
	
	AssetManager::Instance()->getStringValueFor("hero","file", filename);

	char * valorcillo = new char;
	AssetManager::Instance()->getStringValueFor("calabaza","file", valorcillo);
	puts(valorcillo);


	//checar errores!!
	image.loadImage(filename);

	pos = new ofVec2f(500,500);
	vel = new ofVec2f(0,0);
	//another_console.Create("Psicion heroe");
	//another_console.printf("WOW !!! COOLL !!! another console ???");
	
	
	//consola
	//HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
	//CONSOLE_SCREEN_BUFFER_INFO csbi;
	//GetConsoleScreenBufferInfo( hstdout, &csbi );

	SetConsoleTextAttribute( hstdout, 0x0E );
	printf("Inicializando juego..");

	puts("otra cosa");

	SetConsoleTextAttribute( hstdout, 0x0C );
	puts("ejemplo de error");

	SetConsoleTextAttribute( hstdout, 0xC0 );
	puts("ejemplo de error critico");

}

void MiApp::exit()
{
	AssetManager::Instance()->finalize();
	//another_console.Close();
}

int color;
stringstream buff;
//--------------------------------------------------------------
void MiApp::update()
{
	pos->x += vel->x * (float)ofGetLastFrameTime();
	
	//another_console.printf("x: %.6f\n", pos->x);
	color++;
	color = color%16;
	/*
	if( color <10)
		buff << "Color "<<color<<"F"<<"\n";
	else
	{
		char letra;
		letra = color + 55;
		buff << "Color "<<letra<<"F";
	}
	puts(buff.str().c_str());
	system(buff.str().c_str() );
	buff.str(std::string());
	*/
	
}

//--------------------------------------------------------------
void MiApp::draw()
{
	image.drawSubsection(pos->x, pos->y,0,85,140,1,1);
}

//--------------------------------------------------------------
void MiApp::keyPressed(int key)
{
	if(key=='d')
	{
		vel->x = 200;
	}
	if(key=='a')
	{
		vel->x = -200;
	}
}

//--------------------------------------------------------------
void MiApp::keyReleased(int key)
{
	if(key=='d' || key=='a')
	{
		vel->x = 0;
	}
	
}

//--------------------------------------------------------------
void MiApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void MiApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void MiApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void MiApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void MiApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void MiApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void MiApp::dragEvent(ofDragInfo dragInfo){ 

}
