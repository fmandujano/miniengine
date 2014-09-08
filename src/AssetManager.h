#include "sqlite3.h"
#include <cstdio>
#include <cstring>
#include <sstream>

class AssetManager
{
private:
	AssetManager(){}
	~AssetManager(){}
	AssetManager(AssetManager const&){}; //constructor de copia es privado
	AssetManager& operator=(AssetManager const&){}; //operador de asignacion tambien es privado

	//instancia unica de la clase
	static AssetManager* instancia;

	//propiedades
	sqlite3 *db;
	char *zErrMsg; //buffer para los mensajes de error

	//ayudas para el callback
	int * buff_int;
	char* buff_char;

public:
	static AssetManager*  Instance();
	void initialize();
	void finalize();

	static int callback_int(void *value, int argc, char **argv, char **azColName);
	static int callback_str(void *value, int argc, char **argv, char **azColName);
	void AssetManager::getIntValueFor(char* resourceName, char* valueName, int * value);
	void AssetManager::getStringValueFor(char* resourceName, char* valueName, char * value);

};
