
#include "SelectionFichier.hpp"

namespace depistage { namespace gui {

SelectionFichier::SelectionFichier( bool estFichier,
                                    const QString & labelStr,
                                    const QString & message,
                                    const QString & filtre,
                                    const QString & chemin,
                                    QWidget * parent )
   : m_widgetConfig(
        new SelectionFichierWidget( estFichier, labelStr, message, filtre, chemin, parent ) )
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

QString SelectionFichier::getChemin() const
{
   return m_widgetConfig->getChemin();
}

} }
