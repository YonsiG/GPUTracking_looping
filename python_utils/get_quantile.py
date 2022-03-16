import ROOT
import array

file = ROOT.TFile("../outfiles/PU200_500_selected.root")

xq = array.array('d',[0.9,0.99,0.9999,1])
yq = array.array('d',[0,0,0,0])

plot1 = file.Get("md_occupancies_module")
plot1.SetBinContent(1,0)
plot1.GetQuantiles(4,yq,xq)
print "md: ", yq

plot2 = file.Get("sg_occupancies_module")
plot2.SetBinContent(1,0)
plot2.GetQuantiles(4,yq,xq)
print "sg: ", yq

plot3 = file.Get("t3_occupancies_module")
plot3.SetBinContent(1,0)
plot3.GetQuantiles(4,yq,xq)
print "t3: ", yq

plot4 = file.Get("t5_occupancies_module")
plot4.SetBinContent(1,0)
plot4.GetQuantiles(4,yq,xq)
print "t5: ", yq
