
#ifndef DEPISTAGE_GUI_SELECTION_FICHIER_WIDGET_HPP
#define DEPISTAGE_GUI_SELECTION_FICHIER_WIDGET_HPP

#include <QtCore/QString>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class SelectionFichierWidget : public QWidget
{
   Q_OBJECT
public:
   SelectionFichierWidget(const QString & labelStr,
                          const QString & message,
                          const QString & filtre,
                          const QString & chemin,
                          QWidget * parent = nullptr);
   QString getChemin() const;

private:
   QString m_message;
   QString m_filtre;

   QLineEdit * m_wordTest;

private slots:
   void parcourir();
};

} }

#endif
