
#include "FenetrePrincipale.hpp"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

// debug à virer !
#include <office/Word.hpp>
#include <office/WordDocument.hpp>
#include <office/Excel.hpp>
#include <office/ExcelDocument.hpp>
// fin debug à virer !

namespace depistage { namespace gui {

FenetrePrincipale::FenetrePrincipale( const main::ProgrammeEtiquettes & programme,
                                      QWidget * parent )
   : QMainWindow( parent )
{
   std::vector< depistage::gui::ElementGUI * > widgets = programme.getElementsGUI();
   QWidget * mainWidget = new QWidget();
   QGridLayout * mainLayout = new QGridLayout();
   
   QVBoxLayout * basicLayout = new QVBoxLayout();
   QVBoxLayout * configLayout = new QVBoxLayout();

   int row = 0;
   for ( std::vector< depistage::gui::ElementGUI * >::const_iterator iteWidget = widgets.begin();
         iteWidget != widgets.end();
         ++iteWidget )
   {
      if ((*iteWidget)->widgetBasic() != nullptr)
      {
         basicLayout->addWidget( (*iteWidget)->widgetBasic() );
      }
      if ((*iteWidget)->widgetConfig() != nullptr)
      {
         configLayout->addWidget((*iteWidget)->widgetConfig());
      }
   }

   QPushButton * sauvButton = new QPushButton( tr( "Sauvegarder la configuration" ) );
   configLayout->addWidget( sauvButton );
   connect( sauvButton, SIGNAL( clicked( ) ),
            &programme, SLOT( sauverConfig( ) ) );

   mainLayout->addLayout( basicLayout, row++, 0 );

   m_configButton = new QPushButton( tr( "Afficher la configuration" ) );
   m_configButton->setCheckable( true );
   m_configButton->setChecked( false );
   mainLayout->addWidget( m_configButton, row++, 0 );
   connect( m_configButton, SIGNAL( clicked() ),
            this,           SLOT(   configOnOff() ) );
   
   m_configWidget = new QWidget();
   m_configWidget->setLayout( configLayout );
   m_configWidget->hide();
   mainLayout->addWidget( m_configWidget, row++, 0 );

   /*m_motRemplacerChat = new RemplacerMot( "chat" );
   mainLayout->addWidget( m_motRemplacerChat, row++, 0 );
   
   m_motRemplacerTest = new RemplacerMotConfig();
   mainLayout->addWidget( m_motRemplacerTest, row++, 0 );*/
   
   /*m_wordTest = new SelectionFichier( tr( "Word de test : " ),
                                      tr( "Ouvrir un document Word" ), tr( "Word files (*.doc *.docx)" ) );
   mainLayout->addWidget( m_wordTest, row++, 0 );
   
   QPushButton * boutonTestWord = new QPushButton( tr( "Lancer test" ) );
   mainLayout->addWidget( boutonTestWord, row++, 0 );

   connect( boutonTestWord, SIGNAL( clicked() ),
            this,           SLOT(   remplacer() ) );
   
   m_excelTest = new SelectionFichier( tr( "Excel de test : " ),
                                      tr( "Ouvrir un document Excel" ), tr( "Word files (*.xls *.xlsx)" ) );
   mainLayout->addWidget( m_excelTest, row++, 0 );
   
   QPushButton * boutonTestExcel = new QPushButton( tr( "Lancer test" ) );
   mainLayout->addWidget( boutonTestExcel, row++, 0 );

   connect( boutonTestExcel, SIGNAL( clicked() ),
            this,            SLOT(   ajouter() ) );*/
   
   mainWidget->setLayout( mainLayout );
   setCentralWidget( mainWidget );
}

// debug à virer !
//void FenetrePrincipale::remplacer()
//{
//   depistage::office::Word word;
//   depistage::office::WordDocument document = word.open( m_wordTest->getChemin().toStdString() );
//   document.replace( "chat", "lion" );
//}

//void FenetrePrincipale::ajouter()
//{
//   depistage::office::Excel excel;
//   depistage::office::ExcelDocument document = excel.open( m_excelTest->getChemin().toStdString() );
//   depistage::office::ExcelOnglet onglet = document.recupererOnglet( 1 );
//   std::vector< std::string > informations;
//   informations.push_back( "Toto" );
//   onglet.ajouterLigne( informations );
//}

// fin debug à virer !

void FenetrePrincipale::configOnOff()
{
   m_configWidget->setVisible( m_configButton->isChecked() );
}

} }
