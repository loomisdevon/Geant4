 #include "ActionInitialization.hh"

 #include "PrimaryGenerator.hh"

 void ActionInitialization::Build() const
 {
   SetUserAction(new PrimaryGenerator);
 }
