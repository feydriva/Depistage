
#include "RemplacerDate.hpp"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

namespace depistage { namespace gui {

RemplacerDate::RemplacerDate( const QString & labelStr, const QDate & date, QWidget * parent)
   : Remplacer( parent )
{
   QHBoxLayout * mainLayout = new QHBoxLayout();

   QLabel * labelMotRemplacer = new QLabel( labelStr + " : " );
   mainLayout->addWidget( labelMotRemplacer );
   m_motParLequelRemplacer = new QDateEdit( date );
   m_motParLequelRemplacer->setDisplayFormat( "dd/MM/yyyy" );
   mainLayout->addWidget( m_motParLequelRemplacer );
   
   setLayout( mainLayout );
}

QString RemplacerDate::motParLequelRemplacer( ) const
{
   return m_motParLequelRemplacer->text();
}

} }
