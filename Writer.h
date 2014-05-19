#ifndef babyWriter
#define babyWriter


void InitializeBranchesForWriting(TTree* theTree, babyEvent* myEvent)
{
    theTree->Branch("run",                                          &(myEvent->run));
    theTree->Branch("lumi",                                         &(myEvent->lumi));
    theTree->Branch("event",                                        &(myEvent->event));
    
    theTree->Branch("triggerMuon",                                  &(myEvent->triggerMuon));
    theTree->Branch("xtriggerMuon",                                 &(myEvent->xtriggerMuon));
    theTree->Branch("triggerElec",                                  &(myEvent->triggerElec));
    theTree->Branch("triggerDoubleElec",                            &(myEvent->triggerDoubleElec));
    theTree->Branch("triggerDoubleMuon",                            &(myEvent->triggerDoubleMuon));
    theTree->Branch("triggerMuonElec",                              &(myEvent->triggerMuonElec));
    
    theTree->Branch("numberOfLepton",                               &(myEvent->numberOfLepton));
    theTree->Branch("leadingLepton","TLorentzVector",               &(myEvent->leadingLepton));
    theTree->Branch("leadingLeptonPDGId",                           &(myEvent->leadingLeptonPDGId));
    theTree->Branch("secondLepton","TLorentzVector",                &(myEvent->secondLepton));
    theTree->Branch("secondLeptonPDGId",                            &(myEvent->secondLeptonPDGId));
    theTree->Branch("isolatedTrackVeto",                            &(myEvent->isolatedTrackVeto));
    theTree->Branch("tauVeto",                                      &(myEvent->tauVeto));
     
    theTree->Branch("nJets",                                        &(myEvent->nJets));
    theTree->Branch("nBTag",                                        &(myEvent->nBTag));
    theTree->Branch("jets","std::vector<TLorentzVector>",           &(myEvent->jets));
    theTree->Branch("jets_CSV_raw",     "std::vector<Float_t>",     &(myEvent->jets_CSV_raw));
    theTree->Branch("jets_CSV_reshaped","std::vector<Float_t>",     &(myEvent->jets_CSV_reshaped));
    theTree->Branch("jets_partonFlav",  "std::vector<Int_t>",       &(myEvent->jets_partonFlav));

    theTree->Branch("MET",                                          &(myEvent->MET));
    theTree->Branch("MT",                                           &(myEvent->MT));
    theTree->Branch("deltaPhiMETJets",                              &(myEvent->deltaPhiMETJets));
    theTree->Branch("hadronicChi2",                                 &(myEvent->hadronicChi2));
    theTree->Branch("MT2W",                                         &(myEvent->MT2W));
    theTree->Branch("HT",                                           &(myEvent->HT));
    theTree->Branch("HTRatio",                                      &(myEvent->HTRatio));
    theTree->Branch("leadingBPt",                                   &(myEvent->leadingBPt));
    theTree->Branch("leadingLeptonPt",                              &(myEvent->leadingLeptonPt));
    theTree->Branch("leadingJetPt",                                 &(myEvent->leadingJetPt));
    theTree->Branch("Mlb",                                          &(myEvent->Mlb));
    theTree->Branch("Mlb_hemi",                                     &(myEvent->Mlb_hemi));
    theTree->Branch("M3b",                                          &(myEvent->M3b));
    theTree->Branch("deltaRLeptonLeadingB",                         &(myEvent->deltaRLeptonLeadingB));
    theTree->Branch("METoverSqrtHT",                                &(myEvent->METoverSqrtHT));
    theTree->Branch("HTPlusLeptonPtPlusMET",                        &(myEvent->HTPlusLeptonPtPlusMET));
    
    theTree->Branch("nWTag",                                        &(myEvent->nWTag));
    theTree->Branch("leadingWjetPt",                                &(myEvent->leadingWjetPt));
    
    theTree->Branch("mStop",                                        &(myEvent->mStop));
    theTree->Branch("mNeutralino",                                  &(myEvent->mNeutralino));
    theTree->Branch("mCharginoParameter",                           &(myEvent->mCharginoParameter));
    
    theTree->Branch("numberOfGenLepton",                            &(myEvent->numberOfGenLepton));
    theTree->Branch("genParticles","std::vector<TLorentzVector>",   &(myEvent->genParticles));
    theTree->Branch("genParticlesPDGId","std::vector<Int_t>",       &(myEvent->genParticlesPDGId));
    theTree->Branch("genParticlesMother","std::vector<Int_t>",      &(myEvent->genParticlesMother));
    
    theTree->Branch("numberOfInitialEvents",                        &(myEvent->numberOfInitialEvents));
    theTree->Branch("crossSection",                                 &(myEvent->crossSection));
    theTree->Branch("numberOfTruePU",                               &(myEvent->numberOfTruePU));
    theTree->Branch("numberOfPrimaryVertices",                      &(myEvent->numberOfPrimaryVertices));
    theTree->Branch("weightCrossSection",                           &(myEvent->weightCrossSection));
    theTree->Branch("weightPileUp",                                 &(myEvent->weightPileUp));
    theTree->Branch("weightISRmodeling",                            &(myEvent->weightISRmodeling));
    theTree->Branch("weightTopPt",                                  &(myEvent->weightTopPt));
    theTree->Branch("weightT2ttLeftHanded",                         &(myEvent->weightT2ttLeftHanded));
    theTree->Branch("weightT2ttRightHanded",                        &(myEvent->weightT2ttRightHanded));
    theTree->Branch("weightT2bwPolarization_ss",                    &(myEvent->weightT2bwPolarization_ss));
    theTree->Branch("weightT2bwPolarization_ls",                    &(myEvent->weightT2bwPolarization_ss));
    theTree->Branch("weightT2bwPolarization_sl",                    &(myEvent->weightT2bwPolarization_ss));
    theTree->Branch("weightT2bwPolarization_sr",                    &(myEvent->weightT2bwPolarization_ss));
    theTree->Branch("weightT2bwPolarization_rs",                    &(myEvent->weightT2bwPolarization_ss));
    theTree->Branch("weightT2bwPolarization_ll",                    &(myEvent->weightT2bwPolarization_ll));
    theTree->Branch("weightT2bwPolarization_lr",                    &(myEvent->weightT2bwPolarization_lr));
    theTree->Branch("weightT2bwPolarization_rl",                    &(myEvent->weightT2bwPolarization_rl));
    theTree->Branch("weightT2bwPolarization_rr",                    &(myEvent->weightT2bwPolarization_rr));
   
    theTree->Branch("MET_JESup",                                    &(myEvent->MET_JESup));
    theTree->Branch("MT_JESup",                                     &(myEvent->MT_JESup));
    theTree->Branch("deltaPhiMETJets_JESup",                        &(myEvent->deltaPhiMETJets_JESup));
    theTree->Branch("hadronicChi2_JESup",                           &(myEvent->hadronicChi2_JESup));
    theTree->Branch("MT2W_JESup",                                   &(myEvent->MT2W_JESup));
    theTree->Branch("HT_JESup",                                     &(myEvent->HT_JESup));
    theTree->Branch("HTRatio_JESup",                                &(myEvent->HTRatio_JESup));
    theTree->Branch("leadingBPt_JESup",                             &(myEvent->leadingBPt_JESup));
    theTree->Branch("leadingJetPt_JESup",                           &(myEvent->leadingJetPt_JESup));
    theTree->Branch("Mlb_JESup",                                    &(myEvent->Mlb_JESup));
    theTree->Branch("Mlb_hemi_JESup",                               &(myEvent->Mlb_hemi_JESup));
    theTree->Branch("M3b_JESup",                                    &(myEvent->M3b_JESup));
    theTree->Branch("deltaRLeptonLeadingB_JESup",                   &(myEvent->deltaRLeptonLeadingB_JESup));
    theTree->Branch("METoverSqrtHT_JESup",                          &(myEvent->METoverSqrtHT_JESup));
    theTree->Branch("HTPlusLeptonPtPlusMET_JESup",                  &(myEvent->HTPlusLeptonPtPlusMET_JESup));
    theTree->Branch("nJets_JESup",                                  &(myEvent->nJets_JESup));
    
    theTree->Branch("MET_JESdown",                                  &(myEvent->MET_JESdown));
    theTree->Branch("MT_JESdown",                                   &(myEvent->MT_JESdown));
    theTree->Branch("deltaPhiMETJets_JESdown",                      &(myEvent->deltaPhiMETJets_JESdown));
    theTree->Branch("hadronicChi2_JESdown",                         &(myEvent->hadronicChi2_JESdown));
    theTree->Branch("MT2W_JESdown",                                 &(myEvent->MT2W_JESdown));
    theTree->Branch("HT_JESdown",                                   &(myEvent->HT_JESdown));
    theTree->Branch("HTRatio_JESdown",                              &(myEvent->HTRatio_JESdown));
    theTree->Branch("leadingBPt_JESdown",                           &(myEvent->leadingBPt_JESdown));
    theTree->Branch("leadingJetPt_JESdown",                         &(myEvent->leadingJetPt_JESdown));
    theTree->Branch("Mlb_JESdown",                                  &(myEvent->Mlb_JESdown));
    theTree->Branch("Mlb_hemi_JESdown",                             &(myEvent->Mlb_hemi_JESdown));
    theTree->Branch("M3b_JESdown",                                  &(myEvent->M3b_JESdown));
    theTree->Branch("deltaRLeptonLeadingB_JESdown",                 &(myEvent->deltaRLeptonLeadingB_JESdown));
    theTree->Branch("METoverSqrtHT_JESdown",                        &(myEvent->METoverSqrtHT_JESdown));
    theTree->Branch("HTPlusLeptonPtPlusMET_JESdown",                &(myEvent->HTPlusLeptonPtPlusMET_JESdown));
    theTree->Branch("nJets_JESdown",                                &(myEvent->nJets_JESdown));

    theTree->Branch("jets_CSV_reshapedUpBC",       "std::vector<Float_t>",          &(myEvent->jets_CSV_reshapedUpBC));
    theTree->Branch("jets_CSV_reshapedDownBC",     "std::vector<Float_t>",          &(myEvent->jets_CSV_reshapedDownBC));
    theTree->Branch("jets_CSV_reshapedUpLight",    "std::vector<Float_t>",          &(myEvent->jets_CSV_reshapedUpLight));
    theTree->Branch("jets_CSV_reshapedDownLight",  "std::vector<Float_t>",          &(myEvent->jets_CSV_reshapedDownLight));

    theTree->Branch("nonSelectedJets",             "std::vector<TLorentzVector>",   &(myEvent->nonSelectedJets));
    theTree->Branch("nonSelectedJets_CSV_raw",     "std::vector<Float_t>",          &(myEvent->nonSelectedJets_CSV_raw));
    theTree->Branch("nonSelectedJets_CSV_reshaped","std::vector<Float_t>",          &(myEvent->nonSelectedJets_CSV_reshaped));
    theTree->Branch("nonSelectedJets_partonFlav",  "std::vector<Int_t>",            &(myEvent->nonSelectedJets_partonFlav));

    theTree->Branch("nonSelectedLeptons",          &(myEvent->nonSelectedLeptons));
    theTree->Branch("nonSelectedLeptonsPDGId",     &(myEvent->nonSelectedLeptonsPDGId));
    theTree->Branch("rawPFMET",     		   &(myEvent->rawPFMET));

    theTree->Branch("x_firstIncomingParton",        &(myEvent->x_firstIncomingParton));       
    theTree->Branch("x_secondIncomingParton",       &(myEvent->x_secondIncomingParton));      
    theTree->Branch("flavor_firstIncomingParton",   &(myEvent->flavor_firstIncomingParton));  
    theTree->Branch("flavor_secondIncomingParton",  &(myEvent->flavor_secondIncomingParton)); 
    theTree->Branch("scalePDF",                     &(myEvent->scalePDF));                   

}



#endif
