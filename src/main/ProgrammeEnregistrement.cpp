
#include "ProgrammeEnregistrement.hpp"

namespace depistage { namespace main {

ProgrammeEnregistrement::ProgrammeEnregistrement()
{
}

const std::vector< gui::ElementGUI * > & ProgrammeEnregistrement::getElementsGUI() const
{
   return m_elementsGUI;
}

} }
