
#ifndef DEPISTAGE_CONFIG_CONFIG_PROGRAMMES_HPP
#define DEPISTAGE_CONFIG_CONFIG_PROGRAMMES_HPP

#include "ConfigProgramme.hpp"
#include "RemplacerConfig.hpp"
#include "SelectionFichierConfig.hpp"

#include <QtCore/QObject>
#include <QtCore/QString>

#include <map>

namespace depistage { namespace config {

class ConfigProgrammes
{
public:
   typedef QString Label;

   ConfigProgrammes( const QString & chemin );
   void sauver();

   ConfigProgramme & getConfig( const Label & label );

private:
   const QString m_chemin;
   std::map< Label, ConfigProgramme > m_configProgrammes;
};

} }

#endif
