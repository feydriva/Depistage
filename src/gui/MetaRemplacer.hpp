
#ifndef DEPISTAGE_GUI_META_REMPLACER_HPP
#define DEPISTAGE_GUI_META_REMPLACER_HPP

#include "ElementGUI.hpp"
#include "RemplacerMot.hpp"
#include "RemplacerMotConfig.hpp"

#include <QtCore/QObject>
#include <QtCore/QString>

#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class MetaRemplacer : public ElementGUI
{
   Q_OBJECT
public :
   MetaRemplacer( const QString & labelStr, const QString & m_motARemplacer,
                  QWidget * parentWidget = nullptr );
   virtual QWidget * widgetBasic() const override;
   virtual QWidget * widgetConfig() const override;

private :
   RemplacerMot * m_remplacerBasic;
   RemplacerMotConfig * m_remplacerConfig;
};

} }

#endif
