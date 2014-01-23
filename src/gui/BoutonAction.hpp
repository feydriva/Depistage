
#ifndef DEPISTAGE_GUI_BOUTON_ACTION_HPP
#define DEPISTAGE_GUI_BOUTON_ACTION_HPP

#include "ElementGUI.hpp"

#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class BoutonAction : public ElementGUI
{
   Q_OBJECT
public :
   BoutonAction( const QString & labelStr, QWidget * parent = nullptr );

   virtual QWidget * widgetBasic() const override;
   virtual QWidget * widgetConfig() const override;

private :
   QWidget * m_widgetBasic;

signals:
   void clique();
};

} }

#endif
