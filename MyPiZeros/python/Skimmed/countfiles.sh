count=0
#f_name="0_2_GeV_set5"
f_name="MA_1p6GeV/Set1"
for file in $(xrdfs se01.indiacms.res.in:1094 ls -R /store/user/sosaha/test/Official_HtoAA_samples/$f_name); do
  count=$((count + 1))
done
echo "Total number of files: $count"

