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
#build a new dir for riscv-learning such as riscv-learnin
	
	$mkdir riscv-learning
	
	$cd riscv-learning

Getting the Repo
-------------------------
	
	$git clone https://github.com/lx324310/riscv-learning.git

Executing Chisel
-------------------------
	$cd chisel-tutorial
	$cd hello (or example ,solution,problem there are many example for chisel learning)
	$make 

