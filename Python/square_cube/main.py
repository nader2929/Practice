import argparse

def surface_of_cube(length):
	return 6*length**2

def volume_of_cube(length):
	return length**3

def parse_args():
	parser = argparse.ArgumentParser()
	parser.add_argument("-iterations", dest="iterations", required=True, help="The number of iterations to increase the length by", type=int)
	return parser.parse_args()

args = parse_args()
length_of_cube = 1
print("length,surface,volume")
for i in range(args.iterations):
	print(f"{length_of_cube},{surface_of_cube(length_of_cube)},{volume_of_cube(length_of_cube)}")
	length_of_cube += 1
