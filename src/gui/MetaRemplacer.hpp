
#ifndef DEPISTAGE_GUI_META_REMPLACER_HPP
#define DEPISTAGE_GUI_META_REMPLACER_HPP

#include "ElementGUI.hpp"
#include "Remplacer.hpp"
#include "RemplacerConfig.hpp"
#include "RemplacerConfig.hpp"

#include <QtCore/QObject>
#include <QtCore/QString>

#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class MetaRemplacer : public ElementGUI
{
   Q_OBJECT
public :
   MetaRemplacer( Remplacer * widgetRemplacer,
                  const QString & labelStr,
                  const QString & m_motARemplacer,
                  QWidget * parentWidget = nullptr );

   virtual QWidget * widgetBasic() const override;
   virtual QWidget * widgetConfig() const override;

   QString motParLequelRemplacer( ) const;
   QString motARemplacer( ) const;

private :
   Remplacer * m_remplacerBasic;
   RemplacerConfig * m_remplacerConfig;
};

} }

#endif
