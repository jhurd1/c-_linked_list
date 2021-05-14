###############################################################
# Program:
#     Assignment 06, NODE
#     Brother Kirby, CS235
# Author:
#     Jamie Hurd, David Aruldass, and Tyler Williams
# Summary:
#     Jamie: This week posited several challenges, though the leading challenging likely comprised
#		the insertionSort() function. None of the examples I could find entailed the transfer of
#	information between an array to a list to a second array.
#		Tyler:	Things I had a hard time with: I had a pretty hard time with the insert function(), but tutoring helped a lot with that. I had a
# harder	time with insertionSort(). I feel like we all understood the concept and how everything was supposed to go, but it was hard to actually
# write the code for it. I also had a hard time with find().
#		David:	There are two places I got struck and hard time with, one was in FIND function and INSERTION SORT where we have to sort
# 		the	items in the array. Even after reading the chapters and the instructions, I still had hard time with writing the code to work and was getting
# 		errors.
#	Hours worked:
#		Jamie: 20 hrs.
#		Tyler: 13 hrs.
#		David:	7	hrs.
#	Amount of discussion time:
#		Discussion time between the three of us on Slack, text, email, and Zoom meetings likely
# reached around some six hours.
###############################################################

##############################################################
# The main rule
#	Note the -g switch emplaced for separate compilation
##############################################################
a.out: node.h assignment06.o
	g++ -o a.out assignment06.o -g
	tar -cf assignment06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment06.o      : the driver program
#      <anything else?>
##############################################################
assignment06.o: node.h assignment06.cpp sortInsertion.h
	g++ -c assignment06.cpp -g

