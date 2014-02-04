
#include "Dialog.hpp"

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

Dialog::Dialog( QAxObject * dialog, QObject * parent )
: m_dialog( dialog ), m_parent( parent )
{
   connectException( m_parent, m_dialog.get( ) );
}

void Dialog::show( )
{
   m_dialog->dynamicCall( "Show()" );
}

} }
