
#ifndef DEPISTAGE_MAIN_PROGRAMME_ENREGISTREMENT_HPP
#define DEPISTAGE_MAIN_PROGRAMME_ENREGISTREMENT_HPP

#include <main/ProgrammeStandart.hpp>

#include <config/ConfigProgramme.hpp>
#include <config/ConfigProgrammes.hpp>

#include "ElementGUI.hpp"

namespace depistage { namespace main {

class ProgrammeEnregistrement : public ProgrammeStandart
{
   Q_OBJECT
public :
   ProgrammeEnregistrement( depistage::config::ConfigProgrammes & configs );

   virtual const QString & getTitre() const;
   virtual const std::vector< gui::ElementGUI * > & getElementsGUI() const;

private:
   std::vector< gui::ElementGUI * > m_elementsGUI;

   gui::MetaRemplacer * m_codePatient;
   gui::MetaRemplacer * m_sex;
   gui::MetaRemplacer * m_dateDeNaissance;
   gui::MetaRemplacer * m_dateDuJour;
   gui::MetaRemplacer * m_realisePar;
   gui::MetaRemplacer * m_renduPar;
   gui::MetaRemplacer * m_numeroDeLot;

   gui::SelectionFichier * m_fichierWord;
   gui::SelectionFichier * m_dossierWord;
   gui::SelectionFichier * m_fichierExcel;

private slots:
   void lancerGeneration();
   void sauverConfig();
};

} }

#endif
