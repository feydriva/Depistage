
#include "WidgetCompteur.hpp"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

namespace depistage { namespace gui {

WidgetCompteur::WidgetCompteur( const QString & labelStr, QWidget * parent )
   : QWidget( parent )
{
   QHBoxLayout * mainLayout = new QHBoxLayout();

   QLabel * label = new QLabel( labelStr );
   mainLayout->addWidget( label );

   m_compteur = new QSpinBox();
   m_compteur->setRange( 1, 100 );
   connect( m_compteur, SIGNAL( valueChanged( int ) ),
            this,       SIGNAL( nouvelleValeur( int ) ) );
   mainLayout->addWidget( m_compteur );
   
   setLayout( mainLayout );
}

int WidgetCompteur::getNombre() const
{
   return m_compteur->value();
}

} }
