
#include <gui/FenetrePrincipale.hpp>

#include <main/ProgrammeEtiquettes.hpp>

#include <QApplication>


//#include <office/Word.hpp>
//#include <office/WordDocument.hpp>

int main( int argc, char *argv[] )
{
   QApplication app(argc, argv);

   depistage::main::ProgrammeEtiquettes programmeEtiquettes;

   depistage::gui::FenetrePrincipale fenetre( programmeEtiquettes.getElementsGUI( ) );
   fenetre.show();

//   depistage::office::Word word;
//   depistage::office::WordDocument document = word.open( "C:\\test.doc" );
//   document.replace( "chat", "lion" );

   return app.exec();
}
