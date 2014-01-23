
#ifndef DEPISTAGE_MAIN_PROGRAMME_HPP
#define DEPISTAGE_MAIN_PROGRAMME_HPP

#include <QtCore/QObject>

#include "ElementGUI.hpp"

namespace depistage { namespace main {

class Programme : public QObject
{
   Q_OBJECT
public :
   virtual const std::vector< gui::ElementGUI * > & getElementsGUI() const = 0;
};

} }

#endif
