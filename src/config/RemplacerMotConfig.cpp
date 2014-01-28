
#include "RemplacerMotConfig.hpp"

namespace depistage { namespace config {

namespace {

const QString labelLabel = "label";
const QString labelMotARemplacer = "motARemplacer";

}

RemplacerMotConfig::RemplacerMotConfig( const QString & label, const QString & motARemplacer )
   : m_label( label ), m_motARemplacer( motARemplacer )
{}

const QString & RemplacerMotConfig::getLabel( ) const
{
   return m_label;
}

const QString & RemplacerMotConfig::getMotARemplacer() const
{
   return m_motARemplacer;
}

RemplacerMotConfig RemplacerMotConfig::chargerXML( const QDomElement & noeudRemplacerMot )
{
   QString label = noeudRemplacerMot.firstChildElement( labelLabel ).text();
   QString motARemplacer = noeudRemplacerMot.firstChildElement( labelMotARemplacer ).text();
   return RemplacerMotConfig( label, motARemplacer );
}

void RemplacerMotConfig::sauverXML( const RemplacerMotConfig & config,
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
