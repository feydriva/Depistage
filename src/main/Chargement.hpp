
#ifndef DEPISTAGE_MAIN_CHARGEMENT_HPP
#define DEPISTAGE_MAIN_CHARGEMENT_HPP

#include <config/ConfigProgramme.hpp>
#include <config/ConfigProgrammes.hpp>

#include <gui/MetaRemplacer.hpp>
#include <gui/SelectionFichier.hpp>

#include <QtCore/QDate>
#include <QtCore/QString>

#include <vector>

namespace depistage { namespace main {

depistage::config::ConfigProgrammes chargerProgrammes();

depistage::gui::MetaRemplacer * creerRemplacerMot( config::ConfigProgramme & config,
                                                   const QString & labelAffichage,
                                                   const QString & labelXML,
                                                   const QString & valeurParDefaut = "" );

depistage::gui::MetaRemplacer * creerRemplacerDate( config::ConfigProgramme & config,
                                                    const QString & labelAffichage,
                                                    const QString & labelXML,
                                                    const QDate & date = QDate( 2000, 1, 1 ) );

depistage::gui::MetaRemplacer * creerRemplacerCombo( config::ConfigProgramme & config,
                                                     const QString & labelAffichage,
                                                     const std::vector< QString > & choix,
                                                     const QString & labelXML );

depistage::gui::SelectionFichier * creerSelectionFichier( config::ConfigProgramme & config,
                                                          bool estFichier,
                                                          const QString & labelAffichage,
                                                          const QString & labelFenetre,
                                                          const QString & filtre,
                                                          const QString & labelXML );

} }

#endif
