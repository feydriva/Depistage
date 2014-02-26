
#include "ConfigProgramme.hpp"

#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <QtCore/QTextStream>

#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

namespace depistage { namespace config {

namespace {
   
const QString labelGlobal = "depistage";
const QString labelProgrammes = "programmes";
const QString labelProgramme = "programme";
const QString labelLabel = "label";
const QString labelParametres = "parametres";
const QString labelRemplacerMot = "remplacerMot";
const QString labelSelectionFichier = "selectionFichier";

}

ConfigProgramme::ConfigProgramme()
{
}

ConfigProgramme::ConfigProgramme( const QDomElement & racineProgramme )
{
   charger( racineProgramme );
}

void ConfigProgramme::charger( const QDomElement & racineProgramme )
{
   m_label = racineProgramme.firstChildElement( labelLabel ).text( );

   QDomElement parametres = racineProgramme.firstChildElement( labelParametres );
   QDomElement noeudRemplacerMot = parametres.firstChildElement( labelRemplacerMot );
   for ( ;
         !noeudRemplacerMot.isNull( );
         noeudRemplacerMot = noeudRemplacerMot.nextSiblingElement( labelRemplacerMot ) )
   {
      miseAJourRemplacerConfig( RemplacerConfig::chargerXML( noeudRemplacerMot ) );
   }
   QDomElement noeudSelectionFichier = parametres.firstChildElement( labelSelectionFichier );
   for ( ;
         !noeudSelectionFichier.isNull( );
         noeudSelectionFichier = noeudSelectionFichier.nextSiblingElement( labelSelectionFichier ) )
   {
      miseAJourSelectionFichierConfig(
         SelectionFichierConfig::chargerXML( noeudSelectionFichier ) );
   }
}

void ConfigProgramme::sauver( QDomDocument & document, QDomElement & racineProgramme )
{
   QDomElement label = document.createElement( labelLabel );
   racineProgramme.appendChild( label );
   label.appendChild( document.createTextNode( m_label ) );
   QDomElement parametres = document.createElement( labelParametres );
   racineProgramme.appendChild( parametres );
   for ( auto currentRemplacerMot : m_RemplacerConfigs )
   {
      QDomElement remplacerMot = document.createElement( labelRemplacerMot );
      RemplacerConfig::sauverXML( currentRemplacerMot.second, remplacerMot );
      parametres.appendChild( remplacerMot );
   }
   for ( auto currentSelectionFichier : m_selectionFichierConfigs )
   {
      QDomElement selectionFichier = document.createElement( labelSelectionFichier );
      SelectionFichierConfig::sauverXML( currentSelectionFichier.second, selectionFichier );
      parametres.appendChild( selectionFichier );
   }
}

const QString & ConfigProgramme::getLabel() const
{
   return m_label;
}

void ConfigProgramme::setLabel( const QString & label )
{
   m_label = label;
}

const RemplacerConfig & ConfigProgramme::recupRemplacerMot( const QString & label )
{
   return m_RemplacerConfigs[ label ];
}

const SelectionFichierConfig & ConfigProgramme::recupSelectionFichier( const QString & label )
{
   return m_selectionFichierConfigs[ label ];
}

void ConfigProgramme::miseAJourRemplacerConfig( const RemplacerConfig & remplacerConfig )
{
   m_RemplacerConfigs[ remplacerConfig.getLabel() ] = remplacerConfig;
}

void ConfigProgramme::miseAJourSelectionFichierConfig(
   const SelectionFichierConfig & selectionFichierConfig )
{
   m_selectionFichierConfigs[ selectionFichierConfig.getLabel( ) ] = selectionFichierConfig;
}

} }
