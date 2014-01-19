
#include "ExcelOnglet.hpp"

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

ExcelOnglet::ExcelOnglet( QAxObject * onglet, QObject * parent )
   : m_onglet( onglet ), m_parent( parent )
{
   connectException( m_parent, m_onglet.get() );
}

QAxObject * ExcelOnglet::recupererDerniereCelluleNonVidePremiereColonne()
{
   const int xlDownMaison = -4121;
   QAxObject * rangeA1 =
      (QAxObject *) m_onglet->querySubObject( "Range(const QString&)", "A1" );
   return (QAxObject *) rangeA1->querySubObject( "End(int)", xlDownMaison );
}

QAxObject * ExcelOnglet::recupererPremiereCelluleVidePremiereColonne()
{
   QAxObject * derniereCellulePleinePremiereColonne =
      recupererDerniereCelluleNonVidePremiereColonne();
   return (QAxObject *)
          derniereCellulePleinePremiereColonne->querySubObject( "Offset(int, int)", 1, 0 );
}

namespace {

QAxObject * offsetCelluleDroite( QAxObject * cellule )
{
   return (QAxObject *) cellule->querySubObject( "Offset(int, int)", 0, 1 );
}

}

void ExcelOnglet::ajouterLigne( std::vector< std::string > informations )
{
   QAxObject * celluleCourante = recupererPremiereCelluleVidePremiereColonne();

   for ( std::vector< std::string >::const_iterator iteInfo = informations.begin();
         iteInfo != informations.end();
         ++iteInfo )
   {
      celluleCourante->dynamicCall( "SetValue(String)", iteInfo->c_str() );
      celluleCourante = offsetCelluleDroite( celluleCourante );
   }
   //const int idPremiereLigneVide = premiereLigneVide->property( "Row" ).toInt();
   //std::cout << "idPremiereLigneVide: " << idPremiereLigneVide << std::endl;
}

bool ExcelOnglet::isOpen() const
{
   return m_onglet.get() != nullptr;
}

} }
