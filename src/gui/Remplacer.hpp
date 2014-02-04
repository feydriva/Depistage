
#ifndef DEPISTAGE_GUI_REMPLACER_HPP
#define DEPISTAGE_GUI_REMPLACER_HPP

#include <QtCore/QString>

#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class Remplacer : public QWidget
{
   Q_OBJECT
public :
   Remplacer( QWidget * parent = nullptr );
   virtual QString motParLequelRemplacer() const = 0;
};

} }

#endif
