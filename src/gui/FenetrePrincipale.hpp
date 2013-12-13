
#ifndef DEPISTAGE_FENETREPRINCIPALE_HPP
#define DEPISTAGE_FENETREPRINCIPALE_HPP

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

namespace depistage { namespace gui {

class FenetrePrincipale : public QMainWindow
{
   Q_OBJECT
public :
   FenetrePrincipale( QWidget * parent = nullptr );
};

} }

#endif
