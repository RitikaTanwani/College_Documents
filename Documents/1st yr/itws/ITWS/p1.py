#!/usr/bin/python
import random
class tree:
	val=None
	def __init__(self,val):
		self.left=None
		self.right=None
		self.val=val
	def insert(self,val):
		p=int(random.random()*100)
		if(p%2==0):
			if(self.left==None):
				new=tree(val)
				self.left=new
			else:
				self.left.insert(val)
		else:
			if(self.right==None):
				new=tree(val)
				self.right=new
			else:
			 	self.right.insert(val)

	def preorder(self):
		print str(self.val) + " ",
		if self.left:
			self.left.preorder()
		if self.right:
			self.right.preorder()

	def postorder(self):
		if self.left:
			self.left.postorder()
		if self.right:
			self.right.postorder()
		print str(self.val) + " ",

	def inorder(self):
		if self.left:
			self.left.inorder()
		print str(self.val) + " ",
		if self.right:
			self.right.inorder()

	def find(self,val):
		k=0
		if(self.val==val):
			return 1
		else: 
			if self.left:
				k=self.left.find(val)
			if (k!=1 and self.right!=None):
				k=self.right.find(val)
			else:
				return -1
		return k

	def depth(self):
		l=0
		r=0
		if(self.left==None and self.right==None):
			return 0
		else:
			if self.left:
		 		l=self.left.depth()
			if self.right:
		 		r=self.right.depth() 
		if (l>r):
			return l+1
		else:
		 	return r+1

t=tree(50)
t.insert(20)
t.insert(3)
print "pre:",
t.preorder()
print "in:",
t.inorder()
print "post",
t.postorder()
print
print t.find(20)
print t.find(0)
print t.depth()
