
#include "RemplacerMotConfig.hpp"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

namespace depistage { namespace gui {

RemplacerMotConfig::RemplacerMotConfig( const QString & labelStr, const QString & motARemplacer,
                                        QWidget * parent )
	: QWidget( parent )
{
   QHBoxLayout * mainLayout = new QHBoxLayout();

   QLabel * labelRemplacer = new QLabel( tr( "Gestion de " ) + labelStr + ". Remplacer " );
   mainLayout->addWidget( labelRemplacer );
   m_motARemplacer = new QLineEdit();
   m_motARemplacer->setText( motARemplacer );
   mainLayout->addWidget( m_motARemplacer );
   
   setLayout( mainLayout );
}

QString RemplacerMotConfig::motARemplacer() const
{
   return m_motARemplacer->text();
}

} }
