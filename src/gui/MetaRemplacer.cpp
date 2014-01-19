
#include "MetaRemplacer.hpp"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

namespace depistage { namespace gui {

MetaRemplacer::MetaRemplacer( const QString & labelStr, const QString & m_motARemplacer,
                              QWidget * parentWidget )
	: m_remplacerBasic( new RemplacerMot( labelStr, parentWidget ) ),
     m_remplacerConfig( new RemplacerMotConfig( labelStr, m_motARemplacer, parentWidget ) )
{
}

QWidget * MetaRemplacer::widgetBasic() const
{
   return m_remplacerBasic;
}

QWidget * MetaRemplacer::widgetConfig() const
{
   return m_remplacerConfig;
}

} }
