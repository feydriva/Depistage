
#include "ProgrammeEtiquettes.hpp"

#include <config/ConfigProgramme.hpp>

#include <gui/BoutonAction.hpp>

#include <office/Word.hpp>
#include <office/WordDocument.hpp>
#include <office/Excel.hpp>
#include <office/ExcelDocument.hpp>
#include <office/ExcelOnglet.hpp>

#include <string>
#include <vector>
#include <iostream>
namespace depistage { namespace main {

namespace {

const QString chemin = "config.xml";
const QString labelCodePatient = "codePatient";
const QString labelSex = "sex";
const QString labelDateDeNaissance = "dateDeNaissance";
const QString labelWord = "word";
const QString labelExcel = "excel";

depistage::gui::MetaRemplacer * creerMetaRemplacer( config::ConfigProgramme & config,
                                                    const QString & labelAffichage,
                                                    const QString & labelXML )
{
   QString motARemplacer = config.recupRemplacerMot( labelXML ).getMotARemplacer();
   return new depistage::gui::MetaRemplacer( labelAffichage, motARemplacer );
}

depistage::gui::SelectionFichier * creerSelectionFichier( config::ConfigProgramme & config,
   const QString & labelAffichage,
   const QString & labelFenetre,
   const QString & filtre,
   const QString & labelXML )
{
   QString chemin = config.recupSelectionFichier( labelXML ).getChemin();
   return new depistage::gui::SelectionFichier( labelAffichage, labelFenetre, filtre, chemin );
}

}

ProgrammeEtiquettes::ProgrammeEtiquettes()
{
   config::ConfigProgramme config = config::ConfigProgramme::chargerXML( chemin );

   m_codePatient = creerMetaRemplacer( config, tr( "Code patient" ), labelCodePatient );
   m_elementsGUI.push_back( m_codePatient );
   m_sex = creerMetaRemplacer( config, tr( "Sex" ), labelSex );
   m_elementsGUI.push_back( m_sex );
   m_dateDeNaissance =
      creerMetaRemplacer( config, tr( "Date de naissance" ), labelDateDeNaissance );
   m_elementsGUI.push_back( m_dateDeNaissance );

   gui::BoutonAction * boutonGeneration = new depistage::gui::BoutonAction( "Lancer génération" );
   m_elementsGUI.push_back( boutonGeneration );
   connect( boutonGeneration, SIGNAL( clique() ),
            this,             SLOT( lancerGeneration( ) ) );

   m_fichierWord = creerSelectionFichier( config,
                                          "Fichier word de rapport : ",
                                          "Ouvrir un document Word",
                                          "Word files  (*.doc *.docx)",
                                          labelWord );
   m_elementsGUI.push_back( m_fichierWord );
   m_fichierExcel = creerSelectionFichier( config,
                                          "Fichier excel de rapport : ",
                                          "Ouvrir un document Excel",
                                          "Excel files (*.xls *.xlsx)",
                                          labelWord );
   m_elementsGUI.push_back( m_fichierExcel );
}

void ProgrammeEtiquettes::sauverConfig( ) const
{
   config::ConfigProgramme config( "etiquettes" );
   config.miseAJourRemplacerMotConfig(
      config::RemplacerMotConfig( labelCodePatient, m_codePatient->motARemplacer( ) ) );
   config.miseAJourRemplacerMotConfig(
      config::RemplacerMotConfig( labelSex, m_sex->motARemplacer( ) ) );
   config.miseAJourRemplacerMotConfig(
      config::RemplacerMotConfig( labelDateDeNaissance, m_dateDeNaissance->motARemplacer( ) ) );
   config.miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( labelWord, m_fichierWord->getChemin( ) ) );
   config.miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( labelExcel, m_fichierExcel->getChemin( ) ) );
   config::ConfigProgramme::sauverXML( config, chemin );
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
