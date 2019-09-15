#include "PrimaryGenerator.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

PrimaryGenerator::PrimaryGenerator (
                    const G4String& particleName,
                    G4double energy,
                    G4ThreeVector position,
                    G4ThreeVector momentumDirection)
  : G4VUserPrimaryGeneratorAction(),
    fParticleGun(0)
{
  G4int particleNum = 1;
  fParticleGun = new G4ParticleGun(particleNum);

  G4ParticleTable* particleTable = G4ParticleTable::GetParticeTable();
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName);
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleEnergy(energy);
  fParticleGun->SetParticlePosition(position);
  fParticleGun->SetParticleMomentumDirection(momentumDirection);
}

PrimaryGenerator::~PrimaryGenerator()
{
  delete fParticleGun;
}

void PrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
{
  fParticleGun->GeneratePrimaryVertex(anEvent);
}
