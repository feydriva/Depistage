
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

const QString labelCodePatient = "codePatient";
const QString labelSex = "sex";
const QString labelDateDeNaissance = "dateDeNaissance";
const QString labelDateDuJour = "dateDuJour";
const QString labelRealisePar = "realisePar";
const QString labelRenduPar = "renduPar";
const QString labelNumeroDeLot = "numeroDeLot";
const QString labelWord = "word";
const QString labelDossier = "dossier";
const QString labelExcel = "excel";

}

ProgrammeEnregistrement::ProgrammeEnregistrement( const QString & titre,
                                                  depistage::config::ConfigProgrammes & configs )
   : ProgrammeStandart( configs, titre ),
     m_titre( titre )
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

   m_realisePar = creerRemplacerMot( getConfig( ), tr( "Réalisé par" ), labelRealisePar );
   m_elementsGUI.push_back( m_realisePar );

   m_renduPar = creerRemplacerMot( getConfig( ), tr( "Rendu par" ), labelRenduPar, "Docteur " );
   m_elementsGUI.push_back( m_renduPar );

   m_numeroDeLot = creerRemplacerMot( getConfig( ), tr( "Numéro de lot" ), labelNumeroDeLot );
   m_elementsGUI.push_back( m_numeroDeLot );


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
   return m_titre;
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
                           const QString & dateDuJourAvant, const QString & dateDuJourApres,
                           const QString & realiseParAvant, const QString & realiseParApres,
                           const QString & renduParAvant, const QString & renduParApres,
                           const QString & numeroDeLotAvant, const QString & numeroDeLotApres )
{
   depistage::office::Word word;
   depistage::office::WordDocument document = word.open( cheminWord.toStdString() );
   document.replace( codePatientAvant.toStdString(), codePatientApres.toStdString() );
   document.replace( sexAvant.toStdString(), sexApres.toStdString() );
   document.replace( dateNaissanceAvant.toStdString(), dateNaissanceApres.toStdString() );
   document.replace( dateDuJourAvant.toStdString(), dateDuJourApres.toStdString() );
   document.replace( realiseParAvant.toStdString(), realiseParApres.toStdString() );
   document.replace( renduParAvant.toStdString(), renduParApres.toStdString() );
   if ( numeroDeLotAvant != "" )
   {
      document.replace( numeroDeLotAvant.toStdString( ), numeroDeLotApres.toStdString( ) );
   }
   unsigned point = cheminWord.toStdString().find_last_of( "." );
   const std::string extension = cheminWord.toStdString().substr( point );
   std::string nouveauFichier =
      cheminDossier.toStdString() + "/" +
      "trod_resultat_negatif_code_" + codePatientApres.toStdString( ) + extension;
   document.saveAs( nouveauFichier );
   document.imprimer();
   word.quit( depistage::office::Word::ModeFermeture::SansSauvegarde );
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
        m_dateDeNaissance->motARemplacer() != "" &&
        m_realisePar->motARemplacer() != "" &&
        m_renduPar->motARemplacer() != "")
   {
      lancerGenerationWord(
         m_fichierWord->getChemin(), m_dossierWord->getChemin(),
         m_codePatient->motARemplacer(), m_codePatient->motParLequelRemplacer(),
         m_sex->motARemplacer(), m_sex->motParLequelRemplacer(),
         m_dateDeNaissance->motARemplacer(), m_dateDeNaissance->motParLequelRemplacer(),
         m_dateDuJour->motARemplacer(), m_dateDuJour->motParLequelRemplacer(),
         m_realisePar->motARemplacer(), m_realisePar->motParLequelRemplacer(),
         m_renduPar->motARemplacer(), m_renduPar->motParLequelRemplacer(),
         m_numeroDeLot->motARemplacer( ), m_numeroDeLot->motParLequelRemplacer( ) );
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
   getConfig().setLabel( m_titre );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelCodePatient, m_codePatient->motARemplacer() ) );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelSex, m_sex->motARemplacer() ) );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelDateDeNaissance, m_dateDeNaissance->motARemplacer() ) );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelDateDuJour, m_dateDuJour->motARemplacer() ) );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelRealisePar, m_realisePar->motARemplacer() ) );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelRenduPar, m_renduPar->motARemplacer() ) );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelNumeroDeLot, m_numeroDeLot->motARemplacer() ) );
   getConfig().miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( labelWord, m_fichierWord->getChemin() ) );
   getConfig().miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( labelDossier, m_dossierWord->getChemin() ) );
   getConfig().miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( labelExcel, m_fichierExcel->getChemin() ) );
   getConfigs().sauver();
}

} }
