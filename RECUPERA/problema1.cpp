#include <iostream>

class DiskDrive {
    public:
        // Atributos
        int diskSize; // Tamano del disco en GB
        int sectorsPerTrack; // Numero de sectores por pista
        int diskPlates; // Numero de platos del disco
        const int bytesPerSector = 512; // Numero de bytes por sector

        // Constructor
        DiskDrive(int size, int sectors) {
            diskSize = size;
            sectorsPerTrack = sectors;
        }

        // Metodo para calcular el numero total de sectores
        int getTotalSectors() {
            return (diskSize * 1000000000) / bytesPerSector;
        }

        // Metodo para leer el numero de pistas o platos y calcular el otro valor
        void leerDiscoPlato() {
            char option;
            std::cout << "Quieres ingresar el numero de pistas (T) o el numero de platos (P)? ";
            std::cin >> option;
            if (option == 'T' || option == 't') {
                int tracks;
                std::cout << "Ingrese el numero de pistas: ";
                std::cin >> tracks;
                diskPlates = diskSize / (sectorsPerTrack * tracks);
                std::cout << "El numero de platos es: " << diskPlates << "\n";
            }
            else if (option == 'P' || option == 'p') {
                int plates;
                std::cout << "Ingrese el numero de platos: ";
                std::cin >> plates;
                diskPlates = plates;
                int tracks = diskSize / (sectorsPerTrack * plates);
                std::cout << "El numero de pistas es: " << tracks << "\n";
            }
            else {
                std::cout << "Opcion invalida.\n";
            }
        }

        // Metodo para imprimir los atributos del disco
        void imprimirInformacion() {
            std::cout << "Tamano del disco: " << diskSize << " GB\n";
            std::cout << "Numero total de sectores: " << getTotalSectors() << "\n";
            std::cout << "Numero de sectores por pista: " << sectorsPerTrack << "\n";
            std::cout << "Numero de platos del disco: " << diskPlates << "\n";
        }
};

int main() {
    // Leer el tamano del disco y el numero de sectores por pista desde la consola
    int size, sectors;
    std::cout << "Ingrese el tamano del disco en GB: ";
    std::cin >> size;
    std::cout << "Ingrese el numero de sectores por pista: ";
    std::cin >> sectors;

    // Crear un objeto de la clase DiskDrive con los datos ingresados
    DiskDrive disk(size, sectors);

    // Leer el numero de pistas o platos y calcular el otro valor
    disk.leerDiscoPlato();

    // Imprimir la informacion del disco
    disk.imprimirInformacion();

    return 0;
}