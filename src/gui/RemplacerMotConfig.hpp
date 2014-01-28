
#ifndef DEPISTAGE_GUI_REMPLACER_MOT_CONFIG_HPP
#define DEPISTAGE_GUI_REMPLACER_MOT_CONFIG_HPP

#include <QtCore/QString>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class RemplacerMotConfig : public QWidget
{
   Q_OBJECT
public :
   RemplacerMotConfig( const QString & labelStr, const QString & motARemplacer,
                       QWidget * parent = nullptr );
   QString motARemplacer() const;

private :
   QLineEdit * m_motARemplacer;
};

} }

#endif
