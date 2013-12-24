
#include "RemplacerMotConfig.hpp"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

namespace depistage { namespace gui {

RemplacerMotConfig::RemplacerMotConfig( QWidget * parent )
	: QWidget( parent )
{
   QHBoxLayout * mainLayout = new QHBoxLayout();

   QLabel * labelRemplacer = new QLabel( tr( "Remplacer " ) );
   mainLayout->addWidget( labelRemplacer );
   m_motARemplacer = new QLineEdit();
   mainLayout->addWidget( m_motARemplacer );
   QLabel * labelPar = new QLabel( tr( " par " ) );
   mainLayout->addWidget( labelPar );
   m_motParLequelRemplacer = new QLineEdit();
   mainLayout->addWidget( m_motParLequelRemplacer );
   
   setLayout( mainLayout );
}

QString RemplacerMotConfig::motARemplacer() const
{
   return m_motARemplacer->text();
}

QString RemplacerMotConfig::motParLequelRemplacer() const
{
   return m_motParLequelRemplacer->text();
}

} }
