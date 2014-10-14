#!/usr/bin/python
import random
class tree:
#	root=None
	left=None
	data=-1
	right=None
	depth=0
	ld=0
	rd=0
	def __init__(self,val):
		self.right=None
		self.left=None
		self.data=val
		self.depth=0
		self.ld=0
		self.rd=0
	def insert(self,val,evod):
			if val%2==0:
				if self.left==None:
					new=tree(evod)
					self.left=new
				else:
					self.left.insert(val,evod)
			else:
				if self.right==None:
					new=tree(evod)
					self.right=new
				else:
					self.right.insert(val,evod)
	def printa(self):
		if self.left!=None:
			self.left.printa()
		print self.data," ",
		if self.right!=None:
			self.right.printa()
	def printb(self):
		print self.data," ",
		if self.left!=None:
			self.left.printb()
		if self.right!=None:
			self.right.printb()
	def printc(self):
		if self.left!=None:
			self.left.printc()
		if self.right!=None:
			self.right.printc()
		print self.data," ",
	def find(self,evod):
#		print "a"
		if self.data==evod:
			print 1
		if self.left!=None:
			self.left.find(evod)
		if self.right!=None:
			self.right.find(evod)
	def find_depth(self):
		ld=0
		rd=0
		if self.left==None and self.right==None:
			return 0
		if self.left!=None:
			ld=self.left.find_depth()
		if self.right!=None:
			rd=self.right.find_depth()
		return max(ld,rd)+1
	
n=random.random()
a=tree(20)
i=0
c=1
while i<20:
	n=random.randrange(1,100)
	c=random.randrange(1,100)
	a.insert(n,c)
#	print "a"
	c=c+1
	i=i+1
print "inorder"
a.printa()
print "pre"
a.printb()
print "post"
a.printc()
#print "find:"
c=int(raw_input("enter: "))
t=a.find(c)
#if t==1:
#	print t

	#lse:
#	print "-1"
p=a.find_depth()
print p
		


