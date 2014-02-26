
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
   ConfigProgramme();
   ConfigProgramme( const QDomElement & racineProgramme );
   void charger( const QDomElement & racineProgramme );
   void sauver( QDomDocument & document, QDomElement & racineProgramme );

   const QString & getLabel( ) const;
   void setLabel( const QString & label );

   const RemplacerConfig & recupRemplacerMot( const QString & label );
   const SelectionFichierConfig & recupSelectionFichier( const QString & label );

   void miseAJourRemplacerConfig( const RemplacerConfig & RemplacerConfig );
   void miseAJourSelectionFichierConfig( const SelectionFichierConfig & RemplacerConfig );

private:
   typedef QString Label;
   QString m_label;
   std::map< Label, RemplacerConfig > m_RemplacerConfigs;
   std::map< Label, SelectionFichierConfig > m_selectionFichierConfigs;


};

} }

#endif
