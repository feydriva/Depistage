
#ifndef DEPISTAGE_CONFIG_SELECTION_FICHIER_CONFIG_HPP
#define DEPISTAGE_CONFIG_SELECTION_FICHIER_CONFIG_HPP

#include <QtCore/QString>

#include <QtXml/QDomElement>

namespace depistage { namespace config {

class SelectionFichierConfig
{
public:
   explicit SelectionFichierConfig( const QString & label = "", const QString & chemin = "" );

   const QString & getLabel() const;
   const QString & getChemin() const;

   static SelectionFichierConfig chargerXML( const QDomElement & noeudSelectionFichier );
   static void sauverXML( const SelectionFichierConfig & config,
                          QDomElement & noeudSelectionFichier );

private:
   QString m_label;
   QString m_chemin;
};

} }

#endif
