typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int legajo;
    int isEmpty; // 0 para libre. 1 para ocupado
}Employee;

int initEmployees(Employee empleado[], int largo, int valor);

int addEmployee(Employee empleado[], int CANT, int i,int idIncremental);

int findEmployeeById(Employee empleado[], int i,int id);

int modifyEmployee(Employee empleado[], int CANT);

int removeEmployee(Employee empleado[], int CANT, int id);

void sortEmployee(Employee empleado[],int arrayLenght);

int printEmployees(Employee empleado[], int CANT);

float sumaSalary(Employee empleado[], int CANT);

int contadorEmployees(Employee empleado[], int CANT);

int contadorArribaPromedio(Employee empleado[], int CANT, int promedioSalario, int contador);
