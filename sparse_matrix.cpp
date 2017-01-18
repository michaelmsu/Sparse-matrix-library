#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <string>
#include <fstream>


class sp_matrix
{
private:
    
	std::vector<int> _row, _col;
	std::vector<double> _val;
    
	int _N = 0, _nnz = 0;
    
    
public:
    
	void read_from_CSR(std::string filename);
	
	void get_CSR(std::vector<int> &row, std::vector<int> &col, std::vector<double> &val);
	
	// variable "size" is a size of a vector
	template <typename T>
	void read_vector(std::vector<T> &vec, int size, std::ifstream &ifile);
    
};


void sp_matrix::read_from_CSR(std::string filename)
{
	std::ifstream ifile(filename);
	
	if(!ifile)
		std::cout << "File doesn't exist or filename isn't correct" 
													<< std::endl << std::flush;
	
	else
	{
		ifile	>> _N >> _nnz;
		
		read_vector(_row, (_N+1), ifile);
		read_vector(_col, _nnz, ifile);
		read_vector(_val, _nnz, ifile);
	}
}

void sp_matrix::get_CSR(std::vector<int> &row, std::vector<int> &col, std::vector<double> &val)
{
	row = _row;
	col = _col;
	val = _val;
}

template <typename T>
void sp_matrix::read_vector(std::vector<T> &vec, int size, std::ifstream &ifile)
{
	vec.resize(size);
	
	for (auto i = 0; i < size; ++i)
		ifile >> vec[i];
}


int main()
{
	
	sp_matrix test;
	test.read_from_CSR("matrix.csr");
	
	std::vector<int> row, col;
	std::vector<double> val;
	
	test.get_CSR(row, col, val);
	
	for(auto c : row)
		std::cout << c << std::endl;
	
	std::cout << std::endl;
	
	for(auto c : col)
		std::cout << c << std::endl;
	
	std::cout << std::endl;
	
	for(auto c : val)
		std::cout << c << std::endl;
	
	return 0;
}

