
#ifndef DEPISTAGE_GUI_WIDGET_TEXTE_READ_ONLY_HPP
#define DEPISTAGE_GUI_WIDGET_TEXTE_READ_ONLY_HPP

#include <QtCore/QString>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class WidgetTexteReadOnly : public QWidget
{
   Q_OBJECT
public:
   WidgetTexteReadOnly( const QString & labelStr,
                        const QString & texte,
                        QWidget * parent = nullptr );

   void setTexte( const QString & texte );
   QString getTexte() const;

private:
   QLineEdit * m_texte;
};

} }

#endif
