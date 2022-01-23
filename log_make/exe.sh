#/bin/sh

#for i in {0..4}; do
	#timeout 5m roslaunch beginner_tutorials one_simp.launch >> one_simp_log$i.txt
	timeout 5m roslaunch beginner_tutorials one_img.launch >> one_img_log2.txt
	#timeout 5m roslaunch beginner_tutorials two_simp.launch >> two_simp_log$i.txt
	timeout 5m roslaunch beginner_tutorials two_img.launch >> two_img_log2.txt
	#timeout 5m roslaunch beginner_tutorials four_simp.launch >> four_simp_log$i.txt
	timeout 5m roslaunch beginner_tutorials four_img.launch >> four_img_log2.txt
	#timeout 5m roslaunch beginner_tutorials eight_simp.launch >> eight_simp_log$i.txt
	timeout 5m roslaunch beginner_tutorials eight_img.launch >> eight_img_log2.txt
#done
