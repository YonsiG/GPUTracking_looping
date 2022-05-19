import ROOT
import array

file = ROOT.TFile("../outfiles/PU200_selected.root")

xq = array.array('d',[0.9,0.99,0.9999,1])
yq = array.array('d',[0,0,0,0])

plot1 = file.Get("t3_occupancies_module_by_eta0_0")
plot1.SetBinContent(1,0)
plot1.GetQuantiles(4,yq,xq)
print "0_0: ", yq

plot2 = file.Get("t3_occupancies_module_by_eta0_1")
plot2.SetBinContent(1,0)
plot2.GetQuantiles(4,yq,xq)
print "0_1: ", yq

plot3 = file.Get("t3_occupancies_module_by_eta0_2")
plot3.SetBinContent(1,0)
plot3.GetQuantiles(4,yq,xq)
print "0_2: ", yq

plot4 = file.Get("t3_occupancies_module_by_eta0_3")
plot4.SetBinContent(1,0)
plot4.GetQuantiles(4,yq,xq)
print "0_3: ", yq

plot5 = file.Get("t3_occupancies_module_by_eta1_0")
plot5.SetBinContent(1,0)
plot5.GetQuantiles(4,yq,xq)
print "1_0: ", yq

plot6 = file.Get("t3_occupancies_module_by_eta1_1")
plot6.SetBinContent(1,0)
plot6.GetQuantiles(4,yq,xq)
print "1_1: ", yq

plot7 = file.Get("t3_occupancies_module_by_eta2_1")
plot7.SetBinContent(1,0)
plot7.GetQuantiles(4,yq,xq)
print "2_1: ", yq

plot8 = file.Get("t3_occupancies_module_by_eta2_2")
plot8.SetBinContent(1,0)
plot8.GetQuantiles(4,yq,xq)
print "2_2: ", yq

plot9 = file.Get("t3_occupancies_module_by_eta3_1")
plot9.SetBinContent(1,0)
plot9.GetQuantiles(4,yq,xq)
print "3_1: ", yq

plot10 = file.Get("t3_occupancies_module_by_eta3_2")
plot10.SetBinContent(1,0)
plot10.GetQuantiles(4,yq,xq)
print "3_2: ", yq

plot11 = file.Get("t3_occupancies_module_by_eta3_3")
plot11.SetBinContent(1,0)
plot11.GetQuantiles(4,yq,xq)
print "3_3: ", yq

plot12 = file.Get("t3_occupancies_module_by_eta4_0")
plot12.SetBinContent(1,0)
plot12.GetQuantiles(4,yq,xq)
print "4_0: ", yq

plot13 = file.Get("t3_occupancies_module_by_eta4_1")
plot13.SetBinContent(1,0)
plot13.GetQuantiles(4,yq,xq)
print "4_1: ", yq

plot14 = file.Get("t3_occupancies_module_by_eta5_0")
plot14.SetBinContent(1,0)
plot14.GetQuantiles(4,yq,xq)
print "5_0: ", yq

plot15 = file.Get("t3_occupancies_module_by_eta5_1")
plot15.SetBinContent(1,0)
plot15.GetQuantiles(4,yq,xq)
print "5_1: ", yq

plot16 = file.Get("t3_occupancies_module_by_eta6_0")
plot16.SetBinContent(1,0)
plot16.GetQuantiles(4,yq,xq)
print "6_0: ", yq

plot17 = file.Get("t3_occupancies_module_by_eta6_1")
plot17.SetBinContent(1,0)
plot17.GetQuantiles(4,yq,xq)
print "6_1: ", yq
