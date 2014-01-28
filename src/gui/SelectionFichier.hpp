
#ifndef DEPISTAGE_GUI_SELECTION_FICHIER_HPP
#define DEPISTAGE_GUI_SELECTION_FICHIER_HPP

#include "ElementGUI.hpp"

#include "SelectionFichierWidget.hpp"

#include <QtCore/QString>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class SelectionFichier : public ElementGUI
{
   Q_OBJECT
public :
   SelectionFichier( const QString & labelStr, const QString & message,
                     const QString & filtre, QWidget * parent = nullptr );

   virtual QWidget * widgetBasic() const override;
   virtual QWidget * widgetConfig() const override;

   QString getChemin() const;

private :
   SelectionFichierWidget * m_widgetConfig;
};

} }

#endif
