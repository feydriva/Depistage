
#include "gui/FenetrePrincipale.hpp"

#include <QApplication>

int main( int argc, char *argv[] )
{
   QApplication app(argc, argv);
   depistage::gui::FenetrePrincipale fenetre;
   fenetre.show();
   return app.exec();
}
