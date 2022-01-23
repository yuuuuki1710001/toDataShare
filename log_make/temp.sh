#/bin/bash

var8=8
var4=4
var2=2
var=0
file=""
cd ~/.ros/log
ls -1F | grep / | grep -v rqt_gui_py_node |cut -d '/' -f 1 > temp.txt

while read line
do
	cd ~/.ros/log/$line
	cat rosout.log | grep listener | cut -d '[' -f 4 | cut -d ']' -f 1 > start_$line.csv
	cat rosout.log | grep listener | cut -d '[' -f 5 | cut -d ']' -f 1 > now_$line.csv
	cat rosout-1-stdout.log | grep called | cut -d ':' -f 3 > callback_$line.csv
	paste -d , now_$line.csv start_$line.csv callback_$line.csv > log_$line.csv
	
	var=`ls -1 | grep talker | wc -l`
	if [ $var -eq $var8 ]; then
		cd ~/.ros/
		./line8 ./log/$line/log_$line.csv
		mv eight_log.csv eight_log_$line.csv
		sudo mv eight_log_$line.csv ~/../../nfs
		cd ./log/$line	
	elif [ $var -eq $var4 ]; then
		cd ~/.ros/
		./line4 ./log/$line/log_$line.csv
		mv four_log.csv four_log_$line.csv
		sudo mv four_log_$line.csv ~/../../nfs
		cd ./log/$line
	elif [ $var -eq $var2 ]; then
		cd ~/.ros/
		./line2 ./log/$line/log_$line.csv
		mv two_log.csv two_log_$line.csv
		sudo mv two_log_$line.csv ~/../../nfs
		cd ./log/$line
	else
		cd ~/.ros/log/$line
		mv log_$line.csv one_log_$line.csv
		sudo mv one_log_$line.csv ~/../../nfs
	fi
	var=0
done < temp.txt
