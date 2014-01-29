
#ifndef DEPISTAGE_CONFIG_CONFIG_PROGRAMME_HPP
#define DEPISTAGE_CONFIG_CONFIG_PROGRAMME_HPP

#include "RemplacerMotConfig.hpp"
#include "SelectionFichierConfig.hpp"

#include <QtCore/QObject>
#include <QtCore/QString>

#include <map>

namespace depistage { namespace config {

class ConfigProgramme
{
public:
   ConfigProgramme( const QString & label = QObject::tr( "invalide" ) );

   const QString & getLabel() const;

   const RemplacerMotConfig & recupRemplacerMot( const QString & label );
   const SelectionFichierConfig & recupSelectionFichier( const QString & label );

   void miseAJourRemplacerMotConfig( const RemplacerMotConfig & remplacerMotConfig );
   void miseAJourSelectionFichierConfig( const SelectionFichierConfig & remplacerMotConfig );

   static ConfigProgramme chargerXML( const QString & chemin );
   static void sauverXML( const ConfigProgramme & config, const QString & chemin );

private:
   typedef QString Label;

   QString m_label;
   std::map< Label, RemplacerMotConfig > m_remplacerMotConfigs;
   std::map< Label, SelectionFichierConfig > m_selectionFichierConfigs;
};

} }

#endif
