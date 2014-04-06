
#include <Chargement.hpp>

#include <gui/FenetrePrincipale.hpp>

#include <main/ProgrammeEnregistrement.hpp>
#include <main/ProgrammeEtiquettes.hpp>

#include <QApplication>

#include <vector>

int main( int argc, char *argv[] )
{
   QApplication app(argc, argv);

   depistage::config::ConfigProgrammes configs = depistage::main::chargerProgrammes();

   depistage::main::ProgrammeEtiquettes programmeEtiquettes( configs );
   depistage::main::ProgrammeEnregistrement programmeEnregistrement( configs );
   std::vector< depistage::main::Programme * > programmes;
   programmes.push_back( &programmeEnregistrement );
   programmes.push_back( &programmeEtiquettes );

   depistage::gui::FenetrePrincipale fenetre( programmes );
   fenetre.show();

   return app.exec();
}
