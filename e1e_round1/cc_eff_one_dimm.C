void cc_eff_one_dimm() {

TCanvas *c = new TCanvas("c", "c", 1000, 500);
c->Divide(6,3);

gStyle->SetOptStat(0);

gStyle->SetTitleSize(0.5,"t"); 
gStyle->SetTitleX(0.5); //title X location 
gStyle->SetTitleY(1.0); //title Y location 
gStyle->SetTitleW(0.7); //title width 
gStyle->SetTitleH(0.1); //title height 

ostringstream qqq;

TGaxis::SetMaxDigits(3);
//Int_t TGaxis::fgMaxDigits = 3;

TFile *MyFile = new TFile("new_ratio.root","READ");

TH2F *h;
h = (TH2F*)MyFile->Get("h301");
TH1 *h1;

TLine *line = new TLine(-25.,0.8,25.,0.8);
line->SetLineColor(2);
line->SetLineWidth(2);

for (Int_t i=80; i<98; i++)
{

c->cd(i-79);
c->cd(i-79);
c->cd(i-79)->SetTopMargin(0.1);
c->cd(i-79)->SetBottomMargin(0.2);
c->cd(i-79)->SetLeftMargin(0.2);
c->cd(i-79)->SetRightMargin(0.02);

qqq.str("");
qqq << "h_" << i; 

h1 = (TH1*)h301->ProjectionY(qqq.str().c_str(),i,i);
h1->Rebin(2);
h1->Scale(1./2.);

qqq.str("");
qqq << -5. + (i - 1)*60./200. << " < #theta_{cc} < " <<  -5. + i*60./200. << " deg";
h1->SetTitle(qqq.str().c_str());
h1->SetTitleSize(2.);
h1->GetYaxis()->SetTitle("ratio given by eq. 2.1.8");
h1->GetYaxis()->SetTitleSize(0.07);
h1->GetYaxis()->SetTitleOffset(1.35);

h1->GetXaxis()->SetTitle("#varphi_{cc} (deg)");
h1->GetXaxis()->SetTitleSize(0.09);
h1->GetXaxis()->SetTitleOffset(0.9);
h1->SetLabelSize(0.07,"x");
h1->SetLabelSize(0.07,"y");
h1->GetXaxis()->SetNdivisions(505);


h1->Draw();
line->Draw();

};

c->Print("cc_eff_one_dimm.pdf");

/*
before = (TH2F*)MyFile->Get("eout_vs_ein_before");

after = (TH2F*)MyFile->Get("eout_vs_ein_after");

before->SetTitle("");
before->GetYaxis()->SetTitle("E_{out} (GeV)");
before->GetYaxis()->SetTitleSize(0.05);
before->GetYaxis()->SetTitleOffset(1.35);

before->GetXaxis()->SetTitle("E_{in} (GeV)");
before->GetXaxis()->SetTitleSize(0.05);
before->GetXaxis()->SetTitleOffset(0.9);

c->cd(1);
c->cd(1)->SetTopMargin(0.05);
c->cd(1)->SetLeftMargin(0.15);
c->cd(1)->SetRightMargin(0.12);
before->Draw("colz");



after->SetTitle("");
after->GetYaxis()->SetTitle("E_{out} (GeV)");
after->GetYaxis()->SetTitleSize(0.05);
after->GetYaxis()->SetTitleOffset(1.35);

after->GetXaxis()->SetTitle("E_{in} (GeV)");
after->GetXaxis()->SetTitleSize(0.05);
after->GetXaxis()->SetTitleOffset(0.9);

c->cd(2);
c->cd(2)->SetTopMargin(0.05);
c->cd(2)->SetLeftMargin(0.15);
c->cd(2)->SetRightMargin(0.12);
after->Draw("colz");

c->Print("eout_vs_ein.pdf");
*/
}
