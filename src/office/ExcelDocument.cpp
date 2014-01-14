
#include "ExcelDocument.hpp"

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
         parent,   SLOT(   catchException(int, const QString &, const QString &, const QString & ) ) );
   }
}

}

ExcelDocument::ExcelDocument( QAxObject * workbook, QObject * parent )
   : m_workbook( workbook ), m_parent( parent )
{
   connectException( m_parent, m_workbook.get() );
}

void ExcelDocument::ajouterLigne()
{
   std::unique_ptr< QAxObject > sheetNum1( (QAxObject *) m_workbook->querySubObject( "Sheets(int)", 1 ) );
   std::unique_ptr< QAxObject > rangeA1( (QAxObject *) sheetNum1->querySubObject( "Range(const QString&)", "A1" ) );
   std::unique_ptr< QAxObject > derniereLigne( (QAxObject *) rangeA1->querySubObject( "End(int)", -4121 ) );
   std::unique_ptr< QAxObject > premiereLigneVide( (QAxObject *) derniereLigne->querySubObject( "Offset(int, int)", 1, 0 ) );
   premiereLigneVide->dynamicCall("SetValue(String)", "Toto");
   const int idPremiereLigneVide = premiereLigneVide->property( "Row" ).toInt();
   std::cout << "idPremiereLigneVide: " << idPremiereLigneVide << std::endl;
}

bool ExcelDocument::isOpen() const
{
   return m_workbook.get() != nullptr;
}

} }
