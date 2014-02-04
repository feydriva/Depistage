
#include "BasicElementGUI.hpp"

namespace depistage { namespace gui {

BasicElementGUI::BasicElementGUI( QWidget * widgetBasic, QWidget * widgetConfig )
: m_widgetBasic( widgetBasic ), m_widgetConfig( widgetConfig )
{
}

QWidget * BasicElementGUI::widgetBasic() const
{
   return m_widgetBasic;
}

QWidget * BasicElementGUI::widgetConfig() const
{
   return m_widgetConfig;
}

} }
