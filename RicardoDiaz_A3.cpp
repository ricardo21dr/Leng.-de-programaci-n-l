#include <iostream>
#include <string>

// funcion para obtener la primer bocal interna del texto
char obtenerprimeravocalinterna(const std::string& str) {
    for (size_t i = 1;i < str.length(); ++i) {
        char c = str[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
        
        return c;
    } 
    return 'X'; // si no encuentra ninguna vocal interna se usa X
}
// Funcion principal para calcular RFC
std::string calcularRFC(const std::string& nombre, const std::string& apellidopaterno, const std::string& apellidomaterno, const std::string& aniodenacimiento, const std::string& mesdenacimiento, const std::string& diadenacimiento) {
    std::string rfc;
 
    // Se obtiene la letra inicial y la primera vocal interma del apellido apellidopaterno
    char letrainicial = apellidopaterno[0];
    char primeravocalinterna = obtenerprimeravocalinterna(apellidopaterno);
    
    //se obtiene la inicial del apllido materno o se usa un "X" si no hay
    char inicialapellidomaterno = (!apellidomaterno.empty()) ? apellidomaterno[0] : 'X';
    
    //Se obtiene la inicial del primer nombre o se una "X" si no hay 
    char inicialnombre = nombre[0];
    
    //se obtiene los dos ultimos digitos del año de fechadenacimineto
    std::string anio = aniodenacimiento.substr(2, 2);
    
    //se obtiene el mes y el dia de fechadenacimiento 
    std::string mes = mesdenacimiento.substr(0, 2);
    std::string dia = diadenacimiento.substr(0, 2);
    
    // se construye el rfc
    rfc = letrainicial;
    rfc += primeravocalinterna;
    rfc += inicialapellidomaterno;
    rfc += inicialnombre;
    rfc += anio;
    rfc += mes;
    rfc += dia;
    return rfc;
}
    
int main() {
    std::string nombre, apellidopaterno, apellidomaterno, aniodenacimiento, mesdenacimiento, diadenacimiento;
    
    std::cout <<"Ingrese el nombre: ";
    std::getline(std::cin, nombre);

    std::cout <<"Ingrese el apellido paterno: ";
    std::getline(std::cin, apellidopaterno);
    
    std::cout << "ingrese el apellido materno (si no tiene, presione la tecla enter): ";
    std::getline(std::cin, apellidomaterno);
    
    std::cout << "ingrese el dia de nacimeinto (DD): ";
    std::getline(std::cin, diadenacimiento);
    
    std::cout << "ingrese el mes de nacimiento (MM): ";
    std::getline(std::cin, mesdenacimiento);    
    
    std::cout << "ingrese el año de nacimiento (YYYY): ";
    std::getline(std::cin, aniodenacimiento);    
   
    std::string rfc = calcularRFC(nombre, apellidopaterno, apellidomaterno, aniodenacimiento, mesdenacimiento, diadenacimiento);
    std::cout <<  "RFC: " << rfc << std::endl;
    return 0;      //RICARDO DIAZ
}