
#include "Element.hpp"

namespace depistage { namespace main {

Element::Element( const std::string & id, gui::ElementGUI * elementGUI )
   : m_id( id ), m_elementGUI( elementGUI )
{
}

std::string Element::getId() const
{
   return m_id;
}

gui::ElementGUI * Element::getElementGUI() const
{
   return m_elementGUI;
}

} }
