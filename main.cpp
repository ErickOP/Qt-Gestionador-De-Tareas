#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    //Libreria para el idioma
    QTranslator T;
    QStringList langs;
    langs << "Español" << "English";
    const QString lang = QInputDialog::getItem(NULL,
                          "Lenguaje",
                          "Selecciona un lenguaje",
                          langs);
    //Si tal idioma esta, se cambia si no va la de origen.
   if (lang == "English"){
       T.load(":/ingles.qm");
    }
   if (lang != "Español"){
       a.installTranslator(&T);
     }
    principal w;
    a.setStyle("fusion");
    w.show();
    return a.exec();
}
