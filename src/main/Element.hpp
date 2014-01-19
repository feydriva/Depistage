
#ifndef DEPISTAGE_MAIN_ELEMENT_HPP
#define DEPISTAGE_MAIN_ELEMENT_HPP

#include <QtCore/QObject>

#include "Element.hpp"

#include <gui/ElementGUI.hpp>

#include <string>

namespace depistage { namespace main {

class Element : public QObject
{
   Q_OBJECT
public :
   Element( const std::string & id, gui::ElementGUI * elementGUI );

   std::string getId() const;
   gui::ElementGUI * getElementGUI() const;

private :
   std::string m_id;
   gui::ElementGUI * m_elementGUI;
};

} }

#endif
