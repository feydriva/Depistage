
#ifndef DEPISTAGE_GUI_WIDGET_COMPTEUR_HPP
#define DEPISTAGE_GUI_WIDGET_COMPTEUR_HPP

#include <QtCore/QString>

#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class WidgetCompteur : public QWidget
{
   Q_OBJECT
public:
   WidgetCompteur( const QString & labelStr, QWidget * parent = nullptr );
   int getNombre() const;

private:
   QSpinBox * m_compteur;

signals:
   void nouvelleValeur( int nouveauNombre );
};

} }

#endif
