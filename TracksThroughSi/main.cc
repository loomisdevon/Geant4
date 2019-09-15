//Heavy Ion Tracks through Silicon

#include "G4RunManager.hh"
#include "G4UImanager.hh"

#include "G4UImanager.hh"
#include "QBBC.hh"

#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"


int main()
{
  G4RunManager* runManager = new G4RunManager;

  runManager->SetUserInitialization(new DetectorConstruction);

  G4VModularPhysicsList* physicsList = new QBBC;
  physicsList->SetVerboseLevel(1);
  runManager->SetUserInitialization(physicsList);

  runManager->SetUserInitialization(ActionInitialization);

  runManager->Initialize();

  G4UImanager* UI = G4UImanager:;GetUIpointer();
  UI->ApplyCommand("/run/verbose 1");
  UI->ApplyCommand("/event/verbose 1");
  UI->ApplyCommand("/tracking/verbose 1");

  int number = 5
  runManager->BeamOn(number);

  delete runManager;
  return 0;
}
