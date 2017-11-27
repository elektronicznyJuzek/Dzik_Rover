#include <QCoreApplication>
#include "Robot.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    Robot Dzik0;
    
    Dzik0.read_data_from_WorkStation();
    
    return a.exec();
}

// 0 krok: utworz folderw ktorym chcesz umiescic projket
// I krok: $ qmake -project -- tworzy plik projektu nazwa_folderu.pro
// II krok: $ qmake nazwa_folderu.pro -- tworzy MakeFile
// III krok: $ make -- kompilacja
// IV krok: $ ./nazwa_folderu