#!/bin/bash
echo $1
echo $2
echo $3
g++ main.cpp

case "$1" in
	resource)
		case "$2" in
			book)
				echo "resourcebook"
				mkdir ./result
				mkdir ./result/resource
				grep ^Book resource.dat > ./result/resource/book.dat
			;;
			e-book)
				echo "resourcee-book"
				mkdir ./result
				mkdir ./result/resource
				grep ^E-book resource.dat > ./result/resource/e-book.dat			
			;;
			magazine)
				echo "resmaga"
				mkdir ./result
				mkdir ./result/resource
				grep ^Magazine resource.dat > ./result/resource/magazine.dat
			;;
			all)
				echo "resall"
				mkdir ./result
				mkdir ./result/resource
				grep ^Book resource.dat > ./result/resource/book.dat
				grep ^E-book resource.dat > ./result/resource/e-book.dat
				grep ^Magazine resource.dat > ./result/resource/magazine.dat
			;;
		esac;;
	input)
		echo "input"
		case "$2" in
			date)
				echo "date"
			;;
			book)
				echo "book"
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
	space) echo "space";;
	output) echo "output";;
esac
