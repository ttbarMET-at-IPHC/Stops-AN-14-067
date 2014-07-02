#ifndef _SecondLeptonInAcceptance_H
#define _SecondLeptonInAcceptance_H

struct HighestPt
{
  bool operator()( TLorentzVector p1, TLorentzVector p2 ) const {
        return p1.Pt() > p2.Pt() ;
  }
};

// Return true for multilepton events  with true truth-level track and events with true truth-level tau
bool IsMultilepEvtWithTrueTrkFromTau(){

	 bool hastruetrk = false;
	 bool hastruetau = false;
	 
	 //--- store index of genLeptons ---//
	 vector<int> genLeptons; 
	 for(unsigned int ip=0;ip<myEvent.genParticles.size();ip++){
		if(fabs(myEvent.genParticlesPDGId[ip])==11 || fabs(myEvent.genParticlesPDGId[ip])==13 || fabs(myEvent.genParticlesPDGId[ip])==15){
			if(abs(myEvent.genParticlesPDGId[myEvent.genParticlesMother[ip]])==23 || abs(myEvent.genParticlesPDGId[myEvent.genParticlesMother[ip]])==24){
				genLeptons.push_back(ip);
			}
		}
	 }
	 //---------------------------------//
	 //sort the vector in Pt
	 std::sort(genLeptons.begin(),genLeptons.end(),HighestPt());

	 // Event have at least 2 generated leptons and second lepton has [Eta| < 2.5
	 if (genLeptons.size()>1 && abs(myEvent.genParticles[genLeptons[1]].Eta())<2.5) {
	 	//check if second lepton is e/mu pT>5GeV
	 	// Second lepton is an electron or muon with pT > 5
	 	if (abs(myEvent.genParticlesPDGId[genLeptons[1]])<14 && myEvent.genParticles[genLeptons[1]].Pt()>5.) hastruetrk = true;
	 	//if second lepton is tau
	 	//check if daughter lepton or single track has pT>10GeV
		 if (abs(myEvent.genParticlesPDGId[genLeptons[1]])==15) {
	 		//access info of tau decay
			vector<int> tauDecay;
			bool tauHad = false;
			TLorentzVector taudvis;
			for(unsigned int td=genLeptons[1]+1;td<myEvent.genParticles.size();td++){
			if(myEvent.genParticlesMother[td]==genLeptons[1]){
				if(abs(myEvent.genParticlesPDGId[td])>16) tauHad = true;
				if(abs(myEvent.genParticlesPDGId[td])!=16 && abs(myEvent.genParticlesPDGId[td])!=14 && abs(myEvent.genParticlesPDGId[td])!=12) taudvis+=myEvent.genParticles[td];
				tauDecay.push_back(td);
				//int aid = abs(myEvent.genParticlesPDGId[td]);
				//if((aid>20) &&(aid!=22 && aid!=130 && aid!=111 && aid!=211)) cout<<" - "<<myEvent.genParticlesPDGId[td]<<endl;
			}
		}
		//check for hadronic tau
		if(tauHad){
			int ntracks = 0;
			float trackPt = 0;
			for(unsigned int vtd=0;vtd<tauDecay.size();vtd++){
				int aid = abs(myEvent.genParticlesPDGId[tauDecay[vtd]]);
				if(aid==211 || aid==321) {
					trackPt = myEvent.genParticles[tauDecay[vtd]].Pt();
					ntracks++;
				}
			}
			//if(ntracks!=1 && ntracks!=3) cout<<"had tau: "<<ntracks<<" tracks"<<endl;
			if (ntracks==1 && trackPt>10.) hastruetrk = true;
		}
		//check for leptonic decay
		else{
			for(unsigned int vtd=0;vtd<tauDecay.size();vtd++){
				if(abs(myEvent.genParticlesPDGId[tauDecay[vtd]]==11 || abs(myEvent.genParticlesPDGId[tauDecay[vtd]])==13))
					if(myEvent.genParticles[tauDecay[vtd]].Pt()>5.) hastruetrk = true;
			}
		}
	 	if (taudvis.Pt()>20.) hastruetau = true;
	  }
	 }
	 if (hastruetrk && hastruetau) return true;
	 return false;
}

#endif
