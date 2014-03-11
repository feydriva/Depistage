
#include "WidgetTexteReadOnly.hpp"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

namespace depistage { namespace gui {

WidgetTexteReadOnly::WidgetTexteReadOnly( const QString & labelStr,
                                         const QString & texte,
                                         QWidget * parent )
   : QWidget( parent )
{
   QHBoxLayout * mainLayout = new QHBoxLayout();

   QLabel * label = new QLabel( labelStr );
   mainLayout->addWidget( label );

   m_texte = new QLineEdit();
   m_texte->setReadOnly( true );
   setTexte( texte );
   mainLayout->addWidget( m_texte );

   setLayout( mainLayout );
}

void WidgetTexteReadOnly::setTexte( const QString & texte )
{
   m_texte->setText( texte );
}

QString WidgetTexteReadOnly::getTexte() const
{
   return m_texte->text();
}

} }
