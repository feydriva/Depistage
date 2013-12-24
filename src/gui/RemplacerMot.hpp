
#ifndef DEPISTAGE_GUI_REMPLACER_MOT_HPP
#define DEPISTAGE_GUI_REMPLACER_MOT_HPP

#include <QtCore/QString>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class RemplacerMot : public QWidget
{
   Q_OBJECT
public :
   RemplacerMot( const QString & labelStr, QWidget * parent = nullptr );
   QString motParLequelRemplacer() const;

private :
   QLineEdit * m_motParLequelRemplacer;
};

} }

#endif
