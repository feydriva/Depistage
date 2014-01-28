
#ifndef DEPISTAGE_GUI_FENETREPRINCIPALE_HPP
#define DEPISTAGE_GUI_FENETREPRINCIPALE_HPP

#include "ElementGUI.hpp"

// Todo : a rendre generique
#include <main/ProgrammeEtiquettes.hpp>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class FenetrePrincipale : public QMainWindow
{
   Q_OBJECT
public :
   FenetrePrincipale( const main::ProgrammeEtiquettes & programme, QWidget * parent = nullptr );

private :
   //RemplacerMot * m_motRemplacerChat;
   //RemplacerMotConfig * m_motRemplacerTest;
   //SelectionFichier * m_wordTest;
   //SelectionFichier * m_excelTest;

   
   QPushButton * m_configButton;   
   QWidget * m_configWidget;

private slots:
   //void remplacer();
   //void ajouter();
   void configOnOff();
};

} }

#endif
