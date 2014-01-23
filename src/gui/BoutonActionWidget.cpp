
#include "BoutonActionWidget.hpp"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>

namespace depistage { namespace gui {

BoutonActionWidget::BoutonActionWidget( const QString & labelStr, QWidget * parent )
   : QWidget( parent )
{
   QHBoxLayout * mainLayout = new QHBoxLayout();

   QPushButton * pushButton = new QPushButton( labelStr );
   mainLayout->addWidget( pushButton );

   connect( pushButton, SIGNAL( clicked() ),
            this,       SIGNAL( clique() ) );
   
   setLayout( mainLayout );
}

} }
