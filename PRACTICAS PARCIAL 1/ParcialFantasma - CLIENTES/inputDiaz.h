void getStringAlpha(int longMax, char* mensaje, char* dondeAsignar);

int getIntRange(int* dondeAsignar, int min, int max, char* mensaje);

void getSexo(char* dondeAsignar, char* mensaje);

int getChar(int intentos, char* dondeAsignar, char* mensaje);

int getFloatRange(float min, float max, float* dondeAsignar, char* mensaje);

int confimarSalir(char* mensaje);

void getStringAlphaNum(int longMax, char* mensaje, char* dondeAsignar);

void pedirTelefono (char* var_dondeAsignar, int longitudMaxString, char* mensaje);

void pedirEmail (char* var_dondeAsignar, int longitudMaxString, char* mensaje);

int isValidTelephone(char* stringRecibido);

int getTelefono(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, char* dondeAsignar);

void pedirSexo(char* dondeAsignar, char* mensaje);
