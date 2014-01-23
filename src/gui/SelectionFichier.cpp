
#include "SelectionFichier.hpp"

#include "SelectionFichierWidget.hpp"

namespace depistage { namespace gui {

SelectionFichier::SelectionFichier(const QString & labelStr, const QString & message,
                                                const QString & filtre, QWidget * parent )
	: m_widgetConfig( new SelectionFichierWidget( labelStr, message, filtre, parent ) )
{
}

QWidget * SelectionFichier::widgetBasic() const
{
   return nullptr;
}

QWidget * SelectionFichier::widgetConfig() const
{
   return m_widgetConfig;
}

} }
