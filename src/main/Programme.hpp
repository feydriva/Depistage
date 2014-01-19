
#ifndef DEPISTAGE_MAIN_PROGRAMME_HPP
#define DEPISTAGE_MAIN_PROGRAMME_HPP

#include <QtCore/QObject>

#include "Element.hpp"
#include "ElementGUI.hpp"

namespace depistage { namespace main {

class Programme : public QObject
{
   Q_OBJECT
public :
   Programme();

   void addElement( Element * element );

   const std::vector< gui::ElementGUI * > & getElementGUI() const;

private :
   std::map< std::string, Element * > m_elements;
   std::vector< gui::ElementGUI * > m_elementsGUITries;
};

} }

#endif
