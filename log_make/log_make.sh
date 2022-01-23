#/bin/bash
#code1
for i in {0..4}; do
    cat one_img_log1$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> one_img_start1$i.txt
    cat one_img_log1$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> one_img_now1$i.txt

    cat one_img_log$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> one_img_start$i.txt
    cat one_img_log$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> one_img_now$i.txt

    cat one_img_log3$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> one_img_start3$i.txt
    cat one_img_log3$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> one_img_now3$i.txt

    cat one_img_log4$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> one_img_start4$i.txt
    cat one_img_log4$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> one_img_now4$i.txt

    #cat one_simp_log$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> one_simp_start$i.txt
    #cat one_simp_log$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> one_simp_now$i.txt

    cat two_img_log1$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> two_img_start1$i.txt
    cat two_img_log1$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> two_img_now1$i.txt

    cat two_img_log$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> two_img_start$i.txt
    cat two_img_log$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> two_img_now$i.txt

    cat two_img_log3$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> two_img_start3$i.txt
    cat two_img_log3$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> two_img_now3$i.txt

    cat two_img_log4$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> two_img_start4$i.txt
    cat two_img_log4$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> two_img_now4$i.txt

    #cat two_simp_log$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> two_simp_start$i.txt
    #cat two_simp_log$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> two_simp_now$i.txt

    cat four_img_log$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> four_img_start$i.txt
    cat four_img_log$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> four_img_now$i.txt

    cat four_img_log1$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> four_img_start1$i.txt
    cat four_img_log1$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> four_img_now1$i.txt

    cat four_img_log3$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> four_img_start3$i.txt
    cat four_img_log3$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> four_img_now3$i.txt

    cat four_img_log4$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> four_img_start4$i.txt
    cat four_img_log4$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> four_img_now4$i.txt

    #cat four_simp_log$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> four_simp_start$i.txt
    #cat four_simp_log$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> four_simp_now$i.txt

    cat eight_img_log$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> eight_img_start$i.txt
    cat eight_img_log$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> eight_img_now$i.txt

    cat eight_img_log1$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> eight_img_start1$i.txt
    cat eight_img_log1$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> eight_img_now1$i.txt

    cat eight_img_log3$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> eight_img_start3$i.txt
    cat eight_img_log3$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> eight_img_now3$i.txt

    cat eight_img_log4$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> eight_img_start4$i.txt
    cat eight_img_log4$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> eight_img_now4$i.txt

    #cat eight_simp_log$i.txt | grep INFO | cut -d '[' -f 5 | cut -d ']' -f 1 >> eight_simp_start$i.txt
    #cat eight_simp_log$i.txt | grep INFO | cut -d '[' -f 6 | cut -d ']' -f 1 >> eight_simp_now$i.txt


    cat one_img_log$i.txt | grep called | cut -d ':' -f 3 >> one_img_callback$i.txt
    cat two_img_log$i.txt | grep called | cut -d ':' -f 3 >> two_img_callback$i.txt
    cat four_img_log$i.txt | grep called | cut -d ':' -f 3 >> four_img_callback$i.txt
    cat eight_img_log$i.txt | grep called | cut -d ':' -f 3 >> eight_img_callback$i.txt

    cat one_img_log1$i.txt | grep called | cut -d ':' -f 3 >> one_img_callback1$i.txt
    cat two_img_log1$i.txt | grep called | cut -d ':' -f 3 >> two_img_callback1$i.txt
    cat four_img_log1$i.txt | grep called | cut -d ':' -f 3 >> four_img_callback1$i.txt
    cat eight_img_log1$i.txt | grep called | cut -d ':' -f 3 >> eight_img_callback1$i.txt

    cat one_img_log3$i.txt | grep called | cut -d ':' -f 3 >> one_img_callback3$i.txt
    cat two_img_log3$i.txt | grep called | cut -d ':' -f 3 >> two_img_callback3$i.txt
    cat four_img_log3$i.txt | grep called | cut -d ':' -f 3 >> four_img_callback3$i.txt
    cat eight_img_log3$i.txt | grep called | cut -d ':' -f 3 >> eight_img_callback3$i.txt

    cat one_img_log4$i.txt | grep called | cut -d ':' -f 3 >> one_img_callback4$i.txt
    cat two_img_log4$i.txt | grep called | cut -d ':' -f 3 >> two_img_callback4$i.txt
    cat four_img_log4$i.txt | grep called | cut -d ':' -f 3 >> four_img_callback4$i.txt
    cat eight_img_log4$i.txt | grep called | cut -d ':' -f 3 >> eight_img_callback4$i.txt

    #cat one_simp_log$i.txt | grep called | cut -d ':' -f 3 >> one_simp_callback$i.txt
    #cat two_simp_log$i.txt | grep called | cut -d ':' -f 3 >> two_simp_callback$i.txt
    #cat four_simp_log$i.txt | grep called | cut -d ':' -f 3 >> four_simp_callback$i.txt
    #cat eight_simp_log$i.txt | grep called | cut -d ':' -f 3 >> eight_simp_callback$i.txt
done
