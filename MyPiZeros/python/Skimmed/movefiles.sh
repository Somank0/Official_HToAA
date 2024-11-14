#!/bin/bash

# Define the folder name as a variable
f_name="MA_0p6GeV/File1"
# Define the XRootD server and storage path
xrootd_server="root://se01.indiacms.res.in"
storage_path="//store/user/sosaha/test/Official_HtoAA_samples/$f_name"

# Create the folder in the XRootD storage area
xrdfs $xrootd_server mkdir $storage_path

# Loop through the files in the local folder and copy them to the newly created folder in XRootD
for file in $(find $f_name -type f); do
    # Extract the file name from the full path
    file_name=$(basename $file)
    
    # Copy the file to the newly created folder in XRootD storage
    xrdcp $file $xrootd_server/$storage_path/$file_name
done

