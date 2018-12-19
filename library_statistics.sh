#!/bin/bash
g++ -std=c++11 main.cpp

case "$1" in
	resource)
		case "$2" in
			book)
				mkdir ./result
				mkdir ./result/resource
				grep ^Book resource.dat > ./result/resource/book.dat
			;;
			e-book)
				mkdir ./result
				mkdir ./result/resource
				grep ^E-book resource.dat > ./result/resource/e-book.dat			
			;;
			magazine)
				mkdir ./result
				mkdir ./result/resource
				grep ^Magazine resource.dat > ./result/resource/magazine.dat
			;;
			all)
				mkdir ./result
				mkdir ./result/resource
				grep ^Book resource.dat > ./result/resource/book.dat
				grep ^E-book resource.dat > ./result/resource/e-book.dat
				grep ^Magazine resource.dat > ./result/resource/magazine.dat
			;;
		esac;;
	input)
		case "$2" in
			date)
			;;
			book)
				#make directory
				mkdir ./result
				mkdir ./result/input
				#make temp file
				cp input.dat input_temp.dat
				head -n 1 input_temp.dat > input.dat
				grep Book input_temp.dat >> input.dat
				mv space.dat space_temp.dat
				#execute
				./a.out > ./result/input/book.dat
				#restore file
				rm input.dat
				mv input_temp.dat input.dat
				mv space_temp.dat space.dat
			;;
			e-book)
				#make directory
				mkdir ./result
				mkdir ./result/input
				#make temp file
				cp input.dat input_temp.dat
				head -n 1 input_temp.dat > input.dat
				grep E-book input_temp.dat >> input.dat
				mv space.dat space_temp.dat
				#execute
				./a.out > ./result/input/e-book.dat
				#restore file
				rm input.dat
				mv input_temp.dat input.dat
				mv space_temp.dat space.dat
			;;
			magazine)
				#make directory
				mkdir ./result
				mkdir ./result/input
				#make temp file
				cp input.dat input_temp.dat
				head -n 1 input_temp.dat > input.dat
				grep Magazine input_temp.dat >> input.dat
				mv space.dat space_temp.dat
				#execute
				./a.out > ./result/input/magazine.dat
				#restore file
				rm input.dat
				mv input_temp.dat input.dat
				mv space_temp.dat space.dat
			;;
			undergraduate)
				#make directory
				mkdir ./result
				mkdir ./result/input
				#make temp file
				cp input.dat input_temp.dat
				head -n 1 input_temp.dat > input.dat
				grep Undergraduate input_temp.dat >> input.dat
				mv space.dat space_temp.dat
				#execute
				./a.out > ./result/input/undergraduate.dat
				#restore file
				rm input.dat
				mv input_temp.dat input.dat
				mv space_temp.dat space.dat
			;;
			graduate)
				#make directory
				mkdir ./result
				mkdir ./result/input
				#make temp file
				cp input.dat input_temp.dat
				head -n 1 input_temp.dat > input.dat
				grep Graduate input_temp.dat >> input.dat
				mv space.dat space_temp.dat
				#execute
				./a.out > ./result/input/graduate.dat
				#restore file
				rm input.dat
				mv input_temp.dat input.dat
				mv space_temp.dat space.dat
			;;
			faculty)
				#make directory
				mkdir ./result
				mkdir ./result/input
				#make temp file
				cp input.dat input_temp.dat
				head -n 1 input_temp.dat > input.dat
				grep Faculty input_temp.dat >> input.dat
				mv space.dat space_temp.dat
				#execute
				./a.out > ./result/input/faculty.dat
				#restore file
				rm input.dat
				mv input_temp.dat input.dat
				mv space_temp.dat space.dat
			;;
			all)
				#make directory
				mkdir ./result
				mkdir ./result/input
				#make temp file
				cp input.dat input_temp.dat
				#hide space.dat
				mv space.dat space_temp.dat
				#book
				head -n 1 input_temp.dat > input.dat
				grep Book input_temp.dat >> input.dat
				./a.out > ./result/input/book.dat
				#e-book
				head -n 1 input_temp.dat > input.dat
				grep E-book input_temp.dat >> input.dat
				./a.out > ./result/input/e-book.dat
				#magazine
				head -n 1 input_temp.dat > input.dat
				grep Magazine input_temp.dat >> input.dat
				./a.out > ./result/input/magazine.dat
				#undergraduate
				head -n 1 input_temp.dat > input.dat
				grep Undergraduate input_temp.dat >> input.dat
				./a.out > ./result/input/undergraduate.dat
				#graduate
				head -n 1 input_temp.dat > input.dat
				grep Graduate input_temp.dat >> input.dat
				./a.out > ./result/input/graduate.dat
				#faculty
				head -n 1 input_temp.dat > input.dat
				grep Faculty input_temp.dat >> input.dat
				./a.out > ./result/input/faculty.dat
				#restore file
				rm input.dat
				mv input_temp.dat input.dat
				mv space_temp.dat space.dat
			;;
		esac;;
	space)
		case "$2" in
			date)
			#cut 이용
			;;
			studyroom)
				#make directory
				mkdir ./result
				mkdir ./result/space
				#make temp file
				cp space.dat space_temp.dat
				head -n 1 space_temp.dat > space.dat
				case "$3" in
					1)
						grep "StudyRoom	1" space_temp.dat >> space.dat
					;;
					2)
						grep "StudyRoom	2" space_temp.dat >> space.dat
					;;
					3)
						grep "StudyRoom	3" space_temp.dat >> space.dat
					;;
					4)
						grep "StudyRoom	4" space_temp.dat >> space.dat
					;;
					5)
						grep "StudyRoom	5" space_temp.dat >> space.dat
					;;
					6)
						grep "StudyRoom	6" space_temp.dat >> space.dat
					;;
					7)
						grep "StudyRoom	7" space_temp.dat >> space.dat
					;;
					8)
						grep "StudyRoom	8" space_temp.dat >> space.dat
					;;
					9)
						grep "StudyRoom	9" space_temp.dat >> space.dat
					;;
					10)
						grep "StudyRoom	10" space_temp.dat >> space.dat
					;;
					all)
						grep StudyRoom space_temp.dat >> space.dat
					;;
				esac
				mv input.dat input_temp.dat
				#execute
				./a.out > ./result/space/studyroom.dat
				#restore file
				rm space.dat
				mv space_temp.dat space.dat
				mv input_temp.dat input.dat
			;;
			seat)
				#make directory
				mkdir ./result
				mkdir ./result/space
				#make temp file
				cp space.dat space_temp.dat
				head -n 1 space_temp.dat > space.dat
				case "$3" in
					1)
						grep "Seat	1" space_temp.dat >> space.dat
					;;
					2)
						grep "Seat	2" space_temp.dat >> space.dat
					;;
					3)
						grep "Seat	3" space_temp.dat >> space.dat
					;;
					all)
						grep Seat space_temp.dat >> space.dat
					;;
				esac
				mv input.dat input_temp.dat
				#execute
				./a.out > ./result/space/seat.dat
				#restore file
				rm space.dat
				mv space_temp.dat space.dat
				mv input_temp.dat input.dat
			;;
			undergraduate)
				#make directory
				mkdir ./result
				mkdir ./result/space
				#make temp file
				cp space.dat space_temp.dat
				head -n 1 space_temp.dat > space.dat
				grep Undergraduate space_temp.dat >> space.dat
				mv input.dat input_temp.dat
				#execute
				./a.out > ./result/space/undergraduate.dat
				#restore file
				rm space.dat
				mv space_temp.dat space.dat
				mv input_temp.dat input.dat
			;;
			graduate)
				#make directory
				mkdir ./result
				mkdir ./result/space
				#make temp file
				cp space.dat space_temp.dat
				head -n 1 space_temp.dat > space.dat
				grep Graduate space_temp.dat >> space.dat
				mv input.dat input_temp.dat
				#execute
				./a.out > ./result/space/graduate.dat
				#restore file
				rm space.dat
				mv space_temp.dat space.dat
				mv input_temp.dat input.dat
			;;
			faculty)
				#make directory
				mkdir ./result
				mkdir ./result/space
				#make temp file
				cp space.dat space_temp.dat
				head -n 1 space_temp.dat > space.dat
				grep Faculty space_temp.dat >> space.dat
				mv input.dat input_temp.dat
				#execute
				./a.out > ./result/space/faculty.dat
				#restore file
				rm space.dat
				mv space_temp.dat space.dat
				mv input_temp.dat input.dat
			;;
			all)
				#make directory
				mkdir ./result
				mkdir ./result/space
				#make temp file
				cp space.dat space_temp.dat
				mv input.dat input_temp.dat
				#studyroom
				head -n 1 space_temp.dat > space.dat
				grep StudyRoom space_temp.dat >> space.dat
				./a.out > ./result/space/studyroom.dat
				#seat
				head -n 1 space_temp.dat > space.dat
				grep Seat space_temp.dat >> space.dat
				./a.out > ./result/space/seat.dat
				#undergraduate
				head -n 1 space_temp.dat > space.dat
				grep Undergraduate space_temp.dat >> space.dat
				./a.out > ./result/space/undergraduate.dat
				#graduate
				head -n 1 space_temp.dat > space.dat
				grep Graduate space_temp.dat >> space.dat
				./a.out > ./result/space/graduate.dat
				#faculty
				head -n 1 space_temp.dat > space.dat
				grep Faculty space_temp.dat >> space.dat
				./a.out > ./result/space/faculty.dat
				#restore file
				rm space.dat
				mv space_temp.dat space.dat
				mv input_temp.dat input.dat
			;;
		esac;;
	output)
		case "$2" in
			stat_table)
				#make directory
				mkdir -p ./result
				mkdir -p ./result/output
				./a.out | awk '{ print $2 }' > output1.dat
				grep -c -1 output1.dat >> ./result/output/stat_table.dat
				grep -c 0 output1.dat >> ./result/output/stat_table.dat
				grep -c 1 output1.dat >> ./result/output/stat_table.dat
				grep -c 2 output1.dat >> ./result/output/stat_table.dat
				grep -c 3 output1.dat >> ./result/output/stat_table.dat
				grep -c 4 output1.dat >> ./result/output/stat_table.dat
				grep -c 5 output1.dat >> ./result/output/stat_table.dat
				grep -c 6 output1.dat >> ./result/output/stat_table.dat
				grep -c 7 output1.dat >> ./result/output/stat_table.dat
				grep -c 8 output1.dat >> ./result/output/stat_table.dat
				grep -c 9 output1.dat >> ./result/output/stat_table.dat
				grep -c 10 output1.dat >> ./result/output/stat_table.dat
				grep -c 11 output1.dat >> ./result/output/stat_table.dat
				grep -c 12 output1.dat >> ./result/output/stat_table.dat
				grep -c 13 output1.dat >> ./result/output/stat_table.dat
				grep -c 14 output1.dat >> ./result/output/stat_table.dat
				grep -c 15 output1.dat >> ./result/output/stat_table.dat
				grep -c 16 output1.dat >> ./result/output/stat_table.dat
			;;
		esac;;
esac

