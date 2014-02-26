
#ifndef DEPISTAGE_MAIN_PROGRAMME_STANDART_HPP
#define DEPISTAGE_MAIN_PROGRAMME_STANDART_HPP

#include <main/Programme.hpp>

#include <config/ConfigProgramme.hpp>
#include <config/ConfigProgrammes.hpp>

#include <gui/MetaRemplacer.hpp>
#include <gui/SelectionFichier.hpp>

namespace depistage { namespace main {

class ProgrammeStandart : public Programme
{
   Q_OBJECT
public :
   ProgrammeStandart( depistage::config::ConfigProgrammes & configs, const QString & titre );

   depistage::config::ConfigProgrammes & getConfigs();
   depistage::config::ConfigProgramme & getConfig();

private:
   depistage::config::ConfigProgrammes & m_configs;
   depistage::config::ConfigProgramme & m_config;
};

} }

#endif
