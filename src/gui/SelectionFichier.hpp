
#ifndef DEPISTAGE_GUI_SELECTION_FICHIER_HPP
#define DEPISTAGE_GUI_SELECTION_FICHIER_HPP

#include <QtCore/QString>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class SelectionFichier : public QWidget
{
   Q_OBJECT
public :
   SelectionFichier( const QString & labelStr, QWidget * parent = nullptr );
   QString getChemin() const;

private :
   QLineEdit * m_wordTest;

private slots:
   void parcourir();
};

} }

#endif
