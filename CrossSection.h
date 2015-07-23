#ifndef CrossSection_h
#define CrossSection_h


float CrossSection(const string& dataset){
	if(dataset == "T2tt_425_325") return 1.31169;
	if(dataset == "T2tt_500_325") return 0.51848;
	if(dataset == "T2tt_650_100") return 0.107045;
	if(dataset == "T2tt_650_325") return 0.107045;
	if(dataset == "T2tt_850_100") return 0.01896;
	if(dataset == "singleTopbar_s") return 4.16;
	if(dataset == "singleTopbar_t") return 80.95;
	if(dataset == "singleTop_s") return 7.20;
	if(dataset == "singleTop_t") return 136.02;
	if(dataset == "ttbar-madgraph") return 831.76;
	if(dataset == "ttW") return 0.70;
	if(dataset == "ttZ") return 0.62;
	if(dataset == "Wjets") return 61466;
	if(dataset == "WZ") return 48.4;
	if(dataset == "ZZ") return 15.4;

}

#endif
