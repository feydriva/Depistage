
#include "gui/FenetrePrincipale.hpp"

#include <QApplication>

#include <QAxObject>
#include <QAxWidget>

#include <iostream>

int main( int argc, char *argv[] )
{
   QApplication app(argc, argv);
   depistage::gui::FenetrePrincipale fenetre;
   
   
   fenetre.show();
   return app.exec();
}
