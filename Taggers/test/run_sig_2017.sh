export X509_USER_PROXY=~/myproxy
fggRunJobs.py --load sig_2017.json -d Sig2017_26Nov19 --stage-to /eos/user/d/davies/Hgg/jetStudiesGGH/2017/  -x cmsRun legacy_dumper.py maxEvents=-1 runOnZee=False -q testmatch pujidWP=tight dumpJetSysTrees=False useParentDataset=True -n 200 --no-copy-proxy
