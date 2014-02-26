
#ifndef DEPISTAGE_GUI_REMPLACER_DATE_HPP
#define DEPISTAGE_GUI_REMPLACER_DATE_HPP

#include "Remplacer.hpp"

#include <QtCore/QString>

#include <QtWidgets/QDateEdit>

namespace depistage { namespace gui {

class RemplacerDate : public Remplacer
{
   Q_OBJECT
public :
   RemplacerDate( const QString & labelStr, const QDate & date, QWidget * parent = nullptr );
   virtual QString motParLequelRemplacer() const override;

private :
   QDateEdit * m_motParLequelRemplacer;
};

} }

#endif
