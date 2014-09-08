#include "AssetManager.h"

AssetManager* AssetManager::instancia=NULL;

AssetManager* AssetManager::Instance()
{
	return instancia ? instancia:(instancia=new AssetManager);
}

/*
	Inicializacion del modulo
*/
void AssetManager::initialize()
{
	int rc = sqlite3_open("data\\assetDB", &db);
	puts("AssetManager initialized");
}

//finalize
void AssetManager::finalize()
{
	sqlite3_close(db);
	puts("AssetManager finalized");
}



void AssetManager::getIntValueFor(char* resourceName, char* valueName, int * value)
{
	
}

int AssetManager::callback_int(void *value, int argc, char **argv, char **azColName)
{
	int * val = reinterpret_cast<int*>(value);
	printf("llega %i\n",*val);
	for(int i=0; i<argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	std::stringstream ss(argv[argc-1]);
	ss>>*val;

	return 0;
}

int AssetManager::callback_str(void *value, int argc, char **argv, char **azColName)
{
	char * val = reinterpret_cast<char*>(value);
	//valido si solo tenemos un resultado
	strcpy(val, argv[0]);
	return 0;
}

void AssetManager::getStringValueFor(char* resourceName, char* valueName, char * value)
{
	char* query = new char[64];
	strcpy(query, "SELECT ");
	strcat(query, valueName);
	strcat(query, " FROM resource WHERE name='");
	strcat(query, resourceName);
	strcat(query, "'");

	puts(query);

	int res = sqlite3_exec(db, query, callback_str, value, &zErrMsg);
	 if( res!=SQLITE_OK )
	 {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	 }
}