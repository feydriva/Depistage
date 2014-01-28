
#include "SelectionFichierConfig.hpp"

namespace depistage { namespace config {

namespace {

const QString labelLabel = "label";
const QString labelChemin = "chemin";

}

SelectionFichierConfig::SelectionFichierConfig( const QString & label, const QString & chemin )
   : m_label( label ), m_chemin( chemin )
{}

const QString & SelectionFichierConfig::getLabel( ) const
{
   return m_label;
}

const QString & SelectionFichierConfig::getChemin() const
{
   return m_chemin;
}

SelectionFichierConfig SelectionFichierConfig::chargerXML( const QDomElement & noeudSelectionFichier )
{
   QString label = noeudSelectionFichier.firstChildElement( labelLabel ).text( );
   QString chemin = noeudSelectionFichier.firstChildElement( labelChemin ).text( );
   return SelectionFichierConfig( label, chemin );
}

void SelectionFichierConfig::sauverXML( const SelectionFichierConfig & config,
                                        QDomElement & noeudSelectionFichier )
{
   QDomElement label = noeudSelectionFichier.ownerDocument().createElement( labelLabel );
   label.appendChild( noeudSelectionFichier.ownerDocument().createTextNode( config.getLabel( ) ) );
   noeudSelectionFichier.appendChild( label );

   QDomElement chemin = noeudSelectionFichier.ownerDocument( ).createElement( labelChemin );
   chemin.appendChild( noeudSelectionFichier.ownerDocument( ).createTextNode( config.getChemin( ) ) );
   noeudSelectionFichier.appendChild( chemin );
}

} }
