
#include "WordDocument.hpp"

#include <iostream>
#include <sstream>

namespace depistage { namespace office {

namespace {

void connectException( const QObject * parent, const QAxObject * axObject )
{
   if ( parent && axObject )
   {
      QObject::connect(
         axObject, SIGNAL( exception(int, const QString &, const QString &, const QString & ) ),
         parent, SLOT(   catchException(int, const QString &, const QString &, const QString & ) ) );
   }
}

}

WordDocument::WordDocument( QAxObject * document, QObject * parent )
   : m_document( document ), m_parent( parent )
{
   connectException( m_parent, m_document.get() );
}

void WordDocument::saveAs( const std::string & chemin )
{
   m_document->dynamicCall( "SaveAs(const QString&)", chemin.c_str() );

}

namespace {

   QList< QVariant > retrieveDefaultParam()
   {
      const std::string local_wdRepalceAll = "2";
      QList< QVariant > params;
      params << QVariant( "" );                            // FindText
      params << QVariant( "0" );                           // MatchCase
      params << QVariant( "0" );                           // MatchWholeWord 
      params << QVariant( "0" );                           // MatchWildcards 
      params << QVariant( "0" );                           // MatchSoundsLike 
      params << QVariant( "0" );                           // MatchAllWordForms 
      params << QVariant( true );                          // Forward 
      params << QVariant( "0" );                           // Wrap 
      params << QVariant( "0" );                           // Format 
      params << QVariant( "" );                            // ReplaceWith 
      params << QVariant( local_wdRepalceAll.c_str() );  // Replace
      params << QVariant( "0" );                           // MatchKashida
      params << QVariant( "0" );                           // MatchDiacritics
      params << QVariant( "0" );                           // MatchAlefHamza
      params << QVariant( "0" );                           // MatchControl
      return params;
   }

}

void WordDocument::replace( const std::string & textToFind, const std::string & textToReplace )
{
   std::unique_ptr< QAxObject > next( (QAxObject *) m_document->querySubObject( "Content" ) );
   std::unique_ptr< QAxObject > find( (QAxObject *) next->querySubObject( "find" ) );
   find->dynamicCall( "ClearFormatting()" );
   if (!find)
   {
      std::cerr << "find content." << std::endl;
   }

   QList< QVariant > params = retrieveDefaultParam();
   params[ 0 ] = QVariant( textToFind.c_str() );
   params[ 9 ] = QVariant( textToReplace.c_str() );

   find->dynamicCall( "Execute(const QVariant&, const QVariant&, const QVariant&, "
                      "const QVariant&, const QVariant&, const QVariant&, "
                      "const QVariant&, const QVariant&, const QVariant&, "
                      "const QVariant&, const QVariant&, const QVariant&, "
                      "const QVariant&, const QVariant&, const QVariant&)",
                      params);
}

void WordDocument::imprimer() const
{
   m_document->querySubObject( "PrintOut()" );
}

bool WordDocument::isOpen() const
{
   return m_document.get() != nullptr;
}

} }
