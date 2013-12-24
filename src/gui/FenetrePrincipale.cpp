
#include "FenetrePrincipale.hpp"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

// debug à virer !
#include <office/Word.hpp>
#include <office/WordDocument.hpp>
// fin debug à virer !

namespace depistage { namespace gui {

FenetrePrincipale::FenetrePrincipale( QWidget * parent )
	: QMainWindow( parent )
{
   QWidget * mainWidget = new QWidget();
   QGridLayout * mainLayout = new QGridLayout();

   int row = 0;

   m_motRemplacerChat = new RemplacerMot( "chat" );
   mainLayout->addWidget( m_motRemplacerChat, row++, 0 );
   
   m_motRemplacerTest = new RemplacerMotConfig();
   mainLayout->addWidget( m_motRemplacerTest, row++, 0 );
   
   m_wordTest = new SelectionFichier( tr( "Word de test : " ) );
   mainLayout->addWidget( m_wordTest, row++, 0 );
   
   QPushButton * boutonTest = new QPushButton( tr( "Lancer test" ) );
   mainLayout->addWidget( boutonTest, row++, 0 );

   connect( boutonTest, SIGNAL( clicked() ),
            this,       SLOT(   remplacer() ) );
   
   mainWidget->setLayout( mainLayout );
   setCentralWidget( mainWidget );
}

// debug à virer !
void FenetrePrincipale::remplacer()
{
   depistage::office::Word word;
   depistage::office::WordDocument document = word.open( m_wordTest->getChemin().toStdString() );
   document.replace( "chat", "lion" );
}
// fin debug à virer !

} }
