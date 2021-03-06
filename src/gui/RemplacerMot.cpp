
#include "RemplacerMot.hpp"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

namespace depistage { namespace gui {

RemplacerMot::RemplacerMot( const QString & labelStr,
                            const QString & valeurParDefaut,
                            QWidget * parent )
   : Remplacer( parent )
{
   QHBoxLayout * mainLayout = new QHBoxLayout();

   QLabel * labelMotRemplacer = new QLabel( labelStr + " : " );
   mainLayout->addWidget( labelMotRemplacer );
   m_motParLequelRemplacer = new QLineEdit();
   m_motParLequelRemplacer->setText( valeurParDefaut );
   mainLayout->addWidget( m_motParLequelRemplacer );
   connect( m_motParLequelRemplacer, SIGNAL( textChanged( const QString & ) ),
            this,                    SIGNAL( texteModifie( const QString & ) ) );
   
   setLayout( mainLayout );
}

QString RemplacerMot::motParLequelRemplacer() const
{
   return m_motParLequelRemplacer->text();
}

} }
