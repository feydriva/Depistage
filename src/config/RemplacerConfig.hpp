
#ifndef DEPISTAGE_CONFIG_REMPLACER_MOT_CONFIG_HPP
#define DEPISTAGE_CONFIG_REMPLACER_MOT_CONFIG_HPP

#include <QtCore/QString>

#include <QtXml/QDomElement>

namespace depistage { namespace config {

class RemplacerConfig
{
public:
   explicit RemplacerConfig( const QString & label = "", const QString & motARemplacer = "" );

   const QString & getLabel() const;
   const QString & getMotARemplacer() const;

   static RemplacerConfig chargerXML( const QDomElement & noeudRemplacerMot );
   static void sauverXML( const RemplacerConfig & config, QDomElement & noeudRemplacerMot );

private:
   QString m_label;
   QString m_motARemplacer;
};

} }

#endif
