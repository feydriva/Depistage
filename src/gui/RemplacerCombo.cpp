
#include "RemplacerCombo.hpp"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

namespace depistage { namespace gui {

RemplacerCombo::RemplacerCombo( const QString & labelStr,
                                const std::vector< QString > & choix,
                                QWidget * parent )
   : Remplacer( parent )
{
   QHBoxLayout * mainLayout = new QHBoxLayout();

   QLabel * labelMotRemplacer = new QLabel( labelStr + " : " );
   mainLayout->addWidget( labelMotRemplacer );
   m_motParLequelRemplacer = new QComboBox();
   for ( QString choixCourent : choix )
   {
      m_motParLequelRemplacer->addItem( choixCourent );
   }
   mainLayout->addWidget( m_motParLequelRemplacer );
   
   setLayout( mainLayout );
}

QString RemplacerCombo::motParLequelRemplacer() const
{
   return m_motParLequelRemplacer->currentText();
}

} }
