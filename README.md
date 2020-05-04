#AppDev for I-IT1-N1&2
-------------------------------------------------
-------------Application Development 2020--------
-------------------------------------------------

This project is made in course "Application Development 2020"
for us to understand what tools and measures will be used in 
an software application development.

List of contents
1. Configuration instructions
2. Installation instructions
3. Operating instructions
4. File manifest
5. Copyright and licensing information
6. Contact information
7. Credits and acknowledgements

-------------------------------------------------

## 1. Configuration instructions  
	Requirements: a Linux terminal, i.e PuTTY, KiTTY,...  
	You must also have a .wav file named test.wav. This is the file which the program will read.

## 2. Installation instructions  
	Follow these steps to install the application:  
	If you don't have git then install git:  
		sudo apt-get install git  
	Install the build requisites:  
		sudo apt-get install make  
		sudo apt-get install gcc		
	Now clone this repository by type in:  
		git clone https://github.com/Labychu/AppDev.git  
	Change directory to /AppDev/ :  
		cd AppDev  
	Build from sorce:
		make
	Done!  
  
## 3.Operating instructions  
	Build, compile after modify files:  
		make  
	Remove *.o and executable program:  
		make clean  
	Zip all *.c, *.h and makefile files into sound.tar:  
		make zip  
	Execute program after build:  
		make run  
  
## 4. File manifest  
	List of files:
  
	README.md		This file.  
	main.c			Contains the main function.  
	screen.c		Contains screen manipulations functions.  
	screen.h		Contains constant definitions and function declarations used in screen.c.  
	sound.c			Contains *.wav file handling functions.  
	sound.h			Contains custom datatype definitions and function declarations used in sound.c  
	testcurl.c		Contains code which can send information to a specific php page.  
	makefile		Contains the shorter version for the gcc and others command such as rm and tar.  
	testscreen.c		Contains a lot of animations and function that we can play and manipulate alongside with those in screen.c.  
	comm.c			Contains code for the posting and responding to a specific php server or website.  
	comm.h			Contains constant definitions and function declarations at comm.c.
	sound.php		A copy of the real sound.php in pulic_html. Receive info from a pre-specified URL in comm.h 
  
## 5. Licenses and Copyright   
	This application follows GPLv2 copyright.  
  
## 6. Contact information  
	Gmail:	demen2001@gmail.com  
	Github link:	https://github.com/Labychu  
  
## 7. Credits and acknowledgements  
	Written by Thi Dinh under prof. Gao Chao's instructions.  
