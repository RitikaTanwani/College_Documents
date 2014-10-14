import random
import re
class myex(Exception):
	def __init__(self,msg):
		self.msg=msg
def check(expr):
	try:
		return safe_eval(expr)
	except myex as exc:
		print exc.msg


def safe_eval(expr):
	#try:
		k=re.match(r'\d+\.\d+',expr)
		if k is not None:
			raise myex("floating point no.")
			#print "h"
		else:
			try:
				result=eval(expr)
				print expr[:-1],'=',result
			except SyntaxError:
				print "invalid syntax"
			except ZeroDivisionError:
				print "Divison by zero not allowed"
			except NameError:
				print "Value entered not int type"
			else:
			
				try:
					print List[result] 
				except IndexError:
					print "result out of index range"
				else:
					try:
						fptr.close()
					except IOError:
						print "file not found"
					else:
						print "error!!"
	#except myex:
filename=raw_input()
try:
	fptr=open(filename,'r')
except IOError:
	print "File name doesnt exist"
else:
	List=range(10)
	random.shuffle(List)
	for expr in fptr.readlines():
		check(expr)
	
