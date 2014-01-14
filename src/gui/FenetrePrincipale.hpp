
#ifndef DEPISTAGE_GUI_FENETREPRINCIPALE_HPP
#define DEPISTAGE_GUI_FENETREPRINCIPALE_HPP

#include "SelectionFichier.hpp"
#include "RemplacerMot.hpp"
#include "RemplacerMotConfig.hpp"

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class FenetrePrincipale : public QMainWindow
{
   Q_OBJECT
public :
   FenetrePrincipale( QWidget * parent = nullptr );

private :
   RemplacerMot * m_motRemplacerChat;
   RemplacerMotConfig * m_motRemplacerTest;
   SelectionFichier * m_wordTest;
   SelectionFichier * m_excelTest;

private slots:
   void remplacer();
   void ajouter();
};

} }

#endif
