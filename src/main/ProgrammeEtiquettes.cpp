
#include "ProgrammeEtiquettes.hpp"

#include <gui/BoutonAction.hpp>
#include <gui/ElementGUI.hpp>
#include <gui/MetaRemplacer.hpp>
#include <gui/SelectionFichier.hpp>

namespace depistage { namespace main {

ProgrammeEtiquettes::ProgrammeEtiquettes()
{
   m_elementsGUI.push_back( new depistage::gui::MetaRemplacer( "Code patient", "@@code@@" ) );
   m_elementsGUI.push_back( new depistage::gui::MetaRemplacer( "Sex", "@@sex@@" ) );
   m_elementsGUI.push_back(
      new depistage::gui::MetaRemplacer( "Date de naissance", "@@dateNaissance@@" ) );
   m_elementsGUI.push_back(
      new depistage::gui::BoutonAction( "Lancer génération" ) );
   m_elementsGUI.push_back(
      new depistage::gui::SelectionFichier( "Fichier word de rapport : ",
                                            "Ouvrir un document Word",
                                            "Word files  (*.doc *.docx)" ) );
   m_elementsGUI.push_back(
      new depistage::gui::SelectionFichier( "Fichier excel de rapport : ",
                                            "Ouvrir un document Excel",
                                            "Excel files (*.xls *.xlsx)" ) );
}

const std::vector< gui::ElementGUI * > & ProgrammeEtiquettes::getElementsGUI( ) const
{
   return m_elementsGUI;
}

} }
