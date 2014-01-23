
#ifndef DEPISTAGE_GUI_BOUTON_ACTION_WIDGET_HPP
#define DEPISTAGE_GUI_BOUTON_ACTION_WIDGET_HPP

#include <QtCore/QString>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class BoutonActionWidget : public QWidget
{
   Q_OBJECT
public:
   BoutonActionWidget( const QString & labelStr, QWidget * parent = nullptr);

signals:
   void clique();
};

} }

#endif
