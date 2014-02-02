
#ifndef DEPISTAGE_CONFIG_CONFIG_PROGRAMME_HPP
#define DEPISTAGE_CONFIG_CONFIG_PROGRAMME_HPP

#include "RemplacerConfig.hpp"
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

   const RemplacerConfig & recupRemplacerMot( const QString & label );
   const SelectionFichierConfig & recupSelectionFichier( const QString & label );

   void miseAJourRemplacerConfig( const RemplacerConfig & RemplacerConfig );
   void miseAJourSelectionFichierConfig( const SelectionFichierConfig & RemplacerConfig );

   static ConfigProgramme chargerXML( const QString & chemin );
   static void sauverXML( const ConfigProgramme & config, const QString & chemin );

private:
   typedef QString Label;

   QString m_label;
   std::map< Label, RemplacerConfig > m_RemplacerConfigs;
   std::map< Label, SelectionFichierConfig > m_selectionFichierConfigs;
};

} }

#endif
