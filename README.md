# RISCV-learning
==============================================
There are the tutorials for RISCV learning .For these you can also find in 
(https://github.com/ucb-bar/) ,but may have some bugs. In my computer(ubuntu 14.04 LTS(32BIT)) 
I have fixed some bugs and add some material for RISCV learning 

#Firstly,Tools for riscv-learning(sbt,g++-4.8,openjdk-7-jre)
	$echo "deb http://dl.bintray.com/sbt/debian /" | sudo tee -a /etc/apt/sources.list.d/sbt.list
	
	$sudo apt-get update

	$sudo apt-get install sbt

	$sudo apt-get install g++-4.8

	$sudo apt-get install openjdk-7-jre

	
#Secondly,Chisel-tutorial for Chisel learning
1、build a new dir for riscv-learning such as riscv-learning
	
	$cd ~

	$mkdir riscv-learning
	
	$cd riscv-learning

2、Getting the Repo

	$git clone https://github.com/lx324310/riscv-learning.git

3、Executing Chisel

	$cd chisel-tutorial
	$cd hello (or example ,solution,problem there are many example for chisel learning)
	$make 
another command for sbt you can learning in chisel-tutorial/README.md

#Thirdly,riscv-sodor learning
1、install riscv-fesvr
	
	$cd riscv-sodor
	
	$git clone https://github.com/ucb-bar/riscv-fesvr.git

	$cd riscv-fesvr

	$git checkout cf8867448d02ba99ee5a2163dbee0e3dada348dd

	$./configure --prefix=/home/liuxin/riscv-learning/riscv-sodor/install

	$make install
2、install riscv-sodor

	$cd ..

	$./configure --prefix=/home/liuxin/riscv-learning/riscv-sodor/instal

	$make 

	$make install

3、run emulator

	$cd emulator/rv32_1stage (or rv32_2stage rv32_3stage rv32_5stage except rv32_ucode this cpu test ail)

	$make run
you will see 
[ PASSED ] output/simple.out 	
[ PASSED ] output/add.out 	
[ PASSED ] output/addi.out 	
[ PASSED ] output/auipc.out 	
.....

#Fourly,RISCV ISA learning
	
	$cd riscv-isa
There are four doc for riscv-isa learning

