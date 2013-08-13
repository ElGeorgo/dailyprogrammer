import random
# split the first input to get the range of int
a,b = raw_input().split()

def rand():
	return random.randint(int(a),int(b))

# 4 ints, 3 operators
def genEqu():
	equ = ""
	equ += str(rand())

	for i in range(3):
		equ += " "+random.choice(["+","-","*"])
		equ += " "+ str(rand())

	return equ

equ = genEqu()
while True:
	
	print "> "+equ

	input = raw_input("> ")

	if input == "Q" or input == "q":
		break
	elif int(input) == eval(equ):
		equ = genEqu()
		print "> Correct!"
	else:
		print "> Incorrect..."
