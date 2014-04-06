
#include "ProgrammeEnregistrement.hpp"

#include <gui/BoutonAction.hpp>

#include <office/Excel.hpp>
#include <office/ExcelDocument.hpp>
#include <office/ExcelOnglet.hpp>
#include <office/Word.hpp>

#include <main/Chargement.hpp>

#include <QtCore/QDate>

namespace depistage { namespace main {

namespace {

const QString titre = "TROD";
const QString labelCodePatient = "codePatient";
const QString labelSex = "sex";
const QString labelDateDeNaissance = "dateDeNaissance";
const QString labelDateDuJour = "dateDuJour";
const QString labelWord = "word";
const QString labelDossier = "dossier";
const QString labelExcel = "excel";

}

ProgrammeEnregistrement::ProgrammeEnregistrement( depistage::config::ConfigProgrammes & configs )
   : ProgrammeStandart( configs, titre )
{
   m_codePatient = creerRemplacerMot( getConfig(), tr( "Code patient" ), labelCodePatient );
   m_elementsGUI.push_back( m_codePatient );

   std::vector< QString > choix;
   choix.push_back( "M" );
   choix.push_back( "F" );
   m_sex = creerRemplacerCombo( getConfig(), tr( "Sexe" ), choix, labelSex );
   m_elementsGUI.push_back( m_sex );

   m_dateDeNaissance =
      creerRemplacerDate( getConfig(), tr( "Date de naissance" ), labelDateDeNaissance );
   m_elementsGUI.push_back( m_dateDeNaissance );

   m_dateDuJour =
      creerRemplacerDate( getConfig(),
                          tr( "Date du jour" ),
                          labelDateDuJour,
                          QDate::currentDate() );
   m_dateDuJour->widgetBasic()->setEnabled( false );
   m_elementsGUI.push_back( m_dateDuJour );

   gui::BoutonAction * boutonGeneration = new depistage::gui::BoutonAction( "Lancer génération" );
   m_elementsGUI.push_back( boutonGeneration );
   connect( boutonGeneration, SIGNAL( clique() ),
            this,             SLOT( lancerGeneration() ) );

   m_fichierWord = creerSelectionFichier( getConfig(),
                                          true,
                                          "Fichier word de rapport : ",
                                          "Ouvrir un document Word",
                                          "Word files  (*.doc *.docx)",
                                          labelWord );
   m_elementsGUI.push_back( m_fichierWord ); 

   m_dossierWord = creerSelectionFichier( getConfig(),
                                          false,
                                          "Dossier de destination des fichiers words : ",
                                          "Choisir un dossier",
                                          "",
                                          labelDossier );
   m_elementsGUI.push_back( m_dossierWord );

   m_fichierExcel = creerSelectionFichier( getConfig(),
                                           true,
                                           "Fichier excel de rapport : ",
                                           "Ouvrir un document Excel",
                                           "Excel files  (*.xls *.xlsx)",
                                           labelExcel );
   m_elementsGUI.push_back( m_fichierExcel );
}

const QString & ProgrammeEnregistrement::getTitre() const
{
   return titre;
}

const std::vector< gui::ElementGUI * > & ProgrammeEnregistrement::getElementsGUI() const
{
   return m_elementsGUI;
}

namespace {

void lancerGenerationWord( const QString & cheminWord, const QString & cheminDossier,
                           const QString & codePatientAvant, const QString & codePatientApres,
                           const QString & sexAvant, const QString & sexApres,
                           const QString & dateNaissanceAvant, const QString & dateNaissanceApres,
                           const QString & dateDuJourAvant, const QString & dateDuJourApres )
{
   depistage::office::Word word;
   depistage::office::WordDocument document = word.open( cheminWord.toStdString() );
   document.replace( codePatientAvant.toStdString(), codePatientApres.toStdString() );
   document.replace( sexAvant.toStdString(), sexApres.toStdString() );
   document.replace( dateNaissanceAvant.toStdString(), dateNaissanceApres.toStdString() );
   document.replace( dateDuJourAvant.toStdString(), dateDuJourApres.toStdString() );
   unsigned point = cheminWord.toStdString().find_last_of( "." );
   const std::string extension = cheminWord.toStdString().substr( point );
   std::string nouveauFichier =
      cheminDossier.toStdString() + "/" +
      "trod_resultat_negatif_code_" + codePatientApres.toStdString( ) + extension;
   document.saveAs( nouveauFichier );
}

void lancerGenerationExcel( const QString & cheminExcel,
                            const QString & codePatient,
                            const QString & sex,
                            const QString & dateNaissance,
                            const QString & dateDuJour )
{
    office::Excel excel;
    office::ExcelDocument document = excel.open( cheminExcel.toStdString() );
    office::ExcelOnglet onglet = document.recupererOnglet( 1 );
    std::vector< std::string > informations;
    informations.push_back( codePatient.toStdString() );
    informations.push_back( sex.toStdString() );
    informations.push_back( dateNaissance.toStdString() );
    informations.push_back( dateDuJour.toStdString() );
    onglet.ajouterLigne( informations );
    document.save();
    excel.quit();
}

}

void ProgrammeEnregistrement::lancerGeneration()
{
   if ( m_fichierWord->getChemin() != "" &&
        m_dossierWord->getChemin() != "" &&
        m_fichierExcel->getChemin() != "" &&
        m_codePatient->motARemplacer() != "" &&
        m_sex->motARemplacer() != "" &&
        m_dateDeNaissance->motARemplacer() != "" )
   {
      lancerGenerationWord(
         m_fichierWord->getChemin(), m_dossierWord->getChemin(),
         m_codePatient->motARemplacer(), m_codePatient->motParLequelRemplacer(),
         m_sex->motARemplacer(), m_sex->motParLequelRemplacer(),
         m_dateDeNaissance->motARemplacer(), m_dateDeNaissance->motParLequelRemplacer(),
         m_dateDuJour->motARemplacer(), m_dateDuJour->motParLequelRemplacer() );
      lancerGenerationExcel(
         m_fichierExcel->getChemin(),
         m_codePatient->motParLequelRemplacer(),
         m_sex->motParLequelRemplacer(),
         m_dateDeNaissance->motParLequelRemplacer(),
         m_dateDuJour->motParLequelRemplacer() );
   }
}

void ProgrammeEnregistrement::sauverConfig()
{
   getConfig().setLabel( titre );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelCodePatient, m_codePatient->motARemplacer() ) );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelSex, m_sex->motARemplacer() ) );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelDateDeNaissance, m_dateDeNaissance->motARemplacer() ) );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelDateDuJour, m_dateDuJour->motARemplacer() ) );
   getConfig().miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( labelWord, m_fichierWord->getChemin() ) );
   getConfig().miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( labelDossier, m_dossierWord->getChemin() ) );
   getConfig().miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( labelExcel, m_fichierExcel->getChemin() ) );
   getConfigs().sauver();
}

} }
