
#include "ProgrammeStandart.hpp"

#include <gui/RemplacerCombo.hpp>
#include <gui/RemplacerDate.hpp>
#include <gui/RemplacerMot.hpp>

namespace depistage { namespace main {

ProgrammeStandart::ProgrammeStandart( config::ConfigProgrammes & configs, const QString & titre )
   : m_configs(configs), m_config( configs.getConfig( titre ) )
{
}

depistage::config::ConfigProgrammes & ProgrammeStandart::getConfigs()
{
   return m_configs;
}

depistage::config::ConfigProgramme & ProgrammeStandart::getConfig()
{
   return m_config;
}

} }
