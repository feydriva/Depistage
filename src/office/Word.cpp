
#include "Word.hpp"

#include <ActiveQt/QAxObject>

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

Word::Word( QObject * parent )
   : m_word( new QAxObject( "Word.Application", NULL ) ), m_parent( parent )
{
   connectException( m_parent, m_word.get() );

   m_word->setProperty( "DisplayAlerts", false );
   m_word->setProperty( "Visible", true/*false*/ );

}

void Word::quit()
{
   m_word->dynamicCall( "Quit()" );
}

void Word::initializeDocuments()
{
   if (!m_documents)
   {
      m_documents.reset( (QAxObject *) m_word->querySubObject( "Documents" ) );
      connectException( m_parent, m_documents.get() );
   }
}

WordDocument Word::open( const std::string & path )
{
   initializeDocuments();
   m_documents->dynamicCall( "Open(const QString&)", path.c_str() );
   return WordDocument( (QAxObject *) m_word->querySubObject( "ActiveDocument" ), m_parent );
}

bool Word::isLaunched() const
{
   return m_word.get() != nullptr;
}

} }
