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
		{
			int p = 0;
			for (int i = 0; i <= _N; ++i)
			{
				ifile >> p;
				_row.push_back(p);
			}
			
			for (int i = 0; i < _nnz; ++i)
			{
				ifile >> p;
				_col.push_back(p);
			}
		}
		
		{	 	
			double p = 0;
			for (int i = 0; i < _nnz; ++i)
			{
				ifile >> p;
				_val.push_back(p);
			}
		}
	}
}

void sp_matrix::get_CSR(std::vector<int> &row, std::vector<int> &col, std::vector<double> &val)
{
	row = _row;
	col = _col;
	val = _val;
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

