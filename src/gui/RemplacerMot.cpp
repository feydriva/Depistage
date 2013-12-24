
#include "RemplacerMot.hpp"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

namespace depistage { namespace gui {

RemplacerMot::RemplacerMot( const QString & labelStr, QWidget * parent )
	: QWidget( parent )
{
   QHBoxLayout * mainLayout = new QHBoxLayout();

   QLabel * labelMotRemplacer = new QLabel( labelStr + " : " );
   mainLayout->addWidget( labelMotRemplacer );
   m_motParLequelRemplacer = new QLineEdit();
   mainLayout->addWidget( m_motParLequelRemplacer );
   
   setLayout( mainLayout );
}

QString RemplacerMot::motParLequelRemplacer() const
{
   return m_motParLequelRemplacer->text();
}

} }
