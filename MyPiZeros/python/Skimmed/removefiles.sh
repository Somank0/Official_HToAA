f_name="MA_1p6GeV/Set1"
for file in $(xrdfs root://se01.indiacms.res.in ls /store/user/sosaha/test/Official_HtoAA_samples/$f_name); do
    xrdfs root://se01.indiacms.res.in rm $file
done

