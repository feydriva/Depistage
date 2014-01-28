
#include "ProgrammeEtiquettes.hpp"

#include <config/ConfigProgramme.hpp>

#include <gui/BoutonAction.hpp>

#include <office/Word.hpp>
#include <office/WordDocument.hpp>
#include <office/Excel.hpp>
#include <office/ExcelDocument.hpp>
#include <office/ExcelOnglet.hpp>

namespace depistage { namespace main {

ProgrammeEtiquettes::ProgrammeEtiquettes()
{
   m_codePatient = new depistage::gui::MetaRemplacer( "Code patient", "@@code@@" );
   m_elementsGUI.push_back( m_codePatient  );
   m_sex = new depistage::gui::MetaRemplacer( "Sex", "@@sex@@" );
   m_elementsGUI.push_back( m_sex );
   m_dateDeNaissance =
      new depistage::gui::MetaRemplacer( "Date de naissance", "@@dateNaissance@@" );
   m_elementsGUI.push_back( m_dateDeNaissance );

   gui::BoutonAction * boutonGeneration = new depistage::gui::BoutonAction( "Lancer génération" );
   m_elementsGUI.push_back( boutonGeneration );
   connect( boutonGeneration, SIGNAL( clique() ),
            this,             SLOT( lancerGeneration( ) ) );

   m_fichierWord =
      new depistage::gui::SelectionFichier( "Fichier word de rapport : ",
                                            "Ouvrir un document Word",
                                            "Word files  (*.doc *.docx)" );
   m_elementsGUI.push_back( m_fichierWord );
   m_fichierExcel =
      new depistage::gui::SelectionFichier( "Fichier excel de rapport : ",
                                            "Ouvrir un document Excel",
                                            "Excel files (*.xls *.xlsx)" );
   m_elementsGUI.push_back( m_fichierExcel );
}

void ProgrammeEtiquettes::sauverConfig( ) const
{
   config::ConfigProgramme config( "etiquettes" );
   config.miseAJourRemplacerMotConfig(
      config::RemplacerMotConfig( "codePatient", m_codePatient->motARemplacer() ) );
   config.miseAJourRemplacerMotConfig(
      config::RemplacerMotConfig( "sex", m_sex->motARemplacer( ) ) );
   config.miseAJourRemplacerMotConfig(
      config::RemplacerMotConfig( "dateDeNaissance", m_dateDeNaissance->motARemplacer( ) ) );
   config.miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( "word", m_fichierWord->getChemin( ) ) );
   config.miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( "excel", m_fichierExcel->getChemin( ) ) );
   config::ConfigProgramme::sauverXML( config, "config.xml" );
}

const std::vector< gui::ElementGUI * > & ProgrammeEtiquettes::getElementsGUI( ) const
{
   return m_elementsGUI;
}

void ProgrammeEtiquettes::lancerGeneration()
{
   if ( m_fichierWord->getChemin() != "" &&
        m_codePatient->motARemplacer( ) != "" &&
        m_sex->motARemplacer( ) != "" &&
        m_dateDeNaissance->motARemplacer( ) != "" )
   {
      depistage::office::Word word;
      depistage::office::WordDocument document =
         word.open( m_fichierWord->getChemin().toStdString() );
      document.replace( m_codePatient->motARemplacer().toStdString(),
                        m_codePatient->motParLequelRemplacer().toStdString() );
      document.replace( m_sex->motARemplacer().toStdString(),
                        m_sex->motParLequelRemplacer().toStdString() );
      document.replace( m_dateDeNaissance->motARemplacer( ).toStdString( ),
                        m_dateDeNaissance->motParLequelRemplacer().toStdString() );
      document.imprimer();
   }

   if ( m_fichierExcel->getChemin( ) != "" &&
        m_codePatient->motARemplacer( ) != "" &&
        m_sex->motARemplacer( ) != "" &&
        m_dateDeNaissance->motARemplacer( ) != "" )
   {
      depistage::office::Excel excel;
      depistage::office::ExcelDocument document =
         excel.open( m_fichierExcel->getChemin( ).toStdString( ) );
      depistage::office::ExcelOnglet onglet = document.recupererOnglet( 1 );
      std::vector< std::string > informations;
      informations.push_back( m_codePatient->motParLequelRemplacer( ).toStdString( ) );
      informations.push_back( m_sex->motParLequelRemplacer( ).toStdString( ) );
      informations.push_back( m_dateDeNaissance->motParLequelRemplacer( ).toStdString( ) );
      onglet.ajouterLigne( informations );
   }
}

} }
