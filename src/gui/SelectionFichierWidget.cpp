
#include "SelectionFichierWidget.hpp"

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

namespace depistage { namespace gui {

SelectionFichierWidget::SelectionFichierWidget( const QString & labelStr, const QString & message,
                                                const QString & filtre, QWidget * parent )
	: QWidget( parent ),
     m_message( message ), m_filtre( filtre )
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

QString SelectionFichierWidget::getChemin() const
{
   return m_wordTest->text();
}

void SelectionFichierWidget::parcourir()
{
   const QString chemin = QFileDialog::getOpenFileName(this, m_message, getChemin(), m_filtre);
   m_wordTest->setText(chemin);
}

} }
