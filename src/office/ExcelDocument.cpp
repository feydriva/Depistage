
#include "ExcelDocument.hpp"

#include <sstream>

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

ExcelDocument::ExcelDocument( QAxObject * workbook, QObject * parent )
   : m_workbook( workbook ), m_parent( parent )
{
   connectException( m_parent, m_workbook.get() );
}

ExcelOnglet ExcelDocument::recupererOnglet( unsigned int ongletId )
{
   return ExcelOnglet(
             (QAxObject *) m_workbook->querySubObject( "Sheets(int)", ongletId ),
             m_parent );   
}

bool ExcelDocument::isOpen() const
{
   return m_workbook.get() != nullptr;
}

} }
