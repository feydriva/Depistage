
#include "FenetrePrincipale.hpp"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>

namespace depistage { namespace gui {


FenetrePrincipale::FenetrePrincipale( const std::vector< main::Programme * > & programmes,
                                      QWidget * parent )
   : QMainWindow( parent )
{
   QTabWidget * tabs = new QTabWidget();
   for ( const main::Programme * programme : programmes )
   {
      tabs->addTab( creerWidgetProgramme( *programme ), programme->getTitre() );
   }
   setCentralWidget( tabs );
}

QWidget * FenetrePrincipale::creerWidgetProgramme( const main::Programme & programme )
{
   std::vector< depistage::gui::ElementGUI * > widgets = programme.getElementsGUI();
   QWidget * mainWidget = new QWidget();
   QGridLayout * mainLayout = new QGridLayout();

   QVBoxLayout * basicLayout = new QVBoxLayout();
   QVBoxLayout * configLayout = new QVBoxLayout();

   int row = 0;
   for ( depistage::gui::ElementGUI * elementGui : widgets )
   {
      if ( elementGui->widgetBasic() != nullptr )
      {
         basicLayout->addWidget( elementGui->widgetBasic() );
      }
      if ( elementGui->widgetConfig() != nullptr )
      {
         configLayout->addWidget( elementGui->widgetConfig() );
      }
   }

   QPushButton * sauvButton = new QPushButton( tr( "Sauvegarder la configuration" ) );
   configLayout->addWidget( sauvButton );
   connect( sauvButton, SIGNAL( clicked() ),
            &programme, SLOT( sauverConfig() ) );

   mainLayout->addLayout( basicLayout, row++, 0 );

   QPushButton * boutonConfig = new QPushButton( tr( "Afficher la configuration" ) );
   boutonConfig->setCheckable( true );
   boutonConfig->setChecked( false );
   mainLayout->addWidget( boutonConfig, row++, 0 );
   connect( boutonConfig, SIGNAL( clicked( bool ) ),
            this,           SLOT( configOnOff( bool ) ) );
   m_configButtons.push_back( boutonConfig );

   QWidget * widgetConfig = new QWidget();
   widgetConfig->setLayout( configLayout );
   widgetConfig->hide();
   mainLayout->addWidget( widgetConfig, row++, 0 );
   m_configWidgets.push_back( widgetConfig );

   mainWidget->setLayout( mainLayout );
   return mainWidget;
}

void FenetrePrincipale::configOnOff( bool checked )
{
   for ( QPushButton * bouton : m_configButtons )
   {
      if ( bouton->isChecked() != checked )
      {
         bouton->setChecked( checked );
      }
   }
   for ( QWidget * configWidget : m_configWidgets )
   {
      configWidget->setVisible( checked );
   }
}

} }
