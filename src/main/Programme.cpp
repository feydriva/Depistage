
#include "Programme.hpp"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

namespace depistage { namespace main {

Programme::Programme()
{
}

void Programme::addElement( Element * element )
{
   m_elements[ element->getId()] = element;
   m_elementsGUITries.push_back( element->getElementGUI() );
}

const std::vector< gui::ElementGUI * > & Programme::getElementGUI() const
{
   return m_elementsGUITries;
}

} }
