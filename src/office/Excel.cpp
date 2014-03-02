
#include "Excel.hpp"

#include <ActiveQt/QAxObject>

namespace depistage { namespace office {

namespace {

void connectException( const QObject * parent, const QAxObject * axObject )
{
   if ( parent && axObject )
   {
      QObject::connect(
         axObject, SIGNAL( exception(int, const QString &, const QString &, const QString & ) ),
         parent,   SLOT(   catchException(int, const QString &, const QString &, const QString & ) ) );
   }
}

}

Excel::Excel( QObject * parent )
   : m_excel( new QAxObject( "Excel.Application", nullptr ) ), m_parent( parent )
{
   connectException( m_parent, m_excel.get() );

   m_excel->setProperty( "DisplayAlerts", false );
   m_excel->setProperty( "Visible", true/*false*/ );

}

void Excel::quit()
{
   m_excel->querySubObject( "Quit()" );
}

void Excel::initializeWorkbooks()
{
   if (!m_workbooks)
   {
      m_workbooks.reset( (QAxObject *) m_excel->querySubObject( "Workbooks" ) );
      connectException( m_parent, m_workbooks.get() );
   }
}

ExcelDocument Excel::open( const std::string & path )
{
   initializeWorkbooks();
   
   return ExcelDocument(
             (QAxObject *) m_workbooks->querySubObject( "Open(const QString&)", path.c_str() ),
             m_parent );
}

bool Excel::isLaunched() const
{
   return m_excel.get() != nullptr;
}

} }
