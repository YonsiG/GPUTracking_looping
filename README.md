Author: GUYANXI
Date: 03-15-2022

This programs requires a readout in the previous GPU step, which is the input rootfile. The environment setting would be using the uaf-10.t2.ucsd.edu server. To set the environment, simply run 

>> source command.txt
>> mkdir plots
>> mkdir outfiles

To compile, 

>> . gcc.sh

To run, go to source_code/ and run the ZZZAna.exe

>> cd source_code/
>> ./ZZZAna.exe filelist/filename.txt data

To make plots, go to plot_program/

>> cd plot_program/
>> . gcc_plots.sh
>> ./plots.exe

To get quantiles, go to python_utils/
>> cd python_utils/
>> python get_quantile.py