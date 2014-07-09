#ifndef _BDTCUTS_H
#define _BDTCUTS_H

float BDTCutIndepSR[16][4];
float BDTCuts[18];

void LoadBDTCutIndepSR(){
	BDTCutIndepSR[0][0]=0.295;	BDTCutIndepSR[0][1]=0.255;	BDTCutIndepSR[0][2]=0.225;	BDTCutIndepSR[0][3]=0.205;
	BDTCutIndepSR[1][0]=0.325;	BDTCutIndepSR[1][1]=0.265;	BDTCutIndepSR[1][2]=0.225;	BDTCutIndepSR[1][3]=0.185;
	BDTCutIndepSR[2][0]=0.175;	BDTCutIndepSR[2][1]=0.115;	BDTCutIndepSR[2][2]=0.075;	BDTCutIndepSR[2][3]=0.045;
	BDTCutIndepSR[3][0]=0.215;	BDTCutIndepSR[3][1]=0.185;	BDTCutIndepSR[3][2]=0.165;	BDTCutIndepSR[3][3]=0.145;
	BDTCutIndepSR[4][0]=0.255;	BDTCutIndepSR[4][1]=0.205;	BDTCutIndepSR[4][2]=0.165;	BDTCutIndepSR[4][3]=0.135;
	BDTCutIndepSR[5][0]=0.225;	BDTCutIndepSR[5][1]=0.165;	BDTCutIndepSR[5][2]=0.125;	BDTCutIndepSR[5][3]=0.095;
	BDTCutIndepSR[6][0]=0.105;	BDTCutIndepSR[6][1]=0.055;	BDTCutIndepSR[6][2]=0.025;	BDTCutIndepSR[6][3]=-0.005;
	BDTCutIndepSR[7][0]=0.205;	BDTCutIndepSR[7][1]=0.165;	BDTCutIndepSR[7][2]=0.145;	BDTCutIndepSR[7][3]=0.125;
	BDTCutIndepSR[8][0]=0.165;	BDTCutIndepSR[8][1]=0.095;	BDTCutIndepSR[8][2]=0.065;	BDTCutIndepSR[8][3]=0.035;
	BDTCutIndepSR[9][0]=0.095;	BDTCutIndepSR[9][1]=0.045;	BDTCutIndepSR[9][2]=0.015;	BDTCutIndepSR[9][3]=-0.015;
	BDTCutIndepSR[10][0]=0.085;	BDTCutIndepSR[10][1]=0.035;	BDTCutIndepSR[10][2]=0.005;	BDTCutIndepSR[10][3]=-0.025;
	BDTCutIndepSR[11][0]=0.065;	BDTCutIndepSR[11][1]=0.015;	BDTCutIndepSR[11][2]=-0.015;	BDTCutIndepSR[11][3]=-0.045;
	BDTCutIndepSR[12][0]=0.165;	BDTCutIndepSR[12][1]=0.125;	BDTCutIndepSR[12][2]=0.095;	BDTCutIndepSR[12][3]=0.065;
	BDTCutIndepSR[13][0]=0.115;	BDTCutIndepSR[13][1]=0.065;	BDTCutIndepSR[13][2]=0.035;	BDTCutIndepSR[13][3]=0.005;
	BDTCutIndepSR[14][0]=0.075;	BDTCutIndepSR[14][1]=0.035;	BDTCutIndepSR[14][2]=0.005;	BDTCutIndepSR[14][3]=-0.015;
	BDTCutIndepSR[15][0]=0.035;	BDTCutIndepSR[15][1]=-0.005;	BDTCutIndepSR[15][2]=-0.035;	BDTCutIndepSR[15][3]=-0.065;
}

//Loading the loosened BDT cuts used for the CR
//CRregion correspond to the Control Region choosen
//In case of test using independant bins in the BDT distribution
//CR_4j_bin corresponds to the bins choosen
//BDTCutIndepSR_NextBin allows to move from one bin to another one
void LoadBDTCut(string CRregion, int CR4_4j_Bin = 0, bool BDTCutIndepSR_NextBin = false)
{
  if(CRregion == string("CR4_1j")){
    BDTCuts[0] =  0.305;
    BDTCuts[1] =  0.395;
    BDTCuts[2] =  0.265;
    BDTCuts[3] =  0.265;
    BDTCuts[4] =  0.225;
    BDTCuts[5] =  0.315;
    BDTCuts[6] =  0.305;  
    BDTCuts[7] =  0.175;  
    BDTCuts[8] =  0.225;
    BDTCuts[9] =  0.225;
    BDTCuts[10] =  0.295; 
    BDTCuts[11] =  0.185; 
    BDTCuts[12] =  0.175; 
    BDTCuts[13] =  0.145; 
    BDTCuts[14] =  0.205;  
    BDTCuts[15] =  0.185; 
    BDTCuts[16] =  0.135;  
    BDTCuts[17] =  0.105;
 }
  if(CRregion == string("CR4_2j")){
     BDTCuts[0] =  0.305;
     BDTCuts[1] =  0.365 ;
     BDTCuts[2] =  0.225 ;
     BDTCuts[3] =  0.225;
     BDTCuts[4] =  0.225;
     BDTCuts[5] =  0.285;
     BDTCuts[6] =  0.275;  
     BDTCuts[7] =  0.155;  
     BDTCuts[8] =  0.215 ;
     BDTCuts[9] =  0.215;
     BDTCuts[10] = 0.245;  
     BDTCuts[11] = 0.155;  
     BDTCuts[12] = 0.155;  
     BDTCuts[13] = 0.125;  
     BDTCuts[14] = 0.195  ;
     BDTCuts[15] = 0.175;  
     BDTCuts[16] = 0.125  ;
     BDTCuts[17] = 0.095;
 }
 if(CRregion == string("CR4_3j")){
     BDTCuts[0] =  0.285;
     BDTCuts[1] =  0.335 ;
     BDTCuts[2] =  0.185 ;
     BDTCuts[3] =  0.185;
     BDTCuts[4] =  0.195;
     BDTCuts[5] =  0.245;
     BDTCuts[6] =  0.245;  
     BDTCuts[7] =  0.145;  
     BDTCuts[8] =  0.185 ;
     BDTCuts[9] =  0.185;
     BDTCuts[10] = 0.205;  
     BDTCuts[11] = 0.145;  
     BDTCuts[12] = 0.135;  
     BDTCuts[13] = 0.105;  
     BDTCuts[14] = 0.175  ;
     BDTCuts[15] = 0.155;  
     BDTCuts[16] = 0.115  ;
     BDTCuts[17] = 0.095;
 }
 if(CRregion == string("CR4_4j")){
     BDTCuts[0] =  0.265;
     BDTCuts[1] =  0.285 ;
     BDTCuts[2] =  0.135 ;
     BDTCuts[3] =  0.135;
     BDTCuts[4] =  0.155;
     BDTCuts[5] =  0.205;
     BDTCuts[6] =  0.205;  
     BDTCuts[7] =  0.115;  
     BDTCuts[8] =  0.165 ;
     BDTCuts[9] =  0.165;
     BDTCuts[10] = 0.105;  
     BDTCuts[11] = 0.095;  
     BDTCuts[12] = 0.095;  
     BDTCuts[13] = 0.075;  
     BDTCuts[14] = 0.155  ;
     BDTCuts[15] = 0.125;  
     BDTCuts[16] = 0.085  ;
     BDTCuts[17] = 0.075;
 }
 if(CRregion == string("CR4_4j_50evts")){
     BDTCuts[0] =  0.255;
     BDTCuts[1] =  0.255 ;
     BDTCuts[2] =  0.105 ;
     BDTCuts[3] =  0.105;
     BDTCuts[4] =  0.135;
     BDTCuts[5] =  0.175;
     BDTCuts[6] =  0.165;  
     BDTCuts[7] =  0.095;  
     BDTCuts[8] =  0.135 ;
     BDTCuts[9] =  0.135;
     BDTCuts[10] = 0.135;  
     BDTCuts[11] = 0.085;  
     BDTCuts[12] = 0.075;  
     BDTCuts[13] = 0.055;  
     BDTCuts[14] = 0.125  ;
     BDTCuts[15] = 0.095;  
     BDTCuts[16] = 0.065  ;
     BDTCuts[17] = 0.045;
 }
 if(CRregion == string("CR4_4j_100evts")){
     BDTCuts[0] =  0.165;
     BDTCuts[1] =  0.205 ;
     BDTCuts[2] =  0.065 ;
     BDTCuts[3] =  0.065;
     BDTCuts[4] =  0.105;
     BDTCuts[5] =  0.135;
     BDTCuts[6] =  0.115;  
     BDTCuts[7] =  0.055;  
     BDTCuts[8] =  0.105 ;
     BDTCuts[9] =  0.105;
     BDTCuts[10] = 0.095;  
     BDTCuts[11] = 0.055;  
     BDTCuts[12] = 0.035;  
     BDTCuts[13] = 0.015;  
     BDTCuts[14] = 0.085  ;
     BDTCuts[15] = 0.065;  
     BDTCuts[16] = 0.035  ;
     BDTCuts[17] = 0.015;
 }
 if(CRregion == string("CR4_4j_150evts")){
     BDTCuts[0] =  0.135;
     BDTCuts[1] =  0.165 ;
     BDTCuts[2] =  0.035 ;
     BDTCuts[3] =  0.035;
     BDTCuts[4] =  0.085;
     BDTCuts[5] =  0.115;
     BDTCuts[6] =  0.085;  
     BDTCuts[7] =  0.025;  
     BDTCuts[8] =  0.085 ;
     BDTCuts[9] =  0.085;
     BDTCuts[10] = 0.065;  
     BDTCuts[11] = 0.035;  
     BDTCuts[12] = 0.015;  
     BDTCuts[13] = -0.005; 
     BDTCuts[14] = 0.065  ;
     BDTCuts[15] = 0.035;  
     BDTCuts[16] = 0.015  ;
     BDTCuts[17] = -0.015;
 }
 if(CRregion == string("CR4_4j_IndepInterv")){
    int ibin = CR4_4j_Bin;
    if(BDTCutIndepSR_NextBin) ibin--;

     BDTCuts[0] =  BDTCutIndepSR[0][ibin];
     BDTCuts[1] =  BDTCutIndepSR[1][ibin];
     BDTCuts[2] =  BDTCutIndepSR[2][ibin];
     BDTCuts[3] =  BDTCutIndepSR[2][ibin];
     BDTCuts[4] =  BDTCutIndepSR[3][ibin];
     BDTCuts[5] =  BDTCutIndepSR[4][ibin];
     BDTCuts[6] =  BDTCutIndepSR[5][ibin];
     BDTCuts[7] =  BDTCutIndepSR[6][ibin];
     BDTCuts[8] =  BDTCutIndepSR[7][ibin];
     BDTCuts[9] =  BDTCutIndepSR[7][ibin];
     BDTCuts[10] = BDTCutIndepSR[8][ibin];
     BDTCuts[11] = BDTCutIndepSR[9][ibin];
     BDTCuts[12] = BDTCutIndepSR[10][ibin];
     BDTCuts[13] = BDTCutIndepSR[11][ibin];
     BDTCuts[14] = BDTCutIndepSR[12][ibin];
     BDTCuts[15] = BDTCutIndepSR[13][ibin];
     BDTCuts[16] = BDTCutIndepSR[14][ibin];
     BDTCuts[17] = BDTCutIndepSR[15][ibin];
 }
}
 #endif
