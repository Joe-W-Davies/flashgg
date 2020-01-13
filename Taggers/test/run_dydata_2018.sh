export X509_USER_PROXY=~/myproxy
fggRunJobs.py --load data_2018.json -d DYdata2018_7Jan2020 --stage-to /eos/user/d/davies/Hgg/Validation/ggHMulticlassifier/ -x cmsRun legacy_dumper.py maxEvents=-1 -q testmatch pujidWP=tight dumpJetSysTrees=False -n 200 --no-copy-proxy runOnZee=True
