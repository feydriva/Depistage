
#include <gui/FenetrePrincipale.hpp>

#include <QApplication>

//#include <office/Word.hpp>
//#include <office/WordDocument.hpp>

#include <gui/ElementGUI.hpp>
#include <gui/MetaRemplacer.hpp>

int main( int argc, char *argv[] )
{
   QApplication app(argc, argv);

   std::vector< depistage::gui::ElementGUI * > widgets;
   widgets.push_back( new depistage::gui::MetaRemplacer( "Code patient", "@@code@@" ) );
   widgets.push_back( new depistage::gui::MetaRemplacer( "Sex", "@@sex@@" ) );
   widgets.push_back( new depistage::gui::MetaRemplacer( "Date de naissance", "@@dateNaissance@@" ) );

   depistage::gui::FenetrePrincipale fenetre( widgets );
   fenetre.show();

//   depistage::office::Word word;
//   depistage::office::WordDocument document = word.open( "C:\\test.doc" );
//   document.replace( "chat", "lion" );

   return app.exec();
}
