Project Description
Topsis Value Calculator
Submitted by: Ananya Agarwal (102083036)

Topsis_AnanyaAga_102083036 is a Python package, implementing Topsis method for multi-criteria decision analysis.
Topsis stands for Technique for Order of Preference by Similarity to Ideal Solution.
Just provide your input attributes and it will give you the results 

Installation

```
>>> import Topsis_AnanyaAga_102083036 as tp
>>> input_file_name = "102083036-data.csv"
>>> weights = "1,1,0.5,2,1"
>>> impacts = "+,+,-,+,-"
>>> output_file_name = "102083036-result.csv"
>>> output_df = tp.topsis(input_file_name, weights, impacts,output_file_name)
```
Note: Pass the file names within double quotes(" ")

Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change. 

License
MIT
