
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

void ConfigProgramme::miseAJourRemplacerMotConfig( const RemplacerMotConfig & remplacerMotConfig )
{
   m_remplacerMotConfigs[ remplacerMotConfig.getLabel() ] = remplacerMotConfig;
}

void ConfigProgramme::miseAJourSelectionFichierConfig(
   const SelectionFichierConfig & selectionFichierConfig )
{
   m_selectionFichierConfigs[ selectionFichierConfig.getLabel( ) ] = selectionFichierConfig;
}

ConfigProgramme ConfigProgramme::chargerXML( const QString & chemin )
{
   QDomDocument depistage( labelGlobal );

   // Todo : mieux g�rer �a !
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
   ConfigProgramme config( programmes.firstChildElement( labelLabel ).text( ) );

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
         config.miseAJourRemplacerMotConfig( RemplacerMotConfig::chargerXML( noeudRemplacerMot ) );
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

   QDomElement programmes = depistage.createElement( labelProgrammes );
   depistage.appendChild( programmes );

   QDomElement programme = depistage.createElement( labelProgramme );
   programmes.appendChild( programme );

   programme.appendChild( depistage.createTextNode( config.m_label ) );
   QDomElement parametres = depistage.createElement( labelParametres );
   programmes.appendChild( parametres );
   for ( auto currentRemplacerMot : config.m_remplacerMotConfigs )
   {
      QDomElement remplacerMot = depistage.createElement( labelRemplacerMot );
      RemplacerMotConfig::sauverXML( currentRemplacerMot.second, remplacerMot );
      parametres.appendChild( remplacerMot );
   }
   for ( auto currentSelectionFichier : config.m_selectionFichierConfigs )
   {
      QDomElement selectionFichier = depistage.createElement( labelSelectionFichier );
      SelectionFichierConfig::sauverXML( currentSelectionFichier.second, selectionFichier );
      parametres.appendChild( selectionFichier );
   }

   // Todo : mieux g�rer �a !
   QFile file( chemin );
   if ( !file.open( QIODevice::WriteOnly ) )
   {
      return;
   }

   QTextStream  out( &file );
   out << depistage.toString( 3 );
}

} }
