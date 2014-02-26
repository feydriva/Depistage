
#include "ProgrammeEnregistrement.hpp"

#include <gui/BoutonAction.hpp>

#include <main/Chargement.hpp>

#include <QtCore/QDate>

namespace depistage { namespace main {

namespace {

const QString titre = "Enregistrement";
const QString labelCodePatient = "codePatient";
const QString labelSex = "sex";
const QString labelDateDeNaissance = "dateDeNaissance";
const QString labelDateDuJour = "dateDuJour";
const QString labelWord = "word";
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
   m_sex = creerRemplacerCombo( getConfig( ), tr( "Sexe" ), choix, labelSex );
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
            this,             SLOT( lancerGeneration( ) ) );

   m_fichierWord = creerSelectionFichier( getConfig(),
                                          "Fichier word de rapport : ",
                                          "Ouvrir un document Word",
                                          "Word files  (*.doc *.docx)",
                                          labelWord );
   m_elementsGUI.push_back( m_fichierWord );

   m_fichierExcel = creerSelectionFichier( getConfig(),
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

void ProgrammeEnregistrement::lancerGeneration( )
{
   if ( m_fichierWord->getChemin() != "" &&
        m_fichierExcel->getChemin( ) != "" &&
        m_codePatient->motARemplacer( ) != "" &&
        m_sex->motARemplacer( ) != "" &&
        m_dateDeNaissance->motARemplacer( ) != "" )
   {
      //lancerGenerationWord(
      //   m_fichierWord->getChemin(),
      //   m_codePatient->motARemplacer(), m_codePatient->motParLequelRemplacer(),
      //   m_sex->motARemplacer(), m_sex->motParLequelRemplacer(),
      //   m_dateDeNaissance->motARemplacer(), m_dateDeNaissance->motParLequelRemplacer() );
      //lancerGenerationExcel(
      //   m_fichierExcel->getChemin(),
      //   m_codePatient->motARemplacer(), m_codePatient->motParLequelRemplacer(),
      //   m_sex->motARemplacer(), m_sex->motParLequelRemplacer(),
      //   m_dateDeNaissance->motARemplacer(), m_dateDeNaissance->motParLequelRemplacer() );
   }
}

void ProgrammeEnregistrement::sauverConfig( )
{
   getConfig().setLabel( titre );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelCodePatient, m_codePatient->motARemplacer( ) ) );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelSex, m_sex->motARemplacer( ) ) );
   getConfig().miseAJourRemplacerConfig(
      config::RemplacerConfig( labelDateDeNaissance, m_dateDeNaissance->motARemplacer( ) ) );
   getConfig().miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( labelWord, m_fichierWord->getChemin( ) ) );
   getConfig().miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( labelExcel, m_fichierExcel->getChemin( ) ) );
   getConfigs().sauver();
}

} }
