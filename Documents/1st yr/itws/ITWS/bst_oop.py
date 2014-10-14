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
		if self.data==evod:
			return 1
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


	
class bst(tree):
	data=0
	left=None
	right=None
	def __init__(self,root):
		self.data=root
		self.right=None
		self.left=None
	def insert(self,val):
	#	if self.left==None and self.right==None:
			if val>self.data:
				new=bst(val)
				if self.right==None:
					self.right=new
				else:
					self.right.insert(val)
			else:
				new=bst(val)
				if self.left==None:
					self.left=new
				else:
					self.left.insert(val)
	def find(self,val):
		if self.data==val:
			return 1
		elif val>self.data:
			if self.right==None:
				return -1
			else:
				k=self.right.find(val)
		else:
			if self.left==None:
				return -1
			else:
				k=self.left.find(val)
		return k
	
#n=random.random()
a=bst(20)
i=0
#c=1
while i<10:
#	n=random.randrange(1,100)
	c=random.randrange(1,100)
	a.insert(c)
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
print t
#else:
#	print "-1"
#p=a.find_depth()
#print p		


