
#ifndef DEPISTAGE_MAIN_PROGRAMME_ETIQUETTES_HPP
#define DEPISTAGE_MAIN_PROGRAMME_ETIQUETTES_HPP

#include <QtCore/QObject>

#include "ElementGUI.hpp"

namespace depistage { namespace main {

class ProgrammeEtiquettes : public QObject
{
   Q_OBJECT
public :
   ProgrammeEtiquettes();
   virtual const std::vector< gui::ElementGUI * > & getElementsGUI() const;

private:
   std::vector< gui::ElementGUI * > m_elementsGUI;
};

} }

#endif
