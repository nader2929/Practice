import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import argparse

def parse_args():
	parser = argparse.ArgumentParser()
	parser.add_argument("-file", dest="file", required=True, help="The file to read", type=str)
	return parser.parse_args()

args = parse_args()
df = pd.read_csv(args.file)
dfm = df.melt('length', var_name='cols', value_name='vals')
print(dfm)

sns.lineplot(data=dfm, x='length', y='vals', hue='cols').set(yscale='log')
plt.legend()
plt.show()
