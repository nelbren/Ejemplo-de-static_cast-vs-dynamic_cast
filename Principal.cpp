// 2020-08-26 - nelbren@nelbren.com 
#include <iostream>
#include <vector>
#include "SistemaOperativo.hpp"
#include "Linux.hpp"
#include "Mac.hpp"
#include "Windows.hpp"
#define dynamic // Comentarme para proceder con static_cast
int main() {
  vector < SistemaOperativo* > sistemas_operativos( 4 );
  sistemas_operativos[0] = new Linux("npro-vps-02", eLinux, 200);
  sistemas_operativos[1] = new Mac("MBP01-755", eMac, 150);
  sistemas_operativos[2] = new Windows("DESKTOP-I9BGAN1", eWindows, 350);
  sistemas_operativos[3] = new Linux("npro-vps-03", eLinux, 201);
  for ( SistemaOperativo *soPtr : sistemas_operativos ) {
    soPtr->imprimir();
    // intenta conversión descendente del apuntador
    #ifdef dynamic
    Linux *derivadaPtr = dynamic_cast < Linux * >( soPtr );
    #else
    Linux *derivadaPtr = static_cast < Linux * >( soPtr );
    #endif
    if ( derivadaPtr != nullptr ) {
       derivadaPtr->distro = "debian";
       cout << "   " << derivadaPtr->nombre() << " => " << derivadaPtr->distro; 
       cout << " - Paquetes: " << derivadaPtr->aplicaciones() << endl;
    }
  }
  return 0;
}