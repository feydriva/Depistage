
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

ConfigProgramme::ConfigProgramme( const QString & label )
   : m_label( label )
{
}

const QString & ConfigProgramme::getLabel() const
{
   return m_label;
}

const RemplacerConfig & ConfigProgramme::recupRemplacerMot( const QString & label )
{
   return m_RemplacerConfigs[ label ];
}

const SelectionFichierConfig & ConfigProgramme::recupSelectionFichier( const QString & label )
{
   return m_selectionFichierConfigs[ label ];
}

void ConfigProgramme::miseAJourRemplacerConfig( const RemplacerConfig & RemplacerConfig )
{
   m_RemplacerConfigs[ RemplacerConfig.getLabel() ] = RemplacerConfig;
}

void ConfigProgramme::miseAJourSelectionFichierConfig(
   const SelectionFichierConfig & selectionFichierConfig )
{
   m_selectionFichierConfigs[ selectionFichierConfig.getLabel( ) ] = selectionFichierConfig;
}

ConfigProgramme ConfigProgramme::chargerXML( const QString & chemin )
{
   QDomDocument depistage( labelGlobal );

   // Todo : mieux gérer ça !
   QFile file( chemin );
   if ( !file.open( QIODevice::ReadOnly ) )
   {
      return ConfigProgramme();
   }
   if ( !depistage.setContent( &file ) )
   {
      file.close();
      return ConfigProgramme();
   }
   file.close();

   QDomElement programmes = depistage.documentElement( );
   ConfigProgramme config( programmes.firstChildElement( labelLabel ).text() );

   QDomElement programme = programmes.firstChildElement( labelProgramme );
   for ( ;
         !programme.isNull( );
         programme = programme.nextSiblingElement( labelProgramme ) )
   {
      QString label = programme.firstChildElement( labelLabel ).text( );
      QDomElement parametres = programme.firstChildElement( labelParametres );
      QDomElement noeudRemplacerMot = parametres.firstChildElement( labelRemplacerMot );
      for ( ;
            !noeudRemplacerMot.isNull( );
            noeudRemplacerMot = noeudRemplacerMot.nextSiblingElement( labelRemplacerMot ) )
      {
         config.miseAJourRemplacerConfig( RemplacerConfig::chargerXML( noeudRemplacerMot ) );
      }
      QDomElement noeudSelectionFichier = parametres.firstChildElement( labelSelectionFichier );
      for ( ;
            !noeudSelectionFichier.isNull( );
            noeudSelectionFichier = noeudSelectionFichier.nextSiblingElement( labelSelectionFichier ) )
      {
         config.miseAJourSelectionFichierConfig(
            SelectionFichierConfig::chargerXML( noeudSelectionFichier ) );
      }
   }
   return config;
}

void ConfigProgramme::sauverXML( const ConfigProgramme & config, const QString & chemin )
{
   QDomDocument depistage( labelGlobal );
   QDomProcessingInstruction header
      = depistage.createProcessingInstruction( "xml", "version='1.0' encoding='UTF-8'" );
   depistage.appendChild( header );

   QDomElement programmes = depistage.createElement( labelGlobal );
   depistage.appendChild( programmes );

   QDomElement programme = depistage.createElement( labelProgramme );
   programmes.appendChild( programme );

   QDomElement label = depistage.createElement( labelLabel );
   programme.appendChild( label );
   label.appendChild( depistage.createTextNode( config.m_label ) );
   QDomElement parametres = depistage.createElement( labelParametres );
   programme.appendChild( parametres );
   for ( auto currentRemplacerMot : config.m_RemplacerConfigs )
   {
      QDomElement remplacerMot = depistage.createElement( labelRemplacerMot );
      RemplacerConfig::sauverXML( currentRemplacerMot.second, remplacerMot );
      parametres.appendChild( remplacerMot );
   }
   for ( auto currentSelectionFichier : config.m_selectionFichierConfigs )
   {
      QDomElement selectionFichier = depistage.createElement( labelSelectionFichier );
      SelectionFichierConfig::sauverXML( currentSelectionFichier.second, selectionFichier );
      parametres.appendChild( selectionFichier );
   }

   // Todo : mieux gérer ça !
   QFile file( chemin );
   if ( !file.open( QIODevice::WriteOnly ) )
   {
      return;
   }

   QTextStream  out( &file );
   out << depistage.toString( 3 );
}

} }
