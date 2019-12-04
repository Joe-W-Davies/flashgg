export X509_USER_PROXY=~/myproxy
fggRunJobs.py --load data_2017.json -d Data2017_2Dec19 --stage-to /eos/user/d/davies/Hgg/jetStudiesGGH/2017/Data/ -x cmsRun legacy_dumper.py maxEvents=-1 runOnZee=False -q testmatch pujidWP=tight dumpJetSysTrees=False -n 200 --no-copy-proxy
