# Analyze Algorithms

This repository contains code and data for analyzing the time complexity of algorithms. The project includes generating input data, measuring execution time, and plotting the results.

## Directory Structure

```
.
├── createDataset.cpp
├── dataSheet.csv
├── generateInput.cpp
├── input.txt
├── plotGraph.ipynb
├── timeComplexityGraph.py
```

## Files Description

- **createDataset.cpp**: Generates random data, measures the execution time of an algorithm, and saves the results to a CSV file.
- **dataSheet.csv**: Contains the input sizes and corresponding execution times.
- **generateInput.cpp**: Generates input data for testing algorithms and saves it to 

input.txt

.
- **input.txt**: Contains the input sizes for testing.
- **plotGraph.ipynb**: Jupyter notebook for plotting the time complexity graph using the data from 

dataSheet.csv

.
- **timeComplexityGraph.py**: Python script for plotting the time complexity graph using the data from 

dataSheet.csv

.

## Usage

### Generating Input Data

To generate input data, compile and run 

generateInput.cpp

:

```sh
g++ generateInput.cpp -o generateInput
./generateInput
```

### Creating Dataset

To create a dataset and measure the execution time of an algorithm, compile and run 

createDataset.cpp

:

```sh
g++ createDataset.cpp -o createDataset
./createDataset
```

### Plotting the Graph

You can plot the time complexity graph using either the Jupyter notebook or the Python script.

#### Using Jupyter Notebook

Open 

plotGraph.ipynb

 in Jupyter Notebook and run the cells.

#### Using Python Script

Run the 

timeComplexityGraph.py

 script:

```sh
python timeComplexityGraph.py
```

## Dependencies

- **C++**: Required to compile and run the C++ programs.
- **Python**: Required to run the Python script and Jupyter notebook.
- **pandas**: Python library for data manipulation.
- **matplotlib**: Python library for plotting graphs.

Install the Python dependencies using pip:

```sh
pip install pandas matplotlib
```

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## Authors

- [Your Name](https://github.com/yourusername)

---

Feel free to customize this README file as per your requirements.
