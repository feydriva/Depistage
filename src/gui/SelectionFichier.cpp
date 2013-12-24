
#include "SelectionFichier.hpp"

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

namespace depistage { namespace gui {

SelectionFichier::SelectionFichier( const QString & labelStr, QWidget * parent )
	: QWidget( parent )
{
   QHBoxLayout * mainLayout = new QHBoxLayout();

   QLabel * label = new QLabel( labelStr );
   mainLayout->addWidget( label );
   m_wordTest = new QLineEdit();
   m_wordTest->setReadOnly( true );
   mainLayout->addWidget( m_wordTest );
   QPushButton * pushButton = new QPushButton( tr( "Parcourir" ) );
   mainLayout->addWidget( pushButton );

   connect( pushButton, SIGNAL( clicked() ),
            this,       SLOT(   parcourir() ) );
   
   setLayout( mainLayout );
}

QString SelectionFichier::getChemin() const
{
   return m_wordTest->text();
}

void SelectionFichier::parcourir()
{
   const QString chemin =
      QFileDialog::getOpenFileName( this,
                                    tr( "Open Word" ),
                                    getChemin(),
                                    tr( "Word files (*.doc *.docx)" ) );
   m_wordTest->setText( chemin );
}

} }
