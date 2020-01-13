export X509_USER_PROXY=~/myproxy
fggRunJobs.py --load dy_2018.json -d DYMC2018_7Jan2020 --stage-to /eos/user/d/davies/Hgg/Validation/ggHMulticlassifier/ -x cmsRun legacy_dumper.py maxEvents=-1 -q testmatch pujidWP=tight dumpJetSysTrees=True -n 200 --no-copy-proxy runOnZee=True
