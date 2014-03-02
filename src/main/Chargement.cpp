
#include "Chargement.hpp"

#include <gui/RemplacerCombo.hpp>
#include <gui/RemplacerDate.hpp>
#include <gui/RemplacerMot.hpp>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

namespace depistage { namespace main {
   
namespace {

const QString cheminConfig = "config.xml";

}

depistage::gui::MetaRemplacer * creerRemplacerMot( depistage::config::ConfigProgramme & config,
                                                   const QString & labelAffichage,
                                                   const QString & labelXML )
{
   QString motARemplacer = config.recupRemplacerMot( labelXML ).getMotARemplacer();
   depistage::gui::RemplacerMot * remplacerMot =
      new depistage::gui::RemplacerMot( labelAffichage );
   return new depistage::gui::MetaRemplacer( remplacerMot, labelAffichage, motARemplacer );
}

depistage::gui::MetaRemplacer * creerRemplacerDate( depistage::config::ConfigProgramme & config,
                                                    const QString & labelAffichage,
                                                    const QString & labelXML,
                                                    const QDate & date )
{
   QString motARemplacer = config.recupRemplacerMot( labelXML ).getMotARemplacer();
   return new depistage::gui::MetaRemplacer(
      new depistage::gui::RemplacerDate( labelAffichage, date ),
      labelAffichage,
      motARemplacer );
}

depistage::gui::MetaRemplacer * creerRemplacerCombo( depistage::config::ConfigProgramme & config,
                                                     const QString & labelAffichage,
                                                     const std::vector< QString > & choix,
                                                     const QString & labelXML )
{
   QString motARemplacer = config.recupRemplacerMot( labelXML ).getMotARemplacer();
   return new depistage::gui::MetaRemplacer(
      new depistage::gui::RemplacerCombo( labelAffichage, choix ),
      labelAffichage,
      motARemplacer );
}

depistage::gui::SelectionFichier * creerSelectionFichier(
   depistage::config::ConfigProgramme & config,
   bool estFichier,
   const QString & labelAffichage,
   const QString & labelFenetre,
   const QString & filtre,
   const QString & labelXML )
{
   QString chemin = config.recupSelectionFichier( labelXML ).getChemin();
   return new depistage::gui::SelectionFichier( estFichier, labelAffichage, labelFenetre, filtre, chemin );
}

depistage::config::ConfigProgrammes chargerProgrammes( )
{
   return depistage::config::ConfigProgrammes( cheminConfig );
}

} }
