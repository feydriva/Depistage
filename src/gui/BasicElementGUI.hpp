
#ifndef DEPISTAGE_GUI_BASIC_ELEMENT_GUI_HPP
#define DEPISTAGE_GUI_BASIC_ELEMENT_GUI_HPP

#include "ElementGUI.hpp"

#include <QtCore/QObject>
#include <QtCore/QString>

#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class BasicElementGUI : public ElementGUI
{
   Q_OBJECT
public :
   BasicElementGUI( QWidget * widgetBasic, QWidget * widgetConfig );

   virtual QWidget * widgetBasic() const;
   virtual QWidget * widgetConfig() const;

private :
   QWidget * m_widgetBasic;
   QWidget * m_widgetConfig;
};

} }

#endif
