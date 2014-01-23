
#ifndef DEPISTAGE_MAIN_PROGRAMME_ENREGISTREMENT_HPP
#define DEPISTAGE_MAIN_PROGRAMME_ENREGISTREMENT_HPP

#include <QtCore/QObject>

#include "ElementGUI.hpp"

namespace depistage { namespace main {

class ProgrammeEnregistrement : public QObject
{
   Q_OBJECT
public :
   ProgrammeEnregistrement();
   virtual const std::vector< gui::ElementGUI * > & getElementsGUI( ) const;

private:
   std::vector< gui::ElementGUI * > m_elementsGUI;
};

} }

#endif
