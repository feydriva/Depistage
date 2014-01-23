
#include "BoutonAction.hpp"

#include "BoutonActionWidget.hpp"

namespace depistage { namespace gui {

BoutonAction::BoutonAction( const QString & labelStr, QWidget * parent )
   : m_widgetBasic( new BoutonActionWidget( labelStr, parent ) )
{
   connect( m_widgetBasic, SIGNAL( clique( ) ),
            this,          SIGNAL( clique() ) );
}

QWidget * BoutonAction::widgetBasic( ) const
{
   return m_widgetBasic;
}

QWidget * BoutonAction::widgetConfig( ) const
{
   return nullptr;
}

} }
