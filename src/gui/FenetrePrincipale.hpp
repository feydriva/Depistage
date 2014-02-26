
#ifndef DEPISTAGE_GUI_FENETREPRINCIPALE_HPP
#define DEPISTAGE_GUI_FENETREPRINCIPALE_HPP

#include "ElementGUI.hpp"

#include <main/Programme.hpp>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class FenetrePrincipale : public QMainWindow
{
   Q_OBJECT
public :
   FenetrePrincipale( const std::vector< main::Programme * > & programmes,
                      QWidget * parent = nullptr );
   QWidget * creerWidgetProgramme( const main::Programme & programme );

private :   
   std::vector< QPushButton * > m_configButtons;
   std::vector< QWidget * > m_configWidgets;

private slots:
   void configOnOff( bool checked );
};

} }

#endif
