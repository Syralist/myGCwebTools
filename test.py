class test(object):
	_classnum = 0
	def __init__(self, num):
		self._objnum = num
		self._classnum = num

	def func(self):
		print self._objnum
		print self._classnum

inst = test(3)
print inst
inst.func()
