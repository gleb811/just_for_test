void sim_mom_corr2() {

gStyle->SetOptStat(0);

TFile *MyFile = new TFile("sim_proton_mom_corr.root","READ");
TF1 *myfit = new TF1("myfit","gaus", -0.035, 0.035);
TF1 *myfit_pol2 = new TF1("myfit_pol2","pol5", 0.195, 2.0);
TF1 *myfit_pol2_th = new TF1("myfit_pol2_th","pol2", 12., 120.);

TH1F *h_p0 = new TH1F("P0","P0",18,12.,120.);
TH1F *h_p1 = new TH1F("P1","P1",18,12.,120.);
TH1F *h_p2 = new TH1F("P2","P2",18,12.,120.);
TH1F *h_p3 = new TH1F("P3","P3",18,12.,120.);
TH1F *h_p4 = new TH1F("P4","P4",18,12.,120.);
TH1F *h_p5 = new TH1F("P5","P5",18,12.,120.);

const Int_t npar = 18;
   Double_t eloss2d_params[npar];
   TF2* f_eloss2d = new TF2("f_eloss2d",&eloss2d,0.,120.,0.25,1.9, npar);
   TH2F *h_eloss2d = new TH2F("h_elos2d","h_elos2d",40,0.,120.,40,0.25,1.9);
   
//TCanvas *c_corr2d = new TCanvas("c_corr2d","c_corr2d",0,0,600,600);
TCanvas *c_delta = new TCanvas("c_delta","c_delta",0,0,600,600);

//TCanvas *c_param = new TCanvas("parameters","parameters",0,0,1200,200);
//c_param->Divide(6,1);

TH1 *h[20][20];
ostringstream qqq;
TCanvas *c[20];
TH1 *h_p[20];


for (Int_t i=2; i<=19; i++){

qqq.str("");
qqq << "c_" << i;


qqq.str("");
qqq << "th_" << i;

h_p[i] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),17,0.1475,1.7625);

for (Int_t j=1; j<=19; j++){


//c[i]->cd(j+1);



qqq.str("");
qqq << "Pdiff_" << j << "_" << i;

MyFile->GetObject(qqq.str().c_str(),h[i][j]);

qqq.str("");

h[i][j]->Rebin(4);
//h[i][j]->Draw();
h[i][j]->Fit("myfit","Q");
//TF1 *fit = hist->GetFunction();

h_p[i]->Fill((0.1 + 0.095*j),-1.*(myfit->GetParameter(1)));

};

};


Int_t z = 10;
c_delta->cd();
c_delta->cd()->SetLeftMargin(0.15);
h_p[z]->SetTitle("#theta = 63 deg");
h_p[z]->GetXaxis()->SetTitle("P_{p} (GeV)");
h_p[z]->GetYaxis()->SetTitle("#DeltaP_{p} (GeV)");
h_p[z]->GetYaxis()->SetTitleOffset(1.9);
h_p[z]->Draw();



};




Double_t eloss2d(Double_t *x, Double_t *par) {
   for (Int_t i=0; i<18; i++) {
  // cout << "par[" << i << "] = " << par[i] << ";\n";
   };
   Double_t p0 = par[0] + x[0]*par[1] + x[0]*x[0]*par[2];
   Double_t p1 = par[3] + x[0]*par[4] + x[0]*x[0]*par[5];
   Double_t p2 = par[6] + x[0]*par[7] + x[0]*x[0]*par[8];
   Double_t p3 = par[9] + x[0]*par[10] + x[0]*x[0]*par[11];   
   Double_t p4 = par[12] + x[0]*par[13] + x[0]*x[0]*par[14];  
   Double_t p5 = par[15] + x[0]*par[16] + x[0]*x[0]*par[17]; 
   
   return -1.*(p0+p1*x[1]+p2*x[1]*x[1]+p3*x[1]*x[1]*x[1]+p4*x[1]*x[1]*x[1]*x[1]+p5*x[1]*x[1]*x[1]*x[1]*x[1])/x[1]*100.;
   }
