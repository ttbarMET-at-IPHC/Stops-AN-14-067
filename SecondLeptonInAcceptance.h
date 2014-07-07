#ifndef _SecondLeptonInAcceptance_h
#define _SecondLeptonInAcceptance_h

// Return true for multilepton events  with true truth-level track and events with true truth-level tau
bool EventHasSecondGeneratedLeptonInAcceptance()
{

     // Get indexes of generated leptons
	 vector<int> genLeptons; 
	 for(unsigned int ip=0;ip<myEvent.genParticles.size();ip++)
     {
        int genParticlePDGId = abs(myEvent.genParticlesPDGId[ip]);

		if (genParticlePDGId == 11
         || genParticlePDGId == 13
         || genParticlePDGId == 15)
        {
            int genParticleMotherPDGId = abs(myEvent.genParticlesPDGId[myEvent.genParticlesMother[ip]]);
			if (genParticleMotherPDGId == 23
             || genParticleMotherPDGId == 24)
            {
				genLeptons.push_back(ip);
			}
		}
	 }

	 // Sort the vector in Pt
	 vector<TLorentzVector> genParticles = myEvent.genParticles; 
     sort(genLeptons.begin(),genLeptons.end(),
          [&genParticles](int index1, int index2)
          { 
             return genParticles[index1].Pt() > genParticles[index2].Pt(); 
          });

     // Check event has at least 2 generated leptons
     if (genLeptons.size() < 2) return false;

     int secondGenLeptonIndex = genLeptons[1];
     int secondGenLeptonPDGId = myEvent.genParticlesPDGId[secondGenLeptonIndex];
     TLorentzVector secondGenLepton = myEvent.genParticles[secondGenLeptonIndex];

     // Check second lepton is in eta < 2.5
	 if (abs(secondGenLepton.Eta()) > 2.5) return false;

     // e/mu case (pt > 5)

     // Second lepton is an electron or muon with pT > 5
     if ((abs(secondGenLeptonPDGId) < 14)
          && (secondGenLepton.Pt() > 5)) return true;
     
     // tau case
     
     //check if daughter lepton or single track has pT>10GeV
     if (abs(secondGenLeptonPDGId) == 15) 
     {
         //access info of tau decay
         vector<int> tauDecay;
         bool tauHad = false;
         TLorentzVector taudvis;
         for(unsigned int td = secondGenLeptonIndex+1 ; td < myEvent.genParticles.size() ; td++)
         {
             if(myEvent.genParticlesMother[td] == secondGenLeptonIndex)
             {
                 if(abs(myEvent.genParticlesPDGId[td])>16) tauHad = true;

                 if(abs(myEvent.genParticlesPDGId[td])!=16 
                 && abs(myEvent.genParticlesPDGId[td])!=14 
                 && abs(myEvent.genParticlesPDGId[td])!=12) 
                     taudvis+=myEvent.genParticles[td];

                 tauDecay.push_back(td);
             }
         }
         //check for hadronic tau
         if(tauHad)
         {
             int ntracks = 0;
             float trackPt = 0;
             for (unsigned int vtd=0 ; vtd < tauDecay.size() ; vtd++)
             {
                 int aid = abs(myEvent.genParticlesPDGId[tauDecay[vtd]]);
                 if(aid==211 || aid==321) 
                 {
                     trackPt = myEvent.genParticles[tauDecay[vtd]].Pt();
                     ntracks++;
                 }
             }
             if (ntracks==1 && trackPt>10.) return true;
         }
         //check for leptonic decay
         else{
             for(unsigned int vtd=0;vtd<tauDecay.size();vtd++){
                 if(abs(myEvent.genParticlesPDGId[tauDecay[vtd]]==11 || abs(myEvent.genParticlesPDGId[tauDecay[vtd]])==13))
                     if(myEvent.genParticles[tauDecay[vtd]].Pt()>5.) return true;
             }
         }
         if (taudvis.Pt()>20.) return true;
     }
	 
     return false;
}

#endif
