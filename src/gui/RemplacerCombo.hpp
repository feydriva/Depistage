
#ifndef DEPISTAGE_GUI_REMPLACER_COMBO_HPP
#define DEPISTAGE_GUI_REMPLACER_COMBO_HPP

#include "Remplacer.hpp"

#include <QtCore/QString>

#include <QtWidgets/QComboBox>

namespace depistage { namespace gui {

class RemplacerCombo : public Remplacer
{
   Q_OBJECT
public :
   RemplacerCombo( const QString & labelStr,
                   const std::vector< QString > & choix,
                   QWidget * parent = nullptr );
   virtual QString motParLequelRemplacer() const override;

private :
   QComboBox * m_motParLequelRemplacer;
};

} }

#endif
