
#include "ConfigProgrammes.hpp"

#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <QtCore/QTextStream>

#include <QtWidgets/QMessageBox>

#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

namespace depistage { namespace config {

namespace {
   
const QString labelGlobal = "depistage";
const QString labelProgrammes = "programmes";
const QString labelProgramme = "programme";

}

ConfigProgrammes::ConfigProgrammes( const QString & chemin )
   : m_chemin( chemin )
{
   QDomDocument depistageDocument( labelGlobal );

   // Todo : mieux gerer ca !
   QFile file( chemin );
   if ( !file.open( QIODevice::ReadOnly ) )
   {
      return;
   }
   if ( !depistageDocument.setContent( &file ) )
   {
      file.close();
      return;
   }
   file.close();

   QDomElement depistage = depistageDocument.documentElement();
   QDomElement programmes = depistage.firstChildElement( labelProgrammes );
   QDomElement programme = programmes.firstChildElement( labelProgramme );
   for ( ;
         !programme.isNull();
         programme = programme.nextSiblingElement( labelProgramme ) )
   {
      ConfigProgramme config( programme );
      m_configProgrammes[ config.getLabel() ] = config;
   }
}

void ConfigProgrammes::sauver()
{
   QDomDocument depistageDocument( labelGlobal );
   QDomProcessingInstruction header
      = depistageDocument.createProcessingInstruction( "xml", "version='1.0' encoding='UTF-8'" );
   depistageDocument.appendChild( header );

   QDomElement depistage = depistageDocument.createElement( labelGlobal );
   depistageDocument.appendChild( depistage );

   QDomElement programmes = depistageDocument.createElement( labelProgrammes );
   depistage.appendChild( programmes );

   for ( std::pair< Label, ConfigProgramme > configProgramme : m_configProgrammes )
   {
      QDomElement programme = depistageDocument.createElement( labelProgramme );
      programmes.appendChild( programme );
      configProgramme.second.sauver( depistageDocument, programme );
   }

   // Todo : mieux gerer ca !
   QFile file( m_chemin );
   if ( !file.open( QIODevice::WriteOnly ) )
   {
      return;
   }

   QTextStream  out( &file );
   out << depistageDocument.toString( 3 );

    QMessageBox msgSauvegarde;
	msgSauvegarde.setText( QObject::tr( "Sauvegarde terminée" ) );
	msgSauvegarde.exec();
}


ConfigProgramme & ConfigProgrammes::getConfig( const Label & label )
{
   return m_configProgrammes[ label ];
}

} }
