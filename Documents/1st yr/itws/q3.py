import unittest
class myex(Exception):
	def __init__(self,msg):
		self.msg=msg

def binary_search(a, x, lo=0, hi=None):
	if hi is None:
		hi = len(a)-1
	while lo < hi:
		mid = (lo+hi)/2
		midval = a[mid]
		if midval < x:
			lo = mid+1
		elif midval > x: 
			hi = mid
		else:
			return mid 
	#return -1
a=[4,1,7,9,2]
print binary_search(a,2)

l=[2,3,1,4,5,0]
def sort(l,n):
	i=0
	while(i<n):
		min=i
		j=i+1
		while(j<n):
			if l[min]>l[j]:
				min=j
			j=j+1
		t=l[i]
		l[i]=l[min]
		l[min]=t
		i=i+1
	return l

class TestStuff(unittest.TestCase):
	def test_binsearch(self):
		self.assertEqual(binary_search(a,7),2)	
	def test_raises(self):
		self.assertRaises(myex,binary_search(a,4),0)
	def test_sort(self):
		self.assertEqual(sort(l,6),range(6))
	def test_sort2(self):
		self.assertEqual([4,2,5,0,1,3], range(6))
suite = unittest.TestLoader().loadTestsFromTestCase(TestStuff)
unittest.TextTestRunner(verbosity=0).run(suite)


