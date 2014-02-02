
#include "RemplacerConfig.hpp"

namespace depistage { namespace config {

namespace {

const QString labelLabel = "label";
const QString labelMotARemplacer = "motARemplacer";

}

RemplacerConfig::RemplacerConfig( const QString & label, const QString & motARemplacer )
   : m_label( label ), m_motARemplacer( motARemplacer )
{}

const QString & RemplacerConfig::getLabel( ) const
{
   return m_label;
}

const QString & RemplacerConfig::getMotARemplacer() const
{
   return m_motARemplacer;
}

RemplacerConfig RemplacerConfig::chargerXML( const QDomElement & noeudRemplacerMot )
{
   QString label = noeudRemplacerMot.firstChildElement( labelLabel ).text();
   QString motARemplacer = noeudRemplacerMot.firstChildElement( labelMotARemplacer ).text();
   return RemplacerConfig( label, motARemplacer );
}

void RemplacerConfig::sauverXML( const RemplacerConfig & config,
                                    QDomElement & noeudRemplacerMot )
{
   QDomElement label = noeudRemplacerMot.ownerDocument().createElement( labelLabel );
   label.appendChild( noeudRemplacerMot.ownerDocument().createTextNode( config.getLabel( ) ) );
   noeudRemplacerMot.appendChild( label );

   QDomElement motARemplacer =
      noeudRemplacerMot.ownerDocument( ).createElement( labelMotARemplacer );
   motARemplacer.appendChild(
      noeudRemplacerMot.ownerDocument( ).createTextNode( config.getMotARemplacer( ) ) );
   noeudRemplacerMot.appendChild( motARemplacer );
}

} }
