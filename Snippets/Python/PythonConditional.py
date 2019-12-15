#Python

#Write a function that checks if two numbers are BOTH either:
#    Smaller than 0
#    Greater than 0
#    Exactly 0

def both(n1, n2):
	return n1 == n2 or n1 * n2 > 0
	
	# neg * neg && pos * pos ==== Positive Number...