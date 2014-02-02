
#ifndef DEPISTAGE_GUI_REMPLACER_MOT_HPP
#define DEPISTAGE_GUI_REMPLACER_MOT_HPP

#include "Remplacer.hpp"

#include <QtCore/QString>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class RemplacerMot : public Remplacer
{
   Q_OBJECT
public :
   RemplacerMot( const QString & labelStr, QWidget * parent = nullptr );
   virtual QString motParLequelRemplacer() const override;

private :
   QLineEdit * m_motParLequelRemplacer;

signals:
   void texteModifie( const QString & nouveauTexte );
};

} }

#endif
