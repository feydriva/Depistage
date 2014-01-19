
#ifndef DEPISTAGE_GUI_ELEMENT_GUI_HPP
#define DEPISTAGE_GUI_ELEMENT_GUI_HPP

#include <QtCore/QObject>
#include <QtCore/QString>

#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class ElementGUI : public QObject
{
   Q_OBJECT
public :
   virtual QWidget * widgetBasic() const = 0;
   virtual QWidget * widgetConfig() const = 0;
};

} }

#endif
